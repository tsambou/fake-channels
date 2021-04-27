/***** Channels.h *****/
#include "Bela.h"
#include "global.h"

class Channels{

private:

    bool mRecord, mRecord_prev, mTrigRec;
    bool mPlay = 0, mTrigPlay = 0;
    
    float mMaxSample = 0,   mMaxVol,   mVol,   mClip;
    float mMaxSampleOD = 0, mMaxVolOD, mVolOD, mClipOD;
    
    int mAttackTime = 1000, mReleaseTime = 1000;
    float mRamp = 0;
    
    bool mUndo = 1;
    
	bool mReset = 0;
	int mResetCounter = 0;
	
	int mOverdubN = 0;
	bool mSyncOverdubs = 0;
	bool mExtSync = 0;
	
    int mLoopSize = 0;
    int mSampleCounter = 0;
    
    int mLocalCh=1;
    
    float mBuffer[gBufferSize]; // gBufferSize declared in global.h. Currently at 882000 samples = 10 sec (for 2 ch)
    float mBufferOD[gBufferSize]; // an kanw locally "const int mBufferSize = ..." mou bgazei error
    
public:
	Channels();
	    
	void setup(int LocalCh) {
		mLocalCh = LocalCh;
	}
	
	inline void run(BelaContext *context, int frame, int ch){
		
		// Record
		
		if (mTrigRec == 1) setRec();
		
		if (mRecord == 1 && mRecord_prev == 0) recordStart();
		
		if (mRecord == 1) record(context,frame,ch);
	
		if (mRecord == 0 && mRecord_prev == 1) recordEnd();
		
		mRecord_prev = mRecord;
	
		if (mReset == 1) reset();
		
		if (mTrigPlay == 1) setPlay();
		
		if (mPlay == 1) ramp();
		
		if (gCount == 100) mSyncOverdubs = 0; // mSyncOverdubs starts with ONE for some reason
		
	}
	
	
	
	inline float playback()
	{
		float RunningSample;
		if (mLoopSize > 0 && mPlay == 1){
			RunningSample = mBuffer[mSampleCounter]*0.5 + mBufferOD[mSampleCounter]*0.5*mUndo; // Vol1/Vol2 anti gia 0.5
			mSampleCounter++;
			if (mSampleCounter >= mLoopSize) mSampleCounter = 0;
			return RunningSample*mRamp;
		}
		else return 0;
	}
	
	void record(BelaContext *context, int frame, int ch)
	{
		float RecSample, MergedSample;
		MergedSample = mBufferOD[mSampleCounter]*0.5 + mBuffer[mSampleCounter]*0.5; // Vol1/Vol2 anti gia 0.5
		mBuffer[mSampleCounter] = MergedSample;
		RecSample = audioRead(context, frame, ch)*gInputGain;
		mBufferOD[mSampleCounter] = RecSample;
		
		// Find max sample in first buffer
		if (std::abs(MergedSample) > mMaxSample){
			mMaxSample = std::abs(MergedSample);
			if (mMaxSample) mClip = 1;
		}
		
		// Find max sample in overdub buffer
		if (std::abs(RecSample) > mMaxSampleOD){
			mMaxSampleOD = std::abs(RecSample);
			if (mMaxSampleOD > 0.99) mClipOD = 1;
		}
		
		if (mOverdubN == 0) {
			mSampleCounter++;
			if (mSampleCounter == gBufferSize-1) mRecord = 0;
		}
	}
	
	void setRec(){
		if ((mExtSync == 0 && mOverdubN == 0) || (mOverdubN != 0 && mSyncOverdubs == 0)){
			mRecord = !mRecord;
			mTrigRec = 0;
		}
		if (mOverdubN > 0 && mSyncOverdubs == 1 && mSampleCounter == 0){
			if (mRecord == 1) mTrigRec = 0;
			mRecord = !mRecord;
		}
		if (mOverdubN == 0 && mExtSync == 1){
			if (gMasterSize > 0){
				if (gMasterCounter == 0) {
					mRecord = !mRecord;
					mTrigRec = 0;
				}
			}
			else{
				mRecord = !mRecord;
				mTrigRec = 0;
			}
		}
	}
	
	void recordStart(){
		mMaxSample = 0;
		mMaxSampleOD = 0;
	}
	
	void recordEnd(){
		if (mOverdubN == 0) { // when first Recording Ends
			mLoopSize = mSampleCounter; 
			mSampleCounter = 0;
			mPlay = 1;
			mUndo = 1;
			mRamp = 0;
			
			if (mLocalCh == 0) setMaster();
		}
		mMaxVol = 0.99/mMaxSample; // set parameter.maxvolume = mMaxVol + set parameter.volume == 1
		mMaxVolOD = 0.99/mMaxSampleOD;
		
	
		mOverdubN++;
	}
		
	void ramp(){
		if (mLoopSize > mAttackTime + mReleaseTime){
			if (mSampleCounter <= 1000){
				mRamp = mRamp + 1./1000; // 1/mAttackTime doesnt work
				if (mRamp >= 1) mRamp = 1;
				/*if (mLocalCh == SelCh && mSampleCounter%100==0){
					rt_printf("%f\n",mRamp);
				} */
			}
		
			if (mSampleCounter >= mLoopSize - 1000){
				mRamp = mRamp - 1./1000;
				if (mRamp <= 0) mRamp = 0;
				/*if (mLocalCh == SelCh && mSampleCounter%100==0){
					rt_printf("%f\n",mRamp);
				} */
			}
		}
		
	}
	
	void setPlay(){
		if (mExtSync == 1 && gMasterCounter == 0) {
			mPlay = !mPlay;
			mTrigPlay = 0;
		}
		if (mTrigPlay == 1 && mExtSync == 0 && mSyncOverdubs == 1){
			if (mPlay == 0) {
				mPlay = !mPlay;
				mTrigPlay = 0;
			}
			if (mTrigPlay == 1 && mPlay == 1 && mSampleCounter == 0){
				mPlay = 0;
				mTrigPlay = 0;
			}
		}
		if (mExtSync == 0 && mSyncOverdubs == 0){
			mPlay = !mPlay;
			mTrigPlay = 0;
		}
	}

	void reset()	// should i use member variables or local to function? 
	{ 
		if (mResetCounter == 0){
			mPlay = 0;
			if (mRecord == 1){
				mLoopSize = mSampleCounter;
				mRecord = 0;
				mRecord_prev = 0;
				mTrigRec = 0;
			}
		}
		for (unsigned int i=0; i<100; i++)
		{
			mBuffer[mResetCounter] = 0;
			mBufferOD[mResetCounter] = 0;
			mResetCounter++;
			if (mResetCounter >= mLoopSize)
			{
				mResetCounter = 0;
				mReset = 0;
				mLoopSize = 0;
				mSampleCounter = 0;
				mOverdubN = 0;
				mMaxSample = 0;
				mMaxSampleOD = 0;
			}
			if (mReset == 0) break;
		}		
	}
	
	void undo(){
		if (mOverdubN <= 1) reset();
		else mUndo = !mUndo;
	}
	
    void trigRec(){
    	mTrigRec = 1;
    }

	void trigReset(){
		mReset = 1;
	}
	
	void trigPlay(){
		if (mLoopSize > 0) mTrigPlay = 1;
	}
	
	
	void changeSyncOD(){
		mSyncOverdubs = !mSyncOverdubs;
	}
	
	void changeExtSync(){
		if (gMasterSize > 0) mExtSync = !mExtSync;
	}
	
	void setMaster(){
		gMasterCounter = mSampleCounter;
		gMasterSize = mLoopSize;
		gMasterCh = mLocalCh;
	}
	
	
	
	
	bool getSyncOD(){
		return mSyncOverdubs;
	}
	
	bool getExtSync(){
		return mExtSync;
	}
	
    bool getRec(){
        return mRecord;
    }

	bool getPlay(){
		return mPlay;
	}
    
    int getLoopSize(){
        return mLoopSize;
    }
    
    int getSampleCount(){
    	return mSampleCounter;
    }
    
    float getMaxSample(){
    	return mMaxSampleOD;
    }
    
    void printTest(){
    	rt_printf("%d\n",mAttackTime);
    }
    
};

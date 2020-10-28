#include "gen_exported.h"

namespace gen_exported {

/*******************************************************************************************************************
Cycling '74 License for Max-Generated Code for Export
Copyright (c) 2016 Cycling '74
The code that Max generates automatically and that end users are capable of exporting and using, and any
  associated documentation files (the “Software”) is a work of authorship for which Cycling '74 is the author
  and owner for copyright purposes.  A license is hereby granted, free of charge, to any person obtaining a
  copy of the Software (“Licensee”) to use, copy, modify, merge, publish, and distribute copies of the Software,
  and to permit persons to whom the Software is furnished to do so, subject to the following conditions:
The Software is licensed to Licensee only for non-commercial use. Users who wish to make commercial use of the
  Software must contact the copyright owner to determine if a license for commercial use is available, and the
  terms and conditions for same, which may include fees or royalties. For commercial use, please send inquiries
  to licensing (at) cycling74.com.  The determination of whether a use is commercial use or non-commercial use is based
  upon the use, not the user. The Software may be used by individuals, institutions, governments, corporations, or
  other business whether for-profit or non-profit so long as the use itself is not a commercialization of the
  materials or a use that generates or is intended to generate income, revenue, sales or profit.
The above copyright notice and this license shall be included in all copies or substantial portions of the Software.
THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO
  THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT. IN NO EVENT SHALL
  THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF
  CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
  DEALINGS IN THE SOFTWARE.
*******************************************************************************************************************/

// global noise generator
Noise noise;
static const int GENLIB_LOOPCOUNT_BAIL = 100000;


// The State struct contains all the state and procedures for the gendsp kernel
typedef struct State {
	CommonState __commonstate;
	Data m_RatioNumeratorBuf_9;
	Data m_ExtSyncChBuf_7;
	Data m_ExtSyncStatusBuf_6;
	Data m_RecordStatusBuf_8;
	Data m_ClipInfoBuf_11;
	Data m_RatioDenominatorBuf_10;
	Data m_SampleCountBuf_4;
	Data m_SyncOverdubStatusBuf_5;
	Data m_LoopSizeBuf_3;
	Data m_undo_2;
	Data m_loopy_1;
	Delta __m_delta_90;
	Delta __m_delta_224;
	Delta __m_delta_92;
	Delta __m_delta_93;
	Delta __m_delta_94;
	Delta __m_delta_415;
	Delta __m_delta_102;
	Delta __m_delta_221;
	Delta __m_delta_223;
	Delta __m_delta_103;
	Delta __m_delta_89;
	Delta __m_delta_225;
	Delta __m_delta_79;
	Delta __m_delta_233;
	Delta __m_delta_74;
	Delta __m_delta_69;
	Delta __m_delta_67;
	Delta __m_delta_83;
	Delta __m_delta_75;
	Delta __m_delta_106;
	Delta __m_delta_234;
	Delta __m_delta_81;
	Delta __m_delta_80;
	Delta __m_delta_107;
	Delta __m_delta_124;
	Delta __m_delta_220;
	Delta __m_delta_196;
	Delta __m_delta_194;
	Delta __m_delta_198;
	Delta __m_delta_200;
	Delta __m_delta_205;
	Delta __m_delta_192;
	Delta __m_delta_188;
	Delta __m_delta_190;
	Delta __m_delta_184;
	Delta __m_delta_186;
	Delta __m_delta_111;
	Delta __m_delta_206;
	Delta __m_delta_211;
	Delta __m_delta_123;
	Delta __m_delta_122;
	Delta __m_delta_121;
	Delta __m_delta_210;
	Delta __m_delta_65;
	Delta __m_delta_153;
	Delta __m_delta_141;
	Delta __m_delta_212;
	Delta __m_delta_214;
	Delta __m_delta_63;
	Delta __m_delta_53;
	Delta __m_delta_59;
	Delta __m_delta_345;
	Delta __m_delta_343;
	Delta __m_delta_351;
	Delta __m_delta_352;
	Delta __m_delta_354;
	Delta __m_delta_342;
	Delta __m_delta_337;
	Delta __m_delta_341;
	Delta __m_delta_331;
	Delta __m_delta_336;
	Delta __m_delta_61;
	Delta __m_delta_355;
	Delta __m_delta_364;
	Delta __m_delta_384;
	Delta __m_delta_385;
	Delta __m_delta_386;
	Delta __m_delta_356;
	Delta __m_delta_383;
	Delta __m_delta_369;
	Delta __m_delta_373;
	Delta __m_delta_365;
	Delta __m_delta_368;
	Delta __m_delta_327;
	Delta __m_delta_329;
	Delta __m_delta_403;
	Delta __m_delta_238;
	Delta __m_delta_242;
	Delta __m_delta_252;
	Delta __m_delta_325;
	Delta __m_delta_237;
	Delta __m_delta_182;
	Delta __m_delta_51;
	Delta __m_delta_57;
	Delta __m_delta_55;
	Delta __m_delta_254;
	Delta __m_delta_253;
	Delta __m_delta_272;
	Delta __m_delta_255;
	Delta __m_delta_317;
	Delta __m_delta_319;
	Delta __m_delta_315;
	Delta __m_delta_323;
	Delta __m_delta_313;
	Delta __m_delta_284;
	Delta __m_delta_321;
	PlusEquals __m_pluseq_236;
	PlusEquals __m_pluseq_367;
	PlusEquals __m_pluseq_105;
	int __exception;
	int __loopcount;
	int vectorsize;
	t_sample m_SyncLoopSize_39;
	t_sample m_SyncCounter_40;
	t_sample m_ClipOverdubN_312;
	t_sample m_Clip_311;
	t_sample m_ExtSyncStatus_38;
	t_sample m_Dynamic_310;
	t_sample m_ExtSyncCh_37;
	t_sample m_Undo1State_35;
	t_sample m_ResetState_32;
	t_sample m_Undo2State_36;
	t_sample m_UndoChannel_33;
	t_sample m_OverdubNundo_34;
	t_sample m_gCount_31;
	t_sample m_Peak_309;
	t_sample m_RatioState_307;
	t_sample m_ExtSyncCh_299;
	t_sample m_ExtSyncStatus_300;
	t_sample m_Undo2State_298;
	t_sample m_Undo1State_297;
	t_sample m_output_308;
	t_sample m_SyncLoopSize_301;
	t_sample m_SyncCountLoops_303;
	t_sample m_RatioDenominator_306;
	t_sample m_SyncCounter_302;
	t_sample m_RatioNumerator_305;
	t_sample m_Ratio_304;
	t_sample m_OverdubNundo_296;
	t_sample m_Ratio_173;
	t_sample m_RecordOverdub_29;
	t_sample __m_latch_366;
	t_sample m_pSyncOverdubs_17;
	t_sample m_pExtSync_18;
	t_sample m_pGridMode_19;
	t_sample __m_latch_363;
	t_sample m_pPlay_16;
	t_sample m_pReset_14;
	t_sample samplerate;
	t_sample m_pUndo_15;
	t_sample m_pInputCh_12;
	t_sample m_pRec_13;
	t_sample m_SyncRec_30;
	t_sample m_pSyncRatio_20;
	t_sample m_mySelectedCh_22;
	t_sample m_SyncOverdubStatus_27;
	t_sample m_Overdub_26;
	t_sample m_Record_28;
	t_sample __m_latch_340;
	t_sample m_pSyncRatioButton_21;
	t_sample __m_latch_344;
	t_sample __m_latch_350;
	t_sample __m_latch_353;
	t_sample m_SampleCount_25;
	t_sample m_InputCh_23;
	t_sample m_LoopSize_24;
	t_sample m_UndoChannel_295;
	t_sample m_ResetState_294;
	t_sample m_gCount_293;
	t_sample m_SyncRec_161;
	t_sample m_RecordOverdub_160;
	t_sample m_gCount_162;
	t_sample m_UndoChannel_164;
	t_sample m_ResetState_163;
	t_sample m_OverdubNundo_165;
	t_sample m_Record_159;
	t_sample m_SyncOverdubStatus_158;
	t_sample __m_latch_213;
	t_sample __m_latch_209;
	t_sample m_SampleCount_156;
	t_sample m_Overdub_157;
	t_sample m_LoopSize_155;
	t_sample m_Undo1State_166;
	t_sample m_ExtSyncCh_168;
	t_sample m_RatioState_176;
	t_sample m_output_177;
	t_sample m_RatioDenominator_175;
	t_sample m_SyncCounter_171;
	t_sample m_Undo2State_167;
	t_sample m_Peak_178;
	t_sample m_Clip_180;
	t_sample m_ExtSyncStatus_169;
	t_sample m_Dynamic_179;
	t_sample m_SyncLoopSize_170;
	t_sample m_ClipOverdubN_181;
	t_sample m_SyncCountLoops_172;
	t_sample __m_latch_219;
	t_sample __m_latch_222;
	t_sample m_SyncCountLoops_41;
	t_sample m_LoopSize_286;
	t_sample m_Ratio_42;
	t_sample m_RatioNumerator_43;
	t_sample m_RatioDenominator_44;
	t_sample m_SampleCount_287;
	t_sample m_SyncOverdubStatus_289;
	t_sample m_SyncRec_292;
	t_sample m_Overdub_288;
	t_sample m_RecordOverdub_291;
	t_sample m_Record_290;
	t_sample __m_latch_104;
	t_sample m_RatioState_45;
	t_sample m_Peak_47;
	t_sample __m_latch_88;
	t_sample __m_latch_232;
	t_sample __m_latch_91;
	t_sample __m_latch_101;
	t_sample m_output_46;
	t_sample __m_latch_82;
	t_sample __m_latch_235;
	t_sample m_Dynamic_48;
	t_sample __m_latch_78;
	t_sample m_Clip_49;
	t_sample m_ClipOverdubN_50;
	t_sample m_RatioNumerator_174;
	// re-initialize all member variables;
	inline void reset(t_param __sr, int __vs) {
		__exception = 0;
		vectorsize = __vs;
		samplerate = __sr;
		m_loopy_1.reset("loopy", ((int)441000), ((int)3));
		m_undo_2.reset("undo", ((int)441000), ((int)6));
		m_LoopSizeBuf_3.reset("LoopSizeBuf", ((int)1), ((int)3));
		m_SampleCountBuf_4.reset("SampleCountBuf", ((int)1), ((int)3));
		m_SyncOverdubStatusBuf_5.reset("SyncOverdubStatusBuf", ((int)1), ((int)3));
		m_ExtSyncStatusBuf_6.reset("ExtSyncStatusBuf", ((int)1), ((int)3));
		m_ExtSyncChBuf_7.reset("ExtSyncChBuf", ((int)1), ((int)3));
		m_RecordStatusBuf_8.reset("RecordStatusBuf", ((int)1), ((int)3));
		m_RatioNumeratorBuf_9.reset("RatioNumeratorBuf", ((int)1), ((int)3));
		m_RatioDenominatorBuf_10.reset("RatioDenominatorBuf", ((int)1), ((int)3));
		m_ClipInfoBuf_11.reset("ClipInfoBuf", ((int)1), ((int)3));
		m_pInputCh_12 = ((int)0);
		m_pRec_13 = ((int)0);
		m_pReset_14 = ((int)0);
		m_pUndo_15 = ((int)0);
		m_pPlay_16 = ((int)0);
		m_pSyncOverdubs_17 = ((int)0);
		m_pExtSync_18 = ((int)0);
		m_pGridMode_19 = ((int)0);
		m_pSyncRatio_20 = ((int)0);
		m_pSyncRatioButton_21 = ((int)0);
		m_mySelectedCh_22 = ((int)0);
		m_InputCh_23 = ((int)0);
		m_LoopSize_24 = ((int)0);
		m_SampleCount_25 = ((int)0);
		m_Overdub_26 = ((int)1);
		m_SyncOverdubStatus_27 = ((int)0);
		m_Record_28 = ((int)0);
		m_RecordOverdub_29 = ((int)0);
		m_SyncRec_30 = ((int)0);
		m_gCount_31 = ((int)0);
		m_ResetState_32 = ((int)0);
		m_UndoChannel_33 = ((int)0);
		m_OverdubNundo_34 = ((int)0);
		m_Undo1State_35 = ((int)0);
		m_Undo2State_36 = ((int)0);
		m_ExtSyncCh_37 = ((int)0);
		m_ExtSyncStatus_38 = ((int)0);
		m_SyncLoopSize_39 = ((int)0);
		m_SyncCounter_40 = ((int)0);
		m_SyncCountLoops_41 = ((int)0);
		m_Ratio_42 = ((int)1);
		m_RatioNumerator_43 = ((int)1);
		m_RatioDenominator_44 = ((int)1);
		m_RatioState_45 = ((int)0);
		m_output_46 = ((int)0);
		m_Peak_47 = ((int)0);
		m_Dynamic_48 = ((int)1);
		m_Clip_49 = ((int)0);
		m_ClipOverdubN_50 = ((int)0);
		__m_delta_51.reset(0);
		__m_delta_53.reset(0);
		__m_delta_55.reset(0);
		__m_delta_57.reset(0);
		__m_delta_59.reset(0);
		__m_delta_61.reset(0);
		__m_delta_63.reset(0);
		__m_delta_65.reset(0);
		__m_delta_67.reset(0);
		__m_delta_69.reset(0);
		__m_delta_74.reset(0);
		__m_delta_75.reset(0);
		__m_latch_78 = 0;
		__m_delta_79.reset(0);
		__m_delta_80.reset(0);
		__m_delta_81.reset(0);
		__m_latch_82 = 0;
		__m_delta_83.reset(0);
		__m_latch_88 = 0;
		__m_delta_89.reset(0);
		__m_delta_90.reset(0);
		__m_latch_91 = 0;
		__m_delta_92.reset(0);
		__m_delta_93.reset(0);
		__m_delta_94.reset(0);
		__m_latch_101 = 0;
		__m_delta_102.reset(0);
		__m_delta_103.reset(0);
		__m_latch_104 = 0;
		__m_pluseq_105.reset(0);
		__m_delta_106.reset(0);
		__m_delta_107.reset(0);
		__m_delta_111.reset(0);
		__m_delta_121.reset(0);
		__m_delta_122.reset(0);
		__m_delta_123.reset(0);
		__m_delta_124.reset(0);
		__m_delta_141.reset(0);
		__m_delta_153.reset(0);
		m_LoopSize_155 = ((int)0);
		m_SampleCount_156 = ((int)0);
		m_Overdub_157 = ((int)1);
		m_SyncOverdubStatus_158 = ((int)0);
		m_Record_159 = ((int)0);
		m_RecordOverdub_160 = ((int)0);
		m_SyncRec_161 = ((int)0);
		m_gCount_162 = ((int)0);
		m_ResetState_163 = ((int)0);
		m_UndoChannel_164 = ((int)0);
		m_OverdubNundo_165 = ((int)0);
		m_Undo1State_166 = ((int)0);
		m_Undo2State_167 = ((int)0);
		m_ExtSyncCh_168 = ((int)0);
		m_ExtSyncStatus_169 = ((int)0);
		m_SyncLoopSize_170 = ((int)0);
		m_SyncCounter_171 = ((int)0);
		m_SyncCountLoops_172 = ((int)0);
		m_Ratio_173 = ((int)1);
		m_RatioNumerator_174 = ((int)1);
		m_RatioDenominator_175 = ((int)1);
		m_RatioState_176 = ((int)0);
		m_output_177 = ((int)0);
		m_Peak_178 = ((int)0);
		m_Dynamic_179 = ((int)1);
		m_Clip_180 = ((int)0);
		m_ClipOverdubN_181 = ((int)0);
		__m_delta_182.reset(0);
		__m_delta_184.reset(0);
		__m_delta_186.reset(0);
		__m_delta_188.reset(0);
		__m_delta_190.reset(0);
		__m_delta_192.reset(0);
		__m_delta_194.reset(0);
		__m_delta_196.reset(0);
		__m_delta_198.reset(0);
		__m_delta_200.reset(0);
		__m_delta_205.reset(0);
		__m_delta_206.reset(0);
		__m_latch_209 = 0;
		__m_delta_210.reset(0);
		__m_delta_211.reset(0);
		__m_delta_212.reset(0);
		__m_latch_213 = 0;
		__m_delta_214.reset(0);
		__m_latch_219 = 0;
		__m_delta_220.reset(0);
		__m_delta_221.reset(0);
		__m_latch_222 = 0;
		__m_delta_223.reset(0);
		__m_delta_224.reset(0);
		__m_delta_225.reset(0);
		__m_latch_232 = 0;
		__m_delta_233.reset(0);
		__m_delta_234.reset(0);
		__m_latch_235 = 0;
		__m_pluseq_236.reset(0);
		__m_delta_237.reset(0);
		__m_delta_238.reset(0);
		__m_delta_242.reset(0);
		__m_delta_252.reset(0);
		__m_delta_253.reset(0);
		__m_delta_254.reset(0);
		__m_delta_255.reset(0);
		__m_delta_272.reset(0);
		__m_delta_284.reset(0);
		m_LoopSize_286 = ((int)0);
		m_SampleCount_287 = ((int)0);
		m_Overdub_288 = ((int)1);
		m_SyncOverdubStatus_289 = ((int)0);
		m_Record_290 = ((int)0);
		m_RecordOverdub_291 = ((int)0);
		m_SyncRec_292 = ((int)0);
		m_gCount_293 = ((int)0);
		m_ResetState_294 = ((int)0);
		m_UndoChannel_295 = ((int)0);
		m_OverdubNundo_296 = ((int)0);
		m_Undo1State_297 = ((int)0);
		m_Undo2State_298 = ((int)0);
		m_ExtSyncCh_299 = ((int)0);
		m_ExtSyncStatus_300 = ((int)0);
		m_SyncLoopSize_301 = ((int)0);
		m_SyncCounter_302 = ((int)0);
		m_SyncCountLoops_303 = ((int)0);
		m_Ratio_304 = ((int)1);
		m_RatioNumerator_305 = ((int)1);
		m_RatioDenominator_306 = ((int)1);
		m_RatioState_307 = ((int)0);
		m_output_308 = ((int)0);
		m_Peak_309 = ((int)0);
		m_Dynamic_310 = ((int)1);
		m_Clip_311 = ((int)0);
		m_ClipOverdubN_312 = ((int)0);
		__m_delta_313.reset(0);
		__m_delta_315.reset(0);
		__m_delta_317.reset(0);
		__m_delta_319.reset(0);
		__m_delta_321.reset(0);
		__m_delta_323.reset(0);
		__m_delta_325.reset(0);
		__m_delta_327.reset(0);
		__m_delta_329.reset(0);
		__m_delta_331.reset(0);
		__m_delta_336.reset(0);
		__m_delta_337.reset(0);
		__m_latch_340 = 0;
		__m_delta_341.reset(0);
		__m_delta_342.reset(0);
		__m_delta_343.reset(0);
		__m_latch_344 = 0;
		__m_delta_345.reset(0);
		__m_latch_350 = 0;
		__m_delta_351.reset(0);
		__m_delta_352.reset(0);
		__m_latch_353 = 0;
		__m_delta_354.reset(0);
		__m_delta_355.reset(0);
		__m_delta_356.reset(0);
		__m_latch_363 = 0;
		__m_delta_364.reset(0);
		__m_delta_365.reset(0);
		__m_latch_366 = 0;
		__m_pluseq_367.reset(0);
		__m_delta_368.reset(0);
		__m_delta_369.reset(0);
		__m_delta_373.reset(0);
		__m_delta_383.reset(0);
		__m_delta_384.reset(0);
		__m_delta_385.reset(0);
		__m_delta_386.reset(0);
		__m_delta_403.reset(0);
		__m_delta_415.reset(0);
		genlib_reset_complete(this);
		
	};
	// the signal processing routine;
	inline int perform(t_sample ** __ins, t_sample ** __outs, int __n) {
		vectorsize = __n;
		const t_sample * __in1 = __ins[0];
		t_sample * __out1 = __outs[0];
		t_sample * __out2 = __outs[1];
		t_sample * __out3 = __outs[2];
		t_sample * __out4 = __outs[3];
		t_sample * __out5 = __outs[4];
		t_sample * __out6 = __outs[5];
		t_sample * __out7 = __outs[6];
		t_sample * __out8 = __outs[7];
		t_sample * __out9 = __outs[8];
		t_sample * __out10 = __outs[9];
		t_sample * __out11 = __outs[10];
		t_sample * __out12 = __outs[11];
		t_sample * __out13 = __outs[12];
		t_sample * __out14 = __outs[13];
		t_sample * __out15 = __outs[14];
		t_sample * __out16 = __outs[15];
		t_sample * __out17 = __outs[16];
		t_sample * __out18 = __outs[17];
		t_sample * __out19 = __outs[18];
		t_sample * __out20 = __outs[19];
		t_sample * __out21 = __outs[20];
		t_sample * __out22 = __outs[21];
		t_sample * __out23 = __outs[22];
		t_sample * __out24 = __outs[23];
		if (__exception) {
			return __exception;
			
		} else if (( (__in1 == 0) || (__out1 == 0) || (__out2 == 0) || (__out3 == 0) || (__out4 == 0) || (__out5 == 0) || (__out6 == 0) || (__out7 == 0) || (__out8 == 0) || (__out9 == 0) || (__out10 == 0) || (__out11 == 0) || (__out12 == 0) || (__out13 == 0) || (__out14 == 0) || (__out15 == 0) || (__out16 == 0) || (__out17 == 0) || (__out18 == 0) || (__out19 == 0) || (__out20 == 0) || (__out21 == 0) || (__out22 == 0) || (__out23 == 0) || (__out24 == 0) )) {
			__exception = GENLIB_ERR_NULL_BUFFER;
			return __exception;
			
		};
		__loopcount = (__n * GENLIB_LOOPCOUNT_BAIL);
		int SampleCountBuf_dim = m_SampleCountBuf_4.dim;
		int SampleCountBuf_channels = m_SampleCountBuf_4.channels;
		int LoopSizeBuf_dim = m_LoopSizeBuf_3.dim;
		int LoopSizeBuf_channels = m_LoopSizeBuf_3.channels;
		int ExtSyncChBuf_dim = m_ExtSyncChBuf_7.dim;
		int ExtSyncChBuf_channels = m_ExtSyncChBuf_7.channels;
		int ExtSyncStatusBuf_dim = m_ExtSyncStatusBuf_6.dim;
		int ExtSyncStatusBuf_channels = m_ExtSyncStatusBuf_6.channels;
		int SyncOverdubStatusBuf_dim = m_SyncOverdubStatusBuf_5.dim;
		int SyncOverdubStatusBuf_channels = m_SyncOverdubStatusBuf_5.channels;
		int RatioNumeratorBuf_dim = m_RatioNumeratorBuf_9.dim;
		int RatioNumeratorBuf_channels = m_RatioNumeratorBuf_9.channels;
		int RatioDenominatorBuf_dim = m_RatioDenominatorBuf_10.dim;
		int RatioDenominatorBuf_channels = m_RatioDenominatorBuf_10.channels;
		int ClipInfoBuf_dim = m_ClipInfoBuf_11.dim;
		int ClipInfoBuf_channels = m_ClipInfoBuf_11.channels;
		int loopy_dim = m_loopy_1.dim;
		int loopy_channels = m_loopy_1.channels;
		bool index_ignore_432 = (((int)5) >= loopy_dim);
		// the main sample loop;
		while ((__n--)) {
			const t_sample in1 = (*(__in1++));
			if (((m_pGridMode_19 == ((int)0)) && (m_pInputCh_12 >= ((int)0)))) {
				m_mySelectedCh_22 = m_pInputCh_12;
				
			};
			// abort processing if an infinite loop is suspected;
			if (((__loopcount--) <= 0)) {
				__exception = GENLIB_ERR_LOOP_OVERFLOW;
				break ;
				
			};
			t_sample Loop1 = Looper_d_d_i_d_d_d_d_d_d_d_d_d_dat_dat_dat_dat_dat_dat_dat_dat_dat_dat_dat(in1, m_mySelectedCh_22, ((int)0), m_pInputCh_12, m_pGridMode_19, m_pRec_13, m_pReset_14, m_pUndo_15, m_pSyncOverdubs_17, m_pExtSync_18, m_pSyncRatio_20, m_pSyncRatioButton_21, m_loopy_1, m_undo_2, m_SampleCountBuf_4, m_LoopSizeBuf_3, m_ExtSyncChBuf_7, m_SyncOverdubStatusBuf_5, m_ExtSyncStatusBuf_6, m_RecordStatusBuf_8, m_RatioNumeratorBuf_9, m_RatioDenominatorBuf_10, m_ClipInfoBuf_11);
			t_sample Loop2 = Looper_d_d_i_d_d_d_d_d_d_d_d_d_dat_dat_dat_dat_dat_dat_dat_dat_dat_dat_dat_154(in1, m_mySelectedCh_22, ((int)1), m_pInputCh_12, m_pGridMode_19, m_pRec_13, m_pReset_14, m_pUndo_15, m_pSyncOverdubs_17, m_pExtSync_18, m_pSyncRatio_20, m_pSyncRatioButton_21, m_loopy_1, m_undo_2, m_SampleCountBuf_4, m_LoopSizeBuf_3, m_ExtSyncChBuf_7, m_SyncOverdubStatusBuf_5, m_ExtSyncStatusBuf_6, m_RecordStatusBuf_8, m_RatioNumeratorBuf_9, m_RatioDenominatorBuf_10, m_ClipInfoBuf_11);
			t_sample Loop3 = Looper_d_d_i_d_d_d_d_d_d_d_d_d_dat_dat_dat_dat_dat_dat_dat_dat_dat_dat_dat_285(in1, m_mySelectedCh_22, ((int)2), m_pInputCh_12, m_pGridMode_19, m_pRec_13, m_pReset_14, m_pUndo_15, m_pSyncOverdubs_17, m_pExtSync_18, m_pSyncRatio_20, m_pSyncRatioButton_21, m_loopy_1, m_undo_2, m_SampleCountBuf_4, m_LoopSizeBuf_3, m_ExtSyncChBuf_7, m_SyncOverdubStatusBuf_5, m_ExtSyncStatusBuf_6, m_RecordStatusBuf_8, m_RatioNumeratorBuf_9, m_RatioDenominatorBuf_10, m_ClipInfoBuf_11);
			t_sample expr_892 = m_mySelectedCh_22;
			// samples SampleCountBuf channel 1;
			int chan_416 = m_mySelectedCh_22;
			bool chan_ignore_417 = ((chan_416 < 0) || (chan_416 >= SampleCountBuf_channels));
			t_sample expr_893 = (chan_ignore_417 ? 0 : m_SampleCountBuf_4.read(0, chan_416));
			// samples LoopSizeBuf channel 1;
			int chan_418 = m_mySelectedCh_22;
			bool chan_ignore_419 = ((chan_418 < 0) || (chan_418 >= LoopSizeBuf_channels));
			t_sample expr_894 = (chan_ignore_419 ? 0 : m_LoopSizeBuf_3.read(0, chan_418));
			// samples ExtSyncChBuf channel 1;
			int chan_420 = m_mySelectedCh_22;
			bool chan_ignore_421 = ((chan_420 < 0) || (chan_420 >= ExtSyncChBuf_channels));
			t_sample expr_895 = (chan_ignore_421 ? 0 : m_ExtSyncChBuf_7.read(0, chan_420));
			// samples ExtSyncStatusBuf channel 1;
			int chan_422 = m_mySelectedCh_22;
			bool chan_ignore_423 = ((chan_422 < 0) || (chan_422 >= ExtSyncStatusBuf_channels));
			t_sample expr_896 = (chan_ignore_423 ? 0 : m_ExtSyncStatusBuf_6.read(0, chan_422));
			// samples SyncOverdubStatusBuf channel 1;
			int chan_424 = m_mySelectedCh_22;
			bool chan_ignore_425 = ((chan_424 < 0) || (chan_424 >= SyncOverdubStatusBuf_channels));
			t_sample expr_897 = (chan_ignore_425 ? 0 : m_SyncOverdubStatusBuf_5.read(0, chan_424));
			// samples RatioNumeratorBuf channel 1;
			int chan_426 = m_mySelectedCh_22;
			bool chan_ignore_427 = ((chan_426 < 0) || (chan_426 >= RatioNumeratorBuf_channels));
			t_sample expr_898 = (chan_ignore_427 ? 0 : m_RatioNumeratorBuf_9.read(0, chan_426));
			// samples RatioDenominatorBuf channel 1;
			int chan_428 = m_mySelectedCh_22;
			bool chan_ignore_429 = ((chan_428 < 0) || (chan_428 >= RatioDenominatorBuf_channels));
			t_sample expr_899 = (chan_ignore_429 ? 0 : m_RatioDenominatorBuf_10.read(0, chan_428));
			// samples ClipInfoBuf channel 1;
			int chan_430 = m_mySelectedCh_22;
			bool chan_ignore_431 = ((chan_430 < 0) || (chan_430 >= ClipInfoBuf_channels));
			t_sample expr_900 = (chan_ignore_431 ? 0 : m_ClipInfoBuf_11.read(0, chan_430));
			// samples loopy channel 1;
			t_sample peek_886 = (index_ignore_432 ? 0 : m_loopy_1.read(((int)5), 0));
			t_sample peek_887 = ((int)5);
			int expr_901 = (peek_886 != ((int)0));
			t_sample out24 = expr_901;
			t_sample out23 = expr_900;
			t_sample out12 = Loop1;
			t_sample out22 = expr_899;
			t_sample out16 = expr_893;
			t_sample out15 = expr_892;
			t_sample out21 = expr_898;
			t_sample out18 = expr_895;
			t_sample out17 = expr_894;
			t_sample out11 = in1;
			t_sample out19 = expr_896;
			t_sample out20 = expr_897;
			t_sample out14 = Loop3;
			t_sample out13 = Loop2;
			// assign results to output buffer;
			(*(__out1++)) = 0;
			(*(__out2++)) = 0;
			(*(__out3++)) = 0;
			(*(__out4++)) = 0;
			(*(__out5++)) = 0;
			(*(__out6++)) = 0;
			(*(__out7++)) = 0;
			(*(__out8++)) = 0;
			(*(__out9++)) = 0;
			(*(__out10++)) = 0;
			(*(__out11++)) = out11;
			(*(__out12++)) = out12;
			(*(__out13++)) = out13;
			(*(__out14++)) = out14;
			(*(__out15++)) = out15;
			(*(__out16++)) = out16;
			(*(__out17++)) = out17;
			(*(__out18++)) = out18;
			(*(__out19++)) = out19;
			(*(__out20++)) = out20;
			(*(__out21++)) = out21;
			(*(__out22++)) = out22;
			(*(__out23++)) = out23;
			(*(__out24++)) = out24;
			
		};
		return __exception;
		
	};
	inline void set_loopy(void * _value) {
		m_loopy_1.setbuffer(_value);
	};
	inline void set_undo(void * _value) {
		m_undo_2.setbuffer(_value);
	};
	inline void set_LoopSizeBuf(void * _value) {
		m_LoopSizeBuf_3.setbuffer(_value);
	};
	inline void set_SampleCountBuf(void * _value) {
		m_SampleCountBuf_4.setbuffer(_value);
	};
	inline void set_SyncOverdubStatusBuf(void * _value) {
		m_SyncOverdubStatusBuf_5.setbuffer(_value);
	};
	inline void set_ExtSyncStatusBuf(void * _value) {
		m_ExtSyncStatusBuf_6.setbuffer(_value);
	};
	inline void set_ExtSyncChBuf(void * _value) {
		m_ExtSyncChBuf_7.setbuffer(_value);
	};
	inline void set_RecordStatusBuf(void * _value) {
		m_RecordStatusBuf_8.setbuffer(_value);
	};
	inline void set_RatioNumeratorBuf(void * _value) {
		m_RatioNumeratorBuf_9.setbuffer(_value);
	};
	inline void set_RatioDenominatorBuf(void * _value) {
		m_RatioDenominatorBuf_10.setbuffer(_value);
	};
	inline void set_ClipInfoBuf(void * _value) {
		m_ClipInfoBuf_11.setbuffer(_value);
	};
	inline void set_pInputCh(t_param _value) {
		m_pInputCh_12 = (_value < -1 ? -1 : (_value > 2 ? 2 : _value));
	};
	inline void set_pRec(t_param _value) {
		m_pRec_13 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_pReset(t_param _value) {
		m_pReset_14 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_pUndo(t_param _value) {
		m_pUndo_15 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_pPlay(t_param _value) {
		m_pPlay_16 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_pSyncOverdubs(t_param _value) {
		m_pSyncOverdubs_17 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_pExtSync(t_param _value) {
		m_pExtSync_18 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_pGridMode(t_param _value) {
		m_pGridMode_19 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_pSyncRatio(t_param _value) {
		m_pSyncRatio_20 = (_value < 0 ? 0 : (_value > 16 ? 16 : _value));
	};
	inline void set_pSyncRatioButton(t_param _value) {
		m_pSyncRatioButton_21 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline t_sample Looper_d_d_i_d_d_d_d_d_d_d_d_d_dat_dat_dat_dat_dat_dat_dat_dat_dat_dat_dat(t_sample Audio_in, t_sample SelectedCh, int LocalCh, t_sample m_InputCh_23, t_sample GridMode, t_sample bRec, t_sample bReset, t_sample bUndo, t_sample bSyncOverdubs, t_sample bExtSync, t_sample SyncRatio, t_sample SyncRatioButton, Data& LoopBuffer, Data& UndoBuffer, Data& SampleCountBuffer, Data& LoopSizeBuffer, Data& ExtSyncChBuffer, Data& SyncOverdubStatusBuffer, Data& ExtSyncStatusBuffer, Data& RecordStatusBuffer, Data& RatioNbuffer, Data& RatioDbuffer, Data& ClipInfoBuffer) {
		if ((__m_delta_51(m_SyncOverdubStatus_27) != ((int)0))) {
			int SyncOverdubStatusBuffer_dim = SyncOverdubStatusBuffer.dim;
			int SyncOverdubStatusBuffer_channels = SyncOverdubStatusBuffer.channels;
			bool chan_ignore_52 = ((LocalCh < 0) || (LocalCh >= SyncOverdubStatusBuffer_channels));
			if ((!chan_ignore_52)) {
				SyncOverdubStatusBuffer.write(m_SyncOverdubStatus_27, 0, LocalCh);
				
			};
			
		};
		if ((__m_delta_53(m_Record_28) != ((int)0))) {
			int RecordStatusBuffer_dim = RecordStatusBuffer.dim;
			int RecordStatusBuffer_channels = RecordStatusBuffer.channels;
			bool chan_ignore_54 = ((LocalCh < 0) || (LocalCh >= RecordStatusBuffer_channels));
			if ((!chan_ignore_54)) {
				RecordStatusBuffer.write(m_Record_28, 0, LocalCh);
				
			};
			
		};
		if (((m_LoopSize_24 > ((int)0)) || (__m_delta_55(bReset) > ((int)0)))) {
			int SampleCountBuffer_dim = SampleCountBuffer.dim;
			int SampleCountBuffer_channels = SampleCountBuffer.channels;
			bool chan_ignore_56 = ((LocalCh < 0) || (LocalCh >= SampleCountBuffer_channels));
			if ((!chan_ignore_56)) {
				SampleCountBuffer.write(m_SampleCount_25, 0, LocalCh);
				
			};
			
		};
		if ((__m_delta_57(m_LoopSize_24) != ((int)0))) {
			int LoopSizeBuffer_dim = LoopSizeBuffer.dim;
			int LoopSizeBuffer_channels = LoopSizeBuffer.channels;
			bool chan_ignore_58 = ((LocalCh < 0) || (LocalCh >= LoopSizeBuffer_channels));
			if ((!chan_ignore_58)) {
				LoopSizeBuffer.write(m_LoopSize_24, 0, LocalCh);
				
			};
			
		};
		if ((__m_delta_59(m_ExtSyncCh_37) != ((int)0))) {
			int ExtSyncChBuffer_dim = ExtSyncChBuffer.dim;
			int ExtSyncChBuffer_channels = ExtSyncChBuffer.channels;
			bool chan_ignore_60 = ((LocalCh < 0) || (LocalCh >= ExtSyncChBuffer_channels));
			if ((!chan_ignore_60)) {
				ExtSyncChBuffer.write(m_ExtSyncCh_37, 0, LocalCh);
				
			};
			
		};
		if ((__m_delta_61(m_ExtSyncStatus_38) != ((int)0))) {
			int ExtSyncStatusBuffer_dim = ExtSyncStatusBuffer.dim;
			int ExtSyncStatusBuffer_channels = ExtSyncStatusBuffer.channels;
			bool chan_ignore_62 = ((LocalCh < 0) || (LocalCh >= ExtSyncStatusBuffer_channels));
			if ((!chan_ignore_62)) {
				ExtSyncStatusBuffer.write(m_ExtSyncStatus_38, 0, LocalCh);
				
			};
			
		};
		if ((__m_delta_63(m_RatioNumerator_43) != ((int)0))) {
			int RatioNbuffer_dim = RatioNbuffer.dim;
			int RatioNbuffer_channels = RatioNbuffer.channels;
			bool chan_ignore_64 = ((LocalCh < 0) || (LocalCh >= RatioNbuffer_channels));
			if ((!chan_ignore_64)) {
				RatioNbuffer.write(m_RatioNumerator_43, 0, LocalCh);
				
			};
			
		};
		if ((__m_delta_65(m_RatioDenominator_44) != ((int)0))) {
			int RatioDbuffer_dim = RatioDbuffer.dim;
			int RatioDbuffer_channels = RatioDbuffer.channels;
			bool chan_ignore_66 = ((LocalCh < 0) || (LocalCh >= RatioDbuffer_channels));
			if ((!chan_ignore_66)) {
				RatioDbuffer.write(m_RatioDenominator_44, 0, LocalCh);
				
			};
			
		};
		if ((__m_delta_67(m_Clip_49) != ((int)0))) {
			int ClipInfoBuffer_dim = ClipInfoBuffer.dim;
			int ClipInfoBuffer_channels = ClipInfoBuffer.channels;
			bool chan_ignore_68 = ((LocalCh < 0) || (LocalCh >= ClipInfoBuffer_channels));
			if ((!chan_ignore_68)) {
				ClipInfoBuffer.write(m_Clip_49, 0, LocalCh);
				
			};
			
		};
		m_SampleCount_25 = (m_SampleCount_25 + ((int)1));
		if ((m_SampleCount_25 > m_LoopSize_24)) {
			m_SampleCount_25 = ((int)0);
			
		};
		if (((SelectedCh == m_ExtSyncCh_37) && (__m_delta_69(bReset) > ((int)0)))) {
			m_ExtSyncStatus_38 = ((int)0);
			m_ExtSyncCh_37 = (-((int)1));
			m_SyncLoopSize_39 = ((int)0);
			int LoopSizeBuffer_dim = LoopSizeBuffer.dim;
			int LoopSizeBuffer_channels = LoopSizeBuffer.channels;
			// samples LoopSizeBuffer channel 1;
			t_sample peek_870 = LoopSizeBuffer.read(0, 0);
			t_sample peek_871 = ((int)0);
			if ((peek_870 > ((int)0))) {
				m_ExtSyncCh_37 = ((int)0);
				
			};
			
		};
		if ((SelectedCh == LocalCh)) {
			int RecordStatusBuffer_dim = RecordStatusBuffer.dim;
			int RecordStatusBuffer_channels = RecordStatusBuffer.channels;
			// samples RecordStatusBuffer channel 1;
			int chan_70 = m_InputCh_23;
			bool chan_ignore_71 = ((chan_70 < 0) || (chan_70 >= RecordStatusBuffer_channels));
			t_sample peek_872 = (chan_ignore_71 ? 0 : RecordStatusBuffer.read(0, chan_70));
			t_sample peek_873 = ((int)0);
			int LoopSizeBuffer_dim = LoopSizeBuffer.dim;
			int LoopSizeBuffer_channels = LoopSizeBuffer.channels;
			// samples LoopSizeBuffer channel 1;
			int chan_72 = m_InputCh_23;
			bool chan_ignore_73 = ((chan_72 < 0) || (chan_72 >= LoopSizeBuffer_channels));
			t_sample peek_874 = (chan_ignore_73 ? 0 : LoopSizeBuffer.read(0, chan_72));
			t_sample peek_875 = ((int)0);
			if ((((m_InputCh_23 == ((int)0)) && (__m_delta_74(peek_872) == (-((int)1)))) && (__m_delta_75(peek_874) != ((int)0)))) {
				m_ExtSyncCh_37 = ((int)0);
				
			};
			// samples LoopSizeBuffer channel 1;
			int chan_76 = m_InputCh_23;
			bool chan_ignore_77 = ((chan_76 < 0) || (chan_76 >= LoopSizeBuffer_channels));
			t_sample peek_876 = (chan_ignore_77 ? 0 : LoopSizeBuffer.read(0, chan_76));
			t_sample peek_877 = ((int)0);
			if (((((GridMode == ((int)1)) && (peek_876 != ((int)0))) && (m_InputCh_23 != LocalCh)) && (m_LoopSize_24 == ((int)0)))) {
				__m_latch_78 = (((__m_delta_79(m_InputCh_23) > ((int)0)) != 0) ? m_InputCh_23 : __m_latch_78);
				m_ExtSyncCh_37 = __m_latch_78;
				
			};
			if (((m_RatioState_45 == ((int)0)) && (SyncRatioButton > ((int)0)))) {
				m_RatioNumerator_43 = SyncRatio;
				m_RatioDenominator_44 = ((int)1);
				m_Ratio_42 = SyncRatio;
				m_RatioState_45 = ((int)1);
				
			};
			if ((((m_RatioState_45 != ((int)0)) && (__m_delta_80(SyncRatioButton) < ((int)0))) && (__m_delta_81(m_Ratio_42) == ((int)0)))) {
				m_RatioDenominator_44 = SyncRatio;
				m_Ratio_42 = safediv(m_Ratio_42, SyncRatio);
				m_RatioState_45 = ((int)0);
				
			};
			if ((((m_ExtSyncCh_37 >= ((int)0)) && (m_Ratio_42 > ((int)0))) && (m_LoopSize_24 == ((int)0)))) {
				__m_latch_82 = (((__m_delta_83(bExtSync) > ((int)0)) != 0) ? (!m_ExtSyncStatus_38) : __m_latch_82);
				m_ExtSyncStatus_38 = __m_latch_82;
				
			};
			if ((m_ExtSyncStatus_38 == ((int)1))) {
				// samples LoopSizeBuffer channel 1;
				int chan_84 = m_ExtSyncCh_37;
				bool chan_ignore_85 = ((chan_84 < 0) || (chan_84 >= LoopSizeBuffer_channels));
				m_SyncLoopSize_39 = (chan_ignore_85 ? 0 : LoopSizeBuffer.read(0, chan_84));
				int SampleCountBuffer_dim = SampleCountBuffer.dim;
				int SampleCountBuffer_channels = SampleCountBuffer.channels;
				// samples SampleCountBuffer channel 1;
				int chan_86 = m_ExtSyncCh_37;
				bool chan_ignore_87 = ((chan_86 < 0) || (chan_86 >= SampleCountBuffer_channels));
				m_SyncCounter_40 = (chan_ignore_87 ? 0 : SampleCountBuffer.read(0, chan_86));
				
			};
			if ((((m_ExtSyncStatus_38 == ((int)1)) && (m_Overdub_26 == ((int)1))) || (bReset == ((int)1)))) {
				__m_latch_88 = ((((__m_delta_89(bRec) > ((int)0)) || (__m_delta_90(m_Record_28) == (-((int)1)))) != 0) ? (!m_SyncRec_30) : __m_latch_88);
				m_SyncRec_30 = __m_latch_88;
				__m_latch_91 = (((((m_SyncRec_30 == ((int)1)) && ((m_Record_28 == ((int)0)) && (m_SyncCounter_40 == ((int)0)))) || ((m_Record_28 == ((int)1)) && (m_SampleCount_25 == round((m_SyncLoopSize_39 * m_Ratio_42))))) != 0) ? (!m_Record_28) : __m_latch_91);
				m_Record_28 = __m_latch_91;
				
			};
			if ((((m_ExtSyncStatus_38 == ((int)0)) && ((m_SyncOverdubStatus_27 == ((int)0)) || (m_Overdub_26 == ((int)1)))) && (__m_delta_92(bRec) > ((int)0)))) {
				m_Record_28 = (!m_Record_28);
				
			};
			if (((((m_ExtSyncStatus_38 == ((int)1)) && (m_Overdub_26 != ((int)1))) && (m_SyncOverdubStatus_27 == ((int)0))) && (__m_delta_93(bRec) > ((int)0)))) {
				m_Record_28 = (!m_Record_28);
				
			};
			if (((__m_delta_94(m_Record_28) == (-((int)1))) && (bReset == ((int)0)))) {
				m_Overdub_26 = (m_Overdub_26 + ((int)1));
				
			};
			if (((m_Overdub_26 != ((int)1)) && (m_Record_28 == ((int)1)))) {
				int LoopBuffer_dim = LoopBuffer.dim;
				int LoopBuffer_channels = LoopBuffer.channels;
				int chan_clamp_95 = clamp(LocalCh, 0, (LoopBuffer_channels - 1));
				int index_trunc_96 = fixnan(floor(m_SampleCount_25));
				double index_fract_97 = (m_SampleCount_25 - index_trunc_96);
				int index_trunc_98 = (index_trunc_96 + 1);
				int index_wrap_99 = ((index_trunc_96 < 0) ? ((LoopBuffer_dim - 1) + ((index_trunc_96 + 1) % LoopBuffer_dim)) : (index_trunc_96 % LoopBuffer_dim));
				int index_wrap_100 = ((index_trunc_98 < 0) ? ((LoopBuffer_dim - 1) + ((index_trunc_98 + 1) % LoopBuffer_dim)) : (index_trunc_98 % LoopBuffer_dim));
				LoopBuffer.blend(mix(Audio_in, LoopBuffer.read(index_wrap_99, chan_clamp_95), (((int)1) - safediv(((int)1), m_Overdub_26))), index_wrap_99, chan_clamp_95, index_fract_97);
				LoopBuffer.blend(mix(Audio_in, LoopBuffer.read(index_wrap_100, chan_clamp_95), (((int)1) - safediv(((int)1), m_Overdub_26))), index_wrap_100, chan_clamp_95, (1 - index_fract_97));
				
			};
			__m_latch_101 = (((__m_delta_102(bSyncOverdubs) > ((int)0)) != 0) ? (!m_SyncOverdubStatus_27) : __m_latch_101);
			m_SyncOverdubStatus_27 = __m_latch_101;
			if (((m_SyncOverdubStatus_27 == ((int)1)) && (m_Overdub_26 != ((int)1)))) {
				if (((m_Record_28 == ((int)0)) && (__m_delta_103(bRec) > ((int)0)))) {
					m_RecordOverdub_29 = ((int)1);
					
				};
				if (((m_Record_28 == ((int)1)) && (m_SampleCount_25 == ((int)0)))) {
					m_RecordOverdub_29 = ((int)0);
					
				};
				__m_latch_104 = (((m_SampleCount_25 == ((int)0)) != 0) ? m_RecordOverdub_29 : __m_latch_104);
				m_Record_28 = __m_latch_104;
				
			};
			if (((m_Overdub_26 == ((int)1)) || (bReset == ((int)1)))) {
				m_LoopSize_24 = __m_pluseq_105.post(m_Record_28, ((__m_delta_106(m_Record_28) > ((int)0)) || (bReset == ((int)1))), 0);
				if ((__m_delta_107(m_LoopSize_24) != ((int)0))) {
					int LoopBuffer_dim = LoopBuffer.dim;
					int LoopBuffer_channels = LoopBuffer.channels;
					bool chan_ignore_108 = ((LocalCh < 0) || (LocalCh >= LoopBuffer_channels));
					int index_trunc_109 = fixnan(floor(m_LoopSize_24));
					bool index_ignore_110 = ((index_trunc_109 >= LoopBuffer_dim) || (index_trunc_109 < 0));
					if ((!(chan_ignore_108 || index_ignore_110))) {
						LoopBuffer.write(Audio_in, index_trunc_109, LocalCh);
						
					};
					
				};
				
			};
			if (((__m_delta_111(bReset) > ((int)0)) || (m_ResetState_32 == ((int)1)))) {
				(m_ResetState_32 == ((int)1));
				m_Dynamic_48 = ((int)0);
				// for loop initializer;
				t_sample i = (m_gCount_31 * ((int)100));
				// for loop condition;
				while (((i < ((m_gCount_31 * ((int)100)) + ((int)100))) && (i <= m_LoopSize_24))) {
					// abort processing if an infinite loop is suspected;
					if (((__loopcount--) <= 0)) {
						__exception = GENLIB_ERR_LOOP_OVERFLOW;
						break ;
						
					};
					int LoopBuffer_dim = LoopBuffer.dim;
					int LoopBuffer_channels = LoopBuffer.channels;
					bool chan_ignore_112 = ((LocalCh < 0) || (LocalCh >= LoopBuffer_channels));
					int index_trunc_113 = fixnan(floor(i));
					bool index_ignore_114 = ((index_trunc_113 >= LoopBuffer_dim) || (index_trunc_113 < 0));
					if ((!(chan_ignore_112 || index_ignore_114))) {
						LoopBuffer.write(((int)0), index_trunc_113, LocalCh);
						
					};
					int UndoBuffer_dim = UndoBuffer.dim;
					int UndoBuffer_channels = UndoBuffer.channels;
					bool chan_ignore_115 = (((((int)2) * LocalCh) < 0) || ((((int)2) * LocalCh) >= UndoBuffer_channels));
					int index_trunc_116 = fixnan(floor(i));
					bool index_ignore_117 = ((index_trunc_116 >= UndoBuffer_dim) || (index_trunc_116 < 0));
					if ((!(chan_ignore_115 || index_ignore_117))) {
						UndoBuffer.write(((int)0), index_trunc_116, (((int)2) * LocalCh));
						
					};
					bool chan_ignore_118 = ((((((int)2) * LocalCh) + ((int)1)) < 0) || (((((int)2) * LocalCh) + ((int)1)) >= UndoBuffer_channels));
					int index_trunc_119 = fixnan(floor(i));
					bool index_ignore_120 = ((index_trunc_119 >= UndoBuffer_dim) || (index_trunc_119 < 0));
					if ((!(chan_ignore_118 || index_ignore_120))) {
						UndoBuffer.write(((int)0), index_trunc_119, ((((int)2) * LocalCh) + ((int)1)));
						
					};
					if ((i == m_LoopSize_24)) {
						m_LoopSize_24 = ((int)0);
						
					};
					// for loop increment;
					i = (i + ((int)1));
					
				};
				m_gCount_31 = (m_gCount_31 + ((int)1));
				if ((m_LoopSize_24 == ((int)0))) {
					m_gCount_31 = ((int)0);
					m_ResetState_32 = ((int)0);
					m_RecordOverdub_29 = ((int)0);
					m_Record_28 = ((int)0);
					m_Overdub_26 = ((int)1);
					m_SampleCount_25 = ((int)0);
					m_OverdubNundo_34 = ((int)0);
					m_Clip_49 = ((int)0);
					
				};
				
			};
			if ((__m_delta_121(bUndo) > ((int)0))) {
				m_OverdubNundo_34 = (m_OverdubNundo_34 + ((int)1));
				
			};
			if ((m_Record_28 == ((int)1))) {
				m_OverdubNundo_34 = ((int)0);
				
			};
			if (((m_Overdub_26 > ((int)1)) && (__m_delta_122(safemod(m_OverdubNundo_34, ((int)2))) == ((int)1)))) {
				m_Overdub_26 = (m_Overdub_26 - ((int)1));
				
			};
			if (((m_OverdubNundo_34 > ((int)0)) && (__m_delta_123(safemod(m_OverdubNundo_34, ((int)2))) == (-((int)1))))) {
				m_Overdub_26 = (m_Overdub_26 + ((int)1));
				
			};
			if (((m_Record_28 == ((int)1)) && (fabs(Audio_in) >= ((int)1)))) {
				m_Clip_49 = ((int)1);
				m_ClipOverdubN_50 = (m_Overdub_26 + ((int)1));
				
			};
			if (((m_Overdub_26 == (m_ClipOverdubN_50 - ((int)1))) && (m_Record_28 == ((int)0)))) {
				m_Clip_49 = ((int)0);
				
			};
			if (((__m_delta_124(m_Record_28) == (-((int)1))) || (m_Undo1State_35 == ((int)1)))) {
				m_Undo1State_35 = ((int)1);
				// for loop initializer;
				t_sample i = (m_gCount_31 * ((int)40));
				// for loop condition;
				while (((i < ((m_gCount_31 * ((int)40)) + ((int)40))) && (i <= m_LoopSize_24))) {
					// abort processing if an infinite loop is suspected;
					if (((__loopcount--) <= 0)) {
						__exception = GENLIB_ERR_LOOP_OVERFLOW;
						break ;
						
					};
					int LoopBuffer_dim = LoopBuffer.dim;
					int LoopBuffer_channels = LoopBuffer.channels;
					int index_trunc_125 = fixnan(floor(i));
					bool index_ignore_126 = ((index_trunc_125 >= LoopBuffer_dim) || (index_trunc_125 < 0));
					// samples LoopBuffer channel 1;
					int chan_127 = LocalCh;
					bool chan_ignore_128 = ((chan_127 < 0) || (chan_127 >= LoopBuffer_channels));
					t_sample peek_878 = ((chan_ignore_128 || index_ignore_126) ? 0 : LoopBuffer.read(index_trunc_125, chan_127));
					t_sample peek_879 = i;
					int UndoBuffer_dim = UndoBuffer.dim;
					int UndoBuffer_channels = UndoBuffer.channels;
					int channel_trunc_129 = fixnan(floor(((((int)2) * LocalCh) + m_UndoChannel_33)));
					bool chan_ignore_130 = ((channel_trunc_129 < 0) || (channel_trunc_129 >= UndoBuffer_channels));
					int index_trunc_131 = fixnan(floor(i));
					bool index_ignore_132 = ((index_trunc_131 >= UndoBuffer_dim) || (index_trunc_131 < 0));
					if ((!(chan_ignore_130 || index_ignore_132))) {
						UndoBuffer.write(peek_878, index_trunc_131, channel_trunc_129);
						
					};
					if ((i == m_LoopSize_24)) {
						m_Undo1State_35 = ((int)0);
						
					};
					int index_trunc_133 = fixnan(floor(i));
					bool index_ignore_134 = ((index_trunc_133 >= LoopBuffer_dim) || (index_trunc_133 < 0));
					// samples LoopBuffer channel 1;
					int chan_135 = LocalCh;
					bool chan_ignore_136 = ((chan_135 < 0) || (chan_135 >= LoopBuffer_channels));
					t_sample peek_880 = ((chan_ignore_136 || index_ignore_134) ? 0 : LoopBuffer.read(index_trunc_133, chan_135));
					t_sample peek_881 = i;
					if ((m_Peak_47 < fabs(peek_880))) {
						int index_trunc_137 = fixnan(floor(i));
						bool index_ignore_138 = ((index_trunc_137 >= LoopBuffer_dim) || (index_trunc_137 < 0));
						// samples LoopBuffer channel 1;
						int chan_139 = LocalCh;
						bool chan_ignore_140 = ((chan_139 < 0) || (chan_139 >= LoopBuffer_channels));
						t_sample peek_882 = ((chan_ignore_140 || index_ignore_138) ? 0 : LoopBuffer.read(index_trunc_137, chan_139));
						t_sample peek_883 = i;
						m_Peak_47 = fabs(peek_882);
						
					};
					if ((i == m_LoopSize_24)) {
						m_Dynamic_48 = safediv(((t_sample)0.999), m_Peak_47);
						m_Peak_47 = ((int)0);
						
					};
					// for loop increment;
					i = (i + ((int)1));
					
				};
				m_gCount_31 = (m_gCount_31 + ((int)1));
				if ((m_Undo1State_35 == ((int)0))) {
					m_gCount_31 = ((int)0);
					m_UndoChannel_33 = (!m_UndoChannel_33);
					
				};
				
			};
			if (((__m_delta_141(bUndo) > ((int)0)) || (m_Undo2State_36 == ((int)1)))) {
				m_Undo2State_36 = ((int)1);
				// for loop initializer;
				t_sample i = (m_gCount_31 * ((int)40));
				// for loop condition;
				while (((i < ((m_gCount_31 * ((int)40)) + ((int)40))) && (i <= m_LoopSize_24))) {
					// abort processing if an infinite loop is suspected;
					if (((__loopcount--) <= 0)) {
						__exception = GENLIB_ERR_LOOP_OVERFLOW;
						break ;
						
					};
					int UndoBuffer_dim = UndoBuffer.dim;
					int UndoBuffer_channels = UndoBuffer.channels;
					int index_trunc_142 = fixnan(floor(i));
					bool index_ignore_143 = ((index_trunc_142 >= UndoBuffer_dim) || (index_trunc_142 < 0));
					// samples UndoBuffer channel 1;
					int chan_144 = ((((int)2) * LocalCh) + m_UndoChannel_33);
					bool chan_ignore_145 = ((chan_144 < 0) || (chan_144 >= UndoBuffer_channels));
					t_sample peek_884 = ((chan_ignore_145 || index_ignore_143) ? 0 : UndoBuffer.read(index_trunc_142, chan_144));
					t_sample peek_885 = i;
					int LoopBuffer_dim = LoopBuffer.dim;
					int LoopBuffer_channels = LoopBuffer.channels;
					bool chan_ignore_146 = ((LocalCh < 0) || (LocalCh >= LoopBuffer_channels));
					int index_trunc_147 = fixnan(floor(i));
					bool index_ignore_148 = ((index_trunc_147 >= LoopBuffer_dim) || (index_trunc_147 < 0));
					if ((!(chan_ignore_146 || index_ignore_148))) {
						LoopBuffer.write(peek_884, index_trunc_147, LocalCh);
						
					};
					if ((i == m_LoopSize_24)) {
						m_Undo2State_36 = ((int)0);
						
					};
					// for loop increment;
					i = (i + ((int)1));
					
				};
				m_gCount_31 = (m_gCount_31 + ((int)1));
				if ((m_Undo2State_36 == ((int)0))) {
					m_gCount_31 = ((int)0);
					m_UndoChannel_33 = (!m_UndoChannel_33);
					
				};
				
			};
			
		};
		int LoopBuffer_dim = LoopBuffer.dim;
		int LoopBuffer_channels = LoopBuffer.channels;
		int index_trunc_149 = fixnan(floor(m_SampleCount_25));
		bool index_ignore_150 = ((index_trunc_149 >= LoopBuffer_dim) || (index_trunc_149 < 0));
		// samples LoopBuffer channel 1;
		int chan_151 = LocalCh;
		bool chan_ignore_152 = ((chan_151 < 0) || (chan_151 >= LoopBuffer_channels));
		t_sample Loop = ((chan_ignore_152 || index_ignore_150) ? 0 : LoopBuffer.read(index_trunc_149, chan_151));
		t_sample Loop_index = m_SampleCount_25;
		if (((__m_delta_153(m_LoopSize_24) == ((int)0)) && (m_LoopSize_24 > ((int)0)))) {
			m_output_46 = (Loop * m_Dynamic_48);
			
		};
		return m_output_46;
		
	};
	inline t_sample Looper_d_d_i_d_d_d_d_d_d_d_d_d_dat_dat_dat_dat_dat_dat_dat_dat_dat_dat_dat_154(t_sample Audio_in, t_sample SelectedCh, int LocalCh, t_sample m_InputCh_23, t_sample GridMode, t_sample bRec, t_sample bReset, t_sample bUndo, t_sample bSyncOverdubs, t_sample bExtSync, t_sample SyncRatio, t_sample SyncRatioButton, Data& LoopBuffer, Data& UndoBuffer, Data& SampleCountBuffer, Data& LoopSizeBuffer, Data& ExtSyncChBuffer, Data& SyncOverdubStatusBuffer, Data& ExtSyncStatusBuffer, Data& RecordStatusBuffer, Data& RatioNbuffer, Data& RatioDbuffer, Data& ClipInfoBuffer) {
		if ((__m_delta_182(m_SyncOverdubStatus_158) != ((int)0))) {
			int SyncOverdubStatusBuffer_dim = SyncOverdubStatusBuffer.dim;
			int SyncOverdubStatusBuffer_channels = SyncOverdubStatusBuffer.channels;
			bool chan_ignore_183 = ((LocalCh < 0) || (LocalCh >= SyncOverdubStatusBuffer_channels));
			if ((!chan_ignore_183)) {
				SyncOverdubStatusBuffer.write(m_SyncOverdubStatus_158, 0, LocalCh);
				
			};
			
		};
		if ((__m_delta_184(m_Record_159) != ((int)0))) {
			int RecordStatusBuffer_dim = RecordStatusBuffer.dim;
			int RecordStatusBuffer_channels = RecordStatusBuffer.channels;
			bool chan_ignore_185 = ((LocalCh < 0) || (LocalCh >= RecordStatusBuffer_channels));
			if ((!chan_ignore_185)) {
				RecordStatusBuffer.write(m_Record_159, 0, LocalCh);
				
			};
			
		};
		if (((m_LoopSize_155 > ((int)0)) || (__m_delta_186(bReset) > ((int)0)))) {
			int SampleCountBuffer_dim = SampleCountBuffer.dim;
			int SampleCountBuffer_channels = SampleCountBuffer.channels;
			bool chan_ignore_187 = ((LocalCh < 0) || (LocalCh >= SampleCountBuffer_channels));
			if ((!chan_ignore_187)) {
				SampleCountBuffer.write(m_SampleCount_156, 0, LocalCh);
				
			};
			
		};
		if ((__m_delta_188(m_LoopSize_155) != ((int)0))) {
			int LoopSizeBuffer_dim = LoopSizeBuffer.dim;
			int LoopSizeBuffer_channels = LoopSizeBuffer.channels;
			bool chan_ignore_189 = ((LocalCh < 0) || (LocalCh >= LoopSizeBuffer_channels));
			if ((!chan_ignore_189)) {
				LoopSizeBuffer.write(m_LoopSize_155, 0, LocalCh);
				
			};
			
		};
		if ((__m_delta_190(m_ExtSyncCh_168) != ((int)0))) {
			int ExtSyncChBuffer_dim = ExtSyncChBuffer.dim;
			int ExtSyncChBuffer_channels = ExtSyncChBuffer.channels;
			bool chan_ignore_191 = ((LocalCh < 0) || (LocalCh >= ExtSyncChBuffer_channels));
			if ((!chan_ignore_191)) {
				ExtSyncChBuffer.write(m_ExtSyncCh_168, 0, LocalCh);
				
			};
			
		};
		if ((__m_delta_192(m_ExtSyncStatus_169) != ((int)0))) {
			int ExtSyncStatusBuffer_dim = ExtSyncStatusBuffer.dim;
			int ExtSyncStatusBuffer_channels = ExtSyncStatusBuffer.channels;
			bool chan_ignore_193 = ((LocalCh < 0) || (LocalCh >= ExtSyncStatusBuffer_channels));
			if ((!chan_ignore_193)) {
				ExtSyncStatusBuffer.write(m_ExtSyncStatus_169, 0, LocalCh);
				
			};
			
		};
		if ((__m_delta_194(m_RatioNumerator_174) != ((int)0))) {
			int RatioNbuffer_dim = RatioNbuffer.dim;
			int RatioNbuffer_channels = RatioNbuffer.channels;
			bool chan_ignore_195 = ((LocalCh < 0) || (LocalCh >= RatioNbuffer_channels));
			if ((!chan_ignore_195)) {
				RatioNbuffer.write(m_RatioNumerator_174, 0, LocalCh);
				
			};
			
		};
		if ((__m_delta_196(m_RatioDenominator_175) != ((int)0))) {
			int RatioDbuffer_dim = RatioDbuffer.dim;
			int RatioDbuffer_channels = RatioDbuffer.channels;
			bool chan_ignore_197 = ((LocalCh < 0) || (LocalCh >= RatioDbuffer_channels));
			if ((!chan_ignore_197)) {
				RatioDbuffer.write(m_RatioDenominator_175, 0, LocalCh);
				
			};
			
		};
		if ((__m_delta_198(m_Clip_180) != ((int)0))) {
			int ClipInfoBuffer_dim = ClipInfoBuffer.dim;
			int ClipInfoBuffer_channels = ClipInfoBuffer.channels;
			bool chan_ignore_199 = ((LocalCh < 0) || (LocalCh >= ClipInfoBuffer_channels));
			if ((!chan_ignore_199)) {
				ClipInfoBuffer.write(m_Clip_180, 0, LocalCh);
				
			};
			
		};
		m_SampleCount_156 = (m_SampleCount_156 + ((int)1));
		if ((m_SampleCount_156 > m_LoopSize_155)) {
			m_SampleCount_156 = ((int)0);
			
		};
		if (((SelectedCh == m_ExtSyncCh_168) && (__m_delta_200(bReset) > ((int)0)))) {
			m_ExtSyncStatus_169 = ((int)0);
			m_ExtSyncCh_168 = (-((int)1));
			m_SyncLoopSize_170 = ((int)0);
			int LoopSizeBuffer_dim = LoopSizeBuffer.dim;
			int LoopSizeBuffer_channels = LoopSizeBuffer.channels;
			// samples LoopSizeBuffer channel 1;
			t_sample peek_870 = LoopSizeBuffer.read(0, 0);
			t_sample peek_871 = ((int)0);
			if ((peek_870 > ((int)0))) {
				m_ExtSyncCh_168 = ((int)0);
				
			};
			
		};
		if ((SelectedCh == LocalCh)) {
			int RecordStatusBuffer_dim = RecordStatusBuffer.dim;
			int RecordStatusBuffer_channels = RecordStatusBuffer.channels;
			// samples RecordStatusBuffer channel 1;
			int chan_201 = m_InputCh_23;
			bool chan_ignore_202 = ((chan_201 < 0) || (chan_201 >= RecordStatusBuffer_channels));
			t_sample peek_872 = (chan_ignore_202 ? 0 : RecordStatusBuffer.read(0, chan_201));
			t_sample peek_873 = ((int)0);
			int LoopSizeBuffer_dim = LoopSizeBuffer.dim;
			int LoopSizeBuffer_channels = LoopSizeBuffer.channels;
			// samples LoopSizeBuffer channel 1;
			int chan_203 = m_InputCh_23;
			bool chan_ignore_204 = ((chan_203 < 0) || (chan_203 >= LoopSizeBuffer_channels));
			t_sample peek_874 = (chan_ignore_204 ? 0 : LoopSizeBuffer.read(0, chan_203));
			t_sample peek_875 = ((int)0);
			if ((((m_InputCh_23 == ((int)0)) && (__m_delta_205(peek_872) == (-((int)1)))) && (__m_delta_206(peek_874) != ((int)0)))) {
				m_ExtSyncCh_168 = ((int)0);
				
			};
			// samples LoopSizeBuffer channel 1;
			int chan_207 = m_InputCh_23;
			bool chan_ignore_208 = ((chan_207 < 0) || (chan_207 >= LoopSizeBuffer_channels));
			t_sample peek_876 = (chan_ignore_208 ? 0 : LoopSizeBuffer.read(0, chan_207));
			t_sample peek_877 = ((int)0);
			if (((((GridMode == ((int)1)) && (peek_876 != ((int)0))) && (m_InputCh_23 != LocalCh)) && (m_LoopSize_155 == ((int)0)))) {
				__m_latch_209 = (((__m_delta_210(m_InputCh_23) > ((int)0)) != 0) ? m_InputCh_23 : __m_latch_209);
				m_ExtSyncCh_168 = __m_latch_209;
				
			};
			if (((m_RatioState_176 == ((int)0)) && (SyncRatioButton > ((int)0)))) {
				m_RatioNumerator_174 = SyncRatio;
				m_RatioDenominator_175 = ((int)1);
				m_Ratio_173 = SyncRatio;
				m_RatioState_176 = ((int)1);
				
			};
			if ((((m_RatioState_176 != ((int)0)) && (__m_delta_211(SyncRatioButton) < ((int)0))) && (__m_delta_212(m_Ratio_173) == ((int)0)))) {
				m_RatioDenominator_175 = SyncRatio;
				m_Ratio_173 = safediv(m_Ratio_173, SyncRatio);
				m_RatioState_176 = ((int)0);
				
			};
			if ((((m_ExtSyncCh_168 >= ((int)0)) && (m_Ratio_173 > ((int)0))) && (m_LoopSize_155 == ((int)0)))) {
				__m_latch_213 = (((__m_delta_214(bExtSync) > ((int)0)) != 0) ? (!m_ExtSyncStatus_169) : __m_latch_213);
				m_ExtSyncStatus_169 = __m_latch_213;
				
			};
			if ((m_ExtSyncStatus_169 == ((int)1))) {
				// samples LoopSizeBuffer channel 1;
				int chan_215 = m_ExtSyncCh_168;
				bool chan_ignore_216 = ((chan_215 < 0) || (chan_215 >= LoopSizeBuffer_channels));
				m_SyncLoopSize_170 = (chan_ignore_216 ? 0 : LoopSizeBuffer.read(0, chan_215));
				int SampleCountBuffer_dim = SampleCountBuffer.dim;
				int SampleCountBuffer_channels = SampleCountBuffer.channels;
				// samples SampleCountBuffer channel 1;
				int chan_217 = m_ExtSyncCh_168;
				bool chan_ignore_218 = ((chan_217 < 0) || (chan_217 >= SampleCountBuffer_channels));
				m_SyncCounter_171 = (chan_ignore_218 ? 0 : SampleCountBuffer.read(0, chan_217));
				
			};
			if ((((m_ExtSyncStatus_169 == ((int)1)) && (m_Overdub_157 == ((int)1))) || (bReset == ((int)1)))) {
				__m_latch_219 = ((((__m_delta_220(bRec) > ((int)0)) || (__m_delta_221(m_Record_159) == (-((int)1)))) != 0) ? (!m_SyncRec_161) : __m_latch_219);
				m_SyncRec_161 = __m_latch_219;
				__m_latch_222 = (((((m_SyncRec_161 == ((int)1)) && ((m_Record_159 == ((int)0)) && (m_SyncCounter_171 == ((int)0)))) || ((m_Record_159 == ((int)1)) && (m_SampleCount_156 == round((m_SyncLoopSize_170 * m_Ratio_173))))) != 0) ? (!m_Record_159) : __m_latch_222);
				m_Record_159 = __m_latch_222;
				
			};
			if ((((m_ExtSyncStatus_169 == ((int)0)) && ((m_SyncOverdubStatus_158 == ((int)0)) || (m_Overdub_157 == ((int)1)))) && (__m_delta_223(bRec) > ((int)0)))) {
				m_Record_159 = (!m_Record_159);
				
			};
			if (((((m_ExtSyncStatus_169 == ((int)1)) && (m_Overdub_157 != ((int)1))) && (m_SyncOverdubStatus_158 == ((int)0))) && (__m_delta_224(bRec) > ((int)0)))) {
				m_Record_159 = (!m_Record_159);
				
			};
			if (((__m_delta_225(m_Record_159) == (-((int)1))) && (bReset == ((int)0)))) {
				m_Overdub_157 = (m_Overdub_157 + ((int)1));
				
			};
			if (((m_Overdub_157 != ((int)1)) && (m_Record_159 == ((int)1)))) {
				int LoopBuffer_dim = LoopBuffer.dim;
				int LoopBuffer_channels = LoopBuffer.channels;
				int chan_clamp_226 = clamp(LocalCh, 0, (LoopBuffer_channels - 1));
				int index_trunc_227 = fixnan(floor(m_SampleCount_156));
				double index_fract_228 = (m_SampleCount_156 - index_trunc_227);
				int index_trunc_229 = (index_trunc_227 + 1);
				int index_wrap_230 = ((index_trunc_227 < 0) ? ((LoopBuffer_dim - 1) + ((index_trunc_227 + 1) % LoopBuffer_dim)) : (index_trunc_227 % LoopBuffer_dim));
				int index_wrap_231 = ((index_trunc_229 < 0) ? ((LoopBuffer_dim - 1) + ((index_trunc_229 + 1) % LoopBuffer_dim)) : (index_trunc_229 % LoopBuffer_dim));
				LoopBuffer.blend(mix(Audio_in, LoopBuffer.read(index_wrap_230, chan_clamp_226), (((int)1) - safediv(((int)1), m_Overdub_157))), index_wrap_230, chan_clamp_226, index_fract_228);
				LoopBuffer.blend(mix(Audio_in, LoopBuffer.read(index_wrap_231, chan_clamp_226), (((int)1) - safediv(((int)1), m_Overdub_157))), index_wrap_231, chan_clamp_226, (1 - index_fract_228));
				
			};
			__m_latch_232 = (((__m_delta_233(bSyncOverdubs) > ((int)0)) != 0) ? (!m_SyncOverdubStatus_158) : __m_latch_232);
			m_SyncOverdubStatus_158 = __m_latch_232;
			if (((m_SyncOverdubStatus_158 == ((int)1)) && (m_Overdub_157 != ((int)1)))) {
				if (((m_Record_159 == ((int)0)) && (__m_delta_234(bRec) > ((int)0)))) {
					m_RecordOverdub_160 = ((int)1);
					
				};
				if (((m_Record_159 == ((int)1)) && (m_SampleCount_156 == ((int)0)))) {
					m_RecordOverdub_160 = ((int)0);
					
				};
				__m_latch_235 = (((m_SampleCount_156 == ((int)0)) != 0) ? m_RecordOverdub_160 : __m_latch_235);
				m_Record_159 = __m_latch_235;
				
			};
			if (((m_Overdub_157 == ((int)1)) || (bReset == ((int)1)))) {
				m_LoopSize_155 = __m_pluseq_236.post(m_Record_159, ((__m_delta_237(m_Record_159) > ((int)0)) || (bReset == ((int)1))), 0);
				if ((__m_delta_238(m_LoopSize_155) != ((int)0))) {
					int LoopBuffer_dim = LoopBuffer.dim;
					int LoopBuffer_channels = LoopBuffer.channels;
					bool chan_ignore_239 = ((LocalCh < 0) || (LocalCh >= LoopBuffer_channels));
					int index_trunc_240 = fixnan(floor(m_LoopSize_155));
					bool index_ignore_241 = ((index_trunc_240 >= LoopBuffer_dim) || (index_trunc_240 < 0));
					if ((!(chan_ignore_239 || index_ignore_241))) {
						LoopBuffer.write(Audio_in, index_trunc_240, LocalCh);
						
					};
					
				};
				
			};
			if (((__m_delta_242(bReset) > ((int)0)) || (m_ResetState_163 == ((int)1)))) {
				(m_ResetState_163 == ((int)1));
				m_Dynamic_179 = ((int)0);
				// for loop initializer;
				t_sample i = (m_gCount_162 * ((int)100));
				// for loop condition;
				while (((i < ((m_gCount_162 * ((int)100)) + ((int)100))) && (i <= m_LoopSize_155))) {
					// abort processing if an infinite loop is suspected;
					if (((__loopcount--) <= 0)) {
						__exception = GENLIB_ERR_LOOP_OVERFLOW;
						break ;
						
					};
					int LoopBuffer_dim = LoopBuffer.dim;
					int LoopBuffer_channels = LoopBuffer.channels;
					bool chan_ignore_243 = ((LocalCh < 0) || (LocalCh >= LoopBuffer_channels));
					int index_trunc_244 = fixnan(floor(i));
					bool index_ignore_245 = ((index_trunc_244 >= LoopBuffer_dim) || (index_trunc_244 < 0));
					if ((!(chan_ignore_243 || index_ignore_245))) {
						LoopBuffer.write(((int)0), index_trunc_244, LocalCh);
						
					};
					int UndoBuffer_dim = UndoBuffer.dim;
					int UndoBuffer_channels = UndoBuffer.channels;
					bool chan_ignore_246 = (((((int)2) * LocalCh) < 0) || ((((int)2) * LocalCh) >= UndoBuffer_channels));
					int index_trunc_247 = fixnan(floor(i));
					bool index_ignore_248 = ((index_trunc_247 >= UndoBuffer_dim) || (index_trunc_247 < 0));
					if ((!(chan_ignore_246 || index_ignore_248))) {
						UndoBuffer.write(((int)0), index_trunc_247, (((int)2) * LocalCh));
						
					};
					bool chan_ignore_249 = ((((((int)2) * LocalCh) + ((int)1)) < 0) || (((((int)2) * LocalCh) + ((int)1)) >= UndoBuffer_channels));
					int index_trunc_250 = fixnan(floor(i));
					bool index_ignore_251 = ((index_trunc_250 >= UndoBuffer_dim) || (index_trunc_250 < 0));
					if ((!(chan_ignore_249 || index_ignore_251))) {
						UndoBuffer.write(((int)0), index_trunc_250, ((((int)2) * LocalCh) + ((int)1)));
						
					};
					if ((i == m_LoopSize_155)) {
						m_LoopSize_155 = ((int)0);
						
					};
					// for loop increment;
					i = (i + ((int)1));
					
				};
				m_gCount_162 = (m_gCount_162 + ((int)1));
				if ((m_LoopSize_155 == ((int)0))) {
					m_gCount_162 = ((int)0);
					m_ResetState_163 = ((int)0);
					m_RecordOverdub_160 = ((int)0);
					m_Record_159 = ((int)0);
					m_Overdub_157 = ((int)1);
					m_SampleCount_156 = ((int)0);
					m_OverdubNundo_165 = ((int)0);
					m_Clip_180 = ((int)0);
					
				};
				
			};
			if ((__m_delta_252(bUndo) > ((int)0))) {
				m_OverdubNundo_165 = (m_OverdubNundo_165 + ((int)1));
				
			};
			if ((m_Record_159 == ((int)1))) {
				m_OverdubNundo_165 = ((int)0);
				
			};
			if (((m_Overdub_157 > ((int)1)) && (__m_delta_253(safemod(m_OverdubNundo_165, ((int)2))) == ((int)1)))) {
				m_Overdub_157 = (m_Overdub_157 - ((int)1));
				
			};
			if (((m_OverdubNundo_165 > ((int)0)) && (__m_delta_254(safemod(m_OverdubNundo_165, ((int)2))) == (-((int)1))))) {
				m_Overdub_157 = (m_Overdub_157 + ((int)1));
				
			};
			if (((m_Record_159 == ((int)1)) && (fabs(Audio_in) >= ((int)1)))) {
				m_Clip_180 = ((int)1);
				m_ClipOverdubN_181 = (m_Overdub_157 + ((int)1));
				
			};
			if (((m_Overdub_157 == (m_ClipOverdubN_181 - ((int)1))) && (m_Record_159 == ((int)0)))) {
				m_Clip_180 = ((int)0);
				
			};
			if (((__m_delta_255(m_Record_159) == (-((int)1))) || (m_Undo1State_166 == ((int)1)))) {
				m_Undo1State_166 = ((int)1);
				// for loop initializer;
				t_sample i = (m_gCount_162 * ((int)40));
				// for loop condition;
				while (((i < ((m_gCount_162 * ((int)40)) + ((int)40))) && (i <= m_LoopSize_155))) {
					// abort processing if an infinite loop is suspected;
					if (((__loopcount--) <= 0)) {
						__exception = GENLIB_ERR_LOOP_OVERFLOW;
						break ;
						
					};
					int LoopBuffer_dim = LoopBuffer.dim;
					int LoopBuffer_channels = LoopBuffer.channels;
					int index_trunc_256 = fixnan(floor(i));
					bool index_ignore_257 = ((index_trunc_256 >= LoopBuffer_dim) || (index_trunc_256 < 0));
					// samples LoopBuffer channel 1;
					int chan_258 = LocalCh;
					bool chan_ignore_259 = ((chan_258 < 0) || (chan_258 >= LoopBuffer_channels));
					t_sample peek_878 = ((chan_ignore_259 || index_ignore_257) ? 0 : LoopBuffer.read(index_trunc_256, chan_258));
					t_sample peek_879 = i;
					int UndoBuffer_dim = UndoBuffer.dim;
					int UndoBuffer_channels = UndoBuffer.channels;
					int channel_trunc_260 = fixnan(floor(((((int)2) * LocalCh) + m_UndoChannel_164)));
					bool chan_ignore_261 = ((channel_trunc_260 < 0) || (channel_trunc_260 >= UndoBuffer_channels));
					int index_trunc_262 = fixnan(floor(i));
					bool index_ignore_263 = ((index_trunc_262 >= UndoBuffer_dim) || (index_trunc_262 < 0));
					if ((!(chan_ignore_261 || index_ignore_263))) {
						UndoBuffer.write(peek_878, index_trunc_262, channel_trunc_260);
						
					};
					if ((i == m_LoopSize_155)) {
						m_Undo1State_166 = ((int)0);
						
					};
					int index_trunc_264 = fixnan(floor(i));
					bool index_ignore_265 = ((index_trunc_264 >= LoopBuffer_dim) || (index_trunc_264 < 0));
					// samples LoopBuffer channel 1;
					int chan_266 = LocalCh;
					bool chan_ignore_267 = ((chan_266 < 0) || (chan_266 >= LoopBuffer_channels));
					t_sample peek_880 = ((chan_ignore_267 || index_ignore_265) ? 0 : LoopBuffer.read(index_trunc_264, chan_266));
					t_sample peek_881 = i;
					if ((m_Peak_178 < fabs(peek_880))) {
						int index_trunc_268 = fixnan(floor(i));
						bool index_ignore_269 = ((index_trunc_268 >= LoopBuffer_dim) || (index_trunc_268 < 0));
						// samples LoopBuffer channel 1;
						int chan_270 = LocalCh;
						bool chan_ignore_271 = ((chan_270 < 0) || (chan_270 >= LoopBuffer_channels));
						t_sample peek_882 = ((chan_ignore_271 || index_ignore_269) ? 0 : LoopBuffer.read(index_trunc_268, chan_270));
						t_sample peek_883 = i;
						m_Peak_178 = fabs(peek_882);
						
					};
					if ((i == m_LoopSize_155)) {
						m_Dynamic_179 = safediv(((t_sample)0.999), m_Peak_178);
						m_Peak_178 = ((int)0);
						
					};
					// for loop increment;
					i = (i + ((int)1));
					
				};
				m_gCount_162 = (m_gCount_162 + ((int)1));
				if ((m_Undo1State_166 == ((int)0))) {
					m_gCount_162 = ((int)0);
					m_UndoChannel_164 = (!m_UndoChannel_164);
					
				};
				
			};
			if (((__m_delta_272(bUndo) > ((int)0)) || (m_Undo2State_167 == ((int)1)))) {
				m_Undo2State_167 = ((int)1);
				// for loop initializer;
				t_sample i = (m_gCount_162 * ((int)40));
				// for loop condition;
				while (((i < ((m_gCount_162 * ((int)40)) + ((int)40))) && (i <= m_LoopSize_155))) {
					// abort processing if an infinite loop is suspected;
					if (((__loopcount--) <= 0)) {
						__exception = GENLIB_ERR_LOOP_OVERFLOW;
						break ;
						
					};
					int UndoBuffer_dim = UndoBuffer.dim;
					int UndoBuffer_channels = UndoBuffer.channels;
					int index_trunc_273 = fixnan(floor(i));
					bool index_ignore_274 = ((index_trunc_273 >= UndoBuffer_dim) || (index_trunc_273 < 0));
					// samples UndoBuffer channel 1;
					int chan_275 = ((((int)2) * LocalCh) + m_UndoChannel_164);
					bool chan_ignore_276 = ((chan_275 < 0) || (chan_275 >= UndoBuffer_channels));
					t_sample peek_884 = ((chan_ignore_276 || index_ignore_274) ? 0 : UndoBuffer.read(index_trunc_273, chan_275));
					t_sample peek_885 = i;
					int LoopBuffer_dim = LoopBuffer.dim;
					int LoopBuffer_channels = LoopBuffer.channels;
					bool chan_ignore_277 = ((LocalCh < 0) || (LocalCh >= LoopBuffer_channels));
					int index_trunc_278 = fixnan(floor(i));
					bool index_ignore_279 = ((index_trunc_278 >= LoopBuffer_dim) || (index_trunc_278 < 0));
					if ((!(chan_ignore_277 || index_ignore_279))) {
						LoopBuffer.write(peek_884, index_trunc_278, LocalCh);
						
					};
					if ((i == m_LoopSize_155)) {
						m_Undo2State_167 = ((int)0);
						
					};
					// for loop increment;
					i = (i + ((int)1));
					
				};
				m_gCount_162 = (m_gCount_162 + ((int)1));
				if ((m_Undo2State_167 == ((int)0))) {
					m_gCount_162 = ((int)0);
					m_UndoChannel_164 = (!m_UndoChannel_164);
					
				};
				
			};
			
		};
		int LoopBuffer_dim = LoopBuffer.dim;
		int LoopBuffer_channels = LoopBuffer.channels;
		int index_trunc_280 = fixnan(floor(m_SampleCount_156));
		bool index_ignore_281 = ((index_trunc_280 >= LoopBuffer_dim) || (index_trunc_280 < 0));
		// samples LoopBuffer channel 1;
		int chan_282 = LocalCh;
		bool chan_ignore_283 = ((chan_282 < 0) || (chan_282 >= LoopBuffer_channels));
		t_sample Loop = ((chan_ignore_283 || index_ignore_281) ? 0 : LoopBuffer.read(index_trunc_280, chan_282));
		t_sample Loop_index = m_SampleCount_156;
		if (((__m_delta_284(m_LoopSize_155) == ((int)0)) && (m_LoopSize_155 > ((int)0)))) {
			m_output_177 = (Loop * m_Dynamic_179);
			
		};
		return m_output_177;
		
	};
	inline t_sample Looper_d_d_i_d_d_d_d_d_d_d_d_d_dat_dat_dat_dat_dat_dat_dat_dat_dat_dat_dat_285(t_sample Audio_in, t_sample SelectedCh, int LocalCh, t_sample m_InputCh_23, t_sample GridMode, t_sample bRec, t_sample bReset, t_sample bUndo, t_sample bSyncOverdubs, t_sample bExtSync, t_sample SyncRatio, t_sample SyncRatioButton, Data& LoopBuffer, Data& UndoBuffer, Data& SampleCountBuffer, Data& LoopSizeBuffer, Data& ExtSyncChBuffer, Data& SyncOverdubStatusBuffer, Data& ExtSyncStatusBuffer, Data& RecordStatusBuffer, Data& RatioNbuffer, Data& RatioDbuffer, Data& ClipInfoBuffer) {
		if ((__m_delta_313(m_SyncOverdubStatus_289) != ((int)0))) {
			int SyncOverdubStatusBuffer_dim = SyncOverdubStatusBuffer.dim;
			int SyncOverdubStatusBuffer_channels = SyncOverdubStatusBuffer.channels;
			bool chan_ignore_314 = ((LocalCh < 0) || (LocalCh >= SyncOverdubStatusBuffer_channels));
			if ((!chan_ignore_314)) {
				SyncOverdubStatusBuffer.write(m_SyncOverdubStatus_289, 0, LocalCh);
				
			};
			
		};
		if ((__m_delta_315(m_Record_290) != ((int)0))) {
			int RecordStatusBuffer_dim = RecordStatusBuffer.dim;
			int RecordStatusBuffer_channels = RecordStatusBuffer.channels;
			bool chan_ignore_316 = ((LocalCh < 0) || (LocalCh >= RecordStatusBuffer_channels));
			if ((!chan_ignore_316)) {
				RecordStatusBuffer.write(m_Record_290, 0, LocalCh);
				
			};
			
		};
		if (((m_LoopSize_286 > ((int)0)) || (__m_delta_317(bReset) > ((int)0)))) {
			int SampleCountBuffer_dim = SampleCountBuffer.dim;
			int SampleCountBuffer_channels = SampleCountBuffer.channels;
			bool chan_ignore_318 = ((LocalCh < 0) || (LocalCh >= SampleCountBuffer_channels));
			if ((!chan_ignore_318)) {
				SampleCountBuffer.write(m_SampleCount_287, 0, LocalCh);
				
			};
			
		};
		if ((__m_delta_319(m_LoopSize_286) != ((int)0))) {
			int LoopSizeBuffer_dim = LoopSizeBuffer.dim;
			int LoopSizeBuffer_channels = LoopSizeBuffer.channels;
			bool chan_ignore_320 = ((LocalCh < 0) || (LocalCh >= LoopSizeBuffer_channels));
			if ((!chan_ignore_320)) {
				LoopSizeBuffer.write(m_LoopSize_286, 0, LocalCh);
				
			};
			
		};
		if ((__m_delta_321(m_ExtSyncCh_299) != ((int)0))) {
			int ExtSyncChBuffer_dim = ExtSyncChBuffer.dim;
			int ExtSyncChBuffer_channels = ExtSyncChBuffer.channels;
			bool chan_ignore_322 = ((LocalCh < 0) || (LocalCh >= ExtSyncChBuffer_channels));
			if ((!chan_ignore_322)) {
				ExtSyncChBuffer.write(m_ExtSyncCh_299, 0, LocalCh);
				
			};
			
		};
		if ((__m_delta_323(m_ExtSyncStatus_300) != ((int)0))) {
			int ExtSyncStatusBuffer_dim = ExtSyncStatusBuffer.dim;
			int ExtSyncStatusBuffer_channels = ExtSyncStatusBuffer.channels;
			bool chan_ignore_324 = ((LocalCh < 0) || (LocalCh >= ExtSyncStatusBuffer_channels));
			if ((!chan_ignore_324)) {
				ExtSyncStatusBuffer.write(m_ExtSyncStatus_300, 0, LocalCh);
				
			};
			
		};
		if ((__m_delta_325(m_RatioNumerator_305) != ((int)0))) {
			int RatioNbuffer_dim = RatioNbuffer.dim;
			int RatioNbuffer_channels = RatioNbuffer.channels;
			bool chan_ignore_326 = ((LocalCh < 0) || (LocalCh >= RatioNbuffer_channels));
			if ((!chan_ignore_326)) {
				RatioNbuffer.write(m_RatioNumerator_305, 0, LocalCh);
				
			};
			
		};
		if ((__m_delta_327(m_RatioDenominator_306) != ((int)0))) {
			int RatioDbuffer_dim = RatioDbuffer.dim;
			int RatioDbuffer_channels = RatioDbuffer.channels;
			bool chan_ignore_328 = ((LocalCh < 0) || (LocalCh >= RatioDbuffer_channels));
			if ((!chan_ignore_328)) {
				RatioDbuffer.write(m_RatioDenominator_306, 0, LocalCh);
				
			};
			
		};
		if ((__m_delta_329(m_Clip_311) != ((int)0))) {
			int ClipInfoBuffer_dim = ClipInfoBuffer.dim;
			int ClipInfoBuffer_channels = ClipInfoBuffer.channels;
			bool chan_ignore_330 = ((LocalCh < 0) || (LocalCh >= ClipInfoBuffer_channels));
			if ((!chan_ignore_330)) {
				ClipInfoBuffer.write(m_Clip_311, 0, LocalCh);
				
			};
			
		};
		m_SampleCount_287 = (m_SampleCount_287 + ((int)1));
		if ((m_SampleCount_287 > m_LoopSize_286)) {
			m_SampleCount_287 = ((int)0);
			
		};
		if (((SelectedCh == m_ExtSyncCh_299) && (__m_delta_331(bReset) > ((int)0)))) {
			m_ExtSyncStatus_300 = ((int)0);
			m_ExtSyncCh_299 = (-((int)1));
			m_SyncLoopSize_301 = ((int)0);
			int LoopSizeBuffer_dim = LoopSizeBuffer.dim;
			int LoopSizeBuffer_channels = LoopSizeBuffer.channels;
			// samples LoopSizeBuffer channel 1;
			t_sample peek_870 = LoopSizeBuffer.read(0, 0);
			t_sample peek_871 = ((int)0);
			if ((peek_870 > ((int)0))) {
				m_ExtSyncCh_299 = ((int)0);
				
			};
			
		};
		if ((SelectedCh == LocalCh)) {
			int RecordStatusBuffer_dim = RecordStatusBuffer.dim;
			int RecordStatusBuffer_channels = RecordStatusBuffer.channels;
			// samples RecordStatusBuffer channel 1;
			int chan_332 = m_InputCh_23;
			bool chan_ignore_333 = ((chan_332 < 0) || (chan_332 >= RecordStatusBuffer_channels));
			t_sample peek_872 = (chan_ignore_333 ? 0 : RecordStatusBuffer.read(0, chan_332));
			t_sample peek_873 = ((int)0);
			int LoopSizeBuffer_dim = LoopSizeBuffer.dim;
			int LoopSizeBuffer_channels = LoopSizeBuffer.channels;
			// samples LoopSizeBuffer channel 1;
			int chan_334 = m_InputCh_23;
			bool chan_ignore_335 = ((chan_334 < 0) || (chan_334 >= LoopSizeBuffer_channels));
			t_sample peek_874 = (chan_ignore_335 ? 0 : LoopSizeBuffer.read(0, chan_334));
			t_sample peek_875 = ((int)0);
			if ((((m_InputCh_23 == ((int)0)) && (__m_delta_336(peek_872) == (-((int)1)))) && (__m_delta_337(peek_874) != ((int)0)))) {
				m_ExtSyncCh_299 = ((int)0);
				
			};
			// samples LoopSizeBuffer channel 1;
			int chan_338 = m_InputCh_23;
			bool chan_ignore_339 = ((chan_338 < 0) || (chan_338 >= LoopSizeBuffer_channels));
			t_sample peek_876 = (chan_ignore_339 ? 0 : LoopSizeBuffer.read(0, chan_338));
			t_sample peek_877 = ((int)0);
			if (((((GridMode == ((int)1)) && (peek_876 != ((int)0))) && (m_InputCh_23 != LocalCh)) && (m_LoopSize_286 == ((int)0)))) {
				__m_latch_340 = (((__m_delta_341(m_InputCh_23) > ((int)0)) != 0) ? m_InputCh_23 : __m_latch_340);
				m_ExtSyncCh_299 = __m_latch_340;
				
			};
			if (((m_RatioState_307 == ((int)0)) && (SyncRatioButton > ((int)0)))) {
				m_RatioNumerator_305 = SyncRatio;
				m_RatioDenominator_306 = ((int)1);
				m_Ratio_304 = SyncRatio;
				m_RatioState_307 = ((int)1);
				
			};
			if ((((m_RatioState_307 != ((int)0)) && (__m_delta_342(SyncRatioButton) < ((int)0))) && (__m_delta_343(m_Ratio_304) == ((int)0)))) {
				m_RatioDenominator_306 = SyncRatio;
				m_Ratio_304 = safediv(m_Ratio_304, SyncRatio);
				m_RatioState_307 = ((int)0);
				
			};
			if ((((m_ExtSyncCh_299 >= ((int)0)) && (m_Ratio_304 > ((int)0))) && (m_LoopSize_286 == ((int)0)))) {
				__m_latch_344 = (((__m_delta_345(bExtSync) > ((int)0)) != 0) ? (!m_ExtSyncStatus_300) : __m_latch_344);
				m_ExtSyncStatus_300 = __m_latch_344;
				
			};
			if ((m_ExtSyncStatus_300 == ((int)1))) {
				// samples LoopSizeBuffer channel 1;
				int chan_346 = m_ExtSyncCh_299;
				bool chan_ignore_347 = ((chan_346 < 0) || (chan_346 >= LoopSizeBuffer_channels));
				m_SyncLoopSize_301 = (chan_ignore_347 ? 0 : LoopSizeBuffer.read(0, chan_346));
				int SampleCountBuffer_dim = SampleCountBuffer.dim;
				int SampleCountBuffer_channels = SampleCountBuffer.channels;
				// samples SampleCountBuffer channel 1;
				int chan_348 = m_ExtSyncCh_299;
				bool chan_ignore_349 = ((chan_348 < 0) || (chan_348 >= SampleCountBuffer_channels));
				m_SyncCounter_302 = (chan_ignore_349 ? 0 : SampleCountBuffer.read(0, chan_348));
				
			};
			if ((((m_ExtSyncStatus_300 == ((int)1)) && (m_Overdub_288 == ((int)1))) || (bReset == ((int)1)))) {
				__m_latch_350 = ((((__m_delta_351(bRec) > ((int)0)) || (__m_delta_352(m_Record_290) == (-((int)1)))) != 0) ? (!m_SyncRec_292) : __m_latch_350);
				m_SyncRec_292 = __m_latch_350;
				__m_latch_353 = (((((m_SyncRec_292 == ((int)1)) && ((m_Record_290 == ((int)0)) && (m_SyncCounter_302 == ((int)0)))) || ((m_Record_290 == ((int)1)) && (m_SampleCount_287 == round((m_SyncLoopSize_301 * m_Ratio_304))))) != 0) ? (!m_Record_290) : __m_latch_353);
				m_Record_290 = __m_latch_353;
				
			};
			if ((((m_ExtSyncStatus_300 == ((int)0)) && ((m_SyncOverdubStatus_289 == ((int)0)) || (m_Overdub_288 == ((int)1)))) && (__m_delta_354(bRec) > ((int)0)))) {
				m_Record_290 = (!m_Record_290);
				
			};
			if (((((m_ExtSyncStatus_300 == ((int)1)) && (m_Overdub_288 != ((int)1))) && (m_SyncOverdubStatus_289 == ((int)0))) && (__m_delta_355(bRec) > ((int)0)))) {
				m_Record_290 = (!m_Record_290);
				
			};
			if (((__m_delta_356(m_Record_290) == (-((int)1))) && (bReset == ((int)0)))) {
				m_Overdub_288 = (m_Overdub_288 + ((int)1));
				
			};
			if (((m_Overdub_288 != ((int)1)) && (m_Record_290 == ((int)1)))) {
				int LoopBuffer_dim = LoopBuffer.dim;
				int LoopBuffer_channels = LoopBuffer.channels;
				int chan_clamp_357 = clamp(LocalCh, 0, (LoopBuffer_channels - 1));
				int index_trunc_358 = fixnan(floor(m_SampleCount_287));
				double index_fract_359 = (m_SampleCount_287 - index_trunc_358);
				int index_trunc_360 = (index_trunc_358 + 1);
				int index_wrap_361 = ((index_trunc_358 < 0) ? ((LoopBuffer_dim - 1) + ((index_trunc_358 + 1) % LoopBuffer_dim)) : (index_trunc_358 % LoopBuffer_dim));
				int index_wrap_362 = ((index_trunc_360 < 0) ? ((LoopBuffer_dim - 1) + ((index_trunc_360 + 1) % LoopBuffer_dim)) : (index_trunc_360 % LoopBuffer_dim));
				LoopBuffer.blend(mix(Audio_in, LoopBuffer.read(index_wrap_361, chan_clamp_357), (((int)1) - safediv(((int)1), m_Overdub_288))), index_wrap_361, chan_clamp_357, index_fract_359);
				LoopBuffer.blend(mix(Audio_in, LoopBuffer.read(index_wrap_362, chan_clamp_357), (((int)1) - safediv(((int)1), m_Overdub_288))), index_wrap_362, chan_clamp_357, (1 - index_fract_359));
				
			};
			__m_latch_363 = (((__m_delta_364(bSyncOverdubs) > ((int)0)) != 0) ? (!m_SyncOverdubStatus_289) : __m_latch_363);
			m_SyncOverdubStatus_289 = __m_latch_363;
			if (((m_SyncOverdubStatus_289 == ((int)1)) && (m_Overdub_288 != ((int)1)))) {
				if (((m_Record_290 == ((int)0)) && (__m_delta_365(bRec) > ((int)0)))) {
					m_RecordOverdub_291 = ((int)1);
					
				};
				if (((m_Record_290 == ((int)1)) && (m_SampleCount_287 == ((int)0)))) {
					m_RecordOverdub_291 = ((int)0);
					
				};
				__m_latch_366 = (((m_SampleCount_287 == ((int)0)) != 0) ? m_RecordOverdub_291 : __m_latch_366);
				m_Record_290 = __m_latch_366;
				
			};
			if (((m_Overdub_288 == ((int)1)) || (bReset == ((int)1)))) {
				m_LoopSize_286 = __m_pluseq_367.post(m_Record_290, ((__m_delta_368(m_Record_290) > ((int)0)) || (bReset == ((int)1))), 0);
				if ((__m_delta_369(m_LoopSize_286) != ((int)0))) {
					int LoopBuffer_dim = LoopBuffer.dim;
					int LoopBuffer_channels = LoopBuffer.channels;
					bool chan_ignore_370 = ((LocalCh < 0) || (LocalCh >= LoopBuffer_channels));
					int index_trunc_371 = fixnan(floor(m_LoopSize_286));
					bool index_ignore_372 = ((index_trunc_371 >= LoopBuffer_dim) || (index_trunc_371 < 0));
					if ((!(chan_ignore_370 || index_ignore_372))) {
						LoopBuffer.write(Audio_in, index_trunc_371, LocalCh);
						
					};
					
				};
				
			};
			if (((__m_delta_373(bReset) > ((int)0)) || (m_ResetState_294 == ((int)1)))) {
				(m_ResetState_294 == ((int)1));
				m_Dynamic_310 = ((int)0);
				// for loop initializer;
				t_sample i = (m_gCount_293 * ((int)100));
				// for loop condition;
				while (((i < ((m_gCount_293 * ((int)100)) + ((int)100))) && (i <= m_LoopSize_286))) {
					// abort processing if an infinite loop is suspected;
					if (((__loopcount--) <= 0)) {
						__exception = GENLIB_ERR_LOOP_OVERFLOW;
						break ;
						
					};
					int LoopBuffer_dim = LoopBuffer.dim;
					int LoopBuffer_channels = LoopBuffer.channels;
					bool chan_ignore_374 = ((LocalCh < 0) || (LocalCh >= LoopBuffer_channels));
					int index_trunc_375 = fixnan(floor(i));
					bool index_ignore_376 = ((index_trunc_375 >= LoopBuffer_dim) || (index_trunc_375 < 0));
					if ((!(chan_ignore_374 || index_ignore_376))) {
						LoopBuffer.write(((int)0), index_trunc_375, LocalCh);
						
					};
					int UndoBuffer_dim = UndoBuffer.dim;
					int UndoBuffer_channels = UndoBuffer.channels;
					bool chan_ignore_377 = (((((int)2) * LocalCh) < 0) || ((((int)2) * LocalCh) >= UndoBuffer_channels));
					int index_trunc_378 = fixnan(floor(i));
					bool index_ignore_379 = ((index_trunc_378 >= UndoBuffer_dim) || (index_trunc_378 < 0));
					if ((!(chan_ignore_377 || index_ignore_379))) {
						UndoBuffer.write(((int)0), index_trunc_378, (((int)2) * LocalCh));
						
					};
					bool chan_ignore_380 = ((((((int)2) * LocalCh) + ((int)1)) < 0) || (((((int)2) * LocalCh) + ((int)1)) >= UndoBuffer_channels));
					int index_trunc_381 = fixnan(floor(i));
					bool index_ignore_382 = ((index_trunc_381 >= UndoBuffer_dim) || (index_trunc_381 < 0));
					if ((!(chan_ignore_380 || index_ignore_382))) {
						UndoBuffer.write(((int)0), index_trunc_381, ((((int)2) * LocalCh) + ((int)1)));
						
					};
					if ((i == m_LoopSize_286)) {
						m_LoopSize_286 = ((int)0);
						
					};
					// for loop increment;
					i = (i + ((int)1));
					
				};
				m_gCount_293 = (m_gCount_293 + ((int)1));
				if ((m_LoopSize_286 == ((int)0))) {
					m_gCount_293 = ((int)0);
					m_ResetState_294 = ((int)0);
					m_RecordOverdub_291 = ((int)0);
					m_Record_290 = ((int)0);
					m_Overdub_288 = ((int)1);
					m_SampleCount_287 = ((int)0);
					m_OverdubNundo_296 = ((int)0);
					m_Clip_311 = ((int)0);
					
				};
				
			};
			if ((__m_delta_383(bUndo) > ((int)0))) {
				m_OverdubNundo_296 = (m_OverdubNundo_296 + ((int)1));
				
			};
			if ((m_Record_290 == ((int)1))) {
				m_OverdubNundo_296 = ((int)0);
				
			};
			if (((m_Overdub_288 > ((int)1)) && (__m_delta_384(safemod(m_OverdubNundo_296, ((int)2))) == ((int)1)))) {
				m_Overdub_288 = (m_Overdub_288 - ((int)1));
				
			};
			if (((m_OverdubNundo_296 > ((int)0)) && (__m_delta_385(safemod(m_OverdubNundo_296, ((int)2))) == (-((int)1))))) {
				m_Overdub_288 = (m_Overdub_288 + ((int)1));
				
			};
			if (((m_Record_290 == ((int)1)) && (fabs(Audio_in) >= ((int)1)))) {
				m_Clip_311 = ((int)1);
				m_ClipOverdubN_312 = (m_Overdub_288 + ((int)1));
				
			};
			if (((m_Overdub_288 == (m_ClipOverdubN_312 - ((int)1))) && (m_Record_290 == ((int)0)))) {
				m_Clip_311 = ((int)0);
				
			};
			if (((__m_delta_386(m_Record_290) == (-((int)1))) || (m_Undo1State_297 == ((int)1)))) {
				m_Undo1State_297 = ((int)1);
				// for loop initializer;
				t_sample i = (m_gCount_293 * ((int)40));
				// for loop condition;
				while (((i < ((m_gCount_293 * ((int)40)) + ((int)40))) && (i <= m_LoopSize_286))) {
					// abort processing if an infinite loop is suspected;
					if (((__loopcount--) <= 0)) {
						__exception = GENLIB_ERR_LOOP_OVERFLOW;
						break ;
						
					};
					int LoopBuffer_dim = LoopBuffer.dim;
					int LoopBuffer_channels = LoopBuffer.channels;
					int index_trunc_387 = fixnan(floor(i));
					bool index_ignore_388 = ((index_trunc_387 >= LoopBuffer_dim) || (index_trunc_387 < 0));
					// samples LoopBuffer channel 1;
					int chan_389 = LocalCh;
					bool chan_ignore_390 = ((chan_389 < 0) || (chan_389 >= LoopBuffer_channels));
					t_sample peek_878 = ((chan_ignore_390 || index_ignore_388) ? 0 : LoopBuffer.read(index_trunc_387, chan_389));
					t_sample peek_879 = i;
					int UndoBuffer_dim = UndoBuffer.dim;
					int UndoBuffer_channels = UndoBuffer.channels;
					int channel_trunc_391 = fixnan(floor(((((int)2) * LocalCh) + m_UndoChannel_295)));
					bool chan_ignore_392 = ((channel_trunc_391 < 0) || (channel_trunc_391 >= UndoBuffer_channels));
					int index_trunc_393 = fixnan(floor(i));
					bool index_ignore_394 = ((index_trunc_393 >= UndoBuffer_dim) || (index_trunc_393 < 0));
					if ((!(chan_ignore_392 || index_ignore_394))) {
						UndoBuffer.write(peek_878, index_trunc_393, channel_trunc_391);
						
					};
					if ((i == m_LoopSize_286)) {
						m_Undo1State_297 = ((int)0);
						
					};
					int index_trunc_395 = fixnan(floor(i));
					bool index_ignore_396 = ((index_trunc_395 >= LoopBuffer_dim) || (index_trunc_395 < 0));
					// samples LoopBuffer channel 1;
					int chan_397 = LocalCh;
					bool chan_ignore_398 = ((chan_397 < 0) || (chan_397 >= LoopBuffer_channels));
					t_sample peek_880 = ((chan_ignore_398 || index_ignore_396) ? 0 : LoopBuffer.read(index_trunc_395, chan_397));
					t_sample peek_881 = i;
					if ((m_Peak_309 < fabs(peek_880))) {
						int index_trunc_399 = fixnan(floor(i));
						bool index_ignore_400 = ((index_trunc_399 >= LoopBuffer_dim) || (index_trunc_399 < 0));
						// samples LoopBuffer channel 1;
						int chan_401 = LocalCh;
						bool chan_ignore_402 = ((chan_401 < 0) || (chan_401 >= LoopBuffer_channels));
						t_sample peek_882 = ((chan_ignore_402 || index_ignore_400) ? 0 : LoopBuffer.read(index_trunc_399, chan_401));
						t_sample peek_883 = i;
						m_Peak_309 = fabs(peek_882);
						
					};
					if ((i == m_LoopSize_286)) {
						m_Dynamic_310 = safediv(((t_sample)0.999), m_Peak_309);
						m_Peak_309 = ((int)0);
						
					};
					// for loop increment;
					i = (i + ((int)1));
					
				};
				m_gCount_293 = (m_gCount_293 + ((int)1));
				if ((m_Undo1State_297 == ((int)0))) {
					m_gCount_293 = ((int)0);
					m_UndoChannel_295 = (!m_UndoChannel_295);
					
				};
				
			};
			if (((__m_delta_403(bUndo) > ((int)0)) || (m_Undo2State_298 == ((int)1)))) {
				m_Undo2State_298 = ((int)1);
				// for loop initializer;
				t_sample i = (m_gCount_293 * ((int)40));
				// for loop condition;
				while (((i < ((m_gCount_293 * ((int)40)) + ((int)40))) && (i <= m_LoopSize_286))) {
					// abort processing if an infinite loop is suspected;
					if (((__loopcount--) <= 0)) {
						__exception = GENLIB_ERR_LOOP_OVERFLOW;
						break ;
						
					};
					int UndoBuffer_dim = UndoBuffer.dim;
					int UndoBuffer_channels = UndoBuffer.channels;
					int index_trunc_404 = fixnan(floor(i));
					bool index_ignore_405 = ((index_trunc_404 >= UndoBuffer_dim) || (index_trunc_404 < 0));
					// samples UndoBuffer channel 1;
					int chan_406 = ((((int)2) * LocalCh) + m_UndoChannel_295);
					bool chan_ignore_407 = ((chan_406 < 0) || (chan_406 >= UndoBuffer_channels));
					t_sample peek_884 = ((chan_ignore_407 || index_ignore_405) ? 0 : UndoBuffer.read(index_trunc_404, chan_406));
					t_sample peek_885 = i;
					int LoopBuffer_dim = LoopBuffer.dim;
					int LoopBuffer_channels = LoopBuffer.channels;
					bool chan_ignore_408 = ((LocalCh < 0) || (LocalCh >= LoopBuffer_channels));
					int index_trunc_409 = fixnan(floor(i));
					bool index_ignore_410 = ((index_trunc_409 >= LoopBuffer_dim) || (index_trunc_409 < 0));
					if ((!(chan_ignore_408 || index_ignore_410))) {
						LoopBuffer.write(peek_884, index_trunc_409, LocalCh);
						
					};
					if ((i == m_LoopSize_286)) {
						m_Undo2State_298 = ((int)0);
						
					};
					// for loop increment;
					i = (i + ((int)1));
					
				};
				m_gCount_293 = (m_gCount_293 + ((int)1));
				if ((m_Undo2State_298 == ((int)0))) {
					m_gCount_293 = ((int)0);
					m_UndoChannel_295 = (!m_UndoChannel_295);
					
				};
				
			};
			
		};
		int LoopBuffer_dim = LoopBuffer.dim;
		int LoopBuffer_channels = LoopBuffer.channels;
		int index_trunc_411 = fixnan(floor(m_SampleCount_287));
		bool index_ignore_412 = ((index_trunc_411 >= LoopBuffer_dim) || (index_trunc_411 < 0));
		// samples LoopBuffer channel 1;
		int chan_413 = LocalCh;
		bool chan_ignore_414 = ((chan_413 < 0) || (chan_413 >= LoopBuffer_channels));
		t_sample Loop = ((chan_ignore_414 || index_ignore_412) ? 0 : LoopBuffer.read(index_trunc_411, chan_413));
		t_sample Loop_index = m_SampleCount_287;
		if (((__m_delta_415(m_LoopSize_286) == ((int)0)) && (m_LoopSize_286 > ((int)0)))) {
			m_output_308 = (Loop * m_Dynamic_310);
			
		};
		return m_output_308;
		
	};
	
} State;


///
///	Configuration for the genlib API
///

/// Number of signal inputs and outputs

int gen_kernel_numins = 1;
int gen_kernel_numouts = 24;

int num_inputs() { return gen_kernel_numins; }
int num_outputs() { return gen_kernel_numouts; }
int num_params() { return 21; }

/// Assistive lables for the signal inputs and outputs

const char *gen_kernel_innames[] = { "in1" };
const char *gen_kernel_outnames[] = { "out1", "out2", "out3", "out4", "out5", "out6", "out7", "out8", "out9", "out10", "out11", "out12", "out13", "out14", "out15", "out16", "out17", "out18", "out19", "out20", "out21", "out22", "out23", "out24" };

/// Invoke the signal process of a State object

int perform(CommonState *cself, t_sample **ins, long numins, t_sample **outs, long numouts, long n) {
	State* self = (State *)cself;
	return self->perform(ins, outs, n);
}

/// Reset all parameters and stateful operators of a State object

void reset(CommonState *cself) {
	State* self = (State *)cself;
	self->reset(cself->sr, cself->vs);
}

/// Set a parameter of a State object

void setparameter(CommonState *cself, long index, t_param value, void *ref) {
	State *self = (State *)cself;
	switch (index) {
		case 0: self->set_ClipInfoBuf(ref); break;
		case 1: self->set_ExtSyncChBuf(ref); break;
		case 2: self->set_ExtSyncStatusBuf(ref); break;
		case 3: self->set_LoopSizeBuf(ref); break;
		case 4: self->set_RatioDenominatorBuf(ref); break;
		case 5: self->set_RatioNumeratorBuf(ref); break;
		case 6: self->set_RecordStatusBuf(ref); break;
		case 7: self->set_SampleCountBuf(ref); break;
		case 8: self->set_SyncOverdubStatusBuf(ref); break;
		case 9: self->set_loopy(ref); break;
		case 10: self->set_pExtSync(value); break;
		case 11: self->set_pGridMode(value); break;
		case 12: self->set_pInputCh(value); break;
		case 13: self->set_pPlay(value); break;
		case 14: self->set_pRec(value); break;
		case 15: self->set_pReset(value); break;
		case 16: self->set_pSyncOverdubs(value); break;
		case 17: self->set_pSyncRatio(value); break;
		case 18: self->set_pSyncRatioButton(value); break;
		case 19: self->set_pUndo(value); break;
		case 20: self->set_undo(ref); break;
		
		default: break;
	}
}

/// Get the value of a parameter of a State object

void getparameter(CommonState *cself, long index, t_param *value) {
	State *self = (State *)cself;
	switch (index) {
		
		
		
		
		
		
		
		
		
		case 10: *value = self->m_pExtSync_18; break;
		case 11: *value = self->m_pGridMode_19; break;
		case 12: *value = self->m_pInputCh_12; break;
		case 13: *value = self->m_pPlay_16; break;
		case 14: *value = self->m_pRec_13; break;
		case 15: *value = self->m_pReset_14; break;
		case 16: *value = self->m_pSyncOverdubs_17; break;
		case 17: *value = self->m_pSyncRatio_20; break;
		case 18: *value = self->m_pSyncRatioButton_21; break;
		case 19: *value = self->m_pUndo_15; break;
		
		
		default: break;
	}
}

/// Get the name of a parameter of a State object

const char *getparametername(CommonState *cself, long index) {
	if (index >= 0 && index < cself->numparams) {
		return cself->params[index].name;
	}
	return 0;
}

/// Get the minimum value of a parameter of a State object

t_param getparametermin(CommonState *cself, long index) {
	if (index >= 0 && index < cself->numparams) {
		return cself->params[index].outputmin;
	}
	return 0;
}

/// Get the maximum value of a parameter of a State object

t_param getparametermax(CommonState *cself, long index) {
	if (index >= 0 && index < cself->numparams) {
		return cself->params[index].outputmax;
	}
	return 0;
}

/// Get parameter of a State object has a minimum and maximum value

char getparameterhasminmax(CommonState *cself, long index) {
	if (index >= 0 && index < cself->numparams) {
		return cself->params[index].hasminmax;
	}
	return 0;
}

/// Get the units of a parameter of a State object

const char *getparameterunits(CommonState *cself, long index) {
	if (index >= 0 && index < cself->numparams) {
		return cself->params[index].units;
	}
	return 0;
}

/// Get the size of the state of all parameters of a State object

size_t getstatesize(CommonState *cself) {
	return genlib_getstatesize(cself, &getparameter);
}

/// Get the state of all parameters of a State object

short getstate(CommonState *cself, char *state) {
	return genlib_getstate(cself, state, &getparameter);
}

/// set the state of all parameters of a State object

short setstate(CommonState *cself, const char *state) {
	return genlib_setstate(cself, state, &setparameter);
}

/// Allocate and configure a new State object and it's internal CommonState:

void *create(t_param sr, long vs) {
	State *self = new State;
	self->reset(sr, vs);
	ParamInfo *pi;
	self->__commonstate.inputnames = gen_kernel_innames;
	self->__commonstate.outputnames = gen_kernel_outnames;
	self->__commonstate.numins = gen_kernel_numins;
	self->__commonstate.numouts = gen_kernel_numouts;
	self->__commonstate.sr = sr;
	self->__commonstate.vs = vs;
	self->__commonstate.params = (ParamInfo *)genlib_sysmem_newptr(21 * sizeof(ParamInfo));
	self->__commonstate.numparams = 21;
	// initialize parameter 0 ("m_ClipInfoBuf_11")
	pi = self->__commonstate.params + 0;
	pi->name = "ClipInfoBuf";
	pi->paramtype = GENLIB_PARAMTYPE_SYM;
	pi->defaultvalue = 0.;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = false;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 1 ("m_ExtSyncChBuf_7")
	pi = self->__commonstate.params + 1;
	pi->name = "ExtSyncChBuf";
	pi->paramtype = GENLIB_PARAMTYPE_SYM;
	pi->defaultvalue = 0.;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = false;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 2 ("m_ExtSyncStatusBuf_6")
	pi = self->__commonstate.params + 2;
	pi->name = "ExtSyncStatusBuf";
	pi->paramtype = GENLIB_PARAMTYPE_SYM;
	pi->defaultvalue = 0.;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = false;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 3 ("m_LoopSizeBuf_3")
	pi = self->__commonstate.params + 3;
	pi->name = "LoopSizeBuf";
	pi->paramtype = GENLIB_PARAMTYPE_SYM;
	pi->defaultvalue = 0.;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = false;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 4 ("m_RatioDenominatorBuf_10")
	pi = self->__commonstate.params + 4;
	pi->name = "RatioDenominatorBuf";
	pi->paramtype = GENLIB_PARAMTYPE_SYM;
	pi->defaultvalue = 0.;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = false;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 5 ("m_RatioNumeratorBuf_9")
	pi = self->__commonstate.params + 5;
	pi->name = "RatioNumeratorBuf";
	pi->paramtype = GENLIB_PARAMTYPE_SYM;
	pi->defaultvalue = 0.;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = false;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 6 ("m_RecordStatusBuf_8")
	pi = self->__commonstate.params + 6;
	pi->name = "RecordStatusBuf";
	pi->paramtype = GENLIB_PARAMTYPE_SYM;
	pi->defaultvalue = 0.;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = false;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 7 ("m_SampleCountBuf_4")
	pi = self->__commonstate.params + 7;
	pi->name = "SampleCountBuf";
	pi->paramtype = GENLIB_PARAMTYPE_SYM;
	pi->defaultvalue = 0.;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = false;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 8 ("m_SyncOverdubStatusBuf_5")
	pi = self->__commonstate.params + 8;
	pi->name = "SyncOverdubStatusBuf";
	pi->paramtype = GENLIB_PARAMTYPE_SYM;
	pi->defaultvalue = 0.;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = false;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 9 ("m_loopy_1")
	pi = self->__commonstate.params + 9;
	pi->name = "loopy";
	pi->paramtype = GENLIB_PARAMTYPE_SYM;
	pi->defaultvalue = 0.;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = false;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 10 ("m_pExtSync_18")
	pi = self->__commonstate.params + 10;
	pi->name = "pExtSync";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_pExtSync_18;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 11 ("m_pGridMode_19")
	pi = self->__commonstate.params + 11;
	pi->name = "pGridMode";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_pGridMode_19;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 12 ("m_pInputCh_12")
	pi = self->__commonstate.params + 12;
	pi->name = "pInputCh";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_pInputCh_12;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = -1;
	pi->outputmax = 2;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 13 ("m_pPlay_16")
	pi = self->__commonstate.params + 13;
	pi->name = "pPlay";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_pPlay_16;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 14 ("m_pRec_13")
	pi = self->__commonstate.params + 14;
	pi->name = "pRec";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_pRec_13;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 15 ("m_pReset_14")
	pi = self->__commonstate.params + 15;
	pi->name = "pReset";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_pReset_14;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 16 ("m_pSyncOverdubs_17")
	pi = self->__commonstate.params + 16;
	pi->name = "pSyncOverdubs";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_pSyncOverdubs_17;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 17 ("m_pSyncRatio_20")
	pi = self->__commonstate.params + 17;
	pi->name = "pSyncRatio";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_pSyncRatio_20;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 16;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 18 ("m_pSyncRatioButton_21")
	pi = self->__commonstate.params + 18;
	pi->name = "pSyncRatioButton";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_pSyncRatioButton_21;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 19 ("m_pUndo_15")
	pi = self->__commonstate.params + 19;
	pi->name = "pUndo";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_pUndo_15;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 20 ("m_undo_2")
	pi = self->__commonstate.params + 20;
	pi->name = "undo";
	pi->paramtype = GENLIB_PARAMTYPE_SYM;
	pi->defaultvalue = 0.;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = false;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	
	return self;
}

/// Release all resources and memory used by a State object:

void destroy(CommonState *cself) {
	State *self = (State *)cself;
	genlib_sysmem_freeptr(cself->params);
		
	delete self;
}


} // gen_exported::

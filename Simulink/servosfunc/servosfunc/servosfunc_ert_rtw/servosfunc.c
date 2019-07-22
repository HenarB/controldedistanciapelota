/*
 * File: servosfunc.c
 *
 * Code generated for Simulink model 'servosfunc'.
 *
 * Model version                  : 1.34
 * Simulink Coder version         : 8.14 (R2018a) 06-Feb-2018
 * C/C++ source code generated on : Mon Jul 22 14:08:49 2019
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "servosfunc.h"
#include "servosfunc_private.h"
#include "servosfunc_dt.h"

/* Block signals (default storage) */
B_servosfunc_T servosfunc_B;

/* Block states (default storage) */
DW_servosfunc_T servosfunc_DW;

/* Real-time model */
RT_MODEL_servosfunc_T servosfunc_M_;
RT_MODEL_servosfunc_T *const servosfunc_M = &servosfunc_M_;

/* Model step function */
void servosfunc_step(void)
{
  real_T rtb_IntegralGain;
  real_T rtb_FilterCoefficient;
  real_T rtb_SignPreIntegrator;
  real_T rtb_ZeroGain;
  boolean_T rtb_NotEqual;
  real_T TmpSignalConversionAtFilterDiff;
  int8_T rtb_SignPreIntegrator_0;
  uint8_T tmp;

  /* SampleTimeMath: '<S4>/TSamp' incorporates:
   *  Constant: '<S4>/N Copy'
   *
   * About '<S4>/TSamp':
   *  y = u * K where K = ( w * Ts )
   */
  rtb_IntegralGain = servosfunc_P.DiscretePIDController_N *
    servosfunc_P.TSamp_WtEt;

  /* Math: '<S4>/Reciprocal' incorporates:
   *  Constant: '<S4>/Constant'
   *  Sum: '<S4>/SumDen'
   *
   * About '<S4>/Reciprocal':
   *  Operator: reciprocal
   */
  servosfunc_B.Saturate = 1.0 / (servosfunc_P.Constant_Value + rtb_IntegralGain);

  /* SignalConversion: '<S4>/TmpSignal ConversionAtFilter Differentiator TFInport2' incorporates:
   *  Constant: '<S4>/Constant'
   *  Product: '<S4>/Divide'
   *  Sum: '<S4>/SumNum'
   */
  TmpSignalConversionAtFilterDiff = (rtb_IntegralGain -
    servosfunc_P.Constant_Value) * servosfunc_B.Saturate;

  /* S-Function (bloque1): '<Root>/S-Function Builder' */
  bloque1_Outputs_wrapper(&servosfunc_B.SFunctionBuilder,
    &servosfunc_DW.SFunctionBuilder_DSTATE);

  /* Sum: '<Root>/Sum' incorporates:
   *  Constant: '<Root>/Consigna'
   */
  rtb_IntegralGain = servosfunc_P.Consigna_Value - servosfunc_B.SFunctionBuilder;

  /* DiscreteTransferFcn: '<S4>/Filter Differentiator TF' incorporates:
   *  Gain: '<S1>/Derivative Gain'
   */
  TmpSignalConversionAtFilterDiff = servosfunc_P.DiscretePIDController_D *
    rtb_IntegralGain - TmpSignalConversionAtFilterDiff *
    servosfunc_DW.FilterDifferentiatorTF_states;

  /* Gain: '<S4>/Filter Coefficient' incorporates:
   *  DiscreteTransferFcn: '<S4>/Filter Differentiator TF'
   *  Product: '<S4>/DenCoefOut'
   */
  rtb_FilterCoefficient = (servosfunc_P.FilterDifferentiatorTF_NumCoef[0] *
    TmpSignalConversionAtFilterDiff +
    servosfunc_P.FilterDifferentiatorTF_NumCoef[1L] *
    servosfunc_DW.FilterDifferentiatorTF_states) * servosfunc_B.Saturate *
    servosfunc_P.DiscretePIDController_N;

  /* Gain: '<S1>/Proportional Gain' */
  servosfunc_B.Saturate = servosfunc_P.DiscretePIDController_P *
    rtb_IntegralGain;

  /* Gain: '<S1>/Integral Gain' */
  rtb_IntegralGain *= servosfunc_P.DiscretePIDController_I;

  /* Sum: '<S1>/Sum Fdbk' */
  rtb_SignPreIntegrator = (servosfunc_B.Saturate +
    servosfunc_DW.Integrator_DSTATE) + rtb_FilterCoefficient;

  /* Gain: '<S3>/ZeroGain' */
  rtb_ZeroGain = servosfunc_P.ZeroGain_Gain * rtb_SignPreIntegrator;

  /* DeadZone: '<S3>/DeadZone' */
  if (rtb_SignPreIntegrator > servosfunc_P.DiscretePIDController_UpperSatu) {
    rtb_SignPreIntegrator -= servosfunc_P.DiscretePIDController_UpperSatu;
  } else if (rtb_SignPreIntegrator >=
             servosfunc_P.DiscretePIDController_LowerSatu) {
    rtb_SignPreIntegrator = 0.0;
  } else {
    rtb_SignPreIntegrator -= servosfunc_P.DiscretePIDController_LowerSatu;
  }

  /* End of DeadZone: '<S3>/DeadZone' */

  /* RelationalOperator: '<S3>/NotEqual' */
  rtb_NotEqual = (rtb_ZeroGain != rtb_SignPreIntegrator);

  /* Signum: '<S3>/SignDeltaU' */
  if (rtb_SignPreIntegrator < 0.0) {
    rtb_SignPreIntegrator = -1.0;
  } else if (rtb_SignPreIntegrator > 0.0) {
    rtb_SignPreIntegrator = 1.0;
  } else if (rtb_SignPreIntegrator == 0.0) {
    rtb_SignPreIntegrator = 0.0;
  } else {
    rtb_SignPreIntegrator = (rtNaN);
  }

  /* End of Signum: '<S3>/SignDeltaU' */

  /* Signum: '<S3>/SignPreIntegrator' */
  if (rtb_IntegralGain < 0.0) {
    /* DataTypeConversion: '<S3>/DataTypeConv2' */
    rtb_ZeroGain = -1.0;
  } else if (rtb_IntegralGain > 0.0) {
    /* DataTypeConversion: '<S3>/DataTypeConv2' */
    rtb_ZeroGain = 1.0;
  } else if (rtb_IntegralGain == 0.0) {
    /* DataTypeConversion: '<S3>/DataTypeConv2' */
    rtb_ZeroGain = 0.0;
  } else {
    /* DataTypeConversion: '<S3>/DataTypeConv2' */
    rtb_ZeroGain = (rtNaN);
  }

  /* End of Signum: '<S3>/SignPreIntegrator' */

  /* DataTypeConversion: '<S3>/DataTypeConv2' */
  if (rtIsNaN(rtb_ZeroGain)) {
    rtb_ZeroGain = 0.0;
  } else {
    rtb_ZeroGain = fmod(rtb_ZeroGain, 256.0);
  }

  /* DataTypeConversion: '<S3>/DataTypeConv1' */
  if (rtb_SignPreIntegrator < 128.0) {
    rtb_SignPreIntegrator_0 = (int8_T)rtb_SignPreIntegrator;
  } else {
    rtb_SignPreIntegrator_0 = MAX_int8_T;
  }

  /* End of DataTypeConversion: '<S3>/DataTypeConv1' */

  /* Switch: '<S1>/Switch' incorporates:
   *  Constant: '<S1>/Constant'
   *  DataTypeConversion: '<S3>/DataTypeConv2'
   *  Logic: '<S3>/AND'
   *  RelationalOperator: '<S3>/Equal'
   */
  if (rtb_NotEqual && ((rtb_ZeroGain < 0.0 ? (int16_T)(int8_T)-(int8_T)(uint8_T)
                        -rtb_ZeroGain : (int16_T)(int8_T)(uint8_T)rtb_ZeroGain) ==
                       rtb_SignPreIntegrator_0)) {
    rtb_IntegralGain = servosfunc_P.Constant_Value_j;
  }

  /* End of Switch: '<S1>/Switch' */

  /* DiscreteIntegrator: '<S1>/Integrator' */
  rtb_IntegralGain *= servosfunc_P.Integrator_gainval;
  rtb_SignPreIntegrator = rtb_IntegralGain + servosfunc_DW.Integrator_DSTATE;

  /* Sum: '<S1>/Sum' */
  servosfunc_B.Saturate = (servosfunc_B.Saturate + rtb_SignPreIntegrator) +
    rtb_FilterCoefficient;

  /* Saturate: '<S1>/Saturate' */
  if (servosfunc_B.Saturate > servosfunc_P.DiscretePIDController_UpperSatu) {
    servosfunc_B.Saturate = servosfunc_P.DiscretePIDController_UpperSatu;
  } else {
    if (servosfunc_B.Saturate < servosfunc_P.DiscretePIDController_LowerSatu) {
      servosfunc_B.Saturate = servosfunc_P.DiscretePIDController_LowerSatu;
    }
  }

  /* End of Saturate: '<S1>/Saturate' */

  /* DataTypeConversion: '<S2>/Data Type Conversion' */
  if (servosfunc_B.Saturate < 256.0) {
    if (servosfunc_B.Saturate >= 0.0) {
      tmp = (uint8_T)servosfunc_B.Saturate;
    } else {
      tmp = 0U;
    }
  } else {
    tmp = MAX_uint8_T;
  }

  /* End of DataTypeConversion: '<S2>/Data Type Conversion' */

  /* S-Function (arduinoservowrite_sfcn): '<S2>/Servo Write' */
  MW_servoWrite(servosfunc_P.ServoWrite_p1, tmp);

  /* Update for S-Function (bloque1): '<Root>/S-Function Builder' */

  /* S-Function "bloque1_wrapper" Block: <Root>/S-Function Builder */
  bloque1_Update_wrapper(&servosfunc_B.SFunctionBuilder,
    &servosfunc_DW.SFunctionBuilder_DSTATE);

  /* Update for DiscreteTransferFcn: '<S4>/Filter Differentiator TF' */
  servosfunc_DW.FilterDifferentiatorTF_states = TmpSignalConversionAtFilterDiff;

  /* Update for DiscreteIntegrator: '<S1>/Integrator' */
  servosfunc_DW.Integrator_DSTATE = rtb_IntegralGain + rtb_SignPreIntegrator;

  /* External mode */
  rtExtModeUploadCheckTrigger(1);

  {                                    /* Sample time: [0.06s, 0.0s] */
    rtExtModeUpload(0, servosfunc_M->Timing.taskTime0);
  }

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.06s, 0.0s] */
    if ((rtmGetTFinal(servosfunc_M)!=-1) &&
        !((rtmGetTFinal(servosfunc_M)-servosfunc_M->Timing.taskTime0) >
          servosfunc_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(servosfunc_M, "Simulation finished");
    }

    if (rtmGetStopRequested(servosfunc_M)) {
      rtmSetErrorStatus(servosfunc_M, "Simulation finished");
    }
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  servosfunc_M->Timing.taskTime0 =
    (++servosfunc_M->Timing.clockTick0) * servosfunc_M->Timing.stepSize0;
}

/* Model initialize function */
void servosfunc_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)servosfunc_M, 0,
                sizeof(RT_MODEL_servosfunc_T));
  rtmSetTFinal(servosfunc_M, -1);
  servosfunc_M->Timing.stepSize0 = 0.06;

  /* External mode info */
  servosfunc_M->Sizes.checksums[0] = (2541719836U);
  servosfunc_M->Sizes.checksums[1] = (3609031926U);
  servosfunc_M->Sizes.checksums[2] = (1380087129U);
  servosfunc_M->Sizes.checksums[3] = (4010643885U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[1];
    servosfunc_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(servosfunc_M->extModeInfo,
      &servosfunc_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(servosfunc_M->extModeInfo, servosfunc_M->Sizes.checksums);
    rteiSetTPtr(servosfunc_M->extModeInfo, rtmGetTPtr(servosfunc_M));
  }

  /* block I/O */
  (void) memset(((void *) &servosfunc_B), 0,
                sizeof(B_servosfunc_T));

  /* states (dwork) */
  (void) memset((void *)&servosfunc_DW, 0,
                sizeof(DW_servosfunc_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    servosfunc_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 14;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* Start for S-Function (arduinoservowrite_sfcn): '<S2>/Servo Write' */
  MW_servoAttach(servosfunc_P.ServoWrite_p1, servosfunc_P.ServoWrite_pinNumber);

  /* InitializeConditions for S-Function (bloque1): '<Root>/S-Function Builder' */

  /* S-Function Block: <Root>/S-Function Builder */
  {
    real_T initVector[1] = { 0 };

    {
      int_T i1;
      for (i1=0; i1 < 1; i1++) {
        servosfunc_DW.SFunctionBuilder_DSTATE = initVector[0];
      }
    }
  }

  /* InitializeConditions for DiscreteTransferFcn: '<S4>/Filter Differentiator TF' */
  servosfunc_DW.FilterDifferentiatorTF_states =
    servosfunc_P.FilterDifferentiatorTF_InitialS;

  /* InitializeConditions for DiscreteIntegrator: '<S1>/Integrator' */
  servosfunc_DW.Integrator_DSTATE = servosfunc_P.Integrator_IC;
}

/* Model terminate function */
void servosfunc_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

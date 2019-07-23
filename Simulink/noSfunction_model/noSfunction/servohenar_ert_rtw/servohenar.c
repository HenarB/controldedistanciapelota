/*
 * File: servohenar.c
 *
 * Code generated for Simulink model 'servohenar'.
 *
 * Model version                  : 1.25
 * Simulink Coder version         : 8.14 (R2018a) 06-Feb-2018
 * C/C++ source code generated on : Mon Jun 24 19:29:57 2019
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "servohenar.h"
#include "servohenar_private.h"

/* Block states (default storage) */
DW_servohenar_T servohenar_DW;

/* Real-time model */
RT_MODEL_servohenar_T servohenar_M_;
RT_MODEL_servohenar_T *const servohenar_M = &servohenar_M_;

/* Forward declaration for local functions */
static void SystemProp_matlabCodegenSetAnyP(codertarget_arduinobase_int_b_T *obj,
  boolean_T value);
static void matlabCodegenHandle_matlabCodeg(codertarget_arduinobase_int_b_T *obj);
static void SystemProp_matlabCodegenSetAnyP(codertarget_arduinobase_int_b_T *obj,
  boolean_T value)
{
  obj->matlabCodegenIsDeleted = value;
}

static void matlabCodegenHandle_matlabCodeg(codertarget_arduinobase_int_b_T *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    SystemProp_matlabCodegenSetAnyP(obj, true);
  }
}

/* Model step function */
void servohenar_step(void)
{
  uint16_T rtb_AnalogInput_0;
  boolean_T p;
  real32_T rtb_Saturate;
  real32_T rtb_SignPreIntegrator;
  real32_T rtb_IntegralGain;
  real32_T rtb_FilterCoefficient;
  boolean_T rtb_NotEqual;
  real32_T rtb_ZeroGain;
  real32_T TmpSignalConversionAtFilterDiff;
  int8_T rtb_SignPreIntegrator_0;
  uint8_T rtb_Saturate_0;

  /* SampleTimeMath: '<S5>/TSamp' incorporates:
   *  Constant: '<S5>/N Copy'
   *
   * About '<S5>/TSamp':
   *  y = u * K where K = ( w * Ts )
   */
  rtb_IntegralGain = servohenar_P.PID_N * servohenar_P.TSamp_WtEt;

  /* Math: '<S5>/Reciprocal' incorporates:
   *  Constant: '<S5>/Constant'
   *  Sum: '<S5>/SumDen'
   *
   * About '<S5>/Reciprocal':
   *  Operator: reciprocal
   */
  rtb_Saturate = 1.0F / (servohenar_P.Constant_Value + rtb_IntegralGain);

  /* SignalConversion: '<S5>/TmpSignal ConversionAtFilter Differentiator TFInport2' incorporates:
   *  Constant: '<S5>/Constant'
   *  Product: '<S5>/Divide'
   *  Sum: '<S5>/SumNum'
   */
  TmpSignalConversionAtFilterDiff = (rtb_IntegralGain -
    servohenar_P.Constant_Value) * rtb_Saturate;

  /* MATLABSystem: '<Root>/Analog Input' */
  rtb_NotEqual = false;
  p = true;
  if (!(servohenar_DW.obj.SampleTime == servohenar_P.AnalogInput_SampleTime)) {
    p = false;
  }

  if (p) {
    rtb_NotEqual = true;
  }

  if (!rtb_NotEqual) {
    servohenar_DW.obj.SampleTime = servohenar_P.AnalogInput_SampleTime;
  }

  MW_AnalogIn_Start(servohenar_DW.obj.MW_ANALOGIN_HANDLE);
  MW_AnalogInSingle_ReadResult(servohenar_DW.obj.MW_ANALOGIN_HANDLE,
    &rtb_AnalogInput_0, 3);

  /* Sum: '<Root>/Sum' incorporates:
   *  Constant: '<Root>/Consigna'
   *  Constant: '<S1>/Inversor'
   *  Gain: '<S1>/Gain'
   *  Gain: '<S1>/Gain1'
   *  MATLABSystem: '<Root>/Analog Input'
   *  Sum: '<S1>/Sum1'
   */
  rtb_IntegralGain = servohenar_P.Consigna_Value - (servohenar_P.Inversor_Value
    - (real32_T)((uint32_T)servohenar_P.Gain_Gain * rtb_AnalogInput_0) *
    2.98023224E-8F) * servohenar_P.Gain1_Gain;

  /* DiscreteTransferFcn: '<S5>/Filter Differentiator TF' incorporates:
   *  Gain: '<S2>/Derivative Gain'
   */
  TmpSignalConversionAtFilterDiff = servohenar_P.PID_D * rtb_IntegralGain -
    TmpSignalConversionAtFilterDiff *
    servohenar_DW.FilterDifferentiatorTF_states;

  /* Gain: '<S5>/Filter Coefficient' incorporates:
   *  DiscreteTransferFcn: '<S5>/Filter Differentiator TF'
   *  Product: '<S5>/DenCoefOut'
   */
  rtb_FilterCoefficient = (servohenar_P.FilterDifferentiatorTF_NumCoef[0] *
    TmpSignalConversionAtFilterDiff +
    servohenar_P.FilterDifferentiatorTF_NumCoef[1L] *
    servohenar_DW.FilterDifferentiatorTF_states) * rtb_Saturate *
    servohenar_P.PID_N;

  /* Gain: '<S2>/Proportional Gain' */
  rtb_Saturate = servohenar_P.PID_P * rtb_IntegralGain;

  /* Gain: '<S2>/Integral Gain' */
  rtb_IntegralGain *= servohenar_P.PID_I;

  /* Sum: '<S2>/Sum Fdbk' */
  rtb_SignPreIntegrator = (rtb_Saturate + servohenar_DW.Integrator_DSTATE) +
    rtb_FilterCoefficient;

  /* Gain: '<S4>/ZeroGain' */
  rtb_ZeroGain = servohenar_P.ZeroGain_Gain * rtb_SignPreIntegrator;

  /* DeadZone: '<S4>/DeadZone' */
  if (rtb_SignPreIntegrator > servohenar_P.PID_UpperSaturationLimit) {
    rtb_SignPreIntegrator -= servohenar_P.PID_UpperSaturationLimit;
  } else if (rtb_SignPreIntegrator >= servohenar_P.PID_LowerSaturationLimit) {
    rtb_SignPreIntegrator = 0.0F;
  } else {
    rtb_SignPreIntegrator -= servohenar_P.PID_LowerSaturationLimit;
  }

  /* End of DeadZone: '<S4>/DeadZone' */

  /* RelationalOperator: '<S4>/NotEqual' */
  rtb_NotEqual = (rtb_ZeroGain != rtb_SignPreIntegrator);

  /* Signum: '<S4>/SignDeltaU' */
  if (rtb_SignPreIntegrator < 0.0F) {
    rtb_SignPreIntegrator = -1.0F;
  } else if (rtb_SignPreIntegrator > 0.0F) {
    rtb_SignPreIntegrator = 1.0F;
  } else if (rtb_SignPreIntegrator == 0.0F) {
    rtb_SignPreIntegrator = 0.0F;
  } else {
    rtb_SignPreIntegrator = (rtNaNF);
  }

  /* End of Signum: '<S4>/SignDeltaU' */

  /* Signum: '<S4>/SignPreIntegrator' */
  if (rtb_IntegralGain < 0.0F) {
    /* DataTypeConversion: '<S4>/DataTypeConv2' */
    rtb_ZeroGain = -1.0F;
  } else if (rtb_IntegralGain > 0.0F) {
    /* DataTypeConversion: '<S4>/DataTypeConv2' */
    rtb_ZeroGain = 1.0F;
  } else if (rtb_IntegralGain == 0.0F) {
    /* DataTypeConversion: '<S4>/DataTypeConv2' */
    rtb_ZeroGain = 0.0F;
  } else {
    /* DataTypeConversion: '<S4>/DataTypeConv2' */
    rtb_ZeroGain = (rtNaNF);
  }

  /* End of Signum: '<S4>/SignPreIntegrator' */

  /* DataTypeConversion: '<S4>/DataTypeConv2' */
  if (rtIsNaNF(rtb_ZeroGain)) {
    rtb_ZeroGain = 0.0F;
  } else {
    rtb_ZeroGain = (real32_T)fmod(rtb_ZeroGain, 256.0);
  }

  /* DataTypeConversion: '<S4>/DataTypeConv1' */
  if (rtb_SignPreIntegrator < 128.0F) {
    rtb_SignPreIntegrator_0 = (int8_T)rtb_SignPreIntegrator;
  } else {
    rtb_SignPreIntegrator_0 = MAX_int8_T;
  }

  /* End of DataTypeConversion: '<S4>/DataTypeConv1' */

  /* Switch: '<S2>/Switch' incorporates:
   *  Constant: '<S2>/Constant'
   *  DataTypeConversion: '<S4>/DataTypeConv2'
   *  Logic: '<S4>/AND'
   *  RelationalOperator: '<S4>/Equal'
   */
  if (rtb_NotEqual && ((rtb_ZeroGain < 0.0F ? (int16_T)(int8_T)-(int8_T)(uint8_T)
                        -rtb_ZeroGain : (int16_T)(int8_T)(uint8_T)rtb_ZeroGain) ==
                       rtb_SignPreIntegrator_0)) {
    rtb_IntegralGain = servohenar_P.Constant_Value_f;
  }

  /* End of Switch: '<S2>/Switch' */

  /* DiscreteIntegrator: '<S2>/Integrator' */
  rtb_IntegralGain *= servohenar_P.Integrator_gainval;
  rtb_SignPreIntegrator = rtb_IntegralGain + servohenar_DW.Integrator_DSTATE;

  /* Sum: '<S2>/Sum' */
  rtb_Saturate = (rtb_Saturate + rtb_SignPreIntegrator) + rtb_FilterCoefficient;

  /* Saturate: '<S2>/Saturate' */
  if (rtb_Saturate > servohenar_P.PID_UpperSaturationLimit) {
    rtb_Saturate = servohenar_P.PID_UpperSaturationLimit;
  } else {
    if (rtb_Saturate < servohenar_P.PID_LowerSaturationLimit) {
      rtb_Saturate = servohenar_P.PID_LowerSaturationLimit;
    }
  }

  /* End of Saturate: '<S2>/Saturate' */

  /* DataTypeConversion: '<S3>/Data Type Conversion' */
  if (rtb_Saturate < 256.0F) {
    if (rtb_Saturate >= 0.0F) {
      rtb_Saturate_0 = (uint8_T)rtb_Saturate;
    } else {
      rtb_Saturate_0 = 0U;
    }
  } else {
    rtb_Saturate_0 = MAX_uint8_T;
  }

  /* End of DataTypeConversion: '<S3>/Data Type Conversion' */

  /* S-Function (arduinoservowrite_sfcn): '<S3>/Servo Write' */
  MW_servoWrite(servohenar_P.ServoWrite_p1, rtb_Saturate_0);

  /* Update for DiscreteTransferFcn: '<S5>/Filter Differentiator TF' */
  servohenar_DW.FilterDifferentiatorTF_states = TmpSignalConversionAtFilterDiff;

  /* Update for DiscreteIntegrator: '<S2>/Integrator' */
  servohenar_DW.Integrator_DSTATE = rtb_IntegralGain + rtb_SignPreIntegrator;
}

/* Model initialize function */
void servohenar_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize error status */
  rtmSetErrorStatus(servohenar_M, (NULL));

  /* states (dwork) */
  (void) memset((void *)&servohenar_DW, 0,
                sizeof(DW_servohenar_T));

  {
    codertarget_arduinobase_int_b_T *obj;
    MW_AnalogIn_TriggerSource_Type trigger_val;

    /* Start for MATLABSystem: '<Root>/Analog Input' */
    servohenar_DW.obj.matlabCodegenIsDeleted = true;
    obj = &servohenar_DW.obj;
    servohenar_DW.obj.isInitialized = 0L;
    obj->Hw.AvailablePwmPinNames.f1 = '2';
    obj->Hw.AvailablePwmPinNames.f2 = '3';
    obj->Hw.AvailablePwmPinNames.f3 = '4';
    obj->Hw.AvailablePwmPinNames.f4 = '5';
    obj->Hw.AvailablePwmPinNames.f5 = '6';
    obj->Hw.AvailablePwmPinNames.f6 = '7';
    obj->Hw.AvailablePwmPinNames.f7 = '8';
    obj->Hw.AvailablePwmPinNames.f8 = '9';
    obj->Hw.AvailablePwmPinNames.f9[0] = '1';
    obj->Hw.AvailablePwmPinNames.f9[1] = '0';
    obj->Hw.AvailablePwmPinNames.f10[0] = '1';
    obj->Hw.AvailablePwmPinNames.f10[1] = '1';
    obj->Hw.AvailablePwmPinNames.f11[0] = '1';
    obj->Hw.AvailablePwmPinNames.f11[1] = '2';
    obj->Hw.AvailablePwmPinNames.f12[0] = '1';
    obj->Hw.AvailablePwmPinNames.f12[1] = '3';
    servohenar_DW.obj.matlabCodegenIsDeleted = false;
    servohenar_DW.obj.SampleTime = servohenar_P.AnalogInput_SampleTime;
    obj = &servohenar_DW.obj;
    servohenar_DW.obj.isSetupComplete = false;
    servohenar_DW.obj.isInitialized = 1L;
    obj->MW_ANALOGIN_HANDLE = MW_AnalogInSingle_Open(15UL);
    trigger_val = MW_ANALOGIN_SOFTWARE_TRIGGER;
    MW_AnalogIn_SetTriggerSource(servohenar_DW.obj.MW_ANALOGIN_HANDLE,
      trigger_val, 0UL);
    servohenar_DW.obj.isSetupComplete = true;

    /* Start for S-Function (arduinoservowrite_sfcn): '<S3>/Servo Write' */
    MW_servoAttach(servohenar_P.ServoWrite_p1, servohenar_P.ServoWrite_pinNumber);

    /* InitializeConditions for DiscreteTransferFcn: '<S5>/Filter Differentiator TF' */
    servohenar_DW.FilterDifferentiatorTF_states =
      servohenar_P.FilterDifferentiatorTF_InitialS;

    /* InitializeConditions for DiscreteIntegrator: '<S2>/Integrator' */
    servohenar_DW.Integrator_DSTATE = servohenar_P.Integrator_IC;
  }
}

/* Model terminate function */
void servohenar_terminate(void)
{
  /* Terminate for MATLABSystem: '<Root>/Analog Input' */
  matlabCodegenHandle_matlabCodeg(&servohenar_DW.obj);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

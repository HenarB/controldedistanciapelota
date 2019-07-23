/*
 * File: servohenar_data.c
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

/* Block parameters (default storage) */
P_servohenar_T servohenar_P = {
  /* Mask Parameter: PID_D
   * Referenced by: '<S2>/Derivative Gain'
   */
  25.0F,

  /* Mask Parameter: PID_I
   * Referenced by: '<S2>/Integral Gain'
   */
  3.0F,

  /* Mask Parameter: PID_LowerSaturationLimit
   * Referenced by:
   *   '<S2>/Saturate'
   *   '<S4>/DeadZone'
   */
  0.0F,

  /* Mask Parameter: PID_N
   * Referenced by:
   *   '<S5>/N Copy'
   *   '<S5>/Filter Coefficient'
   */
  100.0F,

  /* Mask Parameter: PID_P
   * Referenced by: '<S2>/Proportional Gain'
   */
  15.0F,

  /* Mask Parameter: PID_UpperSaturationLimit
   * Referenced by:
   *   '<S2>/Saturate'
   *   '<S4>/DeadZone'
   */
  180.0F,

  /* Mask Parameter: ServoWrite_pinNumber
   * Referenced by: '<S3>/Servo Write'
   */
  46U,

  /* Expression: 0.06
   * Referenced by: '<Root>/Analog Input'
   */
  0.06,

  /* Computed Parameter: Constant_Value
   * Referenced by: '<S5>/Constant'
   */
  1.0F,

  /* Computed Parameter: TSamp_WtEt
   * Referenced by: '<S5>/TSamp'
   */
  0.03F,

  /* Computed Parameter: Consigna_Value
   * Referenced by: '<Root>/Consigna'
   */
  20.0F,

  /* Computed Parameter: Inversor_Value
   * Referenced by: '<S1>/Inversor'
   */
  1.0F,

  /* Computed Parameter: Gain1_Gain
   * Referenced by: '<S1>/Gain1'
   */
  30.0F,

  /* Computed Parameter: FilterDifferentiatorTF_NumCoef
   * Referenced by: '<S5>/Filter Differentiator TF'
   */
  { 1.0F, -1.0F },

  /* Computed Parameter: FilterDifferentiatorTF_InitialS
   * Referenced by: '<S5>/Filter Differentiator TF'
   */
  0.0F,

  /* Computed Parameter: Constant_Value_f
   * Referenced by: '<S2>/Constant'
   */
  0.0F,

  /* Computed Parameter: ZeroGain_Gain
   * Referenced by: '<S4>/ZeroGain'
   */
  0.0F,

  /* Computed Parameter: Integrator_gainval
   * Referenced by: '<S2>/Integrator'
   */
  0.03F,

  /* Computed Parameter: Integrator_IC
   * Referenced by: '<S2>/Integrator'
   */
  0.0F,

  /* Computed Parameter: Gain_Gain
   * Referenced by: '<S1>/Gain'
   */
  32768U,

  /* Computed Parameter: ServoWrite_p1
   * Referenced by: '<S3>/Servo Write'
   */
  0U
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

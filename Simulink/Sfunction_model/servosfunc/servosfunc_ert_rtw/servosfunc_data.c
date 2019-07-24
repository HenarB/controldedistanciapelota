/*
 * File: servosfunc_data.c
 *
 * Code generated for Simulink model 'servosfunc'.
 *
 * Model version                  : 1.55
 * Simulink Coder version         : 8.14 (R2018a) 06-Feb-2018
 * C/C++ source code generated on : Wed Jul 24 14:07:41 2019
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "servosfunc.h"
#include "servosfunc_private.h"

/* Block parameters (default storage) */
P_servosfunc_T servosfunc_P = {
  /* Mask Parameter: DiscretePIDController_D
   * Referenced by: '<S1>/Derivative Gain'
   */
  25.0,

  /* Mask Parameter: DiscretePIDController_I
   * Referenced by: '<S1>/Integral Gain'
   */
  -6.0,

  /* Mask Parameter: DiscretePIDController_LowerSatu
   * Referenced by:
   *   '<S1>/Saturate'
   *   '<S4>/DeadZone'
   */
  0.0,

  /* Mask Parameter: DiscretePIDController_N
   * Referenced by:
   *   '<S5>/N Copy'
   *   '<S5>/Filter Coefficient'
   */
  100.0,

  /* Mask Parameter: DiscretePIDController_P
   * Referenced by: '<S1>/Proportional Gain'
   */
  -12.0,

  /* Mask Parameter: DiscretePIDController_UpperSatu
   * Referenced by:
   *   '<S1>/Saturate'
   *   '<S4>/DeadZone'
   */
  180.0,

  /* Mask Parameter: ServoWrite_pinNumber
   * Referenced by: '<S3>/Servo Write'
   */
  46U,

  /* Expression: 1
   * Referenced by: '<Root>/Constant'
   */
  1.0,

  /* Expression: 82.390641362145
   * Referenced by: '<Root>/Ángulo deseado'
   */
  82.390641362145,

  /* Expression: 1
   * Referenced by: '<S5>/Constant'
   */
  1.0,

  /* Computed Parameter: TSamp_WtEt
   * Referenced by: '<S5>/TSamp'
   */
  0.03,

  /* Expression: 20
   * Referenced by: '<Root>/Consigna'
   */
  20.0,

  /* Expression: [1 -1]
   * Referenced by: '<S5>/Filter Differentiator TF'
   */
  { 1.0, -1.0 },

  /* Expression: InitialConditionForFilter
   * Referenced by: '<S5>/Filter Differentiator TF'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S1>/Constant'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S4>/ZeroGain'
   */
  0.0,

  /* Computed Parameter: Integrator_gainval
   * Referenced by: '<S1>/Integrator'
   */
  0.03,

  /* Expression: InitialConditionForIntegrator
   * Referenced by: '<S1>/Integrator'
   */
  0.0,

  /* Expression: 0.0004
   * Referenced by: '<Root>/Constant1'
   */
  0.0004,

  /* Computed Parameter: ManualSwitch_CurrentSetting
   * Referenced by: '<Root>/Manual Switch'
   */
  1U,

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

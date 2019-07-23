/*
 * File: servohenar.h
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

#ifndef RTW_HEADER_servohenar_h_
#define RTW_HEADER_servohenar_h_
#include <math.h>
#include <stddef.h>
#include <string.h>
#ifndef servohenar_COMMON_INCLUDES_
# define servohenar_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "MW_AnalogIn.h"
#include "arduino_servowrite_lct.h"
#endif                                 /* servohenar_COMMON_INCLUDES_ */

#include "servohenar_types.h"
#include "MW_target_hardware_resources.h"
#include "rtGetNaN.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Block states (default storage) for system '<Root>' */
typedef struct {
  codertarget_arduinobase_int_b_T obj; /* '<Root>/Analog Input' */
  real32_T FilterDifferentiatorTF_states;/* '<S5>/Filter Differentiator TF' */
  real32_T Integrator_DSTATE;          /* '<S2>/Integrator' */
} DW_servohenar_T;

/* Parameters (default storage) */
struct P_servohenar_T_ {
  real32_T PID_D;                      /* Mask Parameter: PID_D
                                        * Referenced by: '<S2>/Derivative Gain'
                                        */
  real32_T PID_I;                      /* Mask Parameter: PID_I
                                        * Referenced by: '<S2>/Integral Gain'
                                        */
  real32_T PID_LowerSaturationLimit;   /* Mask Parameter: PID_LowerSaturationLimit
                                        * Referenced by:
                                        *   '<S2>/Saturate'
                                        *   '<S4>/DeadZone'
                                        */
  real32_T PID_N;                      /* Mask Parameter: PID_N
                                        * Referenced by:
                                        *   '<S5>/N Copy'
                                        *   '<S5>/Filter Coefficient'
                                        */
  real32_T PID_P;                      /* Mask Parameter: PID_P
                                        * Referenced by: '<S2>/Proportional Gain'
                                        */
  real32_T PID_UpperSaturationLimit;   /* Mask Parameter: PID_UpperSaturationLimit
                                        * Referenced by:
                                        *   '<S2>/Saturate'
                                        *   '<S4>/DeadZone'
                                        */
  uint32_T ServoWrite_pinNumber;       /* Mask Parameter: ServoWrite_pinNumber
                                        * Referenced by: '<S3>/Servo Write'
                                        */
  real_T AnalogInput_SampleTime;       /* Expression: 0.06
                                        * Referenced by: '<Root>/Analog Input'
                                        */
  real32_T Constant_Value;             /* Computed Parameter: Constant_Value
                                        * Referenced by: '<S5>/Constant'
                                        */
  real32_T TSamp_WtEt;                 /* Computed Parameter: TSamp_WtEt
                                        * Referenced by: '<S5>/TSamp'
                                        */
  real32_T Consigna_Value;             /* Computed Parameter: Consigna_Value
                                        * Referenced by: '<Root>/Consigna'
                                        */
  real32_T Inversor_Value;             /* Computed Parameter: Inversor_Value
                                        * Referenced by: '<S1>/Inversor'
                                        */
  real32_T Gain1_Gain;                 /* Computed Parameter: Gain1_Gain
                                        * Referenced by: '<S1>/Gain1'
                                        */
  real32_T FilterDifferentiatorTF_NumCoef[2];/* Computed Parameter: FilterDifferentiatorTF_NumCoef
                                              * Referenced by: '<S5>/Filter Differentiator TF'
                                              */
  real32_T FilterDifferentiatorTF_InitialS;/* Computed Parameter: FilterDifferentiatorTF_InitialS
                                            * Referenced by: '<S5>/Filter Differentiator TF'
                                            */
  real32_T Constant_Value_f;           /* Computed Parameter: Constant_Value_f
                                        * Referenced by: '<S2>/Constant'
                                        */
  real32_T ZeroGain_Gain;              /* Computed Parameter: ZeroGain_Gain
                                        * Referenced by: '<S4>/ZeroGain'
                                        */
  real32_T Integrator_gainval;         /* Computed Parameter: Integrator_gainval
                                        * Referenced by: '<S2>/Integrator'
                                        */
  real32_T Integrator_IC;              /* Computed Parameter: Integrator_IC
                                        * Referenced by: '<S2>/Integrator'
                                        */
  uint16_T Gain_Gain;                  /* Computed Parameter: Gain_Gain
                                        * Referenced by: '<S1>/Gain'
                                        */
  uint8_T ServoWrite_p1;               /* Computed Parameter: ServoWrite_p1
                                        * Referenced by: '<S3>/Servo Write'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_servohenar_T {
  const char_T *errorStatus;
};

/* Block parameters (default storage) */
extern P_servohenar_T servohenar_P;

/* Block states (default storage) */
extern DW_servohenar_T servohenar_DW;

/* Model entry point functions */
extern void servohenar_initialize(void);
extern void servohenar_step(void);
extern void servohenar_terminate(void);

/* Real-time Model object */
extern RT_MODEL_servohenar_T *const servohenar_M;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S1>/Distancia en CM' : Unused code path elimination
 * Block '<S1>/Distancia escalada' : Unused code path elimination
 * Block '<S1>/Medición del sensor' : Unused code path elimination
 * Block '<Root>/Distancia medida' : Unused code path elimination
 * Block '<Root>/Señal para el servo en grados' : Unused code path elimination
 */

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'servohenar'
 * '<S1>'   : 'servohenar/Cálculo de  distancia'
 * '<S2>'   : 'servohenar/PID'
 * '<S3>'   : 'servohenar/Standard Servo Write'
 * '<S4>'   : 'servohenar/PID/Clamping circuit'
 * '<S5>'   : 'servohenar/PID/Filter Differentiator'
 */
#endif                                 /* RTW_HEADER_servohenar_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

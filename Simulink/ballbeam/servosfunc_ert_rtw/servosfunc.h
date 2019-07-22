/*
 * File: servosfunc.h
 *
 * Code generated for Simulink model 'servosfunc'.
 *
 * Model version                  : 1.43
 * Simulink Coder version         : 8.14 (R2018a) 06-Feb-2018
 * C/C++ source code generated on : Mon Jun 24 19:23:37 2019
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_servosfunc_h_
#define RTW_HEADER_servosfunc_h_
#include <math.h>
#include <float.h>
#include <string.h>
#include <stddef.h>
#ifndef servosfunc_COMMON_INCLUDES_
# define servosfunc_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "dt_info.h"
#include "ext_work.h"
#include "arduino_servowrite_lct.h"
#endif                                 /* servosfunc_COMMON_INCLUDES_ */

#include "servosfunc_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "MW_target_hardware_resources.h"
#include "rtGetNaN.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetFinalTime
# define rtmGetFinalTime(rtm)          ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetRTWExtModeInfo
# define rtmGetRTWExtModeInfo(rtm)     ((rtm)->extModeInfo)
#endif

#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
# define rtmGetStopRequested(rtm)      ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
# define rtmSetStopRequested(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
# define rtmGetStopRequestedPtr(rtm)   (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
# define rtmGetT(rtm)                  ((rtm)->Timing.taskTime0)
#endif

#ifndef rtmGetTFinal
# define rtmGetTFinal(rtm)             ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetTPtr
# define rtmGetTPtr(rtm)               (&(rtm)->Timing.taskTime0)
#endif

/* Block signals (default storage) */
typedef struct {
  real_T SFunctionBuilder;             /* '<S3>/S-Function Builder' */
  real_T Saturate;                     /* '<S1>/Saturate' */
} B_servosfunc_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T SFunctionBuilder_DSTATE;      /* '<S3>/S-Function Builder' */
  real_T FilterDifferentiatorTF_states;/* '<S5>/Filter Differentiator TF' */
  real_T Integrator_DSTATE;            /* '<S1>/Integrator' */
} DW_servosfunc_T;

/* Parameters (default storage) */
struct P_servosfunc_T_ {
  real_T DiscretePIDController_D;      /* Mask Parameter: DiscretePIDController_D
                                        * Referenced by: '<S1>/Derivative Gain'
                                        */
  real_T DiscretePIDController_I;      /* Mask Parameter: DiscretePIDController_I
                                        * Referenced by: '<S1>/Integral Gain'
                                        */
  real_T DiscretePIDController_LowerSatu;/* Mask Parameter: DiscretePIDController_LowerSatu
                                          * Referenced by:
                                          *   '<S1>/Saturate'
                                          *   '<S4>/DeadZone'
                                          */
  real_T DiscretePIDController_N;      /* Mask Parameter: DiscretePIDController_N
                                        * Referenced by:
                                        *   '<S5>/N Copy'
                                        *   '<S5>/Filter Coefficient'
                                        */
  real_T DiscretePIDController_P;      /* Mask Parameter: DiscretePIDController_P
                                        * Referenced by: '<S1>/Proportional Gain'
                                        */
  real_T DiscretePIDController_UpperSatu;/* Mask Parameter: DiscretePIDController_UpperSatu
                                          * Referenced by:
                                          *   '<S1>/Saturate'
                                          *   '<S4>/DeadZone'
                                          */
  uint32_T ServoWrite_pinNumber;       /* Mask Parameter: ServoWrite_pinNumber
                                        * Referenced by: '<S2>/Servo Write'
                                        */
  real_T Constant_Value;               /* Expression: 1
                                        * Referenced by: '<S5>/Constant'
                                        */
  real_T TSamp_WtEt;                   /* Computed Parameter: TSamp_WtEt
                                        * Referenced by: '<S5>/TSamp'
                                        */
  real_T Consigna_Value;               /* Expression: 20
                                        * Referenced by: '<Root>/Consigna'
                                        */
  real_T FilterDifferentiatorTF_NumCoef[2];/* Expression: [1 -1]
                                            * Referenced by: '<S5>/Filter Differentiator TF'
                                            */
  real_T FilterDifferentiatorTF_InitialS;/* Expression: InitialConditionForFilter
                                          * Referenced by: '<S5>/Filter Differentiator TF'
                                          */
  real_T Constant_Value_j;             /* Expression: 0
                                        * Referenced by: '<S1>/Constant'
                                        */
  real_T ZeroGain_Gain;                /* Expression: 0
                                        * Referenced by: '<S4>/ZeroGain'
                                        */
  real_T Integrator_gainval;           /* Computed Parameter: Integrator_gainval
                                        * Referenced by: '<S1>/Integrator'
                                        */
  real_T Integrator_IC;                /* Expression: InitialConditionForIntegrator
                                        * Referenced by: '<S1>/Integrator'
                                        */
  uint8_T ServoWrite_p1;               /* Computed Parameter: ServoWrite_p1
                                        * Referenced by: '<S2>/Servo Write'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_servosfunc_T {
  const char_T *errorStatus;
  RTWExtModeInfo *extModeInfo;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    uint32_T checksums[4];
  } Sizes;

  /*
   * SpecialInfo:
   * The following substructure contains special information
   * related to other components that are dependent on RTW.
   */
  struct {
    const void *mappingInfo;
  } SpecialInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    time_T taskTime0;
    uint32_T clockTick0;
    time_T stepSize0;
    time_T tFinal;
    boolean_T stopRequestedFlag;
  } Timing;
};

/* Block parameters (default storage) */
extern P_servosfunc_T servosfunc_P;

/* Block signals (default storage) */
extern B_servosfunc_T servosfunc_B;

/* Block states (default storage) */
extern DW_servosfunc_T servosfunc_DW;

/* Model entry point functions */
extern void servosfunc_initialize(void);
extern void servosfunc_step(void);
extern void servosfunc_terminate(void);

/* Real-time Model object */
extern RT_MODEL_servosfunc_T *const servosfunc_M;

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
 * '<Root>' : 'servosfunc'
 * '<S1>'   : 'servosfunc/Discrete PID Controller'
 * '<S2>'   : 'servosfunc/Standard Servo Write'
 * '<S3>'   : 'servosfunc/Subsystem3'
 * '<S4>'   : 'servosfunc/Discrete PID Controller/Clamping circuit'
 * '<S5>'   : 'servosfunc/Discrete PID Controller/Filter Differentiator'
 */
#endif                                 /* RTW_HEADER_servosfunc_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

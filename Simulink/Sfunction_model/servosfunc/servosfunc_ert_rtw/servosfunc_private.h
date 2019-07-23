/*
 * File: servosfunc_private.h
 *
 * Code generated for Simulink model 'servosfunc'.
 *
 * Model version                  : 1.49
 * Simulink Coder version         : 8.14 (R2018a) 06-Feb-2018
 * C/C++ source code generated on : Tue Jul 23 17:53:08 2019
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_servosfunc_private_h_
#define RTW_HEADER_servosfunc_private_h_
#include "rtwtypes.h"
#include "multiword_types.h"

/* Private macros used by the generated code to access rtModel */
#ifndef rtmSetTFinal
# define rtmSetTFinal(rtm, val)        ((rtm)->Timing.tFinal = (val))
#endif

#ifdef __cplusplus

extern "C" {

#endif

  extern void bloque1_Start_wrapper(real_T *xD);
  extern void bloque1_Outputs_wrapper(real_T *dist1,
    const real_T *xD);
  extern void bloque1_Update_wrapper(real_T *dist1,
    real_T *xD);
  extern void bloque1_Terminate_wrapper(real_T *xD);

#ifdef __cplusplus

}
#endif
#endif                                 /* RTW_HEADER_servosfunc_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

/*
 * File: servohenar_types.h
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

#ifndef RTW_HEADER_servohenar_types_h_
#define RTW_HEADER_servohenar_types_h_
#include "rtwtypes.h"

/* Custom Type definition for MATLABSystem: '<Root>/Analog Input' */
#include "MW_SVD.h"
#ifndef typedef_cell_servohenar_T
#define typedef_cell_servohenar_T

typedef struct {
  char_T f1;
  char_T f2;
  char_T f3;
  char_T f4;
  char_T f5;
  char_T f6;
  char_T f7;
  char_T f8;
  char_T f9[2];
  char_T f10[2];
  char_T f11[2];
  char_T f12[2];
} cell_servohenar_T;

#endif                                 /*typedef_cell_servohenar_T*/

#ifndef typedef_codertarget_arduinobase_inter_T
#define typedef_codertarget_arduinobase_inter_T

typedef struct {
  cell_servohenar_T AvailablePwmPinNames;
} codertarget_arduinobase_inter_T;

#endif                                 /*typedef_codertarget_arduinobase_inter_T*/

#ifndef typedef_codertarget_arduinobase_int_b_T
#define typedef_codertarget_arduinobase_int_b_T

typedef struct {
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  codertarget_arduinobase_inter_T Hw;
  MW_Handle_Type MW_ANALOGIN_HANDLE;
  real_T SampleTime;
} codertarget_arduinobase_int_b_T;

#endif                                 /*typedef_codertarget_arduinobase_int_b_T*/

/* Parameters (default storage) */
typedef struct P_servohenar_T_ P_servohenar_T;

/* Forward declaration for rtModel */
typedef struct tag_RTM_servohenar_T RT_MODEL_servohenar_T;

#endif                                 /* RTW_HEADER_servohenar_types_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

/*
 * File: thrust_test.h
 *
 * Code generated for Simulink model 'thrust_test'.
 *
 * Model version                  : 1.3
 * Simulink Coder version         : 8.14 (R2018a) 06-Feb-2018
 * C/C++ source code generated on : Wed Feb 19 18:17:55 2020
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#ifndef RTW_HEADER_thrust_test_h_
#define RTW_HEADER_thrust_test_h_
#ifndef thrust_test_COMMON_INCLUDES_
# define thrust_test_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* thrust_test_COMMON_INCLUDES_ */

/* Macros for accessing real-time model data structure */

/* External inputs (root inport signals with default storage) */
typedef struct {
  real32_T thrust;                     /* '<Root>/thrust' */
} ExtU;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  uint16_T M1_output;                  /* '<Root>/M1_output' */
  uint16_T M2_output;                  /* '<Root>/M2_output' */
  uint16_T M3_output;                  /* '<Root>/M3_output' */
  uint16_T M4_output;                  /* '<Root>/M4_output' */
} ExtY;

/* External inputs (root inport signals with default storage) */
extern ExtU rtU;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY rtY;

/* Model entry point functions */
extern void thrust_test_initialize(void);
extern void thrust_test_step(void);

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
 * '<Root>' : 'thrust_test'
 */
#endif                                 /* RTW_HEADER_thrust_test_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

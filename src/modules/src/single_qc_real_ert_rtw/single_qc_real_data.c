/*
 * File: single_qc_real_data.c
 *
 * Code generated for Simulink model 'single_qc_real'.
 *
 * Model version                  : 1.17
 * Simulink Coder version         : 9.3 (R2020a) 18-Nov-2019
 * C/C++ source code generated on : Tue Apr 14 15:15:18 2020
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objective: Execution efficiency
 * Validation result: Not run
 */

#include "single_qc_real.h"
#include "single_qc_real_private.h"

/* Block parameters (default storage) */
P_single_qc_real_T single_qc_real_P = {
  /* Variable: dgaina
   * Referenced by: '<S31>/Derivative Gain'
   */
  0.0002,

  /* Variable: dgainb
   * Referenced by: '<S81>/Derivative Gain'
   */
  0.0002,

  /* Variable: igaina
   * Referenced by: '<S36>/Integral Gain'
   */
  0.0,

  /* Variable: igainb
   * Referenced by: '<S86>/Integral Gain'
   */
  0.0,

  /* Variable: pgaina
   * Referenced by: '<S44>/Proportional Gain'
   */
  0.001,

  /* Variable: pgainb
   * Referenced by: '<S94>/Proportional Gain'
   */
  0.001,

  /* Variable: torque_modifier
   * Referenced by: '<Root>/Constant'
   */
  1.0,

  /* Mask Parameter: DiscretePIDController_Different
   * Referenced by: '<S32>/UD'
   */
  0.0,

  /* Mask Parameter: DiscretePIDController1_Differen
   * Referenced by: '<S82>/UD'
   */
  0.0,

  /* Mask Parameter: DiscretePIDController_InitialCo
   * Referenced by: '<S39>/Integrator'
   */
  0.0,

  /* Mask Parameter: DiscretePIDController1_InitialC
   * Referenced by: '<S89>/Integrator'
   */
  0.0,

  /* Expression: 0.5886/65535
   * Referenced by: '<Root>/Gain'
   */
  8.9814602883955138E-6,

  /* Expression: 0.5355
   * Referenced by: '<Root>/Saturation'
   */
  0.5355,

  /* Expression: 0
   * Referenced by: '<Root>/Saturation'
   */
  0.0,

  /* Computed Parameter: Integrator_gainval
   * Referenced by: '<S39>/Integrator'
   */
  0.002,

  /* Computed Parameter: Tsamp_WtEt
   * Referenced by: '<S34>/Tsamp'
   */
  500.0,

  /* Expression: 5.6e-4
   * Referenced by: '<S3>/Saturation'
   */
  0.00056,

  /* Expression: -5.6e-4
   * Referenced by: '<S3>/Saturation'
   */
  -0.00056,

  /* Computed Parameter: Integrator_gainval_i
   * Referenced by: '<S89>/Integrator'
   */
  0.002,

  /* Computed Parameter: Tsamp_WtEt_c
   * Referenced by: '<S84>/Tsamp'
   */
  500.0,

  /* Expression: 5.6e-4
   * Referenced by: '<S3>/Saturation1'
   */
  0.00056,

  /* Expression: -5.6e-4
   * Referenced by: '<S3>/Saturation1'
   */
  -0.00056,

  /* Expression: 5.6e-4
   * Referenced by: '<S3>/Saturation2'
   */
  0.00056,

  /* Expression: -5.6e-4
   * Referenced by: '<S3>/Saturation2'
   */
  -0.00056,

  /* Expression: 65535
   * Referenced by: '<Root>/Saturation1'
   */
  65535.0,

  /* Expression: 0
   * Referenced by: '<Root>/Saturation1'
   */
  0.0
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

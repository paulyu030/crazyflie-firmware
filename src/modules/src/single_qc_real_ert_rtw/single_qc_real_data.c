/*
 * File: single_qc_real_data.c
 *
 * Code generated for Simulink model 'single_qc_real'.
 *
 * Model version                  : 1.52
 * Simulink Coder version         : 9.3 (R2020a) 18-Nov-2019
 * C/C++ source code generated on : Tue Aug 11 11:29:18 2020
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
   * Referenced by: '<S4>/dgain'
   */
  0.0002F,

  /* Variable: dgainb
   * Referenced by: '<S5>/dgain'
   */
  0.0002F,

  /* Variable: igaina
   * Referenced by: '<S4>/igain'
   */
  0.0F,

  /* Variable: igainb
   * Referenced by: '<S5>/igain'
   */
  0.0F,

  /* Variable: pgaina
   * Referenced by: '<S4>/pgain'
   */
  0.001F,

  /* Variable: pgainb
   * Referenced by: '<S5>/pgain'
   */
  0.001F,

  /* Variable: sat_tx
   * Referenced by: '<S3>/Saturation'
   */
  1.0F,

  /* Variable: sat_ty
   * Referenced by: '<S3>/Saturation1'
   */
  1.0F,

  /* Variable: sat_tz
   * Referenced by: '<S3>/Saturation2'
   */
  1.0F,

  /* Variable: torque_modifier
   * Referenced by: '<Root>/Constant'
   */
  1.0F,

  /* Computed Parameter: Gain_Gain
   * Referenced by: '<Root>/Gain'
   */
  8.98146E-6F,

  /* Computed Parameter: Saturation_UpperSat
   * Referenced by: '<Root>/Saturation'
   */
  0.5886F,

  /* Computed Parameter: Saturation_LowerSat
   * Referenced by: '<Root>/Saturation'
   */
  0.0F,

  /* Computed Parameter: Memory_InitialCondition
   * Referenced by: '<S4>/Memory'
   */
  0.0F,

  /* Computed Parameter: Memory1_InitialCondition
   * Referenced by: '<S4>/Memory1'
   */
  0.0F,

  /* Computed Parameter: dgain1_Gain
   * Referenced by: '<S4>/dgain1'
   */
  250.0F,

  /* Computed Parameter: Memory_InitialCondition_o
   * Referenced by: '<S5>/Memory'
   */
  0.0F,

  /* Computed Parameter: Memory2_InitialCondition
   * Referenced by: '<S5>/Memory2'
   */
  0.0F,

  /* Computed Parameter: dgain1_Gain_c
   * Referenced by: '<S5>/dgain1'
   */
  250.0F,

  /* Computed Parameter: Saturation1_UpperSat
   * Referenced by: '<Root>/Saturation1'
   */
  65535.0F,

  /* Computed Parameter: Saturation1_LowerSat
   * Referenced by: '<Root>/Saturation1'
   */
  0.0F,

  /* Computed Parameter: Memory2_InitialCondition_j
   * Referenced by: '<S4>/Memory2'
   */
  0.0F,

  /* Computed Parameter: Memory1_InitialCondition_l
   * Referenced by: '<S5>/Memory1'
   */
  0.0F
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

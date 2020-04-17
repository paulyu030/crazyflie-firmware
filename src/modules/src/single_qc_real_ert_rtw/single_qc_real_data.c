/*
 * File: single_qc_real_data.c
 *
 * Code generated for Simulink model 'single_qc_real'.
 *
 * Model version                  : 1.43
 * Simulink Coder version         : 9.3 (R2020a) 18-Nov-2019
 * C/C++ source code generated on : Thu Apr 16 14:58:38 2020
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
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
  0.0031F,

  /* Variable: sat_ty
   * Referenced by: '<S3>/Saturation1'
   */
  0.0031F,

  /* Variable: sat_tz
   * Referenced by: '<S3>/Saturation2'
   */
  0.0031F,

  /* Variable: torque_modifier
   * Referenced by: '<Root>/Constant'
   */
  1.0F,

  /* Mask Parameter: DiscreteDerivative2_ICPrevScale
   * Referenced by: '<S6>/UD'
   */
  0.0F,

  /* Mask Parameter: DiscreteDerivative2_ICPrevSca_h
   * Referenced by: '<S7>/UD'
   */
  0.0F,

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

  /* Computed Parameter: TSamp_WtEt
   * Referenced by: '<S6>/TSamp'
   */
  500.0F,

  /* Computed Parameter: Memory_InitialCondition_g
   * Referenced by: '<S5>/Memory'
   */
  0.0F,

  /* Computed Parameter: TSamp_WtEt_o
   * Referenced by: '<S7>/TSamp'
   */
  500.0F,

  /* Computed Parameter: Saturation1_UpperSat
   * Referenced by: '<Root>/Saturation1'
   */
  65535.0F,

  /* Computed Parameter: Saturation1_LowerSat
   * Referenced by: '<Root>/Saturation1'
   */
  0.0F
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

/*
 * File: single_qc_ppid_data.c
 *
 * Code generated for Simulink model 'single_qc_ppid'.
 *
 * Model version                  : 1.53
 * Simulink Coder version         : 9.3 (R2020a) 18-Nov-2019
 * C/C++ source code generated on : Thu Aug  6 12:16:58 2020
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objective: Execution efficiency
 * Validation result: Not run
 */

#include "single_qc_ppid.h"
#include "single_qc_ppid_private.h"

/* Block parameters (default storage) */
P_single_qc_ppid_T single_qc_ppid_P = {
  /* Variable: dgaina
   * Referenced by: '<S4>/dgain'
   */
  0.0002F,

  /* Variable: dgainas
   * Referenced by: '<S4>/dgain1'
   */
  0.0002F,

  /* Variable: dgainb
   * Referenced by: '<S5>/dgain'
   */
  0.0002F,

  /* Variable: dgainbs
   * Referenced by: '<S5>/dgain1'
   */
  0.0002F,

  /* Variable: igaina
   * Referenced by: '<S4>/igain'
   */
  0.0F,

  /* Variable: igainas
   * Referenced by: '<S4>/igain1'
   */
  0.0F,

  /* Variable: igainb
   * Referenced by: '<S5>/igain'
   */
  0.0F,

  /* Variable: igainbs
   * Referenced by: '<S5>/igain1'
   */
  0.0F,

  /* Variable: pgaina
   * Referenced by: '<S4>/pgain'
   */
  0.001F,

  /* Variable: pgainas
   * Referenced by: '<S4>/pgain1'
   */
  0.001F,

  /* Variable: pgainb
   * Referenced by: '<S5>/pgain'
   */
  0.001F,

  /* Variable: pgainbs
   * Referenced by: '<S5>/pgain1'
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

  /* Mask Parameter: DiscreteDerivative2_ICPrevScale
   * Referenced by: '<S7>/UD'
   */
  0.0F,

  /* Mask Parameter: DiscreteDerivative1_ICPrevScale
   * Referenced by: '<S6>/UD'
   */
  0.0F,

  /* Mask Parameter: DiscreteDerivative2_ICPrevSca_c
   * Referenced by: '<S11>/UD'
   */
  0.0F,

  /* Mask Parameter: DiscreteDerivative1_ICPrevSca_d
   * Referenced by: '<S10>/UD'
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
   * Referenced by: '<S7>/TSamp'
   */
  500.0F,

  /* Computed Parameter: Memory1_InitialCondition
   * Referenced by: '<S4>/Memory1'
   */
  0.0F,

  /* Computed Parameter: TSamp_WtEt_d
   * Referenced by: '<S6>/TSamp'
   */
  500.0F,

  /* Computed Parameter: Memory_InitialCondition_a
   * Referenced by: '<S5>/Memory'
   */
  0.0F,

  /* Computed Parameter: TSamp_WtEt_i
   * Referenced by: '<S11>/TSamp'
   */
  500.0F,

  /* Computed Parameter: Memory1_InitialCondition_d
   * Referenced by: '<S5>/Memory1'
   */
  0.0F,

  /* Computed Parameter: TSamp_WtEt_j
   * Referenced by: '<S10>/TSamp'
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

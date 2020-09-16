/*
 * File: single_qc_ppid_data.c
 *
 * Code generated for Simulink model 'single_qc_ppid'.
 *
 * Model version                  : 1.66
 * Simulink Coder version         : 9.3 (R2020a) 18-Nov-2019
 * C/C++ source code generated on : Tue Sep 15 21:21:08 2020
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
  0.4F,

  /* Variable: dgainas
   * Referenced by: '<S4>/dgain1'
   */
  4.0E-5F,

  /* Variable: dgainb
   * Referenced by: '<S5>/dgain'
   */
  0.5F,

  /* Variable: dgainbs
   * Referenced by: '<S5>/dgain1'
   */
  5.0E-5F,

  /* Variable: igaina
   * Referenced by: '<S4>/igain'
   */
  0.0F,

  /* Variable: igainas
   * Referenced by: '<S4>/igain1'
   */
  1.0E-5F,

  /* Variable: igainb
   * Referenced by: '<S5>/igain'
   */
  0.0F,

  /* Variable: igainbs
   * Referenced by: '<S5>/igain1'
   */
  2.0E-5F,

  /* Variable: pgaina
   * Referenced by: '<S4>/pgain'
   */
  5.0F,

  /* Variable: pgainas
   * Referenced by: '<S4>/pgain1'
   */
  0.002F,

  /* Variable: pgainb
   * Referenced by: '<S5>/pgain'
   */
  8.0F,

  /* Variable: pgainbs
   * Referenced by: '<S5>/pgain1'
   */
  0.003F,

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

  /* Computed Parameter: Saturation_UpperSat
   * Referenced by: '<Root>/Saturation'
   */
  0.7F,

  /* Computed Parameter: Saturation_LowerSat
   * Referenced by: '<Root>/Saturation'
   */
  0.0F,

  /* Computed Parameter: Memory_InitialCondition
   * Referenced by: '<S4>/Memory'
   */
  0.0F,

  /* Computed Parameter: Memory2_InitialCondition
   * Referenced by: '<S4>/Memory2'
   */
  0.0F,

  /* Computed Parameter: dgain2_Gain
   * Referenced by: '<S4>/dgain2'
   */
  500.0F,

  /* Computed Parameter: Memory1_InitialCondition
   * Referenced by: '<S4>/Memory1'
   */
  0.0F,

  /* Computed Parameter: Memory3_InitialCondition
   * Referenced by: '<S4>/Memory3'
   */
  0.0F,

  /* Computed Parameter: dgain3_Gain
   * Referenced by: '<S4>/dgain3'
   */
  500.0F,

  /* Computed Parameter: Memory_InitialCondition_a
   * Referenced by: '<S5>/Memory'
   */
  0.0F,

  /* Computed Parameter: Memory2_InitialCondition_c
   * Referenced by: '<S5>/Memory2'
   */
  0.0F,

  /* Computed Parameter: dgain2_Gain_l
   * Referenced by: '<S5>/dgain2'
   */
  500.0F,

  /* Computed Parameter: Memory1_InitialCondition_d
   * Referenced by: '<S5>/Memory1'
   */
  0.0F,

  /* Computed Parameter: Memory3_InitialCondition_o
   * Referenced by: '<S5>/Memory3'
   */
  0.0F,

  /* Computed Parameter: dgain3_Gain_h
   * Referenced by: '<S5>/dgain3'
   */
  500.0F,

  /* Computed Parameter: Saturation1_UpperSat
   * Referenced by: '<Root>/Saturation1'
   */
  65535.0F,

  /* Computed Parameter: Saturation1_LowerSat
   * Referenced by: '<Root>/Saturation1'
   */
  0.0F,

  /* Computed Parameter: Memory4_InitialCondition
   * Referenced by: '<S4>/Memory4'
   */
  0.0F,

  /* Computed Parameter: Memory5_InitialCondition
   * Referenced by: '<S4>/Memory5'
   */
  0.0F,

  /* Computed Parameter: Memory4_InitialCondition_a
   * Referenced by: '<S5>/Memory4'
   */
  0.0F,

  /* Computed Parameter: Memory5_InitialCondition_p
   * Referenced by: '<S5>/Memory5'
   */
  0.0F
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

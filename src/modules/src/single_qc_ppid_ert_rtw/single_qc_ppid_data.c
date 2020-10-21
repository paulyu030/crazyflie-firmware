/*
 * File: single_qc_ppid_data.c
 *
 * Code generated for Simulink model 'single_qc_ppid'.
 *
 * Model version                  : 1.71
 * Simulink Coder version         : 9.3 (R2020a) 18-Nov-2019
 * C/C++ source code generated on : Sun Oct 18 22:34:34 2020
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
  5.3063F,

  /* Mask Parameter: DiscreteDerivative2_ICPrevScale
   * Referenced by: '<S8>/UD'
   */
  0.0F,

  /* Mask Parameter: DiscreteDerivative1_ICPrevScale
   * Referenced by: '<S7>/UD'
   */
  0.0F,

  /* Mask Parameter: DiscreteDerivative2_ICPrevSca_g
   * Referenced by: '<S10>/UD'
   */
  0.0F,

  /* Mask Parameter: DiscreteDerivative1_ICPrevSca_h
   * Referenced by: '<S9>/UD'
   */
  0.0F,

  /* Computed Parameter: Constant_Value
   * Referenced by: '<S6>/Constant'
   */
  0.0F,

  /* Computed Parameter: Saturation_UpperSat
   * Referenced by: '<Root>/Saturation'
   */
  0.7F,

  /* Computed Parameter: Saturation_LowerSat
   * Referenced by: '<Root>/Saturation'
   */
  0.0F,

  /* Computed Parameter: DiscreteTimeIntegrator2_gainval
   * Referenced by: '<S4>/Discrete-Time Integrator2'
   */
  0.002F,

  /* Computed Parameter: DiscreteTimeIntegrator2_IC
   * Referenced by: '<S4>/Discrete-Time Integrator2'
   */
  0.0F,

  /* Computed Parameter: DiscreteTimeIntegrator2_UpperSa
   * Referenced by: '<S4>/Discrete-Time Integrator2'
   */
  30.0F,

  /* Computed Parameter: DiscreteTimeIntegrator2_LowerSa
   * Referenced by: '<S4>/Discrete-Time Integrator2'
   */
  -30.0F,

  /* Computed Parameter: TSamp_WtEt
   * Referenced by: '<S8>/TSamp'
   */
  500.0F,

  /* Computed Parameter: DiscreteTimeIntegrator1_gainval
   * Referenced by: '<S4>/Discrete-Time Integrator1'
   */
  0.002F,

  /* Computed Parameter: DiscreteTimeIntegrator1_IC
   * Referenced by: '<S4>/Discrete-Time Integrator1'
   */
  0.0F,

  /* Computed Parameter: DiscreteTimeIntegrator1_UpperSa
   * Referenced by: '<S4>/Discrete-Time Integrator1'
   */
  30.0F,

  /* Computed Parameter: DiscreteTimeIntegrator1_LowerSa
   * Referenced by: '<S4>/Discrete-Time Integrator1'
   */
  -30.0F,

  /* Computed Parameter: TSamp_WtEt_k
   * Referenced by: '<S7>/TSamp'
   */
  500.0F,

  /* Computed Parameter: DiscreteTimeIntegrator2_gainv_f
   * Referenced by: '<S5>/Discrete-Time Integrator2'
   */
  0.002F,

  /* Computed Parameter: DiscreteTimeIntegrator2_IC_h
   * Referenced by: '<S5>/Discrete-Time Integrator2'
   */
  0.0F,

  /* Computed Parameter: DiscreteTimeIntegrator2_Upper_l
   * Referenced by: '<S5>/Discrete-Time Integrator2'
   */
  30.0F,

  /* Computed Parameter: DiscreteTimeIntegrator2_Lower_i
   * Referenced by: '<S5>/Discrete-Time Integrator2'
   */
  -30.0F,

  /* Computed Parameter: TSamp_WtEt_i
   * Referenced by: '<S10>/TSamp'
   */
  500.0F,

  /* Computed Parameter: DiscreteTimeIntegrator1_gainv_c
   * Referenced by: '<S5>/Discrete-Time Integrator1'
   */
  0.002F,

  /* Computed Parameter: DiscreteTimeIntegrator1_IC_h
   * Referenced by: '<S5>/Discrete-Time Integrator1'
   */
  0.0F,

  /* Computed Parameter: DiscreteTimeIntegrator1_Upper_e
   * Referenced by: '<S5>/Discrete-Time Integrator1'
   */
  30.0F,

  /* Computed Parameter: DiscreteTimeIntegrator1_Lower_f
   * Referenced by: '<S5>/Discrete-Time Integrator1'
   */
  -30.0F,

  /* Computed Parameter: TSamp_WtEt_b
   * Referenced by: '<S9>/TSamp'
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

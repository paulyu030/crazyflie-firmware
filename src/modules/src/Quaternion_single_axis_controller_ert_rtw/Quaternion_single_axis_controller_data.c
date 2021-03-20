/*
 * File: Quaternion_single_axis_controller_data.c
 *
 * Code generated for Simulink model 'Quaternion_single_axis_controller'.
 *
 * Model version                  : 1.117
 * Simulink Coder version         : 9.3 (R2020a) 18-Nov-2019
 * C/C++ source code generated on : Sat Mar 20 14:47:21 2021
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Quaternion_single_axis_controller.h"
#include "Quaternion_single_axis_controller_private.h"

/* Block parameters (default storage) */
P_Quaternion_single_axis_cont_T Quaternion_single_axis_contro_P = {
  /* Variable: fy_sat
   * Referenced by: '<Root>/Saturation3'
   */
  0.4F,

  /* Variable: pitch_D
   * Referenced by: '<Root>/pitch_rate_D1'
   */
  0.0F,

  /* Variable: pitch_I
   * Referenced by: '<Root>/pitch_rate_I1'
   */
  1.0F,

  /* Variable: pitch_P
   * Referenced by: '<Root>/pitch_rate_P1'
   */
  1000.0F,

  /* Variable: pitch_rate_D
   * Referenced by: '<Root>/pitch_rate_D'
   */
  9.0E-6F,

  /* Variable: pitch_rate_I
   * Referenced by: '<Root>/pitch_rate_I'
   */
  0.0003F,

  /* Variable: pitch_rate_P
   * Referenced by: '<Root>/pitch_rate_P'
   */
  0.00021F,

  /* Variable: theta_cmd_sat
   * Referenced by: '<Root>/Saturation2'
   */
  3.14F,

  /* Mask Parameter: DiscreteDerivative2_ICPrevScale
   * Referenced by: '<S3>/UD'
   */
  0.0F,

  /* Mask Parameter: DiscreteDerivative1_ICPrevScale
   * Referenced by: '<S2>/UD'
   */
  0.0F,

  /* Expression: 65535
   * Referenced by: '<Root>/Saturation'
   */
  65535.0,

  /* Expression: 0
   * Referenced by: '<Root>/Saturation'
   */
  0.0,

  /* Computed Parameter: Constant_Value
   * Referenced by: '<S1>/Constant'
   */
  0.0F,

  /* Computed Parameter: Saturation1_UpperSat
   * Referenced by: '<Root>/Saturation1'
   */
  0.7F,

  /* Computed Parameter: Saturation1_LowerSat
   * Referenced by: '<Root>/Saturation1'
   */
  0.0F,

  /* Computed Parameter: Saturation2_LowerSat
   * Referenced by: '<Root>/Saturation2'
   */
  -3.14F,

  /* Computed Parameter: DiscreteTimeIntegrator2_gainval
   * Referenced by: '<Root>/Discrete-Time Integrator2'
   */
  0.002F,

  /* Computed Parameter: DiscreteTimeIntegrator2_IC
   * Referenced by: '<Root>/Discrete-Time Integrator2'
   */
  0.0F,

  /* Computed Parameter: DiscreteTimeIntegrator2_UpperSa
   * Referenced by: '<Root>/Discrete-Time Integrator2'
   */
  30.0F,

  /* Computed Parameter: DiscreteTimeIntegrator2_LowerSa
   * Referenced by: '<Root>/Discrete-Time Integrator2'
   */
  -30.0F,

  /* Computed Parameter: TSamp_WtEt
   * Referenced by: '<S3>/TSamp'
   */
  500.0F,

  /* Computed Parameter: DiscreteTimeIntegrator1_gainval
   * Referenced by: '<Root>/Discrete-Time Integrator1'
   */
  0.002F,

  /* Computed Parameter: DiscreteTimeIntegrator1_IC
   * Referenced by: '<Root>/Discrete-Time Integrator1'
   */
  0.0F,

  /* Computed Parameter: DiscreteTimeIntegrator1_UpperSa
   * Referenced by: '<Root>/Discrete-Time Integrator1'
   */
  30.0F,

  /* Computed Parameter: DiscreteTimeIntegrator1_LowerSa
   * Referenced by: '<Root>/Discrete-Time Integrator1'
   */
  -30.0F,

  /* Computed Parameter: TSamp_WtEt_f
   * Referenced by: '<S2>/TSamp'
   */
  500.0F,

  /* Computed Parameter: Saturation3_LowerSat
   * Referenced by: '<Root>/Saturation3'
   */
  -0.4F,

  /* Computed Parameter: Saturation_UpperSat_d
   * Referenced by: '<S9>/Saturation'
   */
  20.0F,

  /* Computed Parameter: Saturation_LowerSat_l
   * Referenced by: '<S9>/Saturation'
   */
  0.0F
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Quaternion_single_axis_controller_data.c
 *
 * Code generated for Simulink model 'Quaternion_single_axis_controller'.
 *
 * Model version                  : 1.84
 * Simulink Coder version         : 8.14 (R2018a) 06-Feb-2018
 * C/C++ source code generated on : Wed Jan 22 11:17:24 2020
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
  /* Variable: pitch_P
   * Referenced by: '<Root>/pitch_P'
   */
  1000.0F,

  /* Variable: pitch_rate_D
   * Referenced by: '<Root>/pitch_rate_D'
   */
  0.5F,

  /* Variable: pitch_rate_I
   * Referenced by: '<Root>/pitch_rate_I'
   */
  8.0F,

  /* Variable: pitch_rate_P
   * Referenced by: '<Root>/pitch_rate_P'
   */
  10.0F,

  /* Mask Parameter: DiscreteDerivative1_ICPrevScale
   * Referenced by: '<S1>/UD'
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

  /* Computed Parameter: Saturation2_UpperSat
   * Referenced by: '<Root>/Saturation2'
   */
  1.0F,

  /* Computed Parameter: Saturation2_LowerSat
   * Referenced by: '<Root>/Saturation2'
   */
  -1.0F,

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

  /* Computed Parameter: TSamp_WtEt
   * Referenced by: '<S1>/TSamp'
   */
  500.0F,

  /* Computed Parameter: Gain_Gain
   * Referenced by: '<Root>/Gain'
   */
  0.0001F,

  /* Computed Parameter: Saturation1_UpperSat
   * Referenced by: '<Root>/Saturation1'
   */
  0.7F,

  /* Computed Parameter: Saturation1_LowerSat
   * Referenced by: '<Root>/Saturation1'
   */
  0.0F,

  /* Computed Parameter: Saturation_UpperSat_d
   * Referenced by: '<S6>/Saturation'
   */
  20.0F,

  /* Computed Parameter: Saturation_LowerSat_l
   * Referenced by: '<S6>/Saturation'
   */
  0.0F
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

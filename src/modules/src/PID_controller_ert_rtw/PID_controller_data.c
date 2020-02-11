/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: PID_controller_data.c
 *
 * Code generated for Simulink model 'PID_controller'.
 *
 * Model version                  : 1.6
 * Simulink Coder version         : 8.14 (R2018a) 06-Feb-2018
 * C/C++ source code generated on : Wed Oct 30 09:59:37 2019
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "PID_controller.h"
#include "PID_controller_private.h"

/* Block parameters (default storage) */
P_PID_controller_T PID_controller_P = {
  /* Mask Parameter: DiscreteDerivative2_ICPrevScale
   * Referenced by: '<S3>/UD'
   */
  0.0F,

  /* Mask Parameter: DiscreteDerivative1_ICPrevScale
   * Referenced by: '<S2>/UD'
   */
  0.0F,

  /* Mask Parameter: DiscreteDerivative_ICPrevScaled
   * Referenced by: '<S1>/UD'
   */
  0.0F,

  /* Computed Parameter: roll_P_Gain
   * Referenced by: '<Root>/roll_P'
   */
  6.0F,

  /* Computed Parameter: DiscreteTimeIntegrator5_gainval
   * Referenced by: '<Root>/Discrete-Time Integrator5'
   */
  0.002F,

  /* Computed Parameter: DiscreteTimeIntegrator5_IC
   * Referenced by: '<Root>/Discrete-Time Integrator5'
   */
  0.0F,

  /* Computed Parameter: DiscreteTimeIntegrator5_UpperSa
   * Referenced by: '<Root>/Discrete-Time Integrator5'
   */
  30.0F,

  /* Computed Parameter: DiscreteTimeIntegrator5_LowerSa
   * Referenced by: '<Root>/Discrete-Time Integrator5'
   */
  -30.0F,

  /* Computed Parameter: roll_I_Gain
   * Referenced by: '<Root>/roll_I'
   */
  0.0F,

  /* Computed Parameter: roll_rate_P_Gain
   * Referenced by: '<Root>/roll_rate_P'
   */
  250.0F,

  /* Computed Parameter: DiscreteTimeIntegrator_gainval
   * Referenced by: '<Root>/Discrete-Time Integrator'
   */
  0.002F,

  /* Computed Parameter: DiscreteTimeIntegrator_IC
   * Referenced by: '<Root>/Discrete-Time Integrator'
   */
  0.0F,

  /* Computed Parameter: DiscreteTimeIntegrator_UpperSat
   * Referenced by: '<Root>/Discrete-Time Integrator'
   */
  30.0F,

  /* Computed Parameter: DiscreteTimeIntegrator_LowerSat
   * Referenced by: '<Root>/Discrete-Time Integrator'
   */
  -30.0F,

  /* Computed Parameter: roll_rate_I_Gain
   * Referenced by: '<Root>/roll_rate_I'
   */
  500.0F,

  /* Computed Parameter: TSamp_WtEt
   * Referenced by: '<S3>/TSamp'
   */
  500.0F,

  /* Computed Parameter: roll_rate_D_Gain
   * Referenced by: '<Root>/roll_rate_D'
   */
  2.5F,

  /* Computed Parameter: Saturation_UpperSat
   * Referenced by: '<Root>/Saturation'
   */
  32767.0F,

  /* Computed Parameter: Saturation_LowerSat
   * Referenced by: '<Root>/Saturation'
   */
  -32767.0F,

  /* Computed Parameter: pitch_P_Gain
   * Referenced by: '<Root>/pitch_P'
   */
  6.0F,

  /* Computed Parameter: DiscreteTimeIntegrator4_gainval
   * Referenced by: '<Root>/Discrete-Time Integrator4'
   */
  0.002F,

  /* Computed Parameter: DiscreteTimeIntegrator4_IC
   * Referenced by: '<Root>/Discrete-Time Integrator4'
   */
  0.0F,

  /* Computed Parameter: DiscreteTimeIntegrator4_UpperSa
   * Referenced by: '<Root>/Discrete-Time Integrator4'
   */
  30.0F,

  /* Computed Parameter: DiscreteTimeIntegrator4_LowerSa
   * Referenced by: '<Root>/Discrete-Time Integrator4'
   */
  -30.0F,

  /* Computed Parameter: pitch_I_Gain
   * Referenced by: '<Root>/pitch_I'
   */
  0.0F,

  /* Computed Parameter: pitch_rate_P_Gain
   * Referenced by: '<Root>/pitch_rate_P'
   */
  250.0F,

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

  /* Computed Parameter: pitch_rate_I_Gain
   * Referenced by: '<Root>/pitch_rate_I'
   */
  500.0F,

  /* Computed Parameter: TSamp_WtEt_f
   * Referenced by: '<S2>/TSamp'
   */
  500.0F,

  /* Computed Parameter: pitch_rate_D_Gain
   * Referenced by: '<Root>/pitch_rate_D'
   */
  2.5F,

  /* Computed Parameter: Saturation1_UpperSat
   * Referenced by: '<Root>/Saturation1'
   */
  32767.0F,

  /* Computed Parameter: Saturation1_LowerSat
   * Referenced by: '<Root>/Saturation1'
   */
  -32767.0F,

  /* Computed Parameter: yaw_P_Gain
   * Referenced by: '<Root>/yaw_P'
   */
  6.0F,

  /* Computed Parameter: DiscreteTimeIntegrator3_gainval
   * Referenced by: '<Root>/Discrete-Time Integrator3'
   */
  0.002F,

  /* Computed Parameter: DiscreteTimeIntegrator3_IC
   * Referenced by: '<Root>/Discrete-Time Integrator3'
   */
  0.0F,

  /* Computed Parameter: DiscreteTimeIntegrator3_UpperSa
   * Referenced by: '<Root>/Discrete-Time Integrator3'
   */
  30.0F,

  /* Computed Parameter: DiscreteTimeIntegrator3_LowerSa
   * Referenced by: '<Root>/Discrete-Time Integrator3'
   */
  -30.0F,

  /* Computed Parameter: yaw_I_Gain
   * Referenced by: '<Root>/yaw_I'
   */
  0.0F,

  /* Computed Parameter: yaw_rate_P_Gain
   * Referenced by: '<Root>/yaw_rate_P'
   */
  120.0F,

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

  /* Computed Parameter: yaw_rate_I_Gain
   * Referenced by: '<Root>/yaw_rate_I'
   */
  16.7F,

  /* Computed Parameter: TSamp_WtEt_k
   * Referenced by: '<S1>/TSamp'
   */
  500.0F,

  /* Computed Parameter: yaw_rate_D_Gain
   * Referenced by: '<Root>/yaw_rate_D'
   */
  0.0F,

  /* Computed Parameter: Saturation2_UpperSat
   * Referenced by: '<Root>/Saturation2'
   */
  32767.0F,

  /* Computed Parameter: Saturation2_LowerSat
   * Referenced by: '<Root>/Saturation2'
   */
  -32767.0F
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

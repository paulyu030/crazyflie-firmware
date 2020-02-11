/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: rotor_combined_controller_data.c
 *
 * Code generated for Simulink model 'rotor_combined_controller'.
 *
 * Model version                  : 1.134
 * Simulink Coder version         : 8.14 (R2018a) 06-Feb-2018
 * C/C++ source code generated on : Fri Dec 27 13:51:40 2019
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "rotor_combined_controller.h"
#include "rotor_combined_controller_private.h"

/* Block parameters (default storage) */
P_rotor_combined_controller_T rotor_combined_controller_P = {
  /* Variable: length
   * Referenced by: '<Root>/MATLAB Function'
   */
  0.22,

  /* Variable: K_att
   * Referenced by: '<S1>/K_att'
   */
  50.0F,

  /* Variable: K_att_dot
   * Referenced by: '<S1>/K_att_dot'
   */
  30.0F,

  /* Variable: Kv
   * Referenced by: '<S6>/Kv'
   */
  30.0F,

  /* Variable: Kx
   * Referenced by: '<S6>/Kx'
   */
  20.0F,

  /* Variable: Kxint
   * Referenced by: '<S6>/Kxint'
   */
  1.0F,

  /* Variable: frame_inertia
   * Referenced by: '<S1>/Constant'
   */
  { 0.003717F, 0.0F, 0.0F, 0.0F, 0.003717F, 0.0F, 0.0F, 0.0F, 0.007138F },

  /* Variable: mass
   * Referenced by: '<S6>/Gain1'
   */
  0.174F,

  /* Mask Parameter: Difference1_ICPrevInput
   * Referenced by: '<S2>/UD'
   */
  0.0F,

  /* Computed Parameter: Gain_Gain
   * Referenced by: '<S11>/Gain'
   */
  2.0F,

  /* Computed Parameter: Gain_Gain_a
   * Referenced by: '<S14>/Gain'
   */
  2.0F,

  /* Computed Parameter: Gain_Gain_k
   * Referenced by: '<S9>/Gain'
   */
  2.0F,

  /* Computed Parameter: Gain_Gain_g
   * Referenced by: '<S15>/Gain'
   */
  2.0F,

  /* Computed Parameter: Gain_Gain_p
   * Referenced by: '<S10>/Gain'
   */
  2.0F,

  /* Computed Parameter: Gain_Gain_p4
   * Referenced by: '<S13>/Gain'
   */
  2.0F,

  /* Computed Parameter: DiscreteTimeIntegrator_gainval
   * Referenced by: '<S1>/Discrete-Time Integrator'
   */
  0.01F,

  /* Computed Parameter: DiscreteTimeIntegrator_IC
   * Referenced by: '<S1>/Discrete-Time Integrator'
   */
  0.0F,

  /* Computed Parameter: DiscreteTimeIntegrator_UpperSat
   * Referenced by: '<S1>/Discrete-Time Integrator'
   */
  500.0F,

  /* Computed Parameter: DiscreteTimeIntegrator_LowerSat
   * Referenced by: '<S1>/Discrete-Time Integrator'
   */
  -500.0F,

  /* Computed Parameter: K_att_int_Gain
   * Referenced by: '<S1>/K_att_int'
   */
  0.0F,

  /* Computed Parameter: Constant1_Value
   * Referenced by: '<Root>/Constant1'
   */
  { 0.0F, 0.0F, 0.0F },

  /* Computed Parameter: DiscreteFIRFilter_InitialStates
   * Referenced by: '<Root>/Discrete FIR Filter'
   */
  0.0F,

  /* Computed Parameter: DiscreteFIRFilter_Coefficients
   * Referenced by: '<Root>/Discrete FIR Filter'
   */
  { 0.2F, 0.2F, 0.2F, 0.2F, 0.2F },

  /* Computed Parameter: DiscreteTimeIntegrator_gainva_o
   * Referenced by: '<S6>/Discrete-Time Integrator'
   */
  0.01F,

  /* Computed Parameter: DiscreteTimeIntegrator_IC_k
   * Referenced by: '<S6>/Discrete-Time Integrator'
   */
  0.0F,

  /* Computed Parameter: DiscreteTimeIntegrator_UpperS_j
   * Referenced by: '<S6>/Discrete-Time Integrator'
   */
  10.0F,

  /* Computed Parameter: DiscreteTimeIntegrator_LowerS_h
   * Referenced by: '<S6>/Discrete-Time Integrator'
   */
  -10.0F,

  /* Computed Parameter: Constant6_Value
   * Referenced by: '<Root>/Constant6'
   */
  { 0.0F, 0.0F, 0.0F },

  /* Computed Parameter: Constant_Value
   * Referenced by: '<S6>/Constant'
   */
  { 0.0F, 0.0F, -8.23F },

  /* Computed Parameter: Saturation_UpperSat
   * Referenced by: '<Root>/Saturation'
   */
  2.5F,

  /* Computed Parameter: Saturation_LowerSat
   * Referenced by: '<Root>/Saturation'
   */
  -2.5F,

  /* Computed Parameter: Gain_Gain_ps
   * Referenced by: '<Root>/Gain'
   */
  0.1F
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

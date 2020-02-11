/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Quaternion_controller_data.c
 *
 * Code generated for Simulink model 'Quaternion_controller'.
 *
 * Model version                  : 1.56
 * Simulink Coder version         : 8.14 (R2018a) 06-Feb-2018
 * C/C++ source code generated on : Wed Nov 13 15:33:34 2019
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Quaternion_controller.h"
#include "Quaternion_controller_private.h"

/* Block parameters (default storage) */
P_Quaternion_controller_T Quaternion_controller_P = {
  /* Variable: K_xi
   * Referenced by: '<S1>/K_xi'
   */
  500.0F,

  /* Variable: K_xi_dot
   * Referenced by: '<S1>/K_xi_dot'
   */
  2.0F,

  /* Variable: K_xi_int
   * Referenced by: '<S1>/K_xi_int'
   */
  7.0F,

  /* Variable: inertia
   * Referenced by: '<S10>/momentum of inertia'
   */
  { 1.657E-5F, 8.3E-7F, 7.18E-7F, 8.3E-7F, 1.666E-5F, 1.8E-6F, 7.18E-7F, 1.8E-6F,
    2.926E-5F },

  /* Variable: mass
   * Referenced by:
   *   '<S4>/Gain'
   *   '<S6>/mass'
   */
  0.028F,

  /* Variable: mu_f_gain
   * Referenced by: '<S10>/mu_f_gain'
   */
  0.02F,

  /* Variable: omega_dot_f_gain
   * Referenced by: '<S10>/omega_dot_f_gain'
   */
  10.0F,

  /* Mask Parameter: DirectionCosineMatrixtoQuaterni
   * Referenced by:
   *   '<S19>/Constant'
   *   '<S44>/Constant'
   *   '<S45>/Constant'
   */
  1.0,

  /* Mask Parameter: Difference1_ICPrevInput
   * Referenced by: '<S3>/UD'
   */
  0.0F,

  /* Mask Parameter: Difference_ICPrevInput
   * Referenced by: '<S2>/UD'
   */
  0.0F,

  /* Mask Parameter: DirectionCosineMatrixtoQuater_j
   * Referenced by:
   *   '<S52>/Constant'
   *   '<S54>/Constant'
   */
  4.4408921E-16F,

  /* Expression: 0
   * Referenced by: '<S45>/Constant1'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S44>/Constant1'
   */
  0.0,

  /* Expression: 65535
   * Referenced by: '<Root>/Saturation'
   */
  65535.0,

  /* Expression: 0
   * Referenced by: '<Root>/Saturation'
   */
  0.0,

  /* Computed Parameter: Constant_Value
   * Referenced by: '<S18>/Constant'
   */
  1.0F,

  /* Computed Parameter: Gain_Gain
   * Referenced by: '<S18>/Gain'
   */
  0.5F,

  /* Computed Parameter: Gain1_Gain
   * Referenced by: '<S18>/Gain1'
   */
  2.0F,

  /* Computed Parameter: Constant2_Value
   * Referenced by: '<S33>/Constant2'
   */
  { 0.0F, 1.0F },

  /* Computed Parameter: Constant1_Value_e
   * Referenced by: '<S33>/Constant1'
   */
  0.5F,

  /* Computed Parameter: Constant_Value_d
   * Referenced by: '<S34>/Constant'
   */
  1.0F,

  /* Computed Parameter: Gain1_Gain_i
   * Referenced by: '<S22>/Gain1'
   */
  1.0F,

  /* Computed Parameter: Gain3_Gain
   * Referenced by: '<S22>/Gain3'
   */
  1.0F,

  /* Computed Parameter: Gain4_Gain
   * Referenced by: '<S22>/Gain4'
   */
  1.0F,

  /* Computed Parameter: Gain_Gain_m
   * Referenced by: '<S22>/Gain'
   */
  0.5F,

  /* Computed Parameter: Constant2_Value_i
   * Referenced by: '<S38>/Constant2'
   */
  { 0.0F, 1.0F },

  /* Computed Parameter: Constant1_Value_b
   * Referenced by: '<S38>/Constant1'
   */
  0.5F,

  /* Computed Parameter: Constant_Value_e
   * Referenced by: '<S39>/Constant'
   */
  1.0F,

  /* Computed Parameter: Gain1_Gain_b
   * Referenced by: '<S23>/Gain1'
   */
  1.0F,

  /* Computed Parameter: Gain2_Gain
   * Referenced by: '<S23>/Gain2'
   */
  1.0F,

  /* Computed Parameter: Gain3_Gain_n
   * Referenced by: '<S23>/Gain3'
   */
  1.0F,

  /* Computed Parameter: Gain_Gain_f
   * Referenced by: '<S23>/Gain'
   */
  0.5F,

  /* Computed Parameter: Constant2_Value_m
   * Referenced by: '<S28>/Constant2'
   */
  { 0.0F, 1.0F },

  /* Computed Parameter: Constant1_Value_l
   * Referenced by: '<S28>/Constant1'
   */
  0.5F,

  /* Computed Parameter: Constant_Value_a
   * Referenced by: '<S29>/Constant'
   */
  1.0F,

  /* Computed Parameter: Gain1_Gain_c
   * Referenced by: '<S21>/Gain1'
   */
  1.0F,

  /* Computed Parameter: Gain2_Gain_p
   * Referenced by: '<S21>/Gain2'
   */
  1.0F,

  /* Computed Parameter: Gain3_Gain_o
   * Referenced by: '<S21>/Gain3'
   */
  1.0F,

  /* Computed Parameter: Gain_Gain_d
   * Referenced by: '<S21>/Gain'
   */
  0.5F,

  /* Computed Parameter: Bias1_Bias
   * Referenced by: '<S46>/Bias1'
   */
  { -1.0F, -0.0F, -0.0F, -0.0F, -1.0F, -0.0F, -0.0F, -0.0F, -1.0F },

  /* Computed Parameter: Bias_Bias
   * Referenced by: '<S47>/Bias'
   */
  -1.0F,

  /* Expression: inv([-length/sqrt(2),-length/sqrt(2),length/sqrt(2),length/sqrt(2); length/sqrt(2),-length/sqrt(2),-length/sqrt(2),length/sqrt(2); drag,-drag,drag,-drag; -1,-1,-1,-1])
   * Referenced by: '<S10>/G1'
   */
  { -10.7137403F, -10.7137384F, 10.7137384F, 10.7137403F, 10.7137384F,
    -10.7137384F, -10.7137403F, 10.7137403F, 41.6666679F, -41.6666679F,
    41.6666679F, -41.6666679F, -0.24999997F, -0.25F, -0.25F, -0.25F },

  /* Expression: [-length/sqrt(2),-length/sqrt(2),length/sqrt(2),length/sqrt(2); length/sqrt(2),-length/sqrt(2),-length/sqrt(2),length/sqrt(2); drag,-drag,drag,-drag;]
   * Referenced by: '<S4>/G2'
   */
  { -0.0233345237F, 0.0233345237F, 0.006F, -0.0233345237F, -0.0233345237F,
    -0.006F, 0.0233345237F, -0.0233345237F, 0.006F, 0.0233345237F, 0.0233345237F,
    -0.006F },

  /* Computed Parameter: Constant5_Value
   * Referenced by: '<Root>/Constant5'
   */
  0.001F,

  /* Computed Parameter: Gain2_Gain_i
   * Referenced by: '<S6>/Gain2'
   */
  -1.0F,

  /* Computed Parameter: DiscreteTimeIntegrator_gainval
   * Referenced by: '<S1>/Discrete-Time Integrator'
   */
  1.0F,

  /* Computed Parameter: DiscreteTimeIntegrator_IC
   * Referenced by: '<S1>/Discrete-Time Integrator'
   */
  0.0F,

  /* Computed Parameter: DiscreteTimeIntegrator_UpperSat
   * Referenced by: '<S1>/Discrete-Time Integrator'
   */
  5.0F,

  /* Computed Parameter: DiscreteTimeIntegrator_LowerSat
   * Referenced by: '<S1>/Discrete-Time Integrator'
   */
  -5.0F,

  /* Computed Parameter: Merge_InitialOutput
   * Referenced by: '<S13>/Merge'
   */
  { 1.0F, 0.0F, 0.0F, 0.0F },

  /* Computed Parameter: xi_dot_ref_Value
   * Referenced by: '<Root>/xi_dot_ref'
   */
  { 0.0F, 0.0F, 0.0F },

  /* Computed Parameter: xi_ddot_ref_Value
   * Referenced by: '<Root>/xi_ddot_ref'
   */
  { 0.0F, 0.0F, 0.0F },

  /* Computed Parameter: DiscreteFIRFilter3_InitialState
   * Referenced by: '<S1>/Discrete FIR Filter3'
   */
  0.0F,

  /* Computed Parameter: DiscreteFIRFilter3_Coefficients
   * Referenced by: '<S1>/Discrete FIR Filter3'
   */
  { 0.005F, 0.005F, 0.005F, 0.005F, 0.005F, 0.005F, 0.005F, 0.005F, 0.005F,
    0.005F, 0.005F, 0.005F, 0.005F, 0.005F, 0.005F, 0.005F, 0.005F, 0.005F,
    0.005F, 0.005F, 0.005F, 0.005F, 0.005F, 0.005F, 0.005F, 0.005F, 0.005F,
    0.005F, 0.005F, 0.005F, 0.005F, 0.005F, 0.005F, 0.005F, 0.005F, 0.005F,
    0.005F, 0.005F, 0.005F, 0.005F, 0.005F, 0.005F, 0.005F, 0.005F, 0.005F,
    0.005F, 0.005F, 0.005F, 0.005F, 0.005F, 0.005F, 0.005F, 0.005F, 0.005F,
    0.005F, 0.005F, 0.005F, 0.005F, 0.005F, 0.005F, 0.005F, 0.005F, 0.005F,
    0.005F, 0.005F, 0.005F, 0.005F, 0.005F, 0.005F, 0.005F, 0.005F, 0.005F,
    0.005F, 0.005F, 0.005F, 0.005F, 0.005F, 0.005F, 0.005F, 0.005F, 0.005F,
    0.005F, 0.005F, 0.005F, 0.005F, 0.005F, 0.005F, 0.005F, 0.005F, 0.005F,
    0.005F, 0.005F, 0.005F, 0.005F, 0.005F, 0.005F, 0.005F, 0.005F, 0.005F,
    0.005F, 0.005F, 0.005F, 0.005F, 0.005F, 0.005F, 0.005F, 0.005F, 0.005F,
    0.005F, 0.005F, 0.005F, 0.005F, 0.005F, 0.005F, 0.005F, 0.005F, 0.005F,
    0.005F, 0.005F, 0.005F, 0.005F, 0.005F, 0.005F, 0.005F, 0.005F, 0.005F,
    0.005F, 0.005F, 0.005F, 0.005F, 0.005F, 0.005F, 0.005F, 0.005F, 0.005F,
    0.005F, 0.005F, 0.005F, 0.005F, 0.005F, 0.005F, 0.005F, 0.005F, 0.005F,
    0.005F, 0.005F, 0.005F, 0.005F, 0.005F, 0.005F, 0.005F, 0.005F, 0.005F,
    0.005F, 0.005F, 0.005F, 0.005F, 0.005F, 0.005F, 0.005F, 0.005F, 0.005F,
    0.005F, 0.005F, 0.005F, 0.005F, 0.005F, 0.005F, 0.005F, 0.005F, 0.005F,
    0.005F, 0.005F, 0.005F, 0.005F, 0.005F, 0.005F, 0.005F, 0.005F, 0.005F,
    0.005F, 0.005F, 0.005F, 0.005F, 0.005F, 0.005F, 0.005F, 0.005F, 0.005F,
    0.005F, 0.005F, 0.005F, 0.005F, 0.005F, 0.005F, 0.005F, 0.005F, 0.005F,
    0.005F, 0.005F },

  /* Computed Parameter: DiscreteFIRFilter_InitialStates
   * Referenced by: '<Root>/Discrete FIR Filter'
   */
  0.0F,

  /* Computed Parameter: DiscreteFIRFilter_Coefficients
   * Referenced by: '<Root>/Discrete FIR Filter'
   */
  { 0.2F, 0.2F, 0.2F, 0.2F, 0.2F },

  /* Computed Parameter: Constant_Value_l
   * Referenced by: '<Root>/Constant'
   */
  -0.0028F,

  /* Computed Parameter: Gain1_Gain_m
   * Referenced by: '<S6>/Gain1'
   */
  -1.0F,

  /* Computed Parameter: DiscreteTransferFcn1_NumCoef
   * Referenced by: '<S4>/Discrete Transfer Fcn1'
   */
  { 7.2345E-8F, 0.0F },

  /* Computed Parameter: DiscreteTransferFcn1_DenCoef
   * Referenced by: '<S4>/Discrete Transfer Fcn1'
   */
  { 1.0F, -0.9695F },

  /* Computed Parameter: DiscreteTransferFcn1_InitialSta
   * Referenced by: '<S4>/Discrete Transfer Fcn1'
   */
  0.0F,

  /* Computed Parameter: DiscreteFIRFilter1_InitialState
   * Referenced by: '<Root>/Discrete FIR Filter1'
   */
  0.0F,

  /* Computed Parameter: DiscreteFIRFilter1_Coefficients
   * Referenced by: '<Root>/Discrete FIR Filter1'
   */
  { 0.2F, 0.2F, 0.2F, 0.2F, 0.2F },

  /* Computed Parameter: Saturation_UpperSat_e
   * Referenced by: '<S10>/Saturation'
   */
  10.0F,

  /* Computed Parameter: Saturation_LowerSat_h
   * Referenced by: '<S10>/Saturation'
   */
  0.0F,

  /* Computed Parameter: G1_Value_c
   * Referenced by: '<S4>/G1'
   */
  { -1.0F, -1.0F, -1.0F, -1.0F },

  /* Computed Parameter: Gain2_Gain_h
   * Referenced by: '<S4>/Gain2'
   */
  -1.0F,

  /* Computed Parameter: DiscreteFIRFilter2_InitialState
   * Referenced by: '<Root>/Discrete FIR Filter2'
   */
  0.0F,

  /* Computed Parameter: DiscreteFIRFilter2_Coefficients
   * Referenced by: '<Root>/Discrete FIR Filter2'
   */
  { 0.05F, 0.05F, 0.05F, 0.05F, 0.05F, 0.05F, 0.05F, 0.05F, 0.05F, 0.05F, 0.05F,
    0.05F, 0.05F, 0.05F, 0.05F, 0.05F, 0.05F, 0.05F, 0.05F, 0.05F },

  /* Computed Parameter: Gain_Gain_p
   * Referenced by: '<S58>/Gain'
   */
  2.0F,

  /* Computed Parameter: Gain_Gain_e
   * Referenced by: '<S61>/Gain'
   */
  2.0F,

  /* Computed Parameter: Gain_Gain_i
   * Referenced by: '<S56>/Gain'
   */
  2.0F,

  /* Computed Parameter: Gain_Gain_fs
   * Referenced by: '<S62>/Gain'
   */
  2.0F,

  /* Computed Parameter: Gain_Gain_k
   * Referenced by: '<S57>/Gain'
   */
  2.0F,

  /* Computed Parameter: Gain_Gain_i1
   * Referenced by: '<S60>/Gain'
   */
  2.0F,

  /* Computed Parameter: j_ref_Value
   * Referenced by: '<Root>/j_ref'
   */
  { 0.0F, 0.0F, 0.0F },

  /* Computed Parameter: s_ref_Value
   * Referenced by: '<Root>/s_ref'
   */
  { 0.0F, 0.0F, 0.0F },

  /* Computed Parameter: psi_ddot_ref_Value
   * Referenced by: '<Root>/psi_ddot_ref'
   */
  0.0F,

  /* Computed Parameter: psi_dot_ref_Value
   * Referenced by: '<Root>/psi_dot_ref'
   */
  0.0F,

  /* Computed Parameter: Memory_InitialCondition
   * Referenced by: '<Root>/Memory'
   */
  10000U
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

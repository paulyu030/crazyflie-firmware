/*
 * File: single_qc_real.c
 *
 * Code generated for Simulink model 'single_qc_real'.
 *
 * Model version                  : 1.25
 * Simulink Coder version         : 9.3 (R2020a) 18-Nov-2019
 * C/C++ source code generated on : Wed Apr 15 17:16:14 2020
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objective: Execution efficiency
 * Validation result: Not run
 */

#include "single_qc_real.h"
#include "single_qc_real_private.h"

/* Block states (default storage) */
DW_single_qc_real_T single_qc_real_DW;

/* External inputs (root inport signals with default storage) */
ExtU_single_qc_real_T single_qc_real_U;

/* External outputs (root outports fed by signals with default storage) */
ExtY_single_qc_real_T single_qc_real_Y;

/* Forward declaration for local functions */
static void single_qc_real_quatmultiply(const real_T q[4], const real_T r[4],
  real_T qout[4]);

/* Function for MATLAB Function: '<Root>/MATLAB Function' */
static void single_qc_real_quatmultiply(const real_T q[4], const real_T r[4],
  real_T qout[4])
{
  qout[0] = ((q[0] * r[0] - q[1] * r[1]) - q[2] * r[2]) - q[3] * r[3];
  qout[1] = (q[0] * r[1] + r[0] * q[1]) + (q[2] * r[3] - q[3] * r[2]);
  qout[2] = (q[0] * r[2] + r[0] * q[2]) + (q[3] * r[1] - q[1] * r[3]);
  qout[3] = (q[0] * r[3] + r[0] * q[3]) + (q[1] * r[2] - q[2] * r[1]);
}

/* Model step function */
void single_qc_real_step(void)
{
  real_T q_bi[4];
  real_T q_bii[4];
  real_T R_bii[9];
  real_T tempR[9];
  int32_T d_k;
  real_T thrust;
  real_T ftx;
  real_T fty;
  real_T ftz;
  real_T rtb_Sum_f;
  real_T rtb_Sum1;
  real_T rtb_Sum;
  real_T rtb_Saturation;
  real_T rtb_beta_e;
  real_T rtb_Tsamp;
  real_T rtb_Sum_b;
  real_T rtb_Tsamp_c;
  real_T tmp[4];
  real_T q_bi_0[4];
  int8_T subsa_idx_1;
  real_T tmp_0;
  real_T u0;
  real_T q_bi_1;
  int32_T R_bii_tmp;
  real_T q_bi_tmp;
  real_T q_bi_tmp_tmp;
  static const real_T c[4] = { 0.70710678118654757, 0.0, 0.0,
    0.70710678118654746 };

  static const real_T d[4] = { -0.70710678118654757, 0.0, 0.0,
    0.70710678118654746 };

  /* Gain: '<Root>/Gain' incorporates:
   *  Inport: '<Root>/thrust'
   */
  rtb_Saturation = single_qc_real_P.Gain_Gain * single_qc_real_U.thrust;

  /* Saturate: '<Root>/Saturation' */
  if (rtb_Saturation > single_qc_real_P.Saturation_UpperSat) {
    rtb_Saturation = single_qc_real_P.Saturation_UpperSat;
  } else {
    if (rtb_Saturation < single_qc_real_P.Saturation_LowerSat) {
      rtb_Saturation = single_qc_real_P.Saturation_LowerSat;
    }
  }

  /* End of Saturate: '<Root>/Saturation' */

  /* MATLAB Function: '<Root>/MATLAB Function' incorporates:
   *  Inport: '<Root>/index'
   *  Inport: '<Root>/qw_IMU'
   *  Inport: '<Root>/qw_op'
   *  Inport: '<Root>/qx_IMU'
   *  Inport: '<Root>/qx_op'
   *  Inport: '<Root>/qy_IMU'
   *  Inport: '<Root>/qy_op'
   *  Inport: '<Root>/qz_IMU'
   *  Inport: '<Root>/qz_op'
   */
  u0 = single_qc_real_U.index * 3.1415926535897931 / 4.0;
  tmp[0] = cos(u0);
  tmp[1] = 0.0;
  tmp[2] = 0.0;
  tmp[3] = sin(u0);
  q_bi_0[0] = single_qc_real_U.qw_op;
  q_bi_0[1] = single_qc_real_U.qx_op;
  q_bi_0[2] = single_qc_real_U.qy_op;
  q_bi_0[3] = single_qc_real_U.qz_op;
  single_qc_real_quatmultiply(tmp, q_bi_0, q_bi);
  tmp[0] = single_qc_real_U.qw_IMU;
  tmp[1] = single_qc_real_U.qx_IMU;
  tmp[2] = single_qc_real_U.qy_IMU;
  tmp[3] = single_qc_real_U.qz_IMU;
  q_bi_0[0] = -q_bi[0];
  q_bi_0[1] = q_bi[1];
  q_bi_0[2] = q_bi[2];
  q_bi_0[3] = q_bi[3];
  single_qc_real_quatmultiply(tmp, d, q_bi);
  single_qc_real_quatmultiply(c, q_bi, tmp);
  single_qc_real_quatmultiply(tmp, q_bi_0, q_bii);
  rtb_beta_e = 1.0 / sqrt(((q_bii[0] * q_bii[0] + q_bii[1] * q_bii[1]) + q_bii[2]
    * q_bii[2]) + q_bii[3] * q_bii[3]);
  q_bi[0] = q_bii[0] * rtb_beta_e;
  q_bi[1] = q_bii[1] * rtb_beta_e;
  q_bi[2] = q_bii[2] * rtb_beta_e;
  q_bi[3] = q_bii[3] * rtb_beta_e;
  rtb_beta_e = q_bi[3] * q_bi[3];
  rtb_Sum = q_bi[2] * q_bi[2];
  tempR[0] = 1.0 - (rtb_Sum + rtb_beta_e) * 2.0;
  rtb_Tsamp = q_bi[1] * q_bi[2];
  rtb_Sum_f = q_bi[0] * q_bi[3];
  tempR[1] = (rtb_Tsamp - rtb_Sum_f) * 2.0;
  rtb_Sum1 = q_bi[1] * q_bi[3];
  rtb_Tsamp_c = q_bi[0] * q_bi[2];
  tempR[2] = (rtb_Sum1 + rtb_Tsamp_c) * 2.0;
  tempR[3] = (rtb_Tsamp + rtb_Sum_f) * 2.0;
  rtb_Tsamp = q_bi[1] * q_bi[1];
  tempR[4] = 1.0 - (rtb_Tsamp + rtb_beta_e) * 2.0;
  rtb_beta_e = q_bi[2] * q_bi[3];
  rtb_Sum_f = q_bi[0] * q_bi[1];
  tempR[5] = (rtb_beta_e - rtb_Sum_f) * 2.0;
  tempR[6] = (rtb_Sum1 - rtb_Tsamp_c) * 2.0;
  tempR[7] = (rtb_beta_e + rtb_Sum_f) * 2.0;
  tempR[8] = 1.0 - (rtb_Tsamp + rtb_Sum) * 2.0;
  for (d_k = 0; d_k < 3; d_k++) {
    R_bii_tmp = (int8_T)(d_k + 1) - 1;
    R_bii[R_bii_tmp] = tempR[R_bii_tmp * 3];
    subsa_idx_1 = (int8_T)(d_k + 1);
    R_bii[subsa_idx_1 + 2] = tempR[(subsa_idx_1 - 1) * 3 + 1];
    subsa_idx_1 = (int8_T)(d_k + 1);
    R_bii[subsa_idx_1 + 5] = tempR[(subsa_idx_1 - 1) * 3 + 2];
  }

  rtb_beta_e = atan2(R_bii[6], R_bii[0]);

  /* Sum: '<S3>/Sum' incorporates:
   *  Inport: '<Root>/alpha_desired'
   *  MATLAB Function: '<Root>/MATLAB Function'
   */
  rtb_Sum = single_qc_real_U.alpha_desired - atan2(-R_bii[7], R_bii[8]);

  /* SampleTimeMath: '<S34>/Tsamp' incorporates:
   *  Gain: '<S31>/Derivative Gain'
   *
   * About '<S34>/Tsamp':
   *  y = u * K where K = 1 / ( w * Ts )
   */
  rtb_Tsamp = single_qc_real_P.dgaina * rtb_Sum * single_qc_real_P.Tsamp_WtEt;

  /* Sum: '<S48>/Sum' incorporates:
   *  Delay: '<S32>/UD'
   *  DiscreteIntegrator: '<S39>/Integrator'
   *  Gain: '<S44>/Proportional Gain'
   *  Sum: '<S32>/Diff'
   */
  rtb_Sum_f = (single_qc_real_P.pgaina * rtb_Sum +
               single_qc_real_DW.Integrator_DSTATE) + (rtb_Tsamp -
    single_qc_real_DW.UD_DSTATE);

  /* Sum: '<S3>/Sum1' incorporates:
   *  Inport: '<Root>/beta_desired'
   */
  rtb_Sum1 = single_qc_real_U.beta_desired - rtb_beta_e;

  /* SampleTimeMath: '<S84>/Tsamp' incorporates:
   *  Gain: '<S81>/Derivative Gain'
   *
   * About '<S84>/Tsamp':
   *  y = u * K where K = 1 / ( w * Ts )
   */
  rtb_Tsamp_c = single_qc_real_P.dgainb * rtb_Sum1 *
    single_qc_real_P.Tsamp_WtEt_c;

  /* Sum: '<S98>/Sum' incorporates:
   *  Delay: '<S82>/UD'
   *  DiscreteIntegrator: '<S89>/Integrator'
   *  Gain: '<S94>/Proportional Gain'
   *  Sum: '<S82>/Diff'
   */
  rtb_Sum_b = (single_qc_real_P.pgainb * rtb_Sum1 +
               single_qc_real_DW.Integrator_DSTATE_e) + (rtb_Tsamp_c -
    single_qc_real_DW.UD_DSTATE_e);

  /* MATLAB Function: '<Root>/MATLAB Function1' */
  thrust = rtb_Saturation / 4.0;

  /* Product: '<S3>/Product' incorporates:
   *  Trigonometry: '<S3>/Trigonometric Function1'
   */
  u0 = cos(rtb_beta_e) * rtb_Sum_f;

  /* Saturate: '<S3>/Saturation' */
  if (u0 > single_qc_real_P.Saturation_UpperSat_b) {
    u0 = single_qc_real_P.Saturation_UpperSat_b;
  } else {
    if (u0 < single_qc_real_P.Saturation_LowerSat_p) {
      u0 = single_qc_real_P.Saturation_LowerSat_p;
    }
  }

  /* End of Saturate: '<S3>/Saturation' */

  /* MATLAB Function: '<Root>/MATLAB Function1' */
  ftx = u0 / 4.0 / 0.03165;

  /* Saturate: '<S3>/Saturation1' */
  if (rtb_Sum_b > single_qc_real_P.Saturation1_UpperSat) {
    u0 = single_qc_real_P.Saturation1_UpperSat;
  } else if (rtb_Sum_b < single_qc_real_P.Saturation1_LowerSat) {
    u0 = single_qc_real_P.Saturation1_LowerSat;
  } else {
    u0 = rtb_Sum_b;
  }

  /* End of Saturate: '<S3>/Saturation1' */

  /* MATLAB Function: '<Root>/MATLAB Function1' */
  fty = u0 / 4.0 / 0.03165;

  /* Product: '<S3>/Product1' incorporates:
   *  Trigonometry: '<S3>/Trigonometric Function'
   */
  u0 = rtb_Sum_f * sin(rtb_beta_e);

  /* Saturate: '<S3>/Saturation2' */
  if (u0 > single_qc_real_P.Saturation2_UpperSat) {
    u0 = single_qc_real_P.Saturation2_UpperSat;
  } else {
    if (u0 < single_qc_real_P.Saturation2_LowerSat) {
      u0 = single_qc_real_P.Saturation2_LowerSat;
    }
  }

  /* End of Saturate: '<S3>/Saturation2' */

  /* MATLAB Function: '<Root>/MATLAB Function1' incorporates:
   *  Constant: '<Root>/Constant'
   */
  ftz = u0 / 4.0 / 0.03165 * single_qc_real_P.torque_modifier;
  q_bi_tmp_tmp = thrust + ftx;
  q_bi_tmp = ((q_bi_tmp_tmp - fty) - ftz) / 0.1472 * 65535.0;

  /* Saturate: '<Root>/Saturation1' incorporates:
   *  MATLAB Function: '<Root>/MATLAB Function1'
   */
  if (q_bi_tmp > single_qc_real_P.Saturation1_UpperSat_m) {
    q_bi_1 = single_qc_real_P.Saturation1_UpperSat_m;
  } else if (q_bi_tmp < single_qc_real_P.Saturation1_LowerSat_e) {
    q_bi_1 = single_qc_real_P.Saturation1_LowerSat_e;
  } else {
    q_bi_1 = q_bi_tmp;
  }

  /* DataTypeConversion: '<Root>/Data Type Conversion2' */
  u0 = fmod(floor(q_bi_1), 65536.0);

  /* Outport: '<Root>/t_motorcom' */
  single_qc_real_Y.t_motorcom[0] = q_bi_tmp;

  /* MATLAB Function: '<Root>/MATLAB Function1' */
  q_bi_tmp = ((q_bi_tmp_tmp + fty) + ftz) / 0.1472 * 65535.0;

  /* Saturate: '<Root>/Saturation1' incorporates:
   *  MATLAB Function: '<Root>/MATLAB Function1'
   */
  if (q_bi_tmp > single_qc_real_P.Saturation1_UpperSat_m) {
    q_bi_1 = single_qc_real_P.Saturation1_UpperSat_m;
  } else if (q_bi_tmp < single_qc_real_P.Saturation1_LowerSat_e) {
    q_bi_1 = single_qc_real_P.Saturation1_LowerSat_e;
  } else {
    q_bi_1 = q_bi_tmp;
  }

  /* DataTypeConversion: '<Root>/Data Type Conversion2' */
  tmp_0 = fmod(floor(q_bi_1), 65536.0);

  /* Outport: '<Root>/t_motorcom' */
  single_qc_real_Y.t_motorcom[1] = q_bi_tmp;

  /* MATLAB Function: '<Root>/MATLAB Function1' */
  q_bi_tmp_tmp = thrust - ftx;
  q_bi_tmp = ((q_bi_tmp_tmp + fty) - ftz) / 0.1472 * 65535.0;

  /* Saturate: '<Root>/Saturation1' incorporates:
   *  MATLAB Function: '<Root>/MATLAB Function1'
   */
  if (q_bi_tmp > single_qc_real_P.Saturation1_UpperSat_m) {
    q_bi_1 = single_qc_real_P.Saturation1_UpperSat_m;
  } else if (q_bi_tmp < single_qc_real_P.Saturation1_LowerSat_e) {
    q_bi_1 = single_qc_real_P.Saturation1_LowerSat_e;
  } else {
    q_bi_1 = q_bi_tmp;
  }

  /* DataTypeConversion: '<Root>/Data Type Conversion2' */
  thrust = fmod(floor(q_bi_1), 65536.0);

  /* Outport: '<Root>/t_motorcom' */
  single_qc_real_Y.t_motorcom[2] = q_bi_tmp;

  /* MATLAB Function: '<Root>/MATLAB Function1' */
  q_bi_tmp = ((q_bi_tmp_tmp - fty) + ftz) / 0.1472 * 65535.0;

  /* Saturate: '<Root>/Saturation1' incorporates:
   *  MATLAB Function: '<Root>/MATLAB Function1'
   */
  if (q_bi_tmp > single_qc_real_P.Saturation1_UpperSat_m) {
    q_bi_1 = single_qc_real_P.Saturation1_UpperSat_m;
  } else if (q_bi_tmp < single_qc_real_P.Saturation1_LowerSat_e) {
    q_bi_1 = single_qc_real_P.Saturation1_LowerSat_e;
  } else {
    q_bi_1 = q_bi_tmp;
  }

  /* DataTypeConversion: '<Root>/Data Type Conversion2' */
  ftx = fmod(floor(q_bi_1), 65536.0);

  /* Outport: '<Root>/t_motorcom' */
  single_qc_real_Y.t_motorcom[3] = q_bi_tmp;

  /* Outport: '<Root>/m1' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion2'
   */
  single_qc_real_Y.m1 = (uint16_T)(u0 < 0.0 ? (int32_T)(uint16_T)-(int16_T)
    (uint16_T)-u0 : (int32_T)(uint16_T)u0);

  /* Outport: '<Root>/m2' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion2'
   */
  single_qc_real_Y.m2 = (uint16_T)(tmp_0 < 0.0 ? (int32_T)(uint16_T)-(int16_T)
    (uint16_T)-tmp_0 : (int32_T)(uint16_T)tmp_0);

  /* Outport: '<Root>/m3' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion2'
   */
  single_qc_real_Y.m3 = (uint16_T)(thrust < 0.0 ? (int32_T)(uint16_T)-(int16_T)
    (uint16_T)-thrust : (int32_T)(uint16_T)thrust);

  /* Outport: '<Root>/m4' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion2'
   */
  single_qc_real_Y.m4 = (uint16_T)(ftx < 0.0 ? (int32_T)(uint16_T)-(int16_T)
    (uint16_T)-ftx : (int32_T)(uint16_T)ftx);

  /* Outport: '<Root>/u_beta' */
  single_qc_real_Y.u_beta = rtb_Sum_b;

  /* Outport: '<Root>/error_beta' */
  single_qc_real_Y.error_beta = rtb_Sum1;

  /* Outport: '<Root>/u_alpha' */
  single_qc_real_Y.u_alpha = rtb_Sum_f;

  /* Outport: '<Root>/error_alpha' */
  single_qc_real_Y.error_alpha = rtb_Sum;

  /* Outport: '<Root>/t_betae' */
  single_qc_real_Y.t_betae = rtb_beta_e;

  /* Outport: '<Root>/t_thrustin' */
  single_qc_real_Y.t_thrustin = rtb_Saturation;

  /* Outport: '<Root>/t_pgaina' incorporates:
   *  Constant: '<Root>/Constant1'
   */
  single_qc_real_Y.t_pgaina = single_qc_real_P.pgaina;

  /* Outport: '<Root>/t_dgaina' incorporates:
   *  Constant: '<Root>/Constant2'
   */
  single_qc_real_Y.t_dgaina = single_qc_real_P.dgaina;

  /* Outport: '<Root>/t_betain' incorporates:
   *  Inport: '<Root>/beta_desired'
   */
  single_qc_real_Y.t_betain = single_qc_real_U.beta_desired;

  /* Update for DiscreteIntegrator: '<S39>/Integrator' incorporates:
   *  Gain: '<S36>/Integral Gain'
   */
  single_qc_real_DW.Integrator_DSTATE += single_qc_real_P.igaina * rtb_Sum *
    single_qc_real_P.Integrator_gainval;

  /* Update for Delay: '<S32>/UD' */
  single_qc_real_DW.UD_DSTATE = rtb_Tsamp;

  /* Update for DiscreteIntegrator: '<S89>/Integrator' incorporates:
   *  Gain: '<S86>/Integral Gain'
   */
  single_qc_real_DW.Integrator_DSTATE_e += single_qc_real_P.igainb * rtb_Sum1 *
    single_qc_real_P.Integrator_gainval_i;

  /* Update for Delay: '<S82>/UD' */
  single_qc_real_DW.UD_DSTATE_e = rtb_Tsamp_c;
}

/* Model initialize function */
void single_qc_real_initialize(void)
{
  /* Registration code */

  /* states (dwork) */
  (void) memset((void *)&single_qc_real_DW, 0,
                sizeof(DW_single_qc_real_T));

  /* external inputs */
  (void)memset(&single_qc_real_U, 0, sizeof(ExtU_single_qc_real_T));

  /* external outputs */
  (void) memset((void *)&single_qc_real_Y, 0,
                sizeof(ExtY_single_qc_real_T));

  /* InitializeConditions for DiscreteIntegrator: '<S39>/Integrator' */
  single_qc_real_DW.Integrator_DSTATE =
    single_qc_real_P.DiscretePIDController_InitialCo;

  /* InitializeConditions for Delay: '<S32>/UD' */
  single_qc_real_DW.UD_DSTATE = single_qc_real_P.DiscretePIDController_Different;

  /* InitializeConditions for DiscreteIntegrator: '<S89>/Integrator' */
  single_qc_real_DW.Integrator_DSTATE_e =
    single_qc_real_P.DiscretePIDController1_InitialC;

  /* InitializeConditions for Delay: '<S82>/UD' */
  single_qc_real_DW.UD_DSTATE_e =
    single_qc_real_P.DiscretePIDController1_Differen;
}

/* Model terminate function */
void single_qc_real_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

/*
 * File: single_qc_ppid.c
 *
 * Code generated for Simulink model 'single_qc_ppid'.
 *
 * Model version                  : 1.50
 * Simulink Coder version         : 9.3 (R2020a) 18-Nov-2019
 * C/C++ source code generated on : Tue Aug  4 04:04:37 2020
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objective: Execution efficiency
 * Validation result: Not run
 */

#include "single_qc_ppid.h"
#include "single_qc_ppid_private.h"

/* Block states (default storage) */
DW_single_qc_ppid_T single_qc_ppid_DW;

/* External inputs (root inport signals with default storage) */
ExtU_single_qc_ppid_T single_qc_ppid_U;

/* External outputs (root outports fed by signals with default storage) */
ExtY_single_qc_ppid_T single_qc_ppid_Y;

/* Forward declaration for local functions */
static void single_qc_ppid_quatmultiply(const real32_T q[4], const real32_T r[4],
  real32_T qout[4]);

/* Function for MATLAB Function: '<Root>/MATLAB Function' */
static void single_qc_ppid_quatmultiply(const real32_T q[4], const real32_T r[4],
  real32_T qout[4])
{
  qout[0] = ((q[0] * r[0] - q[1] * r[1]) - q[2] * r[2]) - q[3] * r[3];
  qout[1] = (q[0] * r[1] + r[0] * q[1]) + (q[2] * r[3] - q[3] * r[2]);
  qout[2] = (q[0] * r[2] + r[0] * q[2]) + (q[3] * r[1] - q[1] * r[3]);
  qout[3] = (q[0] * r[3] + r[0] * q[3]) + (q[1] * r[2] - q[2] * r[1]);
}

/* Model step function */
void single_qc_ppid_step(void)
{
  real32_T q_bi[4];
  real32_T q_bii[4];
  real32_T R_bii[9];
  real32_T tempR[9];
  int32_T d_k;
  real32_T thrust;
  real32_T ftx;
  real32_T fty;
  real32_T ftz;
  real32_T rtb_Sum1_d;
  real32_T rtb_beta_e;
  real32_T rtb_alpha_e;
  real32_T rtb_Sum;
  real32_T rtb_TSamp;
  real32_T rtb_Sum3;
  real32_T rtb_TSamp_l;
  real32_T rtb_Sum1;
  real32_T rtb_TSamp_e;
  real32_T rtb_Sum3_b;
  real32_T rtb_TSamp_pg;
  real32_T rtb_Sum1_p;
  real32_T tmp[4];
  real32_T q_bi_0[4];
  int8_T subsa_idx_1;
  int32_T R_bii_tmp;
  real32_T q_bi_tmp;
  static const real32_T b[4] = { 0.707106769F, 0.0F, 0.0F, 0.707106769F };

  static const real32_T c[4] = { -0.707106769F, 0.0F, 0.0F, 0.707106769F };

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
  thrust = single_qc_ppid_U.index * 3.14159274F / 4.0F;
  tmp[0] = cosf(thrust);
  tmp[1] = 0.0F;
  tmp[2] = 0.0F;
  tmp[3] = sinf(thrust);
  q_bi_0[0] = single_qc_ppid_U.qw_op;
  q_bi_0[1] = single_qc_ppid_U.qx_op;
  q_bi_0[2] = single_qc_ppid_U.qy_op;
  q_bi_0[3] = single_qc_ppid_U.qz_op;
  single_qc_ppid_quatmultiply(tmp, q_bi_0, q_bi);
  tmp[0] = single_qc_ppid_U.qw_IMU;
  tmp[1] = single_qc_ppid_U.qx_IMU;
  tmp[2] = single_qc_ppid_U.qy_IMU;
  tmp[3] = single_qc_ppid_U.qz_IMU;
  q_bi_0[0] = -q_bi[0];
  q_bi_0[1] = q_bi[1];
  q_bi_0[2] = q_bi[2];
  q_bi_0[3] = q_bi[3];
  single_qc_ppid_quatmultiply(tmp, c, q_bi);
  single_qc_ppid_quatmultiply(b, q_bi, tmp);
  single_qc_ppid_quatmultiply(tmp, q_bi_0, q_bii);
  rtb_alpha_e = 1.0F / sqrtf(((q_bii[0] * q_bii[0] + q_bii[1] * q_bii[1]) +
    q_bii[2] * q_bii[2]) + q_bii[3] * q_bii[3]);
  q_bi[0] = q_bii[0] * rtb_alpha_e;
  q_bi[1] = q_bii[1] * rtb_alpha_e;
  q_bi[2] = q_bii[2] * rtb_alpha_e;
  q_bi[3] = q_bii[3] * rtb_alpha_e;
  rtb_alpha_e = q_bi[3] * q_bi[3];
  rtb_beta_e = q_bi[2] * q_bi[2];
  tempR[0] = 1.0F - (rtb_beta_e + rtb_alpha_e) * 2.0F;
  rtb_Sum = q_bi[1] * q_bi[2];
  rtb_TSamp = q_bi[0] * q_bi[3];
  tempR[1] = (rtb_Sum - rtb_TSamp) * 2.0F;
  rtb_Sum3 = q_bi[1] * q_bi[3];
  rtb_TSamp_l = q_bi[0] * q_bi[2];
  tempR[2] = (rtb_Sum3 + rtb_TSamp_l) * 2.0F;
  tempR[3] = (rtb_Sum + rtb_TSamp) * 2.0F;
  rtb_Sum = q_bi[1] * q_bi[1];
  tempR[4] = 1.0F - (rtb_Sum + rtb_alpha_e) * 2.0F;
  rtb_alpha_e = q_bi[2] * q_bi[3];
  rtb_TSamp = q_bi[0] * q_bi[1];
  tempR[5] = (rtb_alpha_e - rtb_TSamp) * 2.0F;
  tempR[6] = (rtb_Sum3 - rtb_TSamp_l) * 2.0F;
  tempR[7] = (rtb_alpha_e + rtb_TSamp) * 2.0F;
  tempR[8] = 1.0F - (rtb_Sum + rtb_beta_e) * 2.0F;
  for (d_k = 0; d_k < 3; d_k++) {
    R_bii_tmp = (int8_T)(d_k + 1) - 1;
    R_bii[R_bii_tmp] = tempR[R_bii_tmp * 3];
    subsa_idx_1 = (int8_T)(d_k + 1);
    R_bii[subsa_idx_1 + 2] = tempR[(subsa_idx_1 - 1) * 3 + 1];
    subsa_idx_1 = (int8_T)(d_k + 1);
    R_bii[subsa_idx_1 + 5] = tempR[(subsa_idx_1 - 1) * 3 + 2];
  }

  rtb_alpha_e = atan2f(-R_bii[7], R_bii[8]);
  rtb_beta_e = atan2f(R_bii[6], R_bii[0]);

  /* End of MATLAB Function: '<Root>/MATLAB Function' */

  /* Sum: '<S3>/Sum' incorporates:
   *  Inport: '<Root>/alpha_desired'
   */
  rtb_Sum = single_qc_ppid_U.alpha_desired - rtb_alpha_e;

  /* SampleTimeMath: '<S7>/TSamp'
   *
   * About '<S7>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   */
  rtb_TSamp = rtb_Sum * single_qc_ppid_P.TSamp_WtEt;

  /* Sum: '<S4>/Sum3' incorporates:
   *  DiscreteIntegrator: '<S4>/Discrete-Time Integrator'
   *  Gain: '<S4>/dgain'
   *  Gain: '<S4>/igain'
   *  Gain: '<S4>/pgain'
   *  Inport: '<Root>/alpha_speed'
   *  Sum: '<S4>/Sum2'
   *  Sum: '<S7>/Diff'
   *  UnitDelay: '<S7>/UD'
   *
   * Block description for '<S7>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S7>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Sum3 = ((single_qc_ppid_P.pgaina * rtb_Sum + single_qc_ppid_P.igaina *
               single_qc_ppid_DW.DiscreteTimeIntegrator_DSTATE) + (rtb_TSamp -
    single_qc_ppid_DW.UD_DSTATE) * single_qc_ppid_P.dgaina) -
    single_qc_ppid_U.alpha_speed;

  /* SampleTimeMath: '<S6>/TSamp'
   *
   * About '<S6>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   */
  rtb_TSamp_l = rtb_Sum3 * single_qc_ppid_P.TSamp_WtEt_d;

  /* Sum: '<S4>/Sum1' incorporates:
   *  DiscreteIntegrator: '<S4>/Discrete-Time Integrator1'
   *  Gain: '<S4>/dgain1'
   *  Gain: '<S4>/igain1'
   *  Gain: '<S4>/pgain1'
   *  Sum: '<S6>/Diff'
   *  UnitDelay: '<S6>/UD'
   *
   * Block description for '<S6>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S6>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Sum1_d = (single_qc_ppid_P.pgainas * rtb_Sum3 + single_qc_ppid_P.igainas *
                single_qc_ppid_DW.DiscreteTimeIntegrator1_DSTATE) + (rtb_TSamp_l
    - single_qc_ppid_DW.UD_DSTATE_d) * single_qc_ppid_P.dgainas;

  /* Sum: '<S3>/Sum1' incorporates:
   *  Inport: '<Root>/beta_desired'
   */
  rtb_Sum1 = single_qc_ppid_U.beta_desired - rtb_beta_e;

  /* SampleTimeMath: '<S9>/TSamp'
   *
   * About '<S9>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   */
  rtb_TSamp_e = rtb_Sum1 * single_qc_ppid_P.TSamp_WtEt_i;

  /* Sum: '<S5>/Sum3' incorporates:
   *  DiscreteIntegrator: '<S5>/Discrete-Time Integrator'
   *  Gain: '<S5>/dgain'
   *  Gain: '<S5>/igain'
   *  Gain: '<S5>/pgain'
   *  Inport: '<Root>/beta_speed'
   *  Sum: '<S5>/Sum2'
   *  Sum: '<S9>/Diff'
   *  UnitDelay: '<S9>/UD'
   *
   * Block description for '<S9>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S9>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Sum3_b = ((single_qc_ppid_P.pgainb * rtb_Sum1 + single_qc_ppid_P.igainb *
                 single_qc_ppid_DW.DiscreteTimeIntegrator_DSTATE_a) +
                (rtb_TSamp_e - single_qc_ppid_DW.UD_DSTATE_g) *
                single_qc_ppid_P.dgainb) - single_qc_ppid_U.beta_speed;

  /* SampleTimeMath: '<S8>/TSamp'
   *
   * About '<S8>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   */
  rtb_TSamp_pg = rtb_Sum3_b * single_qc_ppid_P.TSamp_WtEt_j;

  /* Sum: '<S5>/Sum1' incorporates:
   *  DiscreteIntegrator: '<S5>/Discrete-Time Integrator1'
   *  Gain: '<S5>/dgain1'
   *  Gain: '<S5>/igain1'
   *  Gain: '<S5>/pgain1'
   *  Sum: '<S8>/Diff'
   *  UnitDelay: '<S8>/UD'
   *
   * Block description for '<S8>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S8>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Sum1_p = (single_qc_ppid_P.pgainbs * rtb_Sum3_b + single_qc_ppid_P.igainbs
                * single_qc_ppid_DW.DiscreteTimeIntegrator1_DSTAT_o) +
    (rtb_TSamp_pg - single_qc_ppid_DW.UD_DSTATE_d0) * single_qc_ppid_P.dgainbs;

  /* Gain: '<Root>/Gain' incorporates:
   *  Inport: '<Root>/thrust'
   */
  ftz = single_qc_ppid_P.Gain_Gain * single_qc_ppid_U.thrust;

  /* Saturate: '<Root>/Saturation' */
  if (ftz > single_qc_ppid_P.Saturation_UpperSat) {
    ftz = single_qc_ppid_P.Saturation_UpperSat;
  } else {
    if (ftz < single_qc_ppid_P.Saturation_LowerSat) {
      ftz = single_qc_ppid_P.Saturation_LowerSat;
    }
  }

  /* End of Saturate: '<Root>/Saturation' */

  /* MATLAB Function: '<Root>/MATLAB Function1' */
  thrust = ftz / 4.0F;

  /* Product: '<S3>/Product' incorporates:
   *  Trigonometry: '<S3>/Trigonometric Function1'
   */
  ftz = cosf(rtb_beta_e) * rtb_Sum1_d;

  /* Saturate: '<S3>/Saturation' */
  if (ftz > single_qc_ppid_P.sat_tx) {
    ftz = single_qc_ppid_P.sat_tx;
  } else {
    if (ftz < -single_qc_ppid_P.sat_tx) {
      ftz = -single_qc_ppid_P.sat_tx;
    }
  }

  /* End of Saturate: '<S3>/Saturation' */

  /* MATLAB Function: '<Root>/MATLAB Function1' */
  ftx = ftz / 4.0F / 0.03165F;

  /* Saturate: '<S3>/Saturation1' */
  if (rtb_Sum1_p > single_qc_ppid_P.sat_ty) {
    fty = single_qc_ppid_P.sat_ty;
  } else if (rtb_Sum1_p < -single_qc_ppid_P.sat_ty) {
    fty = -single_qc_ppid_P.sat_ty;
  } else {
    fty = rtb_Sum1_p;
  }

  /* End of Saturate: '<S3>/Saturation1' */

  /* MATLAB Function: '<Root>/MATLAB Function1' */
  fty = fty / 4.0F / 0.03165F;

  /* Product: '<S3>/Product1' incorporates:
   *  Trigonometry: '<S3>/Trigonometric Function'
   */
  ftz = rtb_Sum1_d * sinf(rtb_beta_e);

  /* Saturate: '<S3>/Saturation2' */
  if (ftz > single_qc_ppid_P.sat_tz) {
    ftz = single_qc_ppid_P.sat_tz;
  } else {
    if (ftz < -single_qc_ppid_P.sat_tz) {
      ftz = -single_qc_ppid_P.sat_tz;
    }
  }

  /* End of Saturate: '<S3>/Saturation2' */

  /* MATLAB Function: '<Root>/MATLAB Function1' incorporates:
   *  Constant: '<Root>/Constant'
   */
  ftz = ftz / 4.0F / 0.03165F * single_qc_ppid_P.torque_modifier;
  q_bi_tmp = thrust + ftx;
  q_bi[0] = ((q_bi_tmp - fty) - ftz) / 0.1472F * 65535.0F;
  thrust -= ftx;
  q_bi[1] = ((thrust - fty) + ftz) / 0.1472F * 65535.0F;
  q_bi[2] = ((thrust + fty) - ftz) / 0.1472F * 65535.0F;
  q_bi[3] = ((q_bi_tmp + fty) + ftz) / 0.1472F * 65535.0F;

  /* Saturate: '<Root>/Saturation1' */
  if (q_bi[0] > single_qc_ppid_P.Saturation1_UpperSat) {
    ftz = single_qc_ppid_P.Saturation1_UpperSat;
  } else if (q_bi[0] < single_qc_ppid_P.Saturation1_LowerSat) {
    ftz = single_qc_ppid_P.Saturation1_LowerSat;
  } else {
    ftz = q_bi[0];
  }

  /* DataTypeConversion: '<Root>/Data Type Conversion2' */
  thrust = fmodf(floorf(ftz), 65536.0F);

  /* Saturate: '<Root>/Saturation1' */
  if (q_bi[1] > single_qc_ppid_P.Saturation1_UpperSat) {
    ftz = single_qc_ppid_P.Saturation1_UpperSat;
  } else if (q_bi[1] < single_qc_ppid_P.Saturation1_LowerSat) {
    ftz = single_qc_ppid_P.Saturation1_LowerSat;
  } else {
    ftz = q_bi[1];
  }

  /* DataTypeConversion: '<Root>/Data Type Conversion2' */
  ftx = fmodf(floorf(ftz), 65536.0F);

  /* Saturate: '<Root>/Saturation1' */
  if (q_bi[2] > single_qc_ppid_P.Saturation1_UpperSat) {
    ftz = single_qc_ppid_P.Saturation1_UpperSat;
  } else if (q_bi[2] < single_qc_ppid_P.Saturation1_LowerSat) {
    ftz = single_qc_ppid_P.Saturation1_LowerSat;
  } else {
    ftz = q_bi[2];
  }

  /* DataTypeConversion: '<Root>/Data Type Conversion2' */
  fty = fmodf(floorf(ftz), 65536.0F);

  /* Saturate: '<Root>/Saturation1' */
  if (q_bi[3] > single_qc_ppid_P.Saturation1_UpperSat) {
    ftz = single_qc_ppid_P.Saturation1_UpperSat;
  } else if (q_bi[3] < single_qc_ppid_P.Saturation1_LowerSat) {
    ftz = single_qc_ppid_P.Saturation1_LowerSat;
  } else {
    ftz = q_bi[3];
  }

  /* DataTypeConversion: '<Root>/Data Type Conversion2' */
  ftz = fmodf(floorf(ftz), 65536.0F);

  /* Outport: '<Root>/m1' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion2'
   */
  single_qc_ppid_Y.m1 = (uint16_T)(thrust < 0.0F ? (int32_T)(uint16_T)-(int16_T)
    (uint16_T)-thrust : (int32_T)(uint16_T)thrust);

  /* Outport: '<Root>/m2' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion2'
   */
  single_qc_ppid_Y.m2 = (uint16_T)(ftx < 0.0F ? (int32_T)(uint16_T)-(int16_T)
    (uint16_T)-ftx : (int32_T)(uint16_T)ftx);

  /* Outport: '<Root>/m3' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion2'
   */
  single_qc_ppid_Y.m3 = (uint16_T)(fty < 0.0F ? (int32_T)(uint16_T)-(int16_T)
    (uint16_T)-fty : (int32_T)(uint16_T)fty);

  /* Outport: '<Root>/m4' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion2'
   */
  single_qc_ppid_Y.m4 = (uint16_T)(ftz < 0.0F ? (int32_T)(uint16_T)-(int16_T)
    (uint16_T)-ftz : (int32_T)(uint16_T)ftz);

  /* Outport: '<Root>/t_m1' */
  single_qc_ppid_Y.t_m1 = q_bi[0];

  /* Outport: '<Root>/t_m2' */
  single_qc_ppid_Y.t_m2 = q_bi[1];

  /* Outport: '<Root>/t_m3' */
  single_qc_ppid_Y.t_m3 = q_bi[2];

  /* Outport: '<Root>/t_m4' */
  single_qc_ppid_Y.t_m4 = q_bi[3];

  /* Outport: '<Root>/u_beta' */
  single_qc_ppid_Y.u_beta = rtb_Sum1_p;

  /* Outport: '<Root>/error_betas' */
  single_qc_ppid_Y.error_betas = rtb_Sum3_b;

  /* Outport: '<Root>/error_beta' */
  single_qc_ppid_Y.error_beta = rtb_Sum1;

  /* Outport: '<Root>/u_alpha' */
  single_qc_ppid_Y.u_alpha = rtb_Sum1_d;

  /* Outport: '<Root>/error_alphas' */
  single_qc_ppid_Y.error_alphas = rtb_Sum3;

  /* Outport: '<Root>/error_alpha' */
  single_qc_ppid_Y.error_alpha = rtb_Sum;

  /* Outport: '<Root>/t_betae' */
  single_qc_ppid_Y.t_betae = rtb_beta_e;

  /* Outport: '<Root>/t_alphae' */
  single_qc_ppid_Y.t_alphae = rtb_alpha_e;

  /* Outport: '<Root>/t_betain' incorporates:
   *  Inport: '<Root>/beta_desired'
   */
  single_qc_ppid_Y.t_betain = single_qc_ppid_U.beta_desired;

  /* Outport: '<Root>/t_alphain' incorporates:
   *  Inport: '<Root>/alpha_desired'
   */
  single_qc_ppid_Y.t_alphain = single_qc_ppid_U.alpha_desired;

  /* Update for DiscreteIntegrator: '<S4>/Discrete-Time Integrator' */
  single_qc_ppid_DW.DiscreteTimeIntegrator_DSTATE +=
    single_qc_ppid_P.DiscreteTimeIntegrator_gainval * rtb_Sum;
  if (single_qc_ppid_DW.DiscreteTimeIntegrator_DSTATE >=
      single_qc_ppid_P.DiscreteTimeIntegrator_UpperSat) {
    single_qc_ppid_DW.DiscreteTimeIntegrator_DSTATE =
      single_qc_ppid_P.DiscreteTimeIntegrator_UpperSat;
  } else {
    if (single_qc_ppid_DW.DiscreteTimeIntegrator_DSTATE <=
        single_qc_ppid_P.DiscreteTimeIntegrator_LowerSat) {
      single_qc_ppid_DW.DiscreteTimeIntegrator_DSTATE =
        single_qc_ppid_P.DiscreteTimeIntegrator_LowerSat;
    }
  }

  /* End of Update for DiscreteIntegrator: '<S4>/Discrete-Time Integrator' */

  /* Update for UnitDelay: '<S7>/UD'
   *
   * Block description for '<S7>/UD':
   *
   *  Store in Global RAM
   */
  single_qc_ppid_DW.UD_DSTATE = rtb_TSamp;

  /* Update for DiscreteIntegrator: '<S4>/Discrete-Time Integrator1' */
  single_qc_ppid_DW.DiscreteTimeIntegrator1_DSTATE +=
    single_qc_ppid_P.DiscreteTimeIntegrator1_gainval * rtb_Sum3;
  if (single_qc_ppid_DW.DiscreteTimeIntegrator1_DSTATE >=
      single_qc_ppid_P.DiscreteTimeIntegrator1_UpperSa) {
    single_qc_ppid_DW.DiscreteTimeIntegrator1_DSTATE =
      single_qc_ppid_P.DiscreteTimeIntegrator1_UpperSa;
  } else {
    if (single_qc_ppid_DW.DiscreteTimeIntegrator1_DSTATE <=
        single_qc_ppid_P.DiscreteTimeIntegrator1_LowerSa) {
      single_qc_ppid_DW.DiscreteTimeIntegrator1_DSTATE =
        single_qc_ppid_P.DiscreteTimeIntegrator1_LowerSa;
    }
  }

  /* End of Update for DiscreteIntegrator: '<S4>/Discrete-Time Integrator1' */

  /* Update for UnitDelay: '<S6>/UD'
   *
   * Block description for '<S6>/UD':
   *
   *  Store in Global RAM
   */
  single_qc_ppid_DW.UD_DSTATE_d = rtb_TSamp_l;

  /* Update for DiscreteIntegrator: '<S5>/Discrete-Time Integrator' */
  single_qc_ppid_DW.DiscreteTimeIntegrator_DSTATE_a +=
    single_qc_ppid_P.DiscreteTimeIntegrator_gainva_h * rtb_Sum1;
  if (single_qc_ppid_DW.DiscreteTimeIntegrator_DSTATE_a >=
      single_qc_ppid_P.DiscreteTimeIntegrator_UpperS_f) {
    single_qc_ppid_DW.DiscreteTimeIntegrator_DSTATE_a =
      single_qc_ppid_P.DiscreteTimeIntegrator_UpperS_f;
  } else {
    if (single_qc_ppid_DW.DiscreteTimeIntegrator_DSTATE_a <=
        single_qc_ppid_P.DiscreteTimeIntegrator_LowerS_g) {
      single_qc_ppid_DW.DiscreteTimeIntegrator_DSTATE_a =
        single_qc_ppid_P.DiscreteTimeIntegrator_LowerS_g;
    }
  }

  /* End of Update for DiscreteIntegrator: '<S5>/Discrete-Time Integrator' */

  /* Update for UnitDelay: '<S9>/UD'
   *
   * Block description for '<S9>/UD':
   *
   *  Store in Global RAM
   */
  single_qc_ppid_DW.UD_DSTATE_g = rtb_TSamp_e;

  /* Update for DiscreteIntegrator: '<S5>/Discrete-Time Integrator1' */
  single_qc_ppid_DW.DiscreteTimeIntegrator1_DSTAT_o +=
    single_qc_ppid_P.DiscreteTimeIntegrator1_gainv_m * rtb_Sum3_b;
  if (single_qc_ppid_DW.DiscreteTimeIntegrator1_DSTAT_o >=
      single_qc_ppid_P.DiscreteTimeIntegrator1_Upper_b) {
    single_qc_ppid_DW.DiscreteTimeIntegrator1_DSTAT_o =
      single_qc_ppid_P.DiscreteTimeIntegrator1_Upper_b;
  } else {
    if (single_qc_ppid_DW.DiscreteTimeIntegrator1_DSTAT_o <=
        single_qc_ppid_P.DiscreteTimeIntegrator1_Lower_m) {
      single_qc_ppid_DW.DiscreteTimeIntegrator1_DSTAT_o =
        single_qc_ppid_P.DiscreteTimeIntegrator1_Lower_m;
    }
  }

  /* End of Update for DiscreteIntegrator: '<S5>/Discrete-Time Integrator1' */

  /* Update for UnitDelay: '<S8>/UD'
   *
   * Block description for '<S8>/UD':
   *
   *  Store in Global RAM
   */
  single_qc_ppid_DW.UD_DSTATE_d0 = rtb_TSamp_pg;
}

/* Model initialize function */
void single_qc_ppid_initialize(void)
{
  /* Registration code */

  /* states (dwork) */
  (void) memset((void *)&single_qc_ppid_DW, 0,
                sizeof(DW_single_qc_ppid_T));

  /* external inputs */
  (void)memset(&single_qc_ppid_U, 0, sizeof(ExtU_single_qc_ppid_T));

  /* external outputs */
  (void) memset((void *)&single_qc_ppid_Y, 0,
                sizeof(ExtY_single_qc_ppid_T));

  /* InitializeConditions for DiscreteIntegrator: '<S4>/Discrete-Time Integrator' */
  single_qc_ppid_DW.DiscreteTimeIntegrator_DSTATE =
    single_qc_ppid_P.DiscreteTimeIntegrator_IC;

  /* InitializeConditions for UnitDelay: '<S7>/UD'
   *
   * Block description for '<S7>/UD':
   *
   *  Store in Global RAM
   */
  single_qc_ppid_DW.UD_DSTATE = single_qc_ppid_P.DiscreteDerivative2_ICPrevScale;

  /* InitializeConditions for DiscreteIntegrator: '<S4>/Discrete-Time Integrator1' */
  single_qc_ppid_DW.DiscreteTimeIntegrator1_DSTATE =
    single_qc_ppid_P.DiscreteTimeIntegrator1_IC;

  /* InitializeConditions for UnitDelay: '<S6>/UD'
   *
   * Block description for '<S6>/UD':
   *
   *  Store in Global RAM
   */
  single_qc_ppid_DW.UD_DSTATE_d =
    single_qc_ppid_P.DiscreteDerivative1_ICPrevScale;

  /* InitializeConditions for DiscreteIntegrator: '<S5>/Discrete-Time Integrator' */
  single_qc_ppid_DW.DiscreteTimeIntegrator_DSTATE_a =
    single_qc_ppid_P.DiscreteTimeIntegrator_IC_a;

  /* InitializeConditions for UnitDelay: '<S9>/UD'
   *
   * Block description for '<S9>/UD':
   *
   *  Store in Global RAM
   */
  single_qc_ppid_DW.UD_DSTATE_g =
    single_qc_ppid_P.DiscreteDerivative2_ICPrevSca_c;

  /* InitializeConditions for DiscreteIntegrator: '<S5>/Discrete-Time Integrator1' */
  single_qc_ppid_DW.DiscreteTimeIntegrator1_DSTAT_o =
    single_qc_ppid_P.DiscreteTimeIntegrator1_IC_n;

  /* InitializeConditions for UnitDelay: '<S8>/UD'
   *
   * Block description for '<S8>/UD':
   *
   *  Store in Global RAM
   */
  single_qc_ppid_DW.UD_DSTATE_d0 =
    single_qc_ppid_P.DiscreteDerivative1_ICPrevSca_d;
}

/* Model terminate function */
void single_qc_ppid_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

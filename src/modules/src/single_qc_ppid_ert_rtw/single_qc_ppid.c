/*
 * File: single_qc_ppid.c
 *
 * Code generated for Simulink model 'single_qc_ppid'.
 *
 * Model version                  : 1.73
 * Simulink Coder version         : 9.3 (R2020a) 18-Nov-2019
 * C/C++ source code generated on : Fri Oct 23 15:29:38 2020
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

real32_T rt_atan2f_snf_ppid(real32_T u0, real32_T u1)
{
  real32_T y;
  int32_T u0_0;
  int32_T u1_0;
  if (rtIsNaNF(u0) || rtIsNaNF(u1)) {
    y = (rtNaNF);
  } else if (rtIsInfF(u0) && rtIsInfF(u1)) {
    if (u0 > 0.0F) {
      u0_0 = 1;
    } else {
      u0_0 = -1;
    }

    if (u1 > 0.0F) {
      u1_0 = 1;
    } else {
      u1_0 = -1;
    }

    y = atan2f((real32_T)u0_0, (real32_T)u1_0);
  } else if (u1 == 0.0F) {
    if (u0 > 0.0F) {
      y = RT_PIF / 2.0F;
    } else if (u0 < 0.0F) {
      y = -(RT_PIF / 2.0F);
    } else {
      y = 0.0F;
    }
  } else {
    y = atan2f(u0, u1);
  }

  return y;
}

/* Model step function */
void single_qc_ppid_step(void)
{
  real32_T q_Bbi[4];
  real32_T q_bi[4];
  real32_T R_bii[9];
  real32_T tempR[9];
  int32_T d_k;
  real32_T ftx;
  real32_T fty;
  real32_T ftz;
  real32_T f0;
  real32_T f2;
  real32_T f3;
  real32_T rtb_Sum1_d;
  real32_T rtb_Saturation;
  real32_T rtb_beta_e;
  real32_T rtb_alpha_e;
  real32_T rtb_Sum;
  boolean_T rtb_Compare;
  real32_T rtb_TSamp;
  real32_T rtb_Sum3;
  real32_T rtb_TSamp_p2;
  real32_T rtb_Sum1;
  real32_T rtb_TSamp_c;
  real32_T rtb_Sum3_b;
  real32_T rtb_TSamp_gn;
  real32_T rtb_Sum1_p;
  real32_T tmp[4];
  int8_T subsa_idx_1;
  int32_T R_bii_tmp;
  real32_T f0_tmp;
  static const real32_T b[4] = { 0.707106769F, 0.0F, 0.0F, 0.707106769F };

  static const real32_T c[4] = { -0.707106769F, 0.0F, 0.0F, 0.707106769F };

  real32_T tmp_0[4];

  /* Saturate: '<Root>/Saturation' incorporates:
   *  Inport: '<Root>/thrust'
   */
  if (single_qc_ppid_U.thrust > single_qc_ppid_P.Saturation_UpperSat) {
    rtb_Saturation = single_qc_ppid_P.Saturation_UpperSat;
  } else if (single_qc_ppid_U.thrust < single_qc_ppid_P.Saturation_LowerSat) {
    rtb_Saturation = single_qc_ppid_P.Saturation_LowerSat;
  } else {
    rtb_Saturation = single_qc_ppid_U.thrust;
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
  rtb_alpha_e = -single_qc_ppid_U.index * 3.14159274F / 4.0F;
  rtb_beta_e = cosf(rtb_alpha_e);
  q_Bbi[0] = rtb_beta_e;
  q_Bbi[1] = 0.0F;
  q_Bbi[2] = 0.0F;
  rtb_alpha_e = sinf(rtb_alpha_e);
  q_Bbi[3] = rtb_alpha_e;
  tmp[0] = single_qc_ppid_U.qw_op;
  tmp[1] = single_qc_ppid_U.qx_op;
  tmp[2] = single_qc_ppid_U.qy_op;
  tmp[3] = single_qc_ppid_U.qz_op;
  q_bi[0] = -rtb_beta_e;
  q_bi[1] = 0.0F;
  q_bi[2] = 0.0F;
  q_bi[3] = rtb_alpha_e;
  single_qc_ppid_quatmultiply(tmp, q_bi, tmp_0);
  single_qc_ppid_quatmultiply(q_Bbi, tmp_0, q_bi);
  tmp[0] = single_qc_ppid_U.qw_IMU;
  tmp[1] = single_qc_ppid_U.qx_IMU;
  tmp[2] = single_qc_ppid_U.qy_IMU;
  tmp[3] = single_qc_ppid_U.qz_IMU;
  q_Bbi[0] = -q_bi[0];
  q_Bbi[1] = q_bi[1];
  q_Bbi[2] = q_bi[2];
  q_Bbi[3] = q_bi[3];
  single_qc_ppid_quatmultiply(tmp, c, tmp_0);
  single_qc_ppid_quatmultiply(b, tmp_0, tmp);
  single_qc_ppid_quatmultiply(q_Bbi, tmp, q_bi);
  rtb_alpha_e = 1.0F / sqrtf(((q_bi[0] * q_bi[0] + q_bi[1] * q_bi[1]) + q_bi[2] *
    q_bi[2]) + q_bi[3] * q_bi[3]);
  q_Bbi[0] = q_bi[0] * rtb_alpha_e;
  q_Bbi[1] = q_bi[1] * rtb_alpha_e;
  q_Bbi[2] = q_bi[2] * rtb_alpha_e;
  q_Bbi[3] = q_bi[3] * rtb_alpha_e;
  rtb_alpha_e = q_Bbi[3] * q_Bbi[3];
  rtb_beta_e = q_Bbi[2] * q_Bbi[2];
  tempR[0] = 1.0F - (rtb_beta_e + rtb_alpha_e) * 2.0F;
  rtb_Sum = q_Bbi[1] * q_Bbi[2];
  rtb_TSamp = q_Bbi[0] * q_Bbi[3];
  tempR[1] = (rtb_Sum - rtb_TSamp) * 2.0F;
  rtb_Sum3 = q_Bbi[1] * q_Bbi[3];
  rtb_TSamp_p2 = q_Bbi[0] * q_Bbi[2];
  tempR[2] = (rtb_Sum3 + rtb_TSamp_p2) * 2.0F;
  tempR[3] = (rtb_Sum + rtb_TSamp) * 2.0F;
  rtb_Sum = q_Bbi[1] * q_Bbi[1];
  tempR[4] = 1.0F - (rtb_Sum + rtb_alpha_e) * 2.0F;
  rtb_alpha_e = q_Bbi[2] * q_Bbi[3];
  rtb_TSamp = q_Bbi[0] * q_Bbi[1];
  tempR[5] = (rtb_alpha_e - rtb_TSamp) * 2.0F;
  tempR[6] = (rtb_Sum3 - rtb_TSamp_p2) * 2.0F;
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

  rtb_alpha_e = rt_atan2f_snf_ppid(R_bii[5], R_bii[4]);
  rtb_beta_e = rt_atan2f_snf_ppid(R_bii[6], R_bii[0]);

  /* End of MATLAB Function: '<Root>/MATLAB Function' */

  /* Sum: '<S3>/Sum' incorporates:
   *  Inport: '<Root>/alpha_desired'
   */
  rtb_Sum = single_qc_ppid_U.alpha_desired - rtb_alpha_e;

  /* RelationalOperator: '<S6>/Compare' incorporates:
   *  Constant: '<S6>/Constant'
   */
  rtb_Compare = (rtb_Saturation > single_qc_ppid_P.Constant_Value);

  /* DiscreteIntegrator: '<S4>/Discrete-Time Integrator2' */
  if (rtb_Compare && (single_qc_ppid_DW.DiscreteTimeIntegrator2_PrevRes <= 0)) {
    single_qc_ppid_DW.DiscreteTimeIntegrator2_DSTATE =
      single_qc_ppid_P.DiscreteTimeIntegrator2_IC;
  }

  if (single_qc_ppid_DW.DiscreteTimeIntegrator2_DSTATE >=
      single_qc_ppid_P.DiscreteTimeIntegrator2_UpperSa) {
    single_qc_ppid_DW.DiscreteTimeIntegrator2_DSTATE =
      single_qc_ppid_P.DiscreteTimeIntegrator2_UpperSa;
  } else {
    if (single_qc_ppid_DW.DiscreteTimeIntegrator2_DSTATE <=
        single_qc_ppid_P.DiscreteTimeIntegrator2_LowerSa) {
      single_qc_ppid_DW.DiscreteTimeIntegrator2_DSTATE =
        single_qc_ppid_P.DiscreteTimeIntegrator2_LowerSa;
    }
  }

  /* SampleTimeMath: '<S8>/TSamp'
   *
   * About '<S8>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   */
  rtb_TSamp = rtb_Sum * single_qc_ppid_P.TSamp_WtEt;

  /* Sum: '<S4>/Sum3' incorporates:
   *  DiscreteIntegrator: '<S4>/Discrete-Time Integrator2'
   *  Gain: '<S4>/dgain'
   *  Gain: '<S4>/igain'
   *  Gain: '<S4>/pgain'
   *  Inport: '<Root>/alpha_speed'
   *  Sum: '<S4>/Sum2'
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
  rtb_Sum3 = ((single_qc_ppid_P.pgaina * rtb_Sum + single_qc_ppid_P.igaina *
               single_qc_ppid_DW.DiscreteTimeIntegrator2_DSTATE) + (rtb_TSamp -
    single_qc_ppid_DW.UD_DSTATE) * single_qc_ppid_P.dgaina) -
    single_qc_ppid_U.alpha_speed;

  /* DiscreteIntegrator: '<S4>/Discrete-Time Integrator1' */
  if (rtb_Compare && (single_qc_ppid_DW.DiscreteTimeIntegrator1_PrevRes <= 0)) {
    single_qc_ppid_DW.DiscreteTimeIntegrator1_DSTATE =
      single_qc_ppid_P.DiscreteTimeIntegrator1_IC;
  }

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

  /* SampleTimeMath: '<S7>/TSamp'
   *
   * About '<S7>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   */
  rtb_TSamp_p2 = rtb_Sum3 * single_qc_ppid_P.TSamp_WtEt_k;

  /* Sum: '<S4>/Sum1' incorporates:
   *  DiscreteIntegrator: '<S4>/Discrete-Time Integrator1'
   *  Gain: '<S4>/dgain1'
   *  Gain: '<S4>/igain1'
   *  Gain: '<S4>/pgain1'
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
  rtb_Sum1_d = (single_qc_ppid_P.pgainas * rtb_Sum3 + single_qc_ppid_P.igainas *
                single_qc_ppid_DW.DiscreteTimeIntegrator1_DSTATE) +
    (rtb_TSamp_p2 - single_qc_ppid_DW.UD_DSTATE_j) * single_qc_ppid_P.dgainas;

  /* Sum: '<S3>/Sum1' incorporates:
   *  Inport: '<Root>/beta_desired'
   */
  rtb_Sum1 = single_qc_ppid_U.beta_desired - rtb_beta_e;

  /* DiscreteIntegrator: '<S5>/Discrete-Time Integrator2' */
  if ((rtb_Saturation > 0.0F) &&
      (single_qc_ppid_DW.DiscreteTimeIntegrator2_PrevR_e <= 0)) {
    single_qc_ppid_DW.DiscreteTimeIntegrator2_DSTAT_o =
      single_qc_ppid_P.DiscreteTimeIntegrator2_IC_h;
  }

  if (single_qc_ppid_DW.DiscreteTimeIntegrator2_DSTAT_o >=
      single_qc_ppid_P.DiscreteTimeIntegrator2_Upper_l) {
    single_qc_ppid_DW.DiscreteTimeIntegrator2_DSTAT_o =
      single_qc_ppid_P.DiscreteTimeIntegrator2_Upper_l;
  } else {
    if (single_qc_ppid_DW.DiscreteTimeIntegrator2_DSTAT_o <=
        single_qc_ppid_P.DiscreteTimeIntegrator2_Lower_i) {
      single_qc_ppid_DW.DiscreteTimeIntegrator2_DSTAT_o =
        single_qc_ppid_P.DiscreteTimeIntegrator2_Lower_i;
    }
  }

  /* SampleTimeMath: '<S10>/TSamp'
   *
   * About '<S10>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   */
  rtb_TSamp_c = rtb_Sum1 * single_qc_ppid_P.TSamp_WtEt_i;

  /* Sum: '<S5>/Sum3' incorporates:
   *  DiscreteIntegrator: '<S5>/Discrete-Time Integrator2'
   *  Gain: '<S5>/dgain'
   *  Gain: '<S5>/igain'
   *  Gain: '<S5>/pgain'
   *  Inport: '<Root>/beta_speed'
   *  Sum: '<S10>/Diff'
   *  Sum: '<S5>/Sum2'
   *  UnitDelay: '<S10>/UD'
   *
   * Block description for '<S10>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S10>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Sum3_b = ((single_qc_ppid_P.pgainb * rtb_Sum1 + single_qc_ppid_P.igainb *
                 single_qc_ppid_DW.DiscreteTimeIntegrator2_DSTAT_o) +
                (rtb_TSamp_c - single_qc_ppid_DW.UD_DSTATE_p) *
                single_qc_ppid_P.dgainb) - single_qc_ppid_U.beta_speed;

  /* DiscreteIntegrator: '<S5>/Discrete-Time Integrator1' */
  if ((rtb_Saturation > 0.0F) &&
      (single_qc_ppid_DW.DiscreteTimeIntegrator1_PrevR_o <= 0)) {
    single_qc_ppid_DW.DiscreteTimeIntegrator1_DSTAT_p =
      single_qc_ppid_P.DiscreteTimeIntegrator1_IC_h;
  }

  if (single_qc_ppid_DW.DiscreteTimeIntegrator1_DSTAT_p >=
      single_qc_ppid_P.DiscreteTimeIntegrator1_Upper_e) {
    single_qc_ppid_DW.DiscreteTimeIntegrator1_DSTAT_p =
      single_qc_ppid_P.DiscreteTimeIntegrator1_Upper_e;
  } else {
    if (single_qc_ppid_DW.DiscreteTimeIntegrator1_DSTAT_p <=
        single_qc_ppid_P.DiscreteTimeIntegrator1_Lower_f) {
      single_qc_ppid_DW.DiscreteTimeIntegrator1_DSTAT_p =
        single_qc_ppid_P.DiscreteTimeIntegrator1_Lower_f;
    }
  }

  /* SampleTimeMath: '<S9>/TSamp'
   *
   * About '<S9>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   */
  rtb_TSamp_gn = rtb_Sum3_b * single_qc_ppid_P.TSamp_WtEt_b;

  /* Sum: '<S5>/Sum1' incorporates:
   *  DiscreteIntegrator: '<S5>/Discrete-Time Integrator1'
   *  Gain: '<S5>/dgain1'
   *  Gain: '<S5>/igain1'
   *  Gain: '<S5>/pgain1'
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
  rtb_Sum1_p = (single_qc_ppid_P.pgainbs * rtb_Sum3_b + single_qc_ppid_P.igainbs
                * single_qc_ppid_DW.DiscreteTimeIntegrator1_DSTAT_p) +
    (rtb_TSamp_gn - single_qc_ppid_DW.UD_DSTATE_d) * single_qc_ppid_P.dgainbs;

  /* MATLAB Function: '<Root>/MATLAB Function1' */
  f3 = rtb_Saturation / 4.0F;

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
  f0_tmp = f3 + ftx;
  f0 = (f0_tmp - fty) - ftz;
  f3 -= ftx;
  ftx = (f3 - fty) + ftz;
  f2 = (f3 + fty) - ftz;
  f3 = (f0_tmp + fty) + ftz;
  if (f0 < 0.0F) {
    f0 = 0.0F;
  }

  if (ftx < 0.0F) {
    ftx = 0.0F;
  }

  if (f2 < 0.0F) {
    f2 = 0.0F;
  }

  if (f3 < 0.0F) {
    f3 = 0.0F;
  }

  q_Bbi[0] = (sqrtf(0.366F * f0 + 0.00457922881F) + -0.06767F) / 0.183F *
    65535.0F;
  q_Bbi[1] = (sqrtf(0.366F * ftx + 0.00457922881F) + -0.06767F) / 0.183F *
    65535.0F;
  q_Bbi[2] = (sqrtf(0.366F * f2 + 0.00457922881F) + -0.06767F) / 0.183F *
    65535.0F;
  q_Bbi[3] = (sqrtf(0.366F * f3 + 0.00457922881F) + -0.06767F) / 0.183F *
    65535.0F;

  /* Saturate: '<Root>/Saturation1' */
  if (q_Bbi[0] > single_qc_ppid_P.Saturation1_UpperSat) {
    f0_tmp = single_qc_ppid_P.Saturation1_UpperSat;
  } else if (q_Bbi[0] < single_qc_ppid_P.Saturation1_LowerSat) {
    f0_tmp = single_qc_ppid_P.Saturation1_LowerSat;
  } else {
    f0_tmp = q_Bbi[0];
  }

  /* DataTypeConversion: '<Root>/Data Type Conversion2' */
  f3 = floorf(f0_tmp);
  if (rtIsNaNF(f3) || rtIsInfF(f3)) {
    f3 = 0.0F;
  } else {
    f3 = fmodf(f3, 65536.0F);
  }

  /* Saturate: '<Root>/Saturation1' */
  if (q_Bbi[1] > single_qc_ppid_P.Saturation1_UpperSat) {
    f0_tmp = single_qc_ppid_P.Saturation1_UpperSat;
  } else if (q_Bbi[1] < single_qc_ppid_P.Saturation1_LowerSat) {
    f0_tmp = single_qc_ppid_P.Saturation1_LowerSat;
  } else {
    f0_tmp = q_Bbi[1];
  }

  /* DataTypeConversion: '<Root>/Data Type Conversion2' */
  fty = floorf(f0_tmp);
  if (rtIsNaNF(fty) || rtIsInfF(fty)) {
    fty = 0.0F;
  } else {
    fty = fmodf(fty, 65536.0F);
  }

  /* Saturate: '<Root>/Saturation1' */
  if (q_Bbi[2] > single_qc_ppid_P.Saturation1_UpperSat) {
    f0_tmp = single_qc_ppid_P.Saturation1_UpperSat;
  } else if (q_Bbi[2] < single_qc_ppid_P.Saturation1_LowerSat) {
    f0_tmp = single_qc_ppid_P.Saturation1_LowerSat;
  } else {
    f0_tmp = q_Bbi[2];
  }

  /* DataTypeConversion: '<Root>/Data Type Conversion2' */
  ftz = floorf(f0_tmp);
  if (rtIsNaNF(ftz) || rtIsInfF(ftz)) {
    ftz = 0.0F;
  } else {
    ftz = fmodf(ftz, 65536.0F);
  }

  /* Saturate: '<Root>/Saturation1' */
  if (q_Bbi[3] > single_qc_ppid_P.Saturation1_UpperSat) {
    f0_tmp = single_qc_ppid_P.Saturation1_UpperSat;
  } else if (q_Bbi[3] < single_qc_ppid_P.Saturation1_LowerSat) {
    f0_tmp = single_qc_ppid_P.Saturation1_LowerSat;
  } else {
    f0_tmp = q_Bbi[3];
  }

  /* DataTypeConversion: '<Root>/Data Type Conversion2' */
  f0_tmp = floorf(f0_tmp);
  if (rtIsNaNF(f0_tmp) || rtIsInfF(f0_tmp)) {
    f0_tmp = 0.0F;
  } else {
    f0_tmp = fmodf(f0_tmp, 65536.0F);
  }

  /* Outport: '<Root>/m1' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion2'
   */
  single_qc_ppid_Y.m1 = (uint16_T)(f3 < 0.0F ? (int32_T)(uint16_T)-(int16_T)
    (uint16_T)-f3 : (int32_T)(uint16_T)f3);

  /* Outport: '<Root>/m2' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion2'
   */
  single_qc_ppid_Y.m2 = (uint16_T)(fty < 0.0F ? (int32_T)(uint16_T)-(int16_T)
    (uint16_T)-fty : (int32_T)(uint16_T)fty);

  /* Outport: '<Root>/m3' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion2'
   */
  single_qc_ppid_Y.m3 = (uint16_T)(ftz < 0.0F ? (int32_T)(uint16_T)-(int16_T)
    (uint16_T)-ftz : (int32_T)(uint16_T)ftz);

  /* Outport: '<Root>/m4' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion2'
   */
  single_qc_ppid_Y.m4 = (uint16_T)(f0_tmp < 0.0F ? (int32_T)(uint16_T)-(int16_T)
    (uint16_T)-f0_tmp : (int32_T)(uint16_T)f0_tmp);

  /* Outport: '<Root>/t_m1' */
  single_qc_ppid_Y.t_m1 = q_Bbi[0];

  /* Outport: '<Root>/t_m2' */
  single_qc_ppid_Y.t_m2 = q_Bbi[1];

  /* Outport: '<Root>/t_m3' */
  single_qc_ppid_Y.t_m3 = q_Bbi[2];

  /* Outport: '<Root>/t_m4' */
  single_qc_ppid_Y.t_m4 = q_Bbi[3];

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

  /* Update for DiscreteIntegrator: '<S4>/Discrete-Time Integrator2' */
  single_qc_ppid_DW.DiscreteTimeIntegrator2_DSTATE +=
    single_qc_ppid_P.DiscreteTimeIntegrator2_gainval * rtb_Sum;
  if (single_qc_ppid_DW.DiscreteTimeIntegrator2_DSTATE >=
      single_qc_ppid_P.DiscreteTimeIntegrator2_UpperSa) {
    single_qc_ppid_DW.DiscreteTimeIntegrator2_DSTATE =
      single_qc_ppid_P.DiscreteTimeIntegrator2_UpperSa;
  } else {
    if (single_qc_ppid_DW.DiscreteTimeIntegrator2_DSTATE <=
        single_qc_ppid_P.DiscreteTimeIntegrator2_LowerSa) {
      single_qc_ppid_DW.DiscreteTimeIntegrator2_DSTATE =
        single_qc_ppid_P.DiscreteTimeIntegrator2_LowerSa;
    }
  }

  single_qc_ppid_DW.DiscreteTimeIntegrator2_PrevRes = (int8_T)rtb_Compare;

  /* End of Update for DiscreteIntegrator: '<S4>/Discrete-Time Integrator2' */

  /* Update for UnitDelay: '<S8>/UD'
   *
   * Block description for '<S8>/UD':
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

  single_qc_ppid_DW.DiscreteTimeIntegrator1_PrevRes = (int8_T)rtb_Compare;

  /* End of Update for DiscreteIntegrator: '<S4>/Discrete-Time Integrator1' */

  /* Update for UnitDelay: '<S7>/UD'
   *
   * Block description for '<S7>/UD':
   *
   *  Store in Global RAM
   */
  single_qc_ppid_DW.UD_DSTATE_j = rtb_TSamp_p2;

  /* Update for DiscreteIntegrator: '<S5>/Discrete-Time Integrator2' */
  single_qc_ppid_DW.DiscreteTimeIntegrator2_DSTAT_o +=
    single_qc_ppid_P.DiscreteTimeIntegrator2_gainv_f * rtb_Sum1;
  if (single_qc_ppid_DW.DiscreteTimeIntegrator2_DSTAT_o >=
      single_qc_ppid_P.DiscreteTimeIntegrator2_Upper_l) {
    single_qc_ppid_DW.DiscreteTimeIntegrator2_DSTAT_o =
      single_qc_ppid_P.DiscreteTimeIntegrator2_Upper_l;
  } else {
    if (single_qc_ppid_DW.DiscreteTimeIntegrator2_DSTAT_o <=
        single_qc_ppid_P.DiscreteTimeIntegrator2_Lower_i) {
      single_qc_ppid_DW.DiscreteTimeIntegrator2_DSTAT_o =
        single_qc_ppid_P.DiscreteTimeIntegrator2_Lower_i;
    }
  }

  if (rtb_Saturation > 0.0F) {
    single_qc_ppid_DW.DiscreteTimeIntegrator2_PrevR_e = 1;
  } else if (rtb_Saturation < 0.0F) {
    single_qc_ppid_DW.DiscreteTimeIntegrator2_PrevR_e = -1;
  } else if (rtb_Saturation == 0.0F) {
    single_qc_ppid_DW.DiscreteTimeIntegrator2_PrevR_e = 0;
  } else {
    single_qc_ppid_DW.DiscreteTimeIntegrator2_PrevR_e = 2;
  }

  /* End of Update for DiscreteIntegrator: '<S5>/Discrete-Time Integrator2' */

  /* Update for UnitDelay: '<S10>/UD'
   *
   * Block description for '<S10>/UD':
   *
   *  Store in Global RAM
   */
  single_qc_ppid_DW.UD_DSTATE_p = rtb_TSamp_c;

  /* Update for DiscreteIntegrator: '<S5>/Discrete-Time Integrator1' */
  single_qc_ppid_DW.DiscreteTimeIntegrator1_DSTAT_p +=
    single_qc_ppid_P.DiscreteTimeIntegrator1_gainv_c * rtb_Sum3_b;
  if (single_qc_ppid_DW.DiscreteTimeIntegrator1_DSTAT_p >=
      single_qc_ppid_P.DiscreteTimeIntegrator1_Upper_e) {
    single_qc_ppid_DW.DiscreteTimeIntegrator1_DSTAT_p =
      single_qc_ppid_P.DiscreteTimeIntegrator1_Upper_e;
  } else {
    if (single_qc_ppid_DW.DiscreteTimeIntegrator1_DSTAT_p <=
        single_qc_ppid_P.DiscreteTimeIntegrator1_Lower_f) {
      single_qc_ppid_DW.DiscreteTimeIntegrator1_DSTAT_p =
        single_qc_ppid_P.DiscreteTimeIntegrator1_Lower_f;
    }
  }

  if (rtb_Saturation > 0.0F) {
    single_qc_ppid_DW.DiscreteTimeIntegrator1_PrevR_o = 1;
  } else if (rtb_Saturation < 0.0F) {
    single_qc_ppid_DW.DiscreteTimeIntegrator1_PrevR_o = -1;
  } else if (rtb_Saturation == 0.0F) {
    single_qc_ppid_DW.DiscreteTimeIntegrator1_PrevR_o = 0;
  } else {
    single_qc_ppid_DW.DiscreteTimeIntegrator1_PrevR_o = 2;
  }

  /* End of Update for DiscreteIntegrator: '<S5>/Discrete-Time Integrator1' */

  /* Update for UnitDelay: '<S9>/UD'
   *
   * Block description for '<S9>/UD':
   *
   *  Store in Global RAM
   */
  single_qc_ppid_DW.UD_DSTATE_d = rtb_TSamp_gn;
}

/* Model initialize function */
void single_qc_ppid_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* states (dwork) */
  (void) memset((void *)&single_qc_ppid_DW, 0,
                sizeof(DW_single_qc_ppid_T));

  /* external inputs */
  (void)memset(&single_qc_ppid_U, 0, sizeof(ExtU_single_qc_ppid_T));

  /* external outputs */
  (void) memset((void *)&single_qc_ppid_Y, 0,
                sizeof(ExtY_single_qc_ppid_T));

  /* InitializeConditions for DiscreteIntegrator: '<S4>/Discrete-Time Integrator2' */
  single_qc_ppid_DW.DiscreteTimeIntegrator2_DSTATE =
    single_qc_ppid_P.DiscreteTimeIntegrator2_IC;
  single_qc_ppid_DW.DiscreteTimeIntegrator2_PrevRes = 2;

  /* InitializeConditions for UnitDelay: '<S8>/UD'
   *
   * Block description for '<S8>/UD':
   *
   *  Store in Global RAM
   */
  single_qc_ppid_DW.UD_DSTATE = single_qc_ppid_P.DiscreteDerivative2_ICPrevScale;

  /* InitializeConditions for DiscreteIntegrator: '<S4>/Discrete-Time Integrator1' */
  single_qc_ppid_DW.DiscreteTimeIntegrator1_DSTATE =
    single_qc_ppid_P.DiscreteTimeIntegrator1_IC;
  single_qc_ppid_DW.DiscreteTimeIntegrator1_PrevRes = 2;

  /* InitializeConditions for UnitDelay: '<S7>/UD'
   *
   * Block description for '<S7>/UD':
   *
   *  Store in Global RAM
   */
  single_qc_ppid_DW.UD_DSTATE_j =
    single_qc_ppid_P.DiscreteDerivative1_ICPrevScale;

  /* InitializeConditions for DiscreteIntegrator: '<S5>/Discrete-Time Integrator2' */
  single_qc_ppid_DW.DiscreteTimeIntegrator2_DSTAT_o =
    single_qc_ppid_P.DiscreteTimeIntegrator2_IC_h;
  single_qc_ppid_DW.DiscreteTimeIntegrator2_PrevR_e = 2;

  /* InitializeConditions for UnitDelay: '<S10>/UD'
   *
   * Block description for '<S10>/UD':
   *
   *  Store in Global RAM
   */
  single_qc_ppid_DW.UD_DSTATE_p =
    single_qc_ppid_P.DiscreteDerivative2_ICPrevSca_g;

  /* InitializeConditions for DiscreteIntegrator: '<S5>/Discrete-Time Integrator1' */
  single_qc_ppid_DW.DiscreteTimeIntegrator1_DSTAT_p =
    single_qc_ppid_P.DiscreteTimeIntegrator1_IC_h;
  single_qc_ppid_DW.DiscreteTimeIntegrator1_PrevR_o = 2;

  /* InitializeConditions for UnitDelay: '<S9>/UD'
   *
   * Block description for '<S9>/UD':
   *
   *  Store in Global RAM
   */
  single_qc_ppid_DW.UD_DSTATE_d =
    single_qc_ppid_P.DiscreteDerivative1_ICPrevSca_h;
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

/*
 * File: single_qc_ppid.c
 *
 * Code generated for Simulink model 'single_qc_ppid'.
 *
 * Model version                  : 1.61
 * Simulink Coder version         : 9.3 (R2020a) 18-Nov-2019
 * C/C++ source code generated on : Sat Aug 15 12:44:36 2020
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

/*
 * Output and update for atomic system:
 *    '<S4>/MATLAB Function'
 *    '<S4>/MATLAB Function1'
 *    '<S5>/MATLAB Function'
 *    '<S5>/MATLAB Function1'
 */
void single_qc_ppid_MATLABFunction(real32_T rtu_value, boolean_T rtu_label,
  real32_T *rty_newvalue)
{
  if (rtu_label) {
    *rty_newvalue = 0.0F;
  } else {
    *rty_newvalue = rtu_value;
  }
}

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
  real32_T f2;
  real32_T f3;
  real32_T rtb_newvalue_d;
  real32_T rtb_newvalue_h;
  real32_T rtb_newvalue_g;
  real32_T rtb_beta_e;
  real32_T rtb_alpha_e;
  real32_T rtb_Sum;
  real32_T rtb_Sum_p;
  real32_T rtb_Sum3;
  real32_T rtb_Sum4;
  real32_T rtb_Sum1;
  real32_T rtb_Sum_b;
  real32_T rtb_Sum3_b;
  real32_T rtb_Sum4_b;
  real32_T tmp[4];
  int8_T subsa_idx_1;
  int32_T R_bii_tmp;
  real32_T rtb_newvalue_n_tmp;
  static const real32_T b[4] = { 0.707106769F, 0.0F, 0.0F, 0.707106769F };

  static const real32_T c[4] = { -0.707106769F, 0.0F, 0.0F, 0.707106769F };

  real32_T tmp_0[4];

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
  rtb_alpha_e = single_qc_ppid_U.index * 3.14159274F / 4.0F;
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
  single_qc_ppid_quatmultiply(tmp, q_Bbi, q_bi);
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
  rtb_Sum_p = q_Bbi[0] * q_Bbi[3];
  tempR[1] = (rtb_Sum - rtb_Sum_p) * 2.0F;
  rtb_Sum3 = q_Bbi[1] * q_Bbi[3];
  rtb_Sum4 = q_Bbi[0] * q_Bbi[2];
  tempR[2] = (rtb_Sum3 + rtb_Sum4) * 2.0F;
  tempR[3] = (rtb_Sum + rtb_Sum_p) * 2.0F;
  rtb_Sum = q_Bbi[1] * q_Bbi[1];
  tempR[4] = 1.0F - (rtb_Sum + rtb_alpha_e) * 2.0F;
  rtb_alpha_e = q_Bbi[2] * q_Bbi[3];
  rtb_Sum_p = q_Bbi[0] * q_Bbi[1];
  tempR[5] = (rtb_alpha_e - rtb_Sum_p) * 2.0F;
  tempR[6] = (rtb_Sum3 - rtb_Sum4) * 2.0F;
  tempR[7] = (rtb_alpha_e + rtb_Sum_p) * 2.0F;
  tempR[8] = 1.0F - (rtb_Sum + rtb_beta_e) * 2.0F;
  for (d_k = 0; d_k < 3; d_k++) {
    R_bii_tmp = (int8_T)(d_k + 1) - 1;
    R_bii[R_bii_tmp] = tempR[R_bii_tmp * 3];
    subsa_idx_1 = (int8_T)(d_k + 1);
    R_bii[subsa_idx_1 + 2] = tempR[(subsa_idx_1 - 1) * 3 + 1];
    subsa_idx_1 = (int8_T)(d_k + 1);
    R_bii[subsa_idx_1 + 5] = tempR[(subsa_idx_1 - 1) * 3 + 2];
  }

  rtb_alpha_e = rt_atan2f_snf_ppid(-R_bii[7], R_bii[8]);
  rtb_beta_e = rt_atan2f_snf_ppid(R_bii[6], R_bii[0]);

  /* End of MATLAB Function: '<Root>/MATLAB Function' */

  /* Sum: '<S3>/Sum' incorporates:
   *  Inport: '<Root>/alpha_desired'
   */
  rtb_Sum = single_qc_ppid_U.alpha_desired - rtb_alpha_e;

  /* Sum: '<S4>/Sum' incorporates:
   *  Memory: '<S4>/Memory'
   */
  rtb_Sum_p = single_qc_ppid_DW.Memory_PreviousInput + rtb_Sum;

  /* Sum: '<S4>/Sum3' incorporates:
   *  Gain: '<S4>/dgain'
   *  Gain: '<S4>/dgain2'
   *  Gain: '<S4>/igain'
   *  Gain: '<S4>/pgain'
   *  Inport: '<Root>/alpha_speed'
   *  Memory: '<S4>/Memory2'
   *  Sum: '<S4>/Sum2'
   *  Sum: '<S4>/Sum5'
   */
  rtb_Sum3 = ((rtb_Sum - single_qc_ppid_DW.Memory2_PreviousInput) *
              single_qc_ppid_P.dgain2_Gain * single_qc_ppid_P.dgaina +
              (single_qc_ppid_P.pgaina * rtb_Sum + single_qc_ppid_P.igaina *
               rtb_Sum_p)) - single_qc_ppid_U.alpha_speed;

  /* Sum: '<S4>/Sum4' incorporates:
   *  Memory: '<S4>/Memory1'
   */
  rtb_Sum4 = single_qc_ppid_DW.Memory1_PreviousInput + rtb_Sum3;

  /* Sum: '<S4>/Sum1' incorporates:
   *  Gain: '<S4>/dgain1'
   *  Gain: '<S4>/dgain3'
   *  Gain: '<S4>/igain1'
   *  Gain: '<S4>/pgain1'
   *  Memory: '<S4>/Memory3'
   *  Sum: '<S4>/Sum6'
   */
  rtb_newvalue_d = (rtb_Sum3 - single_qc_ppid_DW.Memory3_PreviousInput) *
    single_qc_ppid_P.dgain3_Gain * single_qc_ppid_P.dgainas +
    (single_qc_ppid_P.pgainas * rtb_Sum3 + single_qc_ppid_P.igainas * rtb_Sum4);

  /* Sum: '<S3>/Sum1' incorporates:
   *  Inport: '<Root>/beta_desired'
   */
  rtb_Sum1 = single_qc_ppid_U.beta_desired - rtb_beta_e;

  /* Sum: '<S5>/Sum' incorporates:
   *  Memory: '<S5>/Memory'
   */
  rtb_Sum_b = single_qc_ppid_DW.Memory_PreviousInput_n + rtb_Sum1;

  /* Sum: '<S5>/Sum3' incorporates:
   *  Gain: '<S5>/dgain'
   *  Gain: '<S5>/dgain2'
   *  Gain: '<S5>/igain'
   *  Gain: '<S5>/pgain'
   *  Inport: '<Root>/beta_speed'
   *  Memory: '<S5>/Memory2'
   *  Sum: '<S5>/Sum2'
   *  Sum: '<S5>/Sum5'
   */
  rtb_Sum3_b = ((rtb_Sum1 - single_qc_ppid_DW.Memory2_PreviousInput_m) *
                single_qc_ppid_P.dgain2_Gain_l * single_qc_ppid_P.dgainb +
                (single_qc_ppid_P.pgainb * rtb_Sum1 + single_qc_ppid_P.igainb *
                 rtb_Sum_b)) - single_qc_ppid_U.beta_speed;

  /* Sum: '<S5>/Sum4' incorporates:
   *  Memory: '<S5>/Memory1'
   */
  rtb_Sum4_b = single_qc_ppid_DW.Memory1_PreviousInput_b + rtb_Sum3_b;

  /* Sum: '<S5>/Sum1' incorporates:
   *  Gain: '<S5>/dgain1'
   *  Gain: '<S5>/dgain3'
   *  Gain: '<S5>/igain1'
   *  Gain: '<S5>/pgain1'
   *  Memory: '<S5>/Memory3'
   *  Sum: '<S5>/Sum6'
   */
  rtb_newvalue_h = (rtb_Sum3_b - single_qc_ppid_DW.Memory3_PreviousInput_k) *
    single_qc_ppid_P.dgain3_Gain_h * single_qc_ppid_P.dgainbs +
    (single_qc_ppid_P.pgainbs * rtb_Sum3_b + single_qc_ppid_P.igainbs *
     rtb_Sum4_b);

  /* Product: '<S3>/Product1' incorporates:
   *  Trigonometry: '<S3>/Trigonometric Function'
   */
  rtb_newvalue_g = rtb_newvalue_d * sinf(rtb_beta_e);

  /* Saturate: '<Root>/Saturation' incorporates:
   *  Inport: '<Root>/thrust'
   */
  if (single_qc_ppid_U.thrust > single_qc_ppid_P.Saturation_UpperSat) {
    f3 = single_qc_ppid_P.Saturation_UpperSat;
  } else if (single_qc_ppid_U.thrust < single_qc_ppid_P.Saturation_LowerSat) {
    f3 = single_qc_ppid_P.Saturation_LowerSat;
  } else {
    f3 = single_qc_ppid_U.thrust;
  }

  /* End of Saturate: '<Root>/Saturation' */

  /* MATLAB Function: '<Root>/MATLAB Function1' */
  f3 /= 4.0F;

  /* Product: '<S3>/Product' incorporates:
   *  Trigonometry: '<S3>/Trigonometric Function1'
   */
  fty = cosf(rtb_beta_e) * rtb_newvalue_d;

  /* Saturate: '<S3>/Saturation' */
  if (fty > single_qc_ppid_P.sat_tx) {
    fty = single_qc_ppid_P.sat_tx;
  } else {
    if (fty < -single_qc_ppid_P.sat_tx) {
      fty = -single_qc_ppid_P.sat_tx;
    }
  }

  /* End of Saturate: '<S3>/Saturation' */

  /* MATLAB Function: '<Root>/MATLAB Function1' */
  ftx = fty / 4.0F / 0.03165F;

  /* Saturate: '<S3>/Saturation1' */
  if (rtb_newvalue_h > single_qc_ppid_P.sat_ty) {
    fty = single_qc_ppid_P.sat_ty;
  } else if (rtb_newvalue_h < -single_qc_ppid_P.sat_ty) {
    fty = -single_qc_ppid_P.sat_ty;
  } else {
    fty = rtb_newvalue_h;
  }

  /* End of Saturate: '<S3>/Saturation1' */

  /* MATLAB Function: '<Root>/MATLAB Function1' */
  fty = fty / 4.0F / 0.03165F;

  /* Saturate: '<S3>/Saturation2' */
  if (rtb_newvalue_g > single_qc_ppid_P.sat_tz) {
    rtb_newvalue_g = single_qc_ppid_P.sat_tz;
  } else {
    if (rtb_newvalue_g < -single_qc_ppid_P.sat_tz) {
      rtb_newvalue_g = -single_qc_ppid_P.sat_tz;
    }
  }

  /* End of Saturate: '<S3>/Saturation2' */

  /* MATLAB Function: '<Root>/MATLAB Function1' incorporates:
   *  Constant: '<Root>/Constant'
   */
  ftz = rtb_newvalue_g / 4.0F / 0.03165F * single_qc_ppid_P.torque_modifier;
  rtb_newvalue_n_tmp = f3 + ftx;
  rtb_newvalue_g = (rtb_newvalue_n_tmp - fty) - ftz;
  f3 -= ftx;
  ftx = (f3 - fty) + ftz;
  f2 = (f3 + fty) - ftz;
  f3 = (rtb_newvalue_n_tmp + fty) + ftz;
  if (rtb_newvalue_g < 0.0F) {
    rtb_newvalue_g = 0.0F;
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

  q_Bbi[0] = (sqrtf(0.366F * rtb_newvalue_g + 0.00457922881F) + -0.06767F) /
    0.183F * 65535.0F;
  q_Bbi[1] = (sqrtf(0.366F * ftx + 0.00457922881F) + -0.06767F) / 0.183F *
    65535.0F;
  q_Bbi[2] = (sqrtf(0.366F * f2 + 0.00457922881F) + -0.06767F) / 0.183F *
    65535.0F;
  q_Bbi[3] = (sqrtf(0.366F * f3 + 0.00457922881F) + -0.06767F) / 0.183F *
    65535.0F;

  /* Saturate: '<Root>/Saturation1' */
  if (q_Bbi[0] > single_qc_ppid_P.Saturation1_UpperSat) {
    ftz = single_qc_ppid_P.Saturation1_UpperSat;
  } else if (q_Bbi[0] < single_qc_ppid_P.Saturation1_LowerSat) {
    ftz = single_qc_ppid_P.Saturation1_LowerSat;
  } else {
    ftz = q_Bbi[0];
  }

  /* DataTypeConversion: '<Root>/Data Type Conversion2' */
  f3 = floorf(ftz);
  if (rtIsNaNF(f3) || rtIsInfF(f3)) {
    f3 = 0.0F;
  } else {
    f3 = fmodf(f3, 65536.0F);
  }

  /* Saturate: '<Root>/Saturation1' */
  if (q_Bbi[1] > single_qc_ppid_P.Saturation1_UpperSat) {
    ftz = single_qc_ppid_P.Saturation1_UpperSat;
  } else if (q_Bbi[1] < single_qc_ppid_P.Saturation1_LowerSat) {
    ftz = single_qc_ppid_P.Saturation1_LowerSat;
  } else {
    ftz = q_Bbi[1];
  }

  /* DataTypeConversion: '<Root>/Data Type Conversion2' */
  rtb_newvalue_g = floorf(ftz);
  if (rtIsNaNF(rtb_newvalue_g) || rtIsInfF(rtb_newvalue_g)) {
    rtb_newvalue_g = 0.0F;
  } else {
    rtb_newvalue_g = fmodf(rtb_newvalue_g, 65536.0F);
  }

  /* Saturate: '<Root>/Saturation1' */
  if (q_Bbi[2] > single_qc_ppid_P.Saturation1_UpperSat) {
    ftz = single_qc_ppid_P.Saturation1_UpperSat;
  } else if (q_Bbi[2] < single_qc_ppid_P.Saturation1_LowerSat) {
    ftz = single_qc_ppid_P.Saturation1_LowerSat;
  } else {
    ftz = q_Bbi[2];
  }

  /* DataTypeConversion: '<Root>/Data Type Conversion2' */
  fty = floorf(ftz);
  if (rtIsNaNF(fty) || rtIsInfF(fty)) {
    fty = 0.0F;
  } else {
    fty = fmodf(fty, 65536.0F);
  }

  /* Saturate: '<Root>/Saturation1' */
  if (q_Bbi[3] > single_qc_ppid_P.Saturation1_UpperSat) {
    ftz = single_qc_ppid_P.Saturation1_UpperSat;
  } else if (q_Bbi[3] < single_qc_ppid_P.Saturation1_LowerSat) {
    ftz = single_qc_ppid_P.Saturation1_LowerSat;
  } else {
    ftz = q_Bbi[3];
  }

  /* DataTypeConversion: '<Root>/Data Type Conversion2' */
  ftz = floorf(ftz);
  if (rtIsNaNF(ftz) || rtIsInfF(ftz)) {
    ftz = 0.0F;
  } else {
    ftz = fmodf(ftz, 65536.0F);
  }

  /* Outport: '<Root>/m1' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion2'
   */
  single_qc_ppid_Y.m1 = (uint16_T)(f3 < 0.0F ? (int32_T)(uint16_T)-(int16_T)
    (uint16_T)-f3 : (int32_T)(uint16_T)f3);

  /* Outport: '<Root>/m2' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion2'
   */
  single_qc_ppid_Y.m2 = (uint16_T)(rtb_newvalue_g < 0.0F ? (int32_T)(uint16_T)
    -(int16_T)(uint16_T)-rtb_newvalue_g : (int32_T)(uint16_T)rtb_newvalue_g);

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
  single_qc_ppid_Y.t_m1 = q_Bbi[0];

  /* Outport: '<Root>/t_m2' */
  single_qc_ppid_Y.t_m2 = q_Bbi[1];

  /* Outport: '<Root>/t_m3' */
  single_qc_ppid_Y.t_m3 = q_Bbi[2];

  /* Outport: '<Root>/t_m4' */
  single_qc_ppid_Y.t_m4 = q_Bbi[3];

  /* Outport: '<Root>/u_beta' */
  single_qc_ppid_Y.u_beta = rtb_newvalue_h;

  /* MATLAB Function: '<S5>/MATLAB Function1' incorporates:
   *  RelationalOperator: '<S5>/IsNaN1'
   */
  single_qc_ppid_MATLABFunction(rtb_Sum4_b, rtIsNaNF(rtb_Sum4_b),
    &rtb_newvalue_g);

  /* Outport: '<Root>/error_betas' */
  single_qc_ppid_Y.error_betas = rtb_Sum3_b;

  /* MATLAB Function: '<S5>/MATLAB Function' incorporates:
   *  RelationalOperator: '<S5>/IsNaN'
   */
  single_qc_ppid_MATLABFunction(rtb_Sum_b, rtIsNaNF(rtb_Sum_b), &rtb_newvalue_h);

  /* Outport: '<Root>/error_beta' */
  single_qc_ppid_Y.error_beta = rtb_Sum1;

  /* Outport: '<Root>/u_alpha' */
  single_qc_ppid_Y.u_alpha = rtb_newvalue_d;

  /* MATLAB Function: '<S4>/MATLAB Function1' incorporates:
   *  RelationalOperator: '<S4>/IsNaN1'
   */
  single_qc_ppid_MATLABFunction(rtb_Sum4, rtIsNaNF(rtb_Sum4), &rtb_newvalue_d);

  /* Outport: '<Root>/error_alphas' */
  single_qc_ppid_Y.error_alphas = rtb_Sum3;

  /* Update for Memory: '<S4>/Memory' incorporates:
   *  MATLAB Function: '<S4>/MATLAB Function'
   *  RelationalOperator: '<S4>/IsNaN'
   */
  single_qc_ppid_MATLABFunction(rtb_Sum_p, rtIsNaNF(rtb_Sum_p),
    &single_qc_ppid_DW.Memory_PreviousInput);

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

  /* Update for Memory: '<S4>/Memory2' incorporates:
   *  Memory: '<S4>/Memory4'
   */
  single_qc_ppid_DW.Memory2_PreviousInput =
    single_qc_ppid_DW.Memory4_PreviousInput;

  /* Update for Memory: '<S4>/Memory1' */
  single_qc_ppid_DW.Memory1_PreviousInput = rtb_newvalue_d;

  /* Update for Memory: '<S4>/Memory3' incorporates:
   *  Memory: '<S4>/Memory5'
   */
  single_qc_ppid_DW.Memory3_PreviousInput =
    single_qc_ppid_DW.Memory5_PreviousInput;

  /* Update for Memory: '<S5>/Memory' */
  single_qc_ppid_DW.Memory_PreviousInput_n = rtb_newvalue_h;

  /* Update for Memory: '<S5>/Memory2' incorporates:
   *  Memory: '<S5>/Memory4'
   */
  single_qc_ppid_DW.Memory2_PreviousInput_m =
    single_qc_ppid_DW.Memory4_PreviousInput_g;

  /* Update for Memory: '<S5>/Memory1' */
  single_qc_ppid_DW.Memory1_PreviousInput_b = rtb_newvalue_g;

  /* Update for Memory: '<S5>/Memory3' incorporates:
   *  Memory: '<S5>/Memory5'
   */
  single_qc_ppid_DW.Memory3_PreviousInput_k =
    single_qc_ppid_DW.Memory5_PreviousInput_b;

  /* Update for Memory: '<S4>/Memory4' */
  single_qc_ppid_DW.Memory4_PreviousInput = rtb_Sum;

  /* Update for Memory: '<S4>/Memory5' */
  single_qc_ppid_DW.Memory5_PreviousInput = rtb_Sum3;

  /* Update for Memory: '<S5>/Memory4' */
  single_qc_ppid_DW.Memory4_PreviousInput_g = rtb_Sum1;

  /* Update for Memory: '<S5>/Memory5' */
  single_qc_ppid_DW.Memory5_PreviousInput_b = rtb_Sum3_b;
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

  /* InitializeConditions for Memory: '<S4>/Memory' */
  single_qc_ppid_DW.Memory_PreviousInput =
    single_qc_ppid_P.Memory_InitialCondition;

  /* InitializeConditions for Memory: '<S4>/Memory2' */
  single_qc_ppid_DW.Memory2_PreviousInput =
    single_qc_ppid_P.Memory2_InitialCondition;

  /* InitializeConditions for Memory: '<S4>/Memory1' */
  single_qc_ppid_DW.Memory1_PreviousInput =
    single_qc_ppid_P.Memory1_InitialCondition;

  /* InitializeConditions for Memory: '<S4>/Memory3' */
  single_qc_ppid_DW.Memory3_PreviousInput =
    single_qc_ppid_P.Memory3_InitialCondition;

  /* InitializeConditions for Memory: '<S5>/Memory' */
  single_qc_ppid_DW.Memory_PreviousInput_n =
    single_qc_ppid_P.Memory_InitialCondition_a;

  /* InitializeConditions for Memory: '<S5>/Memory2' */
  single_qc_ppid_DW.Memory2_PreviousInput_m =
    single_qc_ppid_P.Memory2_InitialCondition_c;

  /* InitializeConditions for Memory: '<S5>/Memory1' */
  single_qc_ppid_DW.Memory1_PreviousInput_b =
    single_qc_ppid_P.Memory1_InitialCondition_d;

  /* InitializeConditions for Memory: '<S5>/Memory3' */
  single_qc_ppid_DW.Memory3_PreviousInput_k =
    single_qc_ppid_P.Memory3_InitialCondition_o;

  /* InitializeConditions for Memory: '<S4>/Memory4' */
  single_qc_ppid_DW.Memory4_PreviousInput =
    single_qc_ppid_P.Memory4_InitialCondition;

  /* InitializeConditions for Memory: '<S4>/Memory5' */
  single_qc_ppid_DW.Memory5_PreviousInput =
    single_qc_ppid_P.Memory5_InitialCondition;

  /* InitializeConditions for Memory: '<S5>/Memory4' */
  single_qc_ppid_DW.Memory4_PreviousInput_g =
    single_qc_ppid_P.Memory4_InitialCondition_a;

  /* InitializeConditions for Memory: '<S5>/Memory5' */
  single_qc_ppid_DW.Memory5_PreviousInput_b =
    single_qc_ppid_P.Memory5_InitialCondition_p;
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

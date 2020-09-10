/*
 * File: single_qc_real.c
 *
 * Code generated for Simulink model 'single_qc_real'.
 *
 * Model version                  : 1.65
 * Simulink Coder version         : 9.3 (R2020a) 18-Nov-2019
 * C/C++ source code generated on : Thu Sep 10 10:12:16 2020
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objective: Execution efficiency
 * Validation result: Not run
 */

#include "single_qc_real.h"
#include "single_qc_real_private.h"

/* External inputs (root inport signals with default storage) */
ExtU_single_qc_real_T single_qc_real_U;

/* External outputs (root outports fed by signals with default storage) */
ExtY_single_qc_real_T single_qc_real_Y;

/* Forward declaration for local functions */
static void single_qc_real_quatmultiply(const real32_T q[4], const real32_T r[4],
  real32_T qout[4]);

/* Function for MATLAB Function: '<Root>/MATLAB Function' */
static void single_qc_real_quatmultiply(const real32_T q[4], const real32_T r[4],
  real32_T qout[4])
{
  qout[0] = ((q[0] * r[0] - q[1] * r[1]) - q[2] * r[2]) - q[3] * r[3];
  qout[1] = (q[0] * r[1] + r[0] * q[1]) + (q[2] * r[3] - q[3] * r[2]);
  qout[2] = (q[0] * r[2] + r[0] * q[2]) + (q[3] * r[1] - q[1] * r[3]);
  qout[3] = (q[0] * r[3] + r[0] * q[3]) + (q[1] * r[2] - q[2] * r[1]);
}

real32_T rt_atan2f_snf(real32_T u0, real32_T u1)
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
void single_qc_real_step(void)
{
  real32_T ftx;
  real32_T f0;
  real32_T f2;
  real32_T f3;
  real32_T q_bi[4];
  real32_T R_bii[9];
  real32_T tempR[9];
  int32_T d_k;
  real32_T rtb_motor_com[4];
  real32_T tmp[4];
  int8_T subsa_idx_1;
  real32_T f0_tmp;
  real32_T tempR_tmp;
  int32_T R_bii_tmp;
  static const real32_T b[4] = { 0.707106769F, 0.0F, 0.0F, 0.707106769F };

  static const real32_T c[4] = { -0.707106769F, 0.0F, 0.0F, 0.707106769F };

  real32_T tmp_0[4];

  /* Saturate: '<Root>/Saturation' incorporates:
   *  Inport: '<Root>/thrust'
   */
  if (single_qc_real_U.thrust > single_qc_real_P.Saturation_UpperSat) {
    f3 = single_qc_real_P.Saturation_UpperSat;
  } else if (single_qc_real_U.thrust < single_qc_real_P.Saturation_LowerSat) {
    f3 = single_qc_real_P.Saturation_LowerSat;
  } else {
    f3 = single_qc_real_U.thrust;
  }

  /* End of Saturate: '<Root>/Saturation' */

  /* MATLAB Function: '<Root>/MATLAB Function1' incorporates:
   *  Inport: '<Root>/alpha_desired'
   */
  f3 /= 4.0F;
  ftx = single_qc_real_U.alpha_desired / 4.0F / 0.03165F;
  f0_tmp = f3 + ftx;
  f0 = f0_tmp;
  f2 = f3 - ftx;
  ftx = f2;
  f3 = f0_tmp;
  if (f0_tmp < 0.0F) {
    f0 = 0.0F;
  }

  if (f2 < 0.0F) {
    ftx = 0.0F;
    f2 = 0.0F;
  }

  if (f0_tmp < 0.0F) {
    f3 = 0.0F;
  }

  rtb_motor_com[0] = (sqrtf(0.366F * f0 + 0.00457922881F) + -0.06767F) / 0.183F *
    65535.0F;
  rtb_motor_com[1] = (sqrtf(0.366F * ftx + 0.00457922881F) + -0.06767F) / 0.183F
    * 65535.0F;
  rtb_motor_com[2] = (sqrtf(0.366F * f2 + 0.00457922881F) + -0.06767F) / 0.183F *
    65535.0F;
  rtb_motor_com[3] = (sqrtf(0.366F * f3 + 0.00457922881F) + -0.06767F) / 0.183F *
    65535.0F;

  /* End of MATLAB Function: '<Root>/MATLAB Function1' */

  /* Saturate: '<Root>/Saturation1' */
  if (rtb_motor_com[0] > single_qc_real_P.Saturation1_UpperSat) {
    ftx = single_qc_real_P.Saturation1_UpperSat;
  } else if (rtb_motor_com[0] < single_qc_real_P.Saturation1_LowerSat) {
    ftx = single_qc_real_P.Saturation1_LowerSat;
  } else {
    ftx = rtb_motor_com[0];
  }

  /* DataTypeConversion: '<Root>/Data Type Conversion2' */
  f3 = floorf(ftx);
  if (rtIsNaNF(f3) || rtIsInfF(f3)) {
    f3 = 0.0F;
  } else {
    f3 = fmodf(f3, 65536.0F);
  }

  /* Saturate: '<Root>/Saturation1' */
  if (rtb_motor_com[1] > single_qc_real_P.Saturation1_UpperSat) {
    ftx = single_qc_real_P.Saturation1_UpperSat;
  } else if (rtb_motor_com[1] < single_qc_real_P.Saturation1_LowerSat) {
    ftx = single_qc_real_P.Saturation1_LowerSat;
  } else {
    ftx = rtb_motor_com[1];
  }

  /* DataTypeConversion: '<Root>/Data Type Conversion2' */
  f0_tmp = floorf(ftx);
  if (rtIsNaNF(f0_tmp) || rtIsInfF(f0_tmp)) {
    f0_tmp = 0.0F;
  } else {
    f0_tmp = fmodf(f0_tmp, 65536.0F);
  }

  /* Saturate: '<Root>/Saturation1' */
  if (rtb_motor_com[2] > single_qc_real_P.Saturation1_UpperSat) {
    ftx = single_qc_real_P.Saturation1_UpperSat;
  } else if (rtb_motor_com[2] < single_qc_real_P.Saturation1_LowerSat) {
    ftx = single_qc_real_P.Saturation1_LowerSat;
  } else {
    ftx = rtb_motor_com[2];
  }

  /* DataTypeConversion: '<Root>/Data Type Conversion2' */
  f0 = floorf(ftx);
  if (rtIsNaNF(f0) || rtIsInfF(f0)) {
    f0 = 0.0F;
  } else {
    f0 = fmodf(f0, 65536.0F);
  }

  /* Saturate: '<Root>/Saturation1' */
  if (rtb_motor_com[3] > single_qc_real_P.Saturation1_UpperSat) {
    ftx = single_qc_real_P.Saturation1_UpperSat;
  } else if (rtb_motor_com[3] < single_qc_real_P.Saturation1_LowerSat) {
    ftx = single_qc_real_P.Saturation1_LowerSat;
  } else {
    ftx = rtb_motor_com[3];
  }

  /* DataTypeConversion: '<Root>/Data Type Conversion2' */
  ftx = floorf(ftx);
  if (rtIsNaNF(ftx) || rtIsInfF(ftx)) {
    ftx = 0.0F;
  } else {
    ftx = fmodf(ftx, 65536.0F);
  }

  /* Outport: '<Root>/m1' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion2'
   */
  single_qc_real_Y.m1 = (uint16_T)(f3 < 0.0F ? (int32_T)(uint16_T)-(int16_T)
    (uint16_T)-f3 : (int32_T)(uint16_T)f3);

  /* Outport: '<Root>/m2' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion2'
   */
  single_qc_real_Y.m2 = (uint16_T)(f0_tmp < 0.0F ? (int32_T)(uint16_T)-(int16_T)
    (uint16_T)-f0_tmp : (int32_T)(uint16_T)f0_tmp);

  /* Outport: '<Root>/m3' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion2'
   */
  single_qc_real_Y.m3 = (uint16_T)(f0 < 0.0F ? (int32_T)(uint16_T)-(int16_T)
    (uint16_T)-f0 : (int32_T)(uint16_T)f0);

  /* Outport: '<Root>/m4' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion2'
   */
  single_qc_real_Y.m4 = (uint16_T)(ftx < 0.0F ? (int32_T)(uint16_T)-(int16_T)
    (uint16_T)-ftx : (int32_T)(uint16_T)ftx);

  /* Outport: '<Root>/t_m1' */
  single_qc_real_Y.t_m1 = rtb_motor_com[0];

  /* Outport: '<Root>/t_m2' */
  single_qc_real_Y.t_m2 = rtb_motor_com[1];

  /* Outport: '<Root>/t_m3' */
  single_qc_real_Y.t_m3 = rtb_motor_com[2];

  /* Outport: '<Root>/t_m4' */
  single_qc_real_Y.t_m4 = rtb_motor_com[3];

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
  f3 = single_qc_real_U.index * 3.14159274F / 4.0F;
  rtb_motor_com[0] = cosf(f3);
  rtb_motor_com[1] = 0.0F;
  rtb_motor_com[2] = 0.0F;
  rtb_motor_com[3] = sinf(f3);
  tmp[0] = single_qc_real_U.qw_op;
  tmp[1] = single_qc_real_U.qx_op;
  tmp[2] = single_qc_real_U.qy_op;
  tmp[3] = single_qc_real_U.qz_op;
  q_bi[0] = -rtb_motor_com[0];
  q_bi[1] = 0.0F;
  q_bi[2] = 0.0F;
  q_bi[3] = rtb_motor_com[3];
  single_qc_real_quatmultiply(tmp, q_bi, tmp_0);
  single_qc_real_quatmultiply(rtb_motor_com, tmp_0, q_bi);
  tmp[0] = single_qc_real_U.qw_IMU;
  tmp[1] = single_qc_real_U.qx_IMU;
  tmp[2] = single_qc_real_U.qy_IMU;
  tmp[3] = single_qc_real_U.qz_IMU;
  rtb_motor_com[0] = -q_bi[0];
  rtb_motor_com[1] = q_bi[1];
  rtb_motor_com[2] = q_bi[2];
  rtb_motor_com[3] = q_bi[3];
  single_qc_real_quatmultiply(tmp, c, tmp_0);
  single_qc_real_quatmultiply(b, tmp_0, tmp);
  single_qc_real_quatmultiply(tmp, rtb_motor_com, q_bi);
  f0 = 1.0F / sqrtf(((q_bi[0] * q_bi[0] + q_bi[1] * q_bi[1]) + q_bi[2] * q_bi[2])
                    + q_bi[3] * q_bi[3]);
  rtb_motor_com[0] = q_bi[0] * f0;
  rtb_motor_com[1] = q_bi[1] * f0;
  rtb_motor_com[2] = q_bi[2] * f0;
  rtb_motor_com[3] = q_bi[3] * f0;
  f3 = rtb_motor_com[3] * rtb_motor_com[3];
  f0_tmp = rtb_motor_com[2] * rtb_motor_com[2];
  tempR[0] = 1.0F - (f0_tmp + f3) * 2.0F;
  f0 = rtb_motor_com[1] * rtb_motor_com[2];
  ftx = rtb_motor_com[0] * rtb_motor_com[3];
  tempR[1] = (f0 - ftx) * 2.0F;
  f2 = rtb_motor_com[1] * rtb_motor_com[3];
  tempR_tmp = rtb_motor_com[0] * rtb_motor_com[2];
  tempR[2] = (f2 + tempR_tmp) * 2.0F;
  tempR[3] = (f0 + ftx) * 2.0F;
  f0 = rtb_motor_com[1] * rtb_motor_com[1];
  tempR[4] = 1.0F - (f0 + f3) * 2.0F;
  f3 = rtb_motor_com[2] * rtb_motor_com[3];
  ftx = rtb_motor_com[0] * rtb_motor_com[1];
  tempR[5] = (f3 - ftx) * 2.0F;
  tempR[6] = (f2 - tempR_tmp) * 2.0F;
  tempR[7] = (f3 + ftx) * 2.0F;
  tempR[8] = 1.0F - (f0 + f0_tmp) * 2.0F;
  for (d_k = 0; d_k < 3; d_k++) {
    R_bii_tmp = (int8_T)(d_k + 1) - 1;
    R_bii[R_bii_tmp] = tempR[R_bii_tmp * 3];
    subsa_idx_1 = (int8_T)(d_k + 1);
    R_bii[subsa_idx_1 + 2] = tempR[(subsa_idx_1 - 1) * 3 + 1];
    subsa_idx_1 = (int8_T)(d_k + 1);
    R_bii[subsa_idx_1 + 5] = tempR[(subsa_idx_1 - 1) * 3 + 2];
  }

  /* Outport: '<Root>/t_betae' incorporates:
   *  MATLAB Function: '<Root>/MATLAB Function'
   */
  single_qc_real_Y.t_betae = rt_atan2f_snf(R_bii[6], R_bii[0]);

  /* Outport: '<Root>/t_alphae' incorporates:
   *  MATLAB Function: '<Root>/MATLAB Function'
   */
  single_qc_real_Y.t_alphae = rt_atan2f_snf(-R_bii[7], R_bii[8]);

  /* Outport: '<Root>/t_betain' incorporates:
   *  Inport: '<Root>/beta_desired'
   */
  single_qc_real_Y.t_betain = single_qc_real_U.beta_desired;
}

/* Model initialize function */
void single_qc_real_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* external inputs */
  (void)memset(&single_qc_real_U, 0, sizeof(ExtU_single_qc_real_T));

  /* external outputs */
  (void) memset((void *)&single_qc_real_Y, 0,
                sizeof(ExtY_single_qc_real_T));
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

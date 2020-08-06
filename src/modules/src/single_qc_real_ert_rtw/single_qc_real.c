/*
 * File: single_qc_real.c
 *
 * Code generated for Simulink model 'single_qc_real'.
 *
 * Model version                  : 1.45
 * Simulink Coder version         : 9.3 (R2020a) 18-Nov-2019
 * C/C++ source code generated on : Wed Aug  5 21:01:58 2020
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
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

/* Model step function */
void single_qc_real_step(void)
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
  real32_T rtb_Sum2;
  real32_T rtb_Sum1;
  real32_T rtb_Sum_p;
  real32_T rtb_beta_e;
  real32_T rtb_alpha_e;
  real32_T rtb_Sum;
  real32_T rtb_TSamp;
  real32_T rtb_Sum2_p;
  real32_T rtb_Sum_c;
  real32_T rtb_TSamp_n;
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
  thrust = single_qc_real_U.index * 3.14159274F / 4.0F;
  tmp[0] = cosf(thrust);
  tmp[1] = 0.0F;
  tmp[2] = 0.0F;
  tmp[3] = sinf(thrust);
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
  single_qc_real_quatmultiply(tmp, c, q_bi);
  single_qc_real_quatmultiply(b, q_bi, tmp);
  single_qc_real_quatmultiply(tmp, q_bi_0, q_bii);
  rtb_alpha_e = 1.0F / sqrtf(((q_bii[0] * q_bii[0] + q_bii[1] * q_bii[1]) +
    q_bii[2] * q_bii[2]) + q_bii[3] * q_bii[3]);
  q_bi[0] = q_bii[0] * rtb_alpha_e;
  q_bi[1] = q_bii[1] * rtb_alpha_e;
  q_bi[2] = q_bii[2] * rtb_alpha_e;
  q_bi[3] = q_bii[3] * rtb_alpha_e;
  rtb_alpha_e = q_bi[3] * q_bi[3];
  rtb_beta_e = q_bi[2] * q_bi[2];
  tempR[0] = 1.0F - (rtb_beta_e + rtb_alpha_e) * 2.0F;
  rtb_Sum_p = q_bi[1] * q_bi[2];
  rtb_Sum = q_bi[0] * q_bi[3];
  tempR[1] = (rtb_Sum_p - rtb_Sum) * 2.0F;
  rtb_TSamp = q_bi[1] * q_bi[3];
  rtb_Sum2 = q_bi[0] * q_bi[2];
  tempR[2] = (rtb_TSamp + rtb_Sum2) * 2.0F;
  tempR[3] = (rtb_Sum_p + rtb_Sum) * 2.0F;
  rtb_Sum_p = q_bi[1] * q_bi[1];
  tempR[4] = 1.0F - (rtb_Sum_p + rtb_alpha_e) * 2.0F;
  rtb_alpha_e = q_bi[2] * q_bi[3];
  rtb_Sum = q_bi[0] * q_bi[1];
  tempR[5] = (rtb_alpha_e - rtb_Sum) * 2.0F;
  tempR[6] = (rtb_TSamp - rtb_Sum2) * 2.0F;
  tempR[7] = (rtb_alpha_e + rtb_Sum) * 2.0F;
  tempR[8] = 1.0F - (rtb_Sum_p + rtb_beta_e) * 2.0F;
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
  rtb_Sum_p = single_qc_real_U.alpha_desired - rtb_alpha_e;

  /* Sum: '<S4>/Sum' incorporates:
   *  Memory: '<S4>/Memory'
   */
  rtb_Sum = single_qc_real_DW.Memory_PreviousInput + rtb_Sum_p;

  /* SampleTimeMath: '<S6>/TSamp'
   *
   * About '<S6>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   */
  rtb_TSamp = rtb_Sum_p * single_qc_real_P.TSamp_WtEt;

  /* Sum: '<S4>/Sum2' incorporates:
   *  Gain: '<S4>/dgain'
   *  Gain: '<S4>/igain'
   *  Gain: '<S4>/pgain'
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
  rtb_Sum2 = (single_qc_real_P.pgaina * rtb_Sum_p + single_qc_real_P.igaina *
              rtb_Sum) + (rtb_TSamp - single_qc_real_DW.UD_DSTATE) *
    single_qc_real_P.dgaina;

  /* Sum: '<S3>/Sum1' incorporates:
   *  Inport: '<Root>/beta_desired'
   */
  rtb_Sum1 = single_qc_real_U.beta_desired - rtb_beta_e;

  /* Sum: '<S5>/Sum' incorporates:
   *  Memory: '<S5>/Memory'
   */
  rtb_Sum_c = single_qc_real_DW.Memory_PreviousInput_d + rtb_Sum1;

  /* SampleTimeMath: '<S7>/TSamp'
   *
   * About '<S7>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   */
  rtb_TSamp_n = rtb_Sum1 * single_qc_real_P.TSamp_WtEt_o;

  /* Sum: '<S5>/Sum2' incorporates:
   *  Gain: '<S5>/dgain'
   *  Gain: '<S5>/igain'
   *  Gain: '<S5>/pgain'
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
  rtb_Sum2_p = (single_qc_real_P.pgainb * rtb_Sum1 + single_qc_real_P.igainb *
                rtb_Sum_c) + (rtb_TSamp_n - single_qc_real_DW.UD_DSTATE_l) *
    single_qc_real_P.dgainb;

  /* Gain: '<Root>/Gain' incorporates:
   *  Inport: '<Root>/thrust'
   */
  ftz = single_qc_real_P.Gain_Gain * single_qc_real_U.thrust;

  /* Saturate: '<Root>/Saturation' */
  if (ftz > single_qc_real_P.Saturation_UpperSat) {
    ftz = single_qc_real_P.Saturation_UpperSat;
  } else {
    if (ftz < single_qc_real_P.Saturation_LowerSat) {
      ftz = single_qc_real_P.Saturation_LowerSat;
    }
  }

  /* End of Saturate: '<Root>/Saturation' */

  /* MATLAB Function: '<Root>/MATLAB Function1' */
  thrust = ftz / 4.0F;

  /* Product: '<S3>/Product' incorporates:
   *  Trigonometry: '<S3>/Trigonometric Function1'
   */
  ftz = cosf(rtb_beta_e) * rtb_Sum2;

  /* Saturate: '<S3>/Saturation' */
  if (ftz > single_qc_real_P.sat_tx) {
    ftz = single_qc_real_P.sat_tx;
  } else {
    if (ftz < -single_qc_real_P.sat_tx) {
      ftz = -single_qc_real_P.sat_tx;
    }
  }

  /* End of Saturate: '<S3>/Saturation' */

  /* MATLAB Function: '<Root>/MATLAB Function1' */
  ftx = ftz / 4.0F / 0.03165F;

  /* Saturate: '<S3>/Saturation1' */
  if (rtb_Sum2_p > single_qc_real_P.sat_ty) {
    fty = single_qc_real_P.sat_ty;
  } else if (rtb_Sum2_p < -single_qc_real_P.sat_ty) {
    fty = -single_qc_real_P.sat_ty;
  } else {
    fty = rtb_Sum2_p;
  }

  /* End of Saturate: '<S3>/Saturation1' */

  /* MATLAB Function: '<Root>/MATLAB Function1' */
  fty = fty / 4.0F / 0.03165F;

  /* Product: '<S3>/Product1' incorporates:
   *  Trigonometry: '<S3>/Trigonometric Function'
   */
  ftz = rtb_Sum2 * sinf(rtb_beta_e);

  /* Saturate: '<S3>/Saturation2' */
  if (ftz > single_qc_real_P.sat_tz) {
    ftz = single_qc_real_P.sat_tz;
  } else {
    if (ftz < -single_qc_real_P.sat_tz) {
      ftz = -single_qc_real_P.sat_tz;
    }
  }

  /* End of Saturate: '<S3>/Saturation2' */

  /* MATLAB Function: '<Root>/MATLAB Function1' incorporates:
   *  Constant: '<Root>/Constant'
   */
  ftz = ftz / 4.0F / 0.03165F * single_qc_real_P.torque_modifier;
  q_bi_tmp = thrust + ftx;
  q_bi[0] = ((q_bi_tmp - fty) - ftz) / 0.1472F * 65535.0F;
  thrust -= ftx;
  q_bi[1] = ((thrust - fty) + ftz) / 0.1472F * 65535.0F;
  q_bi[2] = ((thrust + fty) - ftz) / 0.1472F * 65535.0F;
  q_bi[3] = ((q_bi_tmp + fty) + ftz) / 0.1472F * 65535.0F;

  /* Saturate: '<Root>/Saturation1' */
  if (q_bi[0] > single_qc_real_P.Saturation1_UpperSat) {
    ftz = single_qc_real_P.Saturation1_UpperSat;
  } else if (q_bi[0] < single_qc_real_P.Saturation1_LowerSat) {
    ftz = single_qc_real_P.Saturation1_LowerSat;
  } else {
    ftz = q_bi[0];
  }

  /* DataTypeConversion: '<Root>/Data Type Conversion2' */
  thrust = fmodf(floorf(ftz), 65536.0F);

  /* Saturate: '<Root>/Saturation1' */
  if (q_bi[1] > single_qc_real_P.Saturation1_UpperSat) {
    ftz = single_qc_real_P.Saturation1_UpperSat;
  } else if (q_bi[1] < single_qc_real_P.Saturation1_LowerSat) {
    ftz = single_qc_real_P.Saturation1_LowerSat;
  } else {
    ftz = q_bi[1];
  }

  /* DataTypeConversion: '<Root>/Data Type Conversion2' */
  ftx = fmodf(floorf(ftz), 65536.0F);

  /* Saturate: '<Root>/Saturation1' */
  if (q_bi[2] > single_qc_real_P.Saturation1_UpperSat) {
    ftz = single_qc_real_P.Saturation1_UpperSat;
  } else if (q_bi[2] < single_qc_real_P.Saturation1_LowerSat) {
    ftz = single_qc_real_P.Saturation1_LowerSat;
  } else {
    ftz = q_bi[2];
  }

  /* DataTypeConversion: '<Root>/Data Type Conversion2' */
  fty = fmodf(floorf(ftz), 65536.0F);

  /* Saturate: '<Root>/Saturation1' */
  if (q_bi[3] > single_qc_real_P.Saturation1_UpperSat) {
    ftz = single_qc_real_P.Saturation1_UpperSat;
  } else if (q_bi[3] < single_qc_real_P.Saturation1_LowerSat) {
    ftz = single_qc_real_P.Saturation1_LowerSat;
  } else {
    ftz = q_bi[3];
  }

  /* DataTypeConversion: '<Root>/Data Type Conversion2' */
  ftz = fmodf(floorf(ftz), 65536.0F);

  /* Outport: '<Root>/m1' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion2'
   */
  single_qc_real_Y.m1 = (uint16_T)(thrust < 0.0F ? (int32_T)(uint16_T)-(int16_T)
    (uint16_T)-thrust : (int32_T)(uint16_T)thrust);

  /* Outport: '<Root>/m2' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion2'
   */
  single_qc_real_Y.m2 = (uint16_T)(ftx < 0.0F ? (int32_T)(uint16_T)-(int16_T)
    (uint16_T)-ftx : (int32_T)(uint16_T)ftx);

  /* Outport: '<Root>/m3' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion2'
   */
  single_qc_real_Y.m3 = (uint16_T)(fty < 0.0F ? (int32_T)(uint16_T)-(int16_T)
    (uint16_T)-fty : (int32_T)(uint16_T)fty);

  /* Outport: '<Root>/m4' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion2'
   */
  single_qc_real_Y.m4 = (uint16_T)(ftz < 0.0F ? (int32_T)(uint16_T)-(int16_T)
    (uint16_T)-ftz : (int32_T)(uint16_T)ftz);

  /* Outport: '<Root>/t_m1' */
  single_qc_real_Y.t_m1 = q_bi[0];

  /* Outport: '<Root>/t_m2' */
  single_qc_real_Y.t_m2 = q_bi[1];

  /* Outport: '<Root>/t_m3' */
  single_qc_real_Y.t_m3 = q_bi[2];

  /* Outport: '<Root>/t_m4' */
  single_qc_real_Y.t_m4 = q_bi[3];

  /* Outport: '<Root>/u_beta' */
  single_qc_real_Y.u_beta = rtb_Sum2_p;

  /* Outport: '<Root>/error_beta' */
  single_qc_real_Y.error_beta = rtb_Sum1;

  /* Outport: '<Root>/u_alpha' */
  single_qc_real_Y.u_alpha = rtb_Sum2;

  /* Outport: '<Root>/error_alpha' */
  single_qc_real_Y.error_alpha = rtb_Sum_p;

  /* Outport: '<Root>/t_betae' */
  single_qc_real_Y.t_betae = rtb_beta_e;

  /* Outport: '<Root>/t_alphae' */
  single_qc_real_Y.t_alphae = rtb_alpha_e;

  /* Outport: '<Root>/t_betain' incorporates:
   *  Inport: '<Root>/beta_desired'
   */
  single_qc_real_Y.t_betain = single_qc_real_U.beta_desired;

  /* Outport: '<Root>/t_alphain' incorporates:
   *  Inport: '<Root>/alpha_desired'
   */
  single_qc_real_Y.t_alphain = single_qc_real_U.alpha_desired;

  /* Update for Memory: '<S4>/Memory' */
  single_qc_real_DW.Memory_PreviousInput = rtb_Sum;

  /* Update for UnitDelay: '<S6>/UD'
   *
   * Block description for '<S6>/UD':
   *
   *  Store in Global RAM
   */
  single_qc_real_DW.UD_DSTATE = rtb_TSamp;

  /* Update for Memory: '<S5>/Memory' */
  single_qc_real_DW.Memory_PreviousInput_d = rtb_Sum_c;

  /* Update for UnitDelay: '<S7>/UD'
   *
   * Block description for '<S7>/UD':
   *
   *  Store in Global RAM
   */
  single_qc_real_DW.UD_DSTATE_l = rtb_TSamp_n;
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

  /* InitializeConditions for Memory: '<S4>/Memory' */
  single_qc_real_DW.Memory_PreviousInput =
    single_qc_real_P.Memory_InitialCondition;

  /* InitializeConditions for UnitDelay: '<S6>/UD'
   *
   * Block description for '<S6>/UD':
   *
   *  Store in Global RAM
   */
  single_qc_real_DW.UD_DSTATE = single_qc_real_P.DiscreteDerivative2_ICPrevScale;

  /* InitializeConditions for Memory: '<S5>/Memory' */
  single_qc_real_DW.Memory_PreviousInput_d =
    single_qc_real_P.Memory_InitialCondition_g;

  /* InitializeConditions for UnitDelay: '<S7>/UD'
   *
   * Block description for '<S7>/UD':
   *
   *  Store in Global RAM
   */
  single_qc_real_DW.UD_DSTATE_l =
    single_qc_real_P.DiscreteDerivative2_ICPrevSca_h;
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

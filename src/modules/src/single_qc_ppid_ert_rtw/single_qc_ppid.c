/*
 * File: single_qc_ppid.c
 *
 * Code generated for Simulink model 'single_qc_ppid'.
 *
 * Model version                  : 1.95
 * Simulink Coder version         : 9.3 (R2020a) 18-Nov-2019
 * C/C++ source code generated on : Tue Nov 24 16:52:14 2020
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objective: Execution efficiency
 * Validation result: Not run
 */

#include "single_qc_ppid.h"
#include "single_qc_ppid_private.h"

/* External inputs (root inport signals with default storage) */
ExtU_single_qc_ppid_T single_qc_ppid_U;

/* External outputs (root outports fed by signals with default storage) */
ExtY_single_qc_ppid_T single_qc_ppid_Y;

/* Model step function */
void single_qc_ppid_step(void)
{
  real32_T thrust;
  real32_T t_z;
  real32_T rtb_motor_com_idx_1;
  real32_T rtb_motor_com_idx_2;
  real32_T rtb_motor_com_idx_3;
  real32_T rtb_motor_com_idx_0_tmp;

  /* Saturate: '<Root>/Saturation' incorporates:
   *  Inport: '<Root>/thrust'
   */
  if (single_qc_ppid_U.thrust > single_qc_ppid_P.Saturation_UpperSat) {
    t_z = single_qc_ppid_P.Saturation_UpperSat;
  } else if (single_qc_ppid_U.thrust < single_qc_ppid_P.Saturation_LowerSat) {
    t_z = single_qc_ppid_P.Saturation_LowerSat;
  } else {
    t_z = single_qc_ppid_U.thrust;
  }

  /* End of Saturate: '<Root>/Saturation' */

  /* MATLAB Function: '<Root>/MATLAB Function' incorporates:
   *  Inport: '<Root>/alpha_desired'
   */
  thrust = t_z / 4.0F;
  t_z = single_qc_ppid_U.alpha_desired / 4.0F / 0.00597F;
  rtb_motor_com_idx_0_tmp = (sqrtf((thrust - t_z) * 0.366F + 0.00457922881F) +
    -0.06767F) / 0.183F * 65535.0F;
  thrust = (sqrtf((thrust + t_z) * 0.366F + 0.00457922881F) + -0.06767F) /
    0.183F * 65535.0F;

  /* Saturate: '<Root>/Saturation1' incorporates:
   *  MATLAB Function: '<Root>/MATLAB Function'
   */
  if (rtb_motor_com_idx_0_tmp > single_qc_ppid_P.Saturation1_UpperSat) {
    t_z = single_qc_ppid_P.Saturation1_UpperSat;
  } else if (rtb_motor_com_idx_0_tmp < single_qc_ppid_P.Saturation1_LowerSat) {
    t_z = single_qc_ppid_P.Saturation1_LowerSat;
  } else {
    t_z = rtb_motor_com_idx_0_tmp;
  }

  /* DataTypeConversion: '<Root>/Data Type Conversion2' */
  t_z = floorf(t_z);
  if (rtIsNaNF(t_z) || rtIsInfF(t_z)) {
    t_z = 0.0F;
  } else {
    t_z = fmodf(t_z, 65536.0F);
  }

  /* Saturate: '<Root>/Saturation1' incorporates:
   *  MATLAB Function: '<Root>/MATLAB Function'
   */
  if (thrust > single_qc_ppid_P.Saturation1_UpperSat) {
    rtb_motor_com_idx_1 = single_qc_ppid_P.Saturation1_UpperSat;
  } else if (thrust < single_qc_ppid_P.Saturation1_LowerSat) {
    rtb_motor_com_idx_1 = single_qc_ppid_P.Saturation1_LowerSat;
  } else {
    rtb_motor_com_idx_1 = thrust;
  }

  /* DataTypeConversion: '<Root>/Data Type Conversion2' */
  rtb_motor_com_idx_1 = floorf(rtb_motor_com_idx_1);
  if (rtIsNaNF(rtb_motor_com_idx_1) || rtIsInfF(rtb_motor_com_idx_1)) {
    rtb_motor_com_idx_1 = 0.0F;
  } else {
    rtb_motor_com_idx_1 = fmodf(rtb_motor_com_idx_1, 65536.0F);
  }

  /* Saturate: '<Root>/Saturation1' */
  if (rtb_motor_com_idx_0_tmp > single_qc_ppid_P.Saturation1_UpperSat) {
    rtb_motor_com_idx_2 = single_qc_ppid_P.Saturation1_UpperSat;
  } else if (rtb_motor_com_idx_0_tmp < single_qc_ppid_P.Saturation1_LowerSat) {
    rtb_motor_com_idx_2 = single_qc_ppid_P.Saturation1_LowerSat;
  } else {
    rtb_motor_com_idx_2 = rtb_motor_com_idx_0_tmp;
  }

  /* DataTypeConversion: '<Root>/Data Type Conversion2' */
  rtb_motor_com_idx_2 = floorf(rtb_motor_com_idx_2);
  if (rtIsNaNF(rtb_motor_com_idx_2) || rtIsInfF(rtb_motor_com_idx_2)) {
    rtb_motor_com_idx_2 = 0.0F;
  } else {
    rtb_motor_com_idx_2 = fmodf(rtb_motor_com_idx_2, 65536.0F);
  }

  /* Saturate: '<Root>/Saturation1' */
  if (thrust > single_qc_ppid_P.Saturation1_UpperSat) {
    rtb_motor_com_idx_3 = single_qc_ppid_P.Saturation1_UpperSat;
  } else if (thrust < single_qc_ppid_P.Saturation1_LowerSat) {
    rtb_motor_com_idx_3 = single_qc_ppid_P.Saturation1_LowerSat;
  } else {
    rtb_motor_com_idx_3 = thrust;
  }

  /* DataTypeConversion: '<Root>/Data Type Conversion2' */
  rtb_motor_com_idx_3 = floorf(rtb_motor_com_idx_3);
  if (rtIsNaNF(rtb_motor_com_idx_3) || rtIsInfF(rtb_motor_com_idx_3)) {
    rtb_motor_com_idx_3 = 0.0F;
  } else {
    rtb_motor_com_idx_3 = fmodf(rtb_motor_com_idx_3, 65536.0F);
  }

  /* Outport: '<Root>/m1' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion2'
   */
  single_qc_ppid_Y.m1 = (uint16_T)(t_z < 0.0F ? (int32_T)(uint16_T)-(int16_T)
    (uint16_T)-t_z : (int32_T)(uint16_T)t_z);

  /* Outport: '<Root>/m2' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion2'
   */
  single_qc_ppid_Y.m2 = (uint16_T)(rtb_motor_com_idx_1 < 0.0F ? (int32_T)
    (uint16_T)-(int16_T)(uint16_T)-rtb_motor_com_idx_1 : (int32_T)(uint16_T)
    rtb_motor_com_idx_1);

  /* Outport: '<Root>/m3' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion2'
   */
  single_qc_ppid_Y.m3 = (uint16_T)(rtb_motor_com_idx_2 < 0.0F ? (int32_T)
    (uint16_T)-(int16_T)(uint16_T)-rtb_motor_com_idx_2 : (int32_T)(uint16_T)
    rtb_motor_com_idx_2);

  /* Outport: '<Root>/m4' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion2'
   */
  single_qc_ppid_Y.m4 = (uint16_T)(rtb_motor_com_idx_3 < 0.0F ? (int32_T)
    (uint16_T)-(int16_T)(uint16_T)-rtb_motor_com_idx_3 : (int32_T)(uint16_T)
    rtb_motor_com_idx_3);

  /* Outport: '<Root>/t_m1' incorporates:
   *  MATLAB Function: '<Root>/MATLAB Function'
   */
  single_qc_ppid_Y.t_m1 = rtb_motor_com_idx_0_tmp;

  /* Outport: '<Root>/t_m2' incorporates:
   *  MATLAB Function: '<Root>/MATLAB Function'
   */
  single_qc_ppid_Y.t_m2 = thrust;

  /* Outport: '<Root>/t_m3' */
  single_qc_ppid_Y.t_m3 = rtb_motor_com_idx_0_tmp;

  /* Outport: '<Root>/t_m4' */
  single_qc_ppid_Y.t_m4 = thrust;

  /* Outport: '<Root>/error_alpha' incorporates:
   *  Constant: '<Root>/Constant'
   */
  single_qc_ppid_Y.error_alpha = single_qc_ppid_P.Constant_Value;

  /* Outport: '<Root>/error_beta' incorporates:
   *  Constant: '<Root>/Constant'
   */
  single_qc_ppid_Y.error_beta = single_qc_ppid_P.Constant_Value;

  /* Outport: '<Root>/u_alpha' incorporates:
   *  Constant: '<Root>/Constant'
   */
  single_qc_ppid_Y.u_alpha = single_qc_ppid_P.Constant_Value;

  /* Outport: '<Root>/u_beta' incorporates:
   *  Constant: '<Root>/Constant'
   */
  single_qc_ppid_Y.u_beta = single_qc_ppid_P.Constant_Value;

  /* Outport: '<Root>/t_betae' incorporates:
   *  Constant: '<Root>/Constant'
   */
  single_qc_ppid_Y.t_betae = single_qc_ppid_P.Constant_Value;

  /* Outport: '<Root>/t_alphae' incorporates:
   *  Constant: '<Root>/Constant'
   */
  single_qc_ppid_Y.t_alphae = single_qc_ppid_P.Constant_Value;

  /* Outport: '<Root>/error_alphas' incorporates:
   *  Constant: '<Root>/Constant'
   */
  single_qc_ppid_Y.error_alphas = single_qc_ppid_P.Constant_Value;

  /* Outport: '<Root>/error_betas' incorporates:
   *  Constant: '<Root>/Constant'
   */
  single_qc_ppid_Y.error_betas = single_qc_ppid_P.Constant_Value;

  /* Outport: '<Root>/t_alphain' incorporates:
   *  Inport: '<Root>/alpha_desired'
   */
  single_qc_ppid_Y.t_alphain = single_qc_ppid_U.alpha_desired;

  /* Outport: '<Root>/t_betain' incorporates:
   *  Inport: '<Root>/beta_desired'
   */
  single_qc_ppid_Y.t_betain = single_qc_ppid_U.beta_desired;
}

/* Model initialize function */
void single_qc_ppid_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* external inputs */
  (void)memset(&single_qc_ppid_U, 0, sizeof(ExtU_single_qc_ppid_T));

  /* external outputs */
  (void) memset((void *)&single_qc_ppid_Y, 0,
                sizeof(ExtY_single_qc_ppid_T));
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

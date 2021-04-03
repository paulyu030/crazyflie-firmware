/*
 * File: Quaternion_single_axis_controller.c
 *
 * Code generated for Simulink model 'Quaternion_single_axis_controller'.
 *
 * Model version                  : 1.119
 * Simulink Coder version         : 9.3 (R2020a) 18-Nov-2019
 * C/C++ source code generated on : Sat Apr  3 15:49:36 2021
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Quaternion_single_axis_controller.h"
#include "Quaternion_single_axis_controller_private.h"

/* Block states (default storage) */
DW_Quaternion_single_axis_con_T Quaternion_single_axis_contr_DW;

/* External inputs (root inport signals with default storage) */
ExtU_Quaternion_single_axis_c_T Quaternion_single_axis_contro_U;

/* External outputs (root outports fed by signals with default storage) */
ExtY_Quaternion_single_axis_c_T Quaternion_single_axis_contro_Y;

/* Real-time model */
RT_MODEL_Quaternion_single_ax_T Quaternion_single_axis_contr_M_;
RT_MODEL_Quaternion_single_ax_T *const Quaternion_single_axis_contr_M =
  &Quaternion_single_axis_contr_M_;

/* Model step function */
void Quaternion_single_axis_controller_step(void)
{
  real32_T w;
  real32_T x;
  real32_T y;
  real32_T z;
  real32_T rtb_Saturation1;
  real32_T rtb_TSamp_b;
  real32_T rtb_force[4];
  real32_T rtb_TmpSignalConversionAtSFunct[3];
  int32_T rtb_fail_flag;
  real32_T rtb_real_index;
  boolean_T rtb_Compare;
  real32_T w_tmp;
  real32_T w_tmp_0;
  real32_T rtb_DotProduct_tmp[9];
  int32_T i;
  real_T rtb_omega_cmd;
  real32_T tmp;
  real_T tmp_0;
  real_T tmp_1;
  real_T tmp_2;
  real32_T tmp_3;
  real32_T tmp_4;
  real32_T tmp_5;
  real32_T tmp_6;
  static const real32_T c[6] = { 1.0F, 1.0F, -2.0F, 0.25F, 0.25F, 0.5F };

  static const real32_T b[16] = { -1.0F, -1.0F, 1.0F, 1.0F, -1.0F, 1.0F, 1.0F,
    -1.0F, -1.0F, 1.0F, -1.0F, 1.0F, 0.25F, 0.25F, 0.25F, 0.25F };

  /* MATLAB Function: '<Root>/MATLAB Function' incorporates:
   *  Inport: '<Root>/index'
   */
  if (Quaternion_single_axis_contro_U.index >= 10.0F) {
    rtb_fail_flag = 1;
    rtb_real_index = Quaternion_single_axis_contro_U.index - 10.0F;
  } else {
    rtb_fail_flag = 0;
    rtb_real_index = Quaternion_single_axis_contro_U.index;
  }

  /* End of MATLAB Function: '<Root>/MATLAB Function' */

  /* Saturate: '<Root>/Saturation1' incorporates:
   *  Inport: '<Root>/thrust'
   */
  if (Quaternion_single_axis_contro_U.thrust >
      Quaternion_single_axis_contro_P.Saturation1_UpperSat) {
    rtb_Saturation1 = Quaternion_single_axis_contro_P.Saturation1_UpperSat;
  } else if (Quaternion_single_axis_contro_U.thrust <
             Quaternion_single_axis_contro_P.Saturation1_LowerSat) {
    rtb_Saturation1 = Quaternion_single_axis_contro_P.Saturation1_LowerSat;
  } else {
    rtb_Saturation1 = Quaternion_single_axis_contro_U.thrust;
  }

  /* End of Saturate: '<Root>/Saturation1' */

  /* MATLAB Function: '<Root>/MATLAB Function2' incorporates:
   *  Inport: '<Root>/base_pitch'
   *  Inport: '<Root>/base_roll'
   *  Inport: '<Root>/base_yaw'
   */
  x = sinf(Quaternion_single_axis_contro_U.base_roll / 2.0F);
  y = cosf(Quaternion_single_axis_contro_U.base_pitch / 2.0F);
  z = cosf(Quaternion_single_axis_contro_U.base_yaw / 2.0F);
  w_tmp = cosf(Quaternion_single_axis_contro_U.base_roll / 2.0F);
  w_tmp_0 = sinf(Quaternion_single_axis_contro_U.base_pitch / 2.0F);
  rtb_TSamp_b = sinf(Quaternion_single_axis_contro_U.base_yaw / 2.0F);
  w = w_tmp * y * z + x * w_tmp_0 * rtb_TSamp_b;
  x = x * y * z - w_tmp * w_tmp_0 * rtb_TSamp_b;
  y = cosf(Quaternion_single_axis_contro_U.base_roll / 2.0F) * sinf
    (Quaternion_single_axis_contro_U.base_pitch / 2.0F) * z + sinf
    (Quaternion_single_axis_contro_U.base_roll / 2.0F) * cosf
    (Quaternion_single_axis_contro_U.base_pitch / 2.0F) * rtb_TSamp_b;
  z = cosf(Quaternion_single_axis_contro_U.base_roll / 2.0F) * cosf
    (Quaternion_single_axis_contro_U.base_pitch / 2.0F) * rtb_TSamp_b - sinf
    (Quaternion_single_axis_contro_U.base_roll / 2.0F) * sinf
    (Quaternion_single_axis_contro_U.base_pitch / 2.0F) * z;
  rtb_TmpSignalConversionAtSFunct[0] = 2.0F * x * z + 2.0F * w * y;
  rtb_TmpSignalConversionAtSFunct[1] = 2.0F * y * z - 2.0F * w * x;
  rtb_TmpSignalConversionAtSFunct[2] = ((w * w - x * x) - y * y) + z * z;

  /* MATLAB Function: '<Root>/MATLAB Function1' incorporates:
   *  Inport: '<Root>/qw'
   *  Inport: '<Root>/qx'
   *  Inport: '<Root>/qy'
   *  Inport: '<Root>/qz'
   *  MATLAB Function: '<Root>/MATLAB Function3'
   */
  w_tmp = -rtb_real_index * 3.14159274F / 2.0F;
  w_tmp_0 = sinf(w_tmp);
  w_tmp = cosf(w_tmp);
  rtb_DotProduct_tmp[0] = w_tmp;
  rtb_DotProduct_tmp[3] = -w_tmp_0;
  rtb_DotProduct_tmp[6] = 0.0F;
  rtb_DotProduct_tmp[1] = w_tmp_0;
  rtb_DotProduct_tmp[4] = w_tmp;
  rtb_DotProduct_tmp[7] = 0.0F;
  rtb_DotProduct_tmp[2] = 0.0F;
  rtb_DotProduct_tmp[5] = 0.0F;
  rtb_DotProduct_tmp[8] = 1.0F;
  x = 2.0F * Quaternion_single_axis_contro_U.qx *
    Quaternion_single_axis_contro_U.qz;
  y = 2.0F * Quaternion_single_axis_contro_U.qw *
    Quaternion_single_axis_contro_U.qy;
  w = x + y;
  tmp = 2.0F * Quaternion_single_axis_contro_U.qy *
    Quaternion_single_axis_contro_U.qz - 2.0F *
    Quaternion_single_axis_contro_U.qw * Quaternion_single_axis_contro_U.qx;
  tmp_3 = Quaternion_single_axis_contro_U.qw *
    Quaternion_single_axis_contro_U.qw;
  tmp_4 = Quaternion_single_axis_contro_U.qx *
    Quaternion_single_axis_contro_U.qx;
  tmp_5 = Quaternion_single_axis_contro_U.qy *
    Quaternion_single_axis_contro_U.qy;
  tmp_6 = Quaternion_single_axis_contro_U.qz *
    Quaternion_single_axis_contro_U.qz;
  z = ((tmp_3 - tmp_4) - tmp_5) + tmp_6;

  /* DotProduct: '<Root>/Dot Product' */
  rtb_TSamp_b = 0.0F;
  for (i = 0; i < 3; i++) {
    /* DotProduct: '<Root>/Dot Product' incorporates:
     *  MATLAB Function: '<Root>/MATLAB Function1'
     */
    rtb_TSamp_b += (rtb_DotProduct_tmp[i + 6] * z + (rtb_DotProduct_tmp[i + 3] *
      tmp + rtb_DotProduct_tmp[i] * w)) * rtb_TmpSignalConversionAtSFunct[i];
  }

  /* MATLAB Function: '<Root>/MATLAB Function5' incorporates:
   *  DotProduct: '<Root>/Dot Product'
   *  DotProduct: '<Root>/Dot Product1'
   */
  if (rtb_TSamp_b >= 0.0F) {
    /* MATLAB Function: '<Root>/MATLAB Function3' incorporates:
     *  Inport: '<Root>/qw'
     *  Inport: '<Root>/qx'
     *  Inport: '<Root>/qy'
     *  Inport: '<Root>/qz'
     */
    rtb_DotProduct_tmp[0] = w_tmp;
    rtb_DotProduct_tmp[3] = -sinf(-rtb_real_index * 3.14159274F / 2.0F);
    rtb_DotProduct_tmp[6] = 0.0F;
    rtb_DotProduct_tmp[1] = w_tmp_0;
    rtb_DotProduct_tmp[4] = w_tmp;
    rtb_DotProduct_tmp[7] = 0.0F;
    rtb_DotProduct_tmp[2] = 0.0F;
    rtb_DotProduct_tmp[5] = 0.0F;
    rtb_DotProduct_tmp[8] = 1.0F;
    rtb_real_index = ((Quaternion_single_axis_contro_U.qw *
                       Quaternion_single_axis_contro_U.qw +
                       Quaternion_single_axis_contro_U.qx *
                       Quaternion_single_axis_contro_U.qx) -
                      Quaternion_single_axis_contro_U.qy *
                      Quaternion_single_axis_contro_U.qy) -
      Quaternion_single_axis_contro_U.qz * Quaternion_single_axis_contro_U.qz;
    w = 2.0F * Quaternion_single_axis_contro_U.qx *
      Quaternion_single_axis_contro_U.qy + 2.0F *
      Quaternion_single_axis_contro_U.qz * Quaternion_single_axis_contro_U.qw;
    x = 2.0F * Quaternion_single_axis_contro_U.qx *
      Quaternion_single_axis_contro_U.qz - 2.0F *
      Quaternion_single_axis_contro_U.qw * Quaternion_single_axis_contro_U.qy;

    /* DotProduct: '<Root>/Dot Product1' */
    z = 0.0F;
    for (i = 0; i < 3; i++) {
      /* DotProduct: '<Root>/Dot Product1' incorporates:
       *  MATLAB Function: '<Root>/MATLAB Function3'
       */
      z += (rtb_DotProduct_tmp[i + 6] * x + (rtb_DotProduct_tmp[i + 3] * w +
             rtb_DotProduct_tmp[i] * rtb_real_index)) *
        rtb_TmpSignalConversionAtSFunct[i];
    }

    Quaternion_single_axis_contro_Y.theta_meas = acosf(z) - 1.57079637F;
  } else {
    /* MATLAB Function: '<Root>/MATLAB Function3' incorporates:
     *  Inport: '<Root>/qw'
     *  Inport: '<Root>/qx'
     *  Inport: '<Root>/qy'
     *  Inport: '<Root>/qz'
     */
    rtb_DotProduct_tmp[0] = w_tmp;
    rtb_DotProduct_tmp[3] = -sinf(-rtb_real_index * 3.14159274F / 2.0F);
    rtb_DotProduct_tmp[6] = 0.0F;
    rtb_DotProduct_tmp[1] = w_tmp_0;
    rtb_DotProduct_tmp[4] = w_tmp;
    rtb_DotProduct_tmp[7] = 0.0F;
    rtb_DotProduct_tmp[2] = 0.0F;
    rtb_DotProduct_tmp[5] = 0.0F;
    rtb_DotProduct_tmp[8] = 1.0F;
    rtb_real_index = ((tmp_3 + tmp_4) - tmp_5) - tmp_6;
    w = 2.0F * Quaternion_single_axis_contro_U.qx *
      Quaternion_single_axis_contro_U.qy + 2.0F *
      Quaternion_single_axis_contro_U.qz * Quaternion_single_axis_contro_U.qw;
    x -= y;

    /* DotProduct: '<Root>/Dot Product1' */
    z = 0.0F;
    for (i = 0; i < 3; i++) {
      /* DotProduct: '<Root>/Dot Product1' incorporates:
       *  MATLAB Function: '<Root>/MATLAB Function3'
       */
      z += (rtb_DotProduct_tmp[i + 6] * x + (rtb_DotProduct_tmp[i + 3] * w +
             rtb_DotProduct_tmp[i] * rtb_real_index)) *
        rtb_TmpSignalConversionAtSFunct[i];
    }

    if (z <= 0.0F) {
      Quaternion_single_axis_contro_Y.theta_meas = acosf(rtb_TSamp_b);
    } else {
      Quaternion_single_axis_contro_Y.theta_meas = -acosf(rtb_TSamp_b);
    }
  }

  /* End of MATLAB Function: '<Root>/MATLAB Function5' */

  /* Saturate: '<Root>/Saturation2' incorporates:
   *  Inport: '<Root>/theta'
   */
  if (Quaternion_single_axis_contro_U.theta >
      Quaternion_single_axis_contro_P.theta_cmd_sat) {
    z = Quaternion_single_axis_contro_P.theta_cmd_sat;
  } else if (Quaternion_single_axis_contro_U.theta <
             Quaternion_single_axis_contro_P.Saturation2_LowerSat) {
    z = Quaternion_single_axis_contro_P.Saturation2_LowerSat;
  } else {
    z = Quaternion_single_axis_contro_U.theta;
  }

  /* End of Saturate: '<Root>/Saturation2' */

  /* Sum: '<Root>/Sum4' */
  Quaternion_single_axis_contro_Y.error_theta =
    Quaternion_single_axis_contro_Y.theta_meas - z;

  /* RelationalOperator: '<S1>/Compare' incorporates:
   *  Constant: '<S1>/Constant'
   */
  rtb_Compare = (rtb_Saturation1 >
                 Quaternion_single_axis_contro_P.Constant_Value);

  /* DiscreteIntegrator: '<Root>/Discrete-Time Integrator2' */
  if (rtb_Compare &&
      (Quaternion_single_axis_contr_DW.DiscreteTimeIntegrator2_PrevRes <= 0)) {
    Quaternion_single_axis_contr_DW.DiscreteTimeIntegrator2_DSTATE =
      Quaternion_single_axis_contro_P.DiscreteTimeIntegrator2_IC;
  }

  if (Quaternion_single_axis_contr_DW.DiscreteTimeIntegrator2_DSTATE >=
      Quaternion_single_axis_contro_P.DiscreteTimeIntegrator2_UpperSa) {
    Quaternion_single_axis_contr_DW.DiscreteTimeIntegrator2_DSTATE =
      Quaternion_single_axis_contro_P.DiscreteTimeIntegrator2_UpperSa;
  } else {
    if (Quaternion_single_axis_contr_DW.DiscreteTimeIntegrator2_DSTATE <=
        Quaternion_single_axis_contro_P.DiscreteTimeIntegrator2_LowerSa) {
      Quaternion_single_axis_contr_DW.DiscreteTimeIntegrator2_DSTATE =
        Quaternion_single_axis_contro_P.DiscreteTimeIntegrator2_LowerSa;
    }
  }

  /* SampleTimeMath: '<S3>/TSamp'
   *
   * About '<S3>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   */
  rtb_real_index = Quaternion_single_axis_contro_Y.error_theta *
    Quaternion_single_axis_contro_P.TSamp_WtEt;

  /* Sum: '<Root>/Sum1' incorporates:
   *  DiscreteIntegrator: '<Root>/Discrete-Time Integrator2'
   *  Gain: '<Root>/pitch_rate_D1'
   *  Gain: '<Root>/pitch_rate_I1'
   *  Gain: '<Root>/pitch_rate_P1'
   *  Inport: '<Root>/q'
   *  Sum: '<Root>/Sum2'
   *  Sum: '<S3>/Diff'
   *  UnitDelay: '<S3>/UD'
   *
   * Block description for '<S3>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S3>/UD':
   *
   *  Store in Global RAM
   */
  Quaternion_single_axis_contro_Y.error_omega =
    ((Quaternion_single_axis_contro_P.pitch_P *
      Quaternion_single_axis_contro_Y.error_theta +
      Quaternion_single_axis_contro_P.pitch_I *
      Quaternion_single_axis_contr_DW.DiscreteTimeIntegrator2_DSTATE) +
     (rtb_real_index - Quaternion_single_axis_contr_DW.UD_DSTATE) *
     Quaternion_single_axis_contro_P.pitch_D) -
    Quaternion_single_axis_contro_U.q;

  /* DiscreteIntegrator: '<Root>/Discrete-Time Integrator1' */
  if (rtb_Compare &&
      (Quaternion_single_axis_contr_DW.DiscreteTimeIntegrator1_PrevRes <= 0)) {
    Quaternion_single_axis_contr_DW.DiscreteTimeIntegrator1_DSTATE =
      Quaternion_single_axis_contro_P.DiscreteTimeIntegrator1_IC;
  }

  if (Quaternion_single_axis_contr_DW.DiscreteTimeIntegrator1_DSTATE >=
      Quaternion_single_axis_contro_P.DiscreteTimeIntegrator1_UpperSa) {
    Quaternion_single_axis_contr_DW.DiscreteTimeIntegrator1_DSTATE =
      Quaternion_single_axis_contro_P.DiscreteTimeIntegrator1_UpperSa;
  } else {
    if (Quaternion_single_axis_contr_DW.DiscreteTimeIntegrator1_DSTATE <=
        Quaternion_single_axis_contro_P.DiscreteTimeIntegrator1_LowerSa) {
      Quaternion_single_axis_contr_DW.DiscreteTimeIntegrator1_DSTATE =
        Quaternion_single_axis_contro_P.DiscreteTimeIntegrator1_LowerSa;
    }
  }

  /* SampleTimeMath: '<S2>/TSamp'
   *
   * About '<S2>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   */
  rtb_TSamp_b = Quaternion_single_axis_contro_Y.error_omega *
    Quaternion_single_axis_contro_P.TSamp_WtEt_f;

  /* Sum: '<Root>/Sum3' incorporates:
   *  DiscreteIntegrator: '<Root>/Discrete-Time Integrator1'
   *  Gain: '<Root>/pitch_rate_D'
   *  Gain: '<Root>/pitch_rate_I'
   *  Gain: '<Root>/pitch_rate_P'
   *  Sum: '<S2>/Diff'
   *  UnitDelay: '<S2>/UD'
   *
   * Block description for '<S2>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S2>/UD':
   *
   *  Store in Global RAM
   */
  Quaternion_single_axis_contro_Y.fy =
    (Quaternion_single_axis_contro_P.pitch_rate_P *
     Quaternion_single_axis_contro_Y.error_omega +
     Quaternion_single_axis_contro_P.pitch_rate_I *
     Quaternion_single_axis_contr_DW.DiscreteTimeIntegrator1_DSTATE) +
    (rtb_TSamp_b - Quaternion_single_axis_contr_DW.UD_DSTATE_k) *
    Quaternion_single_axis_contro_P.pitch_rate_D;

  /* Saturate: '<Root>/Saturation3' */
  if (Quaternion_single_axis_contro_Y.fy >
      Quaternion_single_axis_contro_P.fy_sat) {
    y = Quaternion_single_axis_contro_P.fy_sat;
  } else if (Quaternion_single_axis_contro_Y.fy <
             Quaternion_single_axis_contro_P.Saturation3_LowerSat) {
    y = Quaternion_single_axis_contro_P.Saturation3_LowerSat;
  } else {
    y = Quaternion_single_axis_contro_Y.fy;
  }

  /* End of Saturate: '<Root>/Saturation3' */

  /* MATLAB Function: '<S9>/cmd2force' incorporates:
   *  Inport: '<Root>/mx'
   *  Inport: '<Root>/mz'
   */
  if (rtb_fail_flag == 0) {
    w = Quaternion_single_axis_contro_U.mx / 0.1266F;
    z = Quaternion_single_axis_contro_U.mz / 0.02388F;
    for (i = 0; i < 4; i++) {
      x = b[i + 12] * rtb_Saturation1 + (b[i + 8] * z + (b[i + 4] * y + b[i] * w));
      rtb_force[i] = x;
    }

    /* Outport: '<Root>/my_out' incorporates:
     *  Inport: '<Root>/mx'
     *  Inport: '<Root>/mz'
     */
    Quaternion_single_axis_contro_Y.my_out = y * 4.0F * 0.03165F;

    /* Outport: '<Root>/mx_out' incorporates:
     *  Inport: '<Root>/mx'
     */
    Quaternion_single_axis_contro_Y.mx_out = Quaternion_single_axis_contro_U.mx;

    /* Outport: '<Root>/mz_out' incorporates:
     *  Inport: '<Root>/mz'
     */
    Quaternion_single_axis_contro_Y.mz_out = Quaternion_single_axis_contro_U.mz;
  } else {
    rtb_force[0] = 0.0F;
    for (i = 0; i < 3; i++) {
      rtb_force[i + 1] = c[i + 3] * rtb_Saturation1 + c[i] * y;
    }

    /* Outport: '<Root>/my_out' */
    Quaternion_single_axis_contro_Y.my_out = y * 4.0F * 0.03165F;

    /* Outport: '<Root>/mx_out' */
    Quaternion_single_axis_contro_Y.mx_out = ((rtb_force[2] + rtb_force[3]) -
      rtb_force[1]) * -2.0F * 0.03165F;

    /* Outport: '<Root>/mz_out' */
    Quaternion_single_axis_contro_Y.mz_out = ((rtb_force[3] - rtb_force[2]) +
      rtb_force[1]) * -2.0F * 0.00597F;
  }

  /* End of MATLAB Function: '<S9>/cmd2force' */

  /* Saturate: '<S9>/Saturation' */
  if (rtb_force[0] > Quaternion_single_axis_contro_P.Saturation_UpperSat_d) {
    x = Quaternion_single_axis_contro_P.Saturation_UpperSat_d;
  } else if (rtb_force[0] <
             Quaternion_single_axis_contro_P.Saturation_LowerSat_l) {
    x = Quaternion_single_axis_contro_P.Saturation_LowerSat_l;
  } else {
    x = rtb_force[0];
  }

  /* MATLAB Function: '<S9>/force2motorCMD' */
  rtb_omega_cmd = (sqrtf(0.366F * x + 0.00457922881F) + -0.06767F) * 65536.0F /
    0.183F;

  /* Saturate: '<Root>/Saturation' */
  if (rtb_omega_cmd > Quaternion_single_axis_contro_P.Saturation_UpperSat) {
    rtb_omega_cmd = Quaternion_single_axis_contro_P.Saturation_UpperSat;
  } else {
    if (rtb_omega_cmd < Quaternion_single_axis_contro_P.Saturation_LowerSat) {
      rtb_omega_cmd = Quaternion_single_axis_contro_P.Saturation_LowerSat;
    }
  }

  /* DataTypeConversion: '<Root>/Data Type Conversion' */
  tmp_2 = floor(rtb_omega_cmd);
  if (rtIsNaN(tmp_2) || rtIsInf(tmp_2)) {
    tmp_2 = 0.0;
  } else {
    tmp_2 = fmod(tmp_2, 65536.0);
  }

  /* Saturate: '<S9>/Saturation' */
  if (rtb_force[1] > Quaternion_single_axis_contro_P.Saturation_UpperSat_d) {
    x = Quaternion_single_axis_contro_P.Saturation_UpperSat_d;
  } else if (rtb_force[1] <
             Quaternion_single_axis_contro_P.Saturation_LowerSat_l) {
    x = Quaternion_single_axis_contro_P.Saturation_LowerSat_l;
  } else {
    x = rtb_force[1];
  }

  /* MATLAB Function: '<S9>/force2motorCMD' */
  rtb_omega_cmd = (sqrtf(0.366F * x + 0.00457922881F) + -0.06767F) * 65536.0F /
    0.183F;

  /* Saturate: '<Root>/Saturation' */
  if (rtb_omega_cmd > Quaternion_single_axis_contro_P.Saturation_UpperSat) {
    rtb_omega_cmd = Quaternion_single_axis_contro_P.Saturation_UpperSat;
  } else {
    if (rtb_omega_cmd < Quaternion_single_axis_contro_P.Saturation_LowerSat) {
      rtb_omega_cmd = Quaternion_single_axis_contro_P.Saturation_LowerSat;
    }
  }

  /* DataTypeConversion: '<Root>/Data Type Conversion' */
  tmp_1 = floor(rtb_omega_cmd);
  if (rtIsNaN(tmp_1) || rtIsInf(tmp_1)) {
    tmp_1 = 0.0;
  } else {
    tmp_1 = fmod(tmp_1, 65536.0);
  }

  /* Saturate: '<S9>/Saturation' */
  if (rtb_force[2] > Quaternion_single_axis_contro_P.Saturation_UpperSat_d) {
    x = Quaternion_single_axis_contro_P.Saturation_UpperSat_d;
  } else if (rtb_force[2] <
             Quaternion_single_axis_contro_P.Saturation_LowerSat_l) {
    x = Quaternion_single_axis_contro_P.Saturation_LowerSat_l;
  } else {
    x = rtb_force[2];
  }

  /* MATLAB Function: '<S9>/force2motorCMD' */
  rtb_omega_cmd = (sqrtf(0.366F * x + 0.00457922881F) + -0.06767F) * 65536.0F /
    0.183F;

  /* Saturate: '<Root>/Saturation' */
  if (rtb_omega_cmd > Quaternion_single_axis_contro_P.Saturation_UpperSat) {
    rtb_omega_cmd = Quaternion_single_axis_contro_P.Saturation_UpperSat;
  } else {
    if (rtb_omega_cmd < Quaternion_single_axis_contro_P.Saturation_LowerSat) {
      rtb_omega_cmd = Quaternion_single_axis_contro_P.Saturation_LowerSat;
    }
  }

  /* DataTypeConversion: '<Root>/Data Type Conversion' */
  tmp_0 = floor(rtb_omega_cmd);
  if (rtIsNaN(tmp_0) || rtIsInf(tmp_0)) {
    tmp_0 = 0.0;
  } else {
    tmp_0 = fmod(tmp_0, 65536.0);
  }

  /* Saturate: '<S9>/Saturation' */
  if (rtb_force[3] > Quaternion_single_axis_contro_P.Saturation_UpperSat_d) {
    x = Quaternion_single_axis_contro_P.Saturation_UpperSat_d;
  } else if (rtb_force[3] <
             Quaternion_single_axis_contro_P.Saturation_LowerSat_l) {
    x = Quaternion_single_axis_contro_P.Saturation_LowerSat_l;
  } else {
    x = rtb_force[3];
  }

  /* MATLAB Function: '<S9>/force2motorCMD' */
  rtb_omega_cmd = (sqrtf(0.366F * x + 0.00457922881F) + -0.06767F) * 65536.0F /
    0.183F;

  /* Saturate: '<Root>/Saturation' */
  if (rtb_omega_cmd > Quaternion_single_axis_contro_P.Saturation_UpperSat) {
    rtb_omega_cmd = Quaternion_single_axis_contro_P.Saturation_UpperSat;
  } else {
    if (rtb_omega_cmd < Quaternion_single_axis_contro_P.Saturation_LowerSat) {
      rtb_omega_cmd = Quaternion_single_axis_contro_P.Saturation_LowerSat;
    }
  }

  /* DataTypeConversion: '<Root>/Data Type Conversion' */
  rtb_omega_cmd = floor(rtb_omega_cmd);
  if (rtIsNaN(rtb_omega_cmd) || rtIsInf(rtb_omega_cmd)) {
    rtb_omega_cmd = 0.0;
  } else {
    rtb_omega_cmd = fmod(rtb_omega_cmd, 65536.0);
  }

  /* Outport: '<Root>/M1_output' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion'
   */
  Quaternion_single_axis_contro_Y.M1_output = (uint16_T)(tmp_2 < 0.0 ? (int32_T)
    (uint16_T)-(int16_T)(uint16_T)-tmp_2 : (int32_T)(uint16_T)tmp_2);

  /* Outport: '<Root>/M2_output' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion'
   */
  Quaternion_single_axis_contro_Y.M2_output = (uint16_T)(tmp_1 < 0.0 ? (int32_T)
    (uint16_T)-(int16_T)(uint16_T)-tmp_1 : (int32_T)(uint16_T)tmp_1);

  /* Outport: '<Root>/M3_output' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion'
   */
  Quaternion_single_axis_contro_Y.M3_output = (uint16_T)(tmp_0 < 0.0 ? (int32_T)
    (uint16_T)-(int16_T)(uint16_T)-tmp_0 : (int32_T)(uint16_T)tmp_0);

  /* Outport: '<Root>/M4_output' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion'
   */
  Quaternion_single_axis_contro_Y.M4_output = (uint16_T)(rtb_omega_cmd < 0.0 ?
    (int32_T)(uint16_T)-(int16_T)(uint16_T)-rtb_omega_cmd : (int32_T)(uint16_T)
    rtb_omega_cmd);

  /* Update for DiscreteIntegrator: '<Root>/Discrete-Time Integrator2' */
  Quaternion_single_axis_contr_DW.DiscreteTimeIntegrator2_DSTATE +=
    Quaternion_single_axis_contro_P.DiscreteTimeIntegrator2_gainval *
    Quaternion_single_axis_contro_Y.error_theta;
  if (Quaternion_single_axis_contr_DW.DiscreteTimeIntegrator2_DSTATE >=
      Quaternion_single_axis_contro_P.DiscreteTimeIntegrator2_UpperSa) {
    Quaternion_single_axis_contr_DW.DiscreteTimeIntegrator2_DSTATE =
      Quaternion_single_axis_contro_P.DiscreteTimeIntegrator2_UpperSa;
  } else {
    if (Quaternion_single_axis_contr_DW.DiscreteTimeIntegrator2_DSTATE <=
        Quaternion_single_axis_contro_P.DiscreteTimeIntegrator2_LowerSa) {
      Quaternion_single_axis_contr_DW.DiscreteTimeIntegrator2_DSTATE =
        Quaternion_single_axis_contro_P.DiscreteTimeIntegrator2_LowerSa;
    }
  }

  Quaternion_single_axis_contr_DW.DiscreteTimeIntegrator2_PrevRes = (int8_T)
    rtb_Compare;

  /* End of Update for DiscreteIntegrator: '<Root>/Discrete-Time Integrator2' */

  /* Update for UnitDelay: '<S3>/UD'
   *
   * Block description for '<S3>/UD':
   *
   *  Store in Global RAM
   */
  Quaternion_single_axis_contr_DW.UD_DSTATE = rtb_real_index;

  /* Update for DiscreteIntegrator: '<Root>/Discrete-Time Integrator1' */
  Quaternion_single_axis_contr_DW.DiscreteTimeIntegrator1_DSTATE +=
    Quaternion_single_axis_contro_P.DiscreteTimeIntegrator1_gainval *
    Quaternion_single_axis_contro_Y.error_omega;
  if (Quaternion_single_axis_contr_DW.DiscreteTimeIntegrator1_DSTATE >=
      Quaternion_single_axis_contro_P.DiscreteTimeIntegrator1_UpperSa) {
    Quaternion_single_axis_contr_DW.DiscreteTimeIntegrator1_DSTATE =
      Quaternion_single_axis_contro_P.DiscreteTimeIntegrator1_UpperSa;
  } else {
    if (Quaternion_single_axis_contr_DW.DiscreteTimeIntegrator1_DSTATE <=
        Quaternion_single_axis_contro_P.DiscreteTimeIntegrator1_LowerSa) {
      Quaternion_single_axis_contr_DW.DiscreteTimeIntegrator1_DSTATE =
        Quaternion_single_axis_contro_P.DiscreteTimeIntegrator1_LowerSa;
    }
  }

  Quaternion_single_axis_contr_DW.DiscreteTimeIntegrator1_PrevRes = (int8_T)
    rtb_Compare;

  /* End of Update for DiscreteIntegrator: '<Root>/Discrete-Time Integrator1' */

  /* Update for UnitDelay: '<S2>/UD'
   *
   * Block description for '<S2>/UD':
   *
   *  Store in Global RAM
   */
  Quaternion_single_axis_contr_DW.UD_DSTATE_k = rtb_TSamp_b;
}

/* Model initialize function */
void Quaternion_single_axis_controller_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize error status */
  rtmSetErrorStatus(Quaternion_single_axis_contr_M, (NULL));

  /* states (dwork) */
  (void) memset((void *)&Quaternion_single_axis_contr_DW, 0,
                sizeof(DW_Quaternion_single_axis_con_T));

  /* external inputs */
  (void)memset(&Quaternion_single_axis_contro_U, 0, sizeof
               (ExtU_Quaternion_single_axis_c_T));

  /* external outputs */
  (void) memset((void *)&Quaternion_single_axis_contro_Y, 0,
                sizeof(ExtY_Quaternion_single_axis_c_T));

  /* InitializeConditions for DiscreteIntegrator: '<Root>/Discrete-Time Integrator2' */
  Quaternion_single_axis_contr_DW.DiscreteTimeIntegrator2_DSTATE =
    Quaternion_single_axis_contro_P.DiscreteTimeIntegrator2_IC;
  Quaternion_single_axis_contr_DW.DiscreteTimeIntegrator2_PrevRes = 2;

  /* InitializeConditions for UnitDelay: '<S3>/UD'
   *
   * Block description for '<S3>/UD':
   *
   *  Store in Global RAM
   */
  Quaternion_single_axis_contr_DW.UD_DSTATE =
    Quaternion_single_axis_contro_P.DiscreteDerivative2_ICPrevScale;

  /* InitializeConditions for DiscreteIntegrator: '<Root>/Discrete-Time Integrator1' */
  Quaternion_single_axis_contr_DW.DiscreteTimeIntegrator1_DSTATE =
    Quaternion_single_axis_contro_P.DiscreteTimeIntegrator1_IC;
  Quaternion_single_axis_contr_DW.DiscreteTimeIntegrator1_PrevRes = 2;

  /* InitializeConditions for UnitDelay: '<S2>/UD'
   *
   * Block description for '<S2>/UD':
   *
   *  Store in Global RAM
   */
  Quaternion_single_axis_contr_DW.UD_DSTATE_k =
    Quaternion_single_axis_contro_P.DiscreteDerivative1_ICPrevScale;
}

/* Model terminate function */
void Quaternion_single_axis_controller_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

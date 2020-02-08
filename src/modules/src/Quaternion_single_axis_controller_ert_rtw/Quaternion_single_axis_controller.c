/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Quaternion_single_axis_controller.c
 *
 * Code generated for Simulink model 'Quaternion_single_axis_controller'.
 *
 * Model version                  : 1.84
 * Simulink Coder version         : 8.14 (R2018a) 06-Feb-2018
 * C/C++ source code generated on : Wed Jan 22 11:17:24 2020
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
  static const real32_T b[16] = { 0.0F, 0.0F, 0.0F, 0.0F, -1.0F, 1.0F, 1.0F,
    -1.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.25F, 0.25F, 0.25F, 0.25F };

  real32_T rtb_Asin1;
  real32_T rtb_Sum1;
  real32_T rtb_TSamp;
  uint16_T rtb_DataTypeConversion[4];
  real32_T rtb_base_z_vector[3];
  real32_T tmp[9];
  real32_T u0;
  int32_T i;
  real_T rtb_omega_cmd;
  real32_T tmp_0;
  real32_T b_0;

  /* MATLAB Function: '<Root>/MATLAB Function2' incorporates:
   *  Inport: '<Root>/base_w'
   *  Inport: '<Root>/base_x'
   *  Inport: '<Root>/base_y'
   *  Inport: '<Root>/base_z'
   */
  rtb_base_z_vector[0] = 2.0F * Quaternion_single_axis_contro_U.base_x *
    Quaternion_single_axis_contro_U.base_z + 2.0F *
    Quaternion_single_axis_contro_U.base_w *
    Quaternion_single_axis_contro_U.base_y;
  rtb_base_z_vector[1] = 2.0F * Quaternion_single_axis_contro_U.base_y *
    Quaternion_single_axis_contro_U.base_z - 2.0F *
    Quaternion_single_axis_contro_U.base_w *
    Quaternion_single_axis_contro_U.base_x;
  rtb_base_z_vector[2] = ((Quaternion_single_axis_contro_U.base_w *
    Quaternion_single_axis_contro_U.base_w -
    Quaternion_single_axis_contro_U.base_x *
    Quaternion_single_axis_contro_U.base_x) -
    Quaternion_single_axis_contro_U.base_y *
    Quaternion_single_axis_contro_U.base_y) +
    Quaternion_single_axis_contro_U.base_z *
    Quaternion_single_axis_contro_U.base_z;

  /* MATLAB Function: '<Root>/MATLAB Function3' incorporates:
   *  Inport: '<Root>/index'
   *  Inport: '<Root>/qw'
   *  Inport: '<Root>/qx'
   *  Inport: '<Root>/qy'
   *  Inport: '<Root>/qz'
   */
  rtb_Sum1 = -Quaternion_single_axis_contro_U.index * 3.14159274F / 2.0F;
  rtb_Asin1 = cosf(rtb_Sum1);
  tmp[0] = rtb_Asin1;
  rtb_Sum1 = sinf(rtb_Sum1);
  tmp[3] = -rtb_Sum1;
  tmp[6] = 0.0F;
  tmp[1] = rtb_Sum1;
  tmp[4] = rtb_Asin1;
  tmp[7] = 0.0F;
  tmp[2] = 0.0F;
  tmp[5] = 0.0F;
  tmp[8] = 1.0F;
  rtb_Asin1 = ((Quaternion_single_axis_contro_U.qw *
                Quaternion_single_axis_contro_U.qw +
                Quaternion_single_axis_contro_U.qx *
                Quaternion_single_axis_contro_U.qx) -
               Quaternion_single_axis_contro_U.qy *
               Quaternion_single_axis_contro_U.qy) -
    Quaternion_single_axis_contro_U.qz * Quaternion_single_axis_contro_U.qz;
  rtb_Sum1 = 2.0F * Quaternion_single_axis_contro_U.qx *
    Quaternion_single_axis_contro_U.qy + 2.0F *
    Quaternion_single_axis_contro_U.qz * Quaternion_single_axis_contro_U.qw;
  rtb_TSamp = 2.0F * Quaternion_single_axis_contro_U.qx *
    Quaternion_single_axis_contro_U.qz - 2.0F *
    Quaternion_single_axis_contro_U.qw * Quaternion_single_axis_contro_U.qy;

  /* DotProduct: '<Root>/Dot Product1' */
  u0 = 0.0F;
  for (i = 0; i < 3; i++) {
    /* DotProduct: '<Root>/Dot Product1' incorporates:
     *  MATLAB Function: '<Root>/MATLAB Function3'
     */
    u0 += (tmp[i + 6] * rtb_TSamp + (tmp[i + 3] * rtb_Sum1 + tmp[i] * rtb_Asin1))
      * rtb_base_z_vector[i];
  }

  /* Trigonometry: '<Root>/Asin1' incorporates:
   *  DotProduct: '<Root>/Dot Product1'
   */
  if (u0 > 1.0F) {
    u0 = 1.0F;
  } else {
    if (u0 < -1.0F) {
      u0 = -1.0F;
    }
  }

  rtb_Asin1 = acosf(u0);

  /* End of Trigonometry: '<Root>/Asin1' */

  /* Saturate: '<Root>/Saturation2' incorporates:
   *  Inport: '<Root>/theta'
   */
  if (Quaternion_single_axis_contro_U.theta >
      Quaternion_single_axis_contro_P.Saturation2_UpperSat) {
    rtb_Sum1 = Quaternion_single_axis_contro_P.Saturation2_UpperSat;
  } else if (Quaternion_single_axis_contro_U.theta <
             Quaternion_single_axis_contro_P.Saturation2_LowerSat) {
    rtb_Sum1 = Quaternion_single_axis_contro_P.Saturation2_LowerSat;
  } else {
    rtb_Sum1 = Quaternion_single_axis_contro_U.theta;
  }

  /* End of Saturate: '<Root>/Saturation2' */

  /* Sum: '<Root>/Sum1' incorporates:
   *  Gain: '<Root>/pitch_P'
   *  Inport: '<Root>/q'
   *  MATLAB Function: '<Root>/MATLAB Function4'
   *  Sum: '<Root>/Sum4'
   */
  rtb_Sum1 = ((rtb_Asin1 - 1.57079637F) - rtb_Sum1) *
    Quaternion_single_axis_contro_P.pitch_P - Quaternion_single_axis_contro_U.q;

  /* SampleTimeMath: '<S1>/TSamp'
   *
   * About '<S1>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   */
  rtb_TSamp = rtb_Sum1 * Quaternion_single_axis_contro_P.TSamp_WtEt;

  /* MATLAB Function: '<S6>/cmd2force' incorporates:
   *  DiscreteIntegrator: '<Root>/Discrete-Time Integrator1'
   *  Gain: '<Root>/Gain'
   *  Gain: '<Root>/pitch_rate_D'
   *  Gain: '<Root>/pitch_rate_I'
   *  Gain: '<Root>/pitch_rate_P'
   *  Sum: '<Root>/Sum3'
   *  Sum: '<S1>/Diff'
   *  UnitDelay: '<S1>/UD'
   *
   * Block description for '<S1>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S1>/UD':
   *
   *  Store in Global RAM
   */
  u0 = ((Quaternion_single_axis_contro_P.pitch_rate_P * rtb_Sum1 +
         Quaternion_single_axis_contro_P.pitch_rate_I *
         Quaternion_single_axis_contr_DW.DiscreteTimeIntegrator1_DSTATE) +
        (rtb_TSamp - Quaternion_single_axis_contr_DW.UD_DSTATE) *
        Quaternion_single_axis_contro_P.pitch_rate_D) *
    Quaternion_single_axis_contro_P.Gain_Gain;

  /* Saturate: '<Root>/Saturation1' incorporates:
   *  Inport: '<Root>/thrust'
   */
  if (Quaternion_single_axis_contro_U.thrust >
      Quaternion_single_axis_contro_P.Saturation1_UpperSat) {
    /* MATLAB Function: '<S6>/cmd2force' */
    tmp_0 = Quaternion_single_axis_contro_P.Saturation1_UpperSat;
  } else if (Quaternion_single_axis_contro_U.thrust <
             Quaternion_single_axis_contro_P.Saturation1_LowerSat) {
    /* MATLAB Function: '<S6>/cmd2force' */
    tmp_0 = Quaternion_single_axis_contro_P.Saturation1_LowerSat;
  } else {
    /* MATLAB Function: '<S6>/cmd2force' */
    tmp_0 = Quaternion_single_axis_contro_U.thrust;
  }

  /* End of Saturate: '<Root>/Saturation1' */
  for (i = 0; i < 4; i++) {
    /* MATLAB Function: '<S6>/cmd2force' incorporates:
     *  Saturate: '<S6>/Saturation'
     */
    b_0 = b[i + 12] * tmp_0 + (b[i + 8] * 0.0F + (b[i + 4] * u0 + b[i] * 0.0F));

    /* Saturate: '<S6>/Saturation' */
    if (b_0 > Quaternion_single_axis_contro_P.Saturation_UpperSat_d) {
      b_0 = Quaternion_single_axis_contro_P.Saturation_UpperSat_d;
    } else {
      if (b_0 < Quaternion_single_axis_contro_P.Saturation_LowerSat_l) {
        b_0 = Quaternion_single_axis_contro_P.Saturation_LowerSat_l;
      }
    }

    /* MATLAB Function: '<S6>/force2motorCMD' */
    rtb_omega_cmd = (sqrtf(0.366F * b_0 + 0.00457922881F) + -0.06767F) *
      65536.0F / 0.183F;

    /* Saturate: '<Root>/Saturation' */
    if (rtb_omega_cmd > Quaternion_single_axis_contro_P.Saturation_UpperSat) {
      rtb_omega_cmd = Quaternion_single_axis_contro_P.Saturation_UpperSat;
    } else {
      if (rtb_omega_cmd < Quaternion_single_axis_contro_P.Saturation_LowerSat) {
        rtb_omega_cmd = Quaternion_single_axis_contro_P.Saturation_LowerSat;
      }
    }

    /* End of Saturate: '<Root>/Saturation' */

    /* DataTypeConversion: '<Root>/Data Type Conversion' */
    rtb_omega_cmd = floor(rtb_omega_cmd);
    if (rtIsNaN(rtb_omega_cmd) || rtIsInf(rtb_omega_cmd)) {
      rtb_omega_cmd = 0.0;
    } else {
      rtb_omega_cmd = fmod(rtb_omega_cmd, 65536.0);
    }

    rtb_DataTypeConversion[i] = (uint16_T)(rtb_omega_cmd < 0.0 ? (int32_T)
      (uint16_T)-(int16_T)(uint16_T)-rtb_omega_cmd : (int32_T)(uint16_T)
      rtb_omega_cmd);

    /* End of DataTypeConversion: '<Root>/Data Type Conversion' */
  }

  /* Outport: '<Root>/M1_output' */
  Quaternion_single_axis_contro_Y.M1_output = rtb_DataTypeConversion[0];

  /* Outport: '<Root>/M2_output' */
  Quaternion_single_axis_contro_Y.M2_output = rtb_DataTypeConversion[1];

  /* Outport: '<Root>/M3_output' */
  Quaternion_single_axis_contro_Y.M3_output = rtb_DataTypeConversion[2];

  /* Outport: '<Root>/M4_output' */
  Quaternion_single_axis_contro_Y.M4_output = rtb_DataTypeConversion[3];

  /* Outport: '<Root>/theta_meas' incorporates:
   *  MATLAB Function: '<Root>/MATLAB Function4'
   */
  Quaternion_single_axis_contro_Y.theta_meas = rtb_Asin1 - 1.57079637F;

  /* Update for DiscreteIntegrator: '<Root>/Discrete-Time Integrator1' */
  Quaternion_single_axis_contr_DW.DiscreteTimeIntegrator1_DSTATE +=
    Quaternion_single_axis_contro_P.DiscreteTimeIntegrator1_gainval * rtb_Sum1;
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

  /* End of Update for DiscreteIntegrator: '<Root>/Discrete-Time Integrator1' */

  /* Update for UnitDelay: '<S1>/UD'
   *
   * Block description for '<S1>/UD':
   *
   *  Store in Global RAM
   */
  Quaternion_single_axis_contr_DW.UD_DSTATE = rtb_TSamp;
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
  (void)memset((void *)&Quaternion_single_axis_contro_U, 0, sizeof
               (ExtU_Quaternion_single_axis_c_T));

  /* external outputs */
  (void) memset((void *)&Quaternion_single_axis_contro_Y, 0,
                sizeof(ExtY_Quaternion_single_axis_c_T));

  /* InitializeConditions for DiscreteIntegrator: '<Root>/Discrete-Time Integrator1' */
  Quaternion_single_axis_contr_DW.DiscreteTimeIntegrator1_DSTATE =
    Quaternion_single_axis_contro_P.DiscreteTimeIntegrator1_IC;

  /* InitializeConditions for UnitDelay: '<S1>/UD'
   *
   * Block description for '<S1>/UD':
   *
   *  Store in Global RAM
   */
  Quaternion_single_axis_contr_DW.UD_DSTATE =
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

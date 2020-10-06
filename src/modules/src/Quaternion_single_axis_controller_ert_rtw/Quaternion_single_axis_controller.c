/*
 * File: Quaternion_single_axis_controller.c
 *
 * Code generated for Simulink model 'Quaternion_single_axis_controller'.
 *
 * Model version                  : 1.98
 * Simulink Coder version         : 9.3 (R2020a) 18-Nov-2019
 * C/C++ source code generated on : Tue Oct  6 11:01:05 2020
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
  real32_T rtb_Sum1;
  real32_T rtb_TSamp;
  real32_T rtb_Gain;
  uint16_T rtb_DataTypeConversion[4];
  real32_T rtb_base_z_vector[3];
  real32_T rtb_quad_z_vector_tmp[9];
  int32_T i;
  real_T rtb_omega_cmd;
  real32_T tmp;
  real32_T tmp_0;
  real32_T tmp_1;
  real32_T rtb_quad_z_vector_tmp_tmp;
  real32_T rtb_quad_z_vector_tmp_tmp_0;
  real32_T tmp_2;
  real32_T tmp_3;
  real32_T tmp_4;
  real32_T tmp_5;
  static const real32_T b[16] = { -1.0F, -1.0F, 1.0F, 1.0F, -1.0F, 1.0F, 1.0F,
    -1.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.25F, 0.25F, 0.25F, 0.25F };

  /* MATLAB Function: '<Root>/MATLAB Function1' incorporates:
   *  Inport: '<Root>/index'
   *  MATLAB Function: '<Root>/MATLAB Function3'
   */
  rtb_quad_z_vector_tmp_tmp = -Quaternion_single_axis_contro_U.index *
    3.14159274F / 2.0F;
  rtb_quad_z_vector_tmp_tmp_0 = sinf(rtb_quad_z_vector_tmp_tmp);
  rtb_quad_z_vector_tmp_tmp = cosf(rtb_quad_z_vector_tmp_tmp);

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

  /* MATLAB Function: '<Root>/MATLAB Function1' incorporates:
   *  Inport: '<Root>/qw'
   *  Inport: '<Root>/qx'
   *  Inport: '<Root>/qy'
   *  Inport: '<Root>/qz'
   *  MATLAB Function: '<Root>/MATLAB Function3'
   */
  rtb_quad_z_vector_tmp[0] = rtb_quad_z_vector_tmp_tmp;
  rtb_quad_z_vector_tmp[3] = -rtb_quad_z_vector_tmp_tmp_0;
  rtb_quad_z_vector_tmp[6] = 0.0F;
  rtb_quad_z_vector_tmp[1] = rtb_quad_z_vector_tmp_tmp_0;
  rtb_quad_z_vector_tmp[4] = rtb_quad_z_vector_tmp_tmp;
  rtb_quad_z_vector_tmp[7] = 0.0F;
  rtb_quad_z_vector_tmp[2] = 0.0F;
  rtb_quad_z_vector_tmp[5] = 0.0F;
  rtb_quad_z_vector_tmp[8] = 1.0F;
  rtb_TSamp = 2.0F * Quaternion_single_axis_contro_U.qx *
    Quaternion_single_axis_contro_U.qz;
  rtb_Gain = 2.0F * Quaternion_single_axis_contro_U.qw *
    Quaternion_single_axis_contro_U.qy;
  tmp = rtb_TSamp + rtb_Gain;
  tmp_0 = 2.0F * Quaternion_single_axis_contro_U.qy *
    Quaternion_single_axis_contro_U.qz - 2.0F *
    Quaternion_single_axis_contro_U.qw * Quaternion_single_axis_contro_U.qx;
  tmp_2 = Quaternion_single_axis_contro_U.qw *
    Quaternion_single_axis_contro_U.qw;
  tmp_3 = Quaternion_single_axis_contro_U.qx *
    Quaternion_single_axis_contro_U.qx;
  tmp_4 = Quaternion_single_axis_contro_U.qy *
    Quaternion_single_axis_contro_U.qy;
  tmp_5 = Quaternion_single_axis_contro_U.qz *
    Quaternion_single_axis_contro_U.qz;
  tmp_1 = ((tmp_2 - tmp_3) - tmp_4) + tmp_5;

  /* DotProduct: '<Root>/Dot Product' */
  rtb_Sum1 = 0.0F;
  for (i = 0; i < 3; i++) {
    /* DotProduct: '<Root>/Dot Product' incorporates:
     *  MATLAB Function: '<Root>/MATLAB Function1'
     */
    rtb_Sum1 += (rtb_quad_z_vector_tmp[i + 6] * tmp_1 + (rtb_quad_z_vector_tmp[i
      + 3] * tmp_0 + rtb_quad_z_vector_tmp[i] * tmp)) * rtb_base_z_vector[i];
  }

  /* MATLAB Function: '<Root>/MATLAB Function5' incorporates:
   *  DotProduct: '<Root>/Dot Product'
   *  DotProduct: '<Root>/Dot Product1'
   */
  if (rtb_Sum1 >= 0.0F) {
    /* MATLAB Function: '<Root>/MATLAB Function3' incorporates:
     *  Inport: '<Root>/index'
     *  Inport: '<Root>/qw'
     *  Inport: '<Root>/qx'
     *  Inport: '<Root>/qy'
     *  Inport: '<Root>/qz'
     */
    rtb_quad_z_vector_tmp[0] = rtb_quad_z_vector_tmp_tmp;
    rtb_quad_z_vector_tmp[3] = -sinf(-Quaternion_single_axis_contro_U.index *
      3.14159274F / 2.0F);
    rtb_quad_z_vector_tmp[6] = 0.0F;
    rtb_quad_z_vector_tmp[1] = rtb_quad_z_vector_tmp_tmp_0;
    rtb_quad_z_vector_tmp[4] = rtb_quad_z_vector_tmp_tmp;
    rtb_quad_z_vector_tmp[7] = 0.0F;
    rtb_quad_z_vector_tmp[2] = 0.0F;
    rtb_quad_z_vector_tmp[5] = 0.0F;
    rtb_quad_z_vector_tmp[8] = 1.0F;
    tmp = ((Quaternion_single_axis_contro_U.qw *
            Quaternion_single_axis_contro_U.qw +
            Quaternion_single_axis_contro_U.qx *
            Quaternion_single_axis_contro_U.qx) -
           Quaternion_single_axis_contro_U.qy *
           Quaternion_single_axis_contro_U.qy) -
      Quaternion_single_axis_contro_U.qz * Quaternion_single_axis_contro_U.qz;
    rtb_quad_z_vector_tmp_tmp = 2.0F * Quaternion_single_axis_contro_U.qx *
      Quaternion_single_axis_contro_U.qy + 2.0F *
      Quaternion_single_axis_contro_U.qz * Quaternion_single_axis_contro_U.qw;
    rtb_Gain = 2.0F * Quaternion_single_axis_contro_U.qx *
      Quaternion_single_axis_contro_U.qz - 2.0F *
      Quaternion_single_axis_contro_U.qw * Quaternion_single_axis_contro_U.qy;

    /* DotProduct: '<Root>/Dot Product1' */
    rtb_TSamp = 0.0F;
    for (i = 0; i < 3; i++) {
      /* DotProduct: '<Root>/Dot Product1' incorporates:
       *  MATLAB Function: '<Root>/MATLAB Function3'
       */
      rtb_TSamp += (rtb_quad_z_vector_tmp[i + 6] * rtb_Gain +
                    (rtb_quad_z_vector_tmp[i + 3] * rtb_quad_z_vector_tmp_tmp +
                     rtb_quad_z_vector_tmp[i] * tmp)) * rtb_base_z_vector[i];
    }

    Quaternion_single_axis_contro_Y.theta_meas = acosf(rtb_TSamp) - 1.57079637F;
  } else {
    /* MATLAB Function: '<Root>/MATLAB Function3' incorporates:
     *  Inport: '<Root>/index'
     *  Inport: '<Root>/qw'
     *  Inport: '<Root>/qx'
     *  Inport: '<Root>/qy'
     *  Inport: '<Root>/qz'
     */
    rtb_quad_z_vector_tmp[0] = rtb_quad_z_vector_tmp_tmp;
    rtb_quad_z_vector_tmp[3] = -sinf(-Quaternion_single_axis_contro_U.index *
      3.14159274F / 2.0F);
    rtb_quad_z_vector_tmp[6] = 0.0F;
    rtb_quad_z_vector_tmp[1] = rtb_quad_z_vector_tmp_tmp_0;
    rtb_quad_z_vector_tmp[4] = rtb_quad_z_vector_tmp_tmp;
    rtb_quad_z_vector_tmp[7] = 0.0F;
    rtb_quad_z_vector_tmp[2] = 0.0F;
    rtb_quad_z_vector_tmp[5] = 0.0F;
    rtb_quad_z_vector_tmp[8] = 1.0F;
    tmp = ((tmp_2 + tmp_3) - tmp_4) - tmp_5;
    rtb_quad_z_vector_tmp_tmp = 2.0F * Quaternion_single_axis_contro_U.qx *
      Quaternion_single_axis_contro_U.qy + 2.0F *
      Quaternion_single_axis_contro_U.qz * Quaternion_single_axis_contro_U.qw;
    rtb_Gain = rtb_TSamp - rtb_Gain;

    /* DotProduct: '<Root>/Dot Product1' */
    rtb_TSamp = 0.0F;
    for (i = 0; i < 3; i++) {
      /* DotProduct: '<Root>/Dot Product1' incorporates:
       *  MATLAB Function: '<Root>/MATLAB Function3'
       */
      rtb_TSamp += (rtb_quad_z_vector_tmp[i + 6] * rtb_Gain +
                    (rtb_quad_z_vector_tmp[i + 3] * rtb_quad_z_vector_tmp_tmp +
                     rtb_quad_z_vector_tmp[i] * tmp)) * rtb_base_z_vector[i];
    }

    if (rtb_TSamp <= 0.0F) {
      Quaternion_single_axis_contro_Y.theta_meas = acosf(rtb_Sum1);
    } else {
      Quaternion_single_axis_contro_Y.theta_meas = -acosf(rtb_Sum1);
    }
  }

  /* End of MATLAB Function: '<Root>/MATLAB Function5' */

  /* Saturate: '<Root>/Saturation2' incorporates:
   *  Inport: '<Root>/theta'
   */
  if (Quaternion_single_axis_contro_U.theta >
      Quaternion_single_axis_contro_P.theta_cmd_sat) {
    rtb_TSamp = Quaternion_single_axis_contro_P.theta_cmd_sat;
  } else if (Quaternion_single_axis_contro_U.theta <
             Quaternion_single_axis_contro_P.Saturation2_LowerSat) {
    rtb_TSamp = Quaternion_single_axis_contro_P.Saturation2_LowerSat;
  } else {
    rtb_TSamp = Quaternion_single_axis_contro_U.theta;
  }

  /* End of Saturate: '<Root>/Saturation2' */

  /* Sum: '<Root>/Sum1' incorporates:
   *  Gain: '<Root>/pitch_P'
   *  Inport: '<Root>/q'
   *  Sum: '<Root>/Sum4'
   */
  rtb_Sum1 = (Quaternion_single_axis_contro_Y.theta_meas - rtb_TSamp) *
    Quaternion_single_axis_contro_P.pitch_P - Quaternion_single_axis_contro_U.q;

  /* SampleTimeMath: '<S1>/TSamp'
   *
   * About '<S1>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   */
  rtb_TSamp = rtb_Sum1 * Quaternion_single_axis_contro_P.TSamp_WtEt;

  /* Gain: '<Root>/Gain' incorporates:
   *  DiscreteIntegrator: '<Root>/Discrete-Time Integrator1'
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
  rtb_Gain = ((Quaternion_single_axis_contro_P.pitch_rate_P * rtb_Sum1 +
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
    rtb_quad_z_vector_tmp_tmp =
      Quaternion_single_axis_contro_P.Saturation1_UpperSat;
  } else if (Quaternion_single_axis_contro_U.thrust <
             Quaternion_single_axis_contro_P.Saturation1_LowerSat) {
    rtb_quad_z_vector_tmp_tmp =
      Quaternion_single_axis_contro_P.Saturation1_LowerSat;
  } else {
    rtb_quad_z_vector_tmp_tmp = Quaternion_single_axis_contro_U.thrust;
  }

  /* MATLAB Function: '<S6>/cmd2force' incorporates:
   *  Inport: '<Root>/mx'
   *  Saturate: '<Root>/Saturation1'
   */
  tmp = Quaternion_single_axis_contro_U.mx / 0.1266F;
  for (i = 0; i < 4; i++) {
    rtb_quad_z_vector_tmp_tmp_0 = b[i + 12] * rtb_quad_z_vector_tmp_tmp + (b[i +
      8] * 0.0F + (b[i + 4] * rtb_Gain + b[i] * tmp));

    /* Saturate: '<S6>/Saturation' incorporates:
     *  Saturate: '<Root>/Saturation1'
     */
    if (rtb_quad_z_vector_tmp_tmp_0 >
        Quaternion_single_axis_contro_P.Saturation_UpperSat_d) {
      rtb_quad_z_vector_tmp_tmp_0 =
        Quaternion_single_axis_contro_P.Saturation_UpperSat_d;
    } else {
      if (rtb_quad_z_vector_tmp_tmp_0 <
          Quaternion_single_axis_contro_P.Saturation_LowerSat_l) {
        rtb_quad_z_vector_tmp_tmp_0 =
          Quaternion_single_axis_contro_P.Saturation_LowerSat_l;
      }
    }

    /* End of Saturate: '<S6>/Saturation' */

    /* MATLAB Function: '<S6>/force2motorCMD' */
    rtb_omega_cmd = (sqrtf(0.366F * rtb_quad_z_vector_tmp_tmp_0 + 0.00457922881F)
                     + -0.06767F) * 65536.0F / 0.183F;

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

  /* Outport: '<Root>/my' incorporates:
   *  MATLAB Function: '<S6>/cmd2force'
   */
  Quaternion_single_axis_contro_Y.my = rtb_Gain * 4.0F * 0.03165F;

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
  (void)memset(&Quaternion_single_axis_contro_U, 0, sizeof
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

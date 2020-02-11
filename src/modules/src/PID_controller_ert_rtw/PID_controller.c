/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: PID_controller.c
 *
 * Code generated for Simulink model 'PID_controller'.
 *
 * Model version                  : 1.6
 * Simulink Coder version         : 8.14 (R2018a) 06-Feb-2018
 * C/C++ source code generated on : Wed Oct 30 09:59:37 2019
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "PID_controller.h"
#include "PID_controller_private.h"

/* Block states (default storage) */
DW_PID_controller_T PID_controller_DW;

/* External inputs (root inport signals with default storage) */
ExtU_PID_controller_T PID_controller_U;

/* External outputs (root outports fed by signals with default storage) */
ExtY_PID_controller_T PID_controller_Y;

/* Real-time model */
RT_MODEL_PID_controller_T PID_controller_M_;
RT_MODEL_PID_controller_T *const PID_controller_M = &PID_controller_M_;

/* Model step function */
void PID_controller_step(void)
{
  real32_T rtb_Sum2;
  real32_T rtb_Sum1;
  real32_T rtb_TSamp;
  real32_T rtb_Sum5;
  real32_T rtb_Sum4;
  real32_T rtb_TSamp_pb;
  real32_T rtb_Sum8;
  real32_T rtb_Sum7;
  real32_T rtb_TSamp_j;
  real32_T u0;

  /* Sum: '<Root>/Sum2' incorporates:
   *  Inport: '<Root>/roll_sensor'
   *  Inport: '<Root>/roll_setpoint'
   */
  rtb_Sum2 = PID_controller_U.roll_setpoint - PID_controller_U.roll_sensor;

  /* Sum: '<Root>/Sum1' incorporates:
   *  DiscreteIntegrator: '<Root>/Discrete-Time Integrator5'
   *  Gain: '<Root>/roll_I'
   *  Gain: '<Root>/roll_P'
   *  Inport: '<Root>/roll_rate_sensor'
   *  Sum: '<Root>/Sum11'
   */
  rtb_Sum1 = (PID_controller_P.roll_P_Gain * rtb_Sum2 +
              PID_controller_P.roll_I_Gain *
              PID_controller_DW.DiscreteTimeIntegrator5_DSTATE) -
    PID_controller_U.roll_rate_sensor;

  /* SampleTimeMath: '<S3>/TSamp'
   *
   * About '<S3>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   */
  rtb_TSamp = rtb_Sum1 * PID_controller_P.TSamp_WtEt;

  /* Sum: '<Root>/Sum' incorporates:
   *  DiscreteIntegrator: '<Root>/Discrete-Time Integrator'
   *  Gain: '<Root>/roll_rate_D'
   *  Gain: '<Root>/roll_rate_I'
   *  Gain: '<Root>/roll_rate_P'
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
  u0 = (PID_controller_P.roll_rate_P_Gain * rtb_Sum1 +
        PID_controller_P.roll_rate_I_Gain *
        PID_controller_DW.DiscreteTimeIntegrator_DSTATE) + (rtb_TSamp -
    PID_controller_DW.UD_DSTATE) * PID_controller_P.roll_rate_D_Gain;

  /* Saturate: '<Root>/Saturation' */
  if (u0 > PID_controller_P.Saturation_UpperSat) {
    u0 = PID_controller_P.Saturation_UpperSat;
  } else {
    if (u0 < PID_controller_P.Saturation_LowerSat) {
      u0 = PID_controller_P.Saturation_LowerSat;
    }
  }

  /* End of Saturate: '<Root>/Saturation' */

  /* DataTypeConversion: '<Root>/Data Type  Conversion' */
  u0 = floorf(u0);
  if (rtIsNaNF(u0) || rtIsInfF(u0)) {
    u0 = 0.0F;
  } else {
    u0 = fmodf(u0, 65536.0F);
  }

  /* Outport: '<Root>/roll_output' incorporates:
   *  DataTypeConversion: '<Root>/Data Type  Conversion'
   */
  PID_controller_Y.roll_output = (int16_T)(u0 < 0.0F ? (int32_T)(int16_T)
    -(int16_T)(uint16_T)-u0 : (int32_T)(int16_T)(uint16_T)u0);

  /* Sum: '<Root>/Sum5' incorporates:
   *  Inport: '<Root>/pitch_sensor'
   *  Inport: '<Root>/pitch_setpoint'
   */
  rtb_Sum5 = PID_controller_U.pitch_setpoint - PID_controller_U.pitch_sensor;

  /* Sum: '<Root>/Sum4' incorporates:
   *  DiscreteIntegrator: '<Root>/Discrete-Time Integrator4'
   *  Gain: '<Root>/pitch_I'
   *  Gain: '<Root>/pitch_P'
   *  Inport: '<Root>/pitch_rate_sensor'
   *  Sum: '<Root>/Sum10'
   */
  rtb_Sum4 = (PID_controller_P.pitch_P_Gain * rtb_Sum5 +
              PID_controller_P.pitch_I_Gain *
              PID_controller_DW.DiscreteTimeIntegrator4_DSTATE) -
    PID_controller_U.pitch_rate_sensor;

  /* SampleTimeMath: '<S2>/TSamp'
   *
   * About '<S2>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   */
  rtb_TSamp_pb = rtb_Sum4 * PID_controller_P.TSamp_WtEt_f;

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
  u0 = (PID_controller_P.pitch_rate_P_Gain * rtb_Sum4 +
        PID_controller_P.pitch_rate_I_Gain *
        PID_controller_DW.DiscreteTimeIntegrator1_DSTATE) + (rtb_TSamp_pb -
    PID_controller_DW.UD_DSTATE_d) * PID_controller_P.pitch_rate_D_Gain;

  /* Saturate: '<Root>/Saturation1' */
  if (u0 > PID_controller_P.Saturation1_UpperSat) {
    u0 = PID_controller_P.Saturation1_UpperSat;
  } else {
    if (u0 < PID_controller_P.Saturation1_LowerSat) {
      u0 = PID_controller_P.Saturation1_LowerSat;
    }
  }

  /* End of Saturate: '<Root>/Saturation1' */

  /* DataTypeConversion: '<Root>/Data Type  Conversion1' */
  u0 = floorf(u0);
  if (rtIsNaNF(u0) || rtIsInfF(u0)) {
    u0 = 0.0F;
  } else {
    u0 = fmodf(u0, 65536.0F);
  }

  /* Outport: '<Root>/pitch_output' incorporates:
   *  DataTypeConversion: '<Root>/Data Type  Conversion1'
   */
  PID_controller_Y.pitch_output = (int16_T)(u0 < 0.0F ? (int32_T)(int16_T)
    -(int16_T)(uint16_T)-u0 : (int32_T)(int16_T)(uint16_T)u0);

  /* Sum: '<Root>/Sum8' incorporates:
   *  Inport: '<Root>/yaw_sensor'
   *  Inport: '<Root>/yaw_setpoint'
   */
  rtb_Sum8 = PID_controller_U.yaw_setpoint - PID_controller_U.yaw_sensor;

  /* Sum: '<Root>/Sum7' incorporates:
   *  DiscreteIntegrator: '<Root>/Discrete-Time Integrator3'
   *  Gain: '<Root>/yaw_I'
   *  Gain: '<Root>/yaw_P'
   *  Inport: '<Root>/yaw_rate_sensor'
   *  Sum: '<Root>/Sum9'
   */
  rtb_Sum7 = (PID_controller_P.yaw_P_Gain * rtb_Sum8 +
              PID_controller_P.yaw_I_Gain *
              PID_controller_DW.DiscreteTimeIntegrator3_DSTATE) -
    PID_controller_U.yaw_rate_sensor;

  /* SampleTimeMath: '<S1>/TSamp'
   *
   * About '<S1>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   */
  rtb_TSamp_j = rtb_Sum7 * PID_controller_P.TSamp_WtEt_k;

  /* Sum: '<Root>/Sum6' incorporates:
   *  DiscreteIntegrator: '<Root>/Discrete-Time Integrator2'
   *  Gain: '<Root>/yaw_rate_D'
   *  Gain: '<Root>/yaw_rate_I'
   *  Gain: '<Root>/yaw_rate_P'
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
  u0 = (PID_controller_P.yaw_rate_P_Gain * rtb_Sum7 +
        PID_controller_P.yaw_rate_I_Gain *
        PID_controller_DW.DiscreteTimeIntegrator2_DSTATE) + (rtb_TSamp_j -
    PID_controller_DW.UD_DSTATE_m) * PID_controller_P.yaw_rate_D_Gain;

  /* Saturate: '<Root>/Saturation2' */
  if (u0 > PID_controller_P.Saturation2_UpperSat) {
    u0 = PID_controller_P.Saturation2_UpperSat;
  } else {
    if (u0 < PID_controller_P.Saturation2_LowerSat) {
      u0 = PID_controller_P.Saturation2_LowerSat;
    }
  }

  /* End of Saturate: '<Root>/Saturation2' */

  /* DataTypeConversion: '<Root>/Data Type  Conversion2' */
  u0 = floorf(u0);
  if (rtIsNaNF(u0) || rtIsInfF(u0)) {
    u0 = 0.0F;
  } else {
    u0 = fmodf(u0, 65536.0F);
  }

  /* Outport: '<Root>/yaw_output' incorporates:
   *  DataTypeConversion: '<Root>/Data Type  Conversion2'
   */
  PID_controller_Y.yaw_output = (int16_T)(u0 < 0.0F ? (int32_T)(int16_T)
    -(int16_T)(uint16_T)-u0 : (int32_T)(int16_T)(uint16_T)u0);

  /* Outport: '<Root>/thrust_output' incorporates:
   *  Inport: '<Root>/thrust '
   */
  PID_controller_Y.thrust_output = PID_controller_U.thrust;

  /* Update for DiscreteIntegrator: '<Root>/Discrete-Time Integrator5' */
  PID_controller_DW.DiscreteTimeIntegrator5_DSTATE +=
    PID_controller_P.DiscreteTimeIntegrator5_gainval * rtb_Sum2;
  if (PID_controller_DW.DiscreteTimeIntegrator5_DSTATE >=
      PID_controller_P.DiscreteTimeIntegrator5_UpperSa) {
    PID_controller_DW.DiscreteTimeIntegrator5_DSTATE =
      PID_controller_P.DiscreteTimeIntegrator5_UpperSa;
  } else {
    if (PID_controller_DW.DiscreteTimeIntegrator5_DSTATE <=
        PID_controller_P.DiscreteTimeIntegrator5_LowerSa) {
      PID_controller_DW.DiscreteTimeIntegrator5_DSTATE =
        PID_controller_P.DiscreteTimeIntegrator5_LowerSa;
    }
  }

  /* End of Update for DiscreteIntegrator: '<Root>/Discrete-Time Integrator5' */

  /* Update for DiscreteIntegrator: '<Root>/Discrete-Time Integrator' */
  PID_controller_DW.DiscreteTimeIntegrator_DSTATE +=
    PID_controller_P.DiscreteTimeIntegrator_gainval * rtb_Sum1;
  if (PID_controller_DW.DiscreteTimeIntegrator_DSTATE >=
      PID_controller_P.DiscreteTimeIntegrator_UpperSat) {
    PID_controller_DW.DiscreteTimeIntegrator_DSTATE =
      PID_controller_P.DiscreteTimeIntegrator_UpperSat;
  } else {
    if (PID_controller_DW.DiscreteTimeIntegrator_DSTATE <=
        PID_controller_P.DiscreteTimeIntegrator_LowerSat) {
      PID_controller_DW.DiscreteTimeIntegrator_DSTATE =
        PID_controller_P.DiscreteTimeIntegrator_LowerSat;
    }
  }

  /* End of Update for DiscreteIntegrator: '<Root>/Discrete-Time Integrator' */

  /* Update for UnitDelay: '<S3>/UD'
   *
   * Block description for '<S3>/UD':
   *
   *  Store in Global RAM
   */
  PID_controller_DW.UD_DSTATE = rtb_TSamp;

  /* Update for DiscreteIntegrator: '<Root>/Discrete-Time Integrator4' */
  PID_controller_DW.DiscreteTimeIntegrator4_DSTATE +=
    PID_controller_P.DiscreteTimeIntegrator4_gainval * rtb_Sum5;
  if (PID_controller_DW.DiscreteTimeIntegrator4_DSTATE >=
      PID_controller_P.DiscreteTimeIntegrator4_UpperSa) {
    PID_controller_DW.DiscreteTimeIntegrator4_DSTATE =
      PID_controller_P.DiscreteTimeIntegrator4_UpperSa;
  } else {
    if (PID_controller_DW.DiscreteTimeIntegrator4_DSTATE <=
        PID_controller_P.DiscreteTimeIntegrator4_LowerSa) {
      PID_controller_DW.DiscreteTimeIntegrator4_DSTATE =
        PID_controller_P.DiscreteTimeIntegrator4_LowerSa;
    }
  }

  /* End of Update for DiscreteIntegrator: '<Root>/Discrete-Time Integrator4' */

  /* Update for DiscreteIntegrator: '<Root>/Discrete-Time Integrator1' */
  PID_controller_DW.DiscreteTimeIntegrator1_DSTATE +=
    PID_controller_P.DiscreteTimeIntegrator1_gainval * rtb_Sum4;
  if (PID_controller_DW.DiscreteTimeIntegrator1_DSTATE >=
      PID_controller_P.DiscreteTimeIntegrator1_UpperSa) {
    PID_controller_DW.DiscreteTimeIntegrator1_DSTATE =
      PID_controller_P.DiscreteTimeIntegrator1_UpperSa;
  } else {
    if (PID_controller_DW.DiscreteTimeIntegrator1_DSTATE <=
        PID_controller_P.DiscreteTimeIntegrator1_LowerSa) {
      PID_controller_DW.DiscreteTimeIntegrator1_DSTATE =
        PID_controller_P.DiscreteTimeIntegrator1_LowerSa;
    }
  }

  /* End of Update for DiscreteIntegrator: '<Root>/Discrete-Time Integrator1' */

  /* Update for UnitDelay: '<S2>/UD'
   *
   * Block description for '<S2>/UD':
   *
   *  Store in Global RAM
   */
  PID_controller_DW.UD_DSTATE_d = rtb_TSamp_pb;

  /* Update for DiscreteIntegrator: '<Root>/Discrete-Time Integrator3' */
  PID_controller_DW.DiscreteTimeIntegrator3_DSTATE +=
    PID_controller_P.DiscreteTimeIntegrator3_gainval * rtb_Sum8;
  if (PID_controller_DW.DiscreteTimeIntegrator3_DSTATE >=
      PID_controller_P.DiscreteTimeIntegrator3_UpperSa) {
    PID_controller_DW.DiscreteTimeIntegrator3_DSTATE =
      PID_controller_P.DiscreteTimeIntegrator3_UpperSa;
  } else {
    if (PID_controller_DW.DiscreteTimeIntegrator3_DSTATE <=
        PID_controller_P.DiscreteTimeIntegrator3_LowerSa) {
      PID_controller_DW.DiscreteTimeIntegrator3_DSTATE =
        PID_controller_P.DiscreteTimeIntegrator3_LowerSa;
    }
  }

  /* End of Update for DiscreteIntegrator: '<Root>/Discrete-Time Integrator3' */

  /* Update for DiscreteIntegrator: '<Root>/Discrete-Time Integrator2' */
  PID_controller_DW.DiscreteTimeIntegrator2_DSTATE +=
    PID_controller_P.DiscreteTimeIntegrator2_gainval * rtb_Sum7;
  if (PID_controller_DW.DiscreteTimeIntegrator2_DSTATE >=
      PID_controller_P.DiscreteTimeIntegrator2_UpperSa) {
    PID_controller_DW.DiscreteTimeIntegrator2_DSTATE =
      PID_controller_P.DiscreteTimeIntegrator2_UpperSa;
  } else {
    if (PID_controller_DW.DiscreteTimeIntegrator2_DSTATE <=
        PID_controller_P.DiscreteTimeIntegrator2_LowerSa) {
      PID_controller_DW.DiscreteTimeIntegrator2_DSTATE =
        PID_controller_P.DiscreteTimeIntegrator2_LowerSa;
    }
  }

  /* End of Update for DiscreteIntegrator: '<Root>/Discrete-Time Integrator2' */

  /* Update for UnitDelay: '<S1>/UD'
   *
   * Block description for '<S1>/UD':
   *
   *  Store in Global RAM
   */
  PID_controller_DW.UD_DSTATE_m = rtb_TSamp_j;
}

/* Model initialize function */
void PID_controller_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize error status */
  rtmSetErrorStatus(PID_controller_M, (NULL));

  /* states (dwork) */
  (void) memset((void *)&PID_controller_DW, 0,
                sizeof(DW_PID_controller_T));

  /* external inputs */
  (void)memset((void *)&PID_controller_U, 0, sizeof(ExtU_PID_controller_T));

  /* external outputs */
  (void) memset((void *)&PID_controller_Y, 0,
                sizeof(ExtY_PID_controller_T));

  /* InitializeConditions for DiscreteIntegrator: '<Root>/Discrete-Time Integrator5' */
  PID_controller_DW.DiscreteTimeIntegrator5_DSTATE =
    PID_controller_P.DiscreteTimeIntegrator5_IC;

  /* InitializeConditions for DiscreteIntegrator: '<Root>/Discrete-Time Integrator' */
  PID_controller_DW.DiscreteTimeIntegrator_DSTATE =
    PID_controller_P.DiscreteTimeIntegrator_IC;

  /* InitializeConditions for UnitDelay: '<S3>/UD'
   *
   * Block description for '<S3>/UD':
   *
   *  Store in Global RAM
   */
  PID_controller_DW.UD_DSTATE = PID_controller_P.DiscreteDerivative2_ICPrevScale;

  /* InitializeConditions for DiscreteIntegrator: '<Root>/Discrete-Time Integrator4' */
  PID_controller_DW.DiscreteTimeIntegrator4_DSTATE =
    PID_controller_P.DiscreteTimeIntegrator4_IC;

  /* InitializeConditions for DiscreteIntegrator: '<Root>/Discrete-Time Integrator1' */
  PID_controller_DW.DiscreteTimeIntegrator1_DSTATE =
    PID_controller_P.DiscreteTimeIntegrator1_IC;

  /* InitializeConditions for UnitDelay: '<S2>/UD'
   *
   * Block description for '<S2>/UD':
   *
   *  Store in Global RAM
   */
  PID_controller_DW.UD_DSTATE_d =
    PID_controller_P.DiscreteDerivative1_ICPrevScale;

  /* InitializeConditions for DiscreteIntegrator: '<Root>/Discrete-Time Integrator3' */
  PID_controller_DW.DiscreteTimeIntegrator3_DSTATE =
    PID_controller_P.DiscreteTimeIntegrator3_IC;

  /* InitializeConditions for DiscreteIntegrator: '<Root>/Discrete-Time Integrator2' */
  PID_controller_DW.DiscreteTimeIntegrator2_DSTATE =
    PID_controller_P.DiscreteTimeIntegrator2_IC;

  /* InitializeConditions for UnitDelay: '<S1>/UD'
   *
   * Block description for '<S1>/UD':
   *
   *  Store in Global RAM
   */
  PID_controller_DW.UD_DSTATE_m =
    PID_controller_P.DiscreteDerivative_ICPrevScaled;
}

/* Model terminate function */
void PID_controller_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

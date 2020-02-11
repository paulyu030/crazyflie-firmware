/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: PID_controller.h
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

#ifndef RTW_HEADER_PID_controller_h_
#define RTW_HEADER_PID_controller_h_
#include <math.h>
#include <string.h>
#include <stddef.h>
#ifndef PID_controller_COMMON_INCLUDES_
# define PID_controller_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* PID_controller_COMMON_INCLUDES_ */

#include "PID_controller_types.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real32_T DiscreteTimeIntegrator5_DSTATE;/* '<Root>/Discrete-Time Integrator5' */
  real32_T DiscreteTimeIntegrator_DSTATE;/* '<Root>/Discrete-Time Integrator' */
  real32_T UD_DSTATE;                  /* '<S3>/UD' */
  real32_T DiscreteTimeIntegrator4_DSTATE;/* '<Root>/Discrete-Time Integrator4' */
  real32_T DiscreteTimeIntegrator1_DSTATE;/* '<Root>/Discrete-Time Integrator1' */
  real32_T UD_DSTATE_d;                /* '<S2>/UD' */
  real32_T DiscreteTimeIntegrator3_DSTATE;/* '<Root>/Discrete-Time Integrator3' */
  real32_T DiscreteTimeIntegrator2_DSTATE;/* '<Root>/Discrete-Time Integrator2' */
  real32_T UD_DSTATE_m;                /* '<S1>/UD' */
} DW_PID_controller_T;

/* External inputs (root inport signals with default storage) */
typedef struct {
  real32_T roll_setpoint;              /* '<Root>/roll_setpoint' */
  real32_T roll_sensor;                /* '<Root>/roll_sensor' */
  real32_T roll_rate_sensor;           /* '<Root>/roll_rate_sensor' */
  real32_T pitch_setpoint;             /* '<Root>/pitch_setpoint' */
  real32_T pitch_sensor;               /* '<Root>/pitch_sensor' */
  real32_T pitch_rate_sensor;          /* '<Root>/pitch_rate_sensor' */
  real32_T yaw_setpoint;               /* '<Root>/yaw_setpoint' */
  real32_T yaw_sensor;                 /* '<Root>/yaw_sensor' */
  real32_T yaw_rate_sensor;            /* '<Root>/yaw_rate_sensor' */
  real32_T thrust;                     /* '<Root>/thrust ' */
} ExtU_PID_controller_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  int16_T roll_output;                 /* '<Root>/roll_output' */
  int16_T pitch_output;                /* '<Root>/pitch_output' */
  int16_T yaw_output;                  /* '<Root>/yaw_output' */
  real32_T thrust_output;              /* '<Root>/thrust_output' */
} ExtY_PID_controller_T;

/* Parameters (default storage) */
struct P_PID_controller_T_ {
  real32_T DiscreteDerivative2_ICPrevScale;/* Mask Parameter: DiscreteDerivative2_ICPrevScale
                                            * Referenced by: '<S3>/UD'
                                            */
  real32_T DiscreteDerivative1_ICPrevScale;/* Mask Parameter: DiscreteDerivative1_ICPrevScale
                                            * Referenced by: '<S2>/UD'
                                            */
  real32_T DiscreteDerivative_ICPrevScaled;/* Mask Parameter: DiscreteDerivative_ICPrevScaled
                                            * Referenced by: '<S1>/UD'
                                            */
  real32_T roll_P_Gain;                /* Computed Parameter: roll_P_Gain
                                        * Referenced by: '<Root>/roll_P'
                                        */
  real32_T DiscreteTimeIntegrator5_gainval;/* Computed Parameter: DiscreteTimeIntegrator5_gainval
                                            * Referenced by: '<Root>/Discrete-Time Integrator5'
                                            */
  real32_T DiscreteTimeIntegrator5_IC; /* Computed Parameter: DiscreteTimeIntegrator5_IC
                                        * Referenced by: '<Root>/Discrete-Time Integrator5'
                                        */
  real32_T DiscreteTimeIntegrator5_UpperSa;/* Computed Parameter: DiscreteTimeIntegrator5_UpperSa
                                            * Referenced by: '<Root>/Discrete-Time Integrator5'
                                            */
  real32_T DiscreteTimeIntegrator5_LowerSa;/* Computed Parameter: DiscreteTimeIntegrator5_LowerSa
                                            * Referenced by: '<Root>/Discrete-Time Integrator5'
                                            */
  real32_T roll_I_Gain;                /* Computed Parameter: roll_I_Gain
                                        * Referenced by: '<Root>/roll_I'
                                        */
  real32_T roll_rate_P_Gain;           /* Computed Parameter: roll_rate_P_Gain
                                        * Referenced by: '<Root>/roll_rate_P'
                                        */
  real32_T DiscreteTimeIntegrator_gainval;/* Computed Parameter: DiscreteTimeIntegrator_gainval
                                           * Referenced by: '<Root>/Discrete-Time Integrator'
                                           */
  real32_T DiscreteTimeIntegrator_IC;  /* Computed Parameter: DiscreteTimeIntegrator_IC
                                        * Referenced by: '<Root>/Discrete-Time Integrator'
                                        */
  real32_T DiscreteTimeIntegrator_UpperSat;/* Computed Parameter: DiscreteTimeIntegrator_UpperSat
                                            * Referenced by: '<Root>/Discrete-Time Integrator'
                                            */
  real32_T DiscreteTimeIntegrator_LowerSat;/* Computed Parameter: DiscreteTimeIntegrator_LowerSat
                                            * Referenced by: '<Root>/Discrete-Time Integrator'
                                            */
  real32_T roll_rate_I_Gain;           /* Computed Parameter: roll_rate_I_Gain
                                        * Referenced by: '<Root>/roll_rate_I'
                                        */
  real32_T TSamp_WtEt;                 /* Computed Parameter: TSamp_WtEt
                                        * Referenced by: '<S3>/TSamp'
                                        */
  real32_T roll_rate_D_Gain;           /* Computed Parameter: roll_rate_D_Gain
                                        * Referenced by: '<Root>/roll_rate_D'
                                        */
  real32_T Saturation_UpperSat;        /* Computed Parameter: Saturation_UpperSat
                                        * Referenced by: '<Root>/Saturation'
                                        */
  real32_T Saturation_LowerSat;        /* Computed Parameter: Saturation_LowerSat
                                        * Referenced by: '<Root>/Saturation'
                                        */
  real32_T pitch_P_Gain;               /* Computed Parameter: pitch_P_Gain
                                        * Referenced by: '<Root>/pitch_P'
                                        */
  real32_T DiscreteTimeIntegrator4_gainval;/* Computed Parameter: DiscreteTimeIntegrator4_gainval
                                            * Referenced by: '<Root>/Discrete-Time Integrator4'
                                            */
  real32_T DiscreteTimeIntegrator4_IC; /* Computed Parameter: DiscreteTimeIntegrator4_IC
                                        * Referenced by: '<Root>/Discrete-Time Integrator4'
                                        */
  real32_T DiscreteTimeIntegrator4_UpperSa;/* Computed Parameter: DiscreteTimeIntegrator4_UpperSa
                                            * Referenced by: '<Root>/Discrete-Time Integrator4'
                                            */
  real32_T DiscreteTimeIntegrator4_LowerSa;/* Computed Parameter: DiscreteTimeIntegrator4_LowerSa
                                            * Referenced by: '<Root>/Discrete-Time Integrator4'
                                            */
  real32_T pitch_I_Gain;               /* Computed Parameter: pitch_I_Gain
                                        * Referenced by: '<Root>/pitch_I'
                                        */
  real32_T pitch_rate_P_Gain;          /* Computed Parameter: pitch_rate_P_Gain
                                        * Referenced by: '<Root>/pitch_rate_P'
                                        */
  real32_T DiscreteTimeIntegrator1_gainval;/* Computed Parameter: DiscreteTimeIntegrator1_gainval
                                            * Referenced by: '<Root>/Discrete-Time Integrator1'
                                            */
  real32_T DiscreteTimeIntegrator1_IC; /* Computed Parameter: DiscreteTimeIntegrator1_IC
                                        * Referenced by: '<Root>/Discrete-Time Integrator1'
                                        */
  real32_T DiscreteTimeIntegrator1_UpperSa;/* Computed Parameter: DiscreteTimeIntegrator1_UpperSa
                                            * Referenced by: '<Root>/Discrete-Time Integrator1'
                                            */
  real32_T DiscreteTimeIntegrator1_LowerSa;/* Computed Parameter: DiscreteTimeIntegrator1_LowerSa
                                            * Referenced by: '<Root>/Discrete-Time Integrator1'
                                            */
  real32_T pitch_rate_I_Gain;          /* Computed Parameter: pitch_rate_I_Gain
                                        * Referenced by: '<Root>/pitch_rate_I'
                                        */
  real32_T TSamp_WtEt_f;               /* Computed Parameter: TSamp_WtEt_f
                                        * Referenced by: '<S2>/TSamp'
                                        */
  real32_T pitch_rate_D_Gain;          /* Computed Parameter: pitch_rate_D_Gain
                                        * Referenced by: '<Root>/pitch_rate_D'
                                        */
  real32_T Saturation1_UpperSat;       /* Computed Parameter: Saturation1_UpperSat
                                        * Referenced by: '<Root>/Saturation1'
                                        */
  real32_T Saturation1_LowerSat;       /* Computed Parameter: Saturation1_LowerSat
                                        * Referenced by: '<Root>/Saturation1'
                                        */
  real32_T yaw_P_Gain;                 /* Computed Parameter: yaw_P_Gain
                                        * Referenced by: '<Root>/yaw_P'
                                        */
  real32_T DiscreteTimeIntegrator3_gainval;/* Computed Parameter: DiscreteTimeIntegrator3_gainval
                                            * Referenced by: '<Root>/Discrete-Time Integrator3'
                                            */
  real32_T DiscreteTimeIntegrator3_IC; /* Computed Parameter: DiscreteTimeIntegrator3_IC
                                        * Referenced by: '<Root>/Discrete-Time Integrator3'
                                        */
  real32_T DiscreteTimeIntegrator3_UpperSa;/* Computed Parameter: DiscreteTimeIntegrator3_UpperSa
                                            * Referenced by: '<Root>/Discrete-Time Integrator3'
                                            */
  real32_T DiscreteTimeIntegrator3_LowerSa;/* Computed Parameter: DiscreteTimeIntegrator3_LowerSa
                                            * Referenced by: '<Root>/Discrete-Time Integrator3'
                                            */
  real32_T yaw_I_Gain;                 /* Computed Parameter: yaw_I_Gain
                                        * Referenced by: '<Root>/yaw_I'
                                        */
  real32_T yaw_rate_P_Gain;            /* Computed Parameter: yaw_rate_P_Gain
                                        * Referenced by: '<Root>/yaw_rate_P'
                                        */
  real32_T DiscreteTimeIntegrator2_gainval;/* Computed Parameter: DiscreteTimeIntegrator2_gainval
                                            * Referenced by: '<Root>/Discrete-Time Integrator2'
                                            */
  real32_T DiscreteTimeIntegrator2_IC; /* Computed Parameter: DiscreteTimeIntegrator2_IC
                                        * Referenced by: '<Root>/Discrete-Time Integrator2'
                                        */
  real32_T DiscreteTimeIntegrator2_UpperSa;/* Computed Parameter: DiscreteTimeIntegrator2_UpperSa
                                            * Referenced by: '<Root>/Discrete-Time Integrator2'
                                            */
  real32_T DiscreteTimeIntegrator2_LowerSa;/* Computed Parameter: DiscreteTimeIntegrator2_LowerSa
                                            * Referenced by: '<Root>/Discrete-Time Integrator2'
                                            */
  real32_T yaw_rate_I_Gain;            /* Computed Parameter: yaw_rate_I_Gain
                                        * Referenced by: '<Root>/yaw_rate_I'
                                        */
  real32_T TSamp_WtEt_k;               /* Computed Parameter: TSamp_WtEt_k
                                        * Referenced by: '<S1>/TSamp'
                                        */
  real32_T yaw_rate_D_Gain;            /* Computed Parameter: yaw_rate_D_Gain
                                        * Referenced by: '<Root>/yaw_rate_D'
                                        */
  real32_T Saturation2_UpperSat;       /* Computed Parameter: Saturation2_UpperSat
                                        * Referenced by: '<Root>/Saturation2'
                                        */
  real32_T Saturation2_LowerSat;       /* Computed Parameter: Saturation2_LowerSat
                                        * Referenced by: '<Root>/Saturation2'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_PID_controller_T {
  const char_T * volatile errorStatus;
};

/* Block parameters (default storage) */
extern P_PID_controller_T PID_controller_P;

/* Block states (default storage) */
extern DW_PID_controller_T PID_controller_DW;

/* External inputs (root inport signals with default storage) */
extern ExtU_PID_controller_T PID_controller_U;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_PID_controller_T PID_controller_Y;

/* Model entry point functions */
extern void PID_controller_initialize(void);
extern void PID_controller_step(void);
extern void PID_controller_terminate(void);

/* Real-time Model object */
extern RT_MODEL_PID_controller_T *const PID_controller_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'PID_controller'
 * '<S1>'   : 'PID_controller/Discrete Derivative'
 * '<S2>'   : 'PID_controller/Discrete Derivative1'
 * '<S3>'   : 'PID_controller/Discrete Derivative2'
 */
#endif                                 /* RTW_HEADER_PID_controller_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

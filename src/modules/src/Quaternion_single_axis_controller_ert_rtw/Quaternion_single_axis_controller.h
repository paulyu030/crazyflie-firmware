/*
 * File: Quaternion_single_axis_controller.h
 *
 * Code generated for Simulink model 'Quaternion_single_axis_controller'.
 *
 * Model version                  : 1.93
 * Simulink Coder version         : 9.3 (R2020a) 18-Nov-2019
 * C/C++ source code generated on : Sat Oct  3 17:40:20 2020
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Quaternion_single_axis_controller_h_
#define RTW_HEADER_Quaternion_single_axis_controller_h_
#include <math.h>
#include <string.h>
#include <stddef.h>
#ifndef Quaternion_single_axis_controller_COMMON_INCLUDES_
# define Quaternion_single_axis_controller_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                  /* Quaternion_single_axis_controller_COMMON_INCLUDES_ */

#include "Quaternion_single_axis_controller_types.h"
#include "rtGetNaN.h"
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
  real32_T DiscreteTimeIntegrator1_DSTATE;/* '<Root>/Discrete-Time Integrator1' */
  real32_T UD_DSTATE;                  /* '<S1>/UD' */
  real32_T last_theta;                 /* '<Root>/Data Store Memory' */
  real32_T rotation_counter;           /* '<Root>/Data Store Memory1' */
} DW_Quaternion_single_axis_con_T;

/* External inputs (root inport signals with default storage) */
typedef struct {
  real32_T qw;                         /* '<Root>/qw' */
  real32_T qx;                         /* '<Root>/qx' */
  real32_T qy;                         /* '<Root>/qy' */
  real32_T qz;                         /* '<Root>/qz' */
  real32_T base_w;                     /* '<Root>/base_w' */
  real32_T base_x;                     /* '<Root>/base_x' */
  real32_T base_y;                     /* '<Root>/base_y' */
  real32_T base_z;                     /* '<Root>/base_z' */
  real32_T theta;                      /* '<Root>/theta' */
  real32_T q;                          /* '<Root>/q' */
  real32_T thrust;                     /* '<Root>/thrust' */
  real32_T index;                      /* '<Root>/index' */
  real32_T mx;                         /* '<Root>/mx' */
} ExtU_Quaternion_single_axis_c_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  uint16_T M1_output;                  /* '<Root>/M1_output' */
  uint16_T M2_output;                  /* '<Root>/M2_output' */
  uint16_T M3_output;                  /* '<Root>/M3_output' */
  uint16_T M4_output;                  /* '<Root>/M4_output' */
  real32_T theta_meas;                 /* '<Root>/theta_meas' */
} ExtY_Quaternion_single_axis_c_T;

/* Parameters (default storage) */
struct P_Quaternion_single_axis_cont_T_ {
  real32_T pitch_P;                    /* Variable: pitch_P
                                        * Referenced by: '<Root>/pitch_P'
                                        */
  real32_T pitch_rate_D;               /* Variable: pitch_rate_D
                                        * Referenced by: '<Root>/pitch_rate_D'
                                        */
  real32_T pitch_rate_I;               /* Variable: pitch_rate_I
                                        * Referenced by: '<Root>/pitch_rate_I'
                                        */
  real32_T pitch_rate_P;               /* Variable: pitch_rate_P
                                        * Referenced by: '<Root>/pitch_rate_P'
                                        */
  real32_T theta_cmd_sat;              /* Variable: theta_cmd_sat
                                        * Referenced by: '<Root>/Saturation2'
                                        */
  real32_T DiscreteDerivative1_ICPrevScale;
                              /* Mask Parameter: DiscreteDerivative1_ICPrevScale
                               * Referenced by: '<S1>/UD'
                               */
  real_T Saturation_UpperSat;          /* Expression: 65535
                                        * Referenced by: '<Root>/Saturation'
                                        */
  real_T Saturation_LowerSat;          /* Expression: 0
                                        * Referenced by: '<Root>/Saturation'
                                        */
  real32_T Saturation2_LowerSat;     /* Computed Parameter: Saturation2_LowerSat
                                      * Referenced by: '<Root>/Saturation2'
                                      */
  real32_T DiscreteTimeIntegrator1_gainval;
                          /* Computed Parameter: DiscreteTimeIntegrator1_gainval
                           * Referenced by: '<Root>/Discrete-Time Integrator1'
                           */
  real32_T DiscreteTimeIntegrator1_IC;
                               /* Computed Parameter: DiscreteTimeIntegrator1_IC
                                * Referenced by: '<Root>/Discrete-Time Integrator1'
                                */
  real32_T DiscreteTimeIntegrator1_UpperSa;
                          /* Computed Parameter: DiscreteTimeIntegrator1_UpperSa
                           * Referenced by: '<Root>/Discrete-Time Integrator1'
                           */
  real32_T DiscreteTimeIntegrator1_LowerSa;
                          /* Computed Parameter: DiscreteTimeIntegrator1_LowerSa
                           * Referenced by: '<Root>/Discrete-Time Integrator1'
                           */
  real32_T TSamp_WtEt;                 /* Computed Parameter: TSamp_WtEt
                                        * Referenced by: '<S1>/TSamp'
                                        */
  real32_T Gain_Gain;                  /* Computed Parameter: Gain_Gain
                                        * Referenced by: '<Root>/Gain'
                                        */
  real32_T Saturation1_UpperSat;     /* Computed Parameter: Saturation1_UpperSat
                                      * Referenced by: '<Root>/Saturation1'
                                      */
  real32_T Saturation1_LowerSat;     /* Computed Parameter: Saturation1_LowerSat
                                      * Referenced by: '<Root>/Saturation1'
                                      */
  real32_T Saturation_UpperSat_d;   /* Computed Parameter: Saturation_UpperSat_d
                                     * Referenced by: '<S6>/Saturation'
                                     */
  real32_T Saturation_LowerSat_l;   /* Computed Parameter: Saturation_LowerSat_l
                                     * Referenced by: '<S6>/Saturation'
                                     */
  real32_T DataStoreMemory_InitialValue;
                             /* Computed Parameter: DataStoreMemory_InitialValue
                              * Referenced by: '<Root>/Data Store Memory'
                              */
  real32_T DataStoreMemory1_InitialValue;
                            /* Computed Parameter: DataStoreMemory1_InitialValue
                             * Referenced by: '<Root>/Data Store Memory1'
                             */
};

/* Real-time Model Data Structure */
struct tag_RTM_Quaternion_single_axi_T {
  const char_T * volatile errorStatus;
};

/* Block parameters (default storage) */
extern P_Quaternion_single_axis_cont_T Quaternion_single_axis_contro_P;

/* Block states (default storage) */
extern DW_Quaternion_single_axis_con_T Quaternion_single_axis_contr_DW;

/* External inputs (root inport signals with default storage) */
extern ExtU_Quaternion_single_axis_c_T Quaternion_single_axis_contro_U;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_Quaternion_single_axis_c_T Quaternion_single_axis_contro_Y;

/* Model entry point functions */
extern void Quaternion_single_axis_controller_initialize(void);
extern void Quaternion_single_axis_controller_step(void);
extern void Quaternion_single_axis_controller_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Quaternion_single_ax_T *const Quaternion_single_axis_contr_M;

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
 * '<Root>' : 'Quaternion_single_axis_controller'
 * '<S1>'   : 'Quaternion_single_axis_controller/Discrete Derivative1'
 * '<S2>'   : 'Quaternion_single_axis_controller/MATLAB Function1'
 * '<S3>'   : 'Quaternion_single_axis_controller/MATLAB Function2'
 * '<S4>'   : 'Quaternion_single_axis_controller/MATLAB Function3'
 * '<S5>'   : 'Quaternion_single_axis_controller/MATLAB Function5'
 * '<S6>'   : 'Quaternion_single_axis_controller/mixer'
 * '<S7>'   : 'Quaternion_single_axis_controller/mixer/cmd2force'
 * '<S8>'   : 'Quaternion_single_axis_controller/mixer/force2motorCMD'
 */
#endif                     /* RTW_HEADER_Quaternion_single_axis_controller_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

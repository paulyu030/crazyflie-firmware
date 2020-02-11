/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: rotor_combined_controller.h
 *
 * Code generated for Simulink model 'rotor_combined_controller'.
 *
 * Model version                  : 1.134
 * Simulink Coder version         : 8.14 (R2018a) 06-Feb-2018
 * C/C++ source code generated on : Fri Dec 27 13:51:40 2019
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_rotor_combined_controller_h_
#define RTW_HEADER_rotor_combined_controller_h_
#include <math.h>
#include <string.h>
#include <stddef.h>
#ifndef rotor_combined_controller_COMMON_INCLUDES_
# define rotor_combined_controller_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* rotor_combined_controller_COMMON_INCLUDES_ */

#include "rotor_combined_controller_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Block states (default storage) for system '<Root>' */
typedef struct {
  struct {
    void *LoggedData;
  } thrust_output_PWORK;               /* '<Root>/thrust_output' */

  struct {
    void *LoggedData;
  } theta_output_PWORK;                /* '<Root>/theta_output' */

  struct {
    void *LoggedData;
  } acc_input_PWORK;                   /* '<Root>/acc_input' */

  real32_T DiscreteTimeIntegrator_DSTATE[3];/* '<S1>/Discrete-Time Integrator' */
  real32_T UD_DSTATE[4];               /* '<S2>/UD' */
  real32_T DiscreteFIRFilter_states[12];/* '<Root>/Discrete FIR Filter' */
  real32_T DiscreteTimeIntegrator_DSTATE_i[3];/* '<S6>/Discrete-Time Integrator' */
  int32_T DiscreteFIRFilter_circBuf;   /* '<Root>/Discrete FIR Filter' */
} DW_rotor_combined_controller_T;

/* External inputs (root inport signals with default storage) */
typedef struct {
  real32_T euler_cmd[3];               /* '<Root>/euler_cmd' */
  real32_T x_ref[3];                   /* '<Root>/x_ref' */
  real32_T euler_f[3];                 /* '<Root>/euler_f' */
  real32_T x_f[3];                     /* '<Root>/x_f' */
  real32_T v_f[3];                     /* '<Root>/v_f' */
  real32_T q_f[4];                     /* '<Root>/q_f' */
} ExtU_rotor_combined_controlle_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real32_T thrust_cmd[4];              /* '<Root>/thrust_cmd' */
  real32_T theta_cmd[4];               /* '<Root>/theta_cmd' */
} ExtY_rotor_combined_controlle_T;

/* Parameters (default storage) */
struct P_rotor_combined_controller_T_ {
  real_T length;                       /* Variable: length
                                        * Referenced by: '<Root>/MATLAB Function'
                                        */
  real32_T K_att;                      /* Variable: K_att
                                        * Referenced by: '<S1>/K_att'
                                        */
  real32_T K_att_dot;                  /* Variable: K_att_dot
                                        * Referenced by: '<S1>/K_att_dot'
                                        */
  real32_T Kv;                         /* Variable: Kv
                                        * Referenced by: '<S6>/Kv'
                                        */
  real32_T Kx;                         /* Variable: Kx
                                        * Referenced by: '<S6>/Kx'
                                        */
  real32_T Kxint;                      /* Variable: Kxint
                                        * Referenced by: '<S6>/Kxint'
                                        */
  real32_T frame_inertia[9];           /* Variable: frame_inertia
                                        * Referenced by: '<S1>/Constant'
                                        */
  real32_T mass;                       /* Variable: mass
                                        * Referenced by: '<S6>/Gain1'
                                        */
  real32_T Difference1_ICPrevInput;    /* Mask Parameter: Difference1_ICPrevInput
                                        * Referenced by: '<S2>/UD'
                                        */
  real32_T Gain_Gain;                  /* Computed Parameter: Gain_Gain
                                        * Referenced by: '<S11>/Gain'
                                        */
  real32_T Gain_Gain_a;                /* Computed Parameter: Gain_Gain_a
                                        * Referenced by: '<S14>/Gain'
                                        */
  real32_T Gain_Gain_k;                /* Computed Parameter: Gain_Gain_k
                                        * Referenced by: '<S9>/Gain'
                                        */
  real32_T Gain_Gain_g;                /* Computed Parameter: Gain_Gain_g
                                        * Referenced by: '<S15>/Gain'
                                        */
  real32_T Gain_Gain_p;                /* Computed Parameter: Gain_Gain_p
                                        * Referenced by: '<S10>/Gain'
                                        */
  real32_T Gain_Gain_p4;               /* Computed Parameter: Gain_Gain_p4
                                        * Referenced by: '<S13>/Gain'
                                        */
  real32_T DiscreteTimeIntegrator_gainval;/* Computed Parameter: DiscreteTimeIntegrator_gainval
                                           * Referenced by: '<S1>/Discrete-Time Integrator'
                                           */
  real32_T DiscreteTimeIntegrator_IC;  /* Computed Parameter: DiscreteTimeIntegrator_IC
                                        * Referenced by: '<S1>/Discrete-Time Integrator'
                                        */
  real32_T DiscreteTimeIntegrator_UpperSat;/* Computed Parameter: DiscreteTimeIntegrator_UpperSat
                                            * Referenced by: '<S1>/Discrete-Time Integrator'
                                            */
  real32_T DiscreteTimeIntegrator_LowerSat;/* Computed Parameter: DiscreteTimeIntegrator_LowerSat
                                            * Referenced by: '<S1>/Discrete-Time Integrator'
                                            */
  real32_T K_att_int_Gain;             /* Computed Parameter: K_att_int_Gain
                                        * Referenced by: '<S1>/K_att_int'
                                        */
  real32_T Constant1_Value[3];         /* Computed Parameter: Constant1_Value
                                        * Referenced by: '<Root>/Constant1'
                                        */
  real32_T DiscreteFIRFilter_InitialStates;/* Computed Parameter: DiscreteFIRFilter_InitialStates
                                            * Referenced by: '<Root>/Discrete FIR Filter'
                                            */
  real32_T DiscreteFIRFilter_Coefficients[5];/* Computed Parameter: DiscreteFIRFilter_Coefficients
                                              * Referenced by: '<Root>/Discrete FIR Filter'
                                              */
  real32_T DiscreteTimeIntegrator_gainva_o;/* Computed Parameter: DiscreteTimeIntegrator_gainva_o
                                            * Referenced by: '<S6>/Discrete-Time Integrator'
                                            */
  real32_T DiscreteTimeIntegrator_IC_k;/* Computed Parameter: DiscreteTimeIntegrator_IC_k
                                        * Referenced by: '<S6>/Discrete-Time Integrator'
                                        */
  real32_T DiscreteTimeIntegrator_UpperS_j;/* Computed Parameter: DiscreteTimeIntegrator_UpperS_j
                                            * Referenced by: '<S6>/Discrete-Time Integrator'
                                            */
  real32_T DiscreteTimeIntegrator_LowerS_h;/* Computed Parameter: DiscreteTimeIntegrator_LowerS_h
                                            * Referenced by: '<S6>/Discrete-Time Integrator'
                                            */
  real32_T Constant6_Value[3];         /* Computed Parameter: Constant6_Value
                                        * Referenced by: '<Root>/Constant6'
                                        */
  real32_T Constant_Value[3];          /* Computed Parameter: Constant_Value
                                        * Referenced by: '<S6>/Constant'
                                        */
  real32_T Saturation_UpperSat;        /* Computed Parameter: Saturation_UpperSat
                                        * Referenced by: '<Root>/Saturation'
                                        */
  real32_T Saturation_LowerSat;        /* Computed Parameter: Saturation_LowerSat
                                        * Referenced by: '<Root>/Saturation'
                                        */
  real32_T Gain_Gain_ps;               /* Computed Parameter: Gain_Gain_ps
                                        * Referenced by: '<Root>/Gain'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_rotor_combined_contro_T {
  const char_T * volatile errorStatus;
};

/* Block parameters (default storage) */
extern P_rotor_combined_controller_T rotor_combined_controller_P;

/* Block states (default storage) */
extern DW_rotor_combined_controller_T rotor_combined_controller_DW;

/* External inputs (root inport signals with default storage) */
extern ExtU_rotor_combined_controlle_T rotor_combined_controller_U;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_rotor_combined_controlle_T rotor_combined_controller_Y;

/* Model entry point functions */
extern void rotor_combined_controller_initialize(void);
extern void rotor_combined_controller_step(void);
extern void rotor_combined_controller_terminate(void);

/* Real-time Model object */
extern RT_MODEL_rotor_combined_contr_T *const rotor_combined_controller_M;

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
 * '<Root>' : 'rotor_combined_controller'
 * '<S1>'   : 'rotor_combined_controller/Att_controller'
 * '<S2>'   : 'rotor_combined_controller/Difference1'
 * '<S3>'   : 'rotor_combined_controller/MATLAB Function'
 * '<S4>'   : 'rotor_combined_controller/MATLAB Function1'
 * '<S5>'   : 'rotor_combined_controller/MATLAB Function2'
 * '<S6>'   : 'rotor_combined_controller/Pos_controller'
 * '<S7>'   : 'rotor_combined_controller/Quaternions to  Direction Cosine Matrix'
 * '<S8>'   : 'rotor_combined_controller/Quaternions to  Direction Cosine Matrix/A11'
 * '<S9>'   : 'rotor_combined_controller/Quaternions to  Direction Cosine Matrix/A12'
 * '<S10>'  : 'rotor_combined_controller/Quaternions to  Direction Cosine Matrix/A13'
 * '<S11>'  : 'rotor_combined_controller/Quaternions to  Direction Cosine Matrix/A21'
 * '<S12>'  : 'rotor_combined_controller/Quaternions to  Direction Cosine Matrix/A22'
 * '<S13>'  : 'rotor_combined_controller/Quaternions to  Direction Cosine Matrix/A23'
 * '<S14>'  : 'rotor_combined_controller/Quaternions to  Direction Cosine Matrix/A31'
 * '<S15>'  : 'rotor_combined_controller/Quaternions to  Direction Cosine Matrix/A32'
 * '<S16>'  : 'rotor_combined_controller/Quaternions to  Direction Cosine Matrix/A33'
 * '<S17>'  : 'rotor_combined_controller/Quaternions to  Direction Cosine Matrix/Create 3x3 Matrix'
 * '<S18>'  : 'rotor_combined_controller/Quaternions to  Direction Cosine Matrix/Quaternion Normalize'
 * '<S19>'  : 'rotor_combined_controller/Quaternions to  Direction Cosine Matrix/Quaternion Normalize/Quaternion Modulus'
 * '<S20>'  : 'rotor_combined_controller/Quaternions to  Direction Cosine Matrix/Quaternion Normalize/Quaternion Modulus/Quaternion Norm'
 */
#endif                                 /* RTW_HEADER_rotor_combined_controller_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

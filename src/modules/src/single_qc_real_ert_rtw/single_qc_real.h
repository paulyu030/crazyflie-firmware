/*
 * File: single_qc_real.h
 *
 * Code generated for Simulink model 'single_qc_real'.
 *
 * Model version                  : 1.17
 * Simulink Coder version         : 9.3 (R2020a) 18-Nov-2019
 * C/C++ source code generated on : Tue Apr 14 15:15:18 2020
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objective: Execution efficiency
 * Validation result: Not run
 */

#ifndef RTW_HEADER_single_qc_real_h_
#define RTW_HEADER_single_qc_real_h_
#include <math.h>
#include <string.h>
#ifndef single_qc_real_COMMON_INCLUDES_
# define single_qc_real_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* single_qc_real_COMMON_INCLUDES_ */

#include "single_qc_real_types.h"

/* Macros for accessing real-time model data structure */

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T Integrator_DSTATE;            /* '<S39>/Integrator' */
  real_T UD_DSTATE;                    /* '<S32>/UD' */
  real_T Integrator_DSTATE_e;          /* '<S89>/Integrator' */
  real_T UD_DSTATE_e;                  /* '<S82>/UD' */
} DW_single_qc_real_T;

/* External inputs (root inport signals with default storage) */
typedef struct {
  real_T qw_op;                        /* '<Root>/qw_op' */
  real_T qx_op;                        /* '<Root>/qx_op' */
  real_T qy_op;                        /* '<Root>/qy_op' */
  real_T qz_op;                        /* '<Root>/qz_op' */
  real_T index;                        /* '<Root>/index' */
  real_T thrust;                       /* '<Root>/thrust' */
  real_T alpha_desired;                /* '<Root>/alpha_desired' */
  real_T beta_desired;                 /* '<Root>/beta_desired' */
  real_T qw_IMU;                       /* '<Root>/qw_IMU' */
  real_T qx_IMU;                       /* '<Root>/qx_IMU' */
  real_T qy_IMU;                       /* '<Root>/qy_IMU' */
  real_T qz_IMU;                       /* '<Root>/qz_IMU' */
} ExtU_single_qc_real_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  uint16_T m1;                         /* '<Root>/m1' */
  uint16_T m2;                         /* '<Root>/m2' */
  uint16_T m3;                         /* '<Root>/m3' */
  uint16_T m4;                         /* '<Root>/m4' */
  real_T error_alpha;                  /* '<Root>/error_alpha' */
  real_T error_beta;                   /* '<Root>/error_beta' */
  real_T u_alpha;                      /* '<Root>/u_alpha' */
  real_T u_beta;                       /* '<Root>/u_beta' */
} ExtY_single_qc_real_T;

/* Parameters (default storage) */
struct P_single_qc_real_T_ {
  real_T dgaina;                       /* Variable: dgaina
                                        * Referenced by: '<S31>/Derivative Gain'
                                        */
  real_T dgainb;                       /* Variable: dgainb
                                        * Referenced by: '<S81>/Derivative Gain'
                                        */
  real_T igaina;                       /* Variable: igaina
                                        * Referenced by: '<S36>/Integral Gain'
                                        */
  real_T igainb;                       /* Variable: igainb
                                        * Referenced by: '<S86>/Integral Gain'
                                        */
  real_T pgaina;                       /* Variable: pgaina
                                        * Referenced by: '<S44>/Proportional Gain'
                                        */
  real_T pgainb;                       /* Variable: pgainb
                                        * Referenced by: '<S94>/Proportional Gain'
                                        */
  real_T torque_modifier;              /* Variable: torque_modifier
                                        * Referenced by: '<Root>/Constant'
                                        */
  real_T DiscretePIDController_Different;
                              /* Mask Parameter: DiscretePIDController_Different
                               * Referenced by: '<S32>/UD'
                               */
  real_T DiscretePIDController1_Differen;
                              /* Mask Parameter: DiscretePIDController1_Differen
                               * Referenced by: '<S82>/UD'
                               */
  real_T DiscretePIDController_InitialCo;
                              /* Mask Parameter: DiscretePIDController_InitialCo
                               * Referenced by: '<S39>/Integrator'
                               */
  real_T DiscretePIDController1_InitialC;
                              /* Mask Parameter: DiscretePIDController1_InitialC
                               * Referenced by: '<S89>/Integrator'
                               */
  real_T Gain_Gain;                    /* Expression: 0.5886/65535
                                        * Referenced by: '<Root>/Gain'
                                        */
  real_T Saturation_UpperSat;          /* Expression: 0.5355
                                        * Referenced by: '<Root>/Saturation'
                                        */
  real_T Saturation_LowerSat;          /* Expression: 0
                                        * Referenced by: '<Root>/Saturation'
                                        */
  real_T Integrator_gainval;           /* Computed Parameter: Integrator_gainval
                                        * Referenced by: '<S39>/Integrator'
                                        */
  real_T Tsamp_WtEt;                   /* Computed Parameter: Tsamp_WtEt
                                        * Referenced by: '<S34>/Tsamp'
                                        */
  real_T Saturation_UpperSat_b;        /* Expression: 5.6e-4
                                        * Referenced by: '<S3>/Saturation'
                                        */
  real_T Saturation_LowerSat_p;        /* Expression: -5.6e-4
                                        * Referenced by: '<S3>/Saturation'
                                        */
  real_T Integrator_gainval_i;       /* Computed Parameter: Integrator_gainval_i
                                      * Referenced by: '<S89>/Integrator'
                                      */
  real_T Tsamp_WtEt_c;                 /* Computed Parameter: Tsamp_WtEt_c
                                        * Referenced by: '<S84>/Tsamp'
                                        */
  real_T Saturation1_UpperSat;         /* Expression: 5.6e-4
                                        * Referenced by: '<S3>/Saturation1'
                                        */
  real_T Saturation1_LowerSat;         /* Expression: -5.6e-4
                                        * Referenced by: '<S3>/Saturation1'
                                        */
  real_T Saturation2_UpperSat;         /* Expression: 5.6e-4
                                        * Referenced by: '<S3>/Saturation2'
                                        */
  real_T Saturation2_LowerSat;         /* Expression: -5.6e-4
                                        * Referenced by: '<S3>/Saturation2'
                                        */
  real_T Saturation1_UpperSat_m;       /* Expression: 65535
                                        * Referenced by: '<Root>/Saturation1'
                                        */
  real_T Saturation1_LowerSat_e;       /* Expression: 0
                                        * Referenced by: '<Root>/Saturation1'
                                        */
};

/* Block parameters (default storage) */
extern P_single_qc_real_T single_qc_real_P;

/* Block states (default storage) */
extern DW_single_qc_real_T single_qc_real_DW;

/* External inputs (root inport signals with default storage) */
extern ExtU_single_qc_real_T single_qc_real_U;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_single_qc_real_T single_qc_real_Y;

/* Model entry point functions */
extern void single_qc_real_initialize(void);
extern void single_qc_real_step(void);
extern void single_qc_real_terminate(void);

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S32>/DTDup' : Unused code path elimination
 * Block '<S82>/DTDup' : Unused code path elimination
 * Block '<Root>/Data Type Conversion1' : Eliminate redundant data type conversion
 */

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
 * '<Root>' : 'single_qc_real'
 * '<S1>'   : 'single_qc_real/MATLAB Function'
 * '<S2>'   : 'single_qc_real/MATLAB Function1'
 * '<S3>'   : 'single_qc_real/transformed_PID'
 * '<S4>'   : 'single_qc_real/transformed_PID/Discrete PID Controller'
 * '<S5>'   : 'single_qc_real/transformed_PID/Discrete PID Controller1'
 * '<S6>'   : 'single_qc_real/transformed_PID/Discrete PID Controller/Anti-windup'
 * '<S7>'   : 'single_qc_real/transformed_PID/Discrete PID Controller/D Gain'
 * '<S8>'   : 'single_qc_real/transformed_PID/Discrete PID Controller/Filter'
 * '<S9>'   : 'single_qc_real/transformed_PID/Discrete PID Controller/Filter ICs'
 * '<S10>'  : 'single_qc_real/transformed_PID/Discrete PID Controller/I Gain'
 * '<S11>'  : 'single_qc_real/transformed_PID/Discrete PID Controller/Ideal P Gain'
 * '<S12>'  : 'single_qc_real/transformed_PID/Discrete PID Controller/Ideal P Gain Fdbk'
 * '<S13>'  : 'single_qc_real/transformed_PID/Discrete PID Controller/Integrator'
 * '<S14>'  : 'single_qc_real/transformed_PID/Discrete PID Controller/Integrator ICs'
 * '<S15>'  : 'single_qc_real/transformed_PID/Discrete PID Controller/N Copy'
 * '<S16>'  : 'single_qc_real/transformed_PID/Discrete PID Controller/N Gain'
 * '<S17>'  : 'single_qc_real/transformed_PID/Discrete PID Controller/P Copy'
 * '<S18>'  : 'single_qc_real/transformed_PID/Discrete PID Controller/Parallel P Gain'
 * '<S19>'  : 'single_qc_real/transformed_PID/Discrete PID Controller/Reset Signal'
 * '<S20>'  : 'single_qc_real/transformed_PID/Discrete PID Controller/Saturation'
 * '<S21>'  : 'single_qc_real/transformed_PID/Discrete PID Controller/Saturation Fdbk'
 * '<S22>'  : 'single_qc_real/transformed_PID/Discrete PID Controller/Sum'
 * '<S23>'  : 'single_qc_real/transformed_PID/Discrete PID Controller/Sum Fdbk'
 * '<S24>'  : 'single_qc_real/transformed_PID/Discrete PID Controller/Tracking Mode'
 * '<S25>'  : 'single_qc_real/transformed_PID/Discrete PID Controller/Tracking Mode Sum'
 * '<S26>'  : 'single_qc_real/transformed_PID/Discrete PID Controller/Tsamp - Integral'
 * '<S27>'  : 'single_qc_real/transformed_PID/Discrete PID Controller/Tsamp - Ngain'
 * '<S28>'  : 'single_qc_real/transformed_PID/Discrete PID Controller/postSat Signal'
 * '<S29>'  : 'single_qc_real/transformed_PID/Discrete PID Controller/preSat Signal'
 * '<S30>'  : 'single_qc_real/transformed_PID/Discrete PID Controller/Anti-windup/Passthrough'
 * '<S31>'  : 'single_qc_real/transformed_PID/Discrete PID Controller/D Gain/Internal Parameters'
 * '<S32>'  : 'single_qc_real/transformed_PID/Discrete PID Controller/Filter/Differentiator'
 * '<S33>'  : 'single_qc_real/transformed_PID/Discrete PID Controller/Filter/Differentiator/Tsamp'
 * '<S34>'  : 'single_qc_real/transformed_PID/Discrete PID Controller/Filter/Differentiator/Tsamp/Internal Ts'
 * '<S35>'  : 'single_qc_real/transformed_PID/Discrete PID Controller/Filter ICs/Internal IC - Differentiator'
 * '<S36>'  : 'single_qc_real/transformed_PID/Discrete PID Controller/I Gain/Internal Parameters'
 * '<S37>'  : 'single_qc_real/transformed_PID/Discrete PID Controller/Ideal P Gain/Passthrough'
 * '<S38>'  : 'single_qc_real/transformed_PID/Discrete PID Controller/Ideal P Gain Fdbk/Disabled'
 * '<S39>'  : 'single_qc_real/transformed_PID/Discrete PID Controller/Integrator/Discrete'
 * '<S40>'  : 'single_qc_real/transformed_PID/Discrete PID Controller/Integrator ICs/Internal IC'
 * '<S41>'  : 'single_qc_real/transformed_PID/Discrete PID Controller/N Copy/Disabled wSignal Specification'
 * '<S42>'  : 'single_qc_real/transformed_PID/Discrete PID Controller/N Gain/Passthrough'
 * '<S43>'  : 'single_qc_real/transformed_PID/Discrete PID Controller/P Copy/Disabled'
 * '<S44>'  : 'single_qc_real/transformed_PID/Discrete PID Controller/Parallel P Gain/Internal Parameters'
 * '<S45>'  : 'single_qc_real/transformed_PID/Discrete PID Controller/Reset Signal/Disabled'
 * '<S46>'  : 'single_qc_real/transformed_PID/Discrete PID Controller/Saturation/Passthrough'
 * '<S47>'  : 'single_qc_real/transformed_PID/Discrete PID Controller/Saturation Fdbk/Disabled'
 * '<S48>'  : 'single_qc_real/transformed_PID/Discrete PID Controller/Sum/Sum_PID'
 * '<S49>'  : 'single_qc_real/transformed_PID/Discrete PID Controller/Sum Fdbk/Disabled'
 * '<S50>'  : 'single_qc_real/transformed_PID/Discrete PID Controller/Tracking Mode/Disabled'
 * '<S51>'  : 'single_qc_real/transformed_PID/Discrete PID Controller/Tracking Mode Sum/Passthrough'
 * '<S52>'  : 'single_qc_real/transformed_PID/Discrete PID Controller/Tsamp - Integral/Passthrough'
 * '<S53>'  : 'single_qc_real/transformed_PID/Discrete PID Controller/Tsamp - Ngain/Passthrough'
 * '<S54>'  : 'single_qc_real/transformed_PID/Discrete PID Controller/postSat Signal/Forward_Path'
 * '<S55>'  : 'single_qc_real/transformed_PID/Discrete PID Controller/preSat Signal/Forward_Path'
 * '<S56>'  : 'single_qc_real/transformed_PID/Discrete PID Controller1/Anti-windup'
 * '<S57>'  : 'single_qc_real/transformed_PID/Discrete PID Controller1/D Gain'
 * '<S58>'  : 'single_qc_real/transformed_PID/Discrete PID Controller1/Filter'
 * '<S59>'  : 'single_qc_real/transformed_PID/Discrete PID Controller1/Filter ICs'
 * '<S60>'  : 'single_qc_real/transformed_PID/Discrete PID Controller1/I Gain'
 * '<S61>'  : 'single_qc_real/transformed_PID/Discrete PID Controller1/Ideal P Gain'
 * '<S62>'  : 'single_qc_real/transformed_PID/Discrete PID Controller1/Ideal P Gain Fdbk'
 * '<S63>'  : 'single_qc_real/transformed_PID/Discrete PID Controller1/Integrator'
 * '<S64>'  : 'single_qc_real/transformed_PID/Discrete PID Controller1/Integrator ICs'
 * '<S65>'  : 'single_qc_real/transformed_PID/Discrete PID Controller1/N Copy'
 * '<S66>'  : 'single_qc_real/transformed_PID/Discrete PID Controller1/N Gain'
 * '<S67>'  : 'single_qc_real/transformed_PID/Discrete PID Controller1/P Copy'
 * '<S68>'  : 'single_qc_real/transformed_PID/Discrete PID Controller1/Parallel P Gain'
 * '<S69>'  : 'single_qc_real/transformed_PID/Discrete PID Controller1/Reset Signal'
 * '<S70>'  : 'single_qc_real/transformed_PID/Discrete PID Controller1/Saturation'
 * '<S71>'  : 'single_qc_real/transformed_PID/Discrete PID Controller1/Saturation Fdbk'
 * '<S72>'  : 'single_qc_real/transformed_PID/Discrete PID Controller1/Sum'
 * '<S73>'  : 'single_qc_real/transformed_PID/Discrete PID Controller1/Sum Fdbk'
 * '<S74>'  : 'single_qc_real/transformed_PID/Discrete PID Controller1/Tracking Mode'
 * '<S75>'  : 'single_qc_real/transformed_PID/Discrete PID Controller1/Tracking Mode Sum'
 * '<S76>'  : 'single_qc_real/transformed_PID/Discrete PID Controller1/Tsamp - Integral'
 * '<S77>'  : 'single_qc_real/transformed_PID/Discrete PID Controller1/Tsamp - Ngain'
 * '<S78>'  : 'single_qc_real/transformed_PID/Discrete PID Controller1/postSat Signal'
 * '<S79>'  : 'single_qc_real/transformed_PID/Discrete PID Controller1/preSat Signal'
 * '<S80>'  : 'single_qc_real/transformed_PID/Discrete PID Controller1/Anti-windup/Passthrough'
 * '<S81>'  : 'single_qc_real/transformed_PID/Discrete PID Controller1/D Gain/Internal Parameters'
 * '<S82>'  : 'single_qc_real/transformed_PID/Discrete PID Controller1/Filter/Differentiator'
 * '<S83>'  : 'single_qc_real/transformed_PID/Discrete PID Controller1/Filter/Differentiator/Tsamp'
 * '<S84>'  : 'single_qc_real/transformed_PID/Discrete PID Controller1/Filter/Differentiator/Tsamp/Internal Ts'
 * '<S85>'  : 'single_qc_real/transformed_PID/Discrete PID Controller1/Filter ICs/Internal IC - Differentiator'
 * '<S86>'  : 'single_qc_real/transformed_PID/Discrete PID Controller1/I Gain/Internal Parameters'
 * '<S87>'  : 'single_qc_real/transformed_PID/Discrete PID Controller1/Ideal P Gain/Passthrough'
 * '<S88>'  : 'single_qc_real/transformed_PID/Discrete PID Controller1/Ideal P Gain Fdbk/Disabled'
 * '<S89>'  : 'single_qc_real/transformed_PID/Discrete PID Controller1/Integrator/Discrete'
 * '<S90>'  : 'single_qc_real/transformed_PID/Discrete PID Controller1/Integrator ICs/Internal IC'
 * '<S91>'  : 'single_qc_real/transformed_PID/Discrete PID Controller1/N Copy/Disabled wSignal Specification'
 * '<S92>'  : 'single_qc_real/transformed_PID/Discrete PID Controller1/N Gain/Passthrough'
 * '<S93>'  : 'single_qc_real/transformed_PID/Discrete PID Controller1/P Copy/Disabled'
 * '<S94>'  : 'single_qc_real/transformed_PID/Discrete PID Controller1/Parallel P Gain/Internal Parameters'
 * '<S95>'  : 'single_qc_real/transformed_PID/Discrete PID Controller1/Reset Signal/Disabled'
 * '<S96>'  : 'single_qc_real/transformed_PID/Discrete PID Controller1/Saturation/Passthrough'
 * '<S97>'  : 'single_qc_real/transformed_PID/Discrete PID Controller1/Saturation Fdbk/Disabled'
 * '<S98>'  : 'single_qc_real/transformed_PID/Discrete PID Controller1/Sum/Sum_PID'
 * '<S99>'  : 'single_qc_real/transformed_PID/Discrete PID Controller1/Sum Fdbk/Disabled'
 * '<S100>' : 'single_qc_real/transformed_PID/Discrete PID Controller1/Tracking Mode/Disabled'
 * '<S101>' : 'single_qc_real/transformed_PID/Discrete PID Controller1/Tracking Mode Sum/Passthrough'
 * '<S102>' : 'single_qc_real/transformed_PID/Discrete PID Controller1/Tsamp - Integral/Passthrough'
 * '<S103>' : 'single_qc_real/transformed_PID/Discrete PID Controller1/Tsamp - Ngain/Passthrough'
 * '<S104>' : 'single_qc_real/transformed_PID/Discrete PID Controller1/postSat Signal/Forward_Path'
 * '<S105>' : 'single_qc_real/transformed_PID/Discrete PID Controller1/preSat Signal/Forward_Path'
 */
#endif                                 /* RTW_HEADER_single_qc_real_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

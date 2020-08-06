/*
 * File: single_qc_real.h
 *
 * Code generated for Simulink model 'single_qc_real'.
 *
 * Model version                  : 1.48
 * Simulink Coder version         : 9.3 (R2020a) 18-Nov-2019
 * C/C++ source code generated on : Thu Aug  6 12:07:03 2020
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
#include "rt_defines.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"

/* Macros for accessing real-time model data structure */

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real32_T UD_DSTATE;                  /* '<S6>/UD' */
  real32_T UD_DSTATE_l;                /* '<S8>/UD' */
  real32_T Memory_PreviousInput;       /* '<S4>/Memory' */
  real32_T Memory_PreviousInput_l;     /* '<S5>/Memory' */
} DW_single_qc_real_T;

/* External inputs (root inport signals with default storage) */
typedef struct {
  real32_T qw_op;                      /* '<Root>/qw_op' */
  real32_T qx_op;                      /* '<Root>/qx_op' */
  real32_T qy_op;                      /* '<Root>/qy_op' */
  real32_T qz_op;                      /* '<Root>/qz_op' */
  real32_T index;                      /* '<Root>/index' */
  real32_T thrust;                     /* '<Root>/thrust' */
  real32_T alpha_desired;              /* '<Root>/alpha_desired' */
  real32_T beta_desired;               /* '<Root>/beta_desired' */
  real32_T qw_IMU;                     /* '<Root>/qw_IMU' */
  real32_T qx_IMU;                     /* '<Root>/qx_IMU' */
  real32_T qy_IMU;                     /* '<Root>/qy_IMU' */
  real32_T qz_IMU;                     /* '<Root>/qz_IMU' */
} ExtU_single_qc_real_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  uint16_T m1;                         /* '<Root>/m1' */
  uint16_T m2;                         /* '<Root>/m2' */
  uint16_T m3;                         /* '<Root>/m3' */
  uint16_T m4;                         /* '<Root>/m4' */
  real32_T error_alpha;                /* '<Root>/error_alpha' */
  real32_T error_beta;                 /* '<Root>/error_beta' */
  real32_T u_alpha;                    /* '<Root>/u_alpha' */
  real32_T u_beta;                     /* '<Root>/u_beta' */
  real32_T t_betain;                   /* '<Root>/t_betain' */
  real32_T t_betae;                    /* '<Root>/t_betae' */
  real32_T t_alphain;                  /* '<Root>/t_alphain' */
  real32_T t_alphae;                   /* '<Root>/t_alphae' */
  real32_T t_m1;                       /* '<Root>/t_m1' */
  real32_T t_m2;                       /* '<Root>/t_m2' */
  real32_T t_m3;                       /* '<Root>/t_m3' */
  real32_T t_m4;                       /* '<Root>/t_m4' */
} ExtY_single_qc_real_T;

/* Parameters (default storage) */
struct P_single_qc_real_T_ {
  real32_T dgaina;                     /* Variable: dgaina
                                        * Referenced by: '<S4>/dgain'
                                        */
  real32_T dgainb;                     /* Variable: dgainb
                                        * Referenced by: '<S5>/dgain'
                                        */
  real32_T igaina;                     /* Variable: igaina
                                        * Referenced by: '<S4>/igain'
                                        */
  real32_T igainb;                     /* Variable: igainb
                                        * Referenced by: '<S5>/igain'
                                        */
  real32_T pgaina;                     /* Variable: pgaina
                                        * Referenced by: '<S4>/pgain'
                                        */
  real32_T pgainb;                     /* Variable: pgainb
                                        * Referenced by: '<S5>/pgain'
                                        */
  real32_T sat_tx;                     /* Variable: sat_tx
                                        * Referenced by: '<S3>/Saturation'
                                        */
  real32_T sat_ty;                     /* Variable: sat_ty
                                        * Referenced by: '<S3>/Saturation1'
                                        */
  real32_T sat_tz;                     /* Variable: sat_tz
                                        * Referenced by: '<S3>/Saturation2'
                                        */
  real32_T torque_modifier;            /* Variable: torque_modifier
                                        * Referenced by: '<Root>/Constant'
                                        */
  real32_T DiscreteDerivative2_ICPrevScale;
                              /* Mask Parameter: DiscreteDerivative2_ICPrevScale
                               * Referenced by: '<S6>/UD'
                               */
  real32_T DiscreteDerivative2_ICPrevSca_h;
                              /* Mask Parameter: DiscreteDerivative2_ICPrevSca_h
                               * Referenced by: '<S8>/UD'
                               */
  real32_T Gain_Gain;                  /* Computed Parameter: Gain_Gain
                                        * Referenced by: '<Root>/Gain'
                                        */
  real32_T Saturation_UpperSat;       /* Computed Parameter: Saturation_UpperSat
                                       * Referenced by: '<Root>/Saturation'
                                       */
  real32_T Saturation_LowerSat;       /* Computed Parameter: Saturation_LowerSat
                                       * Referenced by: '<Root>/Saturation'
                                       */
  real32_T Memory_InitialCondition;
                                  /* Computed Parameter: Memory_InitialCondition
                                   * Referenced by: '<S4>/Memory'
                                   */
  real32_T TSamp_WtEt;                 /* Computed Parameter: TSamp_WtEt
                                        * Referenced by: '<S6>/TSamp'
                                        */
  real32_T Memory_InitialCondition_o;
                                /* Computed Parameter: Memory_InitialCondition_o
                                 * Referenced by: '<S5>/Memory'
                                 */
  real32_T TSamp_WtEt_o;               /* Computed Parameter: TSamp_WtEt_o
                                        * Referenced by: '<S8>/TSamp'
                                        */
  real32_T Saturation1_UpperSat;     /* Computed Parameter: Saturation1_UpperSat
                                      * Referenced by: '<Root>/Saturation1'
                                      */
  real32_T Saturation1_LowerSat;     /* Computed Parameter: Saturation1_LowerSat
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
 * Block '<S6>/Data Type Duplicate' : Unused code path elimination
 * Block '<S8>/Data Type Duplicate' : Unused code path elimination
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
 * '<S4>'   : 'single_qc_real/transformed_PID/PIDa'
 * '<S5>'   : 'single_qc_real/transformed_PID/PIDb'
 * '<S6>'   : 'single_qc_real/transformed_PID/PIDa/Discrete Derivative2'
 * '<S7>'   : 'single_qc_real/transformed_PID/PIDa/MATLAB Function'
 * '<S8>'   : 'single_qc_real/transformed_PID/PIDb/Discrete Derivative2'
 * '<S9>'   : 'single_qc_real/transformed_PID/PIDb/MATLAB Function'
 */
#endif                                 /* RTW_HEADER_single_qc_real_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

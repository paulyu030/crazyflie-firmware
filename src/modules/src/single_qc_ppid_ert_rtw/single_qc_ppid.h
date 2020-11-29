/*
 * File: single_qc_ppid.h
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

#ifndef RTW_HEADER_single_qc_ppid_h_
#define RTW_HEADER_single_qc_ppid_h_
#include <math.h>
#include <string.h>
#ifndef single_qc_ppid_COMMON_INCLUDES_
# define single_qc_ppid_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* single_qc_ppid_COMMON_INCLUDES_ */

#include "single_qc_ppid_types.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"

/* Macros for accessing real-time model data structure */

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
  real32_T omega_x;                    /* '<Root>/omega_x' */
  real32_T beta_speed;                 /* '<Root>/beta_speed' */
  real32_T omega_z;                    /* '<Root>/omega_z' */
} ExtU_single_qc_ppid_T;

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
  real32_T t_betain;                   /* '<Root>/t_betain' */
  real_T t_betae;                      /* '<Root>/t_betae' */
  real32_T t_alphain;                  /* '<Root>/t_alphain' */
  real_T t_alphae;                     /* '<Root>/t_alphae' */
  real32_T t_m1;                       /* '<Root>/t_m1' */
  real32_T t_m2;                       /* '<Root>/t_m2' */
  real32_T t_m3;                       /* '<Root>/t_m3' */
  real32_T t_m4;                       /* '<Root>/t_m4' */
  real_T error_alphas;                 /* '<Root>/error_alphas' */
  real_T error_betas;                  /* '<Root>/error_betas' */
} ExtY_single_qc_ppid_T;

/* Parameters (default storage) */
struct P_single_qc_ppid_T_ {
  real_T Constant_Value;               /* Expression: 0
                                        * Referenced by: '<Root>/Constant'
                                        */
  real32_T Saturation_UpperSat;       /* Computed Parameter: Saturation_UpperSat
                                       * Referenced by: '<Root>/Saturation'
                                       */
  real32_T Saturation_LowerSat;       /* Computed Parameter: Saturation_LowerSat
                                       * Referenced by: '<Root>/Saturation'
                                       */
  real32_T Saturation1_UpperSat;     /* Computed Parameter: Saturation1_UpperSat
                                      * Referenced by: '<Root>/Saturation1'
                                      */
  real32_T Saturation1_LowerSat;     /* Computed Parameter: Saturation1_LowerSat
                                      * Referenced by: '<Root>/Saturation1'
                                      */
};

/* Block parameters (default storage) */
extern P_single_qc_ppid_T single_qc_ppid_P;

/* External inputs (root inport signals with default storage) */
extern ExtU_single_qc_ppid_T single_qc_ppid_U;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_single_qc_ppid_T single_qc_ppid_Y;

/* Model entry point functions */
extern void single_qc_ppid_initialize(void);
extern void single_qc_ppid_step(void);
extern void single_qc_ppid_terminate(void);

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
 * '<Root>' : 'single_qc_ppid'
 * '<S1>'   : 'single_qc_ppid/MATLAB Function'
 */
#endif                                 /* RTW_HEADER_single_qc_ppid_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

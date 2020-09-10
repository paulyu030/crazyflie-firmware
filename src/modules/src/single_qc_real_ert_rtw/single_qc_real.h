/*
 * File: single_qc_real.h
 *
 * Code generated for Simulink model 'single_qc_real'.
 *
 * Model version                  : 1.65
 * Simulink Coder version         : 9.3 (R2020a) 18-Nov-2019
 * C/C++ source code generated on : Thu Sep 10 10:12:16 2020
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
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
  real32_T t_betain;                   /* '<Root>/t_betain' */
  real32_T t_betae;                    /* '<Root>/t_betae' */
  real32_T t_alphae;                   /* '<Root>/t_alphae' */
  real32_T t_m1;                       /* '<Root>/t_m1' */
  real32_T t_m2;                       /* '<Root>/t_m2' */
  real32_T t_m3;                       /* '<Root>/t_m3' */
  real32_T t_m4;                       /* '<Root>/t_m4' */
} ExtY_single_qc_real_T;

/* Parameters (default storage) */
struct P_single_qc_real_T_ {
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
extern P_single_qc_real_T single_qc_real_P;

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
 */
#endif                                 /* RTW_HEADER_single_qc_real_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

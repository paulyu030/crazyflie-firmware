/*
 * File: single_qc_ppid.h
 *
 * Code generated for Simulink model 'single_qc_ppid'.
 *
 * Model version                  : 1.71
 * Simulink Coder version         : 9.3 (R2020a) 18-Nov-2019
 * C/C++ source code generated on : Sun Oct 18 22:34:34 2020
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
#include "rt_defines.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"

/* Macros for accessing real-time model data structure */

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real32_T DiscreteTimeIntegrator2_DSTATE;/* '<S4>/Discrete-Time Integrator2' */
  real32_T UD_DSTATE;                  /* '<S8>/UD' */
  real32_T DiscreteTimeIntegrator1_DSTATE;/* '<S4>/Discrete-Time Integrator1' */
  real32_T UD_DSTATE_j;                /* '<S7>/UD' */
  real32_T DiscreteTimeIntegrator2_DSTAT_o;/* '<S5>/Discrete-Time Integrator2' */
  real32_T UD_DSTATE_p;                /* '<S10>/UD' */
  real32_T DiscreteTimeIntegrator1_DSTAT_p;/* '<S5>/Discrete-Time Integrator1' */
  real32_T UD_DSTATE_d;                /* '<S9>/UD' */
  int8_T DiscreteTimeIntegrator2_PrevRes;/* '<S4>/Discrete-Time Integrator2' */
  int8_T DiscreteTimeIntegrator1_PrevRes;/* '<S4>/Discrete-Time Integrator1' */
  int8_T DiscreteTimeIntegrator2_PrevR_e;/* '<S5>/Discrete-Time Integrator2' */
  int8_T DiscreteTimeIntegrator1_PrevR_o;/* '<S5>/Discrete-Time Integrator1' */
} DW_single_qc_ppid_T;

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
  real32_T alpha_speed;                /* '<Root>/alpha_speed' */
  real32_T beta_speed;                 /* '<Root>/beta_speed' */
} ExtU_single_qc_ppid_T;

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
  real32_T error_alphas;               /* '<Root>/error_alphas' */
  real32_T error_betas;                /* '<Root>/error_betas' */
} ExtY_single_qc_ppid_T;

/* Parameters (default storage) */
struct P_single_qc_ppid_T_ {
  real32_T dgaina;                     /* Variable: dgaina
                                        * Referenced by: '<S4>/dgain'
                                        */
  real32_T dgainas;                    /* Variable: dgainas
                                        * Referenced by: '<S4>/dgain1'
                                        */
  real32_T dgainb;                     /* Variable: dgainb
                                        * Referenced by: '<S5>/dgain'
                                        */
  real32_T dgainbs;                    /* Variable: dgainbs
                                        * Referenced by: '<S5>/dgain1'
                                        */
  real32_T igaina;                     /* Variable: igaina
                                        * Referenced by: '<S4>/igain'
                                        */
  real32_T igainas;                    /* Variable: igainas
                                        * Referenced by: '<S4>/igain1'
                                        */
  real32_T igainb;                     /* Variable: igainb
                                        * Referenced by: '<S5>/igain'
                                        */
  real32_T igainbs;                    /* Variable: igainbs
                                        * Referenced by: '<S5>/igain1'
                                        */
  real32_T pgaina;                     /* Variable: pgaina
                                        * Referenced by: '<S4>/pgain'
                                        */
  real32_T pgainas;                    /* Variable: pgainas
                                        * Referenced by: '<S4>/pgain1'
                                        */
  real32_T pgainb;                     /* Variable: pgainb
                                        * Referenced by: '<S5>/pgain'
                                        */
  real32_T pgainbs;                    /* Variable: pgainbs
                                        * Referenced by: '<S5>/pgain1'
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
                               * Referenced by: '<S8>/UD'
                               */
  real32_T DiscreteDerivative1_ICPrevScale;
                              /* Mask Parameter: DiscreteDerivative1_ICPrevScale
                               * Referenced by: '<S7>/UD'
                               */
  real32_T DiscreteDerivative2_ICPrevSca_g;
                              /* Mask Parameter: DiscreteDerivative2_ICPrevSca_g
                               * Referenced by: '<S10>/UD'
                               */
  real32_T DiscreteDerivative1_ICPrevSca_h;
                              /* Mask Parameter: DiscreteDerivative1_ICPrevSca_h
                               * Referenced by: '<S9>/UD'
                               */
  real32_T Constant_Value;             /* Computed Parameter: Constant_Value
                                        * Referenced by: '<S6>/Constant'
                                        */
  real32_T Saturation_UpperSat;       /* Computed Parameter: Saturation_UpperSat
                                       * Referenced by: '<Root>/Saturation'
                                       */
  real32_T Saturation_LowerSat;       /* Computed Parameter: Saturation_LowerSat
                                       * Referenced by: '<Root>/Saturation'
                                       */
  real32_T DiscreteTimeIntegrator2_gainval;
                          /* Computed Parameter: DiscreteTimeIntegrator2_gainval
                           * Referenced by: '<S4>/Discrete-Time Integrator2'
                           */
  real32_T DiscreteTimeIntegrator2_IC;
                               /* Computed Parameter: DiscreteTimeIntegrator2_IC
                                * Referenced by: '<S4>/Discrete-Time Integrator2'
                                */
  real32_T DiscreteTimeIntegrator2_UpperSa;
                          /* Computed Parameter: DiscreteTimeIntegrator2_UpperSa
                           * Referenced by: '<S4>/Discrete-Time Integrator2'
                           */
  real32_T DiscreteTimeIntegrator2_LowerSa;
                          /* Computed Parameter: DiscreteTimeIntegrator2_LowerSa
                           * Referenced by: '<S4>/Discrete-Time Integrator2'
                           */
  real32_T TSamp_WtEt;                 /* Computed Parameter: TSamp_WtEt
                                        * Referenced by: '<S8>/TSamp'
                                        */
  real32_T DiscreteTimeIntegrator1_gainval;
                          /* Computed Parameter: DiscreteTimeIntegrator1_gainval
                           * Referenced by: '<S4>/Discrete-Time Integrator1'
                           */
  real32_T DiscreteTimeIntegrator1_IC;
                               /* Computed Parameter: DiscreteTimeIntegrator1_IC
                                * Referenced by: '<S4>/Discrete-Time Integrator1'
                                */
  real32_T DiscreteTimeIntegrator1_UpperSa;
                          /* Computed Parameter: DiscreteTimeIntegrator1_UpperSa
                           * Referenced by: '<S4>/Discrete-Time Integrator1'
                           */
  real32_T DiscreteTimeIntegrator1_LowerSa;
                          /* Computed Parameter: DiscreteTimeIntegrator1_LowerSa
                           * Referenced by: '<S4>/Discrete-Time Integrator1'
                           */
  real32_T TSamp_WtEt_k;               /* Computed Parameter: TSamp_WtEt_k
                                        * Referenced by: '<S7>/TSamp'
                                        */
  real32_T DiscreteTimeIntegrator2_gainv_f;
                          /* Computed Parameter: DiscreteTimeIntegrator2_gainv_f
                           * Referenced by: '<S5>/Discrete-Time Integrator2'
                           */
  real32_T DiscreteTimeIntegrator2_IC_h;
                             /* Computed Parameter: DiscreteTimeIntegrator2_IC_h
                              * Referenced by: '<S5>/Discrete-Time Integrator2'
                              */
  real32_T DiscreteTimeIntegrator2_Upper_l;
                          /* Computed Parameter: DiscreteTimeIntegrator2_Upper_l
                           * Referenced by: '<S5>/Discrete-Time Integrator2'
                           */
  real32_T DiscreteTimeIntegrator2_Lower_i;
                          /* Computed Parameter: DiscreteTimeIntegrator2_Lower_i
                           * Referenced by: '<S5>/Discrete-Time Integrator2'
                           */
  real32_T TSamp_WtEt_i;               /* Computed Parameter: TSamp_WtEt_i
                                        * Referenced by: '<S10>/TSamp'
                                        */
  real32_T DiscreteTimeIntegrator1_gainv_c;
                          /* Computed Parameter: DiscreteTimeIntegrator1_gainv_c
                           * Referenced by: '<S5>/Discrete-Time Integrator1'
                           */
  real32_T DiscreteTimeIntegrator1_IC_h;
                             /* Computed Parameter: DiscreteTimeIntegrator1_IC_h
                              * Referenced by: '<S5>/Discrete-Time Integrator1'
                              */
  real32_T DiscreteTimeIntegrator1_Upper_e;
                          /* Computed Parameter: DiscreteTimeIntegrator1_Upper_e
                           * Referenced by: '<S5>/Discrete-Time Integrator1'
                           */
  real32_T DiscreteTimeIntegrator1_Lower_f;
                          /* Computed Parameter: DiscreteTimeIntegrator1_Lower_f
                           * Referenced by: '<S5>/Discrete-Time Integrator1'
                           */
  real32_T TSamp_WtEt_b;               /* Computed Parameter: TSamp_WtEt_b
                                        * Referenced by: '<S9>/TSamp'
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

/* Block states (default storage) */
extern DW_single_qc_ppid_T single_qc_ppid_DW;

/* External inputs (root inport signals with default storage) */
extern ExtU_single_qc_ppid_T single_qc_ppid_U;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_single_qc_ppid_T single_qc_ppid_Y;

/* Model entry point functions */
extern void single_qc_ppid_initialize(void);
extern void single_qc_ppid_step(void);
extern void single_qc_ppid_terminate(void);

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S7>/Data Type Duplicate' : Unused code path elimination
 * Block '<S8>/Data Type Duplicate' : Unused code path elimination
 * Block '<S9>/Data Type Duplicate' : Unused code path elimination
 * Block '<S10>/Data Type Duplicate' : Unused code path elimination
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
 * '<Root>' : 'single_qc_ppid'
 * '<S1>'   : 'single_qc_ppid/MATLAB Function'
 * '<S2>'   : 'single_qc_ppid/MATLAB Function1'
 * '<S3>'   : 'single_qc_ppid/transformed_PID'
 * '<S4>'   : 'single_qc_ppid/transformed_PID/PIDa'
 * '<S5>'   : 'single_qc_ppid/transformed_PID/PIDb'
 * '<S6>'   : 'single_qc_ppid/transformed_PID/PIDa/Compare To Zero'
 * '<S7>'   : 'single_qc_ppid/transformed_PID/PIDa/Discrete Derivative1'
 * '<S8>'   : 'single_qc_ppid/transformed_PID/PIDa/Discrete Derivative2'
 * '<S9>'   : 'single_qc_ppid/transformed_PID/PIDb/Discrete Derivative1'
 * '<S10>'  : 'single_qc_ppid/transformed_PID/PIDb/Discrete Derivative2'
 */
#endif                                 /* RTW_HEADER_single_qc_ppid_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

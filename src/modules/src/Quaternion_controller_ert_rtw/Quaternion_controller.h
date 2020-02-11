/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Quaternion_controller.h
 *
 * Code generated for Simulink model 'Quaternion_controller'.
 *
 * Model version                  : 1.56
 * Simulink Coder version         : 8.14 (R2018a) 06-Feb-2018
 * C/C++ source code generated on : Wed Nov 13 15:33:34 2019
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Quaternion_controller_h_
#define RTW_HEADER_Quaternion_controller_h_
#include <math.h>
#include <string.h>
#include <stddef.h>
#ifndef Quaternion_controller_COMMON_INCLUDES_
# define Quaternion_controller_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#endif                                 /* Quaternion_controller_COMMON_INCLUDES_ */

#include "Quaternion_controller_types.h"
#include "rt_assert.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Block signals (default storage) */
typedef struct {
  real32_T Merge[4];                   /* '<S13>/Merge' */
} B_Quaternion_controller_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  void* Assertion_slioAccessor;        /* '<S48>/Assertion' */
  void* Assertion_slioAccessor_b;      /* '<S49>/Assertion' */
  void* Assertion_slioAccessor_e;      /* '<S50>/Assertion' */
  void* Assertion_slioAccessor_h;      /* '<S51>/Assertion' */
  real32_T DiscreteTimeIntegrator_DSTATE[3];/* '<S1>/Discrete-Time Integrator' */
  real32_T UD_DSTATE[4];               /* '<S3>/UD' */
  real32_T DiscreteFIRFilter3_states[597];/* '<S1>/Discrete FIR Filter3' */
  real32_T UD_DSTATE_i[3];             /* '<S2>/UD' */
  real32_T DiscreteFIRFilter_states[12];/* '<Root>/Discrete FIR Filter' */
  real32_T DiscreteTransferFcn1_states[4];/* '<S4>/Discrete Transfer Fcn1' */
  real32_T DiscreteFIRFilter1_states[12];/* '<Root>/Discrete FIR Filter1' */
  real32_T DiscreteFIRFilter2_states[19];/* '<Root>/Discrete FIR Filter2' */
  int32_T DiscreteFIRFilter3_circBuf;  /* '<S1>/Discrete FIR Filter3' */
  int32_T DiscreteFIRFilter_circBuf;   /* '<Root>/Discrete FIR Filter' */
  int32_T DiscreteFIRFilter1_circBuf;  /* '<Root>/Discrete FIR Filter1' */
  int32_T DiscreteFIRFilter2_circBuf;  /* '<Root>/Discrete FIR Filter2' */
  uint16_T Memory_PreviousInput[4];    /* '<Root>/Memory' */
} DW_Quaternion_controller_T;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCSigState DiscreteTransferFcn1_Reset_ZCE;/* '<S4>/Discrete Transfer Fcn1' */
} PrevZCX_Quaternion_controller_T;

/* External inputs (root inport signals with default storage) */
typedef struct {
  real32_T qw;                         /* '<Root>/qw' */
  real32_T qx;                         /* '<Root>/qx' */
  real32_T qy;                         /* '<Root>/qy' */
  real32_T qz;                         /* '<Root>/qz' */
  real32_T ax;                         /* '<Root>/ax' */
  real32_T ay;                         /* '<Root>/ay' */
  real32_T az;                         /* '<Root>/az' */
  real32_T yaw_setpoint;               /* '<Root>/yaw_setpoint' */
  real32_T p;                          /* '<Root>/p' */
  real32_T q;                          /* '<Root>/q' */
  real32_T r;                          /* '<Root>/r' */
} ExtU_Quaternion_controller_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  uint16_T M1_output;                  /* '<Root>/M1_output' */
  uint16_T M2_output;                  /* '<Root>/M2_output' */
  uint16_T M3_output;                  /* '<Root>/M3_output' */
  uint16_T M4_output;                  /* '<Root>/M4_output' */
  real32_T Omega_dot_c[3];             /* '<Root>/Omega_dot_c' */
} ExtY_Quaternion_controller_T;

/* Parameters (default storage) */
struct P_Quaternion_controller_T_ {
  real32_T K_xi;                       /* Variable: K_xi
                                        * Referenced by: '<S1>/K_xi'
                                        */
  real32_T K_xi_dot;                   /* Variable: K_xi_dot
                                        * Referenced by: '<S1>/K_xi_dot'
                                        */
  real32_T K_xi_int;                   /* Variable: K_xi_int
                                        * Referenced by: '<S1>/K_xi_int'
                                        */
  real32_T inertia[9];                 /* Variable: inertia
                                        * Referenced by: '<S10>/momentum of inertia'
                                        */
  real32_T mass;                       /* Variable: mass
                                        * Referenced by:
                                        *   '<S4>/Gain'
                                        *   '<S6>/mass'
                                        */
  real32_T mu_f_gain;                  /* Variable: mu_f_gain
                                        * Referenced by: '<S10>/mu_f_gain'
                                        */
  real32_T omega_dot_f_gain;           /* Variable: omega_dot_f_gain
                                        * Referenced by: '<S10>/omega_dot_f_gain'
                                        */
  real_T DirectionCosineMatrixtoQuaterni;/* Mask Parameter: DirectionCosineMatrixtoQuaterni
                                          * Referenced by:
                                          *   '<S19>/Constant'
                                          *   '<S44>/Constant'
                                          *   '<S45>/Constant'
                                          */
  real32_T Difference1_ICPrevInput;    /* Mask Parameter: Difference1_ICPrevInput
                                        * Referenced by: '<S3>/UD'
                                        */
  real32_T Difference_ICPrevInput;     /* Mask Parameter: Difference_ICPrevInput
                                        * Referenced by: '<S2>/UD'
                                        */
  real32_T DirectionCosineMatrixtoQuater_j;/* Mask Parameter: DirectionCosineMatrixtoQuater_j
                                            * Referenced by:
                                            *   '<S52>/Constant'
                                            *   '<S54>/Constant'
                                            */
  real_T Constant1_Value;              /* Expression: 0
                                        * Referenced by: '<S45>/Constant1'
                                        */
  real_T Constant1_Value_f;            /* Expression: 0
                                        * Referenced by: '<S44>/Constant1'
                                        */
  real_T Saturation_UpperSat;          /* Expression: 65535
                                        * Referenced by: '<Root>/Saturation'
                                        */
  real_T Saturation_LowerSat;          /* Expression: 0
                                        * Referenced by: '<Root>/Saturation'
                                        */
  real32_T Constant_Value;             /* Computed Parameter: Constant_Value
                                        * Referenced by: '<S18>/Constant'
                                        */
  real32_T Gain_Gain;                  /* Computed Parameter: Gain_Gain
                                        * Referenced by: '<S18>/Gain'
                                        */
  real32_T Gain1_Gain;                 /* Computed Parameter: Gain1_Gain
                                        * Referenced by: '<S18>/Gain1'
                                        */
  real32_T Constant2_Value[2];         /* Computed Parameter: Constant2_Value
                                        * Referenced by: '<S33>/Constant2'
                                        */
  real32_T Constant1_Value_e;          /* Computed Parameter: Constant1_Value_e
                                        * Referenced by: '<S33>/Constant1'
                                        */
  real32_T Constant_Value_d;           /* Computed Parameter: Constant_Value_d
                                        * Referenced by: '<S34>/Constant'
                                        */
  real32_T Gain1_Gain_i;               /* Computed Parameter: Gain1_Gain_i
                                        * Referenced by: '<S22>/Gain1'
                                        */
  real32_T Gain3_Gain;                 /* Computed Parameter: Gain3_Gain
                                        * Referenced by: '<S22>/Gain3'
                                        */
  real32_T Gain4_Gain;                 /* Computed Parameter: Gain4_Gain
                                        * Referenced by: '<S22>/Gain4'
                                        */
  real32_T Gain_Gain_m;                /* Computed Parameter: Gain_Gain_m
                                        * Referenced by: '<S22>/Gain'
                                        */
  real32_T Constant2_Value_i[2];       /* Computed Parameter: Constant2_Value_i
                                        * Referenced by: '<S38>/Constant2'
                                        */
  real32_T Constant1_Value_b;          /* Computed Parameter: Constant1_Value_b
                                        * Referenced by: '<S38>/Constant1'
                                        */
  real32_T Constant_Value_e;           /* Computed Parameter: Constant_Value_e
                                        * Referenced by: '<S39>/Constant'
                                        */
  real32_T Gain1_Gain_b;               /* Computed Parameter: Gain1_Gain_b
                                        * Referenced by: '<S23>/Gain1'
                                        */
  real32_T Gain2_Gain;                 /* Computed Parameter: Gain2_Gain
                                        * Referenced by: '<S23>/Gain2'
                                        */
  real32_T Gain3_Gain_n;               /* Computed Parameter: Gain3_Gain_n
                                        * Referenced by: '<S23>/Gain3'
                                        */
  real32_T Gain_Gain_f;                /* Computed Parameter: Gain_Gain_f
                                        * Referenced by: '<S23>/Gain'
                                        */
  real32_T Constant2_Value_m[2];       /* Computed Parameter: Constant2_Value_m
                                        * Referenced by: '<S28>/Constant2'
                                        */
  real32_T Constant1_Value_l;          /* Computed Parameter: Constant1_Value_l
                                        * Referenced by: '<S28>/Constant1'
                                        */
  real32_T Constant_Value_a;           /* Computed Parameter: Constant_Value_a
                                        * Referenced by: '<S29>/Constant'
                                        */
  real32_T Gain1_Gain_c;               /* Computed Parameter: Gain1_Gain_c
                                        * Referenced by: '<S21>/Gain1'
                                        */
  real32_T Gain2_Gain_p;               /* Computed Parameter: Gain2_Gain_p
                                        * Referenced by: '<S21>/Gain2'
                                        */
  real32_T Gain3_Gain_o;               /* Computed Parameter: Gain3_Gain_o
                                        * Referenced by: '<S21>/Gain3'
                                        */
  real32_T Gain_Gain_d;                /* Computed Parameter: Gain_Gain_d
                                        * Referenced by: '<S21>/Gain'
                                        */
  real32_T Bias1_Bias[9];              /* Computed Parameter: Bias1_Bias
                                        * Referenced by: '<S46>/Bias1'
                                        */
  real32_T Bias_Bias;                  /* Computed Parameter: Bias_Bias
                                        * Referenced by: '<S47>/Bias'
                                        */
  real32_T G1_Value[16];               /* Expression: inv([-length/sqrt(2),-length/sqrt(2),length/sqrt(2),length/sqrt(2); length/sqrt(2),-length/sqrt(2),-length/sqrt(2),length/sqrt(2); drag,-drag,drag,-drag; -1,-1,-1,-1])
                                        * Referenced by: '<S10>/G1'
                                        */
  real32_T G2_Value[12];               /* Expression: [-length/sqrt(2),-length/sqrt(2),length/sqrt(2),length/sqrt(2); length/sqrt(2),-length/sqrt(2),-length/sqrt(2),length/sqrt(2); drag,-drag,drag,-drag;]
                                        * Referenced by: '<S4>/G2'
                                        */
  real32_T Constant5_Value;            /* Computed Parameter: Constant5_Value
                                        * Referenced by: '<Root>/Constant5'
                                        */
  real32_T Gain2_Gain_i;               /* Computed Parameter: Gain2_Gain_i
                                        * Referenced by: '<S6>/Gain2'
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
  real32_T Merge_InitialOutput[4];     /* Computed Parameter: Merge_InitialOutput
                                        * Referenced by: '<S13>/Merge'
                                        */
  real32_T xi_dot_ref_Value[3];        /* Computed Parameter: xi_dot_ref_Value
                                        * Referenced by: '<Root>/xi_dot_ref'
                                        */
  real32_T xi_ddot_ref_Value[3];       /* Computed Parameter: xi_ddot_ref_Value
                                        * Referenced by: '<Root>/xi_ddot_ref'
                                        */
  real32_T DiscreteFIRFilter3_InitialState;/* Computed Parameter: DiscreteFIRFilter3_InitialState
                                            * Referenced by: '<S1>/Discrete FIR Filter3'
                                            */
  real32_T DiscreteFIRFilter3_Coefficients[200];/* Computed Parameter: DiscreteFIRFilter3_Coefficients
                                                 * Referenced by: '<S1>/Discrete FIR Filter3'
                                                 */
  real32_T DiscreteFIRFilter_InitialStates;/* Computed Parameter: DiscreteFIRFilter_InitialStates
                                            * Referenced by: '<Root>/Discrete FIR Filter'
                                            */
  real32_T DiscreteFIRFilter_Coefficients[5];/* Computed Parameter: DiscreteFIRFilter_Coefficients
                                              * Referenced by: '<Root>/Discrete FIR Filter'
                                              */
  real32_T Constant_Value_l;           /* Computed Parameter: Constant_Value_l
                                        * Referenced by: '<Root>/Constant'
                                        */
  real32_T Gain1_Gain_m;               /* Computed Parameter: Gain1_Gain_m
                                        * Referenced by: '<S6>/Gain1'
                                        */
  real32_T DiscreteTransferFcn1_NumCoef[2];/* Computed Parameter: DiscreteTransferFcn1_NumCoef
                                            * Referenced by: '<S4>/Discrete Transfer Fcn1'
                                            */
  real32_T DiscreteTransferFcn1_DenCoef[2];/* Computed Parameter: DiscreteTransferFcn1_DenCoef
                                            * Referenced by: '<S4>/Discrete Transfer Fcn1'
                                            */
  real32_T DiscreteTransferFcn1_InitialSta;/* Computed Parameter: DiscreteTransferFcn1_InitialSta
                                            * Referenced by: '<S4>/Discrete Transfer Fcn1'
                                            */
  real32_T DiscreteFIRFilter1_InitialState;/* Computed Parameter: DiscreteFIRFilter1_InitialState
                                            * Referenced by: '<Root>/Discrete FIR Filter1'
                                            */
  real32_T DiscreteFIRFilter1_Coefficients[5];/* Computed Parameter: DiscreteFIRFilter1_Coefficients
                                               * Referenced by: '<Root>/Discrete FIR Filter1'
                                               */
  real32_T Saturation_UpperSat_e;      /* Computed Parameter: Saturation_UpperSat_e
                                        * Referenced by: '<S10>/Saturation'
                                        */
  real32_T Saturation_LowerSat_h;      /* Computed Parameter: Saturation_LowerSat_h
                                        * Referenced by: '<S10>/Saturation'
                                        */
  real32_T G1_Value_c[4];              /* Computed Parameter: G1_Value_c
                                        * Referenced by: '<S4>/G1'
                                        */
  real32_T Gain2_Gain_h;               /* Computed Parameter: Gain2_Gain_h
                                        * Referenced by: '<S4>/Gain2'
                                        */
  real32_T DiscreteFIRFilter2_InitialState;/* Computed Parameter: DiscreteFIRFilter2_InitialState
                                            * Referenced by: '<Root>/Discrete FIR Filter2'
                                            */
  real32_T DiscreteFIRFilter2_Coefficients[20];/* Computed Parameter: DiscreteFIRFilter2_Coefficients
                                                * Referenced by: '<Root>/Discrete FIR Filter2'
                                                */
  real32_T Gain_Gain_p;                /* Computed Parameter: Gain_Gain_p
                                        * Referenced by: '<S58>/Gain'
                                        */
  real32_T Gain_Gain_e;                /* Computed Parameter: Gain_Gain_e
                                        * Referenced by: '<S61>/Gain'
                                        */
  real32_T Gain_Gain_i;                /* Computed Parameter: Gain_Gain_i
                                        * Referenced by: '<S56>/Gain'
                                        */
  real32_T Gain_Gain_fs;               /* Computed Parameter: Gain_Gain_fs
                                        * Referenced by: '<S62>/Gain'
                                        */
  real32_T Gain_Gain_k;                /* Computed Parameter: Gain_Gain_k
                                        * Referenced by: '<S57>/Gain'
                                        */
  real32_T Gain_Gain_i1;               /* Computed Parameter: Gain_Gain_i1
                                        * Referenced by: '<S60>/Gain'
                                        */
  real32_T j_ref_Value[3];             /* Computed Parameter: j_ref_Value
                                        * Referenced by: '<Root>/j_ref'
                                        */
  real32_T s_ref_Value[3];             /* Computed Parameter: s_ref_Value
                                        * Referenced by: '<Root>/s_ref'
                                        */
  real32_T psi_ddot_ref_Value;         /* Computed Parameter: psi_ddot_ref_Value
                                        * Referenced by: '<Root>/psi_ddot_ref'
                                        */
  real32_T psi_dot_ref_Value;          /* Computed Parameter: psi_dot_ref_Value
                                        * Referenced by: '<Root>/psi_dot_ref'
                                        */
  uint16_T Memory_InitialCondition;    /* Computed Parameter: Memory_InitialCondition
                                        * Referenced by: '<Root>/Memory'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_Quaternion_controller_T {
  const char_T * volatile errorStatus;
};

/* Block parameters (default storage) */
extern P_Quaternion_controller_T Quaternion_controller_P;

/* Block signals (default storage) */
extern B_Quaternion_controller_T Quaternion_controller_B;

/* Block states (default storage) */
extern DW_Quaternion_controller_T Quaternion_controller_DW;

/* External inputs (root inport signals with default storage) */
extern ExtU_Quaternion_controller_T Quaternion_controller_U;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_Quaternion_controller_T Quaternion_controller_Y;

/* Model entry point functions */
extern void Quaternion_controller_initialize(void);
extern void Quaternion_controller_step(void);
extern void Quaternion_controller_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Quaternion_controlle_T *const Quaternion_controller_M;

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
 * '<Root>' : 'Quaternion_controller'
 * '<S1>'   : 'Quaternion_controller/AARC'
 * '<S2>'   : 'Quaternion_controller/Difference'
 * '<S3>'   : 'Quaternion_controller/Difference1'
 * '<S4>'   : 'Quaternion_controller/Force_Estimation'
 * '<S5>'   : 'Quaternion_controller/JT'
 * '<S6>'   : 'Quaternion_controller/LAC'
 * '<S7>'   : 'Quaternion_controller/MATLAB Function'
 * '<S8>'   : 'Quaternion_controller/Quaternions to  Direction Cosine Matrix'
 * '<S9>'   : 'Quaternion_controller/ST'
 * '<S10>'  : 'Quaternion_controller/mixer'
 * '<S11>'  : 'Quaternion_controller/AARC/quaternion_error'
 * '<S12>'  : 'Quaternion_controller/Force_Estimation/vector norm'
 * '<S13>'  : 'Quaternion_controller/LAC/Direction Cosine Matrix  to Quaternions'
 * '<S14>'  : 'Quaternion_controller/LAC/MATLAB Function2'
 * '<S15>'  : 'Quaternion_controller/LAC/alpha'
 * '<S16>'  : 'Quaternion_controller/LAC/vector norm'
 * '<S17>'  : 'Quaternion_controller/LAC/Direction Cosine Matrix  to Quaternions/Negative Trace'
 * '<S18>'  : 'Quaternion_controller/LAC/Direction Cosine Matrix  to Quaternions/Positive Trace'
 * '<S19>'  : 'Quaternion_controller/LAC/Direction Cosine Matrix  to Quaternions/Validate DCM'
 * '<S20>'  : 'Quaternion_controller/LAC/Direction Cosine Matrix  to Quaternions/trace(DCM)'
 * '<S21>'  : 'Quaternion_controller/LAC/Direction Cosine Matrix  to Quaternions/Negative Trace/Maximum Value at DCM(1,1)'
 * '<S22>'  : 'Quaternion_controller/LAC/Direction Cosine Matrix  to Quaternions/Negative Trace/Maximum Value at DCM(2,2)'
 * '<S23>'  : 'Quaternion_controller/LAC/Direction Cosine Matrix  to Quaternions/Negative Trace/Maximum Value at DCM(3,3)'
 * '<S24>'  : 'Quaternion_controller/LAC/Direction Cosine Matrix  to Quaternions/Negative Trace/diag(DCM)'
 * '<S25>'  : 'Quaternion_controller/LAC/Direction Cosine Matrix  to Quaternions/Negative Trace/Maximum Value at DCM(1,1)/cos(phi)sin(theta)cos(psi) + sin(phi)sin(psi) -sin(theta)'
 * '<S26>'  : 'Quaternion_controller/LAC/Direction Cosine Matrix  to Quaternions/Negative Trace/Maximum Value at DCM(1,1)/cos(theta)sin(phi) - (cos(phi)sin(theta)sin(psi) - sin(phi)cos(psi))'
 * '<S27>'  : 'Quaternion_controller/LAC/Direction Cosine Matrix  to Quaternions/Negative Trace/Maximum Value at DCM(1,1)/cos(theta)sin(psi) + (sin(phi)sin(theta)cos(psi) - cos(phi)sin(psi))'
 * '<S28>'  : 'Quaternion_controller/LAC/Direction Cosine Matrix  to Quaternions/Negative Trace/Maximum Value at DCM(1,1)/if s~=0; s=0.5//s'
 * '<S29>'  : 'Quaternion_controller/LAC/Direction Cosine Matrix  to Quaternions/Negative Trace/Maximum Value at DCM(1,1)/u(1) -(u(5)+u(9)) +1'
 * '<S30>'  : 'Quaternion_controller/LAC/Direction Cosine Matrix  to Quaternions/Negative Trace/Maximum Value at DCM(2,2)/cos(phi)sin(theta)cos(psi) + sin(phi)sin(psi) +sin(theta)'
 * '<S31>'  : 'Quaternion_controller/LAC/Direction Cosine Matrix  to Quaternions/Negative Trace/Maximum Value at DCM(2,2)/cos(theta)sin(phi) + (cos(phi)sin(theta)sin(psi) - sin(phi)cos(psi))'
 * '<S32>'  : 'Quaternion_controller/LAC/Direction Cosine Matrix  to Quaternions/Negative Trace/Maximum Value at DCM(2,2)/cos(theta)sin(psi) + (sin(phi)sin(theta)cos(psi) - cos(phi)sin(psi))'
 * '<S33>'  : 'Quaternion_controller/LAC/Direction Cosine Matrix  to Quaternions/Negative Trace/Maximum Value at DCM(2,2)/if s~=0; s=0.5//s'
 * '<S34>'  : 'Quaternion_controller/LAC/Direction Cosine Matrix  to Quaternions/Negative Trace/Maximum Value at DCM(2,2)/u(5) -(u(1)+u(9)) +1'
 * '<S35>'  : 'Quaternion_controller/LAC/Direction Cosine Matrix  to Quaternions/Negative Trace/Maximum Value at DCM(3,3)/cos(phi)sin(theta)cos(psi) + sin(phi)sin(psi) -sin(theta)'
 * '<S36>'  : 'Quaternion_controller/LAC/Direction Cosine Matrix  to Quaternions/Negative Trace/Maximum Value at DCM(3,3)/cos(theta)sin(phi) + (cos(phi)sin(theta)sin(psi) - sin(phi)cos(psi))'
 * '<S37>'  : 'Quaternion_controller/LAC/Direction Cosine Matrix  to Quaternions/Negative Trace/Maximum Value at DCM(3,3)/cos(theta)sin(psi) - (sin(phi)sin(theta)cos(psi) - cos(phi)sin(psi))'
 * '<S38>'  : 'Quaternion_controller/LAC/Direction Cosine Matrix  to Quaternions/Negative Trace/Maximum Value at DCM(3,3)/if s~=0; s=0.5//s'
 * '<S39>'  : 'Quaternion_controller/LAC/Direction Cosine Matrix  to Quaternions/Negative Trace/Maximum Value at DCM(3,3)/u(9) -(u(1)+u(5)) +1'
 * '<S40>'  : 'Quaternion_controller/LAC/Direction Cosine Matrix  to Quaternions/Positive Trace/cos(phi)sin(theta)cos(psi) + sin(phi)sin(psi) +sin(theta)'
 * '<S41>'  : 'Quaternion_controller/LAC/Direction Cosine Matrix  to Quaternions/Positive Trace/cos(theta)sin(phi) - (cos(phi)sin(theta)sin(psi) - sin(phi)cos(psi))'
 * '<S42>'  : 'Quaternion_controller/LAC/Direction Cosine Matrix  to Quaternions/Positive Trace/cos(theta)sin(psi) - (sin(phi)sin(theta)cos(psi) - cos(phi)sin(psi))'
 * '<S43>'  : 'Quaternion_controller/LAC/Direction Cosine Matrix  to Quaternions/Validate DCM/If Warning//Error'
 * '<S44>'  : 'Quaternion_controller/LAC/Direction Cosine Matrix  to Quaternions/Validate DCM/If Warning//Error/Else If Not Orthogonal'
 * '<S45>'  : 'Quaternion_controller/LAC/Direction Cosine Matrix  to Quaternions/Validate DCM/If Warning//Error/If Not Proper'
 * '<S46>'  : 'Quaternion_controller/LAC/Direction Cosine Matrix  to Quaternions/Validate DCM/If Warning//Error/isNotOrthogonal'
 * '<S47>'  : 'Quaternion_controller/LAC/Direction Cosine Matrix  to Quaternions/Validate DCM/If Warning//Error/isNotProper'
 * '<S48>'  : 'Quaternion_controller/LAC/Direction Cosine Matrix  to Quaternions/Validate DCM/If Warning//Error/Else If Not Orthogonal/Error'
 * '<S49>'  : 'Quaternion_controller/LAC/Direction Cosine Matrix  to Quaternions/Validate DCM/If Warning//Error/Else If Not Orthogonal/Warning'
 * '<S50>'  : 'Quaternion_controller/LAC/Direction Cosine Matrix  to Quaternions/Validate DCM/If Warning//Error/If Not Proper/Error'
 * '<S51>'  : 'Quaternion_controller/LAC/Direction Cosine Matrix  to Quaternions/Validate DCM/If Warning//Error/If Not Proper/Warning'
 * '<S52>'  : 'Quaternion_controller/LAC/Direction Cosine Matrix  to Quaternions/Validate DCM/If Warning//Error/isNotOrthogonal/transpose*dcm ~= eye(3)'
 * '<S53>'  : 'Quaternion_controller/LAC/Direction Cosine Matrix  to Quaternions/Validate DCM/If Warning//Error/isNotProper/Determinant of 3x3 Matrix'
 * '<S54>'  : 'Quaternion_controller/LAC/Direction Cosine Matrix  to Quaternions/Validate DCM/If Warning//Error/isNotProper/determinant does not equal 1'
 * '<S55>'  : 'Quaternion_controller/Quaternions to  Direction Cosine Matrix/A11'
 * '<S56>'  : 'Quaternion_controller/Quaternions to  Direction Cosine Matrix/A12'
 * '<S57>'  : 'Quaternion_controller/Quaternions to  Direction Cosine Matrix/A13'
 * '<S58>'  : 'Quaternion_controller/Quaternions to  Direction Cosine Matrix/A21'
 * '<S59>'  : 'Quaternion_controller/Quaternions to  Direction Cosine Matrix/A22'
 * '<S60>'  : 'Quaternion_controller/Quaternions to  Direction Cosine Matrix/A23'
 * '<S61>'  : 'Quaternion_controller/Quaternions to  Direction Cosine Matrix/A31'
 * '<S62>'  : 'Quaternion_controller/Quaternions to  Direction Cosine Matrix/A32'
 * '<S63>'  : 'Quaternion_controller/Quaternions to  Direction Cosine Matrix/A33'
 * '<S64>'  : 'Quaternion_controller/Quaternions to  Direction Cosine Matrix/Create 3x3 Matrix'
 * '<S65>'  : 'Quaternion_controller/Quaternions to  Direction Cosine Matrix/Quaternion Normalize'
 * '<S66>'  : 'Quaternion_controller/Quaternions to  Direction Cosine Matrix/Quaternion Normalize/Quaternion Modulus'
 * '<S67>'  : 'Quaternion_controller/Quaternions to  Direction Cosine Matrix/Quaternion Normalize/Quaternion Modulus/Quaternion Norm'
 * '<S68>'  : 'Quaternion_controller/ST/MATLAB Function'
 * '<S69>'  : 'Quaternion_controller/ST/MATLAB Function1'
 * '<S70>'  : 'Quaternion_controller/mixer/force2motorCMD'
 */
#endif                                 /* RTW_HEADER_Quaternion_controller_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

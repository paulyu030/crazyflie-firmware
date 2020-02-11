/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: rotor_combined_controller.c
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

#include "rotor_combined_controller.h"
#include "rotor_combined_controller_private.h"

/* Block states (default storage) */
DW_rotor_combined_controller_T rotor_combined_controller_DW;

/* External inputs (root inport signals with default storage) */
ExtU_rotor_combined_controlle_T rotor_combined_controller_U;

/* External outputs (root outports fed by signals with default storage) */
ExtY_rotor_combined_controlle_T rotor_combined_controller_Y;

/* Real-time model */
RT_MODEL_rotor_combined_contr_T rotor_combined_controller_M_;
RT_MODEL_rotor_combined_contr_T *const rotor_combined_controller_M =
  &rotor_combined_controller_M_;

/* Forward declaration for local functions */
static void rotor_combined_control_mldivide(const real32_T A[16], real32_T B[4]);

/* Function for MATLAB Function: '<Root>/MATLAB Function' */
static void rotor_combined_control_mldivide(const real32_T A[16], real32_T B[4])
{
  real32_T b_A[16];
  int8_T ipiv[4];
  int32_T j;
  int32_T c;
  int32_T ix;
  real32_T smax;
  real32_T s;
  int32_T k;
  int32_T b_ix;
  int32_T c_ix;
  int32_T d;
  int32_T ijA;
  memcpy(&b_A[0], &A[0], sizeof(real32_T) << 4U);
  ipiv[0] = 1;
  ipiv[1] = 2;
  ipiv[2] = 3;
  ipiv[3] = 4;
  for (j = 0; j < 3; j++) {
    c = j * 5;
    b_ix = 0;
    ix = c;
    smax = fabsf(b_A[c]);
    for (k = 2; k <= 4 - j; k++) {
      ix++;
      s = fabsf(b_A[ix]);
      if (s > smax) {
        b_ix = k - 1;
        smax = s;
      }
    }

    if (b_A[c + b_ix] != 0.0F) {
      if (b_ix != 0) {
        ix = j + b_ix;
        ipiv[j] = (int8_T)(ix + 1);
        smax = b_A[j];
        b_A[j] = b_A[ix];
        b_A[ix] = smax;
        b_ix = j + 4;
        ix += 4;
        smax = b_A[b_ix];
        b_A[b_ix] = b_A[ix];
        b_A[ix] = smax;
        b_ix += 4;
        ix += 4;
        smax = b_A[b_ix];
        b_A[b_ix] = b_A[ix];
        b_A[ix] = smax;
        b_ix += 4;
        ix += 4;
        smax = b_A[b_ix];
        b_A[b_ix] = b_A[ix];
        b_A[ix] = smax;
      }

      b_ix = (c - j) + 4;
      for (ix = c + 1; ix < b_ix; ix++) {
        b_A[ix] /= b_A[c];
      }
    }

    b_ix = c;
    ix = c + 4;
    for (k = 1; k <= 3 - j; k++) {
      smax = b_A[ix];
      if (b_A[ix] != 0.0F) {
        c_ix = c + 1;
        d = (b_ix - j) + 8;
        for (ijA = 5 + b_ix; ijA < d; ijA++) {
          b_A[ijA] += b_A[c_ix] * -smax;
          c_ix++;
        }
      }

      ix += 4;
      b_ix += 4;
    }

    if (j + 1 != ipiv[j]) {
      smax = B[j];
      c = ipiv[j] - 1;
      B[j] = B[c];
      B[c] = smax;
    }
  }

  if (B[0] != 0.0F) {
    for (j = 1; j + 1 < 5; j++) {
      B[j] -= B[0] * b_A[j];
    }
  }

  if (B[1] != 0.0F) {
    for (j = 2; j + 1 < 5; j++) {
      B[j] -= b_A[j + 4] * B[1];
    }
  }

  if (B[2] != 0.0F) {
    for (j = 3; j + 1 < 5; j++) {
      B[j] -= b_A[j + 8] * B[2];
    }
  }

  if (B[3] != 0.0F) {
    B[3] /= b_A[15];
    for (j = 0; j < 3; j++) {
      B[j] -= b_A[j + 12] * B[3];
    }
  }

  if (B[2] != 0.0F) {
    B[2] /= b_A[10];
    for (j = 0; j < 2; j++) {
      B[j] -= b_A[j + 8] * B[2];
    }
  }

  if (B[1] != 0.0F) {
    B[1] /= b_A[5];
    for (j = 0; j < 1; j++) {
      B[j] -= b_A[j + 4] * B[1];
    }
  }

  if (B[0] != 0.0F) {
    B[0] /= b_A[0];
  }
}

/* Model step function */
void rotor_combined_controller_step(void)
{
  /* local block i/o variables */
  real32_T rtb_Saturation[3];
  real32_T rtb_y[4];
  real32_T rtb_y_a[4];
  int32_T j;
  int32_T cff;
  static const real32_T b[4] = { 0.1F, -0.1F, 0.1F, -0.1F };

  static const int8_T c[24] = { 0, -2, 0, 2, -2, 0, 2, 0, 0, 0, 0, 0, -1, 0, 1,
    0, 0, 1, 0, -1, 0, 0, 0, 0 };

  real32_T rtb_Product3_m;
  real32_T rtb_Product2_j;
  real32_T rtb_Product1_bv;
  real32_T rtb_Product_d;
  real32_T rtb_VectorConcatenate[9];
  real32_T rtb_TmpSignalConversionAtSFunct[6];
  real32_T tmp[16];
  real32_T tmp_0[4];
  real32_T tmp_1[6];
  real32_T tmp_2[12];
  real32_T rtb_VectorConcatenate_0[12];
  real32_T rtb_DiscreteTimeIntegrator_g_id;
  real32_T rtb_Sum_ce_idx_0;
  real32_T rtb_DiscreteTimeIntegrator_g__0;
  real32_T rtb_Sum_ce_idx_1;
  real32_T rtb_Sum_ce_idx_2;
  real32_T rtb_VectorConcatenate_tmp;
  real32_T rtb_VectorConcatenate_tmp_0;
  real32_T rtb_VectorConcatenate_tmp_1;
  int32_T rtb_VectorConcatenate_tmp_2;
  real32_T tmp_3;
  real32_T tmp_4;

  /* Sqrt: '<S19>/sqrt' incorporates:
   *  Inport: '<Root>/q_f'
   *  Product: '<S20>/Product'
   *  Product: '<S20>/Product1'
   *  Product: '<S20>/Product2'
   *  Product: '<S20>/Product3'
   *  Sum: '<S20>/Sum'
   */
  rtb_Product3_m = sqrtf(((rotor_combined_controller_U.q_f[0] *
    rotor_combined_controller_U.q_f[0] + rotor_combined_controller_U.q_f[1] *
    rotor_combined_controller_U.q_f[1]) + rotor_combined_controller_U.q_f[2] *
    rotor_combined_controller_U.q_f[2]) + rotor_combined_controller_U.q_f[3] *
    rotor_combined_controller_U.q_f[3]);

  /* Product: '<S18>/Product' incorporates:
   *  Inport: '<Root>/q_f'
   */
  rtb_Product_d = rotor_combined_controller_U.q_f[0] / rtb_Product3_m;

  /* Product: '<S18>/Product1' incorporates:
   *  Inport: '<Root>/q_f'
   */
  rtb_Product1_bv = rotor_combined_controller_U.q_f[1] / rtb_Product3_m;

  /* Product: '<S18>/Product2' incorporates:
   *  Inport: '<Root>/q_f'
   */
  rtb_Product2_j = rotor_combined_controller_U.q_f[2] / rtb_Product3_m;

  /* Product: '<S18>/Product3' incorporates:
   *  Inport: '<Root>/q_f'
   */
  rtb_Product3_m = rotor_combined_controller_U.q_f[3] / rtb_Product3_m;

  /* Product: '<S8>/Product3' incorporates:
   *  Product: '<S12>/Product3'
   */
  rtb_Sum_ce_idx_0 = rtb_Product_d * rtb_Product_d;

  /* Product: '<S8>/Product2' incorporates:
   *  Product: '<S12>/Product2'
   */
  rtb_Sum_ce_idx_1 = rtb_Product1_bv * rtb_Product1_bv;

  /* Product: '<S8>/Product1' incorporates:
   *  Product: '<S12>/Product1'
   *  Product: '<S16>/Product1'
   */
  rtb_Sum_ce_idx_2 = rtb_Product2_j * rtb_Product2_j;

  /* Product: '<S8>/Product' incorporates:
   *  Product: '<S12>/Product'
   *  Product: '<S16>/Product'
   */
  rtb_DiscreteTimeIntegrator_g_id = rtb_Product3_m * rtb_Product3_m;

  /* Sum: '<S8>/Sum' incorporates:
   *  Product: '<S8>/Product'
   *  Product: '<S8>/Product1'
   *  Product: '<S8>/Product2'
   *  Product: '<S8>/Product3'
   */
  rtb_VectorConcatenate[0] = ((rtb_Sum_ce_idx_0 + rtb_Sum_ce_idx_1) -
    rtb_Sum_ce_idx_2) - rtb_DiscreteTimeIntegrator_g_id;

  /* Product: '<S11>/Product3' incorporates:
   *  Product: '<S9>/Product3'
   */
  rtb_VectorConcatenate_tmp = rtb_Product3_m * rtb_Product_d;

  /* Product: '<S11>/Product2' incorporates:
   *  Product: '<S9>/Product2'
   */
  rtb_DiscreteTimeIntegrator_g__0 = rtb_Product1_bv * rtb_Product2_j;

  /* Gain: '<S11>/Gain' incorporates:
   *  Product: '<S11>/Product2'
   *  Product: '<S11>/Product3'
   *  Sum: '<S11>/Sum'
   */
  rtb_VectorConcatenate[1] = (rtb_DiscreteTimeIntegrator_g__0 -
    rtb_VectorConcatenate_tmp) * rotor_combined_controller_P.Gain_Gain;

  /* Product: '<S14>/Product2' incorporates:
   *  Product: '<S10>/Product2'
   */
  rtb_VectorConcatenate_tmp_0 = rtb_Product1_bv * rtb_Product3_m;

  /* Product: '<S14>/Product1' incorporates:
   *  Product: '<S10>/Product1'
   */
  rtb_VectorConcatenate_tmp_1 = rtb_Product_d * rtb_Product2_j;

  /* Gain: '<S14>/Gain' incorporates:
   *  Product: '<S14>/Product1'
   *  Product: '<S14>/Product2'
   *  Sum: '<S14>/Sum'
   */
  rtb_VectorConcatenate[2] = (rtb_VectorConcatenate_tmp_1 +
    rtb_VectorConcatenate_tmp_0) * rotor_combined_controller_P.Gain_Gain_a;

  /* Gain: '<S9>/Gain' incorporates:
   *  Sum: '<S9>/Sum'
   */
  rtb_VectorConcatenate[3] = (rtb_VectorConcatenate_tmp +
    rtb_DiscreteTimeIntegrator_g__0) * rotor_combined_controller_P.Gain_Gain_k;

  /* Sum: '<S12>/Sum' incorporates:
   *  Sum: '<S16>/Sum'
   */
  rtb_Sum_ce_idx_0 -= rtb_Sum_ce_idx_1;
  rtb_VectorConcatenate[4] = (rtb_Sum_ce_idx_0 + rtb_Sum_ce_idx_2) -
    rtb_DiscreteTimeIntegrator_g_id;

  /* Product: '<S15>/Product1' incorporates:
   *  Product: '<S13>/Product1'
   */
  rtb_Sum_ce_idx_1 = rtb_Product_d * rtb_Product1_bv;

  /* Product: '<S15>/Product2' incorporates:
   *  Product: '<S13>/Product2'
   */
  rtb_VectorConcatenate_tmp = rtb_Product2_j * rtb_Product3_m;

  /* Gain: '<S15>/Gain' incorporates:
   *  Product: '<S15>/Product1'
   *  Product: '<S15>/Product2'
   *  Sum: '<S15>/Sum'
   */
  rtb_VectorConcatenate[5] = (rtb_VectorConcatenate_tmp - rtb_Sum_ce_idx_1) *
    rotor_combined_controller_P.Gain_Gain_g;

  /* Gain: '<S10>/Gain' incorporates:
   *  Sum: '<S10>/Sum'
   */
  rtb_VectorConcatenate[6] = (rtb_VectorConcatenate_tmp_0 -
    rtb_VectorConcatenate_tmp_1) * rotor_combined_controller_P.Gain_Gain_p;

  /* Gain: '<S13>/Gain' incorporates:
   *  Sum: '<S13>/Sum'
   */
  rtb_VectorConcatenate[7] = (rtb_Sum_ce_idx_1 + rtb_VectorConcatenate_tmp) *
    rotor_combined_controller_P.Gain_Gain_p4;

  /* Sum: '<S16>/Sum' */
  rtb_VectorConcatenate[8] = (rtb_Sum_ce_idx_0 - rtb_Sum_ce_idx_2) +
    rtb_DiscreteTimeIntegrator_g_id;

  /* Sum: '<S1>/Sum4' incorporates:
   *  Inport: '<Root>/euler_cmd'
   *  Inport: '<Root>/euler_f'
   */
  rtb_Product3_m = rotor_combined_controller_U.euler_cmd[0] -
    rotor_combined_controller_U.euler_f[0];
  rtb_Product_d = rotor_combined_controller_U.euler_cmd[1] -
    rotor_combined_controller_U.euler_f[1];
  rtb_Product1_bv = rotor_combined_controller_U.euler_cmd[2] -
    rotor_combined_controller_U.euler_f[2];

  /* MATLAB Function: '<Root>/MATLAB Function2' incorporates:
   *  Inport: '<Root>/q_f'
   */
  tmp[0] = 1000.0F * rotor_combined_controller_U.q_f[0];
  tmp[4] = 1000.0F * rotor_combined_controller_U.q_f[1];
  tmp[8] = 1000.0F * rotor_combined_controller_U.q_f[2];
  tmp[12] = 1000.0F * rotor_combined_controller_U.q_f[3];
  rtb_Product2_j = 1000.0F * -rotor_combined_controller_U.q_f[1];
  tmp[1] = rtb_Product2_j;
  tmp[5] = 1000.0F * rotor_combined_controller_U.q_f[0];
  tmp[9] = 1000.0F * rotor_combined_controller_U.q_f[3];
  rtb_DiscreteTimeIntegrator_g_id = 1000.0F * -rotor_combined_controller_U.q_f[2];
  tmp[13] = rtb_DiscreteTimeIntegrator_g_id;
  tmp[2] = rtb_DiscreteTimeIntegrator_g_id;
  rtb_DiscreteTimeIntegrator_g_id = 1000.0F * -rotor_combined_controller_U.q_f[3];
  tmp[6] = rtb_DiscreteTimeIntegrator_g_id;
  tmp[10] = 1000.0F * rotor_combined_controller_U.q_f[0];
  tmp[14] = 1000.0F * rotor_combined_controller_U.q_f[1];
  tmp[3] = rtb_DiscreteTimeIntegrator_g_id;
  tmp[7] = 1000.0F * rotor_combined_controller_U.q_f[2];
  tmp[11] = rtb_Product2_j;
  tmp[15] = 1000.0F * rotor_combined_controller_U.q_f[0];

  /* Sum: '<S2>/Diff' incorporates:
   *  Inport: '<Root>/q_f'
   *  MATLAB Function: '<Root>/MATLAB Function2'
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
  rtb_DiscreteTimeIntegrator_g_id = rotor_combined_controller_U.q_f[0] -
    rotor_combined_controller_DW.UD_DSTATE[0];
  rtb_DiscreteTimeIntegrator_g__0 = rotor_combined_controller_U.q_f[1] -
    rotor_combined_controller_DW.UD_DSTATE[1];
  rtb_VectorConcatenate_tmp = rotor_combined_controller_U.q_f[2] -
    rotor_combined_controller_DW.UD_DSTATE[2];
  rtb_Sum_ce_idx_0 = rotor_combined_controller_U.q_f[3] -
    rotor_combined_controller_DW.UD_DSTATE[3];

  /* MATLAB Function: '<Root>/MATLAB Function2' */
  for (cff = 0; cff < 4; cff++) {
    rtb_Product2_j = tmp[cff + 12] * rtb_Sum_ce_idx_0 + (tmp[cff + 8] *
      rtb_VectorConcatenate_tmp + (tmp[cff + 4] *
      rtb_DiscreteTimeIntegrator_g__0 + tmp[cff] *
      rtb_DiscreteTimeIntegrator_g_id));
    tmp_0[cff] = rtb_Product2_j;
  }

  /* DiscreteFir: '<Root>/Discrete FIR Filter' incorporates:
   *  MATLAB Function: '<Root>/MATLAB Function2'
   */
  rtb_VectorConcatenate_tmp = tmp_0[1] *
    rotor_combined_controller_P.DiscreteFIRFilter_Coefficients[0];
  cff = 1;
  for (j = rotor_combined_controller_DW.DiscreteFIRFilter_circBuf; j < 4; j++) {
    rtb_VectorConcatenate_tmp +=
      rotor_combined_controller_DW.DiscreteFIRFilter_states[j] *
      rotor_combined_controller_P.DiscreteFIRFilter_Coefficients[cff];
    cff++;
  }

  for (j = 0; j < rotor_combined_controller_DW.DiscreteFIRFilter_circBuf; j++) {
    rtb_VectorConcatenate_tmp +=
      rotor_combined_controller_DW.DiscreteFIRFilter_states[j] *
      rotor_combined_controller_P.DiscreteFIRFilter_Coefficients[cff];
    cff++;
  }

  rtb_DiscreteTimeIntegrator_g_id = rtb_VectorConcatenate_tmp;

  /* Sum: '<S6>/Sum' incorporates:
   *  Inport: '<Root>/x_f'
   *  Inport: '<Root>/x_ref'
   */
  rtb_Sum_ce_idx_0 = rotor_combined_controller_U.x_ref[0] -
    rotor_combined_controller_U.x_f[0];

  /* DiscreteFir: '<Root>/Discrete FIR Filter' incorporates:
   *  MATLAB Function: '<Root>/MATLAB Function2'
   */
  rtb_VectorConcatenate_tmp = tmp_0[2] *
    rotor_combined_controller_P.DiscreteFIRFilter_Coefficients[0];
  cff = 1;
  for (j = rotor_combined_controller_DW.DiscreteFIRFilter_circBuf; j < 4; j++) {
    rtb_VectorConcatenate_tmp +=
      rotor_combined_controller_DW.DiscreteFIRFilter_states[4 + j] *
      rotor_combined_controller_P.DiscreteFIRFilter_Coefficients[cff];
    cff++;
  }

  for (j = 0; j < rotor_combined_controller_DW.DiscreteFIRFilter_circBuf; j++) {
    rtb_VectorConcatenate_tmp +=
      rotor_combined_controller_DW.DiscreteFIRFilter_states[4 + j] *
      rotor_combined_controller_P.DiscreteFIRFilter_Coefficients[cff];
    cff++;
  }

  rtb_DiscreteTimeIntegrator_g__0 = rtb_VectorConcatenate_tmp;

  /* Sum: '<S6>/Sum' incorporates:
   *  Inport: '<Root>/x_f'
   *  Inport: '<Root>/x_ref'
   */
  rtb_Sum_ce_idx_1 = rotor_combined_controller_U.x_ref[1] -
    rotor_combined_controller_U.x_f[1];

  /* DiscreteFir: '<Root>/Discrete FIR Filter' incorporates:
   *  MATLAB Function: '<Root>/MATLAB Function2'
   */
  rtb_VectorConcatenate_tmp = tmp_0[3] *
    rotor_combined_controller_P.DiscreteFIRFilter_Coefficients[0];
  cff = 1;
  for (j = rotor_combined_controller_DW.DiscreteFIRFilter_circBuf; j < 4; j++) {
    rtb_VectorConcatenate_tmp +=
      rotor_combined_controller_DW.DiscreteFIRFilter_states[8 + j] *
      rotor_combined_controller_P.DiscreteFIRFilter_Coefficients[cff];
    cff++;
  }

  for (j = 0; j < rotor_combined_controller_DW.DiscreteFIRFilter_circBuf; j++) {
    rtb_VectorConcatenate_tmp +=
      rotor_combined_controller_DW.DiscreteFIRFilter_states[8 + j] *
      rotor_combined_controller_P.DiscreteFIRFilter_Coefficients[cff];
    cff++;
  }

  /* Sum: '<S6>/Sum' incorporates:
   *  Inport: '<Root>/x_f'
   *  Inport: '<Root>/x_ref'
   */
  rtb_Sum_ce_idx_2 = rotor_combined_controller_U.x_ref[2] -
    rotor_combined_controller_U.x_f[2];

  /* Gain: '<S6>/Gain1' incorporates:
   *  Constant: '<Root>/Constant6'
   *  Constant: '<S6>/Constant'
   *  DiscreteIntegrator: '<S6>/Discrete-Time Integrator'
   *  Gain: '<S6>/Kv'
   *  Gain: '<S6>/Kx'
   *  Gain: '<S6>/Kxint'
   *  Inport: '<Root>/v_f'
   *  Sum: '<S6>/Sum1'
   *  Sum: '<S6>/Sum2'
   *  Sum: '<S6>/Sum5'
   */
  rtb_Product2_j = (((rotor_combined_controller_P.Kxint
                      * rotor_combined_controller_DW.DiscreteTimeIntegrator_DSTATE_i
                      [0] + rotor_combined_controller_P.Kx * rtb_Sum_ce_idx_0) +
                     (rotor_combined_controller_P.Constant6_Value[0] -
                      rotor_combined_controller_U.v_f[0]) *
                     rotor_combined_controller_P.Kv) +
                    rotor_combined_controller_P.Constant_Value[0]) *
    rotor_combined_controller_P.mass;

  /* Saturate: '<Root>/Saturation' */
  if (rtb_Product2_j > rotor_combined_controller_P.Saturation_UpperSat) {
    rtb_Saturation[0] = rotor_combined_controller_P.Saturation_UpperSat;
  } else if (rtb_Product2_j < rotor_combined_controller_P.Saturation_LowerSat) {
    rtb_Saturation[0] = rotor_combined_controller_P.Saturation_LowerSat;
  } else {
    rtb_Saturation[0] = rtb_Product2_j;
  }

  /* Gain: '<S6>/Gain1' incorporates:
   *  Constant: '<Root>/Constant6'
   *  Constant: '<S6>/Constant'
   *  DiscreteIntegrator: '<S6>/Discrete-Time Integrator'
   *  Gain: '<S6>/Kv'
   *  Gain: '<S6>/Kx'
   *  Gain: '<S6>/Kxint'
   *  Inport: '<Root>/v_f'
   *  Sum: '<S6>/Sum1'
   *  Sum: '<S6>/Sum2'
   *  Sum: '<S6>/Sum5'
   */
  rtb_Product2_j = (((rotor_combined_controller_P.Kxint
                      * rotor_combined_controller_DW.DiscreteTimeIntegrator_DSTATE_i
                      [1] + rotor_combined_controller_P.Kx * rtb_Sum_ce_idx_1) +
                     (rotor_combined_controller_P.Constant6_Value[1] -
                      rotor_combined_controller_U.v_f[1]) *
                     rotor_combined_controller_P.Kv) +
                    rotor_combined_controller_P.Constant_Value[1]) *
    rotor_combined_controller_P.mass;

  /* Saturate: '<Root>/Saturation' */
  if (rtb_Product2_j > rotor_combined_controller_P.Saturation_UpperSat) {
    rtb_Saturation[1] = rotor_combined_controller_P.Saturation_UpperSat;
  } else if (rtb_Product2_j < rotor_combined_controller_P.Saturation_LowerSat) {
    rtb_Saturation[1] = rotor_combined_controller_P.Saturation_LowerSat;
  } else {
    rtb_Saturation[1] = rtb_Product2_j;
  }

  /* Gain: '<S6>/Gain1' incorporates:
   *  Constant: '<Root>/Constant6'
   *  Constant: '<S6>/Constant'
   *  DiscreteIntegrator: '<S6>/Discrete-Time Integrator'
   *  Gain: '<S6>/Kv'
   *  Gain: '<S6>/Kx'
   *  Gain: '<S6>/Kxint'
   *  Inport: '<Root>/v_f'
   *  Sum: '<S6>/Sum1'
   *  Sum: '<S6>/Sum2'
   *  Sum: '<S6>/Sum5'
   */
  rtb_Product2_j = (((rotor_combined_controller_P.Kxint
                      * rotor_combined_controller_DW.DiscreteTimeIntegrator_DSTATE_i
                      [2] + rotor_combined_controller_P.Kx * rtb_Sum_ce_idx_2) +
                     (rotor_combined_controller_P.Constant6_Value[2] -
                      rotor_combined_controller_U.v_f[2]) *
                     rotor_combined_controller_P.Kv) +
                    rotor_combined_controller_P.Constant_Value[2]) *
    rotor_combined_controller_P.mass;

  /* Saturate: '<Root>/Saturation' */
  if (rtb_Product2_j > rotor_combined_controller_P.Saturation_UpperSat) {
    rtb_Saturation[2] = rotor_combined_controller_P.Saturation_UpperSat;
  } else if (rtb_Product2_j < rotor_combined_controller_P.Saturation_LowerSat) {
    rtb_Saturation[2] = rotor_combined_controller_P.Saturation_LowerSat;
  } else {
    rtb_Saturation[2] = rtb_Product2_j;
  }

  /* SignalConversion: '<S4>/TmpSignal ConversionAt SFunction Inport1' incorporates:
   *  Gain: '<Root>/Gain'
   *  Inport: '<Root>/euler_cmd'
   *  MATLAB Function: '<Root>/MATLAB Function1'
   *  Trigonometry: '<Root>/Atan'
   */
  tmp_1[0] = rotor_combined_controller_U.euler_cmd[0];
  tmp_1[1] = rotor_combined_controller_U.euler_cmd[1];
  tmp_1[2] = rotor_combined_controller_U.euler_cmd[2];
  tmp_1[3] = rotor_combined_controller_P.Gain_Gain_ps * atanf(rtb_Saturation[0]);
  tmp_1[4] = rotor_combined_controller_P.Gain_Gain_ps * atanf(rtb_Saturation[1]);
  tmp_1[5] = rotor_combined_controller_P.Gain_Gain_ps * atanf(rtb_Saturation[2]);

  /* MATLAB Function: '<Root>/MATLAB Function1' incorporates:
   *  SignalConversion: '<S4>/TmpSignal ConversionAt SFunction Inport1'
   */
  for (cff = 0; cff < 4; cff++) {
    rtb_Product2_j = 0.0F;
    for (j = 0; j < 6; j++) {
      rtb_Product2_j += (real32_T)c[(j << 2) + cff] * tmp_1[j];
    }

    rtb_y[cff] = rtb_Product2_j + b[cff];
  }

  /* Sum: '<S1>/Sum2' incorporates:
   *  Constant: '<Root>/Constant1'
   *  DiscreteFir: '<Root>/Discrete FIR Filter'
   *  DiscreteIntegrator: '<S1>/Discrete-Time Integrator'
   *  Gain: '<S1>/K_att'
   *  Gain: '<S1>/K_att_dot'
   *  Gain: '<S1>/K_att_int'
   *  Product: '<S1>/Multiply'
   *  Sum: '<S1>/Sum1'
   */
  rtb_DiscreteTimeIntegrator_g_id = (rotor_combined_controller_P.K_att_int_Gain *
    rotor_combined_controller_DW.DiscreteTimeIntegrator_DSTATE[0] +
    rotor_combined_controller_P.K_att * rtb_Product3_m) +
    (rotor_combined_controller_P.Constant1_Value[0] -
     rtb_DiscreteTimeIntegrator_g_id) * rotor_combined_controller_P.K_att_dot;
  rtb_DiscreteTimeIntegrator_g__0 = (rotor_combined_controller_P.K_att_int_Gain *
    rotor_combined_controller_DW.DiscreteTimeIntegrator_DSTATE[1] +
    rotor_combined_controller_P.K_att * rtb_Product_d) +
    (rotor_combined_controller_P.Constant1_Value[1] -
     rtb_DiscreteTimeIntegrator_g__0) * rotor_combined_controller_P.K_att_dot;
  rtb_VectorConcatenate_tmp = (rotor_combined_controller_P.K_att_int_Gain *
    rotor_combined_controller_DW.DiscreteTimeIntegrator_DSTATE[2] +
    rotor_combined_controller_P.K_att * rtb_Product1_bv) +
    (rotor_combined_controller_P.Constant1_Value[2] - rtb_VectorConcatenate_tmp)
    * rotor_combined_controller_P.K_att_dot;
  for (cff = 0; cff < 3; cff++) {
    /* SignalConversion: '<S3>/TmpSignal ConversionAt SFunction Inport1' incorporates:
     *  Constant: '<S1>/Constant'
     *  MATLAB Function: '<Root>/MATLAB Function'
     *  Product: '<S1>/Multiply'
     */
    rtb_TmpSignalConversionAtSFunct[cff] =
      rotor_combined_controller_P.frame_inertia[cff + 6] *
      rtb_VectorConcatenate_tmp + (rotor_combined_controller_P.frame_inertia[cff
      + 3] * rtb_DiscreteTimeIntegrator_g__0 +
      rotor_combined_controller_P.frame_inertia[cff] *
      rtb_DiscreteTimeIntegrator_g_id);
  }

  /* MATLAB Function: '<Root>/MATLAB Function' incorporates:
   *  Reshape: '<S17>/Reshape (9) to [3x3] column-major'
   *  SignalConversion: '<S3>/TmpSignal ConversionAt SFunction Inport1'
   */
  rtb_y_a[0] = rtb_TmpSignalConversionAtSFunct[0];
  rtb_y_a[1] = rtb_TmpSignalConversionAtSFunct[1];
  rtb_y_a[2] = rtb_TmpSignalConversionAtSFunct[2];
  rtb_y_a[3] = rtb_Saturation[2];
  rtb_Product2_j = sinf(rtb_y[0]);
  tmp_2[0] = -rtb_Product2_j;
  tmp_2[3] = 0.0F;
  rtb_DiscreteTimeIntegrator_g_id = sinf(rtb_y[2]);
  tmp_2[6] = rtb_DiscreteTimeIntegrator_g_id;
  tmp_2[9] = 0.0F;
  tmp_2[1] = 0.0F;
  rtb_VectorConcatenate_tmp = sinf(rtb_y[1]);
  tmp_2[4] = rtb_VectorConcatenate_tmp;
  tmp_2[7] = 0.0F;
  rtb_DiscreteTimeIntegrator_g__0 = sinf(rtb_y[3]);
  tmp_2[10] = -rtb_DiscreteTimeIntegrator_g__0;
  rtb_VectorConcatenate_tmp_0 = -cosf(rtb_y[0]);
  tmp_2[2] = rtb_VectorConcatenate_tmp_0;
  rtb_VectorConcatenate_tmp_1 = cosf(rtb_y[1]);
  tmp_2[5] = -rtb_VectorConcatenate_tmp_1;
  tmp_3 = cosf(rtb_y[2]);
  tmp_2[8] = -tmp_3;
  tmp_4 = -cosf(rtb_y[3]);
  tmp_2[11] = tmp_4;
  for (cff = 0; cff < 4; cff++) {
    for (j = 0; j < 3; j++) {
      rtb_VectorConcatenate_tmp_2 = j + 3 * cff;
      rtb_VectorConcatenate_0[rtb_VectorConcatenate_tmp_2] = 0.0F;
      rtb_VectorConcatenate_0[rtb_VectorConcatenate_tmp_2] =
        rtb_VectorConcatenate_0[3 * cff + j] + tmp_2[3 * cff] *
        rtb_VectorConcatenate[j];
      rtb_VectorConcatenate_0[rtb_VectorConcatenate_tmp_2] = tmp_2[3 * cff + 1] *
        rtb_VectorConcatenate[j + 3] + rtb_VectorConcatenate_0[3 * cff + j];
      rtb_VectorConcatenate_0[rtb_VectorConcatenate_tmp_2] = tmp_2[3 * cff + 2] *
        rtb_VectorConcatenate[j + 6] + rtb_VectorConcatenate_0[3 * cff + j];
    }
  }

  tmp[0] = (real32_T)rotor_combined_controller_P.length *
    rtb_VectorConcatenate_tmp_0;
  rtb_VectorConcatenate_tmp_0 = (real32_T)rotor_combined_controller_P.length *
    0.0F;
  tmp[4] = rtb_VectorConcatenate_tmp_0;
  tmp[8] = (real32_T)rotor_combined_controller_P.length * tmp_3;
  tmp[12] = rtb_VectorConcatenate_tmp_0;
  tmp[1] = rtb_VectorConcatenate_tmp_0;
  tmp[5] = (real32_T)rotor_combined_controller_P.length *
    rtb_VectorConcatenate_tmp_1;
  tmp[9] = rtb_VectorConcatenate_tmp_0;
  tmp[13] = (real32_T)rotor_combined_controller_P.length * tmp_4;
  tmp[2] = (real32_T)rotor_combined_controller_P.length * rtb_Product2_j;
  tmp[6] = (real32_T)rotor_combined_controller_P.length *
    rtb_VectorConcatenate_tmp;
  tmp[10] = (real32_T)rotor_combined_controller_P.length *
    rtb_DiscreteTimeIntegrator_g_id;
  tmp[14] = (real32_T)rotor_combined_controller_P.length *
    rtb_DiscreteTimeIntegrator_g__0;
  tmp[3] = rtb_VectorConcatenate_0[2];
  tmp[7] = rtb_VectorConcatenate_0[5];
  tmp[11] = rtb_VectorConcatenate_0[8];
  tmp[15] = rtb_VectorConcatenate_0[11];
  rotor_combined_control_mldivide(tmp, rtb_y_a);

  /* Outport: '<Root>/thrust_cmd' */
  rotor_combined_controller_Y.thrust_cmd[0] = rtb_y_a[0];
  rotor_combined_controller_Y.thrust_cmd[1] = rtb_y_a[1];
  rotor_combined_controller_Y.thrust_cmd[2] = rtb_y_a[2];
  rotor_combined_controller_Y.thrust_cmd[3] = rtb_y_a[3];

  /* Outport: '<Root>/theta_cmd' */
  rotor_combined_controller_Y.theta_cmd[0] = rtb_y[0];
  rotor_combined_controller_Y.theta_cmd[1] = rtb_y[1];
  rotor_combined_controller_Y.theta_cmd[2] = rtb_y[2];
  rotor_combined_controller_Y.theta_cmd[3] = rtb_y[3];

  /* Update for DiscreteIntegrator: '<S1>/Discrete-Time Integrator' */
  rotor_combined_controller_DW.DiscreteTimeIntegrator_DSTATE[0] +=
    rotor_combined_controller_P.DiscreteTimeIntegrator_gainval * rtb_Product3_m;
  if (rotor_combined_controller_DW.DiscreteTimeIntegrator_DSTATE[0] >=
      rotor_combined_controller_P.DiscreteTimeIntegrator_UpperSat) {
    rotor_combined_controller_DW.DiscreteTimeIntegrator_DSTATE[0] =
      rotor_combined_controller_P.DiscreteTimeIntegrator_UpperSat;
  } else {
    if (rotor_combined_controller_DW.DiscreteTimeIntegrator_DSTATE[0] <=
        rotor_combined_controller_P.DiscreteTimeIntegrator_LowerSat) {
      rotor_combined_controller_DW.DiscreteTimeIntegrator_DSTATE[0] =
        rotor_combined_controller_P.DiscreteTimeIntegrator_LowerSat;
    }
  }

  rotor_combined_controller_DW.DiscreteTimeIntegrator_DSTATE[1] +=
    rotor_combined_controller_P.DiscreteTimeIntegrator_gainval * rtb_Product_d;
  if (rotor_combined_controller_DW.DiscreteTimeIntegrator_DSTATE[1] >=
      rotor_combined_controller_P.DiscreteTimeIntegrator_UpperSat) {
    rotor_combined_controller_DW.DiscreteTimeIntegrator_DSTATE[1] =
      rotor_combined_controller_P.DiscreteTimeIntegrator_UpperSat;
  } else {
    if (rotor_combined_controller_DW.DiscreteTimeIntegrator_DSTATE[1] <=
        rotor_combined_controller_P.DiscreteTimeIntegrator_LowerSat) {
      rotor_combined_controller_DW.DiscreteTimeIntegrator_DSTATE[1] =
        rotor_combined_controller_P.DiscreteTimeIntegrator_LowerSat;
    }
  }

  rotor_combined_controller_DW.DiscreteTimeIntegrator_DSTATE[2] +=
    rotor_combined_controller_P.DiscreteTimeIntegrator_gainval * rtb_Product1_bv;
  if (rotor_combined_controller_DW.DiscreteTimeIntegrator_DSTATE[2] >=
      rotor_combined_controller_P.DiscreteTimeIntegrator_UpperSat) {
    rotor_combined_controller_DW.DiscreteTimeIntegrator_DSTATE[2] =
      rotor_combined_controller_P.DiscreteTimeIntegrator_UpperSat;
  } else {
    if (rotor_combined_controller_DW.DiscreteTimeIntegrator_DSTATE[2] <=
        rotor_combined_controller_P.DiscreteTimeIntegrator_LowerSat) {
      rotor_combined_controller_DW.DiscreteTimeIntegrator_DSTATE[2] =
        rotor_combined_controller_P.DiscreteTimeIntegrator_LowerSat;
    }
  }

  /* End of Update for DiscreteIntegrator: '<S1>/Discrete-Time Integrator' */

  /* Update for UnitDelay: '<S2>/UD' incorporates:
   *  Inport: '<Root>/q_f'
   *
   * Block description for '<S2>/UD':
   *
   *  Store in Global RAM
   */
  rotor_combined_controller_DW.UD_DSTATE[0] = rotor_combined_controller_U.q_f[0];
  rotor_combined_controller_DW.UD_DSTATE[1] = rotor_combined_controller_U.q_f[1];
  rotor_combined_controller_DW.UD_DSTATE[2] = rotor_combined_controller_U.q_f[2];
  rotor_combined_controller_DW.UD_DSTATE[3] = rotor_combined_controller_U.q_f[3];

  /* Update for DiscreteFir: '<Root>/Discrete FIR Filter' incorporates:
   *  MATLAB Function: '<Root>/MATLAB Function2'
   */
  /* Update circular buffer index */
  rotor_combined_controller_DW.DiscreteFIRFilter_circBuf--;
  if (rotor_combined_controller_DW.DiscreteFIRFilter_circBuf < 0) {
    rotor_combined_controller_DW.DiscreteFIRFilter_circBuf = 3;
  }

  /* Update circular buffer */
  rotor_combined_controller_DW.DiscreteFIRFilter_states[rotor_combined_controller_DW.DiscreteFIRFilter_circBuf]
    = tmp_0[1];

  /* Update for DiscreteIntegrator: '<S6>/Discrete-Time Integrator' */
  rotor_combined_controller_DW.DiscreteTimeIntegrator_DSTATE_i[0] +=
    rotor_combined_controller_P.DiscreteTimeIntegrator_gainva_o *
    rtb_Sum_ce_idx_0;
  if (rotor_combined_controller_DW.DiscreteTimeIntegrator_DSTATE_i[0] >=
      rotor_combined_controller_P.DiscreteTimeIntegrator_UpperS_j) {
    rotor_combined_controller_DW.DiscreteTimeIntegrator_DSTATE_i[0] =
      rotor_combined_controller_P.DiscreteTimeIntegrator_UpperS_j;
  } else {
    if (rotor_combined_controller_DW.DiscreteTimeIntegrator_DSTATE_i[0] <=
        rotor_combined_controller_P.DiscreteTimeIntegrator_LowerS_h) {
      rotor_combined_controller_DW.DiscreteTimeIntegrator_DSTATE_i[0] =
        rotor_combined_controller_P.DiscreteTimeIntegrator_LowerS_h;
    }
  }

  /* Update for DiscreteFir: '<Root>/Discrete FIR Filter' incorporates:
   *  MATLAB Function: '<Root>/MATLAB Function2'
   */
  rotor_combined_controller_DW.DiscreteFIRFilter_states[rotor_combined_controller_DW.DiscreteFIRFilter_circBuf
    + 4] = tmp_0[2];

  /* Update for DiscreteIntegrator: '<S6>/Discrete-Time Integrator' */
  rotor_combined_controller_DW.DiscreteTimeIntegrator_DSTATE_i[1] +=
    rotor_combined_controller_P.DiscreteTimeIntegrator_gainva_o *
    rtb_Sum_ce_idx_1;
  if (rotor_combined_controller_DW.DiscreteTimeIntegrator_DSTATE_i[1] >=
      rotor_combined_controller_P.DiscreteTimeIntegrator_UpperS_j) {
    rotor_combined_controller_DW.DiscreteTimeIntegrator_DSTATE_i[1] =
      rotor_combined_controller_P.DiscreteTimeIntegrator_UpperS_j;
  } else {
    if (rotor_combined_controller_DW.DiscreteTimeIntegrator_DSTATE_i[1] <=
        rotor_combined_controller_P.DiscreteTimeIntegrator_LowerS_h) {
      rotor_combined_controller_DW.DiscreteTimeIntegrator_DSTATE_i[1] =
        rotor_combined_controller_P.DiscreteTimeIntegrator_LowerS_h;
    }
  }

  /* Update for DiscreteFir: '<Root>/Discrete FIR Filter' incorporates:
   *  MATLAB Function: '<Root>/MATLAB Function2'
   */
  rotor_combined_controller_DW.DiscreteFIRFilter_states[rotor_combined_controller_DW.DiscreteFIRFilter_circBuf
    + 8] = tmp_0[3];

  /* Update for DiscreteIntegrator: '<S6>/Discrete-Time Integrator' */
  rotor_combined_controller_DW.DiscreteTimeIntegrator_DSTATE_i[2] +=
    rotor_combined_controller_P.DiscreteTimeIntegrator_gainva_o *
    rtb_Sum_ce_idx_2;
  if (rotor_combined_controller_DW.DiscreteTimeIntegrator_DSTATE_i[2] >=
      rotor_combined_controller_P.DiscreteTimeIntegrator_UpperS_j) {
    rotor_combined_controller_DW.DiscreteTimeIntegrator_DSTATE_i[2] =
      rotor_combined_controller_P.DiscreteTimeIntegrator_UpperS_j;
  } else {
    if (rotor_combined_controller_DW.DiscreteTimeIntegrator_DSTATE_i[2] <=
        rotor_combined_controller_P.DiscreteTimeIntegrator_LowerS_h) {
      rotor_combined_controller_DW.DiscreteTimeIntegrator_DSTATE_i[2] =
        rotor_combined_controller_P.DiscreteTimeIntegrator_LowerS_h;
    }
  }
}

/* Model initialize function */
void rotor_combined_controller_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(rotor_combined_controller_M, (NULL));

  /* states (dwork) */
  (void) memset((void *)&rotor_combined_controller_DW, 0,
                sizeof(DW_rotor_combined_controller_T));

  /* external inputs */
  (void)memset((void *)&rotor_combined_controller_U, 0, sizeof
               (ExtU_rotor_combined_controlle_T));

  /* external outputs */
  (void) memset((void *)&rotor_combined_controller_Y, 0,
                sizeof(ExtY_rotor_combined_controlle_T));

  {
    int32_T i;

    /* InitializeConditions for DiscreteIntegrator: '<S1>/Discrete-Time Integrator' */
    rotor_combined_controller_DW.DiscreteTimeIntegrator_DSTATE[0] =
      rotor_combined_controller_P.DiscreteTimeIntegrator_IC;
    rotor_combined_controller_DW.DiscreteTimeIntegrator_DSTATE[1] =
      rotor_combined_controller_P.DiscreteTimeIntegrator_IC;
    rotor_combined_controller_DW.DiscreteTimeIntegrator_DSTATE[2] =
      rotor_combined_controller_P.DiscreteTimeIntegrator_IC;

    /* InitializeConditions for UnitDelay: '<S2>/UD'
     *
     * Block description for '<S2>/UD':
     *
     *  Store in Global RAM
     */
    rotor_combined_controller_DW.UD_DSTATE[0] =
      rotor_combined_controller_P.Difference1_ICPrevInput;
    rotor_combined_controller_DW.UD_DSTATE[1] =
      rotor_combined_controller_P.Difference1_ICPrevInput;
    rotor_combined_controller_DW.UD_DSTATE[2] =
      rotor_combined_controller_P.Difference1_ICPrevInput;
    rotor_combined_controller_DW.UD_DSTATE[3] =
      rotor_combined_controller_P.Difference1_ICPrevInput;

    /* InitializeConditions for DiscreteFir: '<Root>/Discrete FIR Filter' */
    rotor_combined_controller_DW.DiscreteFIRFilter_circBuf = 0;
    for (i = 0; i < 12; i++) {
      rotor_combined_controller_DW.DiscreteFIRFilter_states[i] =
        rotor_combined_controller_P.DiscreteFIRFilter_InitialStates;
    }

    /* End of InitializeConditions for DiscreteFir: '<Root>/Discrete FIR Filter' */

    /* InitializeConditions for DiscreteIntegrator: '<S6>/Discrete-Time Integrator' */
    rotor_combined_controller_DW.DiscreteTimeIntegrator_DSTATE_i[0] =
      rotor_combined_controller_P.DiscreteTimeIntegrator_IC_k;
    rotor_combined_controller_DW.DiscreteTimeIntegrator_DSTATE_i[1] =
      rotor_combined_controller_P.DiscreteTimeIntegrator_IC_k;
    rotor_combined_controller_DW.DiscreteTimeIntegrator_DSTATE_i[2] =
      rotor_combined_controller_P.DiscreteTimeIntegrator_IC_k;
  }
}

/* Model terminate function */
void rotor_combined_controller_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

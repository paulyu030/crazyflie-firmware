/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Quaternion_controller.c
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

#include "Quaternion_controller.h"
#include "Quaternion_controller_private.h"

/* Block signals (default storage) */
B_Quaternion_controller_T Quaternion_controller_B;

/* Block states (default storage) */
DW_Quaternion_controller_T Quaternion_controller_DW;

/* Previous zero-crossings (trigger) states */
PrevZCX_Quaternion_controller_T Quaternion_controller_PrevZCX;

/* External inputs (root inport signals with default storage) */
ExtU_Quaternion_controller_T Quaternion_controller_U;

/* External outputs (root outports fed by signals with default storage) */
ExtY_Quaternion_controller_T Quaternion_controller_Y;

/* Real-time model */
RT_MODEL_Quaternion_controlle_T Quaternion_controller_M_;
RT_MODEL_Quaternion_controlle_T *const Quaternion_controller_M =
  &Quaternion_controller_M_;

/* Forward declaration for local functions */
static real32_T Quaternion_controller_norm(const real32_T x[3]);

/* Function for MATLAB Function: '<S6>/MATLAB Function2' */
static real32_T Quaternion_controller_norm(const real32_T x[3])
{
  real32_T y;
  real32_T scale;
  real32_T absxk;
  real32_T t;
  scale = 1.29246971E-26F;
  absxk = fabsf(x[0]);
  if (absxk > 1.29246971E-26F) {
    y = 1.0F;
    scale = absxk;
  } else {
    t = absxk / 1.29246971E-26F;
    y = t * t;
  }

  absxk = fabsf(x[1]);
  if (absxk > scale) {
    t = scale / absxk;
    y = y * t * t + 1.0F;
    scale = absxk;
  } else {
    t = absxk / scale;
    y += t * t;
  }

  absxk = fabsf(x[2]);
  if (absxk > scale) {
    t = scale / absxk;
    y = y * t * t + 1.0F;
    scale = absxk;
  } else {
    t = absxk / scale;
    y += t * t;
  }

  return scale * sqrtf(y);
}

/* Model step function */
void Quaternion_controller_step(void)
{
  int32_T j;
  int32_T cff;
  real32_T numAccum;
  real32_T scale;
  real32_T absxk;
  real32_T t;
  real32_T rtb_MatrixConcatenate[9];
  real32_T rtb_Multiply1[4];
  real32_T rtb_Sum3[3];
  real32_T rtb_y;
  boolean_T rtb_RelationalOperator;
  real32_T rtb_sqrt;
  real32_T rtb_Reshape[3];
  real32_T rtb_Gain2[3];
  real32_T rtb_Transpose[9];
  boolean_T rtb_Reshape_d[9];
  real32_T e_y[3];
  real32_T tmp[9];
  real32_T tmp_0[16];
  real32_T tmp_1[4];
  real_T rtb_omega_cmd;
  real32_T e_y_idx_0;
  real32_T e_y_idx_1;
  real32_T rtb_DiscreteFIRFilter1_idx_0;
  real32_T rtb_DiscreteFIRFilter1_idx_1;
  real32_T rtb_DiscreteFIRFilter1_idx_2;
  real32_T rtb_DiscreteTransferFcn1_idx_2;
  real32_T DiscreteTransferFcn1_tmp_idx_2;

  /* Reshape: '<S6>/Reshape' incorporates:
   *  Constant: '<Root>/Constant5'
   *  Inport: '<Root>/ax'
   *  Inport: '<Root>/ay'
   *  Inport: '<Root>/az'
   *  Sum: '<Root>/Sum'
   */
  rtb_Reshape[0] = Quaternion_controller_U.ax;
  rtb_Reshape[1] = Quaternion_controller_U.ay;
  rtb_Reshape[2] = Quaternion_controller_U.az +
    Quaternion_controller_P.Constant5_Value;

  /* MATLAB Function: '<S6>/alpha' */
  scale = 1.29246971E-26F;

  /* Gain: '<S6>/Gain2' incorporates:
   *  Inport: '<Root>/ax'
   */
  rtb_DiscreteFIRFilter1_idx_0 = Quaternion_controller_P.Gain2_Gain_i *
    Quaternion_controller_U.ax;

  /* MATLAB Function: '<S6>/alpha' */
  absxk = fabsf(rtb_DiscreteFIRFilter1_idx_0);
  if (absxk > 1.29246971E-26F) {
    rtb_DiscreteFIRFilter1_idx_1 = 1.0F;
    scale = absxk;
  } else {
    t = absxk / 1.29246971E-26F;
    rtb_DiscreteFIRFilter1_idx_1 = t * t;
  }

  /* Gain: '<S6>/Gain2' incorporates:
   *  Inport: '<Root>/ay'
   */
  rtb_Gain2[0] = rtb_DiscreteFIRFilter1_idx_0;
  rtb_DiscreteFIRFilter1_idx_0 = Quaternion_controller_P.Gain2_Gain_i *
    Quaternion_controller_U.ay;

  /* MATLAB Function: '<S6>/alpha' */
  absxk = fabsf(rtb_DiscreteFIRFilter1_idx_0);
  if (absxk > scale) {
    t = scale / absxk;
    rtb_DiscreteFIRFilter1_idx_1 = rtb_DiscreteFIRFilter1_idx_1 * t * t + 1.0F;
    scale = absxk;
  } else {
    t = absxk / scale;
    rtb_DiscreteFIRFilter1_idx_1 += t * t;
  }

  /* Gain: '<S6>/Gain2' */
  rtb_Gain2[1] = rtb_DiscreteFIRFilter1_idx_0;
  rtb_DiscreteFIRFilter1_idx_0 = Quaternion_controller_P.Gain2_Gain_i *
    rtb_Reshape[2];

  /* MATLAB Function: '<S6>/alpha' */
  absxk = fabsf(rtb_DiscreteFIRFilter1_idx_0);
  if (absxk > scale) {
    t = scale / absxk;
    rtb_DiscreteFIRFilter1_idx_1 = rtb_DiscreteFIRFilter1_idx_1 * t * t + 1.0F;
    scale = absxk;
  } else {
    t = absxk / scale;
    rtb_DiscreteFIRFilter1_idx_1 += t * t;
  }

  rtb_DiscreteFIRFilter1_idx_1 = scale * sqrtf(rtb_DiscreteFIRFilter1_idx_1);

  /* MATLAB Function: '<S6>/MATLAB Function2' incorporates:
   *  Inport: '<Root>/yaw_setpoint'
   */
  e_y_idx_0 = -sinf(Quaternion_controller_U.yaw_setpoint);
  e_y_idx_1 = cosf(Quaternion_controller_U.yaw_setpoint);

  /* MATLAB Function: '<S6>/alpha' */
  rtb_sqrt = rtb_Gain2[0] / rtb_DiscreteFIRFilter1_idx_1;

  /* SignalConversion: '<S6>/ConcatBufferAtMatrix ConcatenateIn3' */
  rtb_MatrixConcatenate[6] = rtb_sqrt;

  /* MATLAB Function: '<S6>/alpha' */
  rtb_Gain2[0] = rtb_sqrt;
  rtb_sqrt = rtb_Gain2[1] / rtb_DiscreteFIRFilter1_idx_1;

  /* SignalConversion: '<S6>/ConcatBufferAtMatrix ConcatenateIn3' */
  rtb_MatrixConcatenate[7] = rtb_sqrt;

  /* MATLAB Function: '<S6>/alpha' */
  rtb_Gain2[1] = rtb_sqrt;
  rtb_sqrt = rtb_DiscreteFIRFilter1_idx_0 / rtb_DiscreteFIRFilter1_idx_1;

  /* SignalConversion: '<S6>/ConcatBufferAtMatrix ConcatenateIn3' */
  rtb_MatrixConcatenate[8] = rtb_sqrt;

  /* MATLAB Function: '<S6>/MATLAB Function2' */
  scale = e_y_idx_1 * rtb_sqrt - 0.0F * rtb_Gain2[1];
  e_y[0] = scale;
  absxk = 0.0F * rtb_Gain2[0] - e_y_idx_0 * rtb_sqrt;
  e_y[1] = absxk;
  e_y_idx_0 = e_y_idx_0 * rtb_Gain2[1] - e_y_idx_1 * rtb_Gain2[0];
  e_y[2] = e_y_idx_0;
  e_y_idx_1 = Quaternion_controller_norm(e_y);
  rtb_MatrixConcatenate[0] = scale / e_y_idx_1;
  rtb_MatrixConcatenate[1] = absxk / e_y_idx_1;
  rtb_MatrixConcatenate[2] = e_y_idx_0 / e_y_idx_1;
  e_y_idx_0 = rtb_Gain2[1] * rtb_MatrixConcatenate[2] - rtb_sqrt *
    rtb_MatrixConcatenate[1];
  e_y[0] = e_y_idx_0;
  e_y[1] = rtb_sqrt * rtb_MatrixConcatenate[0] - rtb_Gain2[0] *
    rtb_MatrixConcatenate[2];
  e_y[2] = rtb_Gain2[0] * rtb_MatrixConcatenate[1] - rtb_Gain2[1] *
    rtb_MatrixConcatenate[0];
  e_y_idx_1 = Quaternion_controller_norm(e_y);
  rtb_MatrixConcatenate[3] = e_y_idx_0 / e_y_idx_1;
  rtb_MatrixConcatenate[4] = (rtb_sqrt * rtb_MatrixConcatenate[0] - rtb_Gain2[0]
    * rtb_MatrixConcatenate[2]) / e_y_idx_1;
  rtb_MatrixConcatenate[5] = (rtb_Gain2[0] * rtb_MatrixConcatenate[1] -
    rtb_Gain2[1] * rtb_MatrixConcatenate[0]) / e_y_idx_1;

  /* Math: '<S6>/Transpose' */
  for (cff = 0; cff < 3; cff++) {
    rtb_Transpose[3 * cff] = rtb_MatrixConcatenate[cff];
    rtb_Transpose[1 + 3 * cff] = rtb_MatrixConcatenate[cff + 3];
    rtb_Transpose[2 + 3 * cff] = rtb_MatrixConcatenate[cff + 6];
  }

  /* End of Math: '<S6>/Transpose' */

  /* If: '<S19>/If1' incorporates:
   *  Constant: '<S19>/Constant'
   */
  if (Quaternion_controller_P.DirectionCosineMatrixtoQuaterni != 1.0) {
    /* Outputs for IfAction SubSystem: '<S19>/If Warning//Error' incorporates:
     *  ActionPort: '<S43>/if'
     */
    /* Bias: '<S46>/Bias1' incorporates:
     *  Math: '<S46>/Math Function'
     *  Product: '<S46>/Product'
     */
    for (cff = 0; cff < 3; cff++) {
      for (j = 0; j < 3; j++) {
        rtb_MatrixConcatenate[cff + 3 * j] = ((rtb_Transpose[3 * cff + 1] *
          rtb_Transpose[3 * j + 1] + rtb_Transpose[3 * cff] * rtb_Transpose[3 *
          j]) + rtb_Transpose[3 * cff + 2] * rtb_Transpose[3 * j + 2]) +
          Quaternion_controller_P.Bias1_Bias[3 * j + cff];
      }
    }

    /* Abs: '<S46>/Abs2' incorporates:
     *  Bias: '<S46>/Bias1'
     *  RelationalOperator: '<S52>/Compare'
     */
    for (cff = 0; cff < 9; cff++) {
      tmp[cff] = fabsf(rtb_MatrixConcatenate[cff]);
    }

    /* End of Abs: '<S46>/Abs2' */

    /* RelationalOperator: '<S52>/Compare' incorporates:
     *  Constant: '<S52>/Constant'
     */
    for (cff = 0; cff < 3; cff++) {
      rtb_Reshape_d[3 * cff] = (tmp[3 * cff] >
        Quaternion_controller_P.DirectionCosineMatrixtoQuater_j);
      rtb_Reshape_d[1 + 3 * cff] = (tmp[3 * cff + 1] >
        Quaternion_controller_P.DirectionCosineMatrixtoQuater_j);
      rtb_Reshape_d[2 + 3 * cff] = (tmp[3 * cff + 2] >
        Quaternion_controller_P.DirectionCosineMatrixtoQuater_j);
    }

    /* Logic: '<S46>/Logical Operator1' */
    rtb_RelationalOperator = rtb_Reshape_d[0];
    for (cff = 0; cff < 8; cff++) {
      rtb_RelationalOperator = (rtb_RelationalOperator || rtb_Reshape_d[cff + 1]);
    }

    /* If: '<S43>/If' incorporates:
     *  Abs: '<S47>/Abs1'
     *  Bias: '<S47>/Bias'
     *  Constant: '<S54>/Constant'
     *  Logic: '<S46>/Logical Operator1'
     *  Product: '<S53>/Product'
     *  Product: '<S53>/Product1'
     *  Product: '<S53>/Product2'
     *  Product: '<S53>/Product3'
     *  Product: '<S53>/Product4'
     *  Product: '<S53>/Product5'
     *  RelationalOperator: '<S54>/Compare'
     *  Reshape: '<S53>/Reshape'
     *  Sum: '<S53>/Sum'
     */
    if (fabsf((((((rtb_Transpose[0] * rtb_Transpose[4] * rtb_Transpose[8] -
                   rtb_Transpose[0] * rtb_Transpose[5] * rtb_Transpose[7]) -
                  rtb_Transpose[1] * rtb_Transpose[3] * rtb_Transpose[8]) +
                 rtb_Transpose[2] * rtb_Transpose[3] * rtb_Transpose[7]) +
                rtb_Transpose[1] * rtb_Transpose[5] * rtb_Transpose[6]) -
               rtb_Transpose[2] * rtb_Transpose[4] * rtb_Transpose[6]) +
              Quaternion_controller_P.Bias_Bias) >
        Quaternion_controller_P.DirectionCosineMatrixtoQuater_j) {
      /* Outputs for IfAction SubSystem: '<S43>/If Not Proper' incorporates:
       *  ActionPort: '<S45>/Action Port'
       */
      /* If: '<S45>/If' incorporates:
       *  Constant: '<S45>/Constant'
       */
      if (Quaternion_controller_P.DirectionCosineMatrixtoQuaterni == 2.0) {
        /* Outputs for IfAction SubSystem: '<S45>/Warning' incorporates:
         *  ActionPort: '<S51>/Action Port'
         */
        /* Assertion: '<S51>/Assertion' incorporates:
         *  Constant: '<S45>/Constant1'
         */
        utAssert(Quaternion_controller_P.Constant1_Value != 0.0);

        /* End of Outputs for SubSystem: '<S45>/Warning' */
      } else {
        if (Quaternion_controller_P.DirectionCosineMatrixtoQuaterni == 3.0) {
          /* Outputs for IfAction SubSystem: '<S45>/Error' incorporates:
           *  ActionPort: '<S50>/Action Port'
           */
          /* Assertion: '<S50>/Assertion' incorporates:
           *  Constant: '<S45>/Constant1'
           */
          utAssert(Quaternion_controller_P.Constant1_Value != 0.0);

          /* End of Outputs for SubSystem: '<S45>/Error' */
        }
      }

      /* End of If: '<S45>/If' */
      /* End of Outputs for SubSystem: '<S43>/If Not Proper' */
    } else {
      if (rtb_RelationalOperator) {
        /* Outputs for IfAction SubSystem: '<S43>/Else If Not Orthogonal' incorporates:
         *  ActionPort: '<S44>/Action Port'
         */
        /* If: '<S44>/If' incorporates:
         *  Constant: '<S44>/Constant'
         */
        if (Quaternion_controller_P.DirectionCosineMatrixtoQuaterni == 2.0) {
          /* Outputs for IfAction SubSystem: '<S44>/Warning' incorporates:
           *  ActionPort: '<S49>/Action Port'
           */
          /* Assertion: '<S49>/Assertion' incorporates:
           *  Constant: '<S44>/Constant1'
           */
          utAssert(Quaternion_controller_P.Constant1_Value_f != 0.0);

          /* End of Outputs for SubSystem: '<S44>/Warning' */
        } else {
          if (Quaternion_controller_P.DirectionCosineMatrixtoQuaterni == 3.0) {
            /* Outputs for IfAction SubSystem: '<S44>/Error' incorporates:
             *  ActionPort: '<S48>/Action Port'
             */
            /* Assertion: '<S48>/Assertion' incorporates:
             *  Constant: '<S44>/Constant1'
             */
            utAssert(Quaternion_controller_P.Constant1_Value_f != 0.0);

            /* End of Outputs for SubSystem: '<S44>/Error' */
          }
        }

        /* End of If: '<S44>/If' */
        /* End of Outputs for SubSystem: '<S43>/Else If Not Orthogonal' */
      }
    }

    /* End of If: '<S43>/If' */
    /* End of Outputs for SubSystem: '<S19>/If Warning//Error' */
  }

  /* End of If: '<S19>/If1' */

  /* Sum: '<S20>/Add' incorporates:
   *  Reshape: '<S13>/Reshape 3x3 -> 9'
   */
  scale = (rtb_Transpose[0] + rtb_Transpose[4]) + rtb_Transpose[8];

  /* If: '<S13>/If' incorporates:
   *  If: '<S17>/Find Maximum Diagonal Value'
   *  Reshape: '<S13>/Reshape 3x3 -> 9'
   *  Sum: '<S20>/Add'
   */
  if (scale > 0.0F) {
    /* Outputs for IfAction SubSystem: '<S13>/Positive Trace' incorporates:
     *  ActionPort: '<S18>/Action Port'
     */
    /* Sqrt: '<S18>/sqrt' incorporates:
     *  Constant: '<S18>/Constant'
     *  Sum: '<S18>/Sum'
     */
    e_y_idx_0 = sqrtf(scale + Quaternion_controller_P.Constant_Value);

    /* Gain: '<S18>/Gain' */
    Quaternion_controller_B.Merge[0] = Quaternion_controller_P.Gain_Gain *
      e_y_idx_0;

    /* Gain: '<S18>/Gain1' */
    e_y_idx_0 *= Quaternion_controller_P.Gain1_Gain;

    /* Product: '<S18>/Product' incorporates:
     *  Reshape: '<S13>/Reshape 3x3 -> 9'
     *  Sum: '<S40>/Add'
     *  Sum: '<S41>/Add'
     *  Sum: '<S42>/Add'
     */
    Quaternion_controller_B.Merge[1] = (rtb_Transpose[7] - rtb_Transpose[5]) /
      e_y_idx_0;
    Quaternion_controller_B.Merge[2] = (rtb_Transpose[2] - rtb_Transpose[6]) /
      e_y_idx_0;
    Quaternion_controller_B.Merge[3] = (rtb_Transpose[3] - rtb_Transpose[1]) /
      e_y_idx_0;

    /* End of Outputs for SubSystem: '<S13>/Positive Trace' */
  } else {
    /* Outputs for IfAction SubSystem: '<S13>/Negative Trace' incorporates:
     *  ActionPort: '<S17>/Action Port'
     */
    if ((rtb_Transpose[4] > rtb_Transpose[0]) && (rtb_Transpose[4] >
         rtb_Transpose[8])) {
      /* Outputs for IfAction SubSystem: '<S17>/Maximum Value at DCM(2,2)' incorporates:
       *  ActionPort: '<S22>/Action Port'
       */
      /* If: '<S17>/Find Maximum Diagonal Value' incorporates:
       *  Constant: '<S33>/Constant1'
       *  Constant: '<S33>/Constant2'
       *  Constant: '<S34>/Constant'
       *  Gain: '<S22>/Gain'
       *  Gain: '<S22>/Gain1'
       *  Gain: '<S22>/Gain3'
       *  Gain: '<S22>/Gain4'
       *  Product: '<S22>/Product'
       *  Product: '<S33>/Product'
       *  Reshape: '<S13>/Reshape 3x3 -> 9'
       *  Sqrt: '<S22>/sqrt'
       *  Sum: '<S30>/Add'
       *  Sum: '<S31>/Add'
       *  Sum: '<S32>/Add'
       *  Sum: '<S34>/Add'
       *  Switch: '<S33>/Switch'
       */
      rtb_sqrt = sqrtf(((rtb_Transpose[4] - rtb_Transpose[0]) - rtb_Transpose[8])
                       + Quaternion_controller_P.Constant_Value_d);
      if (rtb_sqrt != 0.0F) {
        e_y_idx_0 = Quaternion_controller_P.Constant1_Value_e;
        e_y_idx_1 = rtb_sqrt;
      } else {
        e_y_idx_0 = Quaternion_controller_P.Constant2_Value[0];
        e_y_idx_1 = Quaternion_controller_P.Constant2_Value[1];
      }

      e_y_idx_0 /= e_y_idx_1;
      Quaternion_controller_B.Merge[1] = Quaternion_controller_P.Gain1_Gain_i *
        ((rtb_Transpose[1] + rtb_Transpose[3]) * e_y_idx_0);
      Quaternion_controller_B.Merge[3] = Quaternion_controller_P.Gain3_Gain *
        ((rtb_Transpose[5] + rtb_Transpose[7]) * e_y_idx_0);
      Quaternion_controller_B.Merge[0] = Quaternion_controller_P.Gain4_Gain *
        ((rtb_Transpose[2] - rtb_Transpose[6]) * e_y_idx_0);
      Quaternion_controller_B.Merge[2] = Quaternion_controller_P.Gain_Gain_m *
        rtb_sqrt;

      /* End of Outputs for SubSystem: '<S17>/Maximum Value at DCM(2,2)' */
    } else if (rtb_Transpose[8] > rtb_Transpose[0]) {
      /* Outputs for IfAction SubSystem: '<S17>/Maximum Value at DCM(3,3)' incorporates:
       *  ActionPort: '<S23>/Action Port'
       */
      /* If: '<S17>/Find Maximum Diagonal Value' incorporates:
       *  Constant: '<S38>/Constant1'
       *  Constant: '<S38>/Constant2'
       *  Constant: '<S39>/Constant'
       *  Gain: '<S23>/Gain'
       *  Gain: '<S23>/Gain1'
       *  Gain: '<S23>/Gain2'
       *  Gain: '<S23>/Gain3'
       *  Product: '<S23>/Product'
       *  Product: '<S38>/Product'
       *  Reshape: '<S13>/Reshape 3x3 -> 9'
       *  Sqrt: '<S23>/sqrt'
       *  Sum: '<S35>/Add'
       *  Sum: '<S36>/Add'
       *  Sum: '<S37>/Add'
       *  Sum: '<S39>/Add'
       *  Switch: '<S38>/Switch'
       */
      rtb_sqrt = sqrtf(((rtb_Transpose[8] - rtb_Transpose[0]) - rtb_Transpose[4])
                       + Quaternion_controller_P.Constant_Value_e);
      if (rtb_sqrt != 0.0F) {
        e_y_idx_0 = Quaternion_controller_P.Constant1_Value_b;
        e_y_idx_1 = rtb_sqrt;
      } else {
        e_y_idx_0 = Quaternion_controller_P.Constant2_Value_i[0];
        e_y_idx_1 = Quaternion_controller_P.Constant2_Value_i[1];
      }

      e_y_idx_0 /= e_y_idx_1;
      Quaternion_controller_B.Merge[1] = Quaternion_controller_P.Gain1_Gain_b *
        ((rtb_Transpose[2] + rtb_Transpose[6]) * e_y_idx_0);
      Quaternion_controller_B.Merge[2] = Quaternion_controller_P.Gain2_Gain *
        ((rtb_Transpose[5] + rtb_Transpose[7]) * e_y_idx_0);
      Quaternion_controller_B.Merge[0] = Quaternion_controller_P.Gain3_Gain_n *
        ((rtb_Transpose[3] - rtb_Transpose[1]) * e_y_idx_0);
      Quaternion_controller_B.Merge[3] = Quaternion_controller_P.Gain_Gain_f *
        rtb_sqrt;

      /* End of Outputs for SubSystem: '<S17>/Maximum Value at DCM(3,3)' */
    } else {
      /* Outputs for IfAction SubSystem: '<S17>/Maximum Value at DCM(1,1)' incorporates:
       *  ActionPort: '<S21>/Action Port'
       */
      /* If: '<S17>/Find Maximum Diagonal Value' incorporates:
       *  Constant: '<S28>/Constant1'
       *  Constant: '<S28>/Constant2'
       *  Constant: '<S29>/Constant'
       *  Gain: '<S21>/Gain'
       *  Gain: '<S21>/Gain1'
       *  Gain: '<S21>/Gain2'
       *  Gain: '<S21>/Gain3'
       *  Product: '<S21>/Product'
       *  Product: '<S28>/Product'
       *  Reshape: '<S13>/Reshape 3x3 -> 9'
       *  Sqrt: '<S21>/sqrt'
       *  Sum: '<S25>/Add'
       *  Sum: '<S26>/Add'
       *  Sum: '<S27>/Add'
       *  Sum: '<S29>/Add'
       *  Switch: '<S28>/Switch'
       */
      rtb_sqrt = sqrtf(((rtb_Transpose[0] - rtb_Transpose[4]) - rtb_Transpose[8])
                       + Quaternion_controller_P.Constant_Value_a);
      if (rtb_sqrt != 0.0F) {
        e_y_idx_0 = Quaternion_controller_P.Constant1_Value_l;
        e_y_idx_1 = rtb_sqrt;
      } else {
        e_y_idx_0 = Quaternion_controller_P.Constant2_Value_m[0];
        e_y_idx_1 = Quaternion_controller_P.Constant2_Value_m[1];
      }

      e_y_idx_0 /= e_y_idx_1;
      Quaternion_controller_B.Merge[2] = Quaternion_controller_P.Gain1_Gain_c *
        ((rtb_Transpose[1] + rtb_Transpose[3]) * e_y_idx_0);
      Quaternion_controller_B.Merge[3] = Quaternion_controller_P.Gain2_Gain_p *
        ((rtb_Transpose[2] + rtb_Transpose[6]) * e_y_idx_0);
      Quaternion_controller_B.Merge[0] = Quaternion_controller_P.Gain3_Gain_o *
        ((rtb_Transpose[7] - rtb_Transpose[5]) * e_y_idx_0);
      Quaternion_controller_B.Merge[1] = Quaternion_controller_P.Gain_Gain_d *
        rtb_sqrt;

      /* End of Outputs for SubSystem: '<S17>/Maximum Value at DCM(1,1)' */
    }

    /* End of Outputs for SubSystem: '<S13>/Negative Trace' */
  }

  /* End of If: '<S13>/If' */

  /* SignalConversion: '<S11>/TmpSignal ConversionAt SFunction Inport2' incorporates:
   *  Inport: '<Root>/qw'
   *  Inport: '<Root>/qx'
   *  Inport: '<Root>/qy'
   *  Inport: '<Root>/qz'
   *  MATLAB Function: '<S1>/quaternion_error'
   */
  rtb_Multiply1[0] = Quaternion_controller_U.qw;
  rtb_Multiply1[1] = Quaternion_controller_U.qx;
  rtb_Multiply1[2] = Quaternion_controller_U.qy;
  rtb_Multiply1[3] = Quaternion_controller_U.qz;

  /* MATLAB Function: '<S1>/quaternion_error' incorporates:
   *  Inport: '<Root>/qw'
   *  Inport: '<Root>/qx'
   *  Inport: '<Root>/qy'
   *  Inport: '<Root>/qz'
   */
  tmp[0] = 0.0F;
  tmp[3] = -Quaternion_controller_B.Merge[3];
  tmp[6] = Quaternion_controller_B.Merge[2];
  tmp[1] = Quaternion_controller_B.Merge[3];
  tmp[4] = 0.0F;
  tmp[7] = -Quaternion_controller_B.Merge[1];
  tmp[2] = -Quaternion_controller_B.Merge[2];
  tmp[5] = Quaternion_controller_B.Merge[1];
  tmp[8] = 0.0F;
  for (cff = 0; cff < 3; cff++) {
    rtb_Gain2[cff] = -((rtb_Multiply1[1 + cff] * Quaternion_controller_B.Merge[0]
                        - Quaternion_controller_B.Merge[1 + cff] *
                        Quaternion_controller_U.qw) - ((tmp[cff + 3] *
      Quaternion_controller_U.qy + tmp[cff] * Quaternion_controller_U.qx) +
      tmp[cff + 6] * Quaternion_controller_U.qz));
  }

  /* MATLAB Function: '<Root>/MATLAB Function' incorporates:
   *  Inport: '<Root>/qw'
   *  Inport: '<Root>/qx'
   *  Inport: '<Root>/qy'
   *  Inport: '<Root>/qz'
   */
  tmp_0[0] = 1000.0F * Quaternion_controller_U.qw;
  tmp_0[4] = 1000.0F * Quaternion_controller_U.qx;
  tmp_0[8] = 1000.0F * Quaternion_controller_U.qy;
  tmp_0[12] = 1000.0F * Quaternion_controller_U.qz;
  scale = 1000.0F * -Quaternion_controller_U.qx;
  tmp_0[1] = scale;
  tmp_0[5] = 1000.0F * Quaternion_controller_U.qw;
  tmp_0[9] = 1000.0F * Quaternion_controller_U.qz;
  e_y_idx_0 = 1000.0F * -Quaternion_controller_U.qy;
  tmp_0[13] = e_y_idx_0;
  tmp_0[2] = e_y_idx_0;
  e_y_idx_0 = 1000.0F * -Quaternion_controller_U.qz;
  tmp_0[6] = e_y_idx_0;
  tmp_0[10] = 1000.0F * Quaternion_controller_U.qw;
  tmp_0[14] = 1000.0F * Quaternion_controller_U.qx;
  tmp_0[3] = e_y_idx_0;
  tmp_0[7] = 1000.0F * Quaternion_controller_U.qy;
  tmp_0[11] = scale;
  tmp_0[15] = 1000.0F * Quaternion_controller_U.qw;

  /* Sum: '<S3>/Diff' incorporates:
   *  Inport: '<Root>/qw'
   *  Inport: '<Root>/qx'
   *  Inport: '<Root>/qy'
   *  Inport: '<Root>/qz'
   *  MATLAB Function: '<Root>/MATLAB Function'
   *  UnitDelay: '<S3>/UD'
   *
   * Block description for '<S3>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S3>/UD':
   *
   *  Store in Global RAM
   */
  e_y_idx_0 = Quaternion_controller_U.qw - Quaternion_controller_DW.UD_DSTATE[0];
  e_y_idx_1 = Quaternion_controller_U.qx - Quaternion_controller_DW.UD_DSTATE[1];
  rtb_sqrt = Quaternion_controller_U.qy - Quaternion_controller_DW.UD_DSTATE[2];
  absxk = Quaternion_controller_U.qz - Quaternion_controller_DW.UD_DSTATE[3];

  /* MATLAB Function: '<Root>/MATLAB Function' */
  for (cff = 0; cff < 4; cff++) {
    scale = tmp_0[cff + 12] * absxk + (tmp_0[cff + 8] * rtb_sqrt + (tmp_0[cff +
      4] * e_y_idx_1 + tmp_0[cff] * e_y_idx_0));
    tmp_1[cff] = scale;
  }

  Quaternion_controller_Y.Omega_dot_c[0] = tmp_1[1];

  /* DiscreteFir: '<S1>/Discrete FIR Filter3' incorporates:
   *  Constant: '<Root>/xi_ddot_ref'
   */
  scale = Quaternion_controller_P.xi_ddot_ref_Value[0] *
    Quaternion_controller_P.DiscreteFIRFilter3_Coefficients[0];
  cff = 1;
  for (j = Quaternion_controller_DW.DiscreteFIRFilter3_circBuf; j < 199; j++) {
    scale += Quaternion_controller_DW.DiscreteFIRFilter3_states[j] *
      Quaternion_controller_P.DiscreteFIRFilter3_Coefficients[cff];
    cff++;
  }

  for (j = 0; j < Quaternion_controller_DW.DiscreteFIRFilter3_circBuf; j++) {
    scale += Quaternion_controller_DW.DiscreteFIRFilter3_states[j] *
      Quaternion_controller_P.DiscreteFIRFilter3_Coefficients[cff];
    cff++;
  }

  /* Sum: '<S1>/Sum3' incorporates:
   *  Constant: '<Root>/xi_dot_ref'
   *  DiscreteFir: '<S1>/Discrete FIR Filter3'
   *  DiscreteIntegrator: '<S1>/Discrete-Time Integrator'
   *  Gain: '<S1>/K_xi'
   *  Gain: '<S1>/K_xi_dot'
   *  Gain: '<S1>/K_xi_int'
   *  Sum: '<S1>/Sum1'
   *  Sum: '<S1>/Sum2'
   */
  rtb_Sum3[0] = ((Quaternion_controller_P.K_xi_int
                  * Quaternion_controller_DW.DiscreteTimeIntegrator_DSTATE[0] +
                  Quaternion_controller_P.K_xi * rtb_Gain2[0]) +
                 (Quaternion_controller_P.xi_dot_ref_Value[0] -
                  Quaternion_controller_Y.Omega_dot_c[0]) *
                 Quaternion_controller_P.K_xi_dot) + scale;

  /* Sum: '<S2>/Diff' incorporates:
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
  e_y_idx_0 = Quaternion_controller_Y.Omega_dot_c[0] -
    Quaternion_controller_DW.UD_DSTATE_i[0];

  /* MATLAB Function: '<Root>/MATLAB Function' */
  Quaternion_controller_Y.Omega_dot_c[1] = tmp_1[2];

  /* DiscreteFir: '<S1>/Discrete FIR Filter3' incorporates:
   *  Constant: '<Root>/xi_ddot_ref'
   */
  scale = Quaternion_controller_P.xi_ddot_ref_Value[1] *
    Quaternion_controller_P.DiscreteFIRFilter3_Coefficients[0];
  cff = 1;
  for (j = Quaternion_controller_DW.DiscreteFIRFilter3_circBuf; j < 199; j++) {
    scale += Quaternion_controller_DW.DiscreteFIRFilter3_states[199 + j] *
      Quaternion_controller_P.DiscreteFIRFilter3_Coefficients[cff];
    cff++;
  }

  for (j = 0; j < Quaternion_controller_DW.DiscreteFIRFilter3_circBuf; j++) {
    scale += Quaternion_controller_DW.DiscreteFIRFilter3_states[199 + j] *
      Quaternion_controller_P.DiscreteFIRFilter3_Coefficients[cff];
    cff++;
  }

  /* Sum: '<S1>/Sum3' incorporates:
   *  Constant: '<Root>/xi_dot_ref'
   *  DiscreteFir: '<S1>/Discrete FIR Filter3'
   *  DiscreteIntegrator: '<S1>/Discrete-Time Integrator'
   *  Gain: '<S1>/K_xi'
   *  Gain: '<S1>/K_xi_dot'
   *  Gain: '<S1>/K_xi_int'
   *  Sum: '<S1>/Sum1'
   *  Sum: '<S1>/Sum2'
   */
  rtb_Sum3[1] = ((Quaternion_controller_P.K_xi_int
                  * Quaternion_controller_DW.DiscreteTimeIntegrator_DSTATE[1] +
                  Quaternion_controller_P.K_xi * rtb_Gain2[1]) +
                 (Quaternion_controller_P.xi_dot_ref_Value[1] -
                  Quaternion_controller_Y.Omega_dot_c[1]) *
                 Quaternion_controller_P.K_xi_dot) + scale;

  /* Sum: '<S2>/Diff' incorporates:
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
  e_y_idx_1 = Quaternion_controller_Y.Omega_dot_c[1] -
    Quaternion_controller_DW.UD_DSTATE_i[1];

  /* MATLAB Function: '<Root>/MATLAB Function' */
  Quaternion_controller_Y.Omega_dot_c[2] = tmp_1[3];

  /* DiscreteFir: '<S1>/Discrete FIR Filter3' incorporates:
   *  Constant: '<Root>/xi_ddot_ref'
   */
  scale = Quaternion_controller_P.xi_ddot_ref_Value[2] *
    Quaternion_controller_P.DiscreteFIRFilter3_Coefficients[0];
  cff = 1;
  for (j = Quaternion_controller_DW.DiscreteFIRFilter3_circBuf; j < 199; j++) {
    scale += Quaternion_controller_DW.DiscreteFIRFilter3_states[398 + j] *
      Quaternion_controller_P.DiscreteFIRFilter3_Coefficients[cff];
    cff++;
  }

  for (j = 0; j < Quaternion_controller_DW.DiscreteFIRFilter3_circBuf; j++) {
    scale += Quaternion_controller_DW.DiscreteFIRFilter3_states[398 + j] *
      Quaternion_controller_P.DiscreteFIRFilter3_Coefficients[cff];
    cff++;
  }

  /* Sum: '<S2>/Diff' incorporates:
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
  rtb_sqrt = Quaternion_controller_Y.Omega_dot_c[2] -
    Quaternion_controller_DW.UD_DSTATE_i[2];

  /* DiscreteFir: '<Root>/Discrete FIR Filter' */
  absxk = e_y_idx_0 * Quaternion_controller_P.DiscreteFIRFilter_Coefficients[0];
  cff = 1;
  for (j = Quaternion_controller_DW.DiscreteFIRFilter_circBuf; j < 4; j++) {
    absxk += Quaternion_controller_DW.DiscreteFIRFilter_states[j] *
      Quaternion_controller_P.DiscreteFIRFilter_Coefficients[cff];
    cff++;
  }

  for (j = 0; j < Quaternion_controller_DW.DiscreteFIRFilter_circBuf; j++) {
    absxk += Quaternion_controller_DW.DiscreteFIRFilter_states[j] *
      Quaternion_controller_P.DiscreteFIRFilter_Coefficients[cff];
    cff++;
  }

  /* Sum: '<S10>/Sum' incorporates:
   *  DiscreteFir: '<Root>/Discrete FIR Filter'
   *  Gain: '<S10>/omega_dot_f_gain'
   */
  rtb_DiscreteFIRFilter1_idx_0 = rtb_Sum3[0] -
    Quaternion_controller_P.omega_dot_f_gain * absxk;

  /* DiscreteFir: '<Root>/Discrete FIR Filter' */
  absxk = e_y_idx_1 * Quaternion_controller_P.DiscreteFIRFilter_Coefficients[0];
  cff = 1;
  for (j = Quaternion_controller_DW.DiscreteFIRFilter_circBuf; j < 4; j++) {
    absxk += Quaternion_controller_DW.DiscreteFIRFilter_states[4 + j] *
      Quaternion_controller_P.DiscreteFIRFilter_Coefficients[cff];
    cff++;
  }

  for (j = 0; j < Quaternion_controller_DW.DiscreteFIRFilter_circBuf; j++) {
    absxk += Quaternion_controller_DW.DiscreteFIRFilter_states[4 + j] *
      Quaternion_controller_P.DiscreteFIRFilter_Coefficients[cff];
    cff++;
  }

  /* Sum: '<S10>/Sum' incorporates:
   *  DiscreteFir: '<Root>/Discrete FIR Filter'
   *  Gain: '<S10>/omega_dot_f_gain'
   */
  rtb_DiscreteFIRFilter1_idx_1 = rtb_Sum3[1] -
    Quaternion_controller_P.omega_dot_f_gain * absxk;

  /* DiscreteFir: '<Root>/Discrete FIR Filter' */
  absxk = rtb_sqrt * Quaternion_controller_P.DiscreteFIRFilter_Coefficients[0];
  cff = 1;
  for (j = Quaternion_controller_DW.DiscreteFIRFilter_circBuf; j < 4; j++) {
    absxk += Quaternion_controller_DW.DiscreteFIRFilter_states[8 + j] *
      Quaternion_controller_P.DiscreteFIRFilter_Coefficients[cff];
    cff++;
  }

  for (j = 0; j < Quaternion_controller_DW.DiscreteFIRFilter_circBuf; j++) {
    absxk += Quaternion_controller_DW.DiscreteFIRFilter_states[8 + j] *
      Quaternion_controller_P.DiscreteFIRFilter_Coefficients[cff];
    cff++;
  }

  /* Sum: '<S10>/Sum' incorporates:
   *  Constant: '<Root>/xi_dot_ref'
   *  DiscreteFir: '<Root>/Discrete FIR Filter'
   *  DiscreteFir: '<S1>/Discrete FIR Filter3'
   *  DiscreteIntegrator: '<S1>/Discrete-Time Integrator'
   *  Gain: '<S10>/omega_dot_f_gain'
   *  Gain: '<S1>/K_xi'
   *  Gain: '<S1>/K_xi_dot'
   *  Gain: '<S1>/K_xi_int'
   *  Sum: '<S1>/Sum1'
   *  Sum: '<S1>/Sum2'
   *  Sum: '<S1>/Sum3'
   */
  rtb_DiscreteFIRFilter1_idx_2 = (((Quaternion_controller_P.K_xi_int
    * Quaternion_controller_DW.DiscreteTimeIntegrator_DSTATE[2] +
    Quaternion_controller_P.K_xi * rtb_Gain2[2]) +
    (Quaternion_controller_P.xi_dot_ref_Value[2] -
     Quaternion_controller_Y.Omega_dot_c[2]) * Quaternion_controller_P.K_xi_dot)
    + scale) - Quaternion_controller_P.omega_dot_f_gain * absxk;

  /* MATLAB Function: '<S6>/vector norm' */
  rtb_y = 0.0F;
  scale = 1.29246971E-26F;
  for (cff = 0; cff < 3; cff++) {
    /* MATLAB Function: '<S6>/vector norm' */
    absxk = fabsf(rtb_Reshape[cff]);
    if (absxk > scale) {
      t = scale / absxk;
      rtb_y = rtb_y * t * t + 1.0F;
      scale = absxk;
    } else {
      t = absxk / scale;
      rtb_y += t * t;
    }

    /* Product: '<S10>/Multiply' incorporates:
     *  Constant: '<S10>/momentum of inertia'
     */
    rtb_Sum3[cff] = Quaternion_controller_P.inertia[cff + 6] *
      rtb_DiscreteFIRFilter1_idx_2 + (Quaternion_controller_P.inertia[cff + 3] *
      rtb_DiscreteFIRFilter1_idx_1 + Quaternion_controller_P.inertia[cff] *
      rtb_DiscreteFIRFilter1_idx_0);
  }

  /* MATLAB Function: '<S6>/vector norm' */
  rtb_y = scale * sqrtf(rtb_y);

  /* Gain: '<S6>/Gain1' incorporates:
   *  Gain: '<S6>/mass'
   */
  absxk = Quaternion_controller_P.mass * rtb_y *
    Quaternion_controller_P.Gain1_Gain_m;

  /* RelationalOperator: '<Root>/Relational Operator' incorporates:
   *  Constant: '<Root>/Constant'
   */
  rtb_RelationalOperator = (Quaternion_controller_P.Constant_Value_l <= absxk);

  /* DiscreteTransferFcn: '<S4>/Discrete Transfer Fcn1' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion1'
   *  Memory: '<Root>/Memory'
   */
  if (rtb_RelationalOperator &&
      (Quaternion_controller_PrevZCX.DiscreteTransferFcn1_Reset_ZCE != POS_ZCSIG))
  {
    Quaternion_controller_DW.DiscreteTransferFcn1_states[0] =
      Quaternion_controller_P.DiscreteTransferFcn1_InitialSta;
    Quaternion_controller_DW.DiscreteTransferFcn1_states[1] =
      Quaternion_controller_P.DiscreteTransferFcn1_InitialSta;
    Quaternion_controller_DW.DiscreteTransferFcn1_states[2] =
      Quaternion_controller_P.DiscreteTransferFcn1_InitialSta;
    Quaternion_controller_DW.DiscreteTransferFcn1_states[3] =
      Quaternion_controller_P.DiscreteTransferFcn1_InitialSta;
  }

  Quaternion_controller_PrevZCX.DiscreteTransferFcn1_Reset_ZCE =
    rtb_RelationalOperator;
  t = ((real32_T)Quaternion_controller_DW.Memory_PreviousInput[0] -
       Quaternion_controller_P.DiscreteTransferFcn1_DenCoef[1] *
       Quaternion_controller_DW.DiscreteTransferFcn1_states[0]) /
    Quaternion_controller_P.DiscreteTransferFcn1_DenCoef[0];
  rtb_DiscreteFIRFilter1_idx_0 =
    Quaternion_controller_P.DiscreteTransferFcn1_NumCoef[0] * t +
    Quaternion_controller_P.DiscreteTransferFcn1_NumCoef[1] *
    Quaternion_controller_DW.DiscreteTransferFcn1_states[0];
  rtb_DiscreteFIRFilter1_idx_1 = t;
  t = ((real32_T)Quaternion_controller_DW.Memory_PreviousInput[1] -
       Quaternion_controller_P.DiscreteTransferFcn1_DenCoef[1] *
       Quaternion_controller_DW.DiscreteTransferFcn1_states[1]) /
    Quaternion_controller_P.DiscreteTransferFcn1_DenCoef[0];
  rtb_DiscreteFIRFilter1_idx_2 =
    Quaternion_controller_P.DiscreteTransferFcn1_NumCoef[0] * t +
    Quaternion_controller_P.DiscreteTransferFcn1_NumCoef[1] *
    Quaternion_controller_DW.DiscreteTransferFcn1_states[1];
  rtb_y = t;
  t = ((real32_T)Quaternion_controller_DW.Memory_PreviousInput[2] -
       Quaternion_controller_P.DiscreteTransferFcn1_DenCoef[1] *
       Quaternion_controller_DW.DiscreteTransferFcn1_states[2]) /
    Quaternion_controller_P.DiscreteTransferFcn1_DenCoef[0];
  rtb_DiscreteTransferFcn1_idx_2 =
    Quaternion_controller_P.DiscreteTransferFcn1_NumCoef[0] * t +
    Quaternion_controller_P.DiscreteTransferFcn1_NumCoef[1] *
    Quaternion_controller_DW.DiscreteTransferFcn1_states[2];
  DiscreteTransferFcn1_tmp_idx_2 = t;
  t = ((real32_T)Quaternion_controller_DW.Memory_PreviousInput[3] -
       Quaternion_controller_P.DiscreteTransferFcn1_DenCoef[1] *
       Quaternion_controller_DW.DiscreteTransferFcn1_states[3]) /
    Quaternion_controller_P.DiscreteTransferFcn1_DenCoef[0];
  numAccum = Quaternion_controller_P.DiscreteTransferFcn1_NumCoef[0] * t +
    Quaternion_controller_P.DiscreteTransferFcn1_NumCoef[1] *
    Quaternion_controller_DW.DiscreteTransferFcn1_states[3];

  /* Product: '<S4>/Multiply3' incorporates:
   *  Constant: '<S4>/G2'
   *  DiscreteTransferFcn: '<S4>/Discrete Transfer Fcn1'
   */
  for (cff = 0; cff < 3; cff++) {
    scale = Quaternion_controller_P.G2_Value[cff + 9] * numAccum +
      (Quaternion_controller_P.G2_Value[cff + 6] *
       rtb_DiscreteTransferFcn1_idx_2 + (Quaternion_controller_P.G2_Value[cff +
        3] * rtb_DiscreteFIRFilter1_idx_2 + Quaternion_controller_P.G2_Value[cff]
        * rtb_DiscreteFIRFilter1_idx_0));
    rtb_Reshape[cff] = scale;
  }

  /* End of Product: '<S4>/Multiply3' */

  /* DiscreteFir: '<Root>/Discrete FIR Filter1' */
  scale = rtb_Reshape[0] *
    Quaternion_controller_P.DiscreteFIRFilter1_Coefficients[0];
  cff = 1;
  for (j = Quaternion_controller_DW.DiscreteFIRFilter1_circBuf; j < 4; j++) {
    scale += Quaternion_controller_DW.DiscreteFIRFilter1_states[j] *
      Quaternion_controller_P.DiscreteFIRFilter1_Coefficients[cff];
    cff++;
  }

  for (j = 0; j < Quaternion_controller_DW.DiscreteFIRFilter1_circBuf; j++) {
    scale += Quaternion_controller_DW.DiscreteFIRFilter1_states[j] *
      Quaternion_controller_P.DiscreteFIRFilter1_Coefficients[cff];
    cff++;
  }

  /* Sum: '<S10>/Sum1' incorporates:
   *  DiscreteFir: '<Root>/Discrete FIR Filter1'
   *  Gain: '<S10>/mu_f_gain'
   */
  rtb_Multiply1[0] = Quaternion_controller_P.mu_f_gain * scale + rtb_Sum3[0];

  /* DiscreteFir: '<Root>/Discrete FIR Filter1' */
  scale = rtb_Reshape[1] *
    Quaternion_controller_P.DiscreteFIRFilter1_Coefficients[0];
  cff = 1;
  for (j = Quaternion_controller_DW.DiscreteFIRFilter1_circBuf; j < 4; j++) {
    scale += Quaternion_controller_DW.DiscreteFIRFilter1_states[4 + j] *
      Quaternion_controller_P.DiscreteFIRFilter1_Coefficients[cff];
    cff++;
  }

  for (j = 0; j < Quaternion_controller_DW.DiscreteFIRFilter1_circBuf; j++) {
    scale += Quaternion_controller_DW.DiscreteFIRFilter1_states[4 + j] *
      Quaternion_controller_P.DiscreteFIRFilter1_Coefficients[cff];
    cff++;
  }

  /* Sum: '<S10>/Sum1' incorporates:
   *  DiscreteFir: '<Root>/Discrete FIR Filter1'
   *  Gain: '<S10>/mu_f_gain'
   */
  rtb_Multiply1[1] = Quaternion_controller_P.mu_f_gain * scale + rtb_Sum3[1];

  /* DiscreteFir: '<Root>/Discrete FIR Filter1' */
  scale = rtb_Reshape[2] *
    Quaternion_controller_P.DiscreteFIRFilter1_Coefficients[0];
  cff = 1;
  for (j = Quaternion_controller_DW.DiscreteFIRFilter1_circBuf; j < 4; j++) {
    scale += Quaternion_controller_DW.DiscreteFIRFilter1_states[8 + j] *
      Quaternion_controller_P.DiscreteFIRFilter1_Coefficients[cff];
    cff++;
  }

  for (j = 0; j < Quaternion_controller_DW.DiscreteFIRFilter1_circBuf; j++) {
    scale += Quaternion_controller_DW.DiscreteFIRFilter1_states[8 + j] *
      Quaternion_controller_P.DiscreteFIRFilter1_Coefficients[cff];
    cff++;
  }

  /* Sum: '<S10>/Sum1' incorporates:
   *  DiscreteFir: '<Root>/Discrete FIR Filter1'
   *  Gain: '<S10>/mu_f_gain'
   */
  rtb_Multiply1[2] = Quaternion_controller_P.mu_f_gain * scale + rtb_Sum3[2];

  /* Product: '<S10>/Multiply1' incorporates:
   *  Constant: '<S10>/G1'
   *  SignalConversion: '<S10>/ConcatBufferAtMatrix ConcatenateIn2'
   */
  for (cff = 0; cff < 4; cff++) {
    scale = Quaternion_controller_P.G1_Value[cff + 12] * absxk +
      (Quaternion_controller_P.G1_Value[cff + 8] * rtb_Multiply1[2] +
       (Quaternion_controller_P.G1_Value[cff + 4] * rtb_Multiply1[1] +
        Quaternion_controller_P.G1_Value[cff] * rtb_Multiply1[0]));
    tmp_1[cff] = scale;
  }

  /* Saturate: '<S10>/Saturation' incorporates:
   *  Product: '<S10>/Multiply1'
   */
  if (tmp_1[0] > Quaternion_controller_P.Saturation_UpperSat_e) {
    scale = Quaternion_controller_P.Saturation_UpperSat_e;
  } else if (tmp_1[0] < Quaternion_controller_P.Saturation_LowerSat_h) {
    scale = Quaternion_controller_P.Saturation_LowerSat_h;
  } else {
    scale = tmp_1[0];
  }

  /* MATLAB Function: '<S10>/force2motorCMD' */
  rtb_omega_cmd = (sqrtf(0.366F * scale + 0.00457922881F) + -0.06767F) *
    65536.0F / 0.183F;

  /* Saturate: '<Root>/Saturation' */
  if (rtb_omega_cmd > Quaternion_controller_P.Saturation_UpperSat) {
    rtb_omega_cmd = Quaternion_controller_P.Saturation_UpperSat;
  } else {
    if (rtb_omega_cmd < Quaternion_controller_P.Saturation_LowerSat) {
      rtb_omega_cmd = Quaternion_controller_P.Saturation_LowerSat;
    }
  }

  /* DataTypeConversion: '<Root>/Data Type Conversion' */
  rtb_omega_cmd = floor(rtb_omega_cmd);
  if (rtIsNaN(rtb_omega_cmd) || rtIsInf(rtb_omega_cmd)) {
    rtb_omega_cmd = 0.0;
  } else {
    rtb_omega_cmd = fmod(rtb_omega_cmd, 65536.0);
  }

  Quaternion_controller_DW.Memory_PreviousInput[0] = (uint16_T)(rtb_omega_cmd <
    0.0 ? (int32_T)(uint16_T)-(int16_T)(uint16_T)-rtb_omega_cmd : (int32_T)
    (uint16_T)rtb_omega_cmd);

  /* Saturate: '<S10>/Saturation' incorporates:
   *  Product: '<S10>/Multiply1'
   */
  if (tmp_1[1] > Quaternion_controller_P.Saturation_UpperSat_e) {
    scale = Quaternion_controller_P.Saturation_UpperSat_e;
  } else if (tmp_1[1] < Quaternion_controller_P.Saturation_LowerSat_h) {
    scale = Quaternion_controller_P.Saturation_LowerSat_h;
  } else {
    scale = tmp_1[1];
  }

  /* MATLAB Function: '<S10>/force2motorCMD' */
  rtb_omega_cmd = (sqrtf(0.366F * scale + 0.00457922881F) + -0.06767F) *
    65536.0F / 0.183F;

  /* Saturate: '<Root>/Saturation' */
  if (rtb_omega_cmd > Quaternion_controller_P.Saturation_UpperSat) {
    rtb_omega_cmd = Quaternion_controller_P.Saturation_UpperSat;
  } else {
    if (rtb_omega_cmd < Quaternion_controller_P.Saturation_LowerSat) {
      rtb_omega_cmd = Quaternion_controller_P.Saturation_LowerSat;
    }
  }

  /* DataTypeConversion: '<Root>/Data Type Conversion' */
  rtb_omega_cmd = floor(rtb_omega_cmd);
  if (rtIsNaN(rtb_omega_cmd) || rtIsInf(rtb_omega_cmd)) {
    rtb_omega_cmd = 0.0;
  } else {
    rtb_omega_cmd = fmod(rtb_omega_cmd, 65536.0);
  }

  Quaternion_controller_DW.Memory_PreviousInput[1] = (uint16_T)(rtb_omega_cmd <
    0.0 ? (int32_T)(uint16_T)-(int16_T)(uint16_T)-rtb_omega_cmd : (int32_T)
    (uint16_T)rtb_omega_cmd);

  /* Saturate: '<S10>/Saturation' incorporates:
   *  Product: '<S10>/Multiply1'
   */
  if (tmp_1[2] > Quaternion_controller_P.Saturation_UpperSat_e) {
    scale = Quaternion_controller_P.Saturation_UpperSat_e;
  } else if (tmp_1[2] < Quaternion_controller_P.Saturation_LowerSat_h) {
    scale = Quaternion_controller_P.Saturation_LowerSat_h;
  } else {
    scale = tmp_1[2];
  }

  /* MATLAB Function: '<S10>/force2motorCMD' */
  rtb_omega_cmd = (sqrtf(0.366F * scale + 0.00457922881F) + -0.06767F) *
    65536.0F / 0.183F;

  /* Saturate: '<Root>/Saturation' */
  if (rtb_omega_cmd > Quaternion_controller_P.Saturation_UpperSat) {
    rtb_omega_cmd = Quaternion_controller_P.Saturation_UpperSat;
  } else {
    if (rtb_omega_cmd < Quaternion_controller_P.Saturation_LowerSat) {
      rtb_omega_cmd = Quaternion_controller_P.Saturation_LowerSat;
    }
  }

  /* DataTypeConversion: '<Root>/Data Type Conversion' */
  rtb_omega_cmd = floor(rtb_omega_cmd);
  if (rtIsNaN(rtb_omega_cmd) || rtIsInf(rtb_omega_cmd)) {
    rtb_omega_cmd = 0.0;
  } else {
    rtb_omega_cmd = fmod(rtb_omega_cmd, 65536.0);
  }

  Quaternion_controller_DW.Memory_PreviousInput[2] = (uint16_T)(rtb_omega_cmd <
    0.0 ? (int32_T)(uint16_T)-(int16_T)(uint16_T)-rtb_omega_cmd : (int32_T)
    (uint16_T)rtb_omega_cmd);

  /* Saturate: '<S10>/Saturation' incorporates:
   *  Product: '<S10>/Multiply1'
   */
  if (tmp_1[3] > Quaternion_controller_P.Saturation_UpperSat_e) {
    scale = Quaternion_controller_P.Saturation_UpperSat_e;
  } else if (tmp_1[3] < Quaternion_controller_P.Saturation_LowerSat_h) {
    scale = Quaternion_controller_P.Saturation_LowerSat_h;
  } else {
    scale = tmp_1[3];
  }

  /* MATLAB Function: '<S10>/force2motorCMD' */
  rtb_omega_cmd = (sqrtf(0.366F * scale + 0.00457922881F) + -0.06767F) *
    65536.0F / 0.183F;

  /* Saturate: '<Root>/Saturation' */
  if (rtb_omega_cmd > Quaternion_controller_P.Saturation_UpperSat) {
    rtb_omega_cmd = Quaternion_controller_P.Saturation_UpperSat;
  } else {
    if (rtb_omega_cmd < Quaternion_controller_P.Saturation_LowerSat) {
      rtb_omega_cmd = Quaternion_controller_P.Saturation_LowerSat;
    }
  }

  /* DataTypeConversion: '<Root>/Data Type Conversion' */
  rtb_omega_cmd = floor(rtb_omega_cmd);
  if (rtIsNaN(rtb_omega_cmd) || rtIsInf(rtb_omega_cmd)) {
    rtb_omega_cmd = 0.0;
  } else {
    rtb_omega_cmd = fmod(rtb_omega_cmd, 65536.0);
  }

  Quaternion_controller_DW.Memory_PreviousInput[3] = (uint16_T)(rtb_omega_cmd <
    0.0 ? (int32_T)(uint16_T)-(int16_T)(uint16_T)-rtb_omega_cmd : (int32_T)
    (uint16_T)rtb_omega_cmd);

  /* Outport: '<Root>/M1_output' */
  Quaternion_controller_Y.M1_output =
    Quaternion_controller_DW.Memory_PreviousInput[0];

  /* Outport: '<Root>/M2_output' */
  Quaternion_controller_Y.M2_output =
    Quaternion_controller_DW.Memory_PreviousInput[1];

  /* Outport: '<Root>/M3_output' */
  Quaternion_controller_Y.M3_output =
    Quaternion_controller_DW.Memory_PreviousInput[2];

  /* Outport: '<Root>/M4_output' */
  Quaternion_controller_Y.M4_output =
    Quaternion_controller_DW.Memory_PreviousInput[3];

  /* Update for DiscreteIntegrator: '<S1>/Discrete-Time Integrator' */
  Quaternion_controller_DW.DiscreteTimeIntegrator_DSTATE[0] +=
    Quaternion_controller_P.DiscreteTimeIntegrator_gainval * rtb_Gain2[0];
  if (Quaternion_controller_DW.DiscreteTimeIntegrator_DSTATE[0] >=
      Quaternion_controller_P.DiscreteTimeIntegrator_UpperSat) {
    Quaternion_controller_DW.DiscreteTimeIntegrator_DSTATE[0] =
      Quaternion_controller_P.DiscreteTimeIntegrator_UpperSat;
  } else {
    if (Quaternion_controller_DW.DiscreteTimeIntegrator_DSTATE[0] <=
        Quaternion_controller_P.DiscreteTimeIntegrator_LowerSat) {
      Quaternion_controller_DW.DiscreteTimeIntegrator_DSTATE[0] =
        Quaternion_controller_P.DiscreteTimeIntegrator_LowerSat;
    }
  }

  Quaternion_controller_DW.DiscreteTimeIntegrator_DSTATE[1] +=
    Quaternion_controller_P.DiscreteTimeIntegrator_gainval * rtb_Gain2[1];
  if (Quaternion_controller_DW.DiscreteTimeIntegrator_DSTATE[1] >=
      Quaternion_controller_P.DiscreteTimeIntegrator_UpperSat) {
    Quaternion_controller_DW.DiscreteTimeIntegrator_DSTATE[1] =
      Quaternion_controller_P.DiscreteTimeIntegrator_UpperSat;
  } else {
    if (Quaternion_controller_DW.DiscreteTimeIntegrator_DSTATE[1] <=
        Quaternion_controller_P.DiscreteTimeIntegrator_LowerSat) {
      Quaternion_controller_DW.DiscreteTimeIntegrator_DSTATE[1] =
        Quaternion_controller_P.DiscreteTimeIntegrator_LowerSat;
    }
  }

  Quaternion_controller_DW.DiscreteTimeIntegrator_DSTATE[2] +=
    Quaternion_controller_P.DiscreteTimeIntegrator_gainval * rtb_Gain2[2];
  if (Quaternion_controller_DW.DiscreteTimeIntegrator_DSTATE[2] >=
      Quaternion_controller_P.DiscreteTimeIntegrator_UpperSat) {
    Quaternion_controller_DW.DiscreteTimeIntegrator_DSTATE[2] =
      Quaternion_controller_P.DiscreteTimeIntegrator_UpperSat;
  } else {
    if (Quaternion_controller_DW.DiscreteTimeIntegrator_DSTATE[2] <=
        Quaternion_controller_P.DiscreteTimeIntegrator_LowerSat) {
      Quaternion_controller_DW.DiscreteTimeIntegrator_DSTATE[2] =
        Quaternion_controller_P.DiscreteTimeIntegrator_LowerSat;
    }
  }

  /* End of Update for DiscreteIntegrator: '<S1>/Discrete-Time Integrator' */

  /* Update for UnitDelay: '<S3>/UD' incorporates:
   *  Inport: '<Root>/qw'
   *  Inport: '<Root>/qx'
   *  Inport: '<Root>/qy'
   *  Inport: '<Root>/qz'
   *
   * Block description for '<S3>/UD':
   *
   *  Store in Global RAM
   */
  Quaternion_controller_DW.UD_DSTATE[0] = Quaternion_controller_U.qw;
  Quaternion_controller_DW.UD_DSTATE[1] = Quaternion_controller_U.qx;
  Quaternion_controller_DW.UD_DSTATE[2] = Quaternion_controller_U.qy;
  Quaternion_controller_DW.UD_DSTATE[3] = Quaternion_controller_U.qz;

  /* Update for DiscreteFir: '<S1>/Discrete FIR Filter3' incorporates:
   *  Constant: '<Root>/xi_ddot_ref'
   */
  /* Update circular buffer index */
  Quaternion_controller_DW.DiscreteFIRFilter3_circBuf--;
  if (Quaternion_controller_DW.DiscreteFIRFilter3_circBuf < 0) {
    Quaternion_controller_DW.DiscreteFIRFilter3_circBuf = 198;
  }

  /* Update circular buffer */
  Quaternion_controller_DW.DiscreteFIRFilter3_states[Quaternion_controller_DW.DiscreteFIRFilter3_circBuf]
    = Quaternion_controller_P.xi_ddot_ref_Value[0];

  /* Update for UnitDelay: '<S2>/UD'
   *
   * Block description for '<S2>/UD':
   *
   *  Store in Global RAM
   */
  Quaternion_controller_DW.UD_DSTATE_i[0] = Quaternion_controller_Y.Omega_dot_c
    [0];

  /* Update for DiscreteFir: '<S1>/Discrete FIR Filter3' incorporates:
   *  Constant: '<Root>/xi_ddot_ref'
   */
  Quaternion_controller_DW.DiscreteFIRFilter3_states[Quaternion_controller_DW.DiscreteFIRFilter3_circBuf
    + 199] = Quaternion_controller_P.xi_ddot_ref_Value[1];

  /* Update for UnitDelay: '<S2>/UD'
   *
   * Block description for '<S2>/UD':
   *
   *  Store in Global RAM
   */
  Quaternion_controller_DW.UD_DSTATE_i[1] = Quaternion_controller_Y.Omega_dot_c
    [1];

  /* Update for DiscreteFir: '<S1>/Discrete FIR Filter3' incorporates:
   *  Constant: '<Root>/xi_ddot_ref'
   */
  Quaternion_controller_DW.DiscreteFIRFilter3_states[Quaternion_controller_DW.DiscreteFIRFilter3_circBuf
    + 398] = Quaternion_controller_P.xi_ddot_ref_Value[2];

  /* Update for UnitDelay: '<S2>/UD'
   *
   * Block description for '<S2>/UD':
   *
   *  Store in Global RAM
   */
  Quaternion_controller_DW.UD_DSTATE_i[2] = Quaternion_controller_Y.Omega_dot_c
    [2];

  /* Update for DiscreteFir: '<Root>/Discrete FIR Filter' */
  /* Update circular buffer index */
  Quaternion_controller_DW.DiscreteFIRFilter_circBuf--;
  if (Quaternion_controller_DW.DiscreteFIRFilter_circBuf < 0) {
    Quaternion_controller_DW.DiscreteFIRFilter_circBuf = 3;
  }

  /* Update circular buffer */
  Quaternion_controller_DW.DiscreteFIRFilter_states[Quaternion_controller_DW.DiscreteFIRFilter_circBuf]
    = e_y_idx_0;
  Quaternion_controller_DW.DiscreteFIRFilter_states[Quaternion_controller_DW.DiscreteFIRFilter_circBuf
    + 4] = e_y_idx_1;
  Quaternion_controller_DW.DiscreteFIRFilter_states[Quaternion_controller_DW.DiscreteFIRFilter_circBuf
    + 8] = rtb_sqrt;

  /* End of Update for DiscreteFir: '<Root>/Discrete FIR Filter' */

  /* Update for DiscreteTransferFcn: '<S4>/Discrete Transfer Fcn1' */
  Quaternion_controller_DW.DiscreteTransferFcn1_states[0] =
    rtb_DiscreteFIRFilter1_idx_1;
  Quaternion_controller_DW.DiscreteTransferFcn1_states[1] = rtb_y;
  Quaternion_controller_DW.DiscreteTransferFcn1_states[2] =
    DiscreteTransferFcn1_tmp_idx_2;
  Quaternion_controller_DW.DiscreteTransferFcn1_states[3] = t;

  /* Update for DiscreteFir: '<Root>/Discrete FIR Filter1' */
  /* Update circular buffer index */
  Quaternion_controller_DW.DiscreteFIRFilter1_circBuf--;
  if (Quaternion_controller_DW.DiscreteFIRFilter1_circBuf < 0) {
    Quaternion_controller_DW.DiscreteFIRFilter1_circBuf = 3;
  }

  /* Update circular buffer */
  Quaternion_controller_DW.DiscreteFIRFilter1_states[Quaternion_controller_DW.DiscreteFIRFilter1_circBuf]
    = rtb_Reshape[0];
  Quaternion_controller_DW.DiscreteFIRFilter1_states[Quaternion_controller_DW.DiscreteFIRFilter1_circBuf
    + 4] = rtb_Reshape[1];
  Quaternion_controller_DW.DiscreteFIRFilter1_states[Quaternion_controller_DW.DiscreteFIRFilter1_circBuf
    + 8] = rtb_Reshape[2];

  /* End of Update for DiscreteFir: '<Root>/Discrete FIR Filter1' */

  /* Update for DiscreteFir: '<Root>/Discrete FIR Filter2' incorporates:
   *  Constant: '<S4>/G1'
   *  DiscreteTransferFcn: '<S4>/Discrete Transfer Fcn1'
   *  Gain: '<S4>/Gain'
   *  Gain: '<S4>/Gain2'
   *  MATLAB Function: '<S4>/vector norm'
   *  Product: '<S4>/Multiply2'
   */
  /* Update circular buffer index */
  Quaternion_controller_DW.DiscreteFIRFilter2_circBuf--;
  if (Quaternion_controller_DW.DiscreteFIRFilter2_circBuf < 0) {
    Quaternion_controller_DW.DiscreteFIRFilter2_circBuf = 18;
  }

  /* Update circular buffer */
  Quaternion_controller_DW.DiscreteFIRFilter2_states[Quaternion_controller_DW.DiscreteFIRFilter2_circBuf]
    = fabsf((((Quaternion_controller_P.G1_Value_c[0] *
               rtb_DiscreteFIRFilter1_idx_0 +
               Quaternion_controller_P.G1_Value_c[1] *
               rtb_DiscreteFIRFilter1_idx_2) +
              Quaternion_controller_P.G1_Value_c[2] *
              rtb_DiscreteTransferFcn1_idx_2) +
             Quaternion_controller_P.G1_Value_c[3] * numAccum) * (1.0F /
             Quaternion_controller_P.mass)) *
    Quaternion_controller_P.Gain2_Gain_h;

  /* End of Update for DiscreteFir: '<Root>/Discrete FIR Filter2' */
}

/* Model initialize function */
void Quaternion_controller_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize error status */
  rtmSetErrorStatus(Quaternion_controller_M, (NULL));

  /* block I/O */
  (void) memset(((void *) &Quaternion_controller_B), 0,
                sizeof(B_Quaternion_controller_T));

  /* states (dwork) */
  (void) memset((void *)&Quaternion_controller_DW, 0,
                sizeof(DW_Quaternion_controller_T));

  /* external inputs */
  (void)memset((void *)&Quaternion_controller_U, 0, sizeof
               (ExtU_Quaternion_controller_T));

  /* external outputs */
  (void) memset((void *)&Quaternion_controller_Y, 0,
                sizeof(ExtY_Quaternion_controller_T));

  {
    int32_T i;
    Quaternion_controller_PrevZCX.DiscreteTransferFcn1_Reset_ZCE = POS_ZCSIG;

    /* InitializeConditions for DiscreteIntegrator: '<S1>/Discrete-Time Integrator' */
    Quaternion_controller_DW.DiscreteTimeIntegrator_DSTATE[0] =
      Quaternion_controller_P.DiscreteTimeIntegrator_IC;
    Quaternion_controller_DW.DiscreteTimeIntegrator_DSTATE[1] =
      Quaternion_controller_P.DiscreteTimeIntegrator_IC;
    Quaternion_controller_DW.DiscreteTimeIntegrator_DSTATE[2] =
      Quaternion_controller_P.DiscreteTimeIntegrator_IC;

    /* InitializeConditions for UnitDelay: '<S3>/UD'
     *
     * Block description for '<S3>/UD':
     *
     *  Store in Global RAM
     */
    Quaternion_controller_DW.UD_DSTATE[0] =
      Quaternion_controller_P.Difference1_ICPrevInput;
    Quaternion_controller_DW.UD_DSTATE[1] =
      Quaternion_controller_P.Difference1_ICPrevInput;
    Quaternion_controller_DW.UD_DSTATE[2] =
      Quaternion_controller_P.Difference1_ICPrevInput;
    Quaternion_controller_DW.UD_DSTATE[3] =
      Quaternion_controller_P.Difference1_ICPrevInput;

    /* InitializeConditions for DiscreteFir: '<S1>/Discrete FIR Filter3' */
    Quaternion_controller_DW.DiscreteFIRFilter3_circBuf = 0;
    for (i = 0; i < 597; i++) {
      Quaternion_controller_DW.DiscreteFIRFilter3_states[i] =
        Quaternion_controller_P.DiscreteFIRFilter3_InitialState;
    }

    /* End of InitializeConditions for DiscreteFir: '<S1>/Discrete FIR Filter3' */

    /* InitializeConditions for UnitDelay: '<S2>/UD'
     *
     * Block description for '<S2>/UD':
     *
     *  Store in Global RAM
     */
    Quaternion_controller_DW.UD_DSTATE_i[0] =
      Quaternion_controller_P.Difference_ICPrevInput;
    Quaternion_controller_DW.UD_DSTATE_i[1] =
      Quaternion_controller_P.Difference_ICPrevInput;
    Quaternion_controller_DW.UD_DSTATE_i[2] =
      Quaternion_controller_P.Difference_ICPrevInput;

    /* InitializeConditions for DiscreteFir: '<Root>/Discrete FIR Filter' */
    Quaternion_controller_DW.DiscreteFIRFilter_circBuf = 0;

    /* InitializeConditions for Memory: '<Root>/Memory' */
    Quaternion_controller_DW.Memory_PreviousInput[0] =
      Quaternion_controller_P.Memory_InitialCondition;

    /* InitializeConditions for DiscreteTransferFcn: '<S4>/Discrete Transfer Fcn1' */
    Quaternion_controller_DW.DiscreteTransferFcn1_states[0] =
      Quaternion_controller_P.DiscreteTransferFcn1_InitialSta;

    /* InitializeConditions for Memory: '<Root>/Memory' */
    Quaternion_controller_DW.Memory_PreviousInput[1] =
      Quaternion_controller_P.Memory_InitialCondition;

    /* InitializeConditions for DiscreteTransferFcn: '<S4>/Discrete Transfer Fcn1' */
    Quaternion_controller_DW.DiscreteTransferFcn1_states[1] =
      Quaternion_controller_P.DiscreteTransferFcn1_InitialSta;

    /* InitializeConditions for Memory: '<Root>/Memory' */
    Quaternion_controller_DW.Memory_PreviousInput[2] =
      Quaternion_controller_P.Memory_InitialCondition;

    /* InitializeConditions for DiscreteTransferFcn: '<S4>/Discrete Transfer Fcn1' */
    Quaternion_controller_DW.DiscreteTransferFcn1_states[2] =
      Quaternion_controller_P.DiscreteTransferFcn1_InitialSta;

    /* InitializeConditions for Memory: '<Root>/Memory' */
    Quaternion_controller_DW.Memory_PreviousInput[3] =
      Quaternion_controller_P.Memory_InitialCondition;

    /* InitializeConditions for DiscreteTransferFcn: '<S4>/Discrete Transfer Fcn1' */
    Quaternion_controller_DW.DiscreteTransferFcn1_states[3] =
      Quaternion_controller_P.DiscreteTransferFcn1_InitialSta;

    /* InitializeConditions for DiscreteFir: '<Root>/Discrete FIR Filter1' */
    Quaternion_controller_DW.DiscreteFIRFilter1_circBuf = 0;
    for (i = 0; i < 12; i++) {
      /* InitializeConditions for DiscreteFir: '<Root>/Discrete FIR Filter' */
      Quaternion_controller_DW.DiscreteFIRFilter_states[i] =
        Quaternion_controller_P.DiscreteFIRFilter_InitialStates;

      /* InitializeConditions for DiscreteFir: '<Root>/Discrete FIR Filter1' */
      Quaternion_controller_DW.DiscreteFIRFilter1_states[i] =
        Quaternion_controller_P.DiscreteFIRFilter1_InitialState;
    }

    /* InitializeConditions for DiscreteFir: '<Root>/Discrete FIR Filter2' */
    Quaternion_controller_DW.DiscreteFIRFilter2_circBuf = 0;
    for (i = 0; i < 19; i++) {
      Quaternion_controller_DW.DiscreteFIRFilter2_states[i] =
        Quaternion_controller_P.DiscreteFIRFilter2_InitialState;
    }

    /* End of InitializeConditions for DiscreteFir: '<Root>/Discrete FIR Filter2' */

    /* SystemInitialize for Merge: '<S13>/Merge' */
    Quaternion_controller_B.Merge[0] =
      Quaternion_controller_P.Merge_InitialOutput[0];
    Quaternion_controller_B.Merge[1] =
      Quaternion_controller_P.Merge_InitialOutput[1];
    Quaternion_controller_B.Merge[2] =
      Quaternion_controller_P.Merge_InitialOutput[2];
    Quaternion_controller_B.Merge[3] =
      Quaternion_controller_P.Merge_InitialOutput[3];
  }
}

/* Model terminate function */
void Quaternion_controller_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

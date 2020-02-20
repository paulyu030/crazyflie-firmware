/*
 * File: thrust_test.c
 *
 * Code generated for Simulink model 'thrust_test'.
 *
 * Model version                  : 1.3
 * Simulink Coder version         : 8.14 (R2018a) 06-Feb-2018
 * C/C++ source code generated on : Wed Feb 19 18:17:55 2020
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#include "thrust_test.h"

/* External inputs (root inport signals with default storage) */
ExtU rtU;

/* External outputs (root outports fed by signals with default storage) */
ExtY rtY;

/* Model step function */
void thrust_test_step(void)
{
  uint16_T rtb_DataTypeConversion;

  /* Saturate: '<Root>/Saturation' incorporates:
   *  Inport: '<Root>/thrust'
   */
  if (rtU.thrust > 65535.0F) {
    /* DataTypeConversion: '<Root>/Data Type Conversion' */
    rtb_DataTypeConversion = MAX_uint16_T;
  } else if (rtU.thrust < 0.0F) {
    /* DataTypeConversion: '<Root>/Data Type Conversion' */
    rtb_DataTypeConversion = 0U;
  } else {
    /* DataTypeConversion: '<Root>/Data Type Conversion' */
    rtb_DataTypeConversion = (uint16_T)rtU.thrust;
  }

  /* End of Saturate: '<Root>/Saturation' */

  /* Outport: '<Root>/M1_output' */
  rtY.M1_output = rtb_DataTypeConversion;

  /* Outport: '<Root>/M2_output' */
  rtY.M2_output = rtb_DataTypeConversion;

  /* Outport: '<Root>/M3_output' */
  rtY.M3_output = rtb_DataTypeConversion;

  /* Outport: '<Root>/M4_output' */
  rtY.M4_output = rtb_DataTypeConversion;
}

/* Model initialize function */
void thrust_test_initialize(void)
{
  /* (no initialization code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

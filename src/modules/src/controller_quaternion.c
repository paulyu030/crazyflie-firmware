#define DEBUG_MODULE "Quaternion"

#include "stabilizer.h"
#include "stabilizer_types.h"

// #include "attitude_controller.h"
#include "sensfusion6.h"
// #include "position_controller.h"
#include "controller_quaternion.h"
#include "Quaternion_single_axis_controller.h"
#include "debug.h"

#include "motors.h"
#include "log.h"
#include "param.h"

#define ATTITUDE_UPDATE_DT    (float)(1.0f/ATTITUDE_RATE)

// int qcounter = 0;

void controllerQuaternionInit(void)
{
  Quaternion_single_axis_controller_initialize();
}

bool controllerQuaternionTest(void)
{
  return true;
}

void controllerQuaternion(control_t *control, setpoint_t *setpoint,
                                         const sensorData_t *sensors,
                                         const state_t *state,
                                         const uint32_t tick)
{
  Quaternion_single_axis_contro_U.base_w = setpoint->attitudeQuaternion.w;
  Quaternion_single_axis_contro_U.base_x = setpoint->attitudeQuaternion.x;
  Quaternion_single_axis_contro_U.base_y = setpoint->attitudeQuaternion.y;
  Quaternion_single_axis_contro_U.base_z = setpoint->attitudeQuaternion.z;

  Quaternion_single_axis_contro_U.qw = state->attitudeQuaternion.w;
  Quaternion_single_axis_contro_U.qx = state->attitudeQuaternion.x;
  Quaternion_single_axis_contro_U.qy = -state->attitudeQuaternion.y;
  Quaternion_single_axis_contro_U.qz = -state->attitudeQuaternion.z;

  Quaternion_single_axis_contro_U.index = setpoint->attitude.roll;
  Quaternion_single_axis_contro_U.theta = setpoint->attitude.pitch;
  Quaternion_single_axis_contro_U.mx = setpoint->attitude.yaw;
  Quaternion_single_axis_contro_U.thrust = setpoint->thrust;
  Quaternion_single_axis_contro_U.q = sensors->gyro.y;

  Quaternion_single_axis_controller_step();

  // if(qcounter > 500){
  //   // DEBUG_PRINT("roll_output: %f\tpitch_output: %f\tyaw_output: %f\tthrust_output: %f\n", (double)Quaternion_controller_Y.roll_output, 
  //   //                                                                                       (double)Quaternion_controller_Y.pitch_output, 
  //   //                                                                                       (double)Quaternion_controller_Y.yaw_output, 
  //   //                                                                                       (double)Quaternion_controller_Y.thrust_output);
  //   // DEBUG_PRINT("qw: %f\tqx: %f\tqy: %f\tqz: %f\n", (double)state->attitudeQuaternion.w, 
  //   //                                                 (double)state->attitudeQuaternion.x, 
  //   //                                                 (double)state->attitudeQuaternion.y, 
  //   //                                                 (double)state->attitudeQuaternion.z);
  //   // DEBUG_PRINT("thrust: %f\n", (double)Quaternion_single_axis_contro_Y.theta_meas);
  //   qcounter = 0;
  // }
  // else
  // {
  //   qcounter++;
  // }
  if ((double)setpoint->thrust < 0.0001)
  {
    motorsSetRatio(0, 0);
    motorsSetRatio(1, 0);
    motorsSetRatio(2, 0);
    motorsSetRatio(3, 0);    
  }
  else
  {
    motorsSetRatio(0, Quaternion_single_axis_contro_Y.M1_output);
    motorsSetRatio(1, Quaternion_single_axis_contro_Y.M2_output);
    motorsSetRatio(2, Quaternion_single_axis_contro_Y.M3_output);
    motorsSetRatio(3, Quaternion_single_axis_contro_Y.M4_output);  
  }
}


LOG_GROUP_START(Q_att)
LOG_ADD(LOG_FLOAT, theta, &Quaternion_single_axis_contro_U.theta)
LOG_ADD(LOG_FLOAT, thrust,&Quaternion_single_axis_contro_U.thrust)
LOG_ADD(LOG_FLOAT, theta_meas,    &Quaternion_single_axis_contro_Y.theta_meas)
LOG_ADD(LOG_FLOAT, gyroy, &Quaternion_single_axis_contro_U.q)
LOG_ADD(LOG_FLOAT, my, &Quaternion_single_axis_contro_Y.my)
LOG_GROUP_STOP(Q_att)

PARAM_GROUP_START(Q_att)
PARAM_ADD(PARAM_FLOAT, pitch_P, &Quaternion_single_axis_contro_P.pitch_P)
PARAM_ADD(PARAM_FLOAT, pitch_rP, &Quaternion_single_axis_contro_P.pitch_rate_P)
PARAM_ADD(PARAM_FLOAT, pitch_rI, &Quaternion_single_axis_contro_P.pitch_rate_I)
PARAM_ADD(PARAM_FLOAT, pitch_rD, &Quaternion_single_axis_contro_P.pitch_rate_D)
// PARAM_ADD(PARAM_FLOAT, index, &Quaternion_single_axis_contro_P.index)
PARAM_GROUP_STOP(Q_att)

// PARAM_GROUP_START(Quaternion_rate)
// PARAM_ADD(PARAM_FLOAT, roll_kp, &Quaternion_controller_P.roll_rate_P_Gain)
// PARAM_ADD(PARAM_FLOAT, roll_ki, &Quaternion_controller_P.roll_rate_I_Gain)
// PARAM_ADD(PARAM_FLOAT, roll_kd, &Quaternion_controller_P.roll_rate_D_Gain)
// PARAM_ADD(PARAM_FLOAT, pitch_kp, &Quaternion_controller_P.pitch_rate_P_Gain)
// PARAM_ADD(PARAM_FLOAT, pitch_ki, &Quaternion_controller_P.pitch_rate_I_Gain)
// PARAM_ADD(PARAM_FLOAT, pitch_kd, &Quaternion_controller_P.pitch_rate_D_Gain)
// PARAM_ADD(PARAM_FLOAT, yaw_kp, &Quaternion_controller_P.yaw_rate_P_Gain)
// PARAM_ADD(PARAM_FLOAT, yaw_ki, &Quaternion_controller_P.yaw_rate_I_Gain)
// PARAM_ADD(PARAM_FLOAT, yaw_kd, &Quaternion_controller_P.yaw_rate_D_Gain)
// PARAM_GROUP_STOP(Quaternion_rate)
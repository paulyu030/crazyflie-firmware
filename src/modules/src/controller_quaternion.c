#define DEBUG_MODULE "Quaternion"

#include "stabilizer.h"
#include "stabilizer_types.h"

// #include "attitude_controller.h"
#include "sensfusion6.h"
// #include "position_controller.h"
#include "controller_quaternion.h"
#include "Quaternion_controller.h"
#include "debug.h"

#include "log.h"
#include "param.h"

#define ATTITUDE_UPDATE_DT    (float)(1.0f/ATTITUDE_RATE)

int qcounter = 0;

void controllerQuaternionInit(void)
{
  Quaternion_controller_initialize();
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
  Quaternion_controller_U.ay = setpoint->attitude.roll;
  Quaternion_controller_U.ax = setpoint->attitude.pitch;   
  Quaternion_controller_U.yaw_setpoint = setpoint->attitudeRate.yaw;
  Quaternion_controller_U.az = -setpoint->thrust;

  Quaternion_controller_U.qw = state->attitudeQuaternion.w;
  Quaternion_controller_U.qx = state->attitudeQuaternion.x;
  Quaternion_controller_U.qy = state->attitudeQuaternion.y;
  Quaternion_controller_U.qz = state->attitudeQuaternion.z;

  Quaternion_controller_U.p = sensors->gyro.x;
  Quaternion_controller_U.q = -sensors->gyro.y;
  Quaternion_controller_U.r = sensors->gyro.z;

  Quaternion_controller_step();

  // if(qcounter > 500){
  //   DEBUG_PRINT("yaw_input: %f\n", (double)setpoint->attitudeRate.yaw);
  //   DEBUG_PRINT("yaw_output: %f\n", (double)-Quaternion_controller_Y.yaw_output);
  //   qcounter = 0;
  // }
  // else
  // {
  //   qcounter++;
  // }
  if (Quaternion_controller_Y.thrust_output < 100)
  {
    control->roll = 0;
    control->pitch = 0;
    control->yaw = 0;
    control->thrust = 0;    
  }
  else
  {
    control->roll = Quaternion_controller_Y.roll_output;
    control->pitch = Quaternion_controller_Y.pitch_output;
    control->yaw = -Quaternion_controller_Y.yaw_output;
    control->thrust = Quaternion_controller_Y.thrust_output;
  }
}


LOG_GROUP_START(controller)
LOG_ADD(LOG_FLOAT, actuatorThrust, &Quaternion_controller_Y.thrust_output)
LOG_ADD(LOG_FLOAT, roll,      &Quaternion_controller_Y.roll_output)
LOG_ADD(LOG_FLOAT, pitch,     &Quaternion_controller_Y.pitch_output)
LOG_ADD(LOG_FLOAT, yaw,       &Quaternion_controller_Y.yaw_output)
// LOG_ADD(LOG_FLOAT, rollRate,  &rateDesired.roll)
// LOG_ADD(LOG_FLOAT, pitchRate, &rateDesired.pitch)
// LOG_ADD(LOG_FLOAT, yawRate,   &rateDesired.yaw)
LOG_GROUP_STOP(controller)

// LOG_GROUP_START(Quaternion_attitude)
// LOG_ADD(LOG_FLOAT, roll_outP, &QuaternionRoll.outP)
// LOG_ADD(LOG_FLOAT, roll_outI, &QuaternionRoll.outI)
// LOG_ADD(LOG_FLOAT, roll_outD, &QuaternionRoll.outD)
// LOG_ADD(LOG_FLOAT, pitch_outP, &QuaternionPitch.outP)
// LOG_ADD(LOG_FLOAT, pitch_outI, &QuaternionPitch.outI)
// LOG_ADD(LOG_FLOAT, pitch_outD, &QuaternionPitch.outD)
// LOG_ADD(LOG_FLOAT, yaw_outP, &QuaternionYaw.outP)
// LOG_ADD(LOG_FLOAT, yaw_outI, &QuaternionYaw.outI)
// LOG_ADD(LOG_FLOAT, yaw_outD, &QuaternionYaw.outD)
// LOG_GROUP_STOP(Quaternion_attitude)

// LOG_GROUP_START(Quaternion_rate)
// LOG_ADD(LOG_FLOAT, roll_outP, &QuaternionRollRate.outP)
// LOG_ADD(LOG_FLOAT, roll_outI, &QuaternionRollRate.outI)
// LOG_ADD(LOG_FLOAT, roll_outD, &QuaternionRollRate.outD)
// LOG_ADD(LOG_FLOAT, pitch_outP, &QuaternionPitchRate.outP)
// LOG_ADD(LOG_FLOAT, pitch_outI, &QuaternionPitchRate.outI)
// LOG_ADD(LOG_FLOAT, pitch_outD, &QuaternionPitchRate.outD)
// LOG_ADD(LOG_FLOAT, yaw_outP, &QuaternionYawRate.outP)
// LOG_ADD(LOG_FLOAT, yaw_outI, &QuaternionYawRate.outI)
// LOG_ADD(LOG_FLOAT, yaw_outD, &QuaternionYawRate.outD)
// LOG_GROUP_STOP(Quaternion_rate)

PARAM_GROUP_START(Quaternion_attitude)
PARAM_ADD(PARAM_FLOAT, mass, &Quaternion_controller_P.mass_Gain)
PARAM_ADD(PARAM_FLOAT, K_xi_dot, &Quaternion_controller_P.K_xi_dot_Gain)
PARAM_ADD(PARAM_FLOAT, K_xi, &Quaternion_controller_P.K_xi_Gain)
PARAM_ADD(PARAM_FLOAT, roll_output_gain, &Quaternion_controller_P.roll_output_gain_Gain)
PARAM_ADD(PARAM_FLOAT, pitch_output_gain, &Quaternion_controller_P.pitch_output_gain_Gain)
PARAM_ADD(PARAM_FLOAT, yaw_output_gain, &Quaternion_controller_P.yaw_output_gain_Gain)
PARAM_ADD(PARAM_FLOAT, thrust_output_gain, &Quaternion_controller_P.thrust_output_gain_Gain)
PARAM_GROUP_STOP(Quaternion_attitude)

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
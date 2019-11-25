#define DEBUG_MODULE "PID"

#include "stabilizer.h"
#include "stabilizer_types.h"

// #include "attitude_controller.h"
#include "sensfusion6.h"
// #include "position_controller.h"
#include "controller_pid.h"
#include "PID_controller.h"
#include "debug.h"

#include "log.h"
#include "param.h"

#define ATTITUDE_UPDATE_DT    (float)(1.0f/ATTITUDE_RATE)

int acounter = 0;

void controllerPidInit(void)
{
  PID_controller_initialize();
}

bool controllerPidTest(void)
{
  return true;
}

void controllerPid(control_t *control, setpoint_t *setpoint,
                                         const sensorData_t *sensors,
                                         const state_t *state,
                                         const uint32_t tick)
{
  PID_controller_U.roll_setpoint = setpoint->attitude.roll;
  PID_controller_U.pitch_setpoint = setpoint->attitude.pitch;   
  // PID_controller_U.yaw_setpoint = setpoint->attitude.yaw;
  PID_controller_U.yaw_setpoint = setpoint->attitudeRate.yaw;
  PID_controller_U.thrust = setpoint->thrust;

  PID_controller_U.roll_sensor = state->attitude.roll; 
  PID_controller_U.pitch_sensor = state->attitude.pitch;     
  PID_controller_U.yaw_sensor = state->attitude.yaw;

  PID_controller_U.roll_rate_sensor = sensors->gyro.x;
  PID_controller_U.pitch_rate_sensor = -sensors->gyro.y;
  PID_controller_U.yaw_rate_sensor = sensors->gyro.z;

  PID_controller_step();

  if(acounter > 500){
    DEBUG_PRINT("yaw_input: %f\n", (double)setpoint->attitudeRate.yaw);
    DEBUG_PRINT("yaw_output: %f\n", (double)-PID_controller_Y.yaw_output);
    acounter = 0;
  }
  else
  {
    acounter++;
  }
  if (PID_controller_Y.thrust_output < 100)
  {
    control->roll = 0;
    control->pitch = 0;
    control->yaw = 0;
    control->thrust = 0;    
  }
  else
  {
    control->roll = PID_controller_Y.roll_output;
    control->pitch = PID_controller_Y.pitch_output;
    control->yaw = -PID_controller_Y.yaw_output;
    control->thrust = PID_controller_Y.thrust_output;
  }
}


LOG_GROUP_START(controller)
LOG_ADD(LOG_FLOAT, actuatorThrust, &PID_controller_Y.thrust_output)
LOG_ADD(LOG_FLOAT, roll,      &PID_controller_Y.roll_output)
LOG_ADD(LOG_FLOAT, pitch,     &PID_controller_Y.pitch_output)
LOG_ADD(LOG_FLOAT, yaw,       &PID_controller_Y.yaw_output)
// LOG_ADD(LOG_FLOAT, rollRate,  &rateDesired.roll)
// LOG_ADD(LOG_FLOAT, pitchRate, &rateDesired.pitch)
// LOG_ADD(LOG_FLOAT, yawRate,   &rateDesired.yaw)
LOG_GROUP_STOP(controller)

// PARAM_GROUP_START(controller)
// PARAM_ADD(PARAM_UINT8, tiltComp, &tiltCompensationEnabled)
// PARAM_GROUP_STOP(controller)

// LOG_GROUP_START(pid_attitude)
// LOG_ADD(LOG_FLOAT, roll_outP, &pidRoll.outP)
// LOG_ADD(LOG_FLOAT, roll_outI, &pidRoll.outI)
// LOG_ADD(LOG_FLOAT, roll_outD, &pidRoll.outD)
// LOG_ADD(LOG_FLOAT, pitch_outP, &pidPitch.outP)
// LOG_ADD(LOG_FLOAT, pitch_outI, &pidPitch.outI)
// LOG_ADD(LOG_FLOAT, pitch_outD, &pidPitch.outD)
// LOG_ADD(LOG_FLOAT, yaw_outP, &pidYaw.outP)
// LOG_ADD(LOG_FLOAT, yaw_outI, &pidYaw.outI)
// LOG_ADD(LOG_FLOAT, yaw_outD, &pidYaw.outD)
// LOG_GROUP_STOP(pid_attitude)

// LOG_GROUP_START(pid_rate)
// LOG_ADD(LOG_FLOAT, roll_outP, &pidRollRate.outP)
// LOG_ADD(LOG_FLOAT, roll_outI, &pidRollRate.outI)
// LOG_ADD(LOG_FLOAT, roll_outD, &pidRollRate.outD)
// LOG_ADD(LOG_FLOAT, pitch_outP, &pidPitchRate.outP)
// LOG_ADD(LOG_FLOAT, pitch_outI, &pidPitchRate.outI)
// LOG_ADD(LOG_FLOAT, pitch_outD, &pidPitchRate.outD)
// LOG_ADD(LOG_FLOAT, yaw_outP, &pidYawRate.outP)
// LOG_ADD(LOG_FLOAT, yaw_outI, &pidYawRate.outI)
// LOG_ADD(LOG_FLOAT, yaw_outD, &pidYawRate.outD)
// LOG_GROUP_STOP(pid_rate)

PARAM_GROUP_START(pid_attitude)
PARAM_ADD(PARAM_FLOAT, roll_kp, &PID_controller_P.roll_P_Gain)
PARAM_ADD(PARAM_FLOAT, roll_ki, &PID_controller_P.roll_I_Gain)
PARAM_ADD(PARAM_FLOAT, pitch_kp, &PID_controller_P.pitch_P_Gain)
PARAM_ADD(PARAM_FLOAT, pitch_ki, &PID_controller_P.pitch_I_Gain)
PARAM_ADD(PARAM_FLOAT, yaw_kp, &PID_controller_P.yaw_P_Gain)
PARAM_ADD(PARAM_FLOAT, yaw_ki, &PID_controller_P.yaw_I_Gain)
PARAM_GROUP_STOP(pid_attitude)

PARAM_GROUP_START(pid_rate)
PARAM_ADD(PARAM_FLOAT, roll_kp, &PID_controller_P.roll_rate_P_Gain)
PARAM_ADD(PARAM_FLOAT, roll_ki, &PID_controller_P.roll_rate_I_Gain)
PARAM_ADD(PARAM_FLOAT, roll_kd, &PID_controller_P.roll_rate_D_Gain)
PARAM_ADD(PARAM_FLOAT, pitch_kp, &PID_controller_P.pitch_rate_P_Gain)
PARAM_ADD(PARAM_FLOAT, pitch_ki, &PID_controller_P.pitch_rate_I_Gain)
PARAM_ADD(PARAM_FLOAT, pitch_kd, &PID_controller_P.pitch_rate_D_Gain)
PARAM_ADD(PARAM_FLOAT, yaw_kp, &PID_controller_P.yaw_rate_P_Gain)
PARAM_ADD(PARAM_FLOAT, yaw_ki, &PID_controller_P.yaw_rate_I_Gain)
PARAM_ADD(PARAM_FLOAT, yaw_kd, &PID_controller_P.yaw_rate_D_Gain)
PARAM_GROUP_STOP(pid_rate)
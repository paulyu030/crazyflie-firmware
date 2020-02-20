#define DEBUG_MODULE "Thrust"

#include "stabilizer.h"
#include "stabilizer_types.h"

// #include "attitude_controller.h"
#include "sensfusion6.h"
// #include "position_controller.h"
#include "controller_thrust.h"
#include "thrust_test.h"
#include "debug.h"
#include "motors.h"

#include "log.h"
#include "param.h"

#define ATTITUDE_UPDATE_DT    (float)(1.0f/ATTITUDE_RATE)


void controllerThrustInit(void)
{
  thrust_test_initialize();
}

bool controllerThrustTest(void)
{
  return true;
}

void controllerThrust(control_t *control, setpoint_t *setpoint,
                                         const sensorData_t *sensors,
                                         const state_t *state,
                                         const uint32_t tick)
{
  rtU.thrust = setpoint->thrust;


  thrust_test_step();

  if (setpoint->thrust < 10)
  {
    motorsSetRatio(0, 0);
    motorsSetRatio(1, 0);
    motorsSetRatio(2, 0);
    motorsSetRatio(3, 0);    
  }
  else
  {
    motorsSetRatio(0, rtY.M1_output);
    motorsSetRatio(1, rtY.M2_output);
    motorsSetRatio(2, rtY.M3_output);
    motorsSetRatio(3, rtY.M4_output);  
  }
}


LOG_GROUP_START(controller)
LOG_ADD(LOG_FLOAT, M1, &rtY.M1_output)
LOG_ADD(LOG_FLOAT, M2, &rtY.M2_output)
LOG_ADD(LOG_FLOAT, M3, &rtY.M3_output)
LOG_ADD(LOG_FLOAT, M4, &rtY.M4_output)
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

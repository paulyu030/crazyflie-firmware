#define DEBUG_MODULE "Thrust"

#include "stabilizer.h"
#include "stabilizer_types.h"

// #include "attitude_controller.h"
#include "sensfusion6.h"
// #include "position_controller.h"
#include "controller_single.h"
#include "single_qc_real.h"
#include "debug.h"
#include "motors.h"

#include "log.h"
#include "param.h"

#define ATTITUDE_UPDATE_DT    (float)(1.0f/ATTITUDE_RATE)


void controllerSingleInit(void)
{
  single_qc_real_initialize();
}

bool controllerSingleTest(void)
{
  return true;
}

void controllerSingle(control_t *control, setpoint_t *setpoint,
                                         const sensorData_t *sensors,
                                         const state_t *state,
                                         const uint32_t tick)
{
  single_qc_real_U.index = setpoint->attitude.roll;

  single_qc_real_U.qw_op = setpoint->attitudeQuaternion.w;
  single_qc_real_U.qx_op = setpoint->attitudeQuaternion.x;
  single_qc_real_U.qy_op = setpoint->attitudeQuaternion.y;
  single_qc_real_U.qz_op = setpoint->attitudeQuaternion.z;

  single_qc_real_U.qw_IMU = state->attitudeQuaternion.w;
  single_qc_real_U.qx_IMU = state->attitudeQuaternion.x;
  single_qc_real_U.qy_IMU = state->attitudeQuaternion.y;
  single_qc_real_U.qz_IMU = state->attitudeQuaternion.z;

  single_qc_real_U.alpha_desired = setpoint->attitude.pitch;
  single_qc_real_U.beta_desired = setpoint->attitude.yaw;

  single_qc_real_U.thrust = setpoint->thrust;

  single_qc_real_step();

  if (setpoint->thrust < 100)
  {
    motorsSetRatio(0, 0);
    motorsSetRatio(1, 0);
    motorsSetRatio(2, 0);
    motorsSetRatio(3, 0);    
  }
  else
  {
    motorsSetRatio(0, single_qc_real_Y.m1);
    motorsSetRatio(1, single_qc_real_Y.m2);
    motorsSetRatio(2, single_qc_real_Y.m3);
    motorsSetRatio(3, single_qc_real_Y.m4);  
  }
}


LOG_GROUP_START(controller)
LOG_ADD(LOG_FLOAT, M1, &single_qc_real_Y.m1)
LOG_ADD(LOG_FLOAT, M2, &single_qc_real_Y.m2)
LOG_ADD(LOG_FLOAT, M3, &single_qc_real_Y.m3)
LOG_ADD(LOG_FLOAT, M4, &single_qc_real_Y.m4)
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

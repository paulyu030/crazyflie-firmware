#define DEBUG_MODULE "Single"

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

  single_qc_real_U.qw_op = setpoint->attitudeQuaternion.w; //1
  single_qc_real_U.qx_op = setpoint->attitudeQuaternion.x; //0
  single_qc_real_U.qy_op = setpoint->attitudeQuaternion.y; //0
  single_qc_real_U.qz_op = setpoint->attitudeQuaternion.z; //0

  single_qc_real_U.qw_IMU = state->attitudeQuaternion.w;
  single_qc_real_U.qx_IMU = state->attitudeQuaternion.x;
  single_qc_real_U.qy_IMU = state->attitudeQuaternion.y;
  single_qc_real_U.qz_IMU = state->attitudeQuaternion.z;

  single_qc_real_U.alpha_desired = setpoint->attitude.pitch; // desired tau_x
  single_qc_real_U.beta_desired = setpoint->attitude.yaw; // no meaning

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


// log/param name can't be too long, otherwise error
// only one log group is allowed

LOG_GROUP_START(sctrl)

LOG_ADD(LOG_FLOAT, t_be, &single_qc_real_Y.t_betae)
LOG_ADD(LOG_FLOAT, t_ae, &single_qc_real_Y.t_alphae)

LOG_ADD(LOG_FLOAT, t_m1, &single_qc_real_Y.t_m1)
LOG_ADD(LOG_FLOAT, t_m2, &single_qc_real_Y.t_m2)
LOG_ADD(LOG_FLOAT, t_m3, &single_qc_real_Y.t_m3)
LOG_ADD(LOG_FLOAT, t_m4, &single_qc_real_Y.t_m4)

LOG_GROUP_STOP(sctrl)


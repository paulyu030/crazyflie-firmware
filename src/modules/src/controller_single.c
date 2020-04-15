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

static float pgaina = 1e-3;
static float pgainb = 1e-3;
static float igaina = 0;
static float igainb = 0;
static float dgaina = 0;
static float dgainb = 0;
static float torque_modifier = 0;


void controllerSingleInit(void)
{
  single_qc_real_P.pgaina = pgaina;
  single_qc_real_P.pgainb = pgainb;
  single_qc_real_P.igaina = igaina;
  single_qc_real_P.igainb = igainb;
  single_qc_real_P.dgaina = dgaina;
  single_qc_real_P.dgainb = dgainb;
  single_qc_real_P.torque_modifier = torque_modifier;
  
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
LOG_GROUP_STOP(controller)

LOG_GROUP_START(ControllerTuning)
LOG_ADD(LOG_FLOAT, error_alpha, &single_qc_real_Y.error_alpha)
LOG_ADD(LOG_FLOAT, error_beta, &single_qc_real_Y.error_beta)
LOG_ADD(LOG_FLOAT, u_alpha, &single_qc_real_Y.u_alpha)
LOG_ADD(LOG_FLOAT, u_beta, &single_qc_real_Y.u_beta)
LOG_GROUP_STOP(ControllerTuning)


PARAM_GROUP_START(ControllerTuningParam)
PARAM_ADD(PARAM_FLOAT, pgaina, &single_qc_real_P.pgaina)
PARAM_ADD(PARAM_FLOAT, pgainb, &single_qc_real_P.pgainb)
PARAM_ADD(PARAM_FLOAT, igaina, &single_qc_real_P.igaina)
PARAM_ADD(PARAM_FLOAT, igainb, &single_qc_real_P.igainb)
PARAM_ADD(PARAM_FLOAT, dgaina, &single_qc_real_P.dgaina)
PARAM_ADD(PARAM_FLOAT, dgainb, &single_qc_real_P.dgainb)
PARAM_ADD(PARAM_FLOAT, torque_modifier, &single_qc_real_P.torque_modifier)
PARAM_GROUP_STOP(ControllerTuningParam)
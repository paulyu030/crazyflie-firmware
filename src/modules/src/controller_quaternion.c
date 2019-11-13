#define DEBUG_MODULE "Quaternion"

#include "stabilizer.h"
#include "stabilizer_types.h"

// #include "attitude_controller.h"
#include "sensfusion6.h"
// #include "position_controller.h"
#include "controller_quaternion.h"
#include "Quaternion_controller.h"
#include "debug.h"
#include "motors.h"

#include "log.h"
#include "param.h"

#define ATTITUDE_UPDATE_DT    (float)(1.0f/ATTITUDE_RATE)

int qcounter = 0;
float gyro_x, gyro_y, gyro_z = 0;

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
  Quaternion_controller_U.ax = -setpoint->attitude.pitch/20;
  Quaternion_controller_U.ay = setpoint->attitude.roll/20;
  Quaternion_controller_U.yaw_setpoint = -setpoint->attitudeRate.yaw/150;
  Quaternion_controller_U.az = -setpoint->thrust/5000-1;

  Quaternion_controller_U.qw = state->attitudeQuaternion.w;
  Quaternion_controller_U.qx = state->attitudeQuaternion.x;
  Quaternion_controller_U.qy = -state->attitudeQuaternion.y;
  Quaternion_controller_U.qz = -state->attitudeQuaternion.z;

  Quaternion_controller_U.p = sensors->gyro.x;
  Quaternion_controller_U.q = -sensors->gyro.y;
  Quaternion_controller_U.r = -sensors->gyro.z;

  // gyro_x += sensors->gyro.x;
  // gyro_y += sensors->gyro.y;
  // gyro_z += sensors->gyro.z;

  Quaternion_controller_step();

  if(qcounter > 500){
    // DEBUG_PRINT("qw: %f\tqx: %f\tqy: %f\tqz: %f\n", (double)Quaternion_controller_U.qw, 
    //                                                 (double)Quaternion_controller_U.qx, 
    //                                                 (double)Quaternion_controller_U.qy, 
    //                                                 (double)Quaternion_controller_U.qz);
    // DEBUG_PRINT("m0: %d\tm1: %d\tm2: %d\tm3: %d\n", Quaternion_controller_Y.M1_output, 
    //                                                 Quaternion_controller_Y.M2_output, 
    //                                                 Quaternion_controller_Y.M3_output, 
    //                                                 Quaternion_controller_Y.M4_output);
    DEBUG_PRINT("p: %f\tq: %f\tr: %f\n", (double)Quaternion_controller_U.p, 
                                         (double)Quaternion_controller_U.q, 
                                         (double)Quaternion_controller_U.r);
    // DEBUG_PRINT("az_output: %f\t omega_dot_f:%.2f %.2f %.2f\t mu_f:%f %f %f\t omega_dot_c: %f %f %f\n", (double)Quaternion_controller_U.az,
    //                                                     (double)Quaternion_controller_Y.Omega_dot_f[0],(double)Quaternion_controller_Y.Omega_dot_f[1],(double)Quaternion_controller_Y.Omega_dot_f[2],
    //                                                     (double)Quaternion_controller_Y.mu_f[0],(double)Quaternion_controller_Y.mu_f[1],(double)Quaternion_controller_Y.mu_f[2],
    //                                                     (double)Quaternion_controller_Y.Omega_dot_c[0],(double)Quaternion_controller_Y.Omega_dot_c[1],(double)Quaternion_controller_Y.Omega_dot_c[2]);
    // DEBUG_PRINT("x:%f\ty:%f\tz:%f\n", (double)gyro_x/500,
    //                                   (double)gyro_y/500,
    //                                   (double)gyro_z/500);
    // gyro_x = 0;
    // gyro_y = 0;
    // gyro_z = 0;
    // DEBUG_PRINT("px: %f\tvx: %f\tax: %f\t\n", (double)state->position.x, 
    //                                                 (double)state->velocity.x, 
    //                                                 (double)state->acc.x);
    qcounter = 0;
  }
  else
  {
    qcounter++;
  }
  if (setpoint->thrust < 100)
  {
    motorsSetRatio(0, 0);
    motorsSetRatio(1, 0);
    motorsSetRatio(2, 0);
    motorsSetRatio(3, 0);    
  }
  else
  {
    motorsSetRatio(0, Quaternion_controller_Y.M1_output);
    motorsSetRatio(1, Quaternion_controller_Y.M2_output);
    motorsSetRatio(2, Quaternion_controller_Y.M3_output);
    motorsSetRatio(3, Quaternion_controller_Y.M4_output);  
  }
}


LOG_GROUP_START(controller)
LOG_ADD(LOG_FLOAT, M1, &Quaternion_controller_Y.M1_output)
LOG_ADD(LOG_FLOAT, M2, &Quaternion_controller_Y.M2_output)
LOG_ADD(LOG_FLOAT, M3, &Quaternion_controller_Y.M3_output)
LOG_ADD(LOG_FLOAT, M4, &Quaternion_controller_Y.M4_output)
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

PARAM_GROUP_START(Q_att)
PARAM_ADD(PARAM_FLOAT, mass,      &Quaternion_controller_P.mass)
PARAM_ADD(PARAM_FLOAT, K_xi,      &Quaternion_controller_P.K_xi)
PARAM_ADD(PARAM_FLOAT, K_xi_dot,  &Quaternion_controller_P.K_xi_dot)
PARAM_ADD(PARAM_FLOAT, K_xi_int,  &Quaternion_controller_P.K_xi_int)
// PARAM_ADD(PARAM_FLOAT, length,    &Quaternion_controller_P.length)
PARAM_ADD(PARAM_FLOAT, mu_f_gain, &Quaternion_controller_P.mu_f_gain)
PARAM_ADD(PARAM_FLOAT, omega_dot_f_gain, &Quaternion_controller_P.omega_dot_f_gain)
// PARAM_ADD(PARAM_FLOAT, pitch_gain, &Quaternion_controller_P.pitch_output_gain_Gain)
// PARAM_ADD(PARAM_FLOAT, yaw_gain, &Quaternion_controller_P.yaw_output_gain_Gain)
// PARAM_ADD(PARAM_FLOAT, thrust_gain, &Quaternion_controller_P.thrust_output_gain_Gain)
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
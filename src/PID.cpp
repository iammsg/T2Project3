#include <vector>
#include <cmath>
#include "PID.h"

/**
 * TODO: Complete the PID class. You may add any additional desired functions.
 */

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp_, double Ki_, double Kd_) {
  /**
   * Initialize PID coefficients and errors
   */

  PID::Kp = Kp_;
  PID::Ki = Ki_;
  PID::Kd = Kd_;

  p_error = 0.0;
  i_error = 0.0;
  d_error = 0.0;

  prev_cte = 0.0;
}

void PID::UpdateError(double cte) {
  /**
   * Update PID errors based on cte.
   */

  // Proportional Error
  p_error = cte;

  // Differential Error
  d_error = p_error - prev_cte;
  prev_cte = p_error;

  // Integral Error
  i_error += cte;

}

double PID::TotalError() {
  /**
   * Calculate and return the total error
   */

  double value = -Kp * p_error - Kd * d_error - Ki * i_error;

  return value;  
}
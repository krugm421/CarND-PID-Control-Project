#include "PID.h"
#include <iostream>

/**
 * TODO: Complete the PID class. You may add any additional desired functions.
 */

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp_, double Ki_, double Kd_, char* controllerName_) {
  Kp = Kp_;
  Ki = Ki_;
  Kd = Kd_;
  controllerName = controllerName_;
}

void PID::UpdateError(double cte) {
  // Update PID errors based on cte.
  p_error = cte;
  i_error += cte;
  d_error = cte - cte_prev;

  // Upatate cte
  cte_prev = cte;
}

double PID::TotalError() {
  // Calculate and return the total error
  double p_component = p_error * Kp;
  double i_component = i_error * Ki;
  double d_component = d_error * Kd;
  std::cout << controllerName << " - P: " << p_component << " I: " << i_component << " D: " << d_component <<  std::endl;

  return -(p_component + i_component + d_component); 
}
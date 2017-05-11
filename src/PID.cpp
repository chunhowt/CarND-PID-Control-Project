#include "PID.h"

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double new_Kp, double new_Ki, double new_Kd) {
  Kp = new_Kp;
  Ki = new_Ki;
  Kd = new_Kd;
}

void PID::UpdateError(double cte) {
  d_error = cte - p_error;
  i_error += cte;
  p_error = cte;
}

double PID::TotalError() {
  return Kp * p_error + Kd * d_error + Ki * i_error;
}

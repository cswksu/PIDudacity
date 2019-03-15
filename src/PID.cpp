#include "PID.h"

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp_, double Ki_, double Kd_) {
  Kp = Kp_;
  Ki = Ki_;
  Kd = Kd_;
  p_error=0;
  i_error=0;
  d_error=0;
  prev_CTE = 0;


}

void PID::UpdateError(double cte) {
  p_error = -cte * Kp;
  i_error -= cte * Ki;
  d_error = -Kd * (cte - prev_CTE);
  prev_CTE = cte;
}

double PID::TotalError() {
  return p_error+i_error+d_error;
}

double PID::getPError() {
  return p_error;
}

double PID::getDError() {
  return d_error;
}

double PID::getIError() {
  return i_error;
}

void PID::setPGain(double p) {
  Kp=p;
}

void PID::setDGain(double d) {
  Kd = d;
}

void PID::setIGain(double i) {
  Ki = i;;
}
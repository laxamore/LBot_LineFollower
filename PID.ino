float lastError;

void PD() {
  error =  sensorError;
  P_Value = kp * error;
  D_Value = (lastError - error) * kd;

  PD_Value = P_Value + D_Value;

  lastError = error;
}

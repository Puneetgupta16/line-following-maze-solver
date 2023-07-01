void PID_control() {
  int error = pos; //0 is the ideal position (the centre)

  P = error;
  I = I + error;
  D = error - lastError;
  lastError = error;
  base_motor_speed_diff = (P*Kp + I*Ki + D*Kd);
  // }
  // Serial.print(pos);
  // Serial.print("      ");
  // Serial.println(base_motor_speed_diff);
}
void PID_control2() {
  int error = pos; //0 is the ideal position (the centre)

  P = error;
  I = I + error;
  D = error - lastError;
  lastError = error;
  base_motor_speed_diff = (P*Kp );
  // }
  // Serial.print(pos);
  // Serial.print("      ");
  // Serial.println(base_motor_speed_diff);
}

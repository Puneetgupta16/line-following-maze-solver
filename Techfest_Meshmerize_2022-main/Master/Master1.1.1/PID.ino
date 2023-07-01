void PID_control() {
  int error = pos; //0 is the ideal position (the centre)

  P = error;
  I = I + error;
  D = error - lastError;
  lastError = error;
  // if(abs(error) >= 20){
  // base_motor_speed_diff = (P*KpAg + I*Ki + D*KdAg);
  // }
  // if(abs(error) <= 20){
  base_motor_speed_diff = (P*Kp + I*Ki + D*Kd);
  // }
  // Serial.print(pos);
  // Serial.print("      ");
  // Serial.println(base_motor_speed_diff);
}

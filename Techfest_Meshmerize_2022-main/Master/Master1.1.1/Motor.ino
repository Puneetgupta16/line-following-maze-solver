// A-> right
// B-> left

void motorInit(){
  pinMode(a1, OUTPUT);
  pinMode(a2, OUTPUT);
  pinMode(apwm, OUTPUT);
  pinMode(b1, OUTPUT);
  pinMode(b2, OUTPUT);
  pinMode(bpwm, OUTPUT);
}

void motorCheck(){
  digitalWrite(a1, HIGH);
  digitalWrite(a2, LOW);
  analogWrite(apwm, 255);
  digitalWrite(b1, HIGH);
  digitalWrite(b2, LOW);
  analogWrite(bpwm, 255);
}

void motorRun(){
  digitalWrite(a1, HIGH);
  digitalWrite(a2, LOW);
  analogWrite(apwm, (int)(base_motor_speed ));
  digitalWrite(b1, HIGH);
  digitalWrite(b2, LOW);
  analogWrite(bpwm, base_motor_speed);
}
void motorStop(){
  digitalWrite(a1, HIGH);
  digitalWrite(a2, LOW);
  analogWrite(apwm, 0);
  digitalWrite(b1, HIGH);
  digitalWrite(b2, LOW);
  analogWrite(bpwm, 0);
}
void motorSpin(){
  digitalWrite(a1, LOW);    //clockwise
  digitalWrite(a2, HIGH);
  analogWrite(apwm, 50) ;
  digitalWrite(b1, HIGH);
  digitalWrite(b2, LOW);
  analogWrite(bpwm, 50);
}
void motorSpinCounterclock(){
  digitalWrite(a1, HIGH);    //counter clockwise
  digitalWrite(a2, LOW);
  analogWrite(apwm, 50);
  digitalWrite(b1, LOW);
  digitalWrite(b2, HIGH);
  analogWrite(bpwm, 50);
}
void motorRunPid(){
  right_motor_speed = base_motor_speed - base_motor_speed_diff;
  left_motor_speed = base_motor_speed + base_motor_speed_diff;

  if (left_motor_speed >= 255) {
  left_motor_speed = 255;
  }
  if (right_motor_speed >= 255) {
  right_motor_speed = 255;
  }
  if (left_motor_speed <= 0) {
  left_motor_speed = 0;
  }
  if (right_motor_speed <= 0) {
  right_motor_speed = 0;
  }
  digitalWrite(a1, HIGH);
  digitalWrite(a2, LOW);
  analogWrite(apwm, right_motor_speed );
  digitalWrite(b1, HIGH);
  digitalWrite(b2, LOW);
  analogWrite(bpwm, left_motor_speed );
}
// void ledPathMotorSpeedCheck(){
//   if(led_path[0]<=led_path_cutoff){
//     base_motor_speed = 0;
//   }
//   else {
//     base_motor_speed = motor_set_speed;
//   }
//   if(led_path[2]<=led_path_cutoff){
//   base_motor_speed = 0;
//   }
//   else {
//   base_motor_speed = motor_set_speed;
//   }
// }
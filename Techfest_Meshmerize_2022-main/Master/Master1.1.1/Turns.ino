void straight(){
  // digitalWrite(a1, HIGH);
  // digitalWrite(a2, LOW);
  // analogWrite(apwm, (int)(base_motor_speed ));
  // digitalWrite(b1, HIGH);
  // digitalWrite(b2, LOW);
  // analogWrite(bpwm, base_motor_speed);
  // delay(del_straight);
  // digitalWrite(13, LOW);

}
void left(){
  brake();
  delay(700);
// retrace();
// delay(200);
  digitalWrite(a1, HIGH);
  digitalWrite(a2, LOW);
  analogWrite(apwm, 55);
  digitalWrite(b1, LOW);
  digitalWrite(b2, HIGH);
  analogWrite(bpwm, 25);
  delay(600);
  brake();
  delay(700);
  motorRunPid();
}
void moveLeft(){
  digitalWrite(a1, HIGH);
  digitalWrite(a2, LOW);
  analogWrite(apwm, 55);
  digitalWrite(b1, HIGH);
  digitalWrite(b2, LOW);
  analogWrite(bpwm, 0);
}
// void left(){
  
//   while(led_path_center==1){ motorRunPid();digitalWrite(13, LOW);ledPathTrigCheck(); }
//     // digitalWrite(13, LOW);
//     brake();
//     delay(700);
//   while(led_path_center==0){
//     moveLeft();
//     ledPathTrigCheck();
//     // digitalWrite(13, LOW);x
//   }
//   brake();
//     delay(700);
//   motorRunPid();
// }
void right(){
  brake();
  delay(700);
// retrace();
// delay(200);
  digitalWrite(a1, LOW);
  digitalWrite(a2, HIGH);
  analogWrite(apwm, 25);
  digitalWrite(b1, HIGH);
  digitalWrite(b2, LOW);
  analogWrite(bpwm, 55);
  delay(600);
  brake();
  delay(700);
  motorRunPid();
}
void back(){
  
}
void checkEndLeft(){
  // delay(del_end);
  // ledPathTrigCheck();
  // if(led_path_left == 1 && led_path_front == 1 && led_path_right == 1 ){    //check end
  //   path = 'E';
  //     while (final_run_var==0) {
  //       digitalWrite(13, HIGH);
  //     }
  //   }
  // else{
  //     path = 'C';left();way[point] = 'L'; point++;
  // }
}
void checkEndRight(){
  // delay(del_end);
  // ledPathTrigCheck();
  // if(led_path_left == 1 && led_path_front == 1 && led_path_right == 1 ){    //check end
  //   path = 'E';
  //     while (final_run_var==0) {
  //       digitalWrite(13, HIGH);
  //     }
  //   }
  // else{
  //     path = 'C';right();way[point] = 'R'; point++;
  // }
}
void brake(){
  digitalWrite(a1, HIGH);
  digitalWrite(a2, LOW);
  analogWrite(apwm, 0);
  digitalWrite(b1, HIGH);
  digitalWrite(b2, LOW);
  analogWrite(bpwm, 0);
}
void retrace(){
  digitalWrite(a1, LOW);
  digitalWrite(a2, HIGH);
  analogWrite(apwm, 50);
  digitalWrite(b1, LOW);
  digitalWrite(b2, HIGH);
  analogWrite(bpwm, 50);
}
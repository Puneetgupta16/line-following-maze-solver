void ledDebugg(){
if(millis()-print_oldtime>=print_time){
    print_oldtime=millis();
    ledShow();
    // ledTriggerShow();
    // Serial.println(pos);
  }
}
void ledShow() {      //Prints LED raw values for debugging
  Serial.print(led[0]);
  Serial.print("    ");
  Serial.print(led[1]);
  Serial.print("    ");
  Serial.print(led[2]);
  Serial.print("    ");
  Serial.print(led[3]);
  Serial.print("    ");
  Serial.print(led[4]);
  Serial.print("    ");
  Serial.print("    ");
  Serial.print("    ");

  Serial.print(led_path[0]);
  Serial.print("    ");
  Serial.print(led_path[1]);
  Serial.print("    ");
  Serial.print(led_path[2]);

  Serial.println();
}
void ledCalShow() {      //Prints LED raw values for debugging
  Serial.print(cal_led_high[0]);
  Serial.print("    ");
  Serial.print(cal_led_high[1]);
  Serial.print("    ");
  Serial.print(cal_led_high[2]);
  Serial.print("    ");
  Serial.print(cal_led_high[3]);
  Serial.print("    ");
  Serial.print(cal_led_high[4]);
  Serial.print("    ");
  Serial.print("    ");
  Serial.print("    ");

  Serial.print(cal_led_low[0]);
  Serial.print("    ");
  Serial.print(cal_led_low[1]);
  Serial.print("    ");
  Serial.print(cal_led_low[2]);
  Serial.print("    ");
  Serial.print(cal_led_low[3]);
  Serial.print("    ");
  Serial.print(cal_led_low[4]);

  Serial.println();
}
void ledPathCalShow() {      //Prints LED raw values for debugging
  Serial.print(cal_led_path_high[0]);
  Serial.print("    ");
  Serial.print(cal_led_path_high[1]);
  Serial.print("    ");
  Serial.print(cal_led_path_high[2]);
  Serial.print("    ");
  Serial.print("    ");
  Serial.print("    ");

  Serial.print(cal_led_path_low[0]);
  Serial.print("    ");
  Serial.print(cal_led_path_low[1]);
  Serial.print("    ");
  Serial.print(cal_led_path_low[2]);

  Serial.println();
}

void ledTriggerShow() {      //Prints LED raw values for debugging
  Serial.print(led_path_left);
  Serial.print("    ");
  Serial.print(led_path_front);
  Serial.print("    ");
  Serial.print(led_path_center);
  Serial.print("    ");
  Serial.print(led_path_right);
  

  Serial.println();
}
void pidDebugg(){
  Serial.print(pos);
  Serial.print("      ");
  Serial.println(base_motor_speed_diff);
}
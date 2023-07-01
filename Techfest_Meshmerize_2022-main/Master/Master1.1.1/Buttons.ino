void buttonInit(){
  pinMode(10,INPUT_PULLUP);   //Blue    calibration button
  pinMode(11,INPUT_PULLUP);   //Red     algo toggle
  pinMode(12,INPUT_PULLUP);   //Yellow  final run button
}

void buttonCheck(){
  if (millis() - button_oldtime >= button_time) {
  // button_oldtime = millis();   //

    if (digitalRead(calibration_pin) == LOW) {
      if(calibrate_done == 0){
        calibrate();
        calibrate_done = 1;
      }
      else {
      calibrate_done = 2;
      }
        button_oldtime = millis();
    }
    if (digitalRead(algo_pin) == LOW) {
        algo_toggle_var = ! algo_toggle_var;
        button_oldtime = millis();
    }
    if (digitalRead(final_run_pin) == LOW) {
        final_run_var = 1; point = 0; digitalWrite(13,LOW);
        button_oldtime = millis();
    }
  }
}

void calibrate(){
  for(int c = 0;c<=4;c++){
   cal_led_high[c] = 0;  
  }
  for(int c = 0;c<=2;c++){
   cal_led_path_high[c] = 0;  
  }
  for(int c = 0;c<=4;c++){
   cal_led_low[c] = 1024;  
  }
  for(int c = 0;c<=2;c++){
   cal_led_path_low[c] = 1024;  
  }
  motorSpin();
  for(int b=0;b<=1200;b++){
  ledCal();
  ledPathCal();
  }
  motorStop();
  ledOffsetAssign();
}
void ledCal(){
  for (int i = 7, j = 0; i >= 3; i--){
    float temp = analogRead(i);
    if(temp > cal_led_high[j]){
    cal_led_high[j] = temp;
    }
    if(temp < cal_led_low[j]){
    cal_led_low[j] = temp;
    }
    j++;
  }
}
void ledPathCal(){
  for (int i = 2, j = 0; i >= 0; i--){
    float temp = analogRead(i);
    if(temp > cal_led_path_high[j]){
    cal_led_path_high[j] = temp;
    }
    if(temp < cal_led_path_low[j]){
    cal_led_path_low[j] = temp;
    }
    j++;
  }
}
void ledOffsetAssign(){
  for(int i;i<=4;i++){
    led_high[i]=cal_led_high[i];
  }
  for(int i;i<=4;i++){
    led_low[i]=cal_led_low[i];
  }
  for(int i;i<=2;i++){
    led_path_high[i]=cal_led_path_high[i];
  }
  for(int i;i<=2;i++){
    led_path_low[i]=cal_led_path_low[i];
  }
}
void ledPathTrigCheck(){
  if(led_path[0]<=led_path_cutoff){
  led_path_left=1;
  }
  else {
  led_path_left=0;
  }
  if(led_path[1]<=led_path_cutoff){
  led_path_front=1;
  }
  else {
  led_path_front=0;
  }
  if(led_path[2]<=led_path_cutoff){
  led_path_right=1;
  }
  else {
  led_path_right=0;
  }
  if(led[2]>=65){
  led_path_center=1;
  }
  else {
  led_path_center=0;
  }
}
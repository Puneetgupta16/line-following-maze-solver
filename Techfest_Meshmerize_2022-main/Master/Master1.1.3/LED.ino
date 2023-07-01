void indicatorInit(){
  pinMode(13, OUTPUT);
}
void ledCheck() {  //Checks current LEDs values also calls saveCheck() and ledMap()
  // for (int i = 2, j = 0; i >= 0; i--){
  for (int i = 7, j = 0; i >= 3; i--){
    led[j] = analogRead(i);
    j++;
  }
  
  // ledMap();
}
void ledPathCheck() {  //Checks current LEDs values also calls saveCheck() and ledMap()
  // for (int i = 7, j = 0; i >= 3; i--){
  for (int i = 2, j = 0; i >= 0; i--){
    led_path[j] = analogRead(i);
    j++;
  }
 
  // ledMap();
}
void ledMap() {     //Maps led values from 0 to 100 according to the LOW and HIGH error
  for (int i = 0; i <= 4; i++) {
    led[i] = ((100 * (led[i] - led_low[i])) / (led_high[i] - led_low[i]));
  }
}
void ledPathMap() {     //Maps led values from 0 to 100 according to the LOW and HIGH error
  for (int i = 0; i <= 2; i++) {
    led_path[i] = ((100 * (led_path[i] - led_path_low[i])) / (led_path_high[i] - led_path_low[i]));
  }
}
void ledSaveLow() {  //save LOW State for Background
  led_low[0] = led[0];
  led_low[1] = led[1];
  led_low[2] = led[2];
  led_low[3] = led[3];
  led_low[4] = led[4];
  Serial.println("Low State Save");
  delay(1000);
}
void ledSaveHigh() {  //save HIGH State for Strip
  led_high[0] = led[0];
  led_high[1] = led[1];
  led_high[2] = led[2];
  led_high[3] = led[3];
  led_high[4] = led[4];
  Serial.println("HIGH State Save");
  delay(1000);
}

void cordCalc() {     //Calculates cordinate of strip left to right ie (0 to 4)

  pos = (float)(-32 * led[0] + -16 * led[1] + -0 * led[2] + 16 * led[3] + 32 * led[4]) / (float)(led[0] + led[1] + led[2] + led[3] + led[4]);  
  // pos = (float)(-1000*(100-led_path[0])+ -32 * led[0] + -16 * led[1] + -0 * led[2] + 16 * led[3] + 32 * led[4]+1000*(100-led_path[2])) / (float)((100-led_path[0])+led[0] + led[1] + led[2] + led[3] + led[4]+(100-led_path[2]));  
}
void ledsUpdate(){
  ledCheck();               //check led array status
  ledMap();
  ledPathCheck();           //check path led status
  ledPathMap();
  cordCalc();               //calculate line coordinate
  ledPathTrigCheck();
}
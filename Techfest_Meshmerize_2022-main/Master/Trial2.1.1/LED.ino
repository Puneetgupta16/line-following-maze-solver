void ledCheck() {  //Checks current LEDs values also calls saveCheck() and ledMap()
  for (int i = 4; i >= 0; i--) {
    led[i] = analogRead(i);
  }
  saveCheck();
  ledMap();
}
void saveCheck() {  //Checks if LED value has to be stored as HIGH or LOW and calls ledSaveLow() and ledSaveHigh() accordingly 
  if (digitalRead(high_Pin) == LOW) {
    ledSaveLow();
  }
  if (digitalRead(low_Pin) == LOW) {
    ledSaveHigh();
  }
}
void ledMap() {     //Maps led values from 0 to 100 according to the LOW and HIGH error
  for (int i = 0; i <= 4; i++) {
    led[i] = ((100 * (led[i] - led_Low[i])) / (led_High[i] - led_Low[i]));
  }
}
void ledSaveLow() {  //save LOW State for Background
  led_Low[0] = led[0];
  led_Low[1] = led[1];
  led_Low[2] = led[2];
  led_Low[3] = led[3];
  led_Low[4] = led[4];
  Serial.println("Low State Save");
  delay(1000);
}
void ledSaveHigh() {  //save HIGH State for Strip
  led_High[0] = led[0];
  led_High[1] = led[1];
  led_High[2] = led[2];
  led_High[3] = led[3];
  led_High[4] = led[4];
  Serial.println("HIGH State Save");
  delay(1000);
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
  Serial.println();
}
void cordCalc() {     //Calculates cordinate of strip left to right ie (0 to 4)
  pos = (float)(-32 * led[0] + -16 * led[1] + -0 * led[2] + 16 * led[3] + 32 * led[4]) / (float)(led[0] + led[1] + led[2] + led[3] + led[4]);
}
void setup() {
  Serial.begin(9600);
  pinMode(10, INPUT_PULLUP);
  pinMode(11, INPUT_PULLUP);
  pinMode(12, INPUT_PULLUP);
}

void loop() {

  Serial.print(digitalRead(10));
  Serial.print("      ");
  Serial.print(digitalRead(11));
  Serial.print("      ");
  Serial.println(digitalRead(12));
}

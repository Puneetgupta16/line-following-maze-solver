void setup() {
  // put your setup code here, to run once:
pinMode(11, OUTPUT);
pinMode(12, OUTPUT);
pinMode(13, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(12, HIGH);
digitalWrite(13, LOW);
analogWrite(11, 255);
}

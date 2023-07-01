void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
Serial.print(analogRead(0));
Serial.print("    ");
Serial.print(analogRead(1));
Serial.print("    ");
Serial.print(analogRead(2));
Serial.print("    ");
Serial.print(analogRead(3));
Serial.print("    ");
Serial.print(analogRead(4));
Serial.print("    ");
Serial.println();


}

#define ENC_IN 2
volatile long encoderValue = 0;

void setup() {
 pinMode(ENC_IN, INPUT_PULLUP); 
  attachInterrupt(digitalPinToInterrupt(ENC_IN), updateEncoder, RISING);
Serial.begin(9600);  
  
}

void loop() {
Serial.println(encoderValue);
}
void updateEncoder()
{
  encoderValue++;
}
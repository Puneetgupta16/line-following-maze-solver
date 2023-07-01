#define high_Pin    8
#define low_Pin   7

float led[5],led_Low[5],led_High[5]={1024,1024,1024,1024,1024};
float pos;

void setup() {
  Serial.begin(9600);
pinMode(7,INPUT_PULLUP);
pinMode(8,INPUT_PULLUP);
}

void loop() {
  

  ledCheck();
  cordCalc();
  if(millis()%100==0){
  // ledShow();
  Serial.println(pos);
  }
}

#define high_Pin    8   //save HIGH state
#define low_Pin   7     //save LOW state

float led[5],led_Low[5],led_High[5]={1024,1024,1024,1024,1024};   //arrays for LED values
float pos;    //value of the line coordinate
unsigned long print_time=0;

void setup() {
  Serial.begin(9600);
  pinMode(7,INPUT_PULLUP);  //LOW State save     /*Switch pin pullups*/  
  pinMode(8,INPUT_PULLUP);  //HIGH State save
}

void loop() {

  ledCheck();               //check led array status
  cordCalc();               //calculate line coordinate

  if(millis()-print_time>=400){
    ledShow();
    // Serial.println(pos);
    print_time=millis();
  }

}

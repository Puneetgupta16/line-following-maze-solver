int IrPin1=2;  //leftSensor
int IrPin2=3;   
int IrPin3=4;
int IrPin4=5;
int IrPin5=6;   //rightSensor
int Sensor[5]={0};  //sensor values left-right
//motor variables
int ENA=7;        //right motor
int input1=8;
int input2=9;
int input3=10;    //left motor
int input4=11;
int ENB=12;       
//led pins
int LedPin=A1;
//PushButtons
int Button1=A2;
int Button2=A3;

char path[100]={};
int pathLength;
int readLength;

void setup() {
  // put your setup code here, to run once:
  pinMode(IrPin1,INPUT);    //IR Pins
  pinMode(IrPin2,INPUT);
  pinMode(IrPin3,INPUT);
  pinMode(IrPin4,INPUT);
  pinMode(IrPin5,INPUT);
  //MotorPins
  pinMode(ENA,OUTPUT);
  pinMode(input1,OUTPUT);
  pinMode(intput2,OUTPUT);
  pinMode(input3,OUTPUT);
  pinMode(input4,OUTPUT);
  pinMode(ENB,OUTPUT);
  analogWrite(ENA,150);
  analogWrite(ENB,150);
  //LED Pins
  pinMode(LedPin,OUTPUT);
  //buttons
  pinMode(Button1,INPUT);
  digitalWrite(Button1,HIGH);
  pinMode(Button2,INPUT);
  digitalWrite(Button2,HIGH);

  Serial.begin(9600);
}

void loop() {
  ReadSensor();
  if(Sensor[0]==0 && Sensor[4]==0 && Sensor[2]==1 || Sensor[1]==1){
    Straight();
  }
  else{
    leftHandWall();
  }
}
void ReadSensor(){
  Sensor[0]=!digitalRead(IrPin1);
  Sensor[1]=!digitalRead(IrPin2);
  Sensor[2]=!digitalRead(IrPin3);
  Sensor[3]=!digitalRead(IrPin4);
  Sensor[4]=!digitalRead(IrPin5);

  Serial.print(Sensor[0]);
  Serial.print(Sensor[1]);
  Serial.print(Sensor[2]);
  Serial.print(Sensor[3]);
  Serial.println(Sensor[4]);
  }

void leftHandWall(){
  
}

void Straight(){
  digitalWrite(input1, HIGH);
  digitalWrite(input2, LOW);
  digitalWrite(intput3,HIGH);
  digitalWrite(input4,LOW);
}
void left(){
  digitalWrite(input1, HIGH);
  digitalWrite(input2, LOW);
  digitalWrite(intput3,LOW);
  digitalWrite(input4,LOW);
}
void right(){
  digitalWrite(input1, LOW);
  digitalWrite(input2, LOW);
  digitalWrite(intput3,HIGH);
  digitalWrite(input4,LOW);
}
void sharp_left(){
  digitalWrite(input1, HIGH);
  digitalWrite(input2, LOW);
  digitalWrite(intput3,LOW);
  digitalWrite(input4,HIGH);
}
void sharp_right(){
  digitalWrite(input1, LOW);
  digitalWrite(input2, HIGH);
  digitalWrite(intput3,HIGH);
  digitalWrite(input4,LOW);
}
void Stop(){
  digitalWrite(input1, LOW);
  digitalWrite(input2, LOW);
  digitalWrite(intput3,LOW);
  digitalWrite(input4,LOW);
}
//motor speed

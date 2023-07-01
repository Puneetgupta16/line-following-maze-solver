// float KpAg = 3;
// float KdAg = 15;
// 80 7 20
// 60 5 13
float Kp = 3;              //change the value by trial-and-error (ex: 0.07).                //PID
float Ki = 0;              //change the value by trial-and-error (ex: 0.0008).
float Kd = 9;              //change the value by trial-and-error (ex: 0.6).
int P,I,D;
int lastError = 0;
int left_motor_speed = 0, right_motor_speed = 0,motor_set_speed = 50 ,base_motor_speed_diff = 0;
int base_motor_speed = motor_set_speed;

unsigned long print_oldtime=0 ,print_time=200;   //time calculations
unsigned long button_oldtime=0 ,button_time=100;

int calibration_pin = 10, algo_pin = 11, final_run_pin = 12;                    //button pins
int calibration_var = 0, calibrate_done = 1, algo_toggle_var = 0, final_run_var=0;    //Button toggle state variable

float led[5],led_low[5]={0,0,0,0,0},led_high[5]={1024,1024,1024,1024,1024};   //arrays for LED values
float pos;    //value of the line coordinate
float led_path[3],led_path_low[3]={0,0,0},led_path_high[3]={1024,1024,1024};
float cal_led_high[5],cal_led_low[5]; float cal_led_path_high[3],cal_led_path_low[3];
int led_path_cutoff = 20;

char path; int point = 0;         //algo array store
char way[100] = {'N','N','N','N','N','N','N','N','N','N','N','N','N','N','N','N','N','N','N','N','N','N','N','N','N','N','N','N','N','N'};

int led_path_left = 0, led_path_right = 0, led_path_front = 0, led_path_center = 0; //turn variables

int a1 = 4, a2 = 5, apwm = 6, b1 = 7, b2 = 8, bpwm = 9;     //motor pins

int del_point = 100, del_end = 100, del_left = 100, del_right = 100 , del_straight = 100 , del_back = 100 ;      //delays

void setup() {
  Serial.begin(9600);
  buttonInit();
  motorInit();
  indicatorInit();
}

void loop() {

  // while (calibrate_done==0) {
  // buttonCheck();
  // }
  buttonCheck();
  ledCheck();               //check led array status
  ledMap();
  ledPathCheck();           //check path led status
  ledPathMap();
  cordCalc();               //calculate line coordinate
  ledPathTrigCheck();
  // ledPathMotorSpeedCheck();
  PID_control();
  if (calibrate_done == 2) {
  motorRunPid();
  pathTrigCheck();
  }
  // ledDebugg();
  // pidDebugg();
}

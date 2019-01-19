#include <LiquidCrystal.h> 
#include <EEPROM.h>

LiquidCrystal lcd(7, 8, A0, A1, A3, A2);

#define OUT1 3
#define OUT2 4
#define OUT3 5
#define OUT4 6

#define PWM1 9
#define PWM2 10

#define muxSelectPin1 2
#define muxSelectPin2 11
#define muxSelectPin3 13

#define muxOutput A4

#define button1 12
#define button2 A6

int sensorVal[8];
int sensorValDigital[8];

int deteksiHitam[8];
int deteksiPutih[8];
int sensorCenterPoint[8];

int kp, kd;
int sensorError;
int error;
float P_Value;
float D_Value;
float PD_Value;

int pwmValue = 150;

String biner = "00000000";

int btn1Val = 0;
int btn2Val = 0;

int lcdMenu = 0;

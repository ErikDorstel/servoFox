#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
Adafruit_PWMServoDriver pwm=Adafruit_PWMServoDriver(0x40);

//int PWMFreq=60; int minServo=100, midServo=350, maxServo=600;
//int PWMFreq=60; int minServo=246, midServo=369, maxServo=492;
//int PWMFreq=50; int minServo=205, midServo=307, maxServo=410;

void initPCA9685() {
  pwm.begin();
  Wire.setClock(400000); }

void setServo(int servoChan,int servoFreq,int servoValue) {
  pwm.setPWMFreq(servoFreq);
  if (servoChan==16) { for (int servo=0;servo<=15;servo++) { pwm.setPWM(servo,0,servoValue); } }
  else { pwm.setPWM(servoChan,0,servoValue); }
  if (debug) { Serial.println("Servo Value " + String(servoValue) + " at " + String(servoFreq) + " Hz on Channel " + String(servoChan) + " written."); } }

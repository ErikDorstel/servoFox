#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
Adafruit_PWMServoDriver pwm40=Adafruit_PWMServoDriver(0x40);
Adafruit_PWMServoDriver pwm41=Adafruit_PWMServoDriver(0x41);

void initPCA9685() {
  pwm40.begin();
  pwm41.begin();
  Wire.setClock(400000); }

void setServo(int servoAddress,int servoChan,int servoFreq,int servoValue) {
  if (servoAddress==64) { pwm40.setPWMFreq(servoFreq);
    if (servoChan==16) { for (int servo=0;servo<=15;servo++) { pwm40.setPWM(servo,0,servoValue); } }
    else { pwm40.setPWM(servoChan,0,servoValue); } }
  if (servoAddress==65) { pwm41.setPWMFreq(servoFreq);
    if (servoChan==16) { for (int servo=0;servo<=15;servo++) { pwm41.setPWM(servo,0,servoValue); } }
    else { pwm41.setPWM(servoChan,0,servoValue); } }
  if (debug) { Serial.println("Servo Value " + String(servoValue) + " at " + String(servoFreq) + " Hz on Channel " + String(servoChan) + " with I2C Address " + String(servoAddress) + " written."); } }

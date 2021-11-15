# servoFox
ESP32 based Servo Tester with WebUI
#### Features
* uses PCA9685 as PWM controller with standard I2C pins and addresses 0x40;0x41
* works as WLAN client and AP (AP chooser included)
* WebUI with IP address 192.168.4.1
* controls all 16 PWM channels of PCA9685
* controls also a single channel
* gives access to the following servo parameters
  * pwm frequency (40 Hz - 500 Hz)
  * pwm pulse width in ms
  * 12 bit pwm pulse value (0 - 4095)
#### I2C bus
* SDA GPIO 21
* SCL GPIO 22
* address 0x40
#### Smartphone Screenshot
![IMAGE ALT TEXT HERE](https://www.dorstel.de/github/servoFox_v1.3.png)

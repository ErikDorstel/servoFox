boolean debug=true;

const char* appName="servoFox";
const char* appDesc="ESP32 Servo Tester";

#include "PCA9685.h"
#include "WLAN.h"
#include "DNS.h"
#include "HTTP.h"

void setup() {
  if (debug) { Serial.begin(115200); }
  initWLAN();
  initDNS();
  initHTTP();
  initPCA9685(); }

void loop() { wlanWorker(); httpWorker(); dnsWorker(); }

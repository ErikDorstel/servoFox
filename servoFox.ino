boolean debug=false;

#include "PCA9685.h"
#include "WLAN.h"
#include "DNS.h"
#include "HTTP.h"

void setup() {
  if (debug) { Serial.begin(115200); }
  initWLAN();
  initPCA9685(); }

void loop() { httpWorker(); dnsWorker(); }

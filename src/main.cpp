#include <Arduino.h>
#include <SoftwareSerial.h>
#include "Write.h"
#include "Serial.h"
#include "Status.h"
#include "Reset.h"
#include "Bluetooth.h"

void setup()
{
    Serial.begin(38400);
    setupReset();
    setupBluetooth();
    restartStatus();
    LAST_STATUS = millis();
    write(0x0A, 0x0A);
}

void loop()
{
    SerialRead();
}
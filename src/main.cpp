#include <Arduino.h>
#include <SoftwareSerial.h>
#include "Write.h"
#include "Serial.h"
#include "Status.h"
#include "Reset.h"
#include "Admin.h"
#include "Bluetooth.h"
#include "TP11.h"
#include "Hopper.h"
#include "CoinAcceptor.h"
#include "XC100.h"

void setup()
{
    Serial.begin(38400);
    setupReset();
    setupAdmin();
    setupTP11();
    setupHopper();
    setupCoinAcceptor();
    setupXC100();
    setupBluetooth();
    restartStatus();
    restartHopper();
    restartCoinAcceptor();
    restartXC100();
    LAST_STATUS = millis();
    write(0x0A, 0x0A);
}

void loop()
{
    SerialRead();
}
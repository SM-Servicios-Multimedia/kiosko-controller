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
#include "Mca1.h"
#include "Close.h"

void setup()
{
    Serial.begin(38400);

    // Setups
    setupReset();
    setupAdmin();
    setupHopper();
    setupCoinAcceptor();
    setupBluetooth();
    SetupLed();

    // Restart Configs
    restartStatus();
    restartHopper();
    restartCoinAcceptor();
    restartAllDevices();

    LAST_STATUS = millis();
    write(0x0A, 0x0A);
}

void loop()
{
    SerialRead();
    delay(50);
}
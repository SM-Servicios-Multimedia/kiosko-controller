#include <Arduino.h>
#include <BLEDevice.h>
#include <BLEServer.h>
#include <BLEUtils.h>
#include <BLE2902.h>
#include "Globals.h"
#include "Write.h"
#include "Bluetooth.h"

void write(byte _device, byte _command)
{
    byte msg[2];
    msg[0] = _device;
    msg[1] = _command;
    Serial.write(msg, 2);
    delay(10);
    writeBluetooth(_device, _command);
}
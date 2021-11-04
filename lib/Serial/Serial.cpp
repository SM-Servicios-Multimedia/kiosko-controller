#include <Arduino.h>
#include "Serial.h"
#include "Write.h"
#include "Globals.h"
#include "Status.h"
#include "Reset.h"
#include "Admin.h"
#include "Bluetooth.h"
#include "TP11.h"
#include "Hopper.h"
#include "XC100.h"
#include "CoinAcceptor.h"

void SerialRead()
{
    byteCommand = 0x00;
    byteAction = 0x00;
    countByte = 0;

    if (Serial.available() > 0)
    {
        while (Serial.available())
        {
            byte byteSerial = Serial.read();

            if (countByte == 0)
            {
                byteCommand = byteSerial;
            }
            else if (countByte == 1)
            {
                byteAction = byteSerial;
            }

            countByte += 1;

            if (debug == true)
            {
                write(byteSerial, byteAction);
            }
        }
    }

    if (byteCommand != 0x00 && byteAction != 0x00)
    {
        readSerialStatus();
        serialReset();
        serialAdmin();
        readSerialTP11();
        readSerialHopper();
        loopSerialCoinAcceptor();
        readSerialXC100();
    }

    if (byteCommandBLE != 0x00 && byteActionBLE != 0x00)
    {
        byteCommand = byteCommandBLE;
        byteAction = byteActionBLE;
        readSerialStatus();
        serialReset();
        serialAdmin();
        readSerialTP11();
        readSerialHopper();
        loopSerialCoinAcceptor();
        readSerialXC100();
    }

    loopStatus();
    loopReset();
    loopAdmin();
    readTP11();
    readXC100();
    loopHopper();
    loopCoinAcceptor();
    loopReadBluetooth();

    if (byteCommandBLE != 0x00 && byteActionBLE != 0x00)
    {
        byteCommandBLE = 0x00;
        byteActionBLE = 0x00;
    }

    delay(10);
}
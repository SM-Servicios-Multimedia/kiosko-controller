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
#include "Mca1.h"
#include "Start.h"

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
        readSerialHopper();
        loopSerialCoinAcceptor();

        // Virtual Serials
        readSerialTP11();
        readSerialXC100();
        readSerialMCA1();
    }

    if (byteCommandBLE != 0x00 && byteActionBLE != 0x00)
    {
        byteCommand = byteCommandBLE;
        byteAction = byteActionBLE;
        readSerialStatus();
        serialReset();
        serialAdmin();
        readSerialHopper();
        loopSerialCoinAcceptor();

        // Virtual Serials
        readSerialTP11();
        readSerialXC100();
        readSerialMCA1();
    }

    loopStatus();
    loopReset();
    loopAdmin();
    loopHopper();
    loopCoinAcceptor();

    // Virtual Serials
    readTP11();
    readXC100();
    readMCA1();

    loopReadBluetooth();
    serialStart();

    if (byteCommandBLE != 0x00 && byteActionBLE != 0x00)
    {
        byteCommandBLE = 0x00;
        byteActionBLE = 0x00;
    }

    delay(10);
}
#include <Arduino.h>
#include "Reset.h"
#include "Globals.h"
#include "Write.h"
#include "Status.h"
#include "TP11.h"
#include "Hopper.h"
#include "CoinAcceptor.h"
#include "XC100.h"
#include "Mca1.h"
#include "TGP58.h"
#include "Close.h"

void setupReset()
{
    pinMode(pin_reset, INPUT_PULLUP);
}

void Reset()
{
    restartStatus();
    restartHopper();
    restartCoinAcceptor();

    // VirtualSerials
    closeTP11();
    closeXC100();
    closeMCA1();
    closeTGP58();

    restartAllDevices();

    delay(300);
}

void loopReset()
{
    if (digitalRead(pin_reset) == LOW)
    {
        LASTRESET = millis();
        int x = 0;
        while (x == 0)
        {
            if (digitalRead(pin_reset) == LOW)
            {
                delay(500);
            }
            else
            {
                x = 1;
            }
        }
        if ((millis() - LASTRESET) >= timeReset)
        {
            write(0x5A, 0x5A);
            Reset();
        }
        LASTRESET = 0;
    }
}

void serialReset()
{
    if (byteCommand == 0x5A && byteAction == 0x50)
    {
        write(0x5A, 0x5A);
        Reset();
        delay(2000);
    }
}

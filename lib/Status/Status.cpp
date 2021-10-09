#include <Arduino.h>
#include "Status.h"
#include "Globals.h"
#include "Write.h"

void readSerialStatus()
{
    if (byteCommand == 0x6A)
    {
        if (byteAction == 0x60)
        {
            CHECK_STATUS = true;
            LAST_STATUS = millis();
            write(0x6A, 0x60);
        }
        else if (byteAction == 0x61)
        {
            CHECK_STATUS = false;
            LAST_STATUS = millis();
            write(0x6A, 0x61);
        }
    }
}

void loopStatus()
{
    if ((millis() - LAST_STATUS) >= 2000 && CHECK_STATUS == true)
    {
        LAST_STATUS = millis();
        write(0x0A, 0x0A);
    }
}

void restartStatus()
{
    CHECK_STATUS = true;
    LAST_STATUS = millis();
}
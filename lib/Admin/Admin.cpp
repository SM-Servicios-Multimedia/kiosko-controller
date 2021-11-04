#include <Arduino.h>
#include "Admin.h"
#include "Globals.h"
#include "Write.h"
#include "Status.h"
#include "TP11.h"
#include "Hopper.h"
#include "CoinAcceptor.h"

void setupAdmin()
{
    pinMode(pin_admin, INPUT_PULLUP);
}

void Admin()
{
    delay(300);
    write(0xAA, 0xAB);
    delay(300);
}

void loopAdmin()
{
    if (digitalRead(pin_admin) == LOW)
    {
        LASTADMIN = millis();
        int x = 0;
        while (x == 0)
        {
            if (digitalRead(pin_admin) == LOW)
            {
                delay(500);
            }
            else
            {
                x = 1;
            }
        }
        if ((millis() - LASTADMIN) >= timeAdmin)
        {
            write(0xAA, 0xAA);
            Admin();
        }
        LASTADMIN = 0;
    }
}

void serialAdmin()
{
    if (byteCommand == 0xAA && byteAction == 0xAA)
    {
        write(0xAA, 0xAA);
        Admin();
    }
}

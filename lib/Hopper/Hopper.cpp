#include <Arduino.h>
#include "Hopper.h"
#include "Globals.h"
#include "Write.h"
#include "Maths.h"

void ICACHE_RAM_ATTR hopper_event();

void setupHopper()
{
    pinMode(pinHopper, INPUT_PULLUP);
    pinMode(relayHopper, OUTPUT);
    digitalWrite(relayHopper, LOW);
}

void startHopper()
{
    LASTIMPULSEHOPPER = millis();
    PULSESHOPPER = 0;
    hopperCoin = true;
    attachInterrupt(digitalPinToInterrupt(pinHopper), hopper_event, RISING);
    digitalWrite(relayHopper, HIGH);
}

void finishHopper()
{
    detachInterrupt(digitalPinToInterrupt(pinHopper));
    digitalWrite(relayHopper, LOW);
    LASTIMPULSEHOPPER = 0;
    PULSESHOPPER = 0;
    numCoinsHopper = 0;
    hopperCoin = false;
}

void hopper_event()
{
    if (hopperCoin == true)
    {

        int lastPulseHopper = PULSESHOPPER;

        if ((millis() - LASTIMPULSEHOPPER) >= timeLimitPulsesHopper && PULSESHOPPER > 0)
        {
            PULSESHOPPER += 1;
            LASTIMPULSEHOPPER = millis();
        }
        else if (PULSESHOPPER == 0)
        {
            PULSESHOPPER += 1;
            LASTIMPULSEHOPPER = millis();
        }

        if (lastPulseHopper != PULSESHOPPER)
        {
            write(0x3A, 0x30);
        }
    }
}

void readSerialHopper()
{
    if (byteCommand == 0x3A)
    {
        if (byteAction == 0x3A)
        {
            finishHopper();
            write(0x3A, 0x3B);
        }
        else
        {
            numCoinsHopper = totalCoins(byteAction);
            startHopper();
            write(0x3A, 0x3A);
        }
    }
}

void loopHopper()
{
    if (hopperCoin == true)
    {
        if (PULSESHOPPER >= numCoinsHopper)
        {
            hopperCoin = false;
            delay(50);
            finishHopper();
        }
        if ((millis() - LASTIMPULSEHOPPER) >= timeWaitHopper)
        {
            hopperCoin = false;
            delay(50);
            finishHopper();
            write(0x3A, 0x3B);
        }
    }
}

void restartHopper()
{
    finishHopper();
}

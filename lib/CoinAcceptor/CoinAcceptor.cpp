#include <Arduino.h>
#include "CoinAcceptor.h"
#include "Write.h"
#include "Globals.h"

void ICACHE_RAM_ATTR coin_event();
void ICACHE_RAM_ATTR coins_inserted();

void setupCoinAcceptor()
{
    pinMode(pinCoinAcceptor, INPUT_PULLUP);
    attachInterrupt(digitalPinToInterrupt(pinCoinAcceptor), coin_event, RISING);
}

void startCoinAcceptor()
{
    LASTIMPULSE = 0;
    PULSES = 0;
    acceptCoin = true;
}

void finishCoinAcceptor()
{
    LASTIMPULSE = 0;
    PULSES = 0;
    acceptCoin = false;
}

void coin_event()
{
    if (acceptCoin == true)
    {
        LASTIMPULSE = millis();
        PULSES += 1;
    }
}

void coins_inserted()
{
    byte byteCoin = 0x00;

    if (PULSES >= 1 && PULSES <= 3)
    {
        byteCoin = 0x72;
    }
    else if (PULSES >= 4 && PULSES <= 6)
    {
        byteCoin = 0x73;
    }
    else if (PULSES >= 7 && PULSES <= 9)
    {
        byteCoin = 0x74;
    }
    else if (PULSES >= 10 && PULSES <= 12)
    {
        byteCoin = 0x75;
    }
    else if (PULSES >= 13 && PULSES <= 15)
    {
        byteCoin = 0x76;
    }
    else if (PULSES >= 16 && PULSES <= 18)
    {
        byteCoin = 0x77;
    }
    else if (PULSES >= 19 && PULSES <= 21)
    {
        byteCoin = 0x78;
    }

    if (byteCoin != 0x00)
    {
        write(0x7A, byteCoin);
    }

    PULSES = 0;
}

void loopSerialCoinAcceptor()
{
    if (byteCommand == 0x7A)
    {
        if (byteAction == 0x70)
        {
            startCoinAcceptor();
            write(0x7A, 0x70);
        }
        else if (byteAction == 0x71)
        {
            finishCoinAcceptor();
            write(0x7A, 0x71);
        }
    }
}

void loopCoinAcceptor()
{
    if (acceptCoin == true)
    {
        if ((millis() - LASTIMPULSE) >= timeLimitPulsesCoin and PULSES > 0)
        {
            cli();
            coins_inserted();
            sei();
        }
    }
}

void restartCoinAcceptor()
{
    LASTIMPULSE = 0;
    PULSES = 0;
    acceptCoin = false;
}
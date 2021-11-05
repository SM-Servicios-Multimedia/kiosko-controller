#include <Arduino.h>
#include "Close.h"
#include "TP11.h"
#include "XC100.h"
#include "Mca1.h"
#include "TGP58.h"
#include "CoinAcceptor.h"
#include "Hopper.h"

void endTP11()
{
    closeTP11();
}

void endXC100()
{
    closeXC100();
}

void endMCA1()
{
    closeMCA1();
}

void endTGP58()
{
    closeTGP58();
}

void endCoinAcceptor()
{
    finishCoinAcceptor();
}

void endHopper()
{
    finishHopper();
}

void closeAllDevices()
{
    endTP11();
    endXC100();
    endMCA1();
    endTGP58();
    finishCoinAcceptor();
    finishHopper();
    openPrinter = false;
}

void restartAllDevices()
{
    closeAllDevices();

    openTP11();
    endTP11();
    delay(150);

    openMCA1();
    endMCA1();
    delay(150);

    openXC100();
    endXC100();
    delay(150);

    openTGP58();
    endTGP58();
    delay(150);

    closeAllDevices();
    delay(150);
}
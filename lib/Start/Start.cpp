#include <Arduino.h>
#include "Start.h"
#include "Globals.h"
#include "Write.h"
#include "TP11.h"
#include "Mca1.h"
#include "XC100.h"
#include "Close.h"
#include "CoinAcceptor.h"
#include "Hopper.h"

void StartMoneyAcceptors()
{
    // Close all devices
    endTP11();
    endMCA1();
    endXC100();
    endTGP58();

    // Open TP11
    openTP11();
    enableTP11();

    // Open MCA1
    openMCA1();
    enableMCA1();

    write(0x1A, 0xA1);
}

void StartDispenserXC100()
{
    // Close all devices
    endTP11();
    endMCA1();
    endXC100();
    endTGP58();

    // Open XC100
    openXC100();

    write(0x1A, 0xB1);
}

void StartPrinterTGP58()
{
    // Close all devices
    endTP11();
    endMCA1();
    endXC100();
    endTGP58();

    // Open TGP58
    // openTGP58();

    write(0x1A, 0xC1);
}

void StopDevices()
{
    endTP11();
    endMCA1();
    endXC100();
    endTGP58();
    finishCoinAcceptor();
    finishHopper();

    write(0x1A, 0x99);
}

void serialStart()
{
    if (byteCommand == 0x1A)
    {
        if (byteAction == 0xA1)
        {
            StartMoneyAcceptors();
        }
        else if (byteAction == 0xB1)
        {
            StartDispenserXC100();
        }
        else if (byteAction == 0xC1)
        {
            StartPrinterTGP58();
        }
        else if (byteAction == 0x99)
        {
            StopDevices();
        }
    }
}

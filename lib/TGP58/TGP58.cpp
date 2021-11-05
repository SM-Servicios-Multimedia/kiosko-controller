#include <Arduino.h>
#include "SoftwareSerial.h"
#include "Globals.h"
#include "Write.h"
#include "TGP58.h"
#include "Close.h"

SoftwareSerial SerialTGP58;
byte byteTGP58 = 0x00;

void readInternalTGP58()
{
    if (statusTGP58 && SerialTGP58.available() > 0)
    {
        while (SerialTGP58.available())
        {
            byteTGP58 = SerialTGP58.read();
        }
    }
}

void openTGP58()
{
    if (!statusTGP58)
    {
        closeAllDevices();
        SerialTGP58.begin(9600, SWSERIAL_8E1, RX_TGP58, TX_TGP58, false, 256);
        statusTGP58 = true;
        openPrinter = true;
        write(0x9A, 0xAA);
    }
}

void closeTGP58()
{
    if (statusTGP58)
    {
        readInternalTGP58();
        readInternalTGP58();
        statusTGP58 = false;
        openPrinter = false;
        SerialTGP58.end();
        closeAllDevices();
        write(0x9A, 0xBB);
    }
}

void readSerialTGP58()
{
    if (byteCommand == 0x9A)
    {
        if (byteAction == 0xAA)
        {
            openTGP58();
        }
        else if (byteAction == 0xBB)
        {
            closeTGP58();
        }
    }
}

void readTGP58()
{
    if (statusTGP58 && SerialTGP58.available() > 0)
    {
        while (SerialTGP58.available())
        {
            byte byteSerial = SerialTGP58.read();
            write(byteSerial);
        }
    }
}

void writeTGP58(byte _byte)
{
    if (statusTGP58)
    {
        SerialTGP58.write(_byte);
    }
}

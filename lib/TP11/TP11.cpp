#include <Arduino.h>
#include "SoftwareSerial.h"
#include "Globals.h"
#include "Write.h"
#include "TP11.h"
#include "Close.h"

SoftwareSerial SerialTP11;

void reloadTP11()
{
    if (statusTP11)
    {
        delay(50);
        SerialTP11.write(0x02);
        delay(50);
        SerialTP11.write(0x3E);
        delay(50);
        SerialTP11.write(0x5E);
        delay(50);
    }
}

void openTP11()
{
    if (!statusTP11)
    {
        endXC100();
        endTGP58();
        SerialTP11.begin(9600, SWSERIAL_8E1, RX_TP11, TX_TP11, false, 256);
        statusTP11 = true;
        reloadTP11();
        write(0x4A, 0xAA);
    }
}

void closeTP11()
{
    if (statusTP11)
    {
        SerialTP11.write(0x30);
        statusTP11 = false;
        SerialTP11.end();
        write(0x4A, 0xBB);
    }
}

void readTP11()
{
    if (statusTP11 && SerialTP11.available() > 0)
    {
        while (SerialTP11.available())
        {
            byte byteSerial = SerialTP11.read();
            if (byteSerial != 0x80 && byteSerial != 0x81)
            {
                if (byteSerial == 0x8F)
                {
                    reloadTP11();
                }
                else
                {
                    write(0x4A, byteSerial);
                }
            }
        }
    }
}

void readSerialTP11()
{
    if (byteCommand == 0x4A)
    {
        if (byteAction == 0xAA)
        {
            openTP11();
        }
        else if (byteAction == 0xBB)
        {
            closeTP11();
        }
        else
        {
            if (statusTP11)
            {
                SerialTP11.write(byteAction);
            }
        }
    }
}

void enableTP11()
{
    if (statusTP11)
    {
        SerialTP11.write(0x3E);
    }
}

void disableTP11()
{
    if (statusTP11)
    {
        SerialTP11.write(0x5E);
    }
}
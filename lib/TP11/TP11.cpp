#include <Arduino.h>
#include "SoftwareSerial.h"
#include "Globals.h"
#include "Write.h"
#include "TP11.h"

SoftwareSerial SerialTP11;

void reloadTP11()
{
    delay(50);
    SerialTP11.write(0x02);
    delay(50);
    SerialTP11.write(0x3E);
    delay(50);
    SerialTP11.write(0x5E);
    delay(50);
}

void setupTP11()
{
    SerialTP11.begin(9600, SWSERIAL_8E1, RX_TP11, TX_TP11, false, 256);
    reloadTP11();
}

void readTP11()
{
    if (SerialTP11.available() > 0)
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
        SerialTP11.write(byteAction);
    }
}

void restartTP11()
{
    SerialTP11.write(0x30);
    delay(150);
    reloadTP11();
}
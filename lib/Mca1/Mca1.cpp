#include <Arduino.h>
#include "SoftwareSerial.h"
#include "Globals.h"
#include "Write.h"
#include "Mca1.h"
#include "Close.h"

SoftwareSerial SerialMCA1;

byte *createCode(byte b0, byte b1, byte b2, byte b3, byte b4)
{
    byte *payload = new byte[5];
    payload[0] = b0;
    payload[1] = b1;
    payload[2] = b2;
    payload[3] = b3;
    payload[4] = b4;
    return payload;
}

byte *createCodeSix(byte b0, byte b1, byte b2, byte b3, byte b4, byte b5)
{
    byte *payload = new byte[6];
    payload[0] = b0;
    payload[1] = b1;
    payload[2] = b2;
    payload[3] = b3;
    payload[4] = b4;
    payload[5] = b5;
    return payload;
}

bool statusRX(byte r[], byte c[])
{
    if (r[0] == c[0] && r[1] == c[1] && r[2] == c[2] && r[3] == c[3] && r[4] == c[4] && r[5] == c[5])
    {
        return true;
    }
    return false;
}

byte *Enable = createCode(0x90, 0x05, 0x01, 0x03, 0x99);
byte *Disable = createCode(0x90, 0x05, 0x02, 0x03, 0x9A);
byte *StatusVMC = createCode(0x90, 0x05, 0x11, 0x03, 0xA9);

// Responses
byte EnableRX[] = {0x90, 0x05, 0x50, 0x03, 0xE8, 0x00};
byte DisableRX[] = {0x90, 0x05, 0x4B, 0x03, 0xE3, 0x00};
byte Channel_1[] = {0x90, 0x06, 0x12, 0x01, 0x03, 0xAC};
byte Channel_2[] = {0x90, 0x06, 0x12, 0x02, 0x03, 0xAD};
byte Channel_3[] = {0x90, 0x06, 0x12, 0x03, 0x03, 0xAE};
byte Channel_4[] = {0x90, 0x06, 0x12, 0x04, 0x03, 0xAF};
byte Idling[] = {0x90, 0x05, 0x11, 0x03, 0xA9, 0x00};
byte DisableVMC[] = {0x90, 0x05, 0x14, 0x03, 0xAC, 0x00};
byte Fishing[] = {0x90, 0x05, 0x17, 0x03, 0xAF, 0x00};
byte ChecksumError[] = {0x90, 0x05, 0x18, 0x03, 0xB0, 0x00};
byte NAK[] = {0x90, 0x05, 0x4B, 0x03, 0xE3, 0x00};
byte Sensor_Problem_COIL_1[] = {0x90, 0x06, 0x16, 0x01, 0x03, 0xB0};
byte Sensor_Problem_COIL_2[] = {0x90, 0x06, 0x16, 0x02, 0x03, 0xB1};
byte Sensor_Problem_DROP_IN_2[] = {0x90, 0x06, 0x16, 0x03, 0x03, 0xB2};
byte Sensor_Problem_DROP_IN_1[] = {0x90, 0x06, 0x16, 0x04, 0x03, 0xB3};
byte Sensor_Problem_COIL_2_1[] = {0x90, 0x06, 0x16, 0x05, 0x03, 0xB4};
byte Sensor_Problem_COIL_2_2[] = {0x90, 0x06, 0x16, 0x06, 0x03, 0xB5};

byte responseBytes[6];
uint countResponseBytes = 0;

void reloadMCA1()
{
    if (statusMCA1)
    {
        SerialMCA1.write(Disable, 5);
        delay(50);
    }
}

void openMCA1()
{
    if (!statusMCA1)
    {
        endXC100();
        endTGP58();
        SerialMCA1.begin(9600, SWSERIAL_8N1, RX_MCA1, TX_MCA1, false, 256);
        statusMCA1 = true;
        reloadMCA1();
        write(0x8A, 0xAA);
    }
}

void closeMCA1()
{
    if (statusMCA1)
    {
        reloadMCA1();
        statusMCA1 = false;
        SerialMCA1.end();
        write(0x8A, 0xBB);
    }
}

void readMCA1()
{
    if (statusMCA1 && SerialMCA1.available() > 0)
    {

        countResponseBytes = 0;

        for (uint i = 0; i < 6; i++)
        {
            responseBytes[i] = 0x00;
        }

        byte byteSerial = 0x00;

        while (SerialMCA1.available() || (byteSerial != 0xE8 && byteSerial != 0xE3 && byteSerial != 0xAC && byteSerial != 0xAD && byteSerial != 0xAE && byteSerial != 0xAF && byteSerial != 0xA9 && byteSerial != 0xAC && byteSerial != 0xAF && byteSerial != 0xB0 && byteSerial != 0xE3 && byteSerial != 0xB0 && byteSerial != 0xB1 && byteSerial != 0xB2 && byteSerial != 0xB3 && byteSerial != 0xB4 && byteSerial != 0xB5))
        {
            if (SerialMCA1.available() > 0)
            {
                byteSerial = SerialMCA1.read();

                responseBytes[countResponseBytes] = byteSerial;
                countResponseBytes++;
            }
        }

        byte Request[] = {responseBytes[0], responseBytes[1], responseBytes[2], responseBytes[3], responseBytes[4], responseBytes[5]};

        if (statusRX(Request, DisableRX))
        {
            write(0x8A, 0x00);
        }
        else if (statusRX(Request, EnableRX))
        {
            write(0x8A, 0x01);
        }
        else if (statusRX(Request, Channel_1))
        {
            write(0x8A, 0xA1);
        }
        else if (statusRX(Request, Channel_2))
        {
            write(0x8A, 0xA2);
        }
        else if (statusRX(Request, Channel_3))
        {
            write(0x8A, 0xA3);
        }
        else if (statusRX(Request, Channel_4))
        {
            write(0x8A, 0xA4);
        }
        else if (statusRX(Request, Idling))
        {
            write(0x8A, 0x02);
        }
        else if (statusRX(Request, DisableVMC))
        {
            write(0x8A, 0x03);
        }
        else if (statusRX(Request, Fishing))
        {
            write(0x8A, 0x04);
        }
        else if (statusRX(Request, ChecksumError))
        {
            write(0x8A, 0x05);
        }
        else if (statusRX(Request, NAK))
        {
            write(0x8A, 0x06);
        }
        else if (statusRX(Request, Sensor_Problem_COIL_1))
        {
            write(0x8A, 0x07);
        }
        else if (statusRX(Request, Sensor_Problem_COIL_2))
        {
            write(0x8A, 0x08);
        }
        else if (statusRX(Request, Sensor_Problem_DROP_IN_2))
        {
            write(0x8A, 0x09);
        }
        else if (statusRX(Request, Sensor_Problem_DROP_IN_1))
        {
            write(0x8A, 0x10);
        }
        else if (statusRX(Request, Sensor_Problem_COIL_2_1))
        {
            write(0x8A, 0x11);
        }
        else if (statusRX(Request, Sensor_Problem_COIL_2_2))
        {
            write(0x8A, 0x12);
        }
    }
}

void readSerialMCA1()
{
    if (byteCommand == 0x8A)
    {
        if (byteAction == 0xAA)
        {
            openMCA1();
        }
        else if (byteAction == 0xBB)
        {
            closeMCA1();
        }
        else
        {
            if (statusMCA1)
            {
                if (byteAction == 0x80) // Disable TX: 90 05 02 03 9A , RX: 90 05 50 03 E8
                {
                    SerialMCA1.write(Disable, 5);
                    write(0x8A, 0x80);
                }
                else if (byteAction == 0x81) // Enable TX: 90 05 01 03 99 , RX: 90 05 50 03 E8
                {
                    SerialMCA1.write(Enable, 5);
                    write(0x8A, 0x81);
                }
                else if (byteAction == 0x82) // Status TX: 90 05 11 03 A9
                {
                    SerialMCA1.write(StatusVMC, 5);
                    write(0x8A, 0x82);
                }
            }
        }
    }
}

void enableMCA1()
{
    if (statusMCA1)
    {
        SerialMCA1.write(Enable, 5);
    }
}

void disableMCA1()
{
    if (statusMCA1)
    {
        SerialMCA1.write(Disable, 5);
    }
}

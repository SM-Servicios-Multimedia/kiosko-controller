#include <Arduino.h>
#include "SoftwareSerial.h"
#include "Globals.h"
#include "Write.h"
#include "XC100.h"
#include "Maths.h"
#include "Close.h"

SoftwareSerial SerialXC100;

uint8_t checksum;
bool statusDispensed = false;
uint clearDispensed = 0;
byte response[11];
uint countResponse = 0;
byte totalByteDispensed = 0x00;

bool errorDispensed = false;
uint countErrors = 0;
uint countDispensed = 0;
uint totalToBeDispensed = 0;
uint countAttempts = 0;
byte totalByteDispensedWithError = 0x00;

byte *createPayload(byte b0, byte b1, byte b2, byte b3, byte b4, byte b5, byte b6, byte b7, byte b8, byte b9)
{
    byte *payload = new byte[10];
    payload[0] = b0;
    payload[1] = b1;
    payload[2] = b2;
    payload[3] = b3;
    payload[4] = b4;
    payload[5] = b5;
    payload[6] = b6;
    payload[7] = b7;
    payload[8] = b8;
    payload[9] = b9;
    return payload;
}

byte *clearPayload()
{
    byte *payload = new byte[3];
    payload[0] = 0x00;
    payload[1] = 0x00;
    payload[2] = 0x00;
    return payload;
}

byte *clearCount = createPayload(0x02, 0x30, 0x30, 0x49, 0x30, 0x30, 0x30, 0x31, 0x6C, 0x03);
byte *clearError = createPayload(0x02, 0x30, 0x30, 0x49, 0x30, 0x30, 0x30, 0x32, 0x6D, 0x03);
byte *clearErrorAndCount = createPayload(0x02, 0x30, 0x30, 0x49, 0x30, 0x30, 0x30, 0x33, 0x6E, 0x03);
byte *keyDisable = createPayload(0x02, 0x30, 0x30, 0x4B, 0x31, 0x30, 0x31, 0x30, 0x6F, 0x03);
byte *keyEnable = createPayload(0x02, 0x30, 0x30, 0x4B, 0x30, 0x30, 0x30, 0x30, 0x6D, 0x03);
byte *Status = createPayload(0x02, 0x30, 0x30, 0x53, 0x30, 0x30, 0x30, 0x30, 0x75, 0x03);
byte *errorRecord = createPayload(0x02, 0x30, 0x30, 0x52, 0x30, 0x30, 0x30, 0x30, 0x74, 0x03);
byte *clearErrorRecord = createPayload(0x02, 0x30, 0x30, 0x55, 0x30, 0x30, 0x30, 0x30, 0x77, 0x03);
byte *totalCount = createPayload(0x02, 0x30, 0x30, 0x43, 0x30, 0x30, 0x30, 0x30, 0x65, 0x03);
byte *passwordEnable = createPayload(0x02, 0x30, 0x30, 0x37, 0x31, 0x30, 0x30, 0x30, 0x5A, 0x03);
byte *passwordDisable = createPayload(0x02, 0x30, 0x30, 0x37, 0x30, 0x30, 0x30, 0x30, 0x59, 0x03);
byte *powerfulOutBill = createPayload(0x02, 0x30, 0x30, 0x36, 0x30, 0x30, 0x30, 0x30, 0x58, 0x03);

uint8_t calculateCS(byte b0, byte b1, byte b2, byte b3, byte b4, byte b5, byte b6, byte b7)
{
    checksum = 0;
    checksum += b0;
    checksum += b1;
    checksum += b2;
    checksum += b3;
    checksum += b4;
    checksum += b5;
    checksum += b6;
    checksum += b7;
    return checksum;
}

uint8_t cs = calculateCS(0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00);

void reloadXC100()
{
    if (statusXC100)
    {
        statusDispensed = false;
        clearDispensed = 1;
        totalByteDispensed = 0x00;
        errorDispensed = false;
        countDispensed = 0;
        totalToBeDispensed = 0;
        countErrors = 0;
        countAttempts = 0;
        autoDispenser = false;
        totalByteDispensedWithError = 0x00;
        SerialXC100.write(clearErrorAndCount, 10);
        SerialXC100.write(clearErrorRecord, 10);
    }
}

void openXC100()
{
    if (!statusXC100)
    {
        endTGP58();
        endTP11();
        endMCA1();
        SerialXC100.begin(9600, SWSERIAL_8N1, RX_XC100, TX_XC100, false, 256);
        SerialXC100.flush();
        statusXC100 = true;
        reloadXC100();
        write(0x2A, 0xAA);
    }
}

void closeXC100()
{
    if (statusXC100)
    {
        reloadXC100();
        statusXC100 = false;
        SerialXC100.end();
        write(0x2A, 0xBB);
    }
}

void readXC100()
{
    if (statusXC100 && SerialXC100.available() > 0)
    {

        countResponse = 0;

        for (uint i = 0; i < 11; i++)
        {
            response[i] = 0x00;
        }

        byte byteSerial = 0x00;

        while (SerialXC100.available() || (byteSerial != 0x03 && byteSerial != 0x06))
        {
            if (SerialXC100.available() > 0)
            {
                byteSerial = SerialXC100.read();

                if (byteSerial == 0x06)
                {
                    response[0] = 0x06;
                }
                else if (byteSerial == 0x02)
                {
                    countResponse = 0;
                    for (uint i = 0; i < 11; i++)
                    {
                        response[i] = 0x00;
                    }
                }

                response[countResponse] = byteSerial;
                countResponse++;

                if (byteSerial == 0x06)
                {
                    if (statusDispensed == true && errorDispensed == true)
                    {
                        countErrors++;
                    }
                    break;
                }
                if (byteSerial == 0x03)
                {
                    break;
                }
            }
        }

        if (statusDispensed == false && response[0] == 0x06 && clearDispensed == 0)
        {
            write(0x2A, response[0]);
        }

        if (statusDispensed == false && response[0] == 0x06 && clearDispensed == 1)
        {
            clearDispensed = 2;
        }
        else if (statusDispensed == false && response[0] == 0x06 && clearDispensed == 2)
        {
            clearDispensed = 0;
        }

        if (statusDispensed == true && response[3] == 0x62)
        {
            SerialXC100.flush();

            byte *total = totalBills(totalByteDispensedWithError);

            if (total[0] == response[5] && total[1] == response[6] && total[2] == response[7])
            {
                statusDispensed = false;
                clearDispensed = 1;
                totalByteDispensed = 0x00;
                errorDispensed = false;
                countDispensed = 0;
                totalToBeDispensed = 0;
                countErrors = 0;
                countAttempts = 0;
                totalByteDispensedWithError = 0x00;
                autoDispenser = false;
                write(0x2A, 0x2B);
                SerialXC100.write(clearErrorAndCount, 10);
                SerialXC100.write(clearErrorRecord, 10);
            }

            if (autoDispenser == false)
            {
                if (total[0] != response[5] || total[1] != response[6] || total[2] != response[7])
                {
                    statusDispensed = false;
                    clearDispensed = 1;
                    totalByteDispensed = 0x00;
                    errorDispensed = false;
                    countDispensed = 0;
                    totalToBeDispensed = 0;
                    countErrors = 0;
                    countAttempts = 0;
                    autoDispenser = false;
                    totalByteDispensedWithError = 0x00;
                    byte billsDispensed = totalByteDispensedCheck(checkCoinsDispensed(response[5], response[6], response[7]));
                    write(0x2C, billsDispensed);
                    SerialXC100.write(clearError, 10);
                    SerialXC100.write(clearErrorRecord, 10);
                }
            }
            else
            {
                if (total[0] != response[5] || total[1] != response[6] || total[2] != response[7])
                {

                    uint countDispensedLast = countDispensed;
                    uint countDispensedNew = countDispensed + checkCoinsDispensed(response[5], response[6], response[7]);

                    if (countDispensedLast < countDispensedNew)
                    {
                        countDispensed = countDispensedNew;
                    }

                    byte billsDispensed = totalByteDispensedCheck(countDispensed);

                    countErrors = 0;
                    errorDispensed = true;
                    countAttempts++;

                    if (countAttempts >= 10)
                    {
                        statusDispensed = false;
                        clearDispensed = 1;
                        totalByteDispensed = 0x00;
                        errorDispensed = false;
                        countDispensed = 0;
                        totalToBeDispensed = 0;
                        countErrors = 0;
                        countAttempts = 0;
                        totalByteDispensedWithError = 0x00;
                        autoDispenser = false;
                        write(0x2C, billsDispensed);
                        SerialXC100.write(clearErrorAndCount, 10);
                        SerialXC100.write(clearErrorRecord, 10);
                    }
                    else
                    {
                        SerialXC100.write(clearError, 10);
                    }
                }
            }
        }

        if (autoDispenser == true)
        {

            if (statusDispensed == true && errorDispensed == true && countErrors == 1 && response[0] == 0x06)
            {
                SerialXC100.write(clearErrorRecord, 10);
            }

            if (statusDispensed == true && errorDispensed == true && countErrors == 2 && response[0] == 0x06)
            {
                SerialXC100.write(powerfulOutBill, 10);
            }

            if (statusDispensed == true && errorDispensed == true && countErrors == 3 && response[0] == 0x06)
            {
                countErrors = 0;

                if (countAttempts >= 3)
                {
                    countDispensed += 2;
                }
                else if (countAttempts >= 2)
                {
                    countDispensed += 1;
                }
                else if (countAttempts == 1)
                {
                    countDispensed += 1;
                }
                else
                {
                    countDispensed += 1;
                }

                byte *total = totalBillsWithError(totalToBeDispensed - countDispensed);
                totalByteDispensedWithError = totalByteDispensedCheck(totalToBeDispensed - countDispensed);

                cs = calculateCS(0x02, 0x30, 0x30, 0x42, 0x30, total[0], total[1], total[2]);
                byte *commandDispensed = createPayload(0x02, 0x30, 0x30, 0x42, 0x30, total[0], total[1], total[2], cs, 0x03);

                SerialXC100.flush();
                SerialXC100.write(commandDispensed, 10);
            }
        }
    }
}

void readSerialXC100()
{

    if (byteCommand == 0x2A)
    {
        if (byteAction == 0xAA)
        {
            openXC100();
        }
        else if (byteAction == 0xBB)
        {
            closeXC100();
        }
        else
        {
            if (statusXC100)
            {
                if (byteAction == 0x20) // Clear Count (0x20) Tx : 02 30 30 49 30 30 30 31 6C 03 , Rx : 06
                {
                    SerialXC100.write(clearCount, 10);
                }
                else if (byteAction == 0x21) // Clear Error (0x21) Tx : 02 30 30 49 30 30 30 32 6D 03 , Rx : 06
                {
                    SerialXC100.write(clearError, 10);
                }
                else if (byteAction == 0x22) // Clear Error and Clear Count (0x22) Tx : 02 30 30 49 30 30 30 33 6E 03 , Rx : 06
                {
                    SerialXC100.write(clearErrorAndCount, 10);
                }
                else if (byteAction == 0x23) // Key Disable (0x23) Tx : 02 30 30 4B 31 30 31 30 6F 03 , Rx : 06
                {
                    SerialXC100.write(keyDisable, 10);
                }
                else if (byteAction == 0x24) // Key Enable (0x24) Tx : 02 30 30 4B 30 30 30 30 6D 03 , Rx : 06
                {
                    SerialXC100.write(keyEnable, 10);
                }
                else if (byteAction == 0x25) // Status (0x25) Tx : 02 30 30 53 30 30 30 30 75 03 , Rx : 02 30 30 73 72 30 30 30 D7 03
                {
                    SerialXC100.write(Status, 10);
                }
                else if (byteAction == 0x26) // Error Record (0x26) Tx : 02 30 30 52 30 30 30 30 74 03
                {
                    SerialXC100.write(errorRecord, 10);
                }
                else if (byteAction == 0x27) // Clear Error Record (0x27) Tx : 02 30 30 55 30 30 30 30 77 03 , Rx : 06
                {
                    SerialXC100.write(clearErrorRecord, 10);
                }
                else if (byteAction == 0x28) // Total Count (0x28) Tx : 02 30 30 43 30 30 30 30 65 03 , Rx : 02 30 30 63 30 30 30 30 85 03
                {
                    SerialXC100.write(totalCount, 10);
                }
                else if (byteAction == 0x29) // Password Enable (0x29) Tx : 02 30 30 37 31 30 30 30 5A 03 , Rx : 06
                {
                    SerialXC100.write(passwordEnable, 10);
                }
                else if (byteAction == 0x30) // Password Disable (0x30) Tx : 02 30 30 37 30 30 30 30 59 03 , Rx : 06
                {
                    SerialXC100.write(passwordDisable, 10);
                }
                else if (byteAction == 0x31) // Powerful Out Bill (0x31) Tx : 02 30 30 36 30 30 30 30 58 03 , Rx : 06
                {
                    SerialXC100.write(powerfulOutBill, 10);
                }
            }
        }
    }
    else if (byteCommand == 0x2B || byteCommand == 0x2C)
    {
        if (statusXC100)
        {
            if (byteCommand == 0x2B)
            {
                autoDispenser = false;
            }
            else if (byteCommand == 0x2C)
            {
                autoDispenser = true;
            }

            byte *total = totalBills(byteAction);

            if (total[0] != 0x30 || total[1] != 0x30 || total[2] != 0x30)
            {
                statusDispensed = true;
                clearDispensed = 0;
                totalByteDispensed = byteAction;
                errorDispensed = false;
                totalToBeDispensed = totalCoins(byteAction);
                countErrors = 0;
                countAttempts = 0;
                totalByteDispensedWithError = byteAction;

                cs = calculateCS(0x02, 0x30, 0x30, 0x42, 0x30, total[0], total[1], total[2]);
                byte *commandDispensed = createPayload(0x02, 0x30, 0x30, 0x42, 0x30, total[0], total[1], total[2], cs, 0x03);

                SerialXC100.write(clearErrorAndCount, 10);
                SerialXC100.write(clearErrorRecord, 10);
                SerialXC100.write(commandDispensed, 10);
            }
            else
            {
                write(0x2B, 0x30);
            }
        }
    }
}

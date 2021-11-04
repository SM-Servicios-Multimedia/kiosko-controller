#ifndef MATHS_H
#define MATHS_H

#include <Arduino.h>

int totalCoins(byte _total);
byte *totalBills(byte _total);
int checkCoinsDispensed(byte b1, byte b2, byte b3);
byte *totalBillsWithError(int _total);
byte totalByteDispensedCheck(int _total);

#endif
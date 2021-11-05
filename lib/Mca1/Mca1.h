#ifndef MCA1_H
#define MCA1_H

#include <Arduino.h>
#include "Globals.h"

byte *createCode(byte b0, byte b1, byte b2, byte b3, byte b4);
byte *createCodeSix(byte b0, byte b1, byte b2, byte b3, byte b4, byte b5);
bool statusRX(byte r[], byte c[]);

void openMCA1();
void closeMCA1();
void reloadMCA1();
void readMCA1();
void readSerialMCA1();
void enableMCA1();
void disableMCA1();

#endif
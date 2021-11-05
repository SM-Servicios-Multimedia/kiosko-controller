#ifndef TGP58_H
#define TGP58_H

#include <Arduino.h>
#include "Globals.h"

void openTGP58();
void closeTGP58();
void readSerialTGP58();
void readTGP58();
void writeTGP58(byte _byte);
void readInternalTGP58();

#endif
#ifndef START_H
#define START_H

#include <Arduino.h>
#include "Globals.h"

void StartMoneyAcceptors();
void StartDispenserXC100();
void StartPrinterTGP58();
void serialStart();
void StopDevices();

#endif
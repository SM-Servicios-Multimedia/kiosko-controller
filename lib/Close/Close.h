#ifndef CLOSE_H
#define CLOSE_H

#include <Arduino.h>
#include "Globals.h"

void endTP11();
void endXC100();
void endMCA1();
void endTGP58();
void endCoinAcceptor();
void endHopper();
void closeAllDevices();
void restartAllDevices();

#endif
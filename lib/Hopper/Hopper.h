#ifndef HOPPER_H
#define HOPPER_H

#include <Arduino.h>
#include "Globals.h"

void setupHopper();
void readSerialHopper();
void loopHopper();
void startHopper();
void finishHopper();
void hopper_event();
void restartHopper();

#endif
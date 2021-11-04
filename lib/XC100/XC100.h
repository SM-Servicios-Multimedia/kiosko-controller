#ifndef XC100_H
#define XC100_H

#include <Arduino.h>
#include "SoftwareSerial.h"
#include "Globals.h"

extern SoftwareSerial SerialXC100;

byte* createPayload(byte b0, byte b1, byte b2, byte b3, byte b4, byte b5, byte b6, byte b7, byte b8, byte b9);

extern byte* clearCount;
extern byte* clearError;
extern byte* clearErrorAndCount;
extern byte* keyDisable;
extern byte* keyEnable;
extern byte* Status;
extern byte* errorRecord;
extern byte* clearErrorRecord;
extern byte* totalCount;
extern byte* passwordEnable;
extern byte* passwordDisable;
extern byte* powerfulOutBill;
extern uint8_t checksum;

void reloadXC100();
void setupXC100();
void readXC100();
void readSerialXC100();
void restartXC100();
uint8_t calculateCS();

#endif
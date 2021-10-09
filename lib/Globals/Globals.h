#ifndef GLOBALS_H
#define GLOBALS_H

#include <Arduino.h>

/*Leds*/
extern int led;

/*Serial*/
extern byte byteCommand;
extern byte byteAction;
extern byte byteCommandBLE;
extern byte byteActionBLE;
extern int countByte;
extern unsigned long LAST_STATUS;
extern bool CHECK_STATUS;
extern bool debug;

/*Reset*/
extern int pin_reset;
extern unsigned long LASTRESET;
extern const int timeReset;

/*BLUETOOTH*/
extern std::string nameBluetooth;
extern uint32_t pinBluetooth;
extern int JUMPER_BLUETOOTH;

/*TP11*/
extern int RX_TP11;
extern int TX_TP11;

#endif
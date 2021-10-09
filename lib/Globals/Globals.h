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

/*Hopper*/
extern int pinHopper;
extern int relayHopper;
extern unsigned long LASTIMPULSEHOPPER;
extern int PULSESHOPPER;
extern bool hopperCoin;
extern int timeLimitPulsesHopper;
extern int numCoinsHopper;
extern int timeWaitHopper;

/*Coin Acceptor*/
extern int pinCoinAcceptor;
extern unsigned long LASTIMPULSE;
extern int PULSES;
extern bool acceptCoin;
extern const int timeLimitPulsesCoin;
extern const int timeDelayPulsesCoin;

#endif
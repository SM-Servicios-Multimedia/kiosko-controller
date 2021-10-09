#include <Arduino.h>
#include "Globals.h"

/*Leds*/
int led = 2;

/*Serial*/
byte byteCommand = 0x00;
byte byteAction = 0x00;
byte byteCommandBLE = 0x00;
byte byteActionBLE = 0x00;
int countByte = 0;
unsigned long LAST_STATUS = millis();
bool CHECK_STATUS = true;
bool debug = false;

/*Reset*/
int pin_reset = 5;
unsigned long LASTRESET = 0;
const int timeReset = 5000;

/*BLUETOOTH*/
std::string nameBluetooth = "ATM Servicios Multimedia";
uint32_t pinBluetooth = 999999;
int JUMPER_BLUETOOTH = 15;

/*TP11*/
int RX_TP11 = 23;
int TX_TP11 = 22;

/*Hopper*/
int pinHopper = 21;
int relayHopper = 16;
unsigned long LASTIMPULSEHOPPER = 0;
int PULSESHOPPER = 0;
bool hopperCoin = false;
int timeLimitPulsesHopper = 150;
int numCoinsHopper = 0;
int timeWaitHopper = 30000;

/*Coin Acceptor*/
int pinCoinAcceptor = 19;
unsigned long LASTIMPULSE = 0;
int PULSES = 0;
bool acceptCoin = false;
const int timeLimitPulsesCoin = 500;
const int timeDelayPulsesCoin = 100;
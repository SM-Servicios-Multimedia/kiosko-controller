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
bool openPrinter = false;

/*Reset*/
int pin_reset = 23;
unsigned long LASTRESET = 0;
const int timeReset = 5000;

/*Admin*/
int pin_admin = 22;
unsigned long LASTADMIN = 0;
const int timeAdmin = 5000;

/*BLUETOOTH*/
std::string nameBluetooth = "ATM Servicios Multimedia";
uint32_t pinBluetooth = 999999;
int JUMPER_BLUETOOTH = 15;
bool DEV_JUMPER_BLUETOOTH = false;

/*Ports Virtual Serials*/
int rx[4] = {27, 26, 32, 35};
int tx[4] = {14, 25, 33, 34};

/*TP11*/
int RX_TP11 = rx[0];
int TX_TP11 = tx[0];

/*XC100*/
int RX_XC100 = rx[1];
int TX_XC100 = tx[1];
bool autoDispenser = false;

/*MCA1 Monedero*/
int RX_MCA1 = rx[2];
int TX_MCA1 = tx[2];

/*TGP58 Printer*/
int RX_TGP58 = rx[3];
int TX_TGP58 = tx[3];

/*Hopper*/
int pinHopper = 19;
int relayHopper = 18;
unsigned long LASTIMPULSEHOPPER = 0;
int PULSESHOPPER = 0;
bool hopperCoin = false;
int timeLimitPulsesHopper = 150;
int numCoinsHopper = 0;
int timeWaitHopper = 30000;

/*Coin Acceptor*/
int pinCoinAcceptor = 21;
unsigned long LASTIMPULSE = 0;
int PULSES = 0;
bool acceptCoin = false;
const int timeLimitPulsesCoin = 500;
const int timeDelayPulsesCoin = 100;

/*StatusDevices*/
bool statusTP11 = false;
bool statusXC100 = false;
bool statusMCA1 = false;
bool statusTGP58 = false;
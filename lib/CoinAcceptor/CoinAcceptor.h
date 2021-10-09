#ifndef COIN_ACCEPTOR_H
#define COIN_ACCEPTOR_H

#include <Arduino.h>
#include "Globals.h"

void setupCoinAcceptor();
void startCoinAcceptor();
void finishCoinAcceptor();
void coin_event();
void coins_inserted();
void loopSerialCoinAcceptor();
void loopCoinAcceptor();
void restartCoinAcceptor();

#endif
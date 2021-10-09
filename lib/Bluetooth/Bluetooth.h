#ifndef BLUETOOH_H
#define BLUETOOH_H

#include <Arduino.h>
#include <BLEDevice.h>
#include <BLEServer.h>
#include <BLEUtils.h>
#include <BLE2902.h>
#include "Globals.h"

extern BLEServer *pServer;
extern BLECharacteristic *pTxCharacteristic;
extern bool deviceConnected;
extern bool rx_received;
extern std::string rxValue;
extern bool statusSetup;

#define SERVICE_UUID "0000FFE0-0000-1000-8000-00805F9B34FB"
#define CHARACTERISTIC_UUID_RX "0000FFE1-0000-1000-8000-00805F9B34FB"
#define CHARACTERISTIC_UUID_TX "0000FFE2-0000-1000-8000-00805F9B34FB"

void bleSecurity();
void bleInit();
void setupBluetooth();
void loopReadBluetooth();
void writeBluetooth(byte _device, byte _command);
void BLE_read();
void initBluetooth();

#endif
/* File: transmit.h */

/* Libraries */
#include "schema.h"
#include "config.h"
#include "sensor.h"

/* External Libraries */
#include <EEPROM.h>
#include <XBee.h>

#define MAX_SIZE 80

/* Global Variable for Packet */
extern schema_1 Gpacket;

/* Gloabal XBee object */
extern XBee Gxbee;

/* Check for previous includes */
#ifndef TRANSMIT_H
#define TRANSMIT_H

void clear_Packet(void);            /* Clear Packet */
void construct_Packet(int Gcount);  /*Construct Packet */
void transmit_Packet(void);         /* Transmit Packet */
void construct_Test(void);          /* Test Packet */

#endif

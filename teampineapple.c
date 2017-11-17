/*  File: pineappledriver.c */

#include "config.h"
#include "sensor.h"
#include "transmit.h"
#include "schema.h"
#include "routine.h"

/*  global variables for packet */
schema_1 Gpacket;

/*  global xbee object  */
XBee Gxbee = XBee();

/*  global count variable */
int G_count = 0;

void setup() {
  
  /*  Initialization  */
  sensor_init();
  Serial.begin(9600);
  Gxbee.begin(Serial);

  /*  Packet Initialization */
  clear_Packet();
}

void loop() {
  routine(&G_count);
}

/*  File: routine.cpp */

/* Libraries */
#include "routine.h"

/*  constructs & transmits packet */
void routine(int *count) {
  
    /* Variable Initialization */
    long wait_ms = 1000;
    unsigned long transmit_timer = millis();
    
    /* Poll sensors and construct packet */
    construct_Packet(*count);

    /* Increment the poll count */
    (*count)++;

    /* Transmit after 3 polls */
    if((*count)>= 60)
    {
      transmit_Packet();
      clear_Packet();
      (*count) = 0;
      
    }

   /* Wait to ensure we poll exactly every second */
   while((millis() - transmit_timer) <= wait_ms);

   return;
}


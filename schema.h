/* File: schema.h */

/* External Library */
#include <stdint.h>

#ifndef SCHEMA_H
#define SCHEMA_H

/* Schema for Weatherbox Packets */
typedef struct {
    uint16_t schema;
    uint16_t address;    // Address of Arduino 
    uint32_t uptime_ms;   // Time since start of program
    int16_t  temperature;   // Temperature value (celcius)
    uint32_t pressure; // Pressure Value (in hPa)
    uint16_t altitude; //Altitude Value (m)
    uint16_t humidity; //Humidity Value (%)
    uint16_t solarirradiance; // Solar Irradiance Value (W*m^-2)
    
} schema_1;

/* Struct for Health Check */
typedef struct {
  uint16_t schema;  //Schema ID number
  uint16_t address; //Address of Arduino
  uint32_t uptime_ms; //Time since the start of program
} schema_5;

#endif 


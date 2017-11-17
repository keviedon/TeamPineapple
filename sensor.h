/* File: sensors.h */

/* Libraries */
#include "config.h"
#include <Wire.h>               
#include <SPI.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>

/*Initialization Function */
void sensor_init(void);

/* Sensor Functions */
void sensorBME280(long *temp, long *pres, long *alt, long *humid);
long sensorSP215(void);

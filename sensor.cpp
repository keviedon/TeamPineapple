/*  File: sensor.cpp  */

/*  Libraries */
#include "sensor.h"
#include "config.h"

Adafruit_BME280 bme;

/*Initialization Function */
void sensor_init(void) {
  bme.begin();
}

/* Sensor Functions */
void sensorBME280(long *temp, long *pres, long *alt, long *humid) {
  *temp = bme.readTemperature(); /* Celsius */
  *pres = bme.readPressure() / 100.0F; /* hPa */
  *alt = bme.readAltitude(SEALEVELPRESSURE_HPA); /* m */
  *humid = bme.readHumidity();  /* % */
  
  return;
}
long sensorSP215(void) {
  long value = analogRead(A1);
  long reading = value *.0049 * (10^3) * 0.25; /* W*m^-2 */
  
  return reading;
}


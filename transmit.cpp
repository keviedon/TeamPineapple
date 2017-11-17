/* File: transmit.cpp  */

/* Libraries */
#include "transmit.h"
#include "sensor.h"

/* Uncomment for serial debug */
//#define DEBUG

/*  clears packet */
void clear_Packet(void) {

  #ifdef DEBUG
  Serial.print("Begin:clear\n");
  #endif

  /* Variables for indexes */
  int i,j,k;

  /* Clear/init values in packet */
  Gpacket.address = EEPROM.read(2) | (EEPROM.read(3) << 8);;
  Gpacket.uptime_ms = 0;
  Gpacket.temperature = 0;
  Gpacket.pressure = 0;
  Gpacket.altitude = 0;
  Gpacket.humidity = 0;
  Gpacket.solarirradiance = 0;

  /* Clear/init values with multiple points */ 
  for(i = 0 ; i < 60; i++){
    j = i/10;
    k = i/3;

    /* Polled every 3 seconds */
    Gpacket.solarirradiance = 0;
  }

  #ifdef DEBUG
  Serial.print("End:clear\n");
  #endif
}

/*  constructs packet to send */
void construct_Packet(int Gcount) {
  
  /* Set Global Count */
  int i = Gcount;

  #ifdef DEBUG
  Serial.print("Begin:con\n");
  #endif
  
  /* Set Packet Schema # */
  Gpacket.schema = 297;
  
  /* Initialize  Sensor Variables */
  long temp = 0;
  long pres = 0;
  long alt = 0;
  long humid = 0;
  long solarirrad = 0;
  unsigned long uptime;

  /* Get Polling Sensor Data */ 
  sensorBME280(&temp, &pres, &alt, &humid);
  solarirrad = sensorSP215();
    
  /* Pack Data */
  Gpacket.temperature = temp;
  Gpacket.pressure = pres;
  Gpacket.altitude = alt;
  Gpacket.humidity = humid;
  Gpacket.solarirradiance = solarirrad;
    
  /* Update uptime */
  uptime = millis();
  Gpacket.uptime_ms = uptime;
   
  /* Debug Statements */    
  #ifdef DEBUG
  Serial.print("\nTemperature Data:");
  Serial.println(temp);
  Serial.print("\nPressure Data:");
  Serial.println(pres);
  Serial.print("\nAltitude Data:");
  Serial.println(alt);
  Serial.print("\nHumidity Data:");
  Serial.println(humid);
  Serial.print("\nSolar Irradiance Data:");
  Serial.println(solarirrad);
  Serial.print("End:con\n");
  #endif
}

/*  transmits packet to xbee  */
void transmit_Packet(void) {

  /* Variable to contain length */
  int len = 0;
  
  /* Obtain address of receiving end */
  XBeeAddress64 addr64 = XBeeAddress64(0x0,0x0);
  
  /* Packet to be transmitted */
  uint8_t payload[MAX_SIZE];

  /* Clear the payload */
  memset(payload, '\0', sizeof(payload));

  /* Obtain length of the packet */
  len = sizeof(Gpacket);

  /* Transfer information into payload */
  memcpy(payload, &Gpacket, len);

 /* Transfer the payload */
  ZBTxRequest zbTx = ZBTxRequest(addr64, payload, len);
  Gxbee.send(zbTx); //!!Prints packet to serial monitor
}

/*  testing for constructing packet */
void construct_Test(void){
  /* Debug */
  Serial.println(F("Generating - BIN"));
  
  /* Store values into packet */
  Gpacket.temperature = 1;
  Gpacket.pressure = 2;
  Gpacket.altitude = 3;
  Gpacket.humidity = 4;
  Gpacket.solarirradiance = 5;
  Gpacket.uptime_ms = 1000;
  
  return;
} 

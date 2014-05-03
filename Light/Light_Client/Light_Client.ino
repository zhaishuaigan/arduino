/**
 * A Mirf example to test the latency between two Ardunio.
 *
 * Pins:
 * Hardware SPI:
 * MISO -> 12
 * MOSI -> 11
 * SCK -> 13
 *
 * Configurable:
 * CE -> 8
 * CSN -> 7
 *
 * Note: To see best case latency comment out all Serial.println
 * statements not displaying the result and load 
 * 'ping_server_interupt' on the server.
 */

#include <SPI.h>
#include <Mirf.h>
#include <nRF24L01.h>
#include <MirfHardwareSpiDriver.h>
int P = 2;
void setup(){
  Serial.begin(9600);
  Mirf.spi = &MirfHardwareSpi;
  Mirf.init(); 
  Mirf.setRADDR((byte *)"clie1");
  Mirf.payload = sizeof(unsigned long);
  Mirf.config();
  Mirf.setTADDR((byte *)"serv1");
  
  pinMode(P, INPUT);
}

void loop(){
  unsigned long D = 1;
  while(!digitalRead(P))
  {
    Serial.println(digitalRead(P));
  }
  Serial.println(D);
  Mirf.send((byte *)&D);
  while(Mirf.isSending()){
  }
  delay(1000);
} 
  
  
  

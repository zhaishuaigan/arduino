/**
 * An Mirf example which copies back the data it recives.
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
 */

#include <SPI.h>
#include <Mirf.h>
#include <nRF24L01.h>
#include <MirfHardwareSpiDriver.h>
unsigned long breakTime = 0;
int K = 2;
bool S = 1;
void setup(){
  pinMode(K, OUTPUT);
  Mirf.spi = &MirfHardwareSpi;
  Mirf.init();
  Mirf.setRADDR((byte *)"serv1");
  Mirf.payload = sizeof(unsigned long);
  Mirf.config();
}

void loop(){
  byte data[Mirf.payload];
  unsigned long D = 0;
  if(!Mirf.isSending() && Mirf.dataReady()){
    Mirf.getData((byte *) &D);
    switch(D)
    {
      case 1:
        breakTime = millis() + 5000;
        if (S) { digitalWrite(K, LOW);}
      break;
      case 2:
        breakTime = 0;
        if (S) { digitalWrite(K, HIGH);}
      break;
      case 3:
        S = 0;
        digitalWrite(K, HIGH);
      break;
      case 4:
        S = 0;
        digitalWrite(K, LOW);
      break;
      case 5:
        S = 1;
      break;
    }
  }
  if (millis() >= breakTime)
  {
    digitalWrite(K, HIGH);
  }
  if (millis() < breakTime)
  {
    digitalWrite(K, LOW);
  }
}

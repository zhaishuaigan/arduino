#include "Shuai.h"
#include "Arduino.h"

/*
#define AR analogRead
#define AW analogWrite
#define DR digitalRead
#define DW digitalWrite
*/
int Shuai::AR(int pin){
	analogRead(pin);
}
void Shuai::AW(int pin, int status){
	analogWrite(pin,status);
}
int Shuai::DR(int pin){
	digitalRead(pin);
}
void Shuai::DW(int pin, int status){
	digitalWrite(pin,status);
}
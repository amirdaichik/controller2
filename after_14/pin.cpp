//
// Created by amirdaichik on 26/07/2018.
//

#include <iostream>
#include "pin.h"
/*class pin{
private
	int m_pin;
public:
	pin();
	pin(int pin);
	void setPin(int pin);
	void toggle();
	void write(int val);
};
class pospin public pin{
private:
	int m_bit;// bit of pos
public:
	pospin();
	pospin(int pin,int bit);
	void setBit(int bit);
};
*/
pin::pin(){ // TODO: In init we should set it to zero at the begining 
	m_pin = 0;
}
pin::pin(int pin_n){
	m_pin = pin_n;
}
void pin::setPin(int pin_n){
	m_pin = pin_n;
}
void pin::toggle(){
	digitalWrite(m_pin, HIGH);
	digitalWrite(m_pin, LOW); 
}
void pin::write(int val){
	digitalWrite(m_pin, val);
}
posPin::posPin() : pin(){
	m_bit = 0;
}
posPin::posPin(int pin,int bit): pin(pin){
	m_bit = bit;
}
void posPin::setBit(int bit){
	m_bit = bit;
}
void posPin::writeBitFromVal(int val){
	val = (val >> m_bit)%2;
	write(val);
}

//
// Created by amirdaichik on 26/07/2018.
//

#include <iostream>
#include "register.h"
/*class register{
private
	int m_pin;
public:
	register();
	register(int pin);
	void setPin(int pin);
	void toggle();
	void write(int val);
};
class posRegister public register{
private:
	int m_bit;// bit of pos
public:
	posRegister();
	posRegister(int pin,int bit);
	void setBit(int bit);
};
*/
register::register(){ // TODO: In init we should set it to zero at the begining 
	m_pin = 0;
}
register::register(int pin){
	m_pin = pin;
}
void register::setPin(int pin){
	m_pin = pin;
}
void register::toggle(){
	digitalWrite(m_pin, HIGH);
	digitalWrite(m_pin, LOW); 
}
void register::write(int val){
	digitalWrite(m_pin, val);
}
posRegister::posRegister() : register(){
	m_bit = 0;
}
posRegister::posRegister(int pin,int bit): register(pin){
	m_bit = bit;
}
void posRegister::setBit(int bit){
	m_bit = bit;
}
void posRegister::writeBitFromVal(int val){
	val = (val >> m_bit)%2;
	write(val);
}

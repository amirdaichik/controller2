//
// Created by amirdaichik on 26/07/2018.
//

#ifndef REGISTER_H
#define REGISTER_H

typedef enum colorType{RED,GREEN,BLUE} colorType;

class register{
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
	void writeBitFromVal(int val);
};


#endif 

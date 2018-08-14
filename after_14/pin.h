//
// Created by amirdaichik on 26/07/2018.
//

#ifndef REGISTER_H
#define REGISTER_H

typedef enum colorType{RED,GREEN,BLUE} colorType;

class pin{
private
	int m_pin;
public:
	pin();
	register(int pin_n);
	void getPin(){return m_pin;}
	void setPin(int pin_n);
	void toggle();
	void write(int val);
};
class posPin public register{
private:
	int m_bit;// bit of pos
public:
	posPin();
	posPin(int pin,int bit);
	void setBit(int bit);
	void writeBitFromVal(int val);
};


#endif 

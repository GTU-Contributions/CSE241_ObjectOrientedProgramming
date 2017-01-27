// HW07_131044084_Mehmed_Mustafa
// integerN.cpp
//
// Created on 10/12/2015 by Mehmed Mustafa
// Last Edited on 15/12/2015 by Mehmed Mustafa

#include "integerN.h"

namespace MehmedsNumbers{
	// realPart is the integer number
	// Constructors
	integerN::integerN(){
		realPart = 1;
	}
	integerN::integerN(int valInt){
		realPart = valInt;
	}

	// Public functions of class integerN
	void integerN::setInt(int valInt){
		realPart = valInt;
	}
	int integerN::getInt()const{
		return (static_cast<int>(realPart));
	}

	void integerN::printNumber()const{
		std::cout << *this << std::endl;
	}

	// Overloaded operators
	const integerN integerN::operator +(const integerN& otherNum)const{
		//Returs the sum of the two integer numbers
		return integerN(static_cast<int>(realPart + otherNum.realPart));
	}
	const integerN integerN::operator -(const integerN& otherNum)const{
		//Returs the difference of the two integer numbers
		return integerN(static_cast<int>(realPart - otherNum.realPart));
	}
	bool integerN::operator <(const integerN& otherNum)const{
		//Compares the two integer numbers
		if(realPart < otherNum.realPart)
			return true;
		else
			return false;
	}
	std::ostream& operator <<(std::ostream& output, const integerN& num){
		output << num.getReal();

		return output;
	}
}
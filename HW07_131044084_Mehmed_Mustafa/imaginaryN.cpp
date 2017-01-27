// HW07_131044084_Mehmed_Mustafa
// imaginaryN.cpp
//
// Created on 10/12/2015 by Mehmed Mustafa
// Last Edited on 15/12/2015 by Mehmed Mustafa

#include "imaginaryN.h"

namespace MehmedsNumbers{
	// Constructors
	imaginaryN::imaginaryN():complexN(0.0, 1.0){
		// Initialize to 1.0 the coefficient of the imaginary
	}
	imaginaryN::imaginaryN(double valImag):complexN(0.0, valImag){
		// Initialize the coefficient of the imaginary to valImag
	}

	void imaginaryN::printNumber()const{
		std::cout << *this << std::endl;
	}

	// Overloaded operators
	const imaginaryN imaginaryN::operator +(const imaginaryN& otherNum)const{
		return imaginaryN(imagPart + otherNum.imagPart);
	}
	const imaginaryN imaginaryN::operator -(const imaginaryN& otherNum)const{
		return imaginaryN(imagPart - otherNum.imagPart);
	}
	bool imaginaryN::operator <(const imaginaryN& otherNum)const{
		// Compares the coefficients of the imaginary numbers
		if(imagPart < otherNum.imagPart)
			return true;
		else
			return false;
	}
	std::ostream& operator <<(std::ostream& output, const imaginaryN& num){
		if(num.imagPart == 0)
			output << "0";
		else // when the imaginary coefficient is != 0
			output << num.imagPart << "i";

		return output;
	}
}
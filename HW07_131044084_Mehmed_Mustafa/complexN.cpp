// HW07_131044084_Mehmed_Mustafa
// complexN.cpp
//
// Created on 10/12/2015 by Mehmed Mustafa
// Last Edited on 15/12/2015 by Mehmed Mustafa

#include "complexN.h"
#include <cmath> // For using sqrt();

namespace MehmedsNumbers{
	// Constructors
	complexN::complexN():realPart(1.0), imagPart(1.0){
		// Initialize to 1.0 both real and imaginary parts
	}
	complexN::complexN(double valReal):realPart(valReal), imagPart(1.0){
		// Initialize realPart to valReal and sets the imagPart to 1.0
	}
	complexN::complexN(double valReal, double valImag):realPart(valReal), 
													  imagPart(valImag){
		// Initialize realPart to valReal and imagPart to valImag
	}

	// Public functions of class complexN
	void complexN::setReal(double valReal){
		realPart = valReal; // Sets the real part to valReal
	}
	void complexN::setImag(double valImag){
		imagPart = valImag; // Sets the imaginary part to valImag
	}
	void complexN::setRealImag(double valReal, double valImag){
		realPart = valReal; // Sets the real part to valReal
		imagPart = valImag; // Sets the imaginary part to valImag
	}
	double complexN::getReal()const{
		return realPart; // Returns the real part
	}
	double complexN::getImag()const{
		return imagPart; // Returns the imaginary part
	}
	double complexN::getMagnitude()const{
		// Finds the magnitude/abs of the complex number
		double temp = realPart*realPart+imagPart*imagPart;
		return sqrt(temp);
	}

	void complexN::printNumber()const{
		std::cout << *this << std::endl;
	}

	// Overloaded operators
	const complexN complexN::operator +(const complexN& otherNum)const{
		double tempReal = realPart + otherNum.realPart;
		double tempImag = imagPart + otherNum.imagPart;

		return complexN(tempReal, tempImag);
	}
	const complexN complexN::operator -(const complexN& otherNum)const{
		double tempReal = realPart - otherNum.realPart;
		double tempImag = imagPart - otherNum.imagPart;

		return complexN(tempReal, tempImag);
	}
	bool complexN::operator <(const complexN& otherNum)const{
		// Compares the magnitudes of the two complex numbers
		if(getMagnitude() < otherNum.getMagnitude())
			return true;
		else
			return false;
	}
	std::ostream& operator <<(std::ostream& output, const complexN& num){
		if(num.getReal() == 0 && num.getImag() == 0)
			output << "0";
		else if(num.getReal() == 0 && num.getImag() != 0)
			output << num.getImag() << "i";
		else if(num.getReal() != 0 && num.getImag() == 0)
			output << num.getReal();
		else if(num.getReal() != 0 && num.getImag() > 0)
			output << num.getReal() << " + " << num.getImag() << "i";
		else // When realPart != 0 && imagPart < 0
			output << num.getReal() << " - " << -num.getImag() << "i";

		return output;
	}

}
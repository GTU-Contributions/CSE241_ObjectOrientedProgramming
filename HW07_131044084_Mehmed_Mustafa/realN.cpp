// HW07_131044084_Mehmed_Mustafa
// realN.cpp
//
// Created on 10/12/2015 by Mehmed Mustafa
// Last Edited on 15/12/2015 by Mehmed Mustafa

#include "realN.h"

namespace MehmedsNumbers{
	// Constructors
	realN::realN():complexN(1.0){
		// Initialize to 1.0 the realPart of the realN class
	}
	realN::realN(double valReal):complexN(valReal){
		// Initialize to valReal the realPart
	}

	void realN::printNumber()const{
		std::cout << *this << std::endl;
	}

	const realN realN::operator +(const realN& otherNum)const{
		//Returs the sum of the two real number
		return realN(realPart + otherNum.realPart);
	}
	const realN realN::operator -(const realN& otherNum)const{
		//Return the difference of the two real number
		return realN(realPart - otherNum.realPart);
	}
	bool realN::operator <(const realN& otherNum)const{
		//Compares the two real number
		if(realPart < otherNum.realPart)
			return true;
		else
			return false;
	}
	std::ostream& operator <<(std::ostream& output, const realN& num){
		output << num.getReal();

		return output;
	}

}
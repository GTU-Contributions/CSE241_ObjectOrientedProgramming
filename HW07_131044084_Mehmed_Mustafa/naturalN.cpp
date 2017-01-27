// HW07_131044084_Mehmed_Mustafa
// naturalN.cpp
//
// Created on 10/12/2015 by Mehmed Mustafa
// Last Edited on 15/12/2015 by Mehmed Mustafa

#include "naturalN.h"
#include <cstdlib>  // For using exit(1)

namespace MehmedsNumbers{
	// realPart is the natural number
	// Constructors
	naturalN::naturalN(){
		//Sets the value of the natural number to 1
		realPart = 1;
	}
	naturalN::naturalN(int valNatural)
	{
		if(isNatural(valNatural))
			realPart = valNatural;
		else
		{
			std::cerr << "Error in natural.cpp!" << std::endl;
			std::cerr << "You are trying to initialize";
			std::cerr << "negative number in Natural class!" << std::endl;
			exit(1);
		}
	}

	// Public functions of class naturalN
	void naturalN::setNatNum(int valNatural){
		if(isNatural(valNatural))
			realPart = valNatural;
		else
		{
			std::cerr << "Error in natural.cpp!" << std::endl;
			std::cerr << "You are trying to set";
			std::cerr << "negative number in Natural class!" << std::endl;
			exit(1);
		}
	}
	int	 naturalN::getNatNum()const{
		return (static_cast<int>(realPart));
	}
	bool naturalN::isNatural(int testValue)const{
		if(testValue < 0)
			return false;
		else
			return true;
	}

	void naturalN::printNumber()const{
		std::cout << *this << std::endl;
	}

	// Overloaded operators
	const naturalN naturalN::operator +(const naturalN otherNum)const{
		return (static_cast<int>(realPart + otherNum.realPart));
	}
	const naturalN naturalN::operator -(const naturalN otherNum)const{
		int result = static_cast<int>(realPart - otherNum.realPart);

		if(result >= 0)
			return result;
		else
		{
			std::cerr << "Error in natural.cpp operator -!" << std::endl;
			std::cerr << "The result from the subtraction is";
			std::cerr << "negative number in Natural class!" << std::endl;
			exit(1);
		}
	}
	bool naturalN::operator <(const naturalN otherNum)const{
		if(realPart < otherNum.realPart)
			return true;
		else
			return false;
	}
	std::ostream& operator <<(std::ostream& output, const naturalN num){
		output << num.getNatNum();

		return output;
	}
}
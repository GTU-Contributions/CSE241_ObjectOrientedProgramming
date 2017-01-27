// HW07_131044084_Mehmed_Mustafa
// rationalN.cpp
//
// Created on 10/12/2015 by Mehmed Mustafa
// Last Edited on 15/12/2015 by Mehmed Mustafa

#include "rationalN.h"
#include <cstdlib>  // For using exit(1)

namespace MehmedsNumbers{
	// realPart is the nominator of the rational
	// Constructors
	rationalN::rationalN(){
		realPart = 1;
		denom = 1;
	}
	rationalN::rationalN(int valNom){
		// Initialize nominator(realPart to valNom and sets denominator to 1
		realPart = valNom;
		denom = 1;
		
	}
	rationalN::rationalN(int valNom, int valDenom){
		if(isRational(valDenom))
		{
			realPart = valNom;
			denom = valDenom;
		}
		else
		{
			std::cerr << "Error in rational.cpp!" << std::endl;
			std::cerr << "You are trying to set";
			std::cerr << "0 in the denominator of the number!" << std::endl;
			exit(1);
		}
	}

	// Public functions of class naturalN
	void rationalN::setNom(int valNom){
		realPart = valNom; // Sets nominator to valNom
	}
	void rationalN::setDenom(int valDenom){
		if(isRational(valDenom)) // If valDenom isn't zero
		{
			denom = valDenom; // Sets denominator to valDenom
		}
		else
		{
			std::cerr << "Error in rational.cpp!" << std::endl;
			std::cerr << "You are trying to set";
			std::cerr << "0 in the denominator of the number!" << std::endl;
			exit(1);
		}
	}
	void rationalN::setNomDenom(int valNom, int valDenom){
		if(isRational(valDenom)) // If valDenom isn't zero
		{
			realPart = valNom; // Sets nominator to valNom
			denom = valDenom; // Sets denominator to valNom
		}
		else // Exit the program
		{
			std::cerr << "Error in rational.cpp!" << std::endl;
			std::cerr << "You are trying to set";
			std::cerr << "0 in the denominator of the number!" << std::endl;
			exit(1);
		}
	}
	int  rationalN::getNom()const{
		return static_cast<int>(realPart); // Returns the value of the nominator
	}
	int  rationalN::getDenom()const{
		return denom; // Returns the value of the denominator
	}
	double rationalN::totalResult()const{
		// Returns the value of the rational in decimal format
		return (static_cast<double>(realPart)/denom);
	}
	bool rationalN::isRational(int testDenom)const{
		if(testDenom != 0) // If the denominator is not zero
			return true; // The rational is valid
		else // Is not valid
			return false;
	}
	void rationalN::normalizeR(rationalN& num)const{
		// If the denominator is positive, normalization isn't needed
		if(num.denom > 0)
			return;
		else
		{
			num.realPart *= -1;
			num.denom *= -1;
		}
	}

	void rationalN::printNumber()const{
		std::cout << *this << std::endl;
	}

	// Private functions of class naturalN
	int rationalN::findGCD(int num1, int num2)const{
		//Finds the greatest common divisor
		if (0 == num2)
			return num1;

		findGCD(num2, num1%num2);
	}

	// Overloaded operators
	const rationalN rationalN::operator +(const rationalN& otherNum)const{
		// Here realPart is nominator

		//Calculates the sum of the rationals
		int tempNom = static_cast<int>(realPart * otherNum.denom + denom * otherNum.realPart);
		int tempDenom = denom * otherNum.denom;

		//Finds the greatest common divisor of the sum
		int gcd = findGCD(tempNom, tempDenom);

		//Divide to gcd both nominator and denominator
		tempNom /= gcd; 
		tempDenom /= gcd;

		//Creates new rational object with the nom and denom of the sum
		rationalN temp(tempNom, tempDenom);

		//Writes the rational in the normalized form
		normalizeR(temp);

		return temp;
	}
	const rationalN rationalN::operator -(const rationalN& otherNum)const{
		// Here realPart is nominator

		//Calculates the difference of the rationals
		int tempNom = static_cast<int>(realPart * otherNum.denom - denom * otherNum.realPart);
		int tempDenom = denom * otherNum.denom;

		//Finds the greatest common divisor of the difference
		int gcd = findGCD(tempNom, tempDenom);

		//Divide to gcd both nominator and denominator
		tempNom /= gcd;
		tempDenom /= gcd;

		//Creates new rational object with the nom and denom of the difference
		rationalN temp(tempNom, tempDenom);

		//Writes the rational in the normalized form
		normalizeR(temp);

		return temp;
	}
	bool rationalN::operator <(const rationalN& otherNum)const{
		// Here realPart is nominator
		//Creates copies of both rationalN classes
		rationalN temp(static_cast<int>(realPart), denom);
		rationalN tempOther(static_cast<int>(otherNum.realPart), otherNum.denom);

		//Writes them in the normalized form
		normalizeR(temp);
		normalizeR(tempOther);

		// Compares them
		if(temp.realPart * tempOther.denom < tempOther.realPart * temp.denom)
			return true;
		else
			return false;
	}
	std::ostream& operator <<(std::ostream& output, const rationalN& num){
		//Prints the rational number
		output << num.getNom() << "/" << num.getDenom();

		return output;
	}
	
}
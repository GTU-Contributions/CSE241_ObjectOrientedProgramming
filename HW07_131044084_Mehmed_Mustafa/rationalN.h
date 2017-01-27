// HW07_131044084_Mehmed_Mustafa
// rationalN.h
//
// Created on 10/12/2015 by Mehmed Mustafa
// Last Edited on 15/12/2015 by Mehmed Mustafa

#ifndef RATIONAL_NUMBER_H
#define RATIONAL_NUMBER_H

#include "realN.h"
#include <iostream>

namespace MehmedsNumbers{
	class rationalN : public realN{
	public:
		// Default constructor, initialize denom and nom to 1
		rationalN(); 
		// Initialize nominator to valNom and sets denominator to 1
		rationalN(int valNom);
		// Initialize nominator to valNom and denominator to valDenom
		rationalN(int valNom, int valDenom); 

		void setNom(int valNom); // Setter for the nominator
		void setDenom(int valDenom); // Setter for the denominator
		void setNomDenom(int valNom, int valDenom); // Setter for both
		int  getNom()const; // Getter for the nominator
		int  getDenom()const; // Getter for the denominator
		double totalResult()const; // totalResult = nominator/denominator
		// Checks if a number is valid rational
		bool isRational(int testDenom)const;
		// Normalize the rational -> -a/-b = a/b; a/-b = -a/b
		void normalizeR(rationalN& num)const;

		virtual void printNumber()const;

		const rationalN operator +(const rationalN& otherNum)const;
		const rationalN operator -(const rationalN& otherNum)const;
		bool operator <(const rationalN& otherNum)const;
		friend std::ostream& operator <<(std::ostream& output, const rationalN& num);

	protected:
		// We have realPart inheritated from the realN
		// realPart is used as a nominator of the rational
		int denom; // Denominator
		int findGCD(int num1, int num2)const;
	};
} // MehmedsNumbers

#endif // RATIONAL_NUMBER_H
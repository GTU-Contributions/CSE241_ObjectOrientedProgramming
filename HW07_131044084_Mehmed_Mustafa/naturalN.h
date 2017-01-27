// HW07_131044084_Mehmed_Mustafa
// naturalN.h
//
// Created on 10/12/2015 by Mehmed Mustafa
// Last Edited on 15/12/2015 by Mehmed Mustafa

#ifndef NATURAL_NUMBER_H
#define NATURAL_NUMBER_H

#include "integerN.h"
#include <iostream> // For cout, cin, cerr

namespace MehmedsNumbers{
	class naturalN : public integerN{
	public:
		naturalN(); //Default constructor, initialize the number to 0
		naturalN(int valNatural); //Initialize the number to the given value

		void setNatNum(int valNatural); // Setter
		int  getNatNum()const; // Getter
		// Checks if a number is valid natural
		bool isNatural(int testValue) const;

		virtual void printNumber()const;

		const naturalN operator +(const naturalN otherNum)const;
		const naturalN operator -(const naturalN otherNum)const;
		bool operator <(const naturalN otherNum)const;
		friend std::ostream& operator <<(std::ostream& output, const naturalN num);

	protected:
		// We have realPart inheritated from the integerN
	};
} // MehmedsNumbers

#endif // NATURAL_NUMBER_H
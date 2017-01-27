// HW07_131044084_Mehmed_Mustafa
// integerN.h
//
// Created on 10/12/2015 by Mehmed Mustafa
// Last Edited on 15/12/2015 by Mehmed Mustafa

#ifndef INTEGER_NUMBER_H
#define INTEGER_NUMBER_H

#include "rationalN.h"
#include <iostream>

namespace MehmedsNumbers{
	class integerN : public rationalN{
	public:
		// Default constructor, initialize realPart(integer number) to 1
		integerN();
		// Initialize realPart(integer number) to valInt
		integerN(int valInt);

		void setInt(int valInt); // Setter for the integer
		int getInt()const; // Getter for the integer

		virtual void printNumber()const;

		const integerN operator +(const integerN& otherNum)const;
		const integerN operator -(const integerN& otherNum)const;
		bool operator <(const integerN& otherNum)const;
		friend std::ostream& operator <<(std::ostream& output, const integerN& num);

	protected:
		// We have realPart inheritated from the rationalN
	};
} // MehmedsNumbers

#endif // INTEGER_NUMBER_H
// HW07_131044084_Mehmed_Mustafa
// realN.h
//
// Created on 10/12/2015 by Mehmed Mustafa
// Last Edited on 15/12/2015 by Mehmed Mustafa

#ifndef REAL_NUMBER_H
#define REAL_NUMBER_H

#include "complexN.h"
#include <iostream>

namespace MehmedsNumbers{
	class realN : public complexN{
	public:
		// Default constructor, initialize the realPart to 1.0
		realN();
		realN(double valReal);

		// Inheritated functions from complexN class:
		// void setReal(double valReal);
		// double getReal()const;

		const realN operator +(const realN& otherNum)const;
		const realN operator -(const realN& otherNum)const;
		bool operator <(const realN& otherNum)const;
		friend std::ostream& operator <<(std::ostream& output, const realN& num);

		virtual void printNumber()const;

	protected:
		// We have realPart inheritated from the complexN
	};
} // MehmedsNumbers

#endif // REAL_NUMBER_H
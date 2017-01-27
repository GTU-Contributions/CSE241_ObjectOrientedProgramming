// HW07_131044084_Mehmed_Mustafa
// imaginaryN.h
//
// Created on 10/12/2015 by Mehmed Mustafa
// Last Edited on 15/12/2015 by Mehmed Mustafa

#ifndef IMAGINARY_NUMBER_H
#define IMAGINARY_NUMBER_H

#include "complexN.h"
#include <iostream>

namespace MehmedsNumbers{
	class imaginaryN : public complexN{
	public:
		// Default constructor, initialize imagPart to 1
		imaginaryN();
		// Initialize imagPart to valImag
		imaginaryN(double valImag);

		// Inheritated functions from complexN class:
		// void setImag(double valImag);
		// double getImag()const;

		const imaginaryN operator +(const imaginaryN& otherNum)const;
		const imaginaryN operator -(const imaginaryN& otherNum)const;
		// Compares the magnitudes of the two complex numbers
		bool operator <(const imaginaryN& otherNum)const;
		friend std::ostream& operator <<(std::ostream& output, const imaginaryN& num);

		virtual void printNumber()const;

	protected:
		// We have imagPart inheritated from the complexN
	};
} // MehmedsNumbers

#endif // IMAGINARY_NUMBER_H
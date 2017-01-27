// HW07_131044084_Mehmed_Mustafa
// cpmplexN.h
//
// Created on 10/12/2015 by Mehmed Mustafa
// Last Edited on 15/12/2015 by Mehmed Mustafa

#ifndef COMPLEX_NUMBER_H
#define COMPLEX_NUMBER_H

#include "number.h"
#include <iostream>

namespace MehmedsNumbers{
	class complexN : public number{
	public:
		// Default constructor, initialize to 1.0 both real and imaginary parts
		complexN();
		// Initialize realPart to the valReal and sets imagPart to 1.0
		complexN(double valReal);
		// Initialize 
		complexN(double valReal, double valImag);

		void setReal(double valReal); // Setter for the real part
		void setImag(double valImag); // Setter for the imaginary part
		void setRealImag(double valReal, double valImag); // Setter for both parts
		double getReal()const; // Getter for the real part
		double getImag()const; // Getter for the imaginary part
		double getMagnitude()const; // Calculates the magnitude/abs

		const complexN operator +(const complexN& otherNum)const;
		const complexN operator -(const complexN& otherNum)const;
		// Compares the magnitudes of the two complex numbers
		bool operator <(const complexN& otherNum)const;
		friend std::ostream& operator <<(std::ostream& output, const complexN& num);

		virtual void printNumber()const;

	protected:
		double realPart;
		double imagPart;
	};
} // MehmedsNumbers

#endif // COMPLEX_NUMBER_H
// HW07_131044084_Mehmed_Mustafa
// irrationalN.h
//
// Created on 10/12/2015 by Mehmed Mustafa
// Last Edited on 15/12/2015 by Mehmed Mustafa

#ifndef IRRATIONAL_NUMBER_H
#define IRRATIONAL_NUMBER_H

#include "realN.h"
#include <iostream>

//Abstract class
namespace MehmedsNumbers{
	class irrationalN : public realN{
		virtual void printNumber()const = 0;

	};
} // MehmedsNumbers

#endif // IRRATIONAL_NUMBER_H
// HW06_131044084_Mehmed_Mustafa
// Cell.h
//
// Created on 05/12/2015 by Mehmed Mustafa
// Last Edited on 11/12/2015 by Mehmed Mustafa

#ifndef CELL_H
#define	CELL_H

#include <iostream>

namespace nameCell{
	class Cell{
	public:
		Cell():X(0), Y(0){}; // Default constructor
		// Constructor taking X and Y coordinates as parameter and '.' symbol
		Cell(int valX, int valY, char valS='.');
		void setX(const int valX) {X=valX;};// Set value for X coordinate 
		void setY(const int valY) {Y=valY;};// Set value for Y coordinate
		void setS(const char valS) {S=valS;}; // Set value for S symbol
		int  getX() const {return X;};// Return X coordinate of the cell
		int  getY() const {return Y;};// Return Y coordinate of the cell
		char getS() const {return S;};// Return S symbol of the cell

		void testerForCell(); // Test all overloaded operators

		bool operator <(const Cell &other);
		bool operator >(const Cell &other);
		bool operator <=(const Cell &other);
		bool operator >=(const Cell &other);
		bool operator ==(const Cell &other);
		bool operator !=(const Cell &other);
		Cell operator ++(); // Prefix version
		Cell operator ++(int ignoreMe); // Postfix version
		Cell operator --(); // Prefix version
		Cell operator --(int ignoreMe); // Postfix version
		friend std::ostream& operator <<(std::ostream& output, const Cell &cell);
		friend std::istream& operator >>(std::istream& input, Cell &cell);
    
		// X ve Y kordinatlarini int olarak tuttum 26x26 dan daha buyuk
		// Tahta boyutlarini da konzola basabilmem icin
		// char yetersiz olacakti
	private:
		int X; //Row, Height
		int Y; //Column, Width
		char S; //Symbol - PL_S for the player, PC_S for the computer
	};
}
#endif	// CELL_H
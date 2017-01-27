// HW06_131044084_Mehmed_Mustafa
// Cell.cpp
//
// Created on 05/12/2015 by Mehmed Mustafa
// Last Edited on 11/12/2015 by Mehmed Mustafa
#include "Cell.h"

namespace nameCell{
	//Public of the Cell class
	Cell::Cell(int valX, int valY, char valS):X(valX), Y(valY), S(valS){}
	void Cell::testerForCell(){
		int choice;
		char checkEnd;
    
		Cell test1, test2;
		do
		{
			std::cout << "------------------------" << std::endl;
			std::cout << " 1) < operator" << std::endl;
			std::cout << " 2) > operator" << std::endl;
			std::cout << " 3) <= operator" << std::endl;
			std::cout << " 4) >= operator" << std::endl;
			std::cout << " 5) == operator" << std::endl;
			std::cout << " 6) != operator" << std::endl;
			std::cout << " 7) ++ prefix" << std::endl;
			std::cout << " 8) ++ postfix" << std::endl;
			std::cout << " 9) -- prefix" << std::endl;
			std::cout << "10) -- postfix" << std::endl;
			std::cout << "Please choose an option: ";
			std::cin >> choice;
        
			switch(choice)
			{
				case 1:
					std::cout << "First cell:" << std::endl;
					std::cin >> test1;
					std::cout << "Second cell:" << std::endl;
					std::cin >> test2;
					std::cout << "Testing < operator" << std::endl;
					if (test1 < test2)
						std::cout << "First cell is smaller than second" << std::endl;
					else
						std::cout << "First cell is bigger than second" << std::endl;
					break;
				case 2:
					std::cout << "First cell:" << std::endl;
					std::cin >> test1;
					std::cout << "Second cell:" << std::endl;
					std::cin >> test2;
					std::cout << "Testing > operator" << std::endl;
					if(test1 > test2)
						std::cout << "First cell is bigger than second" << std::endl;
					else
						std::cout << "First cell is smaller than second" << std::endl;
					break;
				case 3:
					std::cout << "First cell:" << std::endl;
					std::cin >> test1;
					std::cout << "Second cell:" << std::endl;
					std::cin >> test2;
					std::cout << "Testing <= operator" << std::endl;
					if(test1 <= test2)
						std::cout << "First cell is smaller or equal to second" << std::endl;
					else
						std::cout << "First cell is bigger than second" << std::endl;
					break;
				case 4:
					std::cout << "First cell:" << std::endl;
					std::cin >> test1;
					std::cout << "Second cell:" << std::endl;
					std::cin >> test2;
					std::cout << "Testing >= operator" << std::endl;
					if(test1 >= test2)
						std::cout << "First cell is bigger or equal to second" << std::endl;
					else
						std::cout << "First cell is smaller than second" << std::endl;
					break;
				case 5:
					std::cout << "First cell:" << std::endl;
					std::cin >> test1;
					std::cout << "Second cell:" << std::endl;
					std::cin >> test2;
					std::cout << "Testing == operator" << std::endl;
					if(test1 == test2)
						std::cout << "The choosen cells are equal" << std::endl;
					else
						std::cout << "The choosen cells aren't equal" << std::endl;
					break;
				case 6:
					std::cout << "First cell:" << std::endl;
					std::cin >> test1;
					std::cout << "Second cell:" << std::endl;
					std::cin >> test2;
					std::cout << "Testing != operator" << std::endl;
					if(test1 != test2)
						std::cout << "The choosen cells aren't equal" << std::endl;
					else
						std::cout << "The choosen cells are equal" << std::endl;
					break;
				case 7:
					std::cout << "Cell:" << std::endl;
					std::cin >> test1;
					std::cout << "Testing ++ prefix" << std::endl;
					std::cout << ++test1 << std::endl;
					break;
				case 8:
					std::cout << "Cell:" << std::endl;
					std::cin >> test1;
					std::cout << "Testing ++ postfix" << std::endl;
					std::cout << test1++ << std::endl;
					break;
				case 9:
					std::cout << "Cell:" << std::endl;
					std::cin >> test1;
					std::cout << "Testing -- prefix" << std::endl;
					std::cout << --test1 << std::endl;
					break;
				case 10:
					std::cout << "Cell:" << std::endl;
					std::cin >> test1;
					std::cout << "Testing -- postfix" << std::endl;
					std::cout << test1-- << std::endl;
					break;
			}
        
			std::cout << "Do you want to test another operator ?" << std::endl;
			std::cout << "Press Y to test another option: ";
			std::cin >> checkEnd;
		}while(checkEnd == 'Y' || checkEnd == 'y');
	}

	//Operator overloading of the Cell class
	bool Cell::operator <(const Cell &other){
		if(Y < other.getY())
			return true;
		else if(Y == other.getY())
		{
			if(X < other.getX())
				return true;
			else // X > other.getX() or X == other.getX()
				return false;
		}
		else // Y > other.getY()
			return false;
	}
	bool Cell::operator >(const Cell &other){
		if(Y > other.getY())
			return true;
		else if(Y == other.getY())
		{
			if(X > other.getX())
				return true;
			else // X < other.getX() or X == other.getX()
				return false;
		}
		else // Y < other.getY()
			return false;
	}
	bool Cell::operator <=(const Cell &other){
		return (Y <= other.getY());
	}
	bool Cell::operator >=(const Cell &other){
		return (Y >= other.getY());
	}
	bool Cell::operator ==(const Cell &other){
		return ((other.getY() == Y) && (other.getX() == X));
	}
	bool Cell::operator !=(const Cell &other){
		return ((other.getY() != Y) || (other.getX() != X));
	}
	// Prefix version
	Cell Cell::operator ++() {
		++X;
		++Y;
		return Cell(X, Y);
	}
	// Postfix version
	Cell Cell::operator ++(int ignoreMe) {
		int tempX = X;
		int tempY = Y;
		++X;
		++Y;
		return Cell(tempX, tempY);
	} 
	// Prefix version
	Cell Cell::operator --() {
		--X;
		--Y;
		return Cell(X, Y);    
	}
	// Postfix version
	Cell Cell::operator --(int ignoreMe){
		int tempX = X;
		int tempY = Y;
		--X;
		--Y;
		return Cell(tempX, tempY);    
	}
	std::ostream& operator <<(std::ostream& output, const Cell &cell){
		output << "The X coordinate is: " << cell.getX() << std::endl;
		output << "The Y coordinate is: " << cell.getY() << std::endl;
		output << std::endl;
    
		return output;
	}
	std::istream& operator >>(std::istream& input, Cell &cell){
		int x, y;
		std::cout << "Enter the X coordinate of the Cell: ";
		input >>x;
		std::cout << "Enter the Y coordinate of the Cell: ";
		input >>y;
    
		cell.setX(x);
		cell.setY(y);
    
		return input;
	}
}

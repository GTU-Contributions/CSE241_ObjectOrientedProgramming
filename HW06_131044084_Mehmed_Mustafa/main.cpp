// HW06_131044084_Mehmed_Mustafa
// main.cpp
//
// Created on 05/12/2015 by Mehmed Mustafa
// Last Edited on 11/12/2015 by Mehmed Mustafa
#include <iostream>
#include "Reversi.h"

using namespace nameReversi;
using namespace std;

int main(){

	Reversi game1(7, 9);
	cout << "Total active games: " << game1.totalGames() << endl;
	game1.resizeBoard(8, 8);
	game1.displayBoard();
	game1.resizeBoard(6, 6);
	// Shows the new value for the board, and makes move
	// Prefix
	(++game1).displayBoard();
	cout << "Total active games: " << game1.totalGames() << endl;

	cout << "GAME TWO" << endl;
	Reversi game2(6, 6);
	cout << "Total active games: " << game2.totalGames() << endl;
	game2.resizeBoard(10, 10);
	// Shows the old value for the board, and makes move
	// Postfix
	(game2++).displayBoard(); 
	(game2++).displayBoard();
	// Shows the new value for the board and testing << operator
	cout << game2;
	cout << "Total active games: " << game2.totalGames() << endl;

	cout << "TESTING ASSIGNMENT OPERATOR" << endl;
	cout << "GAME ONE" << endl;
	cout << game1;
	cout << "GAME TWO" << endl;
	cout << game2;
	cout << "ASSIGNMING SAME OBJECT" << endl;
	game1 = game1;
	cout << game1;
	cout << "ASSIGNMING game2 to game1" << endl;
	game1 = game2;
	cout << "New view of the game1" << endl;
	cout << game1;
	cout << "" << endl;

	cout << "GAME THREE" << endl;
	Reversi game3(10, 10);
	++game3;
	cout << "game3 on the console" << endl;
	cout << game3;

	cout << "TESTING COPY CONSTRUCTOR" << endl;
	Reversi game4(game3);
	cout << "game4 on the console" << endl;
	cout << game4;
	cout << "Total active games: " << game4.totalGames() << endl;

    Reversi game5;
    // Play the entire game to the end
    game5.playGame();

	return 0;
}


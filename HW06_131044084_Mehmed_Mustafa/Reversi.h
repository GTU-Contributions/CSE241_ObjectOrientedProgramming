// HW06_131044084_Mehmed_Mustafa
// Reversi.h
//
// Created on 05/12/2015 by Mehmed Mustafa
// Last Edited on 11/12/2015 by Mehmed Mustafa

#ifndef REVERSI_H
#define REVERSI_H

#include <cstdlib>  // For using exit(1)
#include <iostream> // For using cout and cin
#include <iomanip>  // For using setw()
#include <string>   // For using strings
#include <vector>	// For using vector to hold legal moves
#include <fstream>  // For using ifstream and ofstream
#include "Cell.h"	// Including Cell library
using namespace nameCell;

namespace nameReversi{
	class Reversi{
	public:
            Reversi(); // Default constructor; Height and Width are set to 4
            Reversi(int valHeight); // Gets value for height, width is set to 4
            Reversi(int valHeight, int valWidth); // Gets values for height and width
            Reversi(const Reversi& otherObj); // Copy Constructor
            static const char PL_S = 'O'; // Player symbol
            static const char PC_S = 'X'; // Computer symbol
            static int totalGames() {return totalReversiGames;};
            int  getHeight() const {return height;}; // Returns height of the board
            int  getWidth() const {return width;};	// Returns width of the board
            // Displays current board on the console
            void displayBoard() const;
            // Resize the board and reset the game
            void resizeBoard(const int valH, const int valW);
            bool isGameEnded(); // Checks if the game is over
            void play(); // Plays move for the computer
            void play(const Cell &square); // Gets move for the player and plays
            void playGame(); // Plays the entire game
            // Compares 2 reversi objects
            bool compare(const Reversi &other)const; 

            Reversi& operator =(const Reversi& rightSize);
            Reversi operator ++(); // Prefix version
            Reversi operator ++(int ignoreMe); // Postfix version
            friend std::ostream& operator <<(std::ostream& output, 
                                                           const Reversi& game);
            virtual ~Reversi(); // Destructor

	private:
            Cell *gameCells; // Keeps the living cells on the board
            int sizeGame; // Keeps the size of the gameCells array
            // Keeps the current legal moves
            Cell *legalMoves; // It's size is equal to gameCells's size
            static int totalReversiGames; // Counts the Reversi objects
            int  height; // Height of the board
            int  width; // Width of the board

            /* PRIVATE FUNCTIONS FOR REVERSI CLASS */
            // Fill blank Cells with dots
            void newBoard();
            // Place central disks for the board
            void placeCenter();
            // Checks if the given square is outside
            bool isOutside(const int row, const int col)const;
            // Checks if the given square is living and gets it's symbol
            bool isLivingCell(const Cell *cells, const int x, const int y, 
                                                                 char &s)const;
            // Checks if the given move is legal or not
            bool isLegalMove(const Cell *cells,
                    const int row, const int col, const int dx, const int dy, 
                                                            const char user);
            // Checks if the given move is on the legals vector
            bool checkMove(const Cell *legals, const int x, const int y)const;
            // Resets legalsMove array
            void refreshLegals(Cell *legals);
            // Checks if legalsMove array is empty
            bool isEmptyLegals(Cell *legals);
            // Gets all legal moves and save them on the legals array
            int  getLegalMoves(const Cell *cells, const int sizeGame,
                                                Cell *legals, const char user);
            // Prints the legal moves on the console
            void printLegalMoves()const;
            // Gets the input move from the console
            void getInputMove(int &row, int &col);
            // Checks if a disk is captured or not
            bool isCaptured(const Cell *cells, int *x, int *y, 
                    const int row, const int col, const int dx, const int dy, 
                                                               const char user);
            // Make move on the board
            void makeMove(Cell *cells, const int row, const int col, 
                                                              const char user);
            // Calculates the best move for the computer
            void calculateBestComputerMove(const Cell *cells, const int sizeBoard,
                                            Cell *legals, int *rowB, int *colB);
            // Gets board dimensions from the console
            void getSize(); 
            // Returns how many disks the user has
            int  getScore(const char user)const; 
            // Prints the final score
            void endGameOutput()const;
	};
}
#endif // REVERSI_H
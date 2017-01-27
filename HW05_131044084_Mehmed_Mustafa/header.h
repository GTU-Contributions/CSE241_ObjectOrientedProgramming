// HW05_131044084_Mehmed_Mustafa
// header.h
//
// Created on 13/11/2015 by Mehmed Mustafa
// Last Edited on 23/11/2015 by Mehmed Mustafa

// Odev verildiginde BIG THREE ve namespace konulari
// islenmemisti, bu yuzden isimsiz namespace kullanmadim

#ifndef HEADER_H
#define	HEADER_H

#include <cstdlib>  // For using exit(1)
#include <iostream> // For using cout and cin
#include <iomanip>  // For using setw()
#include <string>   // For using strings
#include <vector>   // For using vectors
#include <fstream>  // For using ifstream and ofstream

using namespace std;

class Cell{
public:
    Cell():X(0), Y(0){}; // Default constructor
    // Constructor taking X and Y coordinates as parameter and '.' symbol
    Cell(int valX, int valY, char valS='.');
    void setX(const int valX) {X=valX;};    // Set value for X coordinate 
    void setY(const int valY) {Y=valY;};    // Set value for Y coordinate
    void setS(const char valS) {S=valS;};   // Set value for S symbol
    int  getX() const {return X;};  // Return X coordinate of the cell
    int  getY() const {return Y;};  // Return Y coordinate of the cell
    char getS() const {return S;};  // Return S symbol of the cell

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
    friend ostream& operator <<(ostream& output, const Cell &cell);
    friend istream& operator >>(istream& input, Cell &cell);
    
    // X ve Y kordinatlarini int olarak tuttum 26x26 dan daha buyuk
    // Tahta boyutlarini da konzola basabilmem icin
    // char yetersiz olacakti
private:
    int X; //Row, Height
    int Y; //Column, Width
    char S; //Symbol - PL_S for the player, PC_S for the computer
};
class Reversi{
public:
    Reversi(); // Default constructor; Height and Width are set to 4
    Reversi(int valHeight); // Gets value for height, width is set to 4
    Reversi(int valHeight, int valWidth); // Gets values for height and width
    static const char PL_S = 'O'; // Player symbol
    static const char PC_S = 'X'; // Computer symbol
    static int livingCells() {return totalLivingCells;};
    int  getHeight() const {return height;}; // Returns height of the board
    int  getWidth() const {return width;};	// Returns width of the board
    void displayBoard() const;	// Prints board on the console
    bool isGameEnded(); // Checks if the game is over
    void play(); // Makes move for the computer
    void play(const Cell &square); // Makes move for the player
    void playGame();    // Play the entire game
    void write(const char* fileName) const;	//Writes to file, Saves the game
    void read(const char* fileName); // Reads from file, Loads saved game
    bool compare(const Reversi &other)const; // Compares 2 reversi objects
    // Takes integer and returns needed string
    string intToString(const int num)const; 
    // Takes string and returns needed number
    int stringToInt(const string &move)const; 
    
    Reversi operator ++(); // Prefix version
    Reversi operator ++(int ignoreMe); // Postfix version   
    Reversi operator --(); // Prefix version
    Reversi operator --(int ignoreMe); // Postfix version
    Reversi operator +=(const Cell &move);
    friend ostream& operator <<(ostream& output, const Reversi& game);
    Cell   operator [](const string &move);
    Cell   operator ()(const string &move);

private:
    vector<vector<vector<Cell> > > gamePosition; // Keeps the game position
    vector<vector<Cell> > gameCells; // Keeps the living cells on the board
    vector<Cell> legalMoves; // Keeps the current legal moves
    static int totalLivingCells; // A cell is "living" if holds PL_S or PC_S
    int  height; // Height of the board
    int  width; // Width of the board
    bool isValidSize() const; // Checks the validity of the height and width
    void getSize(); // Gets board dimensions from the console
    int  getScore(const char user)const; // Returns how many disks the user has
    // Decrease total living cell number after the game is finished
    void decreaseLivingCells();
    void endGameOutput() const; // Prints the final score
    char setOpponent(const char user)const; // Determines the opponent for user
    // Checks if the given square is outside
    bool isOutside(const int row, const int col)const; 
    void placeCenter();	// Places the central symbols
    // Checks if the given square is living and gets it's symbol
    bool isLivingCell(const vector<vector<Cell> > &cells, 
                                   const int x, const int y, char &s) const;
    // Checks if the given move is legal or not
    bool isLegalMove(const vector<vector<Cell> > &cells, 
    const int x, const int y, const int dx, const int dy, const char user);
    // Gets all legal moves and save them on the legals vector
    int  getLegalMoves(const vector<vector<Cell> > &cells, vector<Cell> &legals, 
                                                           const char user);
    // Checks if the given move is on the legals vector
    bool checkMove(const vector<Cell> &legals, const int x, const int y) const;
    void printLegalMoves() const; // Prints the legals vector on the console
    void getInputMove(int &row, int &col); // Gets input move from the console
    // Checks if the square is captured or not after making move for the user
    bool isCaptured(const vector<vector<Cell> > &cells, int *x, int *y, 
    const int row, const int col, const int dx, const int dy, const char user);
    // If the square has opponent, change the square's symbol to user's
    void findAndChange(vector<vector<Cell> > &cells, 
                                const int x, const int y, const char user);
    // Make move for the user
    void makeMove(vector<vector<Cell> > &cells, 
                            const int row, const int col, const char user);
    // Calculates the move for the computer which takes the most opponent disks
    void calculateBestComputerMove(vector<vector<Cell> > &cells, 
                                vector<Cell> &legals, int *rowB, int *colB);
};

#endif	/* HEADER_H */

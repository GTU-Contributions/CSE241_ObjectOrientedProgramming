// HW01_131044084_Mehmed_Mustafa
// reversi.cpp

// Created on 18/09/2015 by Mehmed Mustafa
// Last Edited on 25/09/2015 by Mehmed Mustafa

#include<iostream>  // cout, cin, cerr, endl
#include<iomanip>   // setw

using namespace std;

const char PLAYER_SYMBOL = 'O';     // Symbol for player's disks
const char COMPUTER_SYMBOL = 'X';   // Symbol for computer's disks
const char BLANK_SYMBOL = '.';      // Symbol for blank squares on the board
const int MAX_SIZE = 20;            // Global max size constant for 2d arrays

int size = 0;           // Global variable - The users size of the board
int fullSquares = 0;    // Global variable - Number of total made moves
int noMoreMoves = 0;	// Global variable - Check if all legal moves are gone
bool whosTurnIs = 1;	// Whos turn is now indicator

int getSize(void);
void newBoard(char b[][MAX_SIZE]);
void placeCenter(char b[][MAX_SIZE]);
void printBoard(char b[][MAX_SIZE]);
char getOpponent(char user);
bool isOutsideSquare(int row, int col);
bool isBlankSquare(char square);
bool isLegalMove(char b[][MAX_SIZE], int row, int col, 
                                     int row_inc, int col_inc, char user);
int getAllLegalMoves(char b[][MAX_SIZE], bool m[][MAX_SIZE], char user);
void getInputMove(char b[][MAX_SIZE], bool m[][MAX_SIZE]);
bool isCaptured(char b[][MAX_SIZE], int &x, int &y, int row, int col, 
                                    int row_inc, int col_inc, char user);
void makeMove(char b[][MAX_SIZE], int row, int col, char user);
int bestScore(char b[][MAX_SIZE], bool m[][MAX_SIZE], char user);
void calculateBestComputerMove(char b[][MAX_SIZE], bool m[][MAX_SIZE], 
													int* rowB, int* colB);
void computersMove(char b[][MAX_SIZE], bool m[][MAX_SIZE]);
void printFinalScore(char b[][MAX_SIZE]);
void gameLoop(char b[][MAX_SIZE], bool m[][MAX_SIZE]);

int main()
{
	char board[MAX_SIZE][MAX_SIZE];
	bool moves[MAX_SIZE][MAX_SIZE];

	cout << "Welcome to Reversi game!" << endl;
	size = getSize();			// Get user size for the game board

	newBoard(board);			// Create new game board with blanks
	placeCenter(board);			// Place 4 center disks on the game board

	gameLoop(board, moves);		// Game loop - exit when the game is over

	printBoard(board);			// Shows the final board
	printFinalScore(board);		// Shows the final score

	return 0;
}

// Function to get size as input from the console
int getSize(void)
{
	int integer;

	cout << "The minimum size of the board is 4, the maximum is ";
    cout << MAX_SIZE << endl;
	while(true)
	{
		cout << "Choose the size of the board: ";
		cin >> integer;

		if(cin.fail())
		{
			cout << "Wrong input! The input must be an integer. Try again!\n";
			cin.clear();
			cin.ignore(512, '\n');
		}
		else if(integer < 4 || integer > MAX_SIZE)
		{
			cout << "The size must be between 4 and " << MAX_SIZE; 
			cout << ". Try again!" << endl;
			cin.clear();
			cin.ignore(512, '\n');
		}
		else if(integer%2 == 1)
		{
			cout << "The size must be an even number. Try again!" << endl;
			cin.clear();
			cin.ignore(512, '\n');
		}
		else
			return integer;
	}
}

// Function to fill blank symbols to an array board
void newBoard(char b[][MAX_SIZE])
{
	// Fills blank symbol for each member
    for(int i = 0; i < size; i++)
        for(int j = 0; j < size; j++)
            b[i][j] = BLANK_SYMBOL;
}

// Function to places 4 central disks on an array board
void placeCenter(char b[][MAX_SIZE])
{
	b[size/2 - 1][size/2 - 1] = COMPUTER_SYMBOL;
	b[size/2][size/2] = COMPUTER_SYMBOL;
	b[size/2 - 1][size/2] = PLAYER_SYMBOL;
	b[size/2][size/2 - 1] = PLAYER_SYMBOL;

	fullSquares = 4;    // Central 4 disks increase full square amount.
}

// Function to print the array board on the screen
void printBoard(char b[][MAX_SIZE])
{
	int row = 0, column = 0;	// Indexes of the rows and columns
	char columnLetter = 'a';	// Column letters
	int rowNumber = 0;			// Row numbers

	// Prints the column letters
	cout << endl << "  ";
	for(column = 0; column < size; column++)
		cout << setw(2) << columnLetter++;
	cout << endl;

	// Prints the row numbers and the values of the 2D array
	for(row = 0; row < size; row++)
	{
		cout << setw(2) << ++rowNumber;
		for(column = 0; column < size; column++)
			cout << setw(2) << b[row][column];
		cout << endl;
	}
	cout << endl;
}

// Function to identify the opponent
char getOpponent(char user)
{
	if(user == PLAYER_SYMBOL)
		return COMPUTER_SYMBOL;
	else if (user == COMPUTER_SYMBOL)
		return PLAYER_SYMBOL;
	else
		cerr << "Opponent identification error!" << endl;
}

// Function to check if a square is outside the board
bool isOutsideSquare(int row, int col)
{
	if(row < 0 || row >= size || col < 0 || col >= size)
		return true;
	else
		return false;
}

// Function to checks if a square is blank
bool isBlankSquare(char square)
{
	if(square == BLANK_SYMBOL)
		return true;
	else
		return false;
}

// Function to check if a given move is legal or not
bool isLegalMove(char b[][MAX_SIZE], int row, int col, 
									 int row_inc, int col_inc, char user)
{
	int x = 0, y = 0;				// Row and Column
	char opponent = getOpponent(user);

	// Don't check outside the board or the current square
	if(isOutsideSquare(row+row_inc, col+col_inc) || (row_inc==0 && col_inc==0))
		return false;

	if(b[row + row_inc][col + col_inc] == opponent)
	{
		x = row + row_inc;
		y = col + col_inc;			

		// Look for a user square in the same direction
		while(true)
		{
			x += row_inc;		
			y += col_inc;		
			
		// If we are off the board or we find a blank square return false
			if(isOutsideSquare(x, y) || isBlankSquare(b[x][y]))
				return false;

			// If we find user disk then we have a legal move
			if(b[x][y] == user)
				return true;
		}
	}
	else
		return false;
}

// Function to get all possible legal moves on the board
int getAllLegalMoves(char b[][MAX_SIZE], bool m[][MAX_SIZE], char user)
{
	int totalLegalMoves = 0;	// Number of total legal moves

	// Clears legal moves array for new check
	for(int i = 0; i < size; i++)
		for(int j = 0; j < size; j++)
			m[i][j] = false;

	// Find all legal moves and mark them on the moves array.
	for(int row = 0; row < size; row++)
		for(int col = 0; col < size; col++)
		{
			// If the square is not a blank, jump and check next square
			if(!isBlankSquare(b[row][col]))
				continue;

			// Check around the blank square for opponent disks
			for(int row_inc = -1; row_inc <= 1; row_inc++)
				for(int col_inc = -1; col_inc <= 1; col_inc++)
					if(isLegalMove(b, row, col, row_inc, col_inc, user))
					{
						m[row][col] = true;
						totalLegalMoves++;
					}
		}

	return totalLegalMoves;
}

// Function to get input from the user and to check it
void getInputMove(char b[][MAX_SIZE], bool m[][MAX_SIZE])
{
	char columnLetter = 0;
	int columnNumber = 0;
	int rowNumber = 0;

	while(true)
	{
		cin.sync();
		cout << "Choose a move [row + column]: ";
		cin >> rowNumber >> columnLetter;

		if(cin.fail())
		{
			cout << "Wrong input! Try again." << endl;
			cin.clear();
			cin.ignore(512, '\n');
			continue;
		}

		columnNumber = tolower(columnLetter) - 97;
		rowNumber--;

		if(m[rowNumber][columnNumber] && rowNumber>=0 && rowNumber<size 
									  && columnNumber>=0 && columnNumber<size)
		{
			makeMove(b, rowNumber, columnNumber, PLAYER_SYMBOL);
			fullSquares++;
			break;
		}
		else
			cout << "Choosen move is illegal, try again." << endl;
	}
}

// Function to check if the opponent disks are captured and change them
bool isCaptured(char b[][MAX_SIZE], int *x, int *y, int row, int col, 
									int row_inc, int col_inc, char user)
{
	char opponent = getOpponent(user);

	// Don't check outside the board or the current square
	if(isOutsideSquare(row+row_inc, col+col_inc) || (row_inc==0 && col_inc==0))
		return false;

	if(b[row + row_inc][col + col_inc] == opponent)
	{
		*x = row + row_inc;
		*y = col + col_inc;

		while(true)
		{
			*x += row_inc;
			*y += col_inc;

		// If we are off the board or we find a blank square return false
			if(isOutsideSquare(*x, *y) || isBlankSquare(b[*x][*y]))
				return false;

		// If we find a user disk, changing all the opponent disks to user
			if(b[*x][*y] == user)
				return true;
		}
	}
	else
		return false;
}

// Function to make a move on the board
void makeMove(char b[][MAX_SIZE], int row, int col, char user)
{
	char opponent = getOpponent(user);
	int x = 0, y = 0;

	b[row][col] = user;

	// Check all squares around for opponent disks and capture them if possible
	for(int row_inc = -1; row_inc <= 1; row_inc++)
		for(int col_inc = -1; col_inc <= 1; col_inc++)
			if(isCaptured(b, &x, &y, row, col, row_inc, col_inc, user))
				while(b[x-=row_inc][y-=col_inc] == opponent)
					b[x][y] = user;
}

// Function to find the best score for possible moves
int bestScore(char b[][MAX_SIZE], bool m[MAX_SIZE][MAX_SIZE], char user)
{
	char tempBoard[MAX_SIZE][MAX_SIZE];
	char opponent = getOpponent(user);
	int scoreBest = 0, score = 0;

	newBoard(tempBoard);

	for(int row = 0; row < size; row++)
		for(int col = 0; col < size; col++)
		{
			// Jump to the next square if the move is illegal
			if(m[row][col] == false)
				continue;

			// Copy the board to a temporary array
			for(int i = 0; i < size; i++)
				for(int j = 0; j < size; j++)
					tempBoard[i][j] = b[i][j];

			makeMove(tempBoard, row, col, user);

			// Check all board squares and get score of the board
			for(int rowS = 0; rowS < size; rowS++)
			{
				for(int colS = 0; colS < size; colS++)
				{ 
					if(b[rowS][colS] == COMPUTER_SYMBOL)
						score++;
					else if(b[rowS][colS] == PLAYER_SYMBOL)
						score--;
				}
			}
			// Save the best score
			if(score > scoreBest)
				scoreBest = score;
		}
	return scoreBest;
}

// Calculate the best move that computer has
void calculateBestComputerMove(char b[][MAX_SIZE], bool m[][MAX_SIZE], 
													int* rowB, int* colB)
{
	char tempBoard[MAX_SIZE][MAX_SIZE];
	bool tempMoves[MAX_SIZE][MAX_SIZE];
	int lowestScore = 0, highestScore = size*size;

	newBoard(tempBoard);

	// Initialize temporary moves array to false
	for(int i = 0; i < size; i++)
		for(int j = 0; j < size; j++)
			tempMoves[i][j] = false;

	// Go through all valid moves
	for(int row = 0; row < size; row++)
		for(int col = 0; col < size; col++)
		{
			if(m[row][col] == false)
				continue;

			// Copies the board to the temporary board
			for(int i = 0; i < size; i++)
				for(int j = 0; j < size; j++)
					tempBoard[i][j] = b[i][j];

			// Make move on temporary board for computer
			makeMove(tempBoard, row, col, COMPUTER_SYMBOL);

			// Find all legal moves for the opponent after computer's temp move
			getAllLegalMoves(tempBoard, tempMoves, PLAYER_SYMBOL);

			// Find the lowest best score for the opponent
			lowestScore = bestScore(tempBoard, tempMoves, PLAYER_SYMBOL);

			// If the lowest score is lower than the highest score, record it
			if(lowestScore < highestScore)
			{
				highestScore = lowestScore;
				// Save row and col for the best move for computer
				*rowB = row;
				*colB = col;
			}
		}
}

// Function to make computer move
void computersMove(char b[][MAX_SIZE], bool m[][MAX_SIZE])
{
	int rowBest = 0, colBest = 0;

	// Get the row and column of the best move
	calculateBestComputerMove(b, m, &rowBest, &colBest);

	// Makes the best move for the computer
	makeMove(b, rowBest, colBest, COMPUTER_SYMBOL); 
}

// Function to print the end text and final scores
void printFinalScore(char b[][MAX_SIZE])
{
	int playerScore = 0, computerScore = 0, blank = 0;

	// Checks all squares on the board
	for(int row = 0; row < size; row++)
		for(int col = 0; col < size; col++)
			// If the checked square is player's disk increase score by 1
			if(b[row][col] == PLAYER_SYMBOL)
                playerScore++;
			// If the checked square is computer's disk increase score by 1
			else if (b[row][col] == COMPUTER_SYMBOL)
				computerScore++;
			// Everything else is a blank
			else
				blank++;

	cout << "Game Over! ";

	if(computerScore > playerScore)
		cout << "Computer wins!" << endl;
	else if(playerScore > computerScore)
		cout << "Player wins!" << endl;
	else	// When playerScore == computerScore, then the game is a draw.
		cout <<"The game is a draw!" << endl;

	cout << "Final Scores: " << "Computer:" << computerScore; 
	cout << " Player:" << playerScore << endl;
}

// Function for gameloop of the game
void gameLoop(char b[][MAX_SIZE], bool m[][MAX_SIZE])
{
	do
	{
		printBoard(b);

		switch(whosTurnIs)
		{
			case true: // Player's turn
				if(getAllLegalMoves(b, m, PLAYER_SYMBOL))
				{
					// Read player inputs until a valid move is entered
					getInputMove(b, m);
				}
				else // No legal moves for the player
				{
					noMoreMoves++;
					if(noMoreMoves<2)
					{
						cin.sync();			// Clears the input buffer
		cout << "Computer: You don't have a legal move, my turn!" << endl;
					}
					else
		cout << "Computer: No more legal moves, the game is over!" << endl;
				}
				whosTurnIs = false;
				break;

			case false: // Computer's turn
				if(getAllLegalMoves(b, m, COMPUTER_SYMBOL)) 
				{
					computersMove(b, m);
					fullSquares++;			// Increment total move count
					noMoreMoves = 0;
				}
				else // No legal moves for the computer
				{
					noMoreMoves++;
					if(noMoreMoves<2)
		cout << "Computer: I don't have legal moves, it's your turn." << endl;
					else
		cout << "Computer: No more legal moves, the game is over!" << endl;
				}
				whosTurnIs = true;
				break;
		}
	}while(fullSquares < size*size && noMoreMoves<2);
}
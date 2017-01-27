// HW06_131044084_Mehmed_Mustafa
// Reversi.cpp
//
// Created on 05/12/2015 by Mehmed Mustafa
// Last Edited on 11/12/2015 by Mehmed Mustafa

#include "Reversi.h"
#include "string"

namespace{
	// Checks the validity of the height and width
	bool isValidSize(const int valH, const int valW){
		// If the height or width is smaller than 2, return false
		if(valH<=1 || valW<=1)
			return false;
		else // Return true
			return true;
	}
	// Determines the opponent for user
	char setOpponent(const char user){
		if(user == nameReversi::Reversi::PL_S) // If the user is player
			return nameReversi::Reversi::PC_S; // The opponent is computer
		else if (user == nameReversi::Reversi::PC_S) // If the user is computer
			return nameReversi::Reversi::PL_S; // The opponent is computer
		else // Error encountered, cuz the user can be only a player or computer
		{
			std::cerr << "Opponent identification error!" << std::endl;
			exit(1);
		}
	}
	// Takes integer and returns needed string
	std::string intToString(const int num){
		std::string stringFormat;

		// If the number is smaller or equal to 26
		// We have a single letter
		if(num <= 26)
		{
			// Store the numbers letter
			// For example A for the number 1
			// D for the number 4 and Z for the number 26
			stringFormat = (num-1 + 'A');
		}
		// If the number is bigger than 26 and smaller or equal to 701
		// We have double letters
		else if(num <= 701)
		{
			std::string firstLetter;
			std::string secondLetter;
        
			//Find the first letter
			firstLetter = toupper(num/26-1 + 'A');
			//Find the second letter
			secondLetter = toupper(num%26 + 'A');

			//Combine two letters into one string
			stringFormat = firstLetter + secondLetter;
		}
		else // If the number is bigger than 701 then stop the program
		{
			std::cout << "ERROR in intToString function."; 
			std::cout << "Width is bigger than expected" << std::endl;
			exit(1);
		}

		return stringFormat;    //Return the string format of the number
	}
	// Takes string and returns needed number
	int stringToInt(const std::string &move, const int width){
		int numberFormat = 0;

		if(move.empty())
			std::cout << "The " << move << " is empty" << std::endl;

		// If the width is smaller or equal to 26
		// We have a single letter
		if(width <= 26)
		{
			// Store the letters numbers
			// For example 1 for the letter A
			// 4 for the letter D and 26 for the letter Z      
			numberFormat = toupper(move[0]+1) - 'A';
		}
    
		// If the width is bigger than 26 and smaller or equal to 701
		// We have double letters
		else if(width <= 701)
		{
			// If the length of the string is 1, then we have a single letter
			if(move.length() == 1)
			{
				// Get the integer number of the given letter
				numberFormat = toupper(move[0]+1) - 'A';
			}
			// We have double letters
			else
			{
				// Get the first letter's number
				int firstLetter = toupper(move[0]+1) - 'A';
				// Get the secont letter's number
				int secondLetter = toupper(move[1]) - 'A';

				// Return the combination of the two numbers
				numberFormat = firstLetter*26 + secondLetter;
			}
		}
		else // If the width is bigger than 701 then stop the program
		{
			std::cout << "ERROR in intToString function."; 
			std::cout << "Width is bigger than expected" << std::endl;
			exit(1);
		}
	
		return numberFormat;    //Return the integer format of the string
	}
}

namespace nameReversi{
	
	/* PUBLIC FUNCTIONS FOR REVERSI CLASS */
	// Constructors
	Reversi::Reversi():height(4), width(4){
		newBoard(); // Make new board
		placeCenter(); // Place the central disks
		// Increase the total Reversi games, since Reversi object is created
		++totalReversiGames;
	}
	Reversi::Reversi(int valHeight):height(valHeight), width(4){
		if(!isValidSize(valHeight, 4)) // Check the validity of the height and width
		{
			std::cout << "Wrong dimension parameters within a constructor!" << std::endl;
			exit(1); // Exit if the parameters aren't valid
		}
		newBoard(); // Make new board
		placeCenter(); // Place the central disks
		// Increase the total Reversi games, since Reversi object is created
		++totalReversiGames;
	}
	Reversi::Reversi(int valHeight, int valWidth):height(valHeight), width(valWidth){
		if(!isValidSize(valHeight, valWidth)) // Check the validity of the height and width
		{
			std::cout << "Wrong dimension parameters within a constructor!" << std::endl;
			exit(1); // Exit if the parameters aren't valid
		}
		newBoard(); // Make new board
		placeCenter(); // Place the central disks
		// Increase the total Reversi games, since Reversi object is created
		++totalReversiGames;
	}
	// Copy Constructor
	Reversi::Reversi(const Reversi& otherObj){
		height = otherObj.getHeight();
		width = otherObj.getWidth();
		sizeGame = height*width;

		gameCells = new Cell[sizeGame];
		for(int i=0; i<sizeGame; ++i)
			gameCells[i] = otherObj.gameCells[i];

		legalMoves = new Cell[sizeGame];
		for(int i=0; i<sizeGame; ++i)
			legalMoves[i] = otherObj.legalMoves[i];
        
        ++totalReversiGames;
	}
	// Displays current board on the console
	void Reversi::displayBoard() const{
		int columnNumber = 0;
		int rowNumber = 0;

		// Prints the column letters
		std::cout << std::endl << std::setw(2) << "";
		for(int column = 0; column<width; column++)
		{
			++columnNumber;
			if(columnNumber <= 26)
				std::cout << std::setw(2) << intToString(columnNumber);
			else if(columnNumber <= 701)
				std::cout << std::setw(2) << intToString(columnNumber);
		}
		std::cout << std::endl; // Go to the next line

		// Prints the rest of the board
		for(int row = 0; row < height; ++row)
		{
			std::cout << std::setw(2) << ++rowNumber;
			for(int col = 0; col < width; ++col)
			{
				std::cout << std::setw(2) << gameCells[row*width + col].getS();
			}
			std::cout << std::endl;	
		}
		std::cout << std::endl << std::endl;
	}
	// Resize the board and reset the game
	void Reversi::resizeBoard(const int valH, const int valW){
		// Reallocate memory if the pointers aren't NULL
		if(gameCells != NULL)
			delete [] gameCells;
		if(legalMoves != NULL)
			delete [] legalMoves;

		height = valH; // Set new value for height of the board
		width = valW; // Set new value for width of the board
		newBoard(); // Make new board
		placeCenter(); // Place the central disks
	}
	// Checks if the game is over
	bool Reversi::isGameEnded(){
		// If the player or the computer don't have any legal moves, game is ended
		if(getLegalMoves(gameCells, sizeGame, legalMoves, PL_S) || 
			getLegalMoves(gameCells, sizeGame, legalMoves, PL_S))
			return false;
		else
		{
			return true;
		}
	}
	// Play move for the computer
	void Reversi::play(){
		int rowBest = 0, colBest = 0;

		if(getLegalMoves(gameCells, sizeGame, legalMoves, PC_S))
		{
			// Get the row and column of the best move
			calculateBestComputerMove(gameCells, sizeGame, legalMoves, 
											&rowBest, &colBest);
			// Makes the best move for the computer
			makeMove(gameCells, rowBest, colBest, PC_S);
			// Prints on the console which move is choosen from the computer
			std::cout << "Computer: I make move <" << ++rowBest << ", "; 
			std::cout << intToString(++colBest) << ">" << std::endl;

		}
		else
			std::cout << "Computer: I don't have legal moves!" << std::endl;
	}
	// Gets move for the player and plays
	void Reversi::play(const Cell &square){
		int x = square.getX() - 1;
		int y = square.getY() - 1;
    
		getLegalMoves(gameCells, sizeGame, legalMoves, PL_S);
    
		// Check the move given as a parameter to play()
		// And if the move is illegal, make move for the computer
		// Player miss 1 move
		if(!checkMove(legalMoves, x, y))
		{
			std::cout << "The move " << square.getX() << " "; 
			std::cout << square.getY() << " is illegal!" << std::endl;
			std::cout << "Computer: You miss your turn! My turn!" << std::endl;
			play();
			return;
		}
        
		// Make move for the user
		makeMove(gameCells, x, y, PL_S);
    
	}
	// Plays the entire game
	void Reversi::playGame(){
		getSize();	// Get the size of the board from the console
		resizeBoard(height, width);
		displayBoard(); // Display board on the console

		bool whosTurnIs = true; // Checks whos turn is
		int row = 0, col = 0; // Row and Column for InputMoves from player
		int illegalMoveCounter = 0; // Controls when the game ends
		// If the both player and computer don't have legal moves in series
		// (illegalMoveCounter = 2) then end the game

		do
		{
			switch(whosTurnIs) // Check who's turn is
			{
				case true: // Player's turn
					if(getLegalMoves(gameCells, sizeGame, legalMoves, PL_S))
					// If the player has any legal moves then
					{
						printLegalMoves();      // Print available moves for player
						getInputMove(row, col); // Get move from the console
						++row;
						++col;
						play(Cell(row, col));	// Make the move
						displayBoard();			// Display the new board
					}
					else // No legal moves for the player
					{
						std::cin.sync();
						++illegalMoveCounter; // The illegal move counter is 1
			std::cout << "Computer: You don't have any legal moves, my turn!" << std::endl;
					}
					whosTurnIs = false; // Change the turn to the computer
					break;

				case false: // Computer's turn
					if(getLegalMoves(gameCells, sizeGame, legalMoves, PC_S))
					// If the computer has any legal moves then
					{
						// Computer have legal move, so reset the counter
						illegalMoveCounter = 0; 
						play(); // Make move for the computer
						displayBoard(); // Display the new board
					}
					else // No legal moves for the computer
					{
						// If the player had a legal move then
						if(++illegalMoveCounter < 2) 
		std::cout << "Computer: I don't have any legal moves, it's your turn." << std::endl;
						// Since the both player and computer 
						// didn't have legal moves the game is over
						else 
					std::cout << "Computer: We both don't have any legal moves!" << std::endl;
					}
					whosTurnIs = true;	// Change the turn to the player
					break;
			}
		// while both player and computer don't have legal moves
		}while(illegalMoveCounter < 2); 
		std::cin.sync();
    
		endGameOutput(); // Print the final score on the console
	}
	// Compares 2 reversi objects
	bool Reversi::compare(const Reversi &other)const{
		// Get points for the player from the main game
		int plScore = getScore(PL_S) - getScore(PC_S);
		// Get points for the player from the other game
		int otherPlScore = other.getScore(PL_S) - other.getScore(PC_S);

		// If the score of the main game is better, return true
		if(plScore > otherPlScore)
			return true;
		else // Return false
			return false;
	}

	Reversi& Reversi::operator =(const Reversi& rightSide){
		if(this == &rightSide)
			return *this; //If the other object is this object, do nothing
		else
		{
			height = rightSide.getHeight();
			width = rightSide.getWidth();
			sizeGame = height*width;

			delete [] gameCells;
			gameCells = new Cell[sizeGame];
			for(int i=0; i<sizeGame; ++i)
				gameCells[i] = rightSide.gameCells[i];

			delete [] legalMoves;
			legalMoves = new Cell[sizeGame];
			for(int i=0; i<sizeGame; ++i)
				legalMoves[i] = rightSide.legalMoves[i];

			return *this;
		}
	}
	//Prefix version
	//Return the board after increment
	Reversi Reversi::operator ++(){
		getLegalMoves(gameCells, sizeGame, legalMoves, PC_S);
		play();
		return *this;
	}
	//Postfix version
	//Return the board before increment
	Reversi Reversi::operator ++(int ignoreMe){
		Reversi temp;
		temp = *this;
		getLegalMoves(gameCells, sizeGame, legalMoves, PC_S);
		play();
		return temp;
	}
	std::ostream& operator <<(std::ostream& output, const Reversi& game){
		int columnNumber = 0;
		int rowNumber = 0;

		// Prints the column letters
		output << std::endl << std::setw(2) << "";
		for(int column = 0; column<(game.width); column++)
		{
			++columnNumber;
			if(columnNumber <= 26)
				output << std::setw(2) << intToString(columnNumber);
			else if(columnNumber <= 701)
				output << std::setw(2) << intToString(columnNumber);
		}
		output << std::endl; // Go to the next line

		// Prints the rest of the board
		for(int row = 0; row < game.height; ++row)
		{
			output << std::setw(2) << ++rowNumber;
			for(int col = 0; col < game.width; ++col)
			{
				output << std::setw(2) << game.gameCells[row*(game.width) + col].getS();
			}
			output << std::endl;	
		}
		output << std::endl << std::endl;

		return output;
	}

	// Destructor
	Reversi::~Reversi(){
		// Reallocate memory if the pointers aren't NULL
		if(gameCells != NULL)
			delete [] gameCells;
		if(legalMoves != NULL)
			delete [] legalMoves;

		// Decrease the total Reversi games, since Reversi object is destroyed
		--totalReversiGames;
	}


	/* PRIVATE FUNCTIONS FOR REVERSI CLASS */
	// Prepare the new board of the game placing '.'
	void Reversi::newBoard(){
		// Set the size for gameCells array
		sizeGame = height*width;
		gameCells = new Cell[sizeGame]; // Allocate memory for gameCells
		legalMoves = new Cell[sizeGame]; // Allocate memory for legalMoves

		for(int row = 0; row < height; ++row)
		{
			for(int col = 0; col < width; ++col)
			{
				gameCells[row*width + col] = Cell(row, col, '.');
				legalMoves[row*width + col] = Cell(row, col, 'N'); // Not legal move
			}
		}
	}
	// Place the central disks
	void Reversi::placeCenter(){
		// Place central disks for the board
		gameCells[width*(height/2-1) + width/2-1] = Cell(height/2-1, width/2-1, Reversi::PC_S);
		gameCells[width*(height/2-1) + width/2] = (Cell(height/2-1, width/2, Reversi::PL_S));
		gameCells[width*(height/2) + width/2-1] = (Cell(height/2, width/2-1, Reversi::PL_S));
		gameCells[width*(height/2) + width/2] = (Cell(height/2, width/2, Reversi::PC_S));
	}
	// Checks if the given square is outside
	bool Reversi::isOutside(const int x, const int y)const{
	if(x < 0 || x >= height || y < 0 || y >= width)
		return true;
	else
		return false;
	}
	// Checks if the given square is living and gets it's symbol
	bool Reversi::isLivingCell(const Cell *cells, const int x, const int y, char &s)const{
		// If we find a living cell
		if(cells[x*width+y].getS() != '.')
		{
			s = cells[x*width+y].getS(); // Get the symbol of that cell
			return true; // The cell is found at the given coordinates
		}

		// The searched cell isn't found, it's not living
		return false;
	}
	// Checks if the given move is legal or not
	bool Reversi::isLegalMove(const Cell *cells,
		const int row, const int col, const int dx, const int dy, const char user){

		char opponent = setOpponent(user); // Identify the opponent

		// If we are outside the board while moving on choosen direction
		// Or we are on the current square (dx = 0, dy = 0)
		if(isOutside(row + dx, col + dy) || (dx == 0 && dy == 0))
			return false; // then return false, the move is illegal

		char sOpp; // Symbol of opponent
		if(isLivingCell(cells, row + dx, col + dy, sOpp))
		{
			if (sOpp == opponent) // If we find opponent symbol
			{
				int x = row + dx; // Initialize opponent's Row
				int y = col + dy; // Initialize opponent's Column

				// Look for a user square in the dx and dy direction
				while(true)
				{
					x += dx; // Move in dx direction
					y += dy; // Move in dy direction

					// If we are off the board
					if(isOutside(x, y))
						return false; // then return false, the move is illegal

					char sUser; // Symbol of user
					if(isLivingCell(cells, x, y, sUser)) 
					{
						if(sUser == user) // If we find user symbol
							return true; // then the move is legal
					}
				}
			}
		}

		return false;
	}
	// Checks if the given move is on the legals vector
	bool Reversi::checkMove(const Cell *legals, const int x, const int y)const{
		// If the move is in the legalMoves array return true
		if(legals[x*width+y].getS() == 'Y') // Y - yes
			return true;
		else if(legals[x*width+y].getS() == 'N') // N - no
			return false;
		else
		{
			std::cout << "ERROR in checkMove function" << std::endl;
			exit(1);
		}
	}
	// Resets legalsMove array
	void Reversi::refreshLegals(Cell *legals){
		for(int row = 0; row < height; ++row)
			for(int col = 0; col < width; ++col)
			{
				// Not legal move
				legalMoves[row*width + col] = Cell(row, col, 'N');
			}
	}
	// Checks if legalsMove array is empty
	bool Reversi::isEmptyLegals(Cell *legals){
		for(int row = 0; row < height; ++row)
			for(int col = 0; col < width; ++col)
			{
				// Return false if a move is found
				if(legalMoves[row*width + col].getS() == 'Y')
					return false;
			}

		//Return true if a move isn't found
		return true;
	}
	// Gets all legal moves and save them on the legals vector
	int  Reversi::getLegalMoves(const Cell *cells, const int sizeGame,
									Cell *legals, const char user){

		// Clears the array that holds all legal moves
		refreshLegals(legals);
		int numLegal = 0; // Counter for legal moves

		char junk; // This is useful, it's needed as a parameter of isLivingCell
		for(int row = 0; row < height; ++row)
			for(int col = 0; col < width; ++col)
			{
				// If the cell is living, the move cannot be legal
				// Legal move is only on empty cells
				if(isLivingCell(cells, row, col, junk))
					continue;

				// If we have any saved moves and 
				// the current ROW and COL is saved as legal move
				if(!isEmptyLegals(legals) && checkMove(legals, row, col)) 
					break; // Don't continue looking and break

				// If no, continue looking
				for(int dRow = -1; dRow <= 1; ++dRow)
					for(int dCol = -1; dCol <= 1; ++dCol)
						// If the move is legal
						if(isLegalMove(cells, row, col, dRow, dCol, user))
						{
							// Set it to Y - yes
							legals[row*width+col].setS('Y');
							++numLegal; // increase legal moves counter
						}
			}

		return numLegal;
	}
	// Prints the legal moves on the console
	void Reversi::printLegalMoves()const{
		int m = 0; // Legal moves counter for a line
		//Prints the legal moves for the player
		std::cout << "Computer: Your legal moves are: " << std::endl;
		for(int i = 0; i < sizeGame; ++i)
		{
			if(legalMoves[i].getS() == 'Y')
			{
				std::cout << "<" << legalMoves[i].getX()+1 << ", "; 
				std::cout << intToString(legalMoves[i].getY()+1) << "> ";
				++m; // Increase legal moves counter by 1 after a legal move is printed
				if(m/8 == 1) // prints no more of 8 legal moves for a line
				{
					std::cout << std::endl;
					m = 0; // Reset legal moves counter for a line
				}
			}
		}

		std::cout << std::endl;
	}
	// Gets the input move from the console
	void Reversi::getInputMove(int &row, int &col){
		std::string columnLetter;
		int columnNumber = 0;
		int rowNumber = 0;

		while(true)
		{
			for(;;) // Loop to take move's row until correct input
			{
				//cin.sync();
				std::cout << "Choose a move's row: ";
				std::cin >> rowNumber; // Get row number
				// If the input fails or row number is bigger than height
				if(std::cin.fail() || rowNumber > height)
				{
					std::cout << "Wrong row input! Try again." << std::endl;
					std::cin.clear(); // Clear the buffer
					std::cin.ignore(2000, '\n'); // Ignore 2000 symbols until '\n'
					continue; // continue to get input
				}
				else
				{
					std::cin.clear(); // Clear the buffer
					std::cin.ignore(2000, '\n'); // Ignore 2000 symbols until '\n'
					break; // Break the loop
				}
			}

			for(;;) // Loop to take move's column until correct input
			{
				//cin.sync();
				std::cout << "Choose a move's column: ";
				std::cin >> columnLetter;
				columnNumber = stringToInt(columnLetter, width);
				if(columnNumber > width) // If the column number is bigger than width
				{
					std::cout << "Wrong column input! Try again." << std::endl;
					std::cin.clear(); // Clear the buffer
					std::cin.ignore(2000, '\n'); // Ignore 2000 symbols until '\n'
					continue; // continue to get input
				}
				else
				{
					std::cin.clear(); // Clear the buffer
					std::cin.ignore(2000, '\n'); // Ignore 2000 symbols until '\n'
					break; // Break the loop
				}
			}

			--columnNumber;
			--rowNumber;

		// If the move is avaible on legalMoves vector and isn't outside the board
			if(checkMove(legalMoves, rowNumber, columnNumber) && 
						!(isOutside(rowNumber, columnNumber)))
			{
				row = rowNumber;	// Mark the row of the move
				col = columnNumber;	// Mark the column of the move
				break;
			}
			else
				std::cout << "Choosen move is illegal, try again." << std::endl;
		}

	}
	// Checks if a disk is captured or not
	bool Reversi::isCaptured(const Cell *cells, int *x, int *y, 
			const int row, const int col, const int dx, const int dy, const char user){
		char opponent = setOpponent(user); // Identify the opponent

		// If we are outside the board while moving on choosen direction
		// Or we are on the current square (dx = 0, dy = 0)
		if(isOutside(row + dx, col + dy) || (dx == 0 && dy == 0))
			return false; // then return false, the move is illegal

		char sOpp; // Symbol of opponent
		if(isLivingCell(cells, row + dx, col + dy, sOpp))
		{
			if (sOpp == opponent)
			{
				*x = row + dx; // Initialize opponent's Row
				*y = col + dy; // Initialize opponent's Column

				// Look for a user square in the dx and dy direction
				while(true)
				{
					*x += dx; // Move in dx direction
					*y += dy; // Move in dy direction

					// If we are off the board
					if(isOutside(*x, *y))
						return false;

					char sUser; // Symbol of user
					if(isLivingCell(cells, *x, *y, sUser))
					{
						if(sUser == user)
							return true;
					}
				}
			}
		}

		return false;
	}
	// Make move on the board
	void Reversi::makeMove(Cell *cells, const int row, const int col, const char user){
		char opponent = setOpponent(user); // Identify the opponent
		int x = 0, y = 0;

		// Make move for the user
		cells[row*width+col].setS(user);

		// Check all squares around for opponent disks and capture them if possible
		for(int row_inc = -1; row_inc <= 1; row_inc++)
			for(int col_inc = -1; col_inc <= 1; col_inc++)
				if(isCaptured(cells, &x, &y, row, col, row_inc, col_inc, user))
				{
					char sOpp; // Symbol of opponent
					// While we seek opponent disk
					while(isLivingCell(cells, x-=row_inc, y-=col_inc, sOpp) && 
																 sOpp == opponent)
					{
						// Capture the disks
						cells[x*width+y].setS(user); // Set the user symbol to that cell
					}
				}
	}
	// Calculates the best move for the computer
	void Reversi::calculateBestComputerMove(const Cell *cells, const int sizeBoard,
                      Cell *legals, int *rowB, int *colB){

		int bestScore = 1; // Best score is at least 1 if there is a legal move

		for(int row = 0; row < height; ++row)
			for(int col = 0; col < width; ++col)
			{
				// If the move is illegal continue
				if(!checkMove(legals, row, col)) 
					continue;

				// Make temporary 2D vector
				Cell *tempGameCells = new Cell[sizeBoard];
				for(int i=0; i<sizeBoard; ++i)
				{
					tempGameCells[i] = cells[i];
				}

				// Make move for computer
				makeMove(tempGameCells, row, col, PC_S);

				int score = 0;
				// Evaluate the board, get the score for computer
				for(int i = 0; i < sizeBoard; ++i)
					if(tempGameCells[i].getS() == PC_S)
						++score;

				// Save the best score
				if(score > bestScore)
				{
					bestScore = score;
					// Save row and col for the best move for computer
					*rowB = row;
					*colB = col;
				}

				if(tempGameCells != NULL)
					delete [] tempGameCells;
			}
	}
	// Gets board dimensions from the console
	void Reversi::getSize(){
		while(true)
		{
			std::cout << "Please enter the size of rows(height): ";
			std::cin >> height; // Get the height of the board from the console
				while(std::cin.fail()) // Loop while the input is illegal
				{
					std::cout << "Wrong input! The input must be an integer. ";
					std::cout << "Try again!" << std::endl;
					std::cin.clear(); // Clear the buffer
					std::cin.ignore(2000, '\n'); // Ignore 2000 symbols until '\n'
					std::cout << "Please enter the size of rows(height): ";
					std::cin >> height; // Get new input for height
				}
			std::cin.ignore(2000, '\n'); // Ignore 2000 symbols until '\n'

			std::cout << "Please enter the size of columns(width): ";
			std::cin >> width; // Get the width of the board from the console
				while(std::cin.fail()) // Loop while the input is illegal
				{
					std::cout << "Wrong input! The input must be an integer. ";
					std::cout << "Try again!" << std::endl;
					std::cin.clear(); // Clear the buffer
					std::cin.ignore(2000, '\n'); // Ignore 2000 symbols until '\n'
					std::cout << "Please enter the size of columns(width): ";
					std::cin >> width; // Get new input for width
				}
			std::cin.ignore(2000, '\n'); // Ignore 2000 symbols until '\n'

			if(!isValidSize(height, width)) // Check if the height and width are legal
			{
				std::cout << "Wrong dimension parameters!" << std::endl;
				std::cout << "Check again the height and the width!" << std::endl;
			}
			else
				return;
		}
	}
	// Returns how many disks the user has
	int  Reversi::getScore(const char user)const{
		int userScore = 0;

		for(int i = 0; i < sizeGame; ++i)
			// If the user disk is encountered, increase score
			if(gameCells[i].getS() == user)
				++userScore;

		return userScore; // Return total number of disks for the user
	}
	// Prints the final score
	void Reversi::endGameOutput()const{
		int p = getScore(PL_S); // Gets player score
		int c = getScore(PC_S); // Gets computer score

		std::cout << "The game is over!" << std::endl << std::endl;
		// Print the scores of the player and computer
		std::cout << "Player: " << p << " Computer: " << c << std::endl;
	
		if(p>c) // If the player has more scores
			std::cout << "The player wins the game!" << std::endl << std::endl;
		else if(c>p) // If the computer has more scores
			std::cout << "The computer wins the game!" << std::endl << std::endl;
		else // (c == p) // When the scores are equal
			std::cout << "The game is drawn!" << std::endl << std::endl;
	}

	// Initializing the static variable
	int Reversi::totalReversiGames = 0; // Counter for the living cells
}
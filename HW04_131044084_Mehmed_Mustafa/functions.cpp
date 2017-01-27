// HW04_131044084_Mehmed_Mustafa
// header.h
//
// Created on 13/11/2015 by Mehmed Mustafa
// Last Edited on 23/11/2015 by Mehmed Mustafa

// Odev verildiginde BIG THREE ve namespace konulari
// islenmemisti, bu yuzden isimsiz namespace kullanmadim

#include "header.h"

Cell::Cell(int valX, int valY, char valS):X(valX), Y(valY), S(valS){}
// Public functions of the Reversi class
Reversi::Reversi():height(4), width(4){
    placeCenter(); // Place the 4 disks on the center at the beggining
}
Reversi::Reversi(int valHeight):height(valHeight), width(4){
	if(!isValidSize()) // Check the validity of the height and width
	{
		cout << "Wrong dimension parameters within a constructor!" << endl;
		exit(1); // Exit if the parameters aren't valid
	}
    placeCenter(); // Place the 4 disks on the center at the beggining
}
Reversi::Reversi(int valHeight, int valWidth):height(valHeight), width(valWidth){
	if(!isValidSize()) // Check the validity of the height and width
	{
		cout << "Wrong dimension parameters within a constructor!" << endl;
		exit(1); // Exit if the parameters aren't valid
	}
    placeCenter(); // Place the 4 disks on the center at the beggining
}
void Reversi::displayBoard()const{
	int columnNumber = 0;
	int rowNumber = 0;

	// Prints the column letters
	cout << endl << setw(3) << "";
	for(int column = 0; column<width; column++)
	{
		++columnNumber;
		if(columnNumber <= 26)
			cout << setw(2) << intToString(columnNumber);
		else if(columnNumber <= 701)
			cout << setw(3) << intToString(columnNumber);
	}
	cout << endl; // Go to the next line

	// Print the rest of the board
	//Check all row's in the vector<vector<Cell>> gameCells
	for(int row=0; row<height; ++row)
	{
		// Print row number
		cout << setw(3) << ++rowNumber;
		//Check all column's in the given row
		for(int y=0; y<width; ++y)
		{
            //If we have only single letter
			if(y <= 26)
			{
				bool isFind = false;
				//Check all cells in the given column
				for(unsigned int column = 0; column<gameCells[row].size(); ++column)
				{
					//if cell is found at Cell[x][y] print it's symbol
					if(y == gameCells[row][column].getY())
					{
						cout << setw(2) << gameCells[row][column].getS();
						isFind = true;
					}
				}
				if(!isFind) // If the cell is not found, print blank
					cout << setw(2) << '.';
			}
            //If we have double letters
			else if(y <= 701)
			{
				bool isFind = false;
				//Check all cells in the given column
				for(unsigned int column = 0; column<gameCells[row].size(); ++column)
				{
					//if cell is found at Cell[x][y] print it's symbol
					if(y == gameCells[row][column].getY())
					{
						cout << setw(3) << gameCells[row][column].getS();
						isFind = true;
					}
				}
				if(!isFind) // If the cell is not found, print blank
					cout << setw(3) << '.';
			}
		}
		cout << endl; // Go to the next line
	}

	cout << endl;
}
bool Reversi::isGameEnded(){
	// If the player or the computer don't have any legal moves, game is ended
	if(getLegalMoves(gameCells, legalMoves, PL_S) || 
		getLegalMoves(gameCells, legalMoves, PC_S))
		return false;
	else
    {
        // Decrease living cells after the game is finished
        decreaseLivingCells(); 
		return true;
    }
}
void Reversi::play(){
	int rowBest = 0, colBest = 0;

    if(getLegalMoves(gameCells, legalMoves, PC_S))
    {
        // Get the row and column of the best move
        calculateBestComputerMove(gameCells, legalMoves, &rowBest, &colBest);
        // Makes the best move for the computer
        makeMove(gameCells, rowBest, colBest, PC_S);
        // Prints on the console which move is choosen from the computer
        cout << "Computer: I make move <" << ++rowBest << ", "; 
        cout << intToString(++colBest) << ">" << endl;

        // Increase total living cells after the move is done
        ++totalLivingCells;
    }
    else
        cout << "Computer: I don't have legal moves!" << endl;
}
void Reversi::play(const Cell &square){
    int x = square.getX() - 1;
    int y = square.getY() - 1;
    
    getLegalMoves(gameCells, legalMoves, PL_S);
    
    // Check the move given as a parameter to play()
    // And if the move is illegal, make move for the computer
    // Player miss 1 move
    if(!checkMove(legalMoves, x, y))
    {
        cout << "The move " << square.getX() << " "; 
        cout << square.getY() << " is illegal!" << endl;
        cout << "Computer: You miss your turn! My turn!" << endl;
        play();
        return;
    }
        
	// Make move for the user
	makeMove(gameCells, x, y, PL_S);
    
    // Increase total living cells after the move is done
	++totalLivingCells;
}
void Reversi::playGame(){
	getSize();	// Get the size of the board from the console
	placeCenter();	// Place the central disks
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
				if(getLegalMoves(gameCells, legalMoves, PL_S))
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
					cin.sync();
					++illegalMoveCounter; // The illegal move counter is 1
		cout << "Computer: You don't have any legal moves, my turn!" << endl;
				}
				whosTurnIs = false; // Change the turn to the computer
				break;

			case false: // Computer's turn
				if(getLegalMoves(gameCells, legalMoves, PC_S))
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
	cout << "Computer: I don't have any legal moves, it's your turn." << endl;
					// Since the both player and computer 
                    // didn't have legal moves the game is over
					else 
                cout << "Computer: We both don't have any legal moves!" << endl;
				}
				whosTurnIs = true;	// Change the turn to the player
				break;
		}
    // while both player and computer don't have legal moves
	}while(illegalMoveCounter < 2); 
    cin.sync();
    
    decreaseLivingCells(); // Decrease living cells after the game is finished
	endGameOutput(); // Print the final score on the console
}
void Reversi::write(const char* fileName) const{
	ofstream outStream;
	outStream.open(fileName); // Open the output file
	if(outStream.fail()) // If the opening is failed, stop the program
	{
		cerr << "Output file opening failed." << endl;
		exit(1);
	}

	outStream << height << endl;    // Save the height to the output file
	outStream << width << endl;     // Save the width to the output file
	
	bool symbolFound = false;   // For checking if we have found a symbol or not
	for(int row=0; row < height; ++row)
	{
		for(int col=0; col < width; ++col)
		{
			symbolFound = false; // Reset checker
			for(unsigned int vCol = 0; vCol < gameCells[row].size(); ++vCol)
			{
                // If we encounter living cell 
				if(gameCells[row][vCol].getX() == row && 
					gameCells[row][vCol].getY() == col &&
					(gameCells[row][vCol].getS() == PL_S ||
					gameCells[row][vCol].getS() == PC_S))
				{
                    // save it's symbol to the output file
					outStream << gameCells[row][vCol].getS();
					symbolFound = true; // We have found a symbol
				}
			}
			if(!symbolFound) // If we haven't found a symbol
				outStream << '.'; // Print a blank on the output file
		}
		outStream << endl; // Print a new line after every vector
	}
    
    // Print on the console the name of the output file where the game is saved
	cout << "Your game was saved to " << fileName << endl;
	outStream.close();  // Close the output file
}
void Reversi::read(const char* fileName){
	ifstream inStream;
	inStream.open(fileName);    // Open the input file
	if(inStream.fail())         // If the opening is failed, stop the program
	{
		cerr << "Input file opening failed." << endl;
		exit(1);
	}

	// Decrease total living cell number by removing old values
	// Before loading from the text file
	for(unsigned int i = 0; i < gameCells.size(); ++i)
		for(unsigned int j = 0; j < gameCells[i].size(); ++j)
			if(gameCells[i][j].getS() == PL_S ||
				gameCells[i][j].getS() == PC_S)
				--totalLivingCells;

	inStream >> height; // Load the height from the input file
	inStream >> width;  // Load the width from the input file

	gameCells.clear();          // Refresh the 2D vector
	gameCells.resize(height);   // Resize the 2D vector to height

	char symbol;
	for(int row=0; row < height; ++row)
		for(int col=0; col < width; )
		{
			inStream.get(symbol);   //Read a symbol from the input file
			if(symbol != '\n')  // If the symbol is not endline symbol
			{
                // And the symbol is either player or computer
				if(symbol == PL_S || symbol == PC_S)
					++totalLivingCells; // Increase total living cells
                
                //And save the cell with it's row and col coordinates
                // and it's symbol
				gameCells[row].push_back(Cell(row, col, symbol));
				++col;  // Go to the next column
			}
			if(inStream.eof()) // If we reach the end of the file
				break;  // Stop reading from the file
		}
    
    // Print on the console the name of the input file where the game is loaded
	cout << "Your game was loaded from " << fileName << endl;
	inStream.close();   // Close the input file
}
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
string Reversi::intToString(const int num)const{
	string stringFormat;

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
		string firstLetter;
		string secondLetter;
        
        //Find the first letter
		firstLetter = toupper(num/26-1 + 'A');
        //Find the second letter
		secondLetter = toupper(num%26 + 'A');

        //Combine two letters into one string
		stringFormat = firstLetter + secondLetter;
	}
	else // If the number is bigger than 701 then stop the program
	{
		cout << "ERROR in intToString function."; 
        cout << "Width is bigger than expected" << endl;
		exit(1);
	}

	return stringFormat;    //Return the string format of the number
}
int Reversi::stringToInt(const string &move)const{
	int numberFormat = 0;

	if(move.empty())
		cout << "The " << move << " is empty" << endl;

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
		cout << "ERROR in intToString function."; 
        cout << "Width is bigger than expected" << endl;
		exit(1);
	}
	
	return numberFormat;    //Return the integer format of the string
}

// Private functions of the Reversi class
bool Reversi::isValidSize()const{
    // If the height or width is smaller than 2, return false
	if(height<=1 || width<=1)
		return false;
	else // Return true
		return true;
}
void Reversi::getSize(){
	while(true)
	{
		cout << "Please enter the size of rows(height): ";
		cin >> height; // Get the height of the board from the console
			while(cin.fail()) // Loop while the input is illegal
			{
				cout << "Wrong input! The input must be an integer. ";
                cout << "Try again!" << endl;
				cin.clear(); // Clear the buffer
				cin.ignore(2000, '\n'); // Ignore 2000 symbols until '\n'
				cout << "Please enter the size of rows(height): ";
				cin >> height; // Get new input for height
			}
		cin.ignore(2000, '\n'); // Ignore 2000 symbols until '\n'

		cout << "Please enter the size of columns(width): ";
		cin >> width; // Get the width of the board from the console
			while(cin.fail()) // Loop while the input is illegal
			{
				cout << "Wrong input! The input must be an integer. ";
                cout << "Try again!" << endl;
				cin.clear(); // Clear the buffer
				cin.ignore(2000, '\n'); // Ignore 2000 symbols until '\n'
				cout << "Please enter the size of columns(width): ";
				cin >> width; // Get new input for width
			}
		cin.ignore(2000, '\n'); // Ignore 2000 symbols until '\n'

		if(!isValidSize()) // Check if the height and width are legal
		{
			cout << "Wrong dimension parameters!" << endl;
			cout << "Check again the height and the width!" << endl;
		}
		else
			return;
	}
}
int  Reversi::getScore(const char user)const{
	int userScore = 0;

	for(unsigned int i = 0; i < gameCells.size(); ++i)
		for(unsigned int j = 0; j < gameCells[i].size(); ++j)
            // If the user disk is encountered, increase score
			if(gameCells[i][j].getS() == user)
				++userScore;

	return userScore; // Return total number of disks for the user
}
void Reversi::decreaseLivingCells(){
    // Decrease total living cell number by removing old values
	// Since the game is finished
	for(unsigned int i = 0; i < gameCells.size(); ++i)
		for(unsigned int j = 0; j < gameCells[i].size(); ++j)
            // If PL_S or PC_S is encountered, decrease totalLivingCells
			if(gameCells[i][j].getS() == PL_S ||
				gameCells[i][j].getS() == PC_S)
				--totalLivingCells;
}
void Reversi::endGameOutput() const{
	int p = getScore(PL_S); // Gets player score
	int c = getScore(PC_S); // Gets computer score

	cout << "The game is over!" << endl << endl;
    // Print the scores of the player and computer
	cout << "Player: " << p << " Computer: " << c << endl;
	
	if(p>c) // If the player has more scores
		cout << "The player wins the game!" << endl << endl;
	else if(c>p) // If the computer has more scores
		cout << "The computer wins the game!" << endl << endl;
	else // (c == p) // When the scores are equal
		cout << "The game is drawn!" << endl << endl;
}
char Reversi::setOpponent(const char user)const{
	if(user == PL_S) // If the user is player
		return PC_S; // The opponent is computer
	else if (user == PC_S) // If the user is computer
		return PL_S; // The opponent is computer
	else // Error encountered, cuz the user can be only a player or computer
	{
		cerr << "Opponent identification error!" << endl;
		exit(1);
	}
}
bool Reversi::isOutside(const int x, const int y)const{
	if(x < 0 || x >= height || y < 0 || y >= width)
		return true;
	else
		return false;
}
void Reversi::placeCenter(){
	gameCells.clear(); // Refresh the 2D vector
	gameCells.resize(height); // Resize it to height of the board

    // Place central disks for the board
	gameCells[height/2 - 1].push_back(Cell(height/2-1, width/2-1, PC_S));
	gameCells[height/2 - 1].push_back(Cell(height/2-1, width/2, PL_S));
	gameCells[height/2].push_back(Cell(height/2, width/2-1, PL_S));
	gameCells[height/2].push_back(Cell(height/2, width/2, PC_S));

    // Increase total living cells by 4 since 4 disks are placed
	totalLivingCells += 4;
}
bool Reversi::isLivingCell(const vector<vector<Cell> > &cells, 
    const int x, const int y, char &s) const{

	for(int col=0; col<width; ++col)
	{
		//Check x'th row's cells
		for(unsigned int i = 0; i<gameCells[x].size(); ++i)
		{
			// If we find a living cell
			if(y == gameCells[x][i].getY())
			{
				s = gameCells[x][i].getS(); // Get the symbol of that cell
				return true; // The cell is found at the given coordinates
			}
		}
	}
	// The searched cell isn't found, it's not living
	return false;
}
bool Reversi::isLegalMove(const vector<vector<Cell> > &cells, 
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
int  Reversi::getLegalMoves(const vector<vector<Cell> > &cells, 
                           vector<Cell> &legals, const char user){
	legals.clear(); // Clears the vector that holds all legal moves

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
			if(!legals.empty() && checkMove(legals, row, col)) 
				break; // Don't continue looking and break

			// If no, continue looking
			for(int dRow = -1; dRow <= 1; ++dRow)
				for(int dCol = -1; dCol <= 1; ++dCol)
					// If the move is legal
					if(isLegalMove(cells, row, col, dRow, dCol, user))
					{
						if(legals.empty())
							legals.push_back(Cell(row, col));
						else if(checkMove(legals, row, col))
							break;
						else // Save the move
							legals.push_back(Cell(row, col));
					}
		}
	return legals.size();
}
bool Reversi::checkMove(const vector<Cell> &legals, 
                                   const int x, const int y) const{
	// If the move is in the legalMoves vector return true
	for(unsigned int i=0; i<legals.size(); ++i)
		if(legals[i].getX() == x && legals[i].getY() == y)
			return true;
	// Else
	return false;
}
void Reversi::printLegalMoves() const{
	int m = 0; // Legal moves counter for a line
    //Prints the legal moves for the player
	cout << "Computer: Your legal moves are: " << endl;
	for(unsigned int i = 0; i < legalMoves.size(); ++i)
	{
		cout << "<" << legalMoves[i].getX()+1 << ", "; 
        cout << intToString(legalMoves[i].getY()+1) << "> ";
		++m; // Increase legal moves counter by 1 after a legal move is printed
		if(m/8 == 1) // prints no more of 8 legal moves for a line
		{
			cout << endl;
			m = 0; // Reset legal moves counter for a line
		}
	}

	cout << endl;
}
void Reversi::getInputMove(int &row, int &col){
	string columnLetter;
	int columnNumber = 0;
	int rowNumber = 0;

	while(true)
	{
		for(;;) // Loop to take move's row until correct input
		{
			//cin.sync();
			cout << "Choose a move's row: ";
			cin >> rowNumber; // Get row number
            // If the input fails or row number is bigger than height
			if(cin.fail() || rowNumber > height)
			{
				cout << "Wrong row input! Try again." << endl;
				cin.clear(); // Clear the buffer
				cin.ignore(2000, '\n'); // Ignore 2000 symbols until '\n'
				continue; // continue to get input
			}
			else
				cin.clear(); // Clear the buffer
				cin.ignore(2000, '\n'); // Ignore 2000 symbols until '\n'
				break; // Break the loop
		}

		for(;;) // Loop to take move's column until correct input
		{
			//cin.sync();
			cout << "Choose a move's column: ";
			cin >> columnLetter;
			columnNumber = stringToInt(columnLetter);
			if(columnNumber > width) // If the column number is bigger than width
			{
				cout << "Wrong column input! Try again." << endl;
				cin.clear(); // Clear the buffer
				cin.ignore(2000, '\n'); // Ignore 2000 symbols until '\n'
				continue; // continue to get input
			}
			else
				cin.clear(); // Clear the buffer
				cin.ignore(2000, '\n'); // Ignore 2000 symbols until '\n'
				break; // Break the loop
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
			cout << "Choosen move is illegal, try again." << endl;
	}

}
bool Reversi::isCaptured(const vector<vector<Cell> > &cells, int *x, int *y, 
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
void Reversi::findAndChange(vector<vector<Cell> > &cells, 
                       const int x, const int y, const char user){
	for(int col=0; col<width; ++col)
	{
		//Check x'th row's cells
		for(unsigned int i = 0; i<cells[x].size(); ++i)
		{
			// If we find a cell at the parameter coordinates
			if(y == cells[x][i].getY())
			{
				cells[x][i].setS(user); // Set the user symbol to that cell
				return; // The cell is found at the given coordinates
			}
		}
	}
}
void Reversi::makeMove(vector<vector<Cell> > &cells, 
                   const int row, const int col, const char user){
	char opponent = setOpponent(user); // Identify the opponent
	int x = 0, y = 0;

	// Make move for the user
	cells[row].push_back(Cell(row, col, user));

	// Check all squares around for opponent disks and capture them if possible
	for(int row_inc = -1; row_inc <= 1; row_inc++)
		for(int col_inc = -1; col_inc <= 1; col_inc++)
			if(isCaptured(cells, &x, &y, row, col, row_inc, col_inc, user))
			{
				char sOpp; // Symbol of opponent
				// While we seek opponent disk
				while(isLivingCell(cells, x-=row_inc, y-=col_inc, sOpp) && 
                                                             sOpp == opponent)
					// Capture the disks
					findAndChange(cells, x, y, user);
			}
}
void Reversi::calculateBestComputerMove(vector<vector<Cell> > &cells, 
                      vector<Cell> &legals, int *rowB, int *colB){
	vector<vector<Cell> > tempGameCells; // Make temporary 2D vector
	vector<Cell> tempLegalMoves; // Make temporary legal moves vector

	int bestScore = 1; // Best score is at least 1 if there is a legal move

	for(int row = 0; row < height; ++row)
		for(int col = 0; col < width; ++col)
		{
            // If the move is illegal continue
			if(!checkMove(legalMoves, row, col)) 
				continue;

			tempGameCells = cells; // Refresh gameCells for another move try
			tempLegalMoves.clear(); // Refresh the legal moves vector

			// Make move for computer
			makeMove(tempGameCells, row, col, PC_S);

			int score = 0;
			// Evaluate the board, get the score for computer
			for(unsigned int i = 0; i < gameCells.size(); ++i)
				for(unsigned int j = 0; j < gameCells[i].size(); ++j)
					if(tempGameCells[i][j].getS() == PC_S)
						++score;

			// Save the best score
			if(score > bestScore)
			{
				bestScore = score;
				// Save row and col for the best move for computer
				*rowB = row;
				*colB = col;
			}
		}
}

// Our static is initialized
int Reversi::totalLivingCells = 0; // Counter for the living cells
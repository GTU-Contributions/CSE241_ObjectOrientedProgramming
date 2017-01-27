// HW04_131044084_Mehmed_Mustafa
// main.cpp
//
// Created on 13/11/2015 by Mehmed Mustafa
// Last Edited on 23/11/2015 by Mehmed Mustafa

// Odev verildiginde BIG THREE ve namespace konulari
// islenmemisti, bu yuzden isimsiz namespace kullanmadim

#include "header.h"

int main(int argc, char** argv) {
    {
    Reversi game1(10, 10), game2(5, 7), game3(8, 9), game4(15, 18), game5;
    // Since 5 objects are created, every object has 4 central disks
    // Which makes our total living cells 20
    cout << "Total living cells: " << game1.livingCells() << endl;
    
    cout << "GAME 1 PART" << endl;
    game1.displayBoard(); // Display the current board
    game1.play(Cell(4, 5)); // Play move for the player
    game1.displayBoard(); // Display the current board
    game1.play(); // Play move for the computer
    game1.displayBoard(); // Display the current board
    game1.play(Cell(6, 9)); // Illegal move entered, player lose 1 move
    game1.displayBoard(); // Display the current board
    // 3 moves are played on game1, total living cells are 23
    cout << "Total living cells: " << game1.livingCells() << endl;
    game1.play(); // Total living cells are 24
    game1.displayBoard();
    game1.play(); // Since computer doesn't have legal moves
    // Nothing happened and living cells are still 24
    game1.displayBoard(); // Display the current board
    game1.play(Cell(4, 3)); // No legal moves for the player
    // Nothing happened and living cells are still 24
    cout << "Total living cells: " << game1.livingCells() << endl;
    game1.isGameEnded(); // Since the game is finished
    // All 8 living cells are dead, so total living cells are 16 now
    cout << "Total living cells: " << game1.livingCells() << endl;
    
    cout << "CHECKING HEIGHT AND WIDTH" << endl;
    cout << "The height and width of game2 are " << game2.getHeight();
    cout << " " << game2.getWidth() << endl;
    cout << "The height and width of game3 are " << game3.getHeight();
    cout << " " << game3.getWidth() << endl;
    
    cout << "GAME 2 PART" << endl;
    game2.play(Cell(2, 2)); // Play move for the player
    game2.displayBoard(); // Display the current board
    game2.play(); // Play move for the computer
    game2.displayBoard(); // Display the current board
    // 2 moves are player, total living cells are 18 now
    cout << "Total living cells: " << game1.livingCells() << endl;
    
    cout << "GAME 3 PART" << endl;
    game3.play(); // Play move for the computer
    game3.play(); // Play move for the computer
    game3.displayBoard(); // Display the current board
    // 2 moves are played from computer, total living cells are 20 now
    cout << "Total living cells: " << game1.livingCells() << endl;
    game3.isGameEnded(); // Since the game is finished
    // All 6 living cells from game3 are now dead, so total living are 14 now
    cout << "Total living cells: " << game1.livingCells() << endl;
    
    cout << "WRITING AND READIN FROM FILES - GAME 4 PART" << endl;
    game2.write("game2saved.txt"); // Saving game2 to text file
    game2.displayBoard(); // The game2 has 6 viling cells
    game4.displayBoard(); // The game4 has 4 living cells
    // read function kills all living cells of game44
    // and adds the living cells of game2 to game4
    game4.read("game2saved.txt"); // Load game2 to game4
    game4.displayBoard(); // The game has 6 living cells
    // Since loaded the size and cells of game2
    // So the living cells are 14-4+6 = 16
    cout << "Total living cells: " << game1.livingCells() << endl;    
    
    cout << "COMPARISON OF GAMES" << endl;
    
    cout << "Game1's board: " << endl;
    game1.displayBoard();
    cout << "Game2's board:" << endl;
    game2.displayBoard();
    
    if(game1.compare(game2))
        cout << " Game1 is better for player " << endl;
    else
        cout << " Game2 is better for player " << endl;
    }
    
    cout << "PLAY ONE FULL GAME FROM THE BEGGINING TO THE END" << endl;
    Reversi testGame;
    testGame.playGame();
    
    return 0;
}
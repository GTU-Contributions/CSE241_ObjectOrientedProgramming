// HW05_131044084_Mehmed_Mustafa
// main.cpp
//
// Created on 13/11/2015 by Mehmed Mustafa
// Last Edited on 23/11/2015 by Mehmed Mustafa

// Odev verildiginde BIG THREE ve namespace konulari
// islenmemisti, bu yuzden isimsiz namespace kullanmadim

#include "header.h"

int main(int argc, char** argv) {
    // Driver for testing Cell operators
    
    bool isTestOn = true; // Change the value to true, to enter testing driver
    if(isTestOn)
    {
        Cell A;
        A.testerForCell();
    }
    
    // Reversi testing overloaded operators
    Reversi mehmed(10, 10);
    cout << mehmed;
    mehmed += Cell(4, 5);
    cout << mehmed;
    --mehmed;
    cout << mehmed;
    mehmed.play();
    cout << mehmed;
    mehmed += Cell(4, 7);
    cout << mehmed;
    mehmed++;
    cout << mehmed;
    
    cout << Cell(5, 9);
    cout << mehmed;
    
    cout << mehmed["E2"] << endl; // This is not living cell
    cout << mehmed["E5"] << endl; // This is living cell
    cout << mehmed["E6"] << endl; // This is living cell
    cout << mehmed["F5"] << endl; // This is living cell
    cout << mehmed["H4"] << endl; // This is living cell
    cout << mehmed("B5") << endl; // This is not living cell
    cout << mehmed("H4") << endl; // This is living cell
    
    cout << mehmed << endl;
    --mehmed;
    cout << "1 move is taken back" << endl;
    cout << mehmed;
    --mehmed;
    cout << "1 move is taken back" << endl;
    cout << mehmed;
    --mehmed;
    cout << "1 move is taken back" << endl;
    cout << mehmed;
    --mehmed;
    cout << "Since we are at the beggining of the game" << endl;
    cout << "We can't go back anymore" << endl;
    cout << mehmed;
    
    
    return 0;
}
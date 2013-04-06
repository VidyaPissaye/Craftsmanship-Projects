/* 
 * File:   main.cpp
 * Author: Vidya
 *
 * Created on February 4, 2013, 4:11 PM
 */

#include <cstdlib>
#include <iostream>
#include <vector>

#include "Tictactoe.h"


using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

    int size;
    vector<vector<char> > board; // creates a vector of 0 size
    
    cout << "Welcome to Tic-Tac-Toe" << endl;
    cout << "Enter the board size to begin play" << endl;
    cin >> size;
    board.resize(size, vector<char>(size, ' ')); // Set the size of the vector
    

    Tictactoe game(size, board);
    game.playgame();
    
}


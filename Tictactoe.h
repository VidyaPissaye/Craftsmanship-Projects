/* 
 * File:   Tictactoe.h
 * Author: Vidya
 *
 * Created on February 4, 2013, 4:12 PM
 */

#ifndef TICTACTOE_H
#define	TICTACTOE_H

#include <iostream>
#include <vector>

using namespace std;

class Tictactoe
{
    int dimension;
    vector<vector<char> > & board;
    bool playerX;
    
    
    

    
public:
    
    Tictactoe(int dimension, vector<vector<char> > & board) : dimension(dimension), board(board){
        
        playerX = true;
    }
        
    void playgame();
   
    bool determine_game(int row, int column, char move);
    
    void display_board();
    
};

#endif	/* TICTACTOE_H */


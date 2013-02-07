

#include "Tictactoe.h"



void Tictactoe::playgame(){
    
    
    int row, column, size;

    // Determine the total size of the board. Eg: 3X3 = 9
    size = dimension * dimension;
    
    // Play until the board has available spots
    while(size != 0){
        
        display_board();
        
        if(playerX) {
            cout << "Player 1 - Your Turn" << endl;
            cout << "Enter row" << endl;
            cin >> row;
            cout << "Enter column" << endl;
            cin >> column;
            
            // Adjust to start from 0
            row = row-1;
            column = column-1;
            
            if ((board[row][column] != 'X') || (board[row][column] != 'O'))
            {
                board[row][column] = 'X';
                
                if(determine_game(row, column, board[row][column])){
                    cout << "Congratulations Player 1 - You Win!" << endl;
                    break;
                }
                
                // Change player
                playerX = false;
                
                // Spot taken! Decrement the total available spots on board
                size--;
                    
            }
            else {
                cout << "The spot is not free! Enter a new spot" << endl;
            }

        }else{
            cout << "Player 2 - Your Turn" << endl;
            cout << "Enter row" << endl;
            cin >> row;
            cout << "Enter column" << endl;
            cin >> column;
            
            // Adjust to start from 0
            row = row-1;
            column = column-1;
            
            if ((board[row][column] != 'X') || (board[row][column] != 'O'))
            {
                board[row][column] = 'O';
                if(determine_game(row, column, board[row][column])){
                    cout << "Congratulations Player 2 - You Win!" << endl;
                    break;
                }
                
                // Change player
                playerX = true;
                
                // Spot taken! Decrement the total available spots on board
                size--;
            }
            else {
                cout << "The spot is not free! Enter a new spot" << endl;
            }
            
        }
        
    }
    
    if (size == 0){
        cout << "Game Over!" << endl;
    }
}

bool Tictactoe::determine_game(int row, int column, char move){
    
    bool flag = true;
    
    // Check the row of latest play
    
  //  for(int i=0; i<dimension, flag==true; i++){
    int i=0;
    while((i<dimension) && (flag==true)){
        if(board[row][i] != move){
            flag = false;
        }
        i++;
    }
    
    // Check the column of latest play
    if(!flag){
        flag = true;
        i=0;
        while((i<dimension) && (flag==true)){
            if(board[i][column] != move){
                flag = false;
            }
            i++;
        }
    }
    
    // Check diagonal Top left - bottom right
    if(!flag){
        flag = true;
        i=0;
        while((i<dimension) && (flag==true)){
            if(board[i][i] != move){
                flag = false;
            }
            i++;
        }
    }
    
    // Check diagonal bottom left - top right
    if(!flag){
        flag = true;
        i=0;
        int n = dimension;
        
        while((i<dimension) && (flag==true)){        
            if(board[i][--n] != move){
                flag = false;
            }
            i++;
        }
    }
    
    return flag;   
    
}

void Tictactoe::display_board(){
    
    cout << "Tic-Tac-Toe board" << endl;
    
    for(int i=0; i<dimension; i++){
        for(int j=0; j<dimension; j++){
            if(board[i][j]){
                cout << board[i][j];
            }
            else{
                cout << "__";
            }
            cout << "  ";
        }
        cout << endl;
    }
        
}
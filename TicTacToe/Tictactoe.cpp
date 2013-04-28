
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
        }
        else {
            cout << "Player 2 - Your Turn" << endl;
        }
        
        cout << "Enter row" << endl;
        cin >> row;
        cout << "Enter column" << endl;
        cin >> column;
            
        // Adjust to start from 0
        row = row-1;
        column = column-1;
            
        if ((board[row][column] != 'X') || (board[row][column] != 'O'))
        {
            if(playerX) {
                // Change player
                board[row][column] = 'X';
                playerX = false;
            }
            else {
                board[row][column] = 'O';
                playerX = true;
            }
                            
            if(determine_is_game(row, column, board[row][column])){
                cout << "Congratulations Player - You Win!" << endl;
                break;
            }            
            // Spot taken! Decrement the total available spots on board
            size--;
                    
        }
        else {
            cout << "The spot is not free! Enter a new spot" << endl;
        }      
    }
    
    if (size == 0){
        cout << "Game Over!" << endl;
    }
}

bool Tictactoe::row_game(int row, char move) {
    int i=0;
    bool is_game = true;
    while((i<dimension) && (is_game==true)){
        if(board[row][i] != move){
            is_game = false;
        }
        i++;
    }
    return is_game;
}

bool Tictactoe::col_game(int col, char move) {
    bool is_game = true;
        
    int i=0;
    while((i<dimension) && (is_game==true)){
        if(board[i][col] != move){
            is_game = false;
        }
        i++;
    }
    return is_game;
}

bool Tictactoe::top_bottom_diagonal_game(int row, int col, char move) {
    bool is_game = true;
    int i=0;
    while((i<dimension) && (is_game==true)){
        if(board[i][i] != move){
            is_game = false;
        }
        i++;
    }
    return is_game;
}

bool Tictactoe::bottom_top_diagonal_game(int row, int col, char move) {
    bool is_game = true;
    int i=0;
    int n = dimension;
        
    while((i<dimension) && (is_game==true)){        
        if(board[i][--n] != move){
            is_game = false;
        }
        i++;
    }  
    return is_game;
}


bool Tictactoe::determine_is_game(int row, int column, char move) {
    
    bool is_game = true;
     
    if(!row_game(row, move)) {
        if(!col_game(column, move)) {
            if(!top_bottom_diagonal_game(row, column, move)) {
                is_game = bottom_top_diagonal_game(row, column, move);
            }
        }
    } 
    return is_game;      
}

void Tictactoe::display_board() {
    
    cout << "Tic-Tac-Toe board" << endl;
    
    for(int i=0; i<dimension; i++){
        for(int j=0; j<dimension; j++){
            if(board[i][j]){
                cout << board[i][j];
            }
            else{
                cout << "-";
            }
            cout << "  ";
        }
        cout << endl;
    }       
}
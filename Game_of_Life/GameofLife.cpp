
#include "GameofLife.h"

void GameofLife::create_border() {
    for (int k = 0; k < cols; k++) {
        universe[0][k] = '-';
        universe[rows-1][k] = '-';
    }
    
    for (int p = 0; p < rows; p++) {
        universe[p][0] = '-';
        universe[p][cols-1] = '-';
    }
}

void GameofLife::random_universe() {
    create_border();
    
    for(int i=1; i < rows-1; i++) {
        for(int j = 1; j < cols-1; j++) {
            int random_number = rand()%2;
            if(random_number != 0) {
                universe[i][j] = '*';
            }
            else {
                universe[i][j] = '-';
            }
        }
    }
    cout << "Random Universe" << endl;
    display_universe();
}

void GameofLife::display_universe() {
    
    for(int i=0; i < rows; i++) {
        for(int j=0; j < cols; j++) {
            cout << "|" << universe[i][j];
        }
        cout << "|" << endl;
    }
    cout << endl;
}

int GameofLife::check_neighbours(int row, int col) {
    int neighbours_alive = 0;
    
    if(universe[row-1][col-1] == '*') {
        neighbours_alive++;
    }
    
    if(universe[row-1][col] == '*') {
        neighbours_alive++;
    }
    
    if(universe[row-1][col+1] == '*') {
        neighbours_alive++;
    }
    
    if(universe[row][col-1] == '*') {
        neighbours_alive++;
    }
    
    if(universe[row][col+1] == '*') {
        neighbours_alive++;
    }
    
    if(universe[row+1][col-1] == '*') {
        neighbours_alive++;
    }
    
    if(universe[row+1][col] == '*') {
        neighbours_alive++;
    }
    
    if(universe[row+1][col+1] == '*') {
        neighbours_alive++;
    }
    
    return neighbours_alive;
}

void GameofLife::determine_life(char alt_univ[][cols]) {
    
    for(int i=1; i < rows-1; i++) {
        for(int j=1; j < cols-1; j++) {
            int neighbours_alive = check_neighbours(i, j);
            
            if(universe[i][j] == '*') {
                if((neighbours_alive < 2) || (neighbours_alive > 3)) {
                    alt_univ[i][j] = '-';
                }
                else {
                    alt_univ[i][j] = '*';
                }
            }
            else {
                if(neighbours_alive == 3) {
                    alt_univ[i][j] = '*';
                }
                else {
                    alt_univ[i][j] = '-';
                }
            }
        }
    }    
}

void GameofLife::update_universe(char alt_univ[][cols]) {    
    for(int i=1; i < rows-1; i++) {
        for(int j=1; j < cols-1; j++) {
            universe[i][j] = alt_univ[i][j];
        }
    }
}

void GameofLife::generations() {   
    char alt_univ[rows][cols];
    
    for(int i=0; i < num_of_gens; i++) {
        determine_life(alt_univ);
        update_universe(alt_univ);
        cout << "Universe: Generation " << i+1 << endl;
        display_universe();
    }
}

void GameofLife::play_gameoflife() {
    random_universe();
    generations();
}

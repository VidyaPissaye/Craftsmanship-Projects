/* 
 * File:   GameofLife.h
 * Author: Vidya
 *
 * Created on April 8, 2013, 4:06 PM
 */

#ifndef GAMEOFLIFE_H
#define	GAMEOFLIFE_H

#include <cstdlib>
#include <iostream>

using namespace std;

#define rows 10
#define cols 10

class GameofLife {
    char universe[rows][cols];
    int num_of_gens;
    
public:
    GameofLife(int num_of_gens):num_of_gens(num_of_gens) { };
    void initial_universe();
    void display_universe();
    int check_neighbours(int row, int col);
    void determine_life(char alt_univ[][cols]);
    void update_universe(char alt_univ[][cols]);
    void generations();
    void play_gameoflife();
    void create_border();
};


#endif	/* GAMEOFLIFE_H */


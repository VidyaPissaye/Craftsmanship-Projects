/* 
 * File:   main.cpp
 * Author: Vidya
 *
 * Created on April 8, 2013, 1:31 PM
 */

#include <cstdlib>
#include <iostream>

#include "GameofLife.h"

using namespace std;

/*
 * 
 *   Rules of Game of Life
 * 1. Any live cell with fewer than two live neighbours dies, as if caused by under-population.
 * 2. Any live cell with two or three live neighbours lives on to the next generation.
 * 3. Any live cell with more than three live neighbours dies, as if by overcrowding.
 * 4. Any dead cell with exactly three live neighbours becomes a live cell, as if by reproduction.
 * 
 */

int main(int argc, char** argv) {

    GameofLife life(2);
    life.play_gameoflife();
}


/* 
 * File:   main.cpp
 * Author: Vidya
 *
 * Created on March 18, 2013, 12:22 PM
 */

#include <cstdlib>
#include <iostream>

#include "BowlingGame.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

    BowlingGame player;
    
    cout << "Welcome to Bowling!" << endl;
    
    player.play();
}


/* 
 * File:   BowlingGame.h
 * Author: Vidya
 *
 * Created on March 18, 2013, 12:23 PM
 */

#ifndef BOWLINGGAME_H
#define	BOWLINGGAME_H

#include <iostream>
using namespace std;

struct Frame {
    int turn1;
    int turn2;
    int bonus; 
    bool frame_done;
};

class BowlingGame {
    Frame frames[10];
    
public:
    
    BowlingGame() {
        for (int i=0; i < 10; i++) {
            frames[i].turn1 = -1;
            frames[i].turn2 = -1;
            frames[i].bonus = 0;
            frames[i].frame_done = false;
        }
    }
    
    ~BowlingGame() {}
    
    void play();
    bool game_over();
    bool strike(int pins); 
    bool spare(int frame);
    void roll(int pins);
    void prev_strike_bonus(int frame);
    void prev_spare_bonus(int frame);
    void update_bonus(int frame);
    void update_prev_frames_score(int frame);
    void display_score();
};

#endif	/* BOWLINGGAME_H */


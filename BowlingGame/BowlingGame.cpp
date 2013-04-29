
#include "BowlingGame.h"

#define max_pins 10
#define max_frames 9

void BowlingGame::display_score() {
    int i=0, final_score = 0; 
    int scores[max_frames+1];
    
    cout << "The score for each frame: " << endl;
    while((i <= max_frames) && (frames[i].frame_done)) {
        cout << frames[i].turn1;
        if(frames[i].turn2 >= 0) {
            if(i == max_frames) {
                cout << ":" << frames[i].turn2 << ":" << frames[i].bonus << " | ";
            }
            else {
                cout << ":" << frames[i].turn2 << " | ";
            }
            final_score += frames[i].turn1 + frames[i].turn2 + frames[i].bonus;
        }
        else {
            cout << ":X | ";
            final_score += frames[i].turn1 + frames[i].bonus;
        }
        scores[i] = final_score;
        i++;
    }
    cout << endl;
    i = 0;
    
    while((i <= max_frames) && (frames[i].frame_done)) {
        cout << scores[i] << " | ";
        i++;
    }
    cout << endl;
}

bool BowlingGame::strike(int pins) {
    return(pins == max_pins);
}

bool BowlingGame::spare(int frame) {
    return((frames[frame].turn1 + frames[frame].turn2) == max_pins);
}

void BowlingGame::prev_strike_bonus(int frame) {
    if(strike(frames[frame-1].turn1)) {
        if((!strike(frames[frame].turn1)) || (strike(frames[frame].turn1) && (frame == max_frames))) {
            frames[frame-1].bonus = frames[frame].turn1 + frames[frame].turn2;
        }
    }

    if(strike(frames[frame-2].turn1)) {
        if(strike(frames[frame-1].turn1)) {
            frames[frame-2].bonus = frames[frame-1].turn1 + frames[frame].turn1;
        }
    }
}

void BowlingGame::prev_spare_bonus(int frame) {
    if(spare(frame-1)) {
        frames[frame-1].bonus = frames[frame].turn1;
    }
}

void BowlingGame::update_bonus(int frame) {
    prev_strike_bonus(frame);
    prev_spare_bonus(frame);
}

void BowlingGame::roll(int pins_knocked) {
    static int current_frame = 0;
    
    if(frames[current_frame].turn1 < 0) {
        frames[current_frame].turn1 = pins_knocked;
        
        if(strike(pins_knocked)) {            
            if(current_frame != max_frames) {
                frames[current_frame].frame_done = true;
                update_bonus(current_frame);  
                current_frame++;
            }
        }
    }
    else {
        if(current_frame != max_frames) {
            frames[current_frame].turn2 = pins_knocked;
            frames[current_frame].frame_done = true;
            update_bonus(current_frame);  
            current_frame++;
        }
        else {
            if(frames[current_frame].turn2 < 0) {
                frames[current_frame].turn2 = pins_knocked;
                
                if(!(strike(frames[current_frame].turn1) || spare(current_frame))) {
                    frames[current_frame].frame_done = true;
                    update_bonus(current_frame);  
                }
            }
            else{
                frames[current_frame].bonus = pins_knocked;
                frames[current_frame].frame_done = true;
                update_bonus(current_frame);  
            }
        }             
    }
    
}

bool BowlingGame::game_over() {
    return(frames[max_frames].frame_done);
}

void BowlingGame::play() {    
    while(!game_over()) {
        int pins_knocked;
        cout << "Enter the number of pins knocked down" << endl;
        cin >> pins_knocked;
        roll(pins_knocked);
        display_score();
    }
}

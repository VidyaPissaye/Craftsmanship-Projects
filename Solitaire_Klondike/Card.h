/* 
 * File:   Card.h
 * Author: Vidya
 *
 * Created on May 5, 2013, 5:33 PM
 */

#ifndef CARD_H
#define	CARD_H

#include <iostream>

#include "Stack.h"
#include "library.h"



class Card {
    Colour colour;
    Symbol symbol;
    Card_Rank rank;
    
public:
    
    Card() {
        symbol = Heart;
        colour = Red;
        rank = Ace;
    }
    
    bool is_one_greater_in_rank(Card_Rank rank);
    bool is_one_less_in_rank(Card_Rank rank);
    bool is_alternate_colour(Colour colour);
    bool is_king();
    bool is_ace();
    Colour get_card_colour();
    Symbol get_card_symbol();
    bool is_move_valid(Card destination_card, bool is_ascending);
    
};

#endif	/* CARD_H */


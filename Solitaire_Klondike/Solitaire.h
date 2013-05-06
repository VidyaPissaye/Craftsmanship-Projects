/* 
 * File:   Solitaire.h
 * Author: Vidya
 *
 * Created on May 5, 2013, 5:33 PM
 */

#ifndef SOLITAIRE_H
#define	SOLITAIRE_H

#include <iostream>

#include "library.h"
#include "Stack.h"

using namespace std;

class Card;

class Solitaire {
    Stack Foundation[Symbol_Count];
    Stack Tableau[7];
    Stack Stock;
    Stack Discard_Pile;
    
public:
    
    bool is_stock_empty();
    bool is_discard_pile_empty();
    bool is_tableau_empty(int tableau_number);
    void xfer_discardpile_to_stock();
    void move_card_from_discardpile_to_tableu(int tableau_number);
    void move_card_from_discardpile_to_foundation();
    void move_card_from_tableau_to_foundation(int tableau_number);
    void move_card_between_tableus(int from_tableu, int to_tableu, bool multiple_cards);
    
};

#endif	/* SOLITAIRE_H */


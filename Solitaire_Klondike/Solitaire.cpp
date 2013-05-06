
#include "Solitaire.h"

bool Solitaire::is_stock_emtpy() {
    return(Stock.empty());
}

bool Solitaire::is_discard_pile_empty() {
    return(Discard_Pile.empty());
}

bool Solitaire::is_tableau_empty(int tableau_number) {
    return(Tableau[tableau_number].empty());
}

bool Solitaire::xfer_discardpile_to_stock() {
    while(!Discard_Pile.empty()) {
        Stock.push(Discard_Pile.pop());
    }
}

void Solitaire::move_card_from_discardpile_to_tableu(int tableau_number) {
    
    if(!is_discard_pile_empty()) {  
        Card discard_pile_card = Discard_Pile.peek();
        
        if(!is_tableau_empty(tableau_number)) {
            Card tableau_top_card = Tableau[tableau_number].peek();
            if(discard_pile_card.is_move_valid(tableau_top_card, false)) {
                Tableau[tableau_number].push(Discard_Pile.pop());
            } 
        }
        else {
            if(discard_pile_card.is_king()) {
                Tableau[tableau_number].push(Discard_Pile.pop());
            }
        }
    }
}

void Solitaire::move_card_from_discardpile_to_foundation() {
    if(!is_discard_pile_empty()) { 
        Card discard_pile_card = Discard_Pile.peek();
        Symbol discard_pile_card_symbol = discard_pile_card.get_card_symbol();
        if(!Foundation[discard_pile_card_symbol].empty) {
            Card foundation_top_card = Foundation[discard_pile_card_symbol].peek();
            if(discard_pile_card.is_move_valid(foundation_top_card, true)) {
                Foundation[discard_pile_card_symbol].push(Discard_Pile.pop());
            }    
        }
        else if(discard_pile_card.is_ace()) {
            Foundation[discard_pile_card_symbol].push(Discard_Pile.pop());
        }
    }
}

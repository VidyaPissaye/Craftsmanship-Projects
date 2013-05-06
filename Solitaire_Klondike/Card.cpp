
#include "Card.h"


bool Card::is_alternate_colour(Colour colour) {
    if (((this->colour == Red) && (colour == Black)) || 
            ((this->colour == Black) && (colour == Red))) 
        return true;
    else
        return false;
}

bool Card::is_one_greater_in_rank(Card_Rank card_rank) {
    if((rank > card_rank) && ((rank - card_rank) == 1))
        return true;
    else
        return false;
}

bool Card::is_one_less_in_rank(Card_Rank card_rank) {
    if((rank < card_rank) && ((rank - card_rank) == 1))
        return true;
    else
        return false;
}

bool Card::is_king() {
    return((rank == King) ? true:false);
}

bool Card::is_ace() {
    return((rank == Ace) ? true:false);
}

Colour Card::get_card_colour() {
    return(colour);
}

Symbol Card::get_card_symbol() {
    return(symbol);
}

bool Card::is_move_valid(Card destination_card, bool is_ascending) {
    
    if(is_ascending) { 
        if(this->is_one_greater_in_rank(destination_card.rank)) {
                return(!discard_pile_card.is_alternate_colour(tableau_top_card.colour));                
        }
    }
    else {
        if(this->is_one_less_in_rank(destination_card.rank)) {
                return(discard_pile_card.is_alternate_colour(tableau_top_card.colour));
        }
    }
    
    return false;
}

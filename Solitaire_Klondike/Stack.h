/* 
 * File:   Stack.h
 * Author: Vidya
 *
 * Created on May 5, 2013, 6:49 PM
 */

#ifndef STACK_H
#define	STACK_H

#include <iostream>
using namespace std;

class Card;

#define max 52

class Stack {
    Card arr[max];
    int top;
    
public: 
    Stack() {
        top = -1;
    }
    
    void push(Card card);
    Card pop();
    Card peek();
    bool empty();
};


#endif	/* STACK_H */


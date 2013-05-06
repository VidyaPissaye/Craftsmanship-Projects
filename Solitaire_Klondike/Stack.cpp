

#include "Stack.h"

void Stack::push(Card card) {
    if(top < (max-1)) {
        arr[++top] = card;
    }
    else {
        cout << "Stack overflow!" << endl;
    }
}

Card Stack::pop() {
    if(top != -1) {
        return (arr[top--]);
    }
    else {
        cout << "Stack underflow!" << endl;
    }
}

Card Stack::peek() {
    if(top > -1) {
        return (arr[top]);
    }
    else {
        cout << "Empty Stack!" << endl;
    }
}

bool Stack::empty() {
    if(top == -1) {
        return true;
    }
    else {
        return false;
    }
}






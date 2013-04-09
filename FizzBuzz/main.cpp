/* 
 * File:   main.cpp
 * Author: Vidya
 *
 * Created on April 5, 2013, 11:14 PM
 */

#include <cstdlib>
#include <iostream>
#include "gtest/gtest.h"

using namespace std;

/*
 *  FizzBuzz is a simple number game where you count, but say "Fizz" and/or 
 *  "Buzz" instead of numbers adhering to certain rules.
 *  Create a FizzBuzz() method that prints out the numbers 1 through 100. 
        • Instead of numbers divisible by three print "Fizz". 
        • Instead of numbers divisible by five print "Buzz".
        • Instead of numbers divisible by three and five print "FizzBuzz".
        • Instead of numbers with a three in them print "Fizz".
        • Instead of numbers with a five in them print "Buzz".
        • Instead of numbers with a three and a five in them print "FizzBuzz"
 */

void FizzBuzz() {
    int i = 1;
    
    while (i <= 100) {
        
        if((((i % 3) == 0) && ((i % 5) == 0)) || 
           (((i / 10) == 3) && ((i % 10) == 5)) ||
           (((i / 10) == 5) && ((i % 10) == 3))){
            cout << "FizzBuzz" << endl;
        }
        else if(((i % 3) == 0) || ((i / 10) == 3) || ((i % 10) == 3)) {
            cout << "Fizz" << endl;
        }
        else if((i % 5) == 0 || ((i / 10) == 5) || ((i % 10) == 5)) {
            cout << "Buzz" << endl;
        }
        else {
            cout << i << endl;
        }
        i++;
    }
}

int main(int argc, char** argv) {

    FizzBuzz();
}


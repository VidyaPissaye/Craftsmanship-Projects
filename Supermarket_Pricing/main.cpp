/* 
 * File:   main.cpp
 * Author: Vidya
 *
 * Created on April 6, 2013, 12:36 AM
 */

#include <cstdlib>
#include <iostream>
#include "gtest/gtest.h"

using namespace std;

/*
 * 
 */

#define LOAF_BREAD 1
#define NOODLES 0.5
#define SOUP_CANS 2
#define APPLES 2
#define SOUP_DISCOUNT 4

enum products {loaf_bread, noodles, soup_cans, apples};

int breadloaf_cost(int num_bread) {
    int price = 0;
    if(num_bread) {
        price = num_bread * LOAF_BREAD;
    } 
    return price;
}

double noodles_cost(double num_noodles) {
    double price = 0;
    if(num_noodles) {
        price = num_noodles * NOODLES;
    }
    return price;
}

int get_discount(int num, int min_num) {
    return(num - (num/min_num));
}

int soupcan_price(int num_soup) {
    int price = 0;
    
    if(num_soup) {
        if(num_soup >= SOUP_DISCOUNT) {
            num_soup = get_discount(num_soup, SOUP_DISCOUNT);
        }
        price = num_soup * SOUP_CANS;
    }
    return price;
}

double apple_pound(double pound) {
    return (APPLES * pound);
}

double cost(int num_bread, double num_noodles, int num_soup, double apple_wt) {
    double final_price = 0;
    
    final_price += breadloaf_cost(num_bread);   
    final_price += noodles_cost(num_noodles);
    final_price += soupcan_price(num_soup);
    final_price += apple_pound(apple_wt);
    
    return final_price;
}

GTEST_API_ int main(int argc, char **argv) {
  cout << "Running main() from gtest_main.cc\n";

  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

TEST(MyTestSuite, MyTestCase)
{
    EXPECT_EQ(2, breadloaf_cost(2));
    EXPECT_EQ(1.5, noodles_cost(3));
    EXPECT_EQ(4, soupcan_price(2));
    EXPECT_EQ(6, soupcan_price(4));
    EXPECT_EQ(2, apple_pound(1));
    EXPECT_EQ(5, apple_pound(2.5));
    EXPECT_EQ(15.5, cost(2, 2, 3, 3.25));

}

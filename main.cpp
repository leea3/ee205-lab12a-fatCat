///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab12a_fatCat - EE 205 - Spr 2022
///
/// @file main.cpp
/// @version 1.0
///
/// @author Arthur Lee <leea3@hawaii.edu>
/// @date   15_Apr_2022
///////////////////////////////////////////////////////////////////////////////
#include "Weight.h"
#include <iostream>

using namespace std;

int main(){
    cout << "Hello World!" << endl;

    //testing constructor 1
    Weight const1 = Weight();
    const1.dump();

    //testing constructor 2
    Weight const2 = Weight( 5.0 );
    const2.dump();

    //testing constructor 3
    Weight const3 = Weight( Weight::SLUG );
    const3.dump();

    //testing constructor 4
    Weight const4 = Weight(25, Weight::SLUG );
    const4.dump();

    //testing constructor 5
    Weight const5 = Weight(25, 50);
    const5.dump();

    //testing constructor 6
    Weight const6 = Weight( Weight::SLUG , 55);
    const3.dump();

    //testing constructor 7
    Weight const7 = Weight(Weight::UNKNOWN_WEIGHT, Weight::KILO, 40.0);

    //testing negative values (should fail)
    //Weight test1 = Weight(-5.5, Weight::KILO, 40.0);


    //testing weight greater than maxweight (should fail)
    //Weight test2 = Weight(500, Weight::KILO, 50);

    //setting unknown weight
    Weight test3 = Weight(Weight::UNKNOWN_WEIGHT, Weight::KILO, 40.0);
    test3.dump();

    //changing maxweight to a different value (should fail)
    Weight test4 = Weight(5.0, Weight::KILO, 55);
    //test4.setMaxWeight( 52 );

    //changing weight from known to unknown (should fail)
    Weight test5 = Weight(5.0, Weight::KILO, 55);
    //test5.setWeight( Weight::UNKNOWN_WEIGHT );

    //testing += operator
    Weight test6 = Weight(5.0, Weight::POUND, 55);
    test6.dump();
    test6 += 10;
    test6.dump();

}
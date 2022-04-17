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

    Weight test1 = Weight(1.0, Weight::KILO, 40.0);
    test1.dump();

    //Weight test2 = Weight(-5.5, Weight::KILO, 40.0);
    Weight test3 = Weight(5.0);
    test3.dump();

    //Weight test4 = Weight(500, Weight::KILO, 50);

    Weight test5 = Weight(Weight::UNKNOWN_WEIGHT, Weight::KILO, 40.0);
    test5.dump();

    Weight test6 = Weight(5.0, Weight::KILO, 55);
    //test6.setMaxWeight( 52 );

    Weight test7 = Weight(5.0, Weight::KILO, 55);
    //test7.setWeight( Weight::UNKNOWN_WEIGHT );

    Weight test8 = Weight(5.0, Weight::POUND, 55);
    test8.dump();
    test8 += 10;
    test8.dump();

}
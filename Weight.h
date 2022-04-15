///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205-lab12a-fatCat - EE 205 - Spr 2022
///
/// @file Weight.h
/// @version 1.0
///
/// @author Arthur Lee <leea3@hawaii.edu>
/// @date   17_Apr_2022
///////////////////////////////////////////////////////////////////////////////
#pragma once
#include <iostream>

class Weight {
public:
    //units enum
    enum UnitOfWeight { POUND , KILO , SLUG };

    //conversion constants
    static const float KILOS_IN_A_POUND;
    static const float SLUGS_IN_A_POUND;

    //labels
    static const std::string POUND_LABEL;
    static const std::string KILO_LABEL;
    static const std::string SLUG_LABEL;

};

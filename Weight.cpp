///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205-lab12a-fatCat - EE 205 - Spr 2022
///
/// @file Weight.cpp
/// @version 1.0
///
/// @author Arthur Lee <leea3@hawaii.edu>
/// @date   17_Apr_2022
///////////////////////////////////////////////////////////////////////////////
#include "Weight.h"
#include <iostream>

//constants
const float Weight::KILOS_IN_A_POUND = 0.453592;
const float Weight::SLUGS_IN_A_POUND = 0.031081;

Weight::Weight() {}
Weight::Weight (float newWeight){}
Weight::Weight (UnitOfWeight newUnitOfWeight) noexcept{}
Weight::Weight (float newWeight, UnitOfWeight newUnitOfWeight){}
Weight::Weight (float newWeight, float newMaxWeight){}
Weight::Weight (UnitOfWeight newUnitOfWeight, float newMaxWeight){}
Weight::Weight (float newWeight, UnitOfWeight newUnitOfWeight, float newMaxWeight){}

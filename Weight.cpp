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
#include <cassert>

//constants
const float Weight::KILOS_IN_A_POUND = 0.453592;
const float Weight::SLUGS_IN_A_POUND = 0.031081;

Weight::Weight () {}
Weight::Weight (float newWeight){}
Weight::Weight (UnitOfWeight newUnitOfWeight) noexcept{}
Weight::Weight (float newWeight, UnitOfWeight newUnitOfWeight){}
Weight::Weight (float newWeight, float newMaxWeight){}
Weight::Weight (UnitOfWeight newUnitOfWeight, float newMaxWeight){}
Weight::Weight (float newWeight, UnitOfWeight newUnitOfWeight, float newMaxWeight){}

float Weight::fromKilogramToPound(const float kilogram) noexcept {
    return kilogram / KILOS_IN_A_POUND;
}

float Weight::fromPoundToKilogram(float pound) noexcept {
    return pound * KILOS_IN_A_POUND;
}

float Weight::fromSlugToPound(float slug) noexcept {
    return slug / SLUGS_IN_A_POUND;
}

float Weight::fromPoundToSlug(float pound) noexcept {
    return pound * SLUGS_IN_A_POUND;
}

float Weight::convertWeight(float fromWeight, UnitOfWeight fromUnit, UnitOfWeight toUnit) noexcept {
    float weightInKilograms;
    float weightInPounds;

    switch( fromUnit ){
        case POUND:
            weightInKilograms = fromPoundToKilogram( fromWeight );
            break;
        case KILO:
            weightInKilograms = fromUnit;
            break;
        case SLUG:
            weightInPounds = fromSlugToPound( fromWeight );
            weightInKilograms = fromPoundToKilogram( weightInPounds );
            break;
        default: assert( 0 );
    }
    switch( toUnit ){
        case POUND:
            return fromKilogramToPound( weightInKilograms );
        case KILO:
            return weightInKilograms;
        case SLUG:
            weightInPounds = fromKilogramToPound( weightInKilograms );
            return fromPoundToSlug( weightInPounds );
        default: assert( 0 );
    }
    assert( 0 ); // we should never get here
}
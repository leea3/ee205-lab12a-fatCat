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
#include <iomanip>
#include <cassert>
#include <stdexcept>

#define FORMAT_LINE( className, member ) cout << setw(8) << (className) << setw(20) << (member) << setw(15)

using namespace std;

//constants
const float Weight::KILOS_IN_A_POUND = 0.453592;
const float Weight::SLUGS_IN_A_POUND = 0.031081;
const std::string Weight::POUND_LABEL = "pound";
const std::string Weight::KILO_LABEL  = "kilo";
const std::string Weight::SLUG_LABEL  = "slug";

Weight::Weight () {
    bIsKnown     = false;
    bHasMax      = false;
    unitOfWeight = KILO;
    weight       = -1;
    maxWeight    = -1;
}

Weight::Weight (float newWeight) : Weight() {
    assert( validateWeight(newWeight) );
    setWeight( newWeight );
}

Weight::Weight (UnitOfWeight newUnitOfWeight) noexcept{
    unitOfWeight = newUnitOfWeight;
}

Weight::Weight (float newWeight, UnitOfWeight newUnitOfWeight) : Weight() {
    assert( validateWeight(newWeight) );
    setWeight( newWeight , newUnitOfWeight );
}

Weight::Weight (float newWeight, float newMaxWeight) : Weight(newWeight){
    setMaxWeight( newMaxWeight );
    assert( validateWeight(weight) );
}

Weight::Weight (UnitOfWeight newUnitOfWeight, float newMaxWeight) : Weight(newUnitOfWeight){
    setMaxWeight( newMaxWeight );
}

Weight::Weight (float newWeight, UnitOfWeight newUnitOfWeight, float newMaxWeight) : Weight(newWeight,newUnitOfWeight){
    setMaxWeight( newMaxWeight );
    assert( validateWeight(weight) );
}

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

std::ostream& operator<<( ostream& lhs_stream
        ,const Weight::UnitOfWeight rhs_UnitOfWeight ) {
    switch( rhs_UnitOfWeight ) {
        case Weight::POUND: return lhs_stream << Weight::POUND_LABEL ;
        case Weight::KILO: return lhs_stream << Weight::KILO_LABEL ;
        case Weight::SLUG: return lhs_stream << Weight::SLUG_LABEL ;
        default:
            throw out_of_range( "The unit can’t be mapped to a string" );
    }
}

bool Weight::operator==( const Weight& rhs_Weight ) const {
    float lhs_weight = (bIsKnown) ? getWeight(Weight::KILO) : 0;
    float rhs_weight = (rhs_Weight.bIsKnown) ?
                       rhs_Weight.getWeight(Weight::KILO) : 0;
    return lhs_weight == rhs_weight;
}

bool Weight::operator<(const Weight &rhs_Weight) const {
    float lhs_weight = (bIsKnown) ? getWeight(Weight::KILO) : 0;
    float rhs_weight = (rhs_Weight.bIsKnown) ?
                       rhs_Weight.getWeight(Weight::KILO) : 0;
    return lhs_weight < rhs_weight;
}

Weight& Weight::operator+= (float rhs_addToWeight ){
    if( bIsKnown = false )
        throw out_of_range("Weight::weight is currently unknown");

    setWeight( weight + rhs_addToWeight );

}


bool Weight::validateWeight(const float newWeight) {
    if( newWeight <= 0.0 ) //cats cannot have zero/negative weight
        return false;

    return true;
}

void Weight::setWeight(float newWeight) {
    bIsKnown = true;
    Weight::weight = newWeight; //in kilograms
}

void Weight::setWeight(float newWeight, UnitOfWeight weightUnit ){
    bIsKnown = true;
    Weight::weight = convertWeight( newWeight , weightUnit , unitOfWeight );
}

void Weight::setMaxWeight(float newMaxWeight) {
    bHasMax = true;
    Weight::maxWeight = newMaxWeight;
}

float Weight::getWeight() const {
    return weight;
}

float Weight::getWeight( Weight::UnitOfWeight weightUnits ) const {
    return convertWeight( weight, weightUnits, KILO );
}

void Weight::dump(){
    cout << "==============================================" << endl;
    FORMAT_LINE( "Weight", "isKnown" )      << Weight::bIsKnown      << endl ;
    FORMAT_LINE( "Weight", "weight" )       << Weight::weight        << endl ;
    FORMAT_LINE( "Weight", "unitOfWeight" ) << Weight::unitOfWeight  << endl ;
    FORMAT_LINE( "Weight", "hasMax" )       << Weight::bHasMax       << endl ;
    FORMAT_LINE( "Weight", "maxWeight" )    << Weight::maxWeight     << endl ;
}

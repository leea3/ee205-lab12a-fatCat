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

#define FORMAT_LINE( className, member ) cout << setw(8) << (className) << setw(20) << (member) << setw(20)

using namespace std;

//constants
const float Weight::UNKNOWN_WEIGHT    = -1.0;
const float Weight::KILOS_IN_A_POUND  = 0.453592;
const float Weight::SLUGS_IN_A_POUND  = 0.031081;
const std::string Weight::POUND_LABEL = "pound";
const std::string Weight::KILO_LABEL  = "kilo";
const std::string Weight::SLUG_LABEL  = "slug";

Weight::Weight () {
    validate();
}

Weight::Weight (float newWeight) {
    validate();
    setWeight( newWeight );
}

Weight::Weight (UnitOfWeight newUnitOfWeight) noexcept{
    unitOfWeight = newUnitOfWeight;
}

Weight::Weight (float newWeight, UnitOfWeight newUnitOfWeight) {
    validate();
    setWeight( newWeight , newUnitOfWeight );
}

Weight::Weight (float newWeight, float newMaxWeight) : Weight(newWeight){
    validate();
    setMaxWeight( newMaxWeight );
}

Weight::Weight (UnitOfWeight newUnitOfWeight, float newMaxWeight) : Weight(newUnitOfWeight){
    setMaxWeight( newMaxWeight );
}

Weight::Weight (float newWeight, UnitOfWeight newUnitOfWeight, float newMaxWeight) : Weight(newWeight,newUnitOfWeight){
    validate();
    setMaxWeight( newMaxWeight );
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
    float weightInPounds;

    switch( fromUnit ){
        case POUND:
            weightInPounds = fromWeight;
            break;
        case KILO:
            weightInPounds = fromKilogramToPound( fromWeight );
            break;
        case SLUG:
            weightInPounds = fromSlugToPound( fromWeight );
            break;
        default: assert( 0 );
    }
    switch( toUnit ){
        case POUND:
            return weightInPounds;
        case KILO:
            return fromPoundToKilogram( weightInPounds );
        case SLUG:
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
    if( bIsKnown == false )
        throw out_of_range("Weight::weight is currently unknown");

    setWeight( weight + rhs_addToWeight );
    return *this;
}


bool Weight::validateWeight(const float newWeight) noexcept {
    if( newWeight <= 0.0 ) //cats cannot have zero/negative weight
        return false;

    return true;
}

bool Weight::validate() const{
    if( bIsKnown == true )
        assert( validateWeight( weight ) );
    if( bHasMax == true ){
        assert( validateWeight( maxWeight ));
        assert( weight < maxWeight );
    }
    return true;
}

void Weight::setWeight(float newWeight) {
    validate();
    if( bIsKnown == true )
        if( newWeight == UNKNOWN_WEIGHT )
            assert(0);
    if(newWeight != UNKNOWN_WEIGHT) {
        bIsKnown = true;
        Weight::weight = newWeight; //in kilograms
    } else
        Weight::weight = UNKNOWN_WEIGHT;
}

void Weight::setWeight(float newWeight, UnitOfWeight weightUnit ){
    validate();
    if( bIsKnown == true )
        if( newWeight == UNKNOWN_WEIGHT )
            assert(0);
    if(newWeight != UNKNOWN_WEIGHT) {
        bIsKnown = true;
        Weight::weight = convertWeight(newWeight, weightUnit, unitOfWeight);
    }else
        Weight::weight = UNKNOWN_WEIGHT;
}

void Weight::setMaxWeight(float newMaxWeight) {
    assert(validateWeight( newMaxWeight ) );
    if( bHasMax == true )
        assert(0);
    bHasMax = true;
    Weight::maxWeight = newMaxWeight;
}

float Weight::getWeight() const {
    validate();
    if( bIsKnown == false )
        return UNKNOWN_WEIGHT;
    return weight;
}

float Weight::getWeight( Weight::UnitOfWeight weightUnits ) const {
    validate();
    if( bIsKnown == false )
        return UNKNOWN_WEIGHT;
    return convertWeight( weight, weightUnits, KILO );
}

float Weight::getMaxWeight() const noexcept {
    validate();
    if( bHasMax == false )
        return UNKNOWN_WEIGHT;
    return maxWeight;
}

bool Weight::getWeightKnown() const noexcept {
    validate();
    return bIsKnown;
}

bool Weight::getHasMax() const noexcept {
    validate();
    return bHasMax;
}

Weight::UnitOfWeight Weight::getUnitOfWeight() const noexcept {
    return unitOfWeight;
}

void Weight::dump(){
    cout << "==============================================" << endl;
    FORMAT_LINE( "Weight", "this" )         << this                  << endl ;
    FORMAT_LINE( "Weight", "isKnown" )      << Weight::bIsKnown      << endl ;
    FORMAT_LINE( "Weight", "weight" )       << Weight::weight        << endl ;
    FORMAT_LINE( "Weight", "unitOfWeight" ) << Weight::unitOfWeight  << endl ;
    FORMAT_LINE( "Weight", "hasMax" )       << Weight::bHasMax       << endl ;
    FORMAT_LINE( "Weight", "maxWeight" )    << Weight::maxWeight     << endl ;
}

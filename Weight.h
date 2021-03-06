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
    enum UnitOfWeight {
        POUND, KILO, SLUG
    };

    static const float UNKNOWN_WEIGHT;

    //conversion constants
    static const float KILOS_IN_A_POUND;
    static const float SLUGS_IN_A_POUND;

    //labels
    static const std::string POUND_LABEL;
    static const std::string KILO_LABEL;
    static const std::string SLUG_LABEL;

private:
    bool  bIsKnown = false;
    bool  bHasMax = false;
    enum  UnitOfWeight unitOfWeight = POUND;
    float weight = UNKNOWN_WEIGHT;
    float maxWeight = UNKNOWN_WEIGHT;

public: //constructors
    Weight();
    Weight(float newWeight);
    Weight(UnitOfWeight newUnitOfWeight) noexcept;
    Weight(float newWeight, UnitOfWeight newUnitOfWeight);
    Weight(float newWeight, float newMaxWeight);
    Weight(UnitOfWeight newUnitOfWeight, float newMaxWeight);
    Weight(float newWeight, UnitOfWeight newUnitOfWeight, float newMaxWeight);

public: //static methods
    static float fromKilogramToPound(const float kilogram) noexcept;
    static float fromPoundToKilogram(float pound) noexcept;
    static float fromSlugToPound(float slug) noexcept;
    static float fromPoundToSlug(float pound) noexcept;

    static float convertWeight(float fromWeight, UnitOfWeight fromUnit, UnitOfWeight toUnit) noexcept;

public: //getters and setters
    void setWeight(float newWeight);
    void setWeight(float newWeight, UnitOfWeight weightUnit );
    void setMaxWeight(float maxWeight);

    float getWeight() const;
    float getWeight( UnitOfWeight weightUnit ) const;
    float getMaxWeight() const noexcept;
    bool  getWeightKnown() const noexcept;
    bool  getHasMax()      const noexcept;
    UnitOfWeight getUnitOfWeight() const noexcept;

    void dump();


public: //validation
    static bool validateWeight(const float newWeight) noexcept;
    bool validate() const;

public:
    bool operator==( const Weight& rhs_Weight ) const;
    bool operator<(const Weight &rhs_Weight) const;
    Weight & operator+= (float rhs_addToWeight );

};
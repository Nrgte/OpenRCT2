#pragma once

#include "../ride/Ride.h"
//#include "../core/DataSerialiser.h"

#include <iostream>
#include <vector>

struct GuestRideRating
{
public:
    RideId ID;
    uint8_t Rating;

//public:
    GuestRideRating(RideId id, uint8_t rating)
        : ID(id)
        , Rating(rating){}
    void SetValues(RideId id, uint8_t rating)
    {
        this->ID = id;
        this->Rating = rating;
    }
    uint8_t getRating()
    {
        return this->Rating;
    }
    RideId getRideID()
    {
        return this->ID;
    }
    Ride* getRide()
    {
        return GetRide(this->ID);
    }
    explicit operator RideId() const
    {
        return ID;
    }
    explicit operator uint8_t() const
    {
        return Rating;
    }
    
    void Serialise(DataSerialiser& stream);
    
};

class AdvancedGuestStats
{
public:
    uint8_t testbla = 0;

    AdvancedGuestStats();
    void InsertRide(RideId id, uint8_t rating);
    uint8_t GetAverageRating(RideId id);
    std::vector<GuestRideRating> FindRidesByRideId(std::vector<GuestRideRating>& ratings, RideId targetId);
    void Serialise(DataSerialiser& stream);
    

//private:
    std::vector<GuestRideRating> RideSatisfaction;

};

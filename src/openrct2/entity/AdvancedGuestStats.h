#pragma once

#include "../ride/Ride.h"
//#include "../core/DataSerialiser.h"

#include <iostream>
#include <vector>
#include <mutex>
#include <deque>
#include <memory>

struct GuestRideRating
{
public:
    RideId ID;
    uint8_t Rating;
    ride_rating MeasuredRideValue;

//public:
    GuestRideRating(RideId id, uint8_t rating, ride_rating measuredRideValue)
        : ID(id)
        , Rating(rating)
        , MeasuredRideValue (measuredRideValue){}
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
    ride_rating getMeasuredValue()
    {
        return this->MeasuredRideValue;
    }
    explicit operator RideId() const
    {
        return ID;
    }
    explicit operator uint8_t() const
    {
        return Rating;
    }
    
    //void Serialise(DataSerialiser& stream);
    
};

/* Possible Traits
Traits:
- Stingy
- Superfan
-

*/

class AdvancedGuestStats
{
public:
    mutable std::mutex pathfindingQueueMutex;

    AdvancedGuestStats();
    void InsertRideIntensityRating(RideId id, uint8_t rating, ride_rating rideRating);
    float GetMedianIntensityRating(RideId id, ride_rating currentIntensity);
    std::string GetMedianIntensityRatingString(RideId id, ride_rating currentIntensity);
    uint8_t GetQueueTimeThreshold();
    uint8_t GetQueueTimeCancelChance();
    std::vector<GuestRideRating> FindRidesByRideId(std::vector<GuestRideRating>& ratings, RideId targetId);
    std::vector<GuestRideRating> FindRideIntensityRatingsByRideId(RideId targetId);
    void DeleteOldIntensityRatings(RideId id, ride_rating currentIntensity);
    //void Serialise(DataSerialiser& stream);
   

//private:
    std::vector<GuestRideRating> RideIntensitySatisfaction{};
    std::deque<TileCoordsXYZ> PathfindingQueue;

};

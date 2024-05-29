#include "AdvancedGuestStats.h"

#include "../ride/Ride.h"
#include "../core/DataSerialiser.h"
#include "Guest.h"

#include <iostream>
#include <algorithm>

using namespace OpenRCT2;

// Empty constructor with no arguments
AdvancedGuestStats::AdvancedGuestStats() 
{
}

void AdvancedGuestStats::InsertRide(RideId id, uint8_t rating)
{
    GuestRideRating temp(id, rating);
    this->RideSatisfaction.push_back(temp);
}

uint8_t AdvancedGuestStats::GetAverageRating(RideId id)
{
    std::vector<GuestRideRating> matches = FindRidesByRideId(this->RideSatisfaction, id);
    if (matches.size() == 0)
        return 0;


    int totalRideRating = 0;
    for (GuestRideRating& ride : matches)
    {
        totalRideRating += ride.getRating();
    }

    return totalRideRating / matches.size();
}

std::vector<GuestRideRating> AdvancedGuestStats::FindRidesByRideId(std::vector<GuestRideRating>& ratings, RideId targetId)
{
    // Use std::find_if to search for matching RideRating objects
    std::vector<GuestRideRating> matchingRides;
    std::copy_if(ratings.begin(), ratings.end(), std::back_inserter(matchingRides), [targetId](GuestRideRating& rating) {
        return rating.getRideID() == targetId;
    });
    return matchingRides;
}


void AdvancedGuestStats::Serialise(DataSerialiser& stream)
{
    //stream << RideSatisfaction;
    stream << testbla;
}

void GuestRideRating::Serialise(DataSerialiser& stream)
{
    stream << ID;
    stream << Rating;
}

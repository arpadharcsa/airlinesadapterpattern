#include "atlantisplanner.h"
#include <iostream>
#include <algorithm>

void AtlantisPlanner::updateData()
{
    map<string,map<string,int>> network;
    for (auto it = airlines->begin(); it != airlines->end(); ++it){
        const AtlantisAirlines::City city = *it;
        network[city.name] = city.travels;
    }
    routeFinder.changeNetwork(network);
}

int AtlantisPlanner::getDirectTravelTime(const string &from, const string &to)
{
    AtlantisAirlines::City fromCity;
    for (auto it = airlines->begin(); it != airlines->end(); ++it){
        const AtlantisAirlines::City city = *it;
        if(city.name == from){
            fromCity = city;
        }
    }
    return fromCity.travels[to];
}

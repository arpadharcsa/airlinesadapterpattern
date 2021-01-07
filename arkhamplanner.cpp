#include "arkhamplanner.h"
#include <iostream>
#include <algorithm>

void ArkhamPlanner::updateData()
{
    map<string,map<string,int>> network;
    const vector<string> cities = airlines->getCities();

    for(unsigned int i=0 ; i < cities.size() ; i++)
    {
        for(unsigned int j=0 ; j < cities.size() ; j++)
        {
            try {
                int time = airlines->getOneTime(i,j);
                network[cities[i]][cities[j]] = time;
            } catch (NoTravelException ex) {
               //cerr << ex.what();
            }
        }
    }
    routeFinder.changeNetwork(network);
}

int ArkhamPlanner::getDirectTravelTime(const string &from, const string &to)
{
    const vector<string> cities = airlines->getCities();
    auto fromElement = find(cities.begin(),cities.end(),from);
    auto toElement = find(cities.begin(),cities.end(),to);
    if ((fromElement == cities.end()) || (toElement == cities.end()))
    {
        //early exit if no city found
        return 0;
    }

    int fromIndex = std::distance(cities.begin(), fromElement);
    int toIndex = std::distance(cities.begin(), toElement);
    try {
        int time = airlines->getOneTime(fromIndex,toIndex);
        return time;
    } catch (NoTravelException ex) {
        return 0;
    }
}

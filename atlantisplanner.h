#ifndef ATLANTISPLANNER_H
#define ATLANTISPLANNER_H

#include "atlantisairlines.h"
#include "plannerinterface.h"

class AtlantisPlanner : public PlannerInterface
{
    AtlantisAirlines *airlines;
public:
    AtlantisPlanner(AtlantisAirlines *airlines)
    {
        this->airlines = airlines;
    }

    virtual void updateData();

    virtual int getDirectTravelTime(const string &from, const string &to);

};
#endif // ATLANTISPLANNER_H

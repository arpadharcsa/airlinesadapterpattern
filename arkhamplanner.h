#ifndef ARKHAMPLANNER_H
#define ARKHAMPLANNER_H

#include "arkhamairlines.h"
#include "plannerinterface.h"
class ArkhamPlanner : public PlannerInterface
{
    ArkhamAirlines *airlines;
public:
    ArkhamPlanner(ArkhamAirlines *airlines)
    {
        this->airlines = airlines;
    }

    virtual void updateData();

    virtual int getDirectTravelTime(const string &from, const string &to);

};
#endif // ARKHAMPLANNER_H

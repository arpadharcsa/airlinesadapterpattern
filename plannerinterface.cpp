#include "plannerinterface.h"

list<string> PlannerInterface::findRoute(const string &from, const string &to)
{
    list<string> route = routeFinder.dijkstra(from,to);
    if(route.size() == 0){
        throw NoRouteBetweenCitiesException(from,to);
    }
    return route;
}

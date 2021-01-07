#ifndef PLANNERINTERFACE_H
#define PLANNERINTERFACE_H

#include <list>
#include <string>
#include "routefinder.h"


class NoRouteBetweenCitiesException : public exception
{
    string message;

public:
    NoRouteBetweenCitiesException(const string &from, const string &to)
    {
        this->message = "No route from " + from + " to " + to;
    }
    const char *what() const noexcept override
    {
        return this->message.c_str();
    }
};


class PlannerInterface
{

protected:
    RouteFinder routeFinder;

public:
    virtual void updateData() = 0;

    virtual int getDirectTravelTime(const string &from, const string &to) = 0;

    list<string> findRoute(const string &from, const string &to);

    virtual ~PlannerInterface() = default;
};

#endif // PLANNERINTERFACE_H

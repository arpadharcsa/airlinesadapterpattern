#ifndef ATLANTISAIRLINES_H
#define ATLANTISAIRLINES_H

#include <map>
#include <string>
#include <list>

using namespace std;

class AtlantisAirlines
{
public:
	struct City
	{
		string name;
		map<string,int> travels;
	};
	list<City> cities;
public:
	AtlantisAirlines();
	const list<City> &getCities() const;
	list<City>::const_iterator begin() const;
	list<City>::const_iterator end() const;
};

#endif // ATLANTISAIRLINES_H

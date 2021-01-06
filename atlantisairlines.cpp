#include "atlantisairlines.h"

AtlantisAirlines::AtlantisAirlines()
{
	cities.push_back({"London", {{"Berlin", 140},{"Athens",340}}});
	cities.push_back({"Berlin", {{"Budapest", 140}, {"London", 140}}});
	cities.push_back({"Madrid", {{"Rome", 90}, {"Paris", 110}}});
	cities.push_back({"Moscow", {{"Athens", 410}, {"Budapest", 280}}});
	cities.push_back({"Athens", {{"London", 340}, {"Moscow", 410}, {"Rome", 120}}});
	cities.push_back({"Paris", {{"Madrid", 110}}});
	cities.push_back({"Budapest", {{"Berlin", 140}, {"Moscow", 280}}});
	cities.push_back({"Rome", {{"Madrid", 90}, {"Athens", 120}}});
}

const list<AtlantisAirlines::City> &AtlantisAirlines::getCities() const
{
	return cities;
}

list<AtlantisAirlines::City>::const_iterator AtlantisAirlines::begin() const
{
	return cities.begin();
}

list<AtlantisAirlines::City>::const_iterator AtlantisAirlines::end() const
{
	return cities.end();
}

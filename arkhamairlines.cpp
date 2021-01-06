#include "arkhamairlines.h"

ArkhamAirlines::ArkhamAirlines():
	cities({"London", "Paris", "Madrid", "Budapest", "Moscow", "Athens", "Rome", "Berlin"}),
	times(8,vector<int>(8,-1))
{
	times[0][3]=times[3][0]=200;
	times[0][4]=times[4][0]=350;
	times[1][2]=times[2][1]=80;
	times[1][4]=times[4][1]=400;
	times[3][4]=times[4][3]=300;
	times[5][6]=times[6][5]=100;
	times[5][7]=times[7][5]=250;
}

const vector<string> &ArkhamAirlines::getCities() const
{
	return cities;
}

const vector<vector<int> > &ArkhamAirlines::getTimes() const
{
	return times;
}

int ArkhamAirlines::getOneTime(unsigned int startIdx, unsigned int endIdx) const
{
	if (startIdx>=cities.size() || endIdx>=cities.size()) throw InvalidCityIndexException();
	if (times[startIdx][endIdx]<0) throw NoTravelException();
	return times[startIdx][endIdx];
}

#ifndef ARKHAMAIRLINES_H
#define ARKHAMAIRLINES_H

#include <vector>
#include <string>
#include <exception>

using namespace std;

class InvalidCityIndexException : public exception
{
public:
	const char *what() const noexcept override
	{
		return "Invalid city index pair";
	}
};

class NoTravelException : public exception
{
public:
	const char *what() const noexcept override
	{
		return "No direct travel between the cities";
	}
};

class ArkhamAirlines
{
	vector<string> cities;
	vector<vector<int>> times;
public:
	ArkhamAirlines();
	const vector<string> &getCities() const;
	const vector<vector<int>> &getTimes() const;
	int getOneTime(unsigned int startIdx, unsigned int endIdx) const;
};

#endif // ARKHAMAIRLINES_H

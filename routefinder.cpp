#include "routefinder.h"

// just another algorithm
template <class ForwardIterator, class Compare, class UnaryPredicate>
ForwardIterator min_element_if (ForwardIterator first, ForwardIterator last, Compare comp, UnaryPredicate pred)
{
	if (first==last) return last;
	ForwardIterator smallest = last;
	while (first!=last)
	{
		if (pred(*first))
			if (smallest==last || comp(*first,*smallest))
				smallest=first;
		++first;
	}
	return smallest;
}

RouteFinder::RouteFinder(const map<string, map<string, int> > &network):
	network(network)
{
}

void RouteFinder::changeNetwork(const map<string, map<string, int> > &network)
{
	this->network=network;
}

// Good old Dijkstra
list<string> RouteFinder::dijkstra(const string &from, const string &to) const
{
	if (network.find(from)==network.end() || network.find(to)==network.end()) return {};

	// Some types
	enum SearchStates{
		S_NONE=0,
		S_INPROGRESS,
		S_FINISHED
	};
	struct SearchData
	{
		int distance;
		SearchStates state;
		string previousCity;
	};

	// Initialization
	map<string,SearchData> cityStates;
	for (const auto &city : network)
		cityStates.insert({city.first, SearchData{-1,S_NONE,string()}});
	cityStates[from]=SearchData{0,S_INPROGRESS,string()};

	// Lambda functions
	auto smallestDistance=[](const pair<string,SearchData> &sd1, const pair<string,SearchData> &sd2){
		return sd1.second.distance<sd2.second.distance;
	};
	auto stateIsInProgress=[](const pair<string,SearchData> &sd){
		return sd.second.state==S_INPROGRESS;
	};


	bool routeFound=false;
	while (!routeFound)
	{
		// Find started but unfinished (in progress) node with shortest distance
		auto minInprogressIt=min_element_if(cityStates.begin(), cityStates.end(), smallestDistance, stateIsInProgress);
		if (minInprogressIt==cityStates.end()) return {}; // ERROR: no route is possible
		auto &cityData=minInprogressIt->second;
		string cityName=minInprogressIt->first;
		// It is now fixed
		cityData.state=S_FINISHED;
		if (cityName==to)
		{
			// Destination reached, found route;
			routeFound=true;
			string tempName=cityName;
			// Build city list
			list<string> cityList;
			while (!tempName.empty())
			{
				cityList.push_front(tempName);
				tempName=cityStates[tempName].previousCity;
			}
			return cityList;
		}
		// Update neighbours if needed
		const auto &cityTransits=network.find(cityName)->second;
		for (const auto &transit : cityTransits)
		{
			auto &neighbour=cityStates[transit.first];
			if (neighbour.state==S_NONE || (neighbour.state==S_INPROGRESS && neighbour.distance>cityData.distance+transit.second))
			{
				neighbour.distance=cityData.distance+transit.second;
				neighbour.previousCity=cityName;
				neighbour.state=S_INPROGRESS;
			}
		}
	}
	return {}; // Just in case
}

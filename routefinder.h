#ifndef ROUTEFINDER_H
#define ROUTEFINDER_H

#include <map>
#include <string>
#include <list>

using namespace std;

class RouteFinder
{
	map<string,map<string,int>> network;
public:
	RouteFinder(const map<string,map<string,int>> &network={});
	void changeNetwork(const map<string,map<string,int>> &network);
	list<string> dijkstra(const string &from, const string &to) const;
};

#endif // ROUTEFINDER_H

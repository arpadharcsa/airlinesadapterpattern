#include <iostream>
#include "arkhamairlines.h"
#include "atlantisairlines.h"
#include "routefinder.h"
#include "plannerinterface.h"
#include "arkhamplanner.h"
//#include "atlantisplanner.h"

using namespace std;

int main()
{

	// RouteFinder example
	cout << endl << endl << "RouteFinder example" << endl;
	{

		RouteFinder rf({
						   {"London", {{"Berlin", 140},{"Athens",340}}},
						   {"Berlin", {{"Budapest", 140}, {"London", 140}}},
						   {"Madrid", {{"Rome", 90}, {"Paris", 110}}},
						   {"Moscow", {{"Athens", 410}, {"Budapest", 280}}},
						   {"Athens", {{"London", 340}, {"Moscow", 410}}},
						   {"Paris", {{"Madrid", 110}}},
						   {"Budapest", {{"Berlin", 140}, {"Moscow", 280}}},
						   {"Rome", {{"Madrid", 90}}}
					   });

		cout << endl << "Athens to Berlin:" << endl;
		auto route1=rf.dijkstra("Budapest", "Berlin"); // Ilyen van közvetlenül
		for (string city: route1)
			cout << city << endl;
		// Budapest
		// Berlin

		cout << endl << "London to Moscow:" << endl;
		auto route2=rf.dijkstra("London", "Moscow"); // Itt kell 3 átszállás
		for (string city: route2)
			cout << city << endl;
		// London
		// Berlin
		// Budapest
		// Moscow

		cout << endl << "London to Rome:" << endl;
		auto route3=rf.dijkstra("London", "Rome"); // Ilyen nincs
		for (string city: route3)
			cout << city << endl;
	}

    // PlannerInterface test
    cout << endl << endl << "PlannerInterface test" << endl;
    {
        // A dummy class with empty network
        class Dummy : public PlannerInterface
        {
        public:
            void updateData(){cout << "updateData" << endl;}
            int getDirectTravelTime(const string &, const string &){cout << "getDirectTravelTime" << endl;return 0;}
        };

        PlannerInterface *test=new Dummy;
        // Ha valamelyik függvény nincs meg, az maradjon kommentben
        test->updateData(); // updateData
        test->getDirectTravelTime("London", "Paris"); // getDirectTravelTime
        try {
            list<string> route=test->findRoute("London", "Madrid");
            cout << route.size() << endl;
            for (string city : route) cout << city << endl;
        }  catch (exception &e) {
            cout << e.what() << endl; // "No route from London to Madrid
        }
        delete test;
    }

//	// ArkhamPlanner test: konstruktor, updateData
    cout << endl << endl << "ArkhamPlanner test: konstruktor, updateData" << endl;
    {
        ArkhamAirlines aa;
        PlannerInterface *apl=new ArkhamPlanner(&aa);

        apl->updateData();
        list<pair<string,string>> plans={{"London", "Madrid"}, {"Athens", "Rome"}, {"Budapest", "Berlin"}, {"Moscow", "Paris"}};
        for (auto routePlan: plans)
        {
            cout << "Travel route from " << routePlan.first << " to " << routePlan.second << ":" << endl;
            try {
                auto route=apl->findRoute(routePlan.first, routePlan.second);
                for (string city : route) cout << city << endl;
            }  catch (exception &e) {
                cout << e.what() << endl; // "No route from London to Madrid
            }
        }
        delete apl;
////		Travel route from London to Madrid:
////		London
////		Moscow
////		Paris
////		Madrid
////		Travel route from Athens to Rome:
////		Athens
////		Rome
////		Travel route from Budapest to Berlin:
////		No route from Budapest to Berlin
////		Travel route from Moscow to Paris:
////		Moscow
////		Paris
    }

    // ArkhamPlanner test: getDirectTravelTime
    cout << endl << endl << "ArkhamPlanner test: getDirectTravelTime " << endl;
    {
        ArkhamAirlines aa;
        PlannerInterface *apl=new ArkhamPlanner(&aa);

        apl->updateData();
        list<pair<string,string>> plans={{"London", "Madrid"}, {"Athens", "Rome"}, {"Budapest", "Berlin"}, {"Moscow", "Paris"}};
        for (auto routePlan: plans)
        {
            cout << "Direct travel time from " << routePlan.first << " to " << routePlan.second << ": " << apl->getDirectTravelTime(routePlan.first, routePlan.second) << endl;
        }
        delete apl;
////		Direct travel time from London to Madrid: 0
////		Direct travel time from Athens to Rome: 100
////		Direct travel time from Budapest to Berlin: 0
////		Direct travel time from Moscow to Paris: 400
    }

//	// AtlantisPlanner test: konstruktor, updateData
//	cout << endl << endl << "AtlantisPlanner test: konstruktor, updateData" << endl;
//	{
//		AtlantisAirlines aa;
//		PlannerInterface *apl=new AtlantisPlanner(&aa);

//		apl->updateData();
//		list<pair<string,string>> plans={{"London", "Madrid"}, {"Athens", "Rome"}, {"Budapest", "Berlin"}, {"Moscow", "Paris"}};
//		for (auto routePlan: plans)
//		{
//			cout << "Travel route from " << routePlan.first << " to " << routePlan.second << ":" << endl;
//			try {
//				auto route=apl->findRoute(routePlan.first, routePlan.second);
//				for (string city : route) cout << city << endl;
//			}  catch (exception &e) {
//				cout << e.what() << endl; // "No route from London to Madrid
//			}
//		}
//		delete apl;
////		Travel route from London to Madrid:
////		London
////		Athens
////		Rome
////		Madrid
////		Travel route from Athens to Rome:
////		Athens
////		Rome
////		Travel route from Budapest to Berlin:
////		Budapest
////		Berlin
////		Travel route from Moscow to Paris:
////		Moscow
////		Athens
////		Rome
////		Madrid
////		Paris
//	}

//	// AtlantisPlanner test: getDirectTravelTime
//	cout << endl << endl << "AtlantisPlanner test: getDirectTravelTime" << endl;
//	{
//		AtlantisAirlines aa;
//		PlannerInterface *apl=new AtlantisPlanner(&aa);

//		apl->updateData();
//		list<pair<string,string>> plans={{"London", "Madrid"}, {"Athens", "Rome"}, {"Budapest", "Berlin"}, {"Moscow", "Paris"}};
//		for (auto routePlan: plans)
//		{
//			cout << "Direct travel time from " << routePlan.first << " to " << routePlan.second << ": " << apl->getDirectTravelTime(routePlan.first, routePlan.second) << endl;
//		}
//		delete apl;
////		Direct travel time from London to Madrid: 0
////		Direct travel time from Athens to Rome: 120
////		Direct travel time from Budapest to Berlin: 140
////		Direct travel time from Moscow to Paris: 0
//	}


	return 0;
}

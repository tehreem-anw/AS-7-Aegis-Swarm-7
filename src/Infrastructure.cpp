#include "Infrastructure.h"
using namespace std;

// Default Constructor
Infrastructure::Infrastructure() : buildingName("Unknown"), type("General"), location(0,0,0), protectionRadius(100.0) {}

// Parameterized Constructor: Inputs the specific site in the city
Infrastructure::Infrastructure(string name, string t, Coordinate loc, double radius): buildingName(name), type(t), location(loc), protectionRadius(radius) {}

// Displays the site data for the Command Center's protection log
void Infrastructure::displayInfraDetails() const {
    cout<<"Infrastructure: "<<buildingName<<" ("<<type<<") at ";
    location.display();
    cout<<" | Shield: "<<protectionRadius<<"m"<<endl;
}

// Logic for the Location Shield: Checks if an intercept point is too close to a protected site
bool Infrastructure::isWithinZone(const Coordinate& targetCoord) const {
    double distance = location.calculateDistance(targetCoord);
    return (distance <= protectionRadius);
}

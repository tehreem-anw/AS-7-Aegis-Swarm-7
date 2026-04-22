#pragma once
#include <iostream>
#include <string>
#include "Coordinate.h"
using namespace std;

class Infrastructure {
private:
    string buildingName;
    string type; 	// e.g., "Hospital", "School", "Power Plant"
    Coordinate location; 	// Composes Coordinate class for location
    double protectionRadius; 	// The "No-Fire" zone size

public:
    // Constructors
    Infrastructure();
    Infrastructure(string name, string t, Coordinate loc, double radius);

    // Member Functions
    void displayInfraDetails() const;
    bool isWithinZone(const Coordinate& targetCoord) const;

    // Getters
    string getName() const { return buildingName; }
    string getType() const { return type; }
    Coordinate getLocation() const { return location; }
};

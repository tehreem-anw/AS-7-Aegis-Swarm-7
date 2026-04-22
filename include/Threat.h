#pragma once
#include <iostream>
#include <string>
#include "Coordinate.h"
#include "TargetProfile.h"

using namespace std;

// Abstract Base Class for threat units
class Threat {
protected:
    string threatID;
    Coordinate currentPosition;		//Composition: Each target has a current position
    TargetProfile profile; 			//Composition: Each target has a target profile
    double speed;

public:
    // Constructor
    Threat(string id, Coordinate pos, TargetProfile prof, double s);

    // Virtual Destructor
    virtual ~Threat() {}

    // Pure Virtual Function: Each threat moves according to different physics
    virtual void calculateTrajectory() = 0;

    // Shared display logic
    virtual void displayThreatInfo() const;

    // Getters
    string getID() const { return threatID; }
    Coordinate getPosition() const { return currentPosition; }
    TargetProfile getProfile() const { return profile; }
    double getSpeed() const { return speed; }
};

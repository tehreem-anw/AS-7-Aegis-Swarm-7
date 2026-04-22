#pragma once
#include <iostream>
#include <string>
#include "Coordinate.h"
using namespace std;

// Abstract Base Class for interceptor units
class Interceptor {
protected:
    string unitID;
    Coordinate currentPosition;     // Composition: Each unit has a physical location
    double speed;
    bool isActive;

public:
    // Constructor
    Interceptor(string id, Coordinate pos, double s);

    // Virtual Destructor
    virtual ~Interceptor() {}

    // Pure Virtual Function: Each drone behaves differently
    virtual void updatePosition() = 0;

    // Shared display logic for all interceptors
    virtual void displayInterceptorInfo() const;

    // Getters
    string getID() const { return unitID; }
    Coordinate getPosition() const { return currentPosition; }
    double getSpeed() const { return speed; }
    bool getStatus() const { return isActive; }
    
    void setStatus(bool status) { isActive = status; }
};

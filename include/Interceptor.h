#pragma once
#include <iostream>
#include <string>
#include "Coordinate.h"
using namespace std;

class Threat;
class IntelMessage;
class CommandCenter;

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

	//Pure Vurtial Function: Determines if the unit is destroyed upon successful engagement
	virtual bool isExpendable() const = 0;

    // Shared display logic for all interceptors
    virtual void displayInterceptorInfo() const;
    
    // Functions for communication logic
    virtual void receiveMessage(const IntelMessage& msg); 
	void sendMessage(IntelMessage& msg, CommandCenter& center);
    
    // Friend Function: For collision logic (Links Threat & Interceptor)
    friend bool checkCollision(const Threat& target, const Interceptor& drone);
    
    // Getters
    string getID() const { return unitID; }
    Coordinate getPosition() const { return currentPosition; }
    double getSpeed() const { return speed; }
    bool getStatus() const { return isActive; }
    
    // Setters
    void setStatus(bool status) { isActive = status; }
};

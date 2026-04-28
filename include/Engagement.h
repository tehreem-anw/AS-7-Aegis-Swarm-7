#pragma once
#include <iostream>
#include <string>
#include "Interceptor.h"
#include "Threat.h"
#include "Infrastructure.h"
#include "IntelMessage.h"
using namespace std;

class Engagement {
private:
    string engagementID;
    Threat* targetThreat;           // Association: Points to a specific threat
    Interceptor* assignedSwarm[5];  // Association: Array of pointers to drones
    int swarmSize;
    bool isResolved;

public:
    // Constructor
    Engagement(string id, Threat* threat, Interceptor* drones[], int size);

    // Member Functions
    void executeTacticalTick(Infrastructure* protectedSites[], int siteCount); 
    bool isSafeToEngage(Coordinate impactPos, Infrastructure* sites[], int count) const;
    void resolve();
    void replaceDrone(int index, Interceptor* newDrone);
    
    // Getters
    bool getStatus() const { return isResolved; }
    int getSwarmSize() const { return swarmSize; }
    Interceptor* getDrone(int index) { return assignedSwarm[index]; }
};

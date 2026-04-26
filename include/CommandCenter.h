#pragma once
#include <iostream>
#include <string>
#include "Interceptor.h"
#include "Threat.h"
#include "Engagement.h"
#include "Infrastructure.h"
using namespace std;

class CommandCenter {
private:
    Interceptor* availableDrones[20];
    int droneCount;
    Engagement* activeEngagements[10];
    int engagementCount;
    Infrastructure* protectedSites[10];
    int siteCount;
public:
	// Constructor
    CommandCenter();
    
    // Member Functions
    void registerDrone(Interceptor* drone);
    void registerInfrastructure(Infrastructure* site);
    void handleIncomingThreat(Threat* threat);
    void updateSystem();
    void processIncomingIntel(const IntelMessage& msg);
    
    // Destructor
    ~CommandCenter();
};

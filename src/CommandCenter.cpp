#include "CommandCenter.h"
#include "IntelMessage.h"
#include <iostream>
using namespace std;

CommandCenter::CommandCenter() : droneCount(0), engagementCount(0), siteCount(0) {
    // Initialize arrays to null
    for(int i=0; i<20; i++) availableDrones[i] = nullptr;
    for(int i=0; i<10; i++) activeEngagements[i] = nullptr;
    for(int i=0; i<10; i++) protectedSites[i] = nullptr;
}

// Function to add drone
void CommandCenter::registerDrone(Interceptor* drone) {
    if (droneCount < 20) {
        availableDrones[droneCount++] = drone;
    }
}

// Function to add site
void CommandCenter::registerInfrastructure(Infrastructure* site) {
    if (siteCount < 10) {
        protectedSites[siteCount++] = site;
    }
}

// Brain of the Program: Creates Engagement
void CommandCenter::handleIncomingThreat(Threat* threat) {
    if (engagementCount >= 10) return; // System at max capacity

    int risk = threat->getProfile().getRiskLevel();
    Interceptor* assignedSubset[5];
    int assignedCount = 0;

    // TARGET PRIORITIZATION
    int dronesNeeded = 0;
    string requiredType = "";

    if (risk >= 9) {
        dronesNeeded = 5; 	
        requiredType = "KAM";	// 5 kamikazes for a high-speed ballistic missile
    } else if (risk >= 5) {
        dronesNeeded = 1;	
        requiredType = "SNP";	// 1 sniper for a mid-tier loitering munition
    } else {
        dronesNeeded = 1;
        requiredType = "JAM";	// 1 jammer for a low-risk electronic decoy
    }

    cout << "[COMMAND]: Deploying " << dronesNeeded << " " << requiredType << " units for Threat " << threat->getID() << endl;

    // SMART SELECTION: Search the hangar for the specific drone type
    for (int i = droneCount - 1; i >= 0 && assignedCount < dronesNeeded; i--) {
        // Check if the first 3 letters of the ID match what we need (e.g., "KAM")
        if (availableDrones[i] != nullptr && availableDrones[i]->getID().substr(0, 3) == requiredType) {
            
            assignedSubset[assignedCount++] = availableDrones[i];

            // Shift the remaining drones to fill the empty spot in the hangar
            for (int j = i; j < droneCount - 1; j++) {
                availableDrones[j] = availableDrones[j + 1];
            }
            availableDrones[--droneCount] = nullptr;
        }
    }

    if (assignedCount > 0) {
        activeEngagements[engagementCount++] = new Engagement("ENG-" + threat->getID(), threat, assignedSubset, assignedCount);
    }
}

// Brain of the Program: Implements Engagement
void CommandCenter::updateSystem() {
    for (int i = 0; i < engagementCount; i++) {
        if (activeEngagements[i] == nullptr) continue;

        // 1. Run the tactical tick
        activeEngagements[i]->executeTacticalTick(protectedSites, siteCount);

		// 2. THE HANDOVER LOGIC: Check for battery alerts
        for (int d=0; d<activeEngagements[i]->getSwarmSize(); d++) {
            Interceptor* currentDrone = activeEngagements[i]->getDrone(d);

            if (currentDrone != nullptr && currentDrone->isLowOnPower()) {
                cout<<"[ALERT]: Drone "<<currentDrone->getID()<<" battery low! Initiating Handover."<<endl;

                // Step A: Find out what type we need (First 3 chars: "KAM", "SNP", "JAM")
                string typeNeeded = currentDrone->getID().substr(0, 3);
                Interceptor* freshReplacement = nullptr;
                int replacementIndex = -1;

                // Step B: Search Hangar for a fresh drone of the same type
                for (int k=0; k<droneCount; k++) {
                    if (availableDrones[k]->getID().substr(0, 3) == typeNeeded && !availableDrones[k]->isLowOnPower()) {
                        freshReplacement = availableDrones[k];
                        replacementIndex = k;
                        break;
                    }
                }

                // Step C: If fresh drone found, swap them
                if (freshReplacement != nullptr) {
                    cout<<"[HANDOVER]: Swapping "<<currentDrone->getID()<<" with "<<freshReplacement->getID()<<endl;
                    
                    activeEngagements[i]->replaceDrone(d, freshReplacement);

                    // Put the old drone back in the hangar (to be "recharged")
                    currentDrone->setStatus(false); // Set to Inactive
                    availableDrones[replacementIndex] = currentDrone; 
                    
                } else {
                    cout<<"[CRITICAL]: No fresh "<<typeNeeded<<" units available in hangar!"<<endl;
                }
            }
        }

        // 3. If the threat is resolved, clean up the engagement
        if (activeEngagements[i]->getStatus()) {
            cout<<"[COMMAND]: Engagement "<<i<<" resolved. Clearing memory."<<endl;
            delete activeEngagements[i];
            
            // Shift remaining engagements left to fill the gap (reorganising array)
            for (int j = i; j < engagementCount - 1; j++) {
                activeEngagements[j] = activeEngagements[j + 1];
            }
            activeEngagements[--engagementCount] = nullptr;
            i--; 
        }
    }
}

void CommandCenter::processIncomingIntel(const IntelMessage& msg) {
    cout<<"[BASE-INTEL]: Report from "<<msg.getSender()<<": "<<msg.getData()<<endl;
}

// Destructor: Clean up allocated memory
CommandCenter::~CommandCenter() {
    for (int i = 0; i < droneCount; i++) delete availableDrones[i];
    for (int i = 0; i < engagementCount; i++) delete activeEngagements[i];
    for (int i = 0; i < siteCount; i++) delete protectedSites[i];
}

#pragma once
#include <iostream>
#include "CommandCenter.h"
#include "Infrastructure.h"
#include "Threat.h"
// Include specific threats and drones here if instantiating them directly
using namespace std;

class WarRoom {
private:
    CommandCenter hq;               // Composition: The WarRoom owns the Command Center
    bool isSimulationActive;
    int clockTick;                  // Tracks the "seconds" of the battle

public:
    // Constructor
    WarRoom();

    // Setup Functions
    void initializeDefenseGrid();
    void loadInfrastructure();

    // The Wave Generator
    void spawnThreatWave();

    // The Main Loop
    void runSimulation();
};

#include <iostream>
#include "WarRoom.h"

using namespace std;

int main() {
    // 1. Initialize the Simulation Engine
    WarRoom as7;

    // 2. Load the Map (Hospitals, Power Plants, etc.)
    as7.loadInfrastructure();

    // 3. Prepare the Hangar (Kamikazes, Snipers, Jammers)
    as7.initializeDefenseGrid();

    // 4. Detect Incoming Enemy Wave
    as7.spawnThreatWave();

    // 5. Start the Real-Time Tactical Simulation
    as7.runSimulation();

    cout << "\n[FINAL]: Mission debrief complete. System standing down." << endl;

    return 0;
}

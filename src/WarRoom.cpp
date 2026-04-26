#include "WarRoom.h"
#include "KamikazeDrone.h"
#include "JammerDrone.h"
#include "SniperDrone.h"
#include "BallisticMissile.h"
#include "LoiteringMunition.h"
#include "ElectronicDecoy.h"

using namespace std;

WarRoom::WarRoom() : isSimulationActive(true), clockTick(0) {}

void WarRoom::loadInfrastructure() {
    cout<<"=== AS-7 WAR ROOM: INITIALIZING INFRASTRUCTURE ==="<<endl;
    // Create No-Fire Zones
    Infrastructure* hospital = new Infrastructure("Jinnah Hospital", "Hospital", Coordinate(0, 50, 0), 20.0);
    Infrastructure* powerPlant = new Infrastructure("Nuclear Plant", "Plant", Coordinate(0, -50, 0), 30.0);
    
    hq.registerInfrastructure(hospital);
    hq.registerInfrastructure(powerPlant);
}

void WarRoom::initializeDefenseGrid() {
    cout<<"=== AS-7 WAR ROOM: LOADING DRONE ASSETS ==="<<endl;
    
    // Load 5 Kamikazes, 2 Snipers, 3 Jammers
    for(int i = 0; i < 5; i++) {
        hq.registerDrone(new KamikazeDrone("KAM-" + to_string(i+1), Coordinate(0,0,0), 100.0));
    }
    for(int i = 0; i < 2; i++) {
        hq.registerDrone(new SniperDrone("SNP-" + to_string(i+1), Coordinate(0,0,0), 0.0));
    }
    for(int i = 0; i < 3; i++) {
        hq.registerDrone(new JammerDrone("JAM-" + to_string(i+1), Coordinate(0,0,0), 40.0)); 
    }
    cout<<"[SYSTEM]: All drones loaded and on standby."<<endl;
}

void WarRoom::spawnThreatWave() {
    cout << "\n=== WARNING: INCOMING ENEMY WAVE ===" << endl;
    
    TargetProfile highRisk("High-Speed", 9, 670.0);
    TargetProfile medRisk("Low-Speed", 6, 167.0);
    TargetProfile lowRisk("Decoy", 2, 67.0);

    // FIX: Set Y and Z to 0 for EVERYTHING. 
    // This forces them to collide on the X-axis lane.
    Threat* missile = new BallisticMissile("BM-67", Coordinate(100, 0, 0), highRisk, 200.0);
    Threat* munition = new LoiteringMunition("LM-99", Coordinate(40, 0, 0), medRisk, 30.0);
    Threat* decoy = new ElectronicDecoy("ED-01", Coordinate(50, 0, 0), lowRisk, 15.0);

    hq.handleIncomingThreat(missile);
    hq.handleIncomingThreat(munition);
    hq.handleIncomingThreat(decoy);
}

void WarRoom::runSimulation() {
    cout<<"\n=== AS-7 SIMULATION STARTED (TACTICAL OVERVIEW) ==="<<endl;
    while (isSimulationActive && clockTick < 10) { 
        cout<<"\n--- CLOCK TICK: "<<clockTick<<" ---"<<endl;
        
        hq.updateSystem(); // Triggers tactical updates and collision checks
        clockTick++;

    }
    cout<<"\n=== AS-7 SIMULATION TERMINATED ==="<<endl;
}

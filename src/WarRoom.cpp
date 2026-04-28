#include "WarRoom.h"
#include "KamikazeDrone.h"
#include "JammerDrone.h"
#include "SniperDrone.h"
#include "BallisticMissile.h"
#include "LoiteringMunition.h"
#include "ElectronicDecoy.h"
using namespace std;

WarRoom::WarRoom(): isSimulationActive(true), clockTick(0), threatCount(0) {
    for(int i = 0; i < 10; i++){
    	spawnedThreats[i] = nullptr;
	}
}

void WarRoom::loadInfrastructure() {
    cout<<"=== AS-7 WAR ROOM: INITIALIZING INFRASTRUCTURE ==="<<endl;
    // Create No-Fire Zones
    Infrastructure* hospital = new Infrastructure("Jinnah Hospital", "Hospital", Coordinate(50, 0, 0), 20.0);
    Infrastructure* powerPlant = new Infrastructure("Nuclear Plant", "Plant", Coordinate(-50, 0, 0), 30.0);
    
    hq.registerInfrastructure(hospital);
    hq.registerInfrastructure(powerPlant);
}

void WarRoom::initializeDefenseGrid() {
    cout<<"=== AS-7 WAR ROOM: LOADING DRONE ASSETS ==="<<endl;
    
    // Create default battery and sensor profiles
    Battery standardBattery(100.0); // 100% charge, not low power
    SensorArray standardSensors(0.95f, "Active"); // 95% precision
    
    // Load 5 Kamikazes, 2 Snipers, 3 Jammers
    for(int i = 0; i < 15; i++) {
        hq.registerDrone(new KamikazeDrone("KAM-" + to_string(i+1), Coordinate(0,0,0), 100.0, standardBattery, standardSensors));
    }
    for(int i = 0; i < 2; i++) {
        hq.registerDrone(new SniperDrone("SNP-" + to_string(i+1), Coordinate(0,0,0), 0.0, standardBattery, standardSensors));
    }
    for(int i = 0; i < 3; i++) {
        hq.registerDrone(new JammerDrone("JAM-" + to_string(i+1), Coordinate(0,0,0), 40.0, standardBattery, standardSensors)); 
    }
    cout<<"[SYSTEM]: All drones loaded and on standby."<<endl;
}

void WarRoom::spawnThreatWave() {
	TargetProfile highRisk("High-Altitude", 10, 600.0);
    TargetProfile medRisk("Mid-Tier", 5, 250.0);
    TargetProfile lowRisk("Decoy", 2, 50.0);
	
    Threat* missile  = new BallisticMissile("BM-67", Coordinate(40,0,0), highRisk, 10.0);
    Threat* munition = new LoiteringMunition("LM-99", Coordinate(40,0,0), medRisk, 30.0);
    Threat* decoy    = new ElectronicDecoy("ED-01",  Coordinate(50,0,0), lowRisk, 15.0);
    Threat* hunt = new BallisticMissile("HNT-01", Coordinate(50, 0, 0), highRisk, 20.0);

    spawnedThreats[threatCount++] = missile;
    spawnedThreats[threatCount++] = munition;
    spawnedThreats[threatCount++] = decoy;
    spawnedThreats[threatCount++] = hunt;

    hq.handleIncomingThreat(missile);
    hq.handleIncomingThreat(munition);
    hq.handleIncomingThreat(decoy);
    hq.handleIncomingThreat(hunt);
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

WarRoom::~WarRoom() {
    for(int i = 0; i < threatCount; i++){
    	delete spawnedThreats[i];
	}
}

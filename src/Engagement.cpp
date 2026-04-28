#include "Engagement.h"

using namespace std;

// Parameterized Constructor: Called by CommandCentre to initiate defense
Engagement::Engagement(string id, Threat* threat, Interceptor* drones[], int size): engagementID(id), targetThreat(threat), swarmSize(size), isResolved(false) {
    // Linking the specific drone pointers from the CommandCenter to this engagement
    for(int i = 0; i < swarmSize; i++) {
        assignedSwarm[i] = drones[i];
    }
    cout<<"[ENGAGEMENT]: Initialized "<<engagementID<<". Swarm of "<<swarmSize<<" drones assigned to Threat "<<targetThreat->getID()<<endl;
}

// Function to carry out Location Shield logic utilizing Infrastructure class
bool Engagement::isSafeToEngage(Coordinate impactPos, Infrastructure* sites[], int count) const {
    for (int i = 0; i < count; i++) {
        // Calling the Infrastructure class to check its own protection radius
        if (sites[i]->isWithinZone(impactPos)) {
            cout<<"[SHIELD]: DANGER! Impact within No-Fire Zone of "<<sites[i]->getName()<<endl;
            return false; 	// Within No-Fire Zone: not clear for impact
        }
    }
    return true; 	// No infrastructure nearby: clear for impact
}

// Logic for Handover: Replacement function
void Engagement::replaceDrone(int index, Interceptor* newDrone) {
    if (index >= 0 && index < swarmSize) {
        assignedSwarm[index] = newDrone;
    }
}

// Manages the movement of the entire swarm vs the threat
void Engagement::executeTacticalTick(Infrastructure* protectedSites[], int siteCount) {
    if (isResolved) return;     // If threat neutralized (successful impact)
    
    targetThreat->calculateTrajectory();
    for (int i = 0; i < swarmSize; i++) {
        if (assignedSwarm[i]->getStatus()) {
            assignedSwarm[i]->updatePosition();
            assignedSwarm[i]->drainEnergy(25.0);

            // 1. Check if they have met in the sky
            if (checkCollision(*targetThreat, *assignedSwarm[i])) {
                
                // 2. Location Shield check
                // We pass the current impact coordinates to the safety checker
                if (isSafeToEngage(assignedSwarm[i]->getPosition(), protectedSites, siteCount)) {
                    cout<<"[LOCATION SHIELD]: Area Clear. Finalizing Neutralization."<<endl;
                    resolve();
                } 
                else {
                    // Logic for "Nudging" or delaying the strike to protect infrastructure
                    cout<<"[ALERT]: Impact point too close to Infrastructure! Drone "<<assignedSwarm[i]->getID()<<" attempting trajectory nudge."<<endl;
                    
                    // Drone modifies its path slightly to push the threat to a "Green" zone
                    assignedSwarm[i]->receiveMessage(IntelMessage("SHIELD", "REDIRECT_IMPACT", 777));
                }
                return; 
            }
        }
    }
}

void Engagement::resolve() {
    isResolved = true;
    for(int i = 0; i < swarmSize; i++) {
        // If it's a Kamikaze, it's destroyed (isExpendable = true)
        // If it's a Jammer or Sniper, it stays Active (isExpendable = false)
        if (assignedSwarm[i]->isExpendable()) {
            assignedSwarm[i]->setStatus(false); 
            cout<<"[DESTRUCTION]: Drone "<<assignedSwarm[i]->getID()<<" neutralized along with threat."<<endl;
        } else {
            cout<<"[STANDBY]: Drone "<<assignedSwarm[i]->getID()<<" mission successful. Unit remains operational."<<endl;
        }
    }
    cout<<"[ENGAGEMENT]: "<<engagementID<<" RESOLVED."<<endl;
}

// Friend function definition
bool checkCollision(const Threat& target, const Interceptor& drone) {
    double dist = target.getPosition().calculateDistance(drone.getPosition());

    // Match-up 1: Kamikaze vs Ballistic Missile (Requires direct impact)
    if (dist < 20.0) { // Within 5 meters is a "hit" for all types
        return true;
    }
    
    // Match-up 2: Sniper vs Munition (Stays on ground)
    if (drone.getID().find("SNP") != string::npos && dist < 60.0) {
        cout << "[FIRE]: Sniper Drone " << drone.getID() << " eliminated target from distance!" << endl;
        return true;
    }

    // Match-up 3: Jammer vs Decoy (Effective at a distance)
    // If the drone is a Jammer (you can check speed or ID if needed), 
    // it neutralizes the threat if within, say, 50 meters.
    if (drone.getSpeed() < 50.0 && dist < 50.0) { 
        return true; 
    }
    return false;
}

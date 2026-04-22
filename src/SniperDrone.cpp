#include "SniperDrone.h"
using namespace std;

// Parametrized Constructor
SniperDrone::SniperDrone(string id, Coordinate pos, double s): Interceptor(id, pos, s) {}

// Implements behavior for the stationary sniper unit
void SniperDrone::updatePosition() { 
    // This is a stationary unit. Position remains fixed while monitoring its engagement range.
    cout<<"[STATUS]: Sniper Drone "<<unitID<<" maintaining stationary defensive position."<<endl;
}

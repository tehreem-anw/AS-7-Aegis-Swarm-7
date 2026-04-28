#include "JammerDrone.h"
using namespace std;

// Parametrized Constructor
JammerDrone::JammerDrone(string id, Coordinate pos, double s, Battery b, SensorArray sen): Interceptor(id, pos, s, b, sen) {}

bool JammerDrone::isExpendable() const { return false; } // Emits signal, survives

// Implements movement logic for electronic "soft kill" positioning
void JammerDrone::updatePosition() {
    // Note: Jammer units stay within a specific radius of electronic decoys to neutralize signals without physical impact.
    cout<<"[STATUS]: Jammer Drone "<<unitID<<" emitting electronic counter-measures."<<endl;
}

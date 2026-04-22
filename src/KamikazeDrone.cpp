#include "KamikazeDrone.h"
using namespace std;

// Parametrized Constructor
KamikazeDrone::KamikazeDrone(string id, Coordinate pos, double s): Interceptor(id, pos, s) {}

// Implements movement logic specifically for physical interception
void KamikazeDrone::updatePosition() {
    // Note: The specific target coordinates will be passed by the CommandCenter later.
    // This allows the drone to adjust its trajectory for a collision.
    cout<<"[STATUS]: Kamikaze Drone "<<unitID<<" locked on target. Adjusting intercept course."<<endl;
}

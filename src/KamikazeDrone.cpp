#include "KamikazeDrone.h"
#include "IntelMessage.h"
using namespace std;

KamikazeDrone::KamikazeDrone(string id, Coordinate pos, double s, Battery b, SensorArray sen): Interceptor(id, pos, s, b, sen) {}

bool KamikazeDrone::isExpendable() const { return true; } // Crashes, so it dies

void KamikazeDrone::updatePosition() {
    // Actual math: Move forward by (speed * 0.1) every tick
    double nextX = currentPosition.getX() + (speed * 0.1);
    currentPosition.setCoordinates(nextX, currentPosition.getY(), currentPosition.getZ());
    cout<<"[STATUS]: Kamikaze Drone "<<unitID<<" at X: "<<currentPosition.getX()<<" accelerating..."<<endl;
}

void KamikazeDrone::receiveMessage(const IntelMessage& msg) {
    if (msg.getData() == "REDIRECT_IMPACT") {
        // Nudge Logic: Adjust speed and shift coordinates to avoid infrastructure
        speed = speed * 0.8; 
        currentPosition.setCoordinates(currentPosition.getX() + 20, currentPosition.getY() + 20, currentPosition.getZ());
        cout<<"[ALERT]: Drone "<<unitID<<" performing kinetic nudge. New path calculated."<<endl;
    } else {
        Interceptor::receiveMessage(msg);
    }
}

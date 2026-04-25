#include "KamikazeDrone.h"
#include "IntelMessage.h"
using namespace std;

KamikazeDrone::KamikazeDrone(string id, Coordinate pos, double s): Interceptor(id, pos, s) {}

bool KamikazeDrone::isExpendable() const { return true; } // Crashes, so it dies

void KamikazeDrone::updatePosition() {
    // Moves directly toward the high-speed threat coordinates
    cout<<"[STATUS]: Kamikaze Drone "<<unitID<<" accelerating for interception."<<endl;
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

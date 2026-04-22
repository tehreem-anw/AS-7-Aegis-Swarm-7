#include "LoiteringMunition.h"
using namespace std;

// Parametrized Constructor
LoiteringMunition::LoiteringMunition(string id, Coordinate pos, TargetProfile prof, double s): Threat(id, pos, prof, s) {}

void LoiteringMunition::calculateTrajectory() {
    static bool zig = true; 
    
    // Forward movement on x-axis toward origin
    double x = currentPosition.getX() - (speed * 0.05);
    double y;

    // The Zig-Zag logic
    if (zig == true) {
        y = currentPosition.getY() + 10; // Move Up
    } else {
        y = currentPosition.getY() - 10; // Move Down
    }

    // Flip the switch for the next time this function is called
    zig = !zig; 

    // Update the actual position of the threat
    currentPosition = Coordinate(x, y, currentPosition.getZ());
    
    cout<<"[SYSTEM]: Loitering Munition "<<threatID<<" updating zig-zag trajectory."<<endl;
}

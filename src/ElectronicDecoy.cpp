#include "ElectronicDecoy.h"
using namespace std;

// Parametrized Constructor
ElectronicDecoy::ElectronicDecoy(string id, Coordinate pos, TargetProfile prof, double s): Threat(id, pos, prof, s) {}

void ElectronicDecoy::calculateTrajectory() {
    // Moves in a simple straight line
    double x = currentPosition.getX() - (speed * 0.02);
    currentPosition = Coordinate(x, currentPosition.getY(), currentPosition.getZ());
    cout<<"[SYSTEM]: Electronic Decoy "<<threatID<<" updating linear trajectory."<<endl;
}

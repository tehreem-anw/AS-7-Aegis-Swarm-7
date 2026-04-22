#include "BallisticMissile.h"
using namespace std;

// Parametrized Constructor
BallisticMissile::BallisticMissile(string id, Coordinate pos, TargetProfile prof, double s): Threat(id, pos, prof, s) {}

void BallisticMissile::calculateTrajectory() {
    // Moves rapidly towards origin in a parabolic arc: X decreases, Y follows parabolic path
    double x = currentPosition.getX() - (speed * 0.1);
    double y = currentPosition.getY() - (0.5 * 9.8 * 0.1 * 0.1); // Simple gravity effect
    currentPosition = Coordinate(x, y, currentPosition.getZ());
    cout<<"[SYSTEM]: Ballistic Missile "<<threatID<<" updating arc trajectory."<<endl;
}

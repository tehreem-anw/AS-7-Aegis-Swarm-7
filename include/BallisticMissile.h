#pragma once
#include "Threat.h"
using namespace std;

class BallisticMissile: public Threat {
public:
    // Calls the base Threat constructor
    BallisticMissile(string id, Coordinate pos, TargetProfile prof, double s);

    // Implements high-speed arc-based movement
    void calculateTrajectory() override;
};s

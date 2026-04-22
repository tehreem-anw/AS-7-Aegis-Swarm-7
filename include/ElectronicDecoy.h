#pragma once
#include "Threat.h"
using namespace std;

class ElectronicDecoy : public Threat {
public:
    ElectronicDecoy(string id, Coordinate pos, TargetProfile prof, double s);

    // Implements simple straight-line movement
    void calculateTrajectory() override;
};

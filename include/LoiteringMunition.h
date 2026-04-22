#pragma once
#include "Threat.h"
using namespace std;

class LoiteringMunition : public Threat {
public:
    LoiteringMunition(string id, Coordinate pos, TargetProfile prof, double s);

    // Implements low-speed zig-zag movement
    void calculateTrajectory() override;
};

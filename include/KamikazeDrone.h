#pragma once
#include "Interceptor.h"
using namespace std;

// Derived class for high-speed physical interceptor
class KamikazeDrone : public Interceptor {
public:
    // Calls base Interceptor constructor
    KamikazeDrone(string id, Coordinate pos, double s);

    // Overrides updatePosition to implement intercept logic
    void updatePosition() override;

    // Overrides isExpendable to implement destroy logic
    bool isExpendable() const override { return true; } // It crashes, so it dies
};

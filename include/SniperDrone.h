#pragma once
#include "Interceptor.h"
using namespace std;

// Derived class for stationary precision defense
class SniperDrone : public Interceptor {
public:
    // Calls base Interceptor constructor
    SniperDrone(string id, Coordinate pos, double s);

    // Overrides updatePosition; note that this unit is stationary
    void updatePosition() override;
    
    // Overrides isExpendable to implement destroy logic
    bool isExpendable() const override;
};

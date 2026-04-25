#pragma once
#include "Interceptor.h"
using namespace std;

// Derived class for mobile electronic interception
class JammerDrone : public Interceptor {
public:
    // Calls base Interceptor constructor
    JammerDrone(string id, Coordinate pos, double s);

    // Overrides updatePosition to implement jamming proximity logic
    void updatePosition() override;
    
    // Overrides isExpendable to implement destroy logic
    bool isExpendable() const override;
};

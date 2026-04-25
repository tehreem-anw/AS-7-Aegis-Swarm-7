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
    
    // Overrides receiveMessage to implement Location Shield logic
    void receiveMessage(const IntelMessage& msg) override;
    
    // Overrides isExpendable to implement destroy logic
    bool isExpendable() const override;
};

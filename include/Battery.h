#pragma once
#include <iostream>
using namespace std;

class Battery {
private:
    double chargePercentage;
    bool lowPower;

public:
    // Constructors
    Battery();
    Battery(double initialCharge);

    // Member Functions
    void consumePower(double amount);
    void recharge();
    void displayStatus() const;
    bool needsReplacement() const;

    // Getters
    double getCharge() const { return chargePercentage; }
    bool getLowPowerMode() const { return lowPower; }

    // Setters
    void setCharge(double c);
};

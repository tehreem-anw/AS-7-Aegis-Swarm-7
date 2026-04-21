#include "Battery.h"
using namespace std;

// Default Constructor: Starts at 100% capacity
Battery::Battery() : chargePercentage(100.0), lowPower(false) {}

// Parameterized Constructor: Used for simulating mid-flight drones
Battery::Battery(double initialCharge) : chargePercentage(initialCharge) {
    if (chargePercentage < 15.0){
    	lowPower = true;
	}
}

// Decrements charge and updates the low-power flag for the Handover Logic
void Battery::consumePower(double amount) {
    chargePercentage -= amount;
    if(chargePercentage < 0) chargePercentage = 0;
    if(chargePercentage < 15.0) lowPower = true;
}

// Resetting battery status upon return to base
void Battery::recharge() {
    chargePercentage = 100.0;
    lowPower = false;
}

// Log current energy levels for monitoring
void Battery::displayStatus() const {
    cout<<"Battery: "<<chargePercentage<<"% ["<<(lowPower ? "LOW" : "OK")<<"]"<<endl;
}

// Mechanical check used by CommandCenter to decide on replacements
bool Battery::needsReplacement() const {
    return lowPower;
}

void Battery::setCharge(double c) {
    chargePercentage = c;
    if (chargePercentage < 15.0){
    	lowPower = true;
	}
}

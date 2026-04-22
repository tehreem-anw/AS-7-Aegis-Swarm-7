#include "TargetProfile.h"
using namespace std;

// Default Constructor: Unknown low-level profile
TargetProfile::TargetProfile() : targetType("Unknown"), riskLevel(1), heatSignature(0.0) {}

// Parameterized Constructor: Defines the threat profile data
TargetProfile::TargetProfile(string type, int risk, double heat): targetType(type), riskLevel(risk), heatSignature(heat) {}

// Logic to refine risk level based on detected heat/size
void TargetProfile::classifyTarget() {
    if (heatSignature > 500.0) {
        targetType = "High-Speed";
        riskLevel = 10;
    } 
	else if (heatSignature > 100.0) {
        targetType = "Low-Speed";
        riskLevel = 5;
    } 
	else {
        targetType = "Decoy";
        riskLevel = 2;
    }
}

// Logs the threat identity for the Command Center
void TargetProfile::displayProfile() const {
    cout<<"Type: "<<targetType<<" | Risk: "<<riskLevel<<"/10"<<endl;
}

// Overloading (>) to rank which threat needs more drones assigned first
bool TargetProfile::operator > (const TargetProfile& other) const {
    return this->riskLevel > other.riskLevel;
}

// Setters
void TargetProfile::setRisk(int r) {
    if (r >= 1 && r <= 10) {
    	riskLevel = r;
	}
}

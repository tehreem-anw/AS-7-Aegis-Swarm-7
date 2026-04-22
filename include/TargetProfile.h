#pragma once
#include <iostream>
#include <string>
using namespace std;

class TargetProfile {
private:
    string targetType; // High-Speed/Low-Speed/Decoy
    int riskLevel;     // 1-10
    double heatSignature;

public:
    // Constructors
    TargetProfile();
    TargetProfile(string type, int risk, double heat);

    // Member Functions
    void classifyTarget();
    void displayProfile() const;

    // Operator Overloading: Vital for Prioritization logic in CommandCenter
    bool operator > (const TargetProfile& other) const;

    // Getters
    string getTargetType() const { return targetType; }
    int getRiskLevel() const { return riskLevel; }
    double getHeat() const { return heatSignature; }

    // Setters
    void setRisk(int r);
};

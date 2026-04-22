#include "Threat.h"
using namespace std;

// Parametrized Constructor: Initializes identity, physics, and profile
Threat::Threat(string id, Coordinate pos, TargetProfile prof, double s): threatID(id), currentPosition(pos), profile(prof), speed(s) {}

// Displays status details of the threat
void Threat::displayThreatInfo() const {
    cout<<"Threat ID: "<<threatID<<" | Speed: "<<speed<<" m/s"<<endl;
    cout<<"Position: ";
    currentPosition.display();
    cout<<"\nProfile: ";
    profile.displayProfile();
}

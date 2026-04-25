#include "Interceptor.h"
#include "IntelMessage.h"
#include "CommandCenter.h"
using namespace std;

// Parametrized Constructor: Initializes identity, position, and active status
Interceptor::Interceptor(string id, Coordinate pos, double s): unitID(id), currentPosition(pos), speed(s), isActive(true) {}

// Displays status details of the interceptor
void Interceptor::displayInterceptorInfo() const {
    cout<<"Unit ID: "<<unitID<<" | Speed: "<<speed<<" m/s"<<endl;
    cout<<"Status: "<<(isActive ? "Active" : "Inactive")<<endl;
    cout<<"Current Position: ";
    currentPosition.display();
    cout<<endl;
}

// Base implementation: Most drones just log the message
void Interceptor::receiveMessage(const IntelMessage& msg) {
    cout<<"[SYSTEM]: Drone "<<unitID<<" received packet from "<<msg.getSender()<<endl;
}

// Drones can send status updates back to the Command Center
void Interceptor::sendMessage(IntelMessage& msg, CommandCenter& center) {
    cout<<"[COMMS]: Drone "<<unitID<<" transmitting data to Command Center."<<endl;
    center.processIncomingIntel(msg); 	// Logic for the Command Center to handle data
}

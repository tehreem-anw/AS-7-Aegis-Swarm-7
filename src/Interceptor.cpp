#include "Interceptor.h"
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

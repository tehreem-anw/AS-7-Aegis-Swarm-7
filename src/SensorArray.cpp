#include "SensorArray.h"
using namespace std;

// Default Setup: Sensors on with full precision
SensorArray::SensorArray() : precision(1.0), sensorStatus("Optimal"), active(true) {}

// Custom Setup: Useful for simulating damaged or legacy sensors
SensorArray::SensorArray(float p, string status) : precision(p), sensorStatus(status), active(true) {}

// Checks if hardware is functional before engaging a high-speed threat
void SensorArray::performSelfCheck() {
    if(active) {
        cout<<"Sensor Check: "<<sensorStatus<<" at "<<precision * 100<<"% precision."<<endl;
    } else {
        cout<<"Sensor Offline."<<endl;
    }
}

// Used to save power or simulate jamming
void SensorArray::toggleSensor() {
    active = !active;
}

// Summary display for the drone's radar capabilities
void SensorArray::displaySensorInfo() const {
    cout<<"Sensor: "<<sensorStatus<<" | Precision: "<<precision<<endl;
}

void SensorArray::setPrecision(float p) { precision = p; }
void SensorArray::setStatus(string s) { sensorStatus = s; }

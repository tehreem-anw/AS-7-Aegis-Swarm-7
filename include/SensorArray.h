#pragma once
#include <iostream>
#include <string>
using namespace std;

class SensorArray {
private:
    float precision;
    string sensorStatus;
    bool active;

public:
    // Constructors
    SensorArray();
    SensorArray(float p, string status);

    // Member Functions
    void performSelfCheck();
    void toggleSensor();
    void displaySensorInfo() const;

    // Getters
    float getPrecision() const { return precision; }
    string getStatus() const { return sensorStatus; }
    bool isActive() const { return active; }

    // Setters
    void setPrecision(float p);
    void setStatus(string s);
};

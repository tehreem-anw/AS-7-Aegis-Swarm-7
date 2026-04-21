#pragma once
#include <iostream>
#include <cmath>

class Coordinate {
private:
    double x, y, z;

public:
    // Constructors
    Coordinate();
    Coordinate(double x, double y, double z);

    // Member Functions
    double calculateDistance(const Coordinate& other) const;
    void display() const;

    // Operator Overloading (Useful for shifting intercept points)
    Coordinate operator+(const Coordinate& other) const;
    bool operator==(const Coordinate& other) const;
    
    // Getters
    double getX() const { return x; }
    double getY() const { return y; }
    double getZ() const { return z; }

    // Setters
    void setCoordinates(double x, double y, double z);
};

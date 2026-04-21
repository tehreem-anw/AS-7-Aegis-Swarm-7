#include "Coordinate.h"
using namespace std;

// Default Constructor (Origin)
Coordinate::Coordinate() : x(0.0), y(0.0), z(0.0) {}

// Parameterized Constructor
Coordinate::Coordinate(double x, double y, double z) : x(x), y(y), z(z) {}

void Coordinate::setCoordinates(double x, double y, double z) {
    this->x = x;
    this->y = y;
    this->z = z;
}

// Distance Calculation
double Coordinate::calculateDistance(const Coordinate& other) const {
    return sqrt(pow(other.x - this->x, 2) + pow(other.y - this->y, 2) + pow(other.z - this->z, 2));
}

// Coordinate Display
void Coordinate::display() const {
    cout<<"("<<x<<", "<<y<<", "<<z<<")";
}

// Overloading (+) to simplify moving coordinates in a 3D grid
Coordinate Coordinate::operator+(const Coordinate& other) const {
    return Coordinate(this->x + other.x, this->y + other.y, this->z + other.z);
}

// Overloading (==) to check if a drone has reached its target
bool Coordinate::operator == (const Coordinate& other) const {
    return (this->x == other.x && this->y == other.y && this->z == other.z);
}

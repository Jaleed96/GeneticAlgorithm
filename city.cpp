//
// Created by jay on 17/03/19.
//

#include "city.hpp"
#include <sstream>
#include <iostream>

using namespace std;

city::city(std::string name, double xCoord, double yCoord) : name(name) {
    if (xCoord>1000.0 || xCoord<0.0) {
        cerr << "Please make sure X-Coordinate is between 0.0 and 1000.0";
        throw "CoordinateOutOfBoundsException";
    }
    if (yCoord>1000.0 || yCoord<0.0) {
        cerr << "Please make sure Y-Coordinate is between 0.0 and 1000.0";
        throw "CoordinateOutOfBoundsException";
    }
    this->x = xCoord;
    this->y = yCoord;
}

std::string city::getName() const { return this->name; }

double city::getX() const { return this->x; }

double city::getY() const { return this->y; }
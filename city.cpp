//
// Created by jay on 17/03/19.
//

#include "city.hpp"
#include <sstream>

using namespace std;

city::city(std::string name, double xCoord, double yCoord) : name(name), x(xCoord), y(yCoord) {}

std::string city::getName() const { return this->name; }

double city::getX() const { return this->x; }

double city::getY() const { return this->y; }
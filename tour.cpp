//
// Created by jay on 17/03/19.
//

#include "tour.hpp"
#include <sstream>
#include <vector>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

tour::tour(std::vector<city*> listOfCities) : cityTour(listOfCities) {
    fitnessRating = 1/(10*getTourDistance());
}
std::vector<city*> tour::getTour() const { return cityTour; }

double tour::getFitnessRating() const { return fitnessRating; }

double tour::getDistanceBetweenCities(city c1, city c2) const {
    return abs(c1.getX()-c2.getX()) + abs(c1.getY()-c2.getY());
}

double tour::getTourDistance() const {
    double distTravelled = 0.0;
    for (int i = 1; i<cityTour.size(); i++) {
        distTravelled = distTravelled+getDistanceBetweenCities(*(cityTour[i-1]), *(cityTour[i]));
    }
    return distTravelled;
}

bool tour::containsCity(std::string cityName) {
    for (city* c : cityTour) {
        if ((*c).getName() == cityName) {
            return true;
        }
    }
    return false;
}

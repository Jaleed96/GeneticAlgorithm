//
// Created by jay on 17/03/19.
//

#include "tour.hpp"
#include <sstream>
#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

tour::tour(std::vector<city> listOfCities) : cityTour(listOfCities) {
    // TODO: Calculate fitness rating here
    double xTravelled = 0.0, yTravelled = 0.0;
    for (int i = 1; i<cityTour.size(); i++) {
        xTravelled = xTravelled+abs(cityTour[i-1].getX()-cityTour[i].getX());
        yTravelled = yTravelled+abs(cityTour[i-1].getY()-cityTour[i].getY());
    }
    fitnessRating = 1/(10*(xTravelled+yTravelled));
}
std::vector<city> tour::getTour() const { return cityTour; }

double tour::getFitnessRating() const { return fitnessRating; }

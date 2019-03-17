//
// Created by jay on 17/03/19.
//

#include "tour.hpp"
#include <sstream>
#include <vector>
#include <iostream>

using namespace std;

tour::tour(std::vector<city> listOfCities) : cityTour(listOfCities) {
    // TODO: Calculate fitness rating here

}
std::vector<city> tour::getTour() const { return cityTour; }

double tour::getFitnessRating() const { return fitnessRating; }

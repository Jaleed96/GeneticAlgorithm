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

constexpr int MUTATION_RATE = 30;
using namespace std;

tour::tour(std::vector<city*> listOfCities) {
    for (int i = 0; i<listOfCities.size(); i++) {
        cityTour.push_back(listOfCities[i]);
    }
    this->fitnessRating = getTourDistance();
}

tour::tour(std::vector<city*>* listOfCities) {
    cityTour = *(listOfCities);
    this->fitnessRating = getTourDistance();
}
void tour::calculateFitness() {
    this->fitnessRating = getTourDistance();
}
std::vector<city*> tour::getTour() const { return cityTour; }

double tour::getFitnessRating() const { return this->fitnessRating; }

double tour::getDistanceBetweenCities(city* c1, city* c2) const {
    return sqrt(pow(c2->getX()-c1->getX(), 2)+pow(c2->getY()-c1->getY(), 2));
    //return abs(c1->getX()-c2->getX()) + abs(c1->getY()-c2->getY());
}

double tour::getTourDistance() const {
    double distTravelled = 0.0;
    for (int i = 1; i<cityTour.size(); i++) {
        distTravelled = distTravelled+getDistanceBetweenCities(cityTour[i-1], cityTour[i]);
    }
    return distTravelled;
}

bool tour::containsCity(std::string cityName, std::vector<city*>* cities) const {
    for (city* c : *(cities)) {
        if (c->getName() == cityName) {
            return true;
        }
    }
    return false;
}

void tour::mutate() {
    for (int i = 0; i<cityTour.size(); i++) {
        int percent = rand()%100;
        if (percent<MUTATION_RATE) {
            if (i==cityTour.size()-1) {
                swap(cityTour[i], cityTour[0]);
            } else {
                swap(cityTour[i], cityTour[i+1]);
            }
        }
    }
}

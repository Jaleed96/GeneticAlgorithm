//
// Created by jay on 17/03/19.
//

#ifndef GENETICALGORITHM_TOUR_HPP
#define GENETICALGORITHM_TOUR_HPP

#include <sstream>
#include <iostream>
#include <vector>
#include "city.hpp"

class tour {
private:
    std::vector<city*> cityTour;
    double fitnessRating;
public:
    tour(std::vector<city*> listOfCities);

    tour(std::vector<city*>* listOfCities);

    std::vector<city*> getTour() const;

    double getFitnessRating() const;

    void calculateFitness();

    bool containsCity(std::string cityName, std::vector<city*>* cities) const;

    double getDistanceBetweenCities(city* c1, city* c2) const;

    double getTourDistance() const;

    void mutate();

    friend std::ostream& operator<<(std::ostream& output, const tour& m);
};


#endif //GENETICALGORITHM_TOUR_HPP

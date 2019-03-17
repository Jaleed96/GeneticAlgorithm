//
// Created by jay on 17/03/19.
//

#ifndef GENETICALGORITHM_TOUR_HPP
#define GENETICALGORITHM_TOUR_HPP

#include <sstream>
#include <vector>
#include "city.hpp"

class tour {
private:
    std::vector<city> cityTour;
    double fitnessRating;
public:
    tour(std::vector<city> listOfCities);

    std::vector<city> getTour() const;

    double getFitnessRating() const;
};


#endif //GENETICALGORITHM_TOUR_HPP

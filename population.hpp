//
// Created by jay on 17/03/19.
//

#ifndef GENETICALGORITHM_POPULATION_HPP
#define GENETICALGORITHM_POPULATION_HPP

#include "city.hpp"
#include "tour.hpp"
#include <random>
#include <algorithm>
#include <vector>

class population {
private:
    std::vector<tour> listOfTours;
    tour* eliteTour;
public:
    population(std::vector<city> masterList);

    tour* determineElite();

    void crossover();

    std::pair<tour*, tour*> selectParent(int poolSize);

    void shuffleCities(std::vector<city*>& t);

    void mutateTours();

    std::vector<tour> getTours() const;

};


#endif //GENETICALGORITHM_POPULATION_HPP

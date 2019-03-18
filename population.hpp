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

    tour crossover(tour t1, tour t2);

    tour crossover(tour t1, tour t2, tour t3);

    tour selectParent(int poolSize);

    void shuffleCities(tour& t);

};


#endif //GENETICALGORITHM_POPULATION_HPP

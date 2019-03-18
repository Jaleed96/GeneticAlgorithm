//
// Created by jay on 17/03/19.
//

#include "population.hpp"
#include <random>
#include <algorithm>
#include <vector>

using namespace std;

auto generator = default_random_engine {};

population::population(std::vector<city> masterList) {
    vector<city*> ptrToMList;
    for(int i = 0; i<masterList.size(); i++) {
        ptrToMList[i] = &(masterList[i]);
    }
    for(int i =0; i<30; i++) {
        tour t{ptrToMList};
        if(i == 0) {
            listOfTours.push_back(t);
        } else {
            shuffleCities(t);
            listOfTours.push_back(t);
        }
    }
}

void population::shuffleCities(tour& t) {
    shuffle(t.getTour().begin(), t.getTour().end(), generator);
}
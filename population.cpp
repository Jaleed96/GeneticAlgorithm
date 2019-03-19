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
        ptrToMList.push_back(&(masterList[i]));
    }
    for(int i =0; i<3; i++) {

        if(i == 0) {
            tour t{ptrToMList};
            listOfTours.push_back(t);
        } else {
            shuffleCities(ptrToMList);
            tour t{ptrToMList};
            listOfTours.push_back(t);
        }
    }
}

void population::shuffleCities(vector<city*>& t) {
    shuffle(t.begin(), t.end(), generator);
}

tour* population::determineElite() {
    tour* elite = &(listOfTours[0]);
    for (int i = 1; i<listOfTours.size(); i++) {
        if ((*elite).getFitnessRating()>listOfTours[i].getFitnessRating()) {
            elite = &listOfTours[i];
        }
    }
    eliteTour = elite;
    return elite;
}
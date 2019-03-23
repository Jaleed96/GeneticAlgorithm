//
// Created by jay on 17/03/19.
//
constexpr int PARENT_POOL_SIZE = 5;
constexpr int CITIES_IN_TOUR = 32;
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
    for(int i =0; i<CITIES_IN_TOUR; i++) {

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

    tour temp = listOfTours[0];
    listOfTours[0] = *elite;
    *elite = temp;
    eliteTour = &(listOfTours[0]);

    return eliteTour;
}

pair<tour, tour> population::selectParent(int poolSize) {
    vector<tour> parentPool;
    srand((int) time(0));
    for (int i = 0; i<PARENT_POOL_SIZE; i++) {
        int index = rand()%29;
        parentPool.push_back(listOfTours[index]);
    }
    tour parent1 = parentPool[0];
    for (int i = 1; i<parentPool.size(); i++) {
        if (parentPool[i].getFitnessRating()<parent1.getFitnessRating()) {
            parent1 = parentPool[i];
        }
    }
    parentPool.clear();
    for (int i = 0; i<PARENT_POOL_SIZE; i++) {
        int index = rand()%29;
        parentPool.push_back(listOfTours[index]);
    }
    tour parent2 = parentPool[0];
    for (int i = 1; i<parentPool.size(); i++) {
        if (parentPool[i].getFitnessRating()<parent2.getFitnessRating()) {
            parent2 = parentPool[i];
        }
    }
    pair<tour, tour> p (parent1, parent2);
    return p;
}

tour population::crossover(tour t1, tour t2) {
    int index = rand()%CITIES_IN_TOUR;
    vector<city*> newList;
    for (int i = 0; i<index; i++) {
        newList.push_back(t1.getTour()[i]);
    }
    for (int i = 0, citiesAdded=0; i<t2.getTour().size()&&citiesAdded<CITIES_IN_TOUR-index; i++) {
        if (find(newList.begin(), newList.end(), t2.getTour()[i]) != newList.end()) {
            newList.push_back(t2.getTour()[i]);
            citiesAdded++;
        }
    }
    tour t{newList};
    return t;
}

std::vector<tour> population::getTours() const {
    return this->listOfTours;
}

void population::mutateTours() {
    for (int i = 1; i<listOfTours.size(); i++) {
        listOfTours[i].mutate();
        listOfTours[i].calculateFitness();
    }
}
#include <iostream>

#include "tour.hpp"
#include "population.hpp"
#include <sstream>
#include <vector>
#include "city.hpp"
#include <cmath>

using namespace std;

int main() {
    vector<city> list;
    city london{"Manchester", 0.0, 120.0};
    city manchester{"London", 20.0, 180.0};
    city liverpool{"Liverpool", 10.0, 60.0};
    list.push_back(london);
    list.push_back(liverpool);
    list.push_back(manchester);

    population basicTour{list};
    cout<<(basicTour.determineElite())->getFitnessRating()<<endl;
//    if (basicTour.containsCity("London")) {
//        cout<<basicTour.getFitnessRating()<<endl;
//    } else cout<<"no"<<endl;

    return 0;
}
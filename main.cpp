#include <iostream>

#include "tour.hpp"
#include <sstream>
#include <vector>
#include "city.hpp"
#include <cmath>

using namespace std;

int main() {
    vector<city> list;
    city london{"London", 0.0, 120.0};
    city manchester{"London", 20.0, 180.0};
    city liverpool{"London", 10.0, 60.0};
    list.push_back(london);
    list.push_back(manchester);
    list.push_back(liverpool);

    tour basicTour{list};
    cout<<basicTour.getFitnessRating()<<endl;

    return 0;
}
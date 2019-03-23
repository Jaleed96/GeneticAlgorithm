#include <iostream>

#include "tour.hpp"
#include "population.hpp"
#include <sstream>
#include <vector>
#include "city.hpp"
#include <cmath>
#include <iostream>

using namespace std;
constexpr int IMPROVEMENT_FACTOR = 30;
constexpr int ITERATIONS = 1000;

int main() {
    vector<string> cityNames {"Violetlight", "Linbourne", "Prybush", "Wyverntown", "Newcrest", "Redrose", "Deepway", "Fieldmont", "Moorley", "Fogbeach", "Westermarble", "Icemoor", "Waynesse", "Snowley", "Grassshore", "Winterview", "Coldgate", "Coldloch", "Raywyn", "Westermeadow", "Starrywinter", "Eriwick", "Lightston", "Dorwall", "Crystalham", "Icewheat", "Aldmarble", "Marblemont", "Stoneelf", "Starryhollow", "Cordale", "Crystalmallow"};
    vector<city> list;
    srand((int) time(0));

    for (int i = 0; i <cityNames.size(); i++) {
        int x = rand()%1000;
        int y = rand()%1000;
        city temp{cityNames[i], x, y};
        list.push_back(temp);
    }

    population middleEarth{list};


//    population basicPop{list};
//    cout<<(basicPop.determineElite())->getFitnessRating()<<endl;
//    pair <tour, tour> p = basicPop.selectParent(6);
//    cout<<basicPop.crossover(p.first, p.second).getFitnessRating()<<endl;
//    cout<<basicPop.getTours()[1].getFitnessRating()<<endl;
//    basicPop.mutateTours();
//    cout<<basicPop.getTours()[1].getFitnessRating()<<endl;
    return 0;
}
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
    tour* elite = middleEarth.determineElite();
    double baseRating = elite->getFitnessRating();
    tour baseTour = elite->getTour();
    int iterationsRan = 0;
    string improvementAchieved;

    while (100.0-(100*elite->getFitnessRating()/baseRating) < IMPROVEMENT_FACTOR && iterationsRan<ITERATIONS) {
        elite = middleEarth.determineElite();
        improvementAchieved = 100.0-(100*elite->getFitnessRating()/baseRating) < IMPROVEMENT_FACTOR ? "no" : "yes";
        middleEarth.crossover();
        middleEarth.mutateTours();
        cout<<"Iteration: "<<iterationsRan<<"; Base Distance: "<<baseRating<< "; Current Elite Distance: ";
        cout<<elite->getFitnessRating()<<"; Improvement Achieved: "<<improvementAchieved<< "; Improvement: "<<100.0-(100*elite->getFitnessRating()/baseRating)<<"%"<<endl;
        iterationsRan++;
    }

    cout<<"==============RESULTS==============="<<endl;
    cout<<"Number of iterations ran: "<<iterationsRan<<endl;
    cout<<"Base distance: "<< baseRating<<"; Best distance: "<<elite->getFitnessRating()<<endl;
    cout<<"Improvement achieved: "<<improvementAchieved<<endl;
    cout<<"Base tour: "<<baseTour<<endl;
    cout<<"Elite tour: "<<*elite<<endl;

    return 0;
}
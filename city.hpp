//
// Created by jay on 17/03/19.
//

#ifndef GENETICALGORITHM_CITY_HPP
#define GENETICALGORITHM_CITY_HPP

#include <sstream>

class city {
private:
    std::string name;
    double x;
    double y;
public:
    city(std::string name, double xCoord, double yCoord);

    std::string getName() const;

    double getX() const;

    double getY() const;

};


#endif //GENETICALGORITHM_CITY_HPP

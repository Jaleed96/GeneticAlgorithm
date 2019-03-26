//
// Created by jay on 17/03/19.
//

#ifndef GENETICALGORITHM_CITY_HPP
#define GENETICALGORITHM_CITY_HPP

#include <sstream>

class city {
private:
    std::string name;
    int x;
    int y;
public:
    city(std::string& name, int xCoord, int yCoord);

    std::string getName() const;

    int getX() const;

    int getY() const;

};


#endif //GENETICALGORITHM_CITY_HPP

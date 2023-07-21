#ifndef FORTUNE_ALGORITM_H
#define FORTUNE_ALGORITM_H

#include <iostream>
#include <vector>
#include "voronoi.hpp"

class FortuneAlgorithm
{
private:

    Voronoi mDiagram;


public:

    Voronoi getDiagram();
    FortuneAlgorithm(std::vector<Voronoi::cartesian_coordinates> points);
    ~FortuneAlgorithm();  

    void initialize();

};

#endif // FORTUNE_ALGORITM_H
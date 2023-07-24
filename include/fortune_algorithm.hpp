#ifndef FORTUNE_ALGORITM_H
#define FORTUNE_ALGORITM_H

#include <iostream>
#include <vector>
#include "voronoi.hpp"
#include "event.hpp"

class FortuneAlgorithm
{
private:

    Voronoi mDiagram;

    // Create the eventVector using the wrapper for Event class
    EventVectorWrapper<Event> priorty_vector;
public:

    Voronoi getDiagram();
    FortuneAlgorithm(std::vector<Voronoi::cartesian_coordinates> points);
    ~FortuneAlgorithm();  

    void handleSiteEvent(Event* event);
    void initialize();

};

#endif // FORTUNE_ALGORITM_H
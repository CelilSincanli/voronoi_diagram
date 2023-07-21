#include "fortune_algorithm.hpp"

FortuneAlgorithm::FortuneAlgorithm(std::vector<Voronoi::cartesian_coordinates> points) : mDiagram(std::move(points))
{

}

FortuneAlgorithm::~FortuneAlgorithm() = default;

void FortuneAlgorithm::initialize()
{
    // Initialize event queue
    for (std::size_t i = 0; i < mDiagram.getNbSites(); ++i)
        mEvents.push(std::make_unique<Event>(mDiagram.getSite(i)));

}
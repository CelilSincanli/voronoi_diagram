#include "fortune_algorithm.hpp"

FortuneAlgorithm::FortuneAlgorithm(std::vector<Voronoi::cartesian_coordinates> points) : mDiagram(std::move(points))
{

}

FortuneAlgorithm::~FortuneAlgorithm() = default;

void FortuneAlgorithm::initialize()
{
    // Initialize event queue
    for (std::size_t i = 0; i < mDiagram.getNbSites(); ++i)
        priorty_vector.elements.push_back(std::make_unique<Event>(mDiagram.getSite(i)));

        // Process events
    while (!priorty_vector.elements.empty())
    {
        std::unique_ptr<Event> event = std::move(priorty_vector.elements.back());
        priorty_vector.elements.pop_back();
        if(event->type == Event::Type::SITE)
            //TODO handle site event
            ;

            
        else 
            //TODO handle circle event
            ;
    }
}

void FortuneAlgorithm::handleSiteEvent(Event* event)
{
    Voronoi::Site* site = event->site;
    // 1. Check if the bachline is empty
    if (mBeachline.isEmpty())
    {
        mBeachline.setRoot(mBeachline.createArc(site));
        return;
    }
}
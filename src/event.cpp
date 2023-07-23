#include "event.hpp"

Event::Event(Voronoi::Site* site) : type(Type::SITE), y(site->point.y), index(-1), site(site)
{

}

void Event::Process() {
    std::cout << "Event with ID " << mId << " processed. Value: " << mValue << std::endl;
}
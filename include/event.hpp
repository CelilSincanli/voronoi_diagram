#ifndef EVENT_H
#define EVENT_H

#include <iostream>
#include <memory>
#include <queue>
#include "voronoi.hpp"

// Wrapper class for the vector of unique pointers
template <typename T>
class EventVectorWrapper {
    
// private:
    
public:
    std::vector<std::unique_ptr<T>> elements;
};

// Event class
class Event {
public:

    enum class Type{SITE, CIRCLE};

    Event(Voronoi::Site* site);
    
    void Process();

    const Type type;
    double y;
    int index;
    // Site event
    Voronoi::Site* site;

private:
    int mId;
    double mValue;

};

#endif // EVENT_H
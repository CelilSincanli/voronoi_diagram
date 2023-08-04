#ifndef BEACHLINE_H
#define BEACHLINE_H

#include "voronoi.hpp"
#include "event.hpp"

struct Arc
{
    enum class Color{RED, BLACK};

    // Hierarchy
    Arc* parent;
    Arc* left;
    Arc* right;
    // Diagram
    Voronoi::Site* site;
    Voronoi::HalfEdge* leftHalfEdge;
    Voronoi::HalfEdge* rightHalfEdge;
    Event* event;
    // Optimizations
    Arc* prev;
    Arc* next;
    // Only for balancing
    Color color;
};

class Beachline
{
public:
    Beachline();
    ~Beachline();

    // Remove copy and move operations
    Beachline(const Beachline&) = delete;
    Beachline& operator=(const Beachline&) = delete;
    Beachline(Beachline&&) = delete;
    Beachline& operator=(Beachline&&) = delete;

    Arc* createArc(Voronoi::Site* site);

    bool isEmpty() const;
    bool isNil(const Arc* x) const;
    void setRoot(Arc* x);
    Arc* getLeftmostArc() const;

    Arc* locateArcAbove(const Voronoi::cartesian_coordinates& point, double l) const;
    void insertBefore(Arc* x, Arc* y);
    void insertAfter(Arc* x, Arc* y);
    void replace(Arc* x, Arc* y);
    void remove(Arc* z);

    std::ostream& print(std::ostream& os) const;

private:
    Arc* mNil;
    Arc* mRoot;
};

#endif // BEACHLINE_H
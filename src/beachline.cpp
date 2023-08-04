#include "beachline.hpp"

// STL
#include <limits>
#include <cmath>

Beachline::Beachline() : mNil(new Arc), mRoot(mNil)
{
    // mNil->color = Arc::Color::BLACK; 
}

Beachline::~Beachline()
{
    // free(mRoot);    
    // delete mNil;
}

Arc* Beachline::createArc(Voronoi::Site* site)
{
    return new Arc{mNil, mNil, mNil, site, nullptr, nullptr, nullptr, mNil, mNil, Arc::Color::RED};
}

bool Beachline::isEmpty() const
{
    return isNil(mRoot);
}

bool Beachline::isNil(const Arc* x) const
{
    return x == mNil;
}

void Beachline::setRoot(Arc* x)
{
    mRoot = x;
    mRoot->color = Arc::Color::BLACK;
}

Arc* Beachline::getLeftmostArc() const
{
    Arc* x = mRoot;
    while (!isNil(x->prev))
        x = x->prev;
    return x;
}
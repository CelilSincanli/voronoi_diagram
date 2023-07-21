#include "voronoi.hpp"
#include "fortune_algorithm.hpp"

Voronoi::Voronoi(const std::vector<cartesian_coordinates>& points)
{
    mSites.reserve(points.size());
    mFaces.reserve(points.size());

    for(std::size_t point_index = 0; point_index < points.size(); ++point_index)
    {
        mSites.push_back(Voronoi::Site{point_index, points[point_index], nullptr});
        mFaces.push_back(Voronoi::Face{&mSites.back(), nullptr});
        mSites.back().face = &mFaces.back();
    }
}

Voronoi::~Voronoi()
{

}

Voronoi::Site* Voronoi::getSite(std::size_t index)
{
    return &mSites[index];
}

std::size_t Voronoi::getNbSites() const
{
    return mSites.size();
}

Voronoi::Face* Voronoi::getFace(std::size_t index)
{
    return &mFaces[index];
}

const std::list<Voronoi::Vertex>& Voronoi::getVertices() const
{
    return mVertices;
}

const std::list<Voronoi::HalfEdge>& Voronoi::getHalfEdges() const
{
    return mHalfEdges;
}
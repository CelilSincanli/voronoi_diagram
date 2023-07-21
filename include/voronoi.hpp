#ifndef VORONOI_H
#define VORONOI_H

#include <iostream>
#include <vector>
#include <list>

class Voronoi
{
public:

    struct cartesian_coordinates
    {
        double x;
        double y;
        cartesian_coordinates(double a, double b) { this->x = a; this->y = b; }
    };

    struct HalfEdge;
    struct Face;

    struct Site
    {
        std::size_t index;
        cartesian_coordinates point;
        Face* face;
    };

    struct Vertex
    {
        cartesian_coordinates point;

    private:
        friend Voronoi;
        std::list<Vertex>::iterator it;
    };

    struct HalfEdge
    {
        Vertex* origin = nullptr;
        Vertex* destination = nullptr;
        HalfEdge* twin = nullptr;
        Face* incidentFace;
        HalfEdge* prev = nullptr;
        HalfEdge* next = nullptr;

    private:
        friend Voronoi;
        std::list<HalfEdge>::iterator it;
    };

    struct Face
    {
        Site* site;
        HalfEdge* outerComponent;
    };


    Site* getSite(std::size_t index);
    std::size_t getNbSites() const;    
    Face* getFace(std::size_t index);
    const std::list<Voronoi::Vertex>& getVertices() const;
    const std::list<Voronoi::HalfEdge>& getHalfEdges() const;

    Voronoi(const std::vector<cartesian_coordinates>& points);
    ~Voronoi();

private:
    
    std::vector<Site> mSites;
    std::vector<Face> mFaces;
    std::list<Vertex> mVertices;
    std::list<HalfEdge> mHalfEdges;


};

#endif // VORONOI_H
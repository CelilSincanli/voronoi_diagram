#include <iostream>
#include "voronoi.hpp"

int main()
{
    //init visualization
    Voronoi voronoi;
    
    while (voronoi.is_window_open())
    {
        //Update
        voronoi.update();
        
        //Render
        voronoi.render();
        

    }
    
    return 0;
}
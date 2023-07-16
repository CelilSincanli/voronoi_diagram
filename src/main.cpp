#include "voronoi.hpp"

int main()
{
    //Init srand
    std::srand(static_cast<unsigned>(time(NULL)));

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
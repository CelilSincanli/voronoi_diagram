#include "voronoi.hpp"

int main()
{
    //Init srand
    std::srand(static_cast<unsigned>(time(NULL)));

    std::size_t number_of_points = 100;

    //init visualization
    Voronoi voronoi(number_of_points);
    
    while (voronoi.is_window_open())
    {
        //Update
        voronoi.update();
        
        //Render
        voronoi.render();
        

    }
    
    return 0;
}
#include "diagram.hpp"

int main()
{
    //Init srand
    std::srand(static_cast<unsigned>(time(NULL)));

    std::size_t number_of_points = 100;

    //init visualization
    Diagram voronoi_diagram(number_of_points);
    
    while (voronoi_diagram.is_window_open())
    {
        //Update
        voronoi_diagram.update();
        
        //Render
        voronoi_diagram.render();
        

    }
    
    return 0;
}
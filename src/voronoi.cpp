#include "voronoi.hpp"



// Constructor
Voronoi::Voronoi(/* args */)
{
    this->init_variables();
    this->init_window();
    this->init_points();
}

// Deconstructor
Voronoi::~Voronoi()
{
    delete this->window;
}

// Accessors
const bool Voronoi::is_window_open() const
{
    return this->window->isOpen();
}

// Functions
void Voronoi::update()
{
    this->poll_events();

    this->update_mouse_positions();

    this->update_points();
}

void Voronoi::render()
{
    /*
        @return void

        - clear old frame
        - render diagram
        - display frame in window

        Renders the voronoi diagram
    */
   
    this->window->clear();

    // Draw diagram 
    this->render_points();
    
    this->window->display();
}

void Voronoi::init_variables()
{
    this->window = nullptr;

    // logic
    this->point_counter = 0;
    this->point_spawn_timer_max = 1000.f;
    this->point_spawn_timer = this->point_spawn_timer_max;
    this->max_points = 5;

}

void Voronoi::init_window()
{
    this->video_mode.height = 640;
    this->video_mode.width = 800;

    this->window = new sf::RenderWindow(this->video_mode, "Voronoi Diagram", sf::Style::Titlebar | sf::Style::Close);

    this->window->setFramerateLimit(80);
}

void Voronoi::init_points()
{
    this->point.setPosition(0.f, 0.f);
    this->point.setRadius(3.f);
    this->point.setFillColor(sf::Color::Cyan);
    this->point.setOutlineColor(sf::Color::Green);
    this->point.setOutlineThickness(2.f);


}

void Voronoi::spawn_points()
{
    /*
        @return void

        Spawns points and sets their colors and positions.
        -Sets a random position.
        -Sets arandom color.
        -Adds enemy to the vector.
    */

   this->point.setPosition(
        static_cast<float>(rand() % static_cast<int>(this->window->getSize().x - this->point.getRadius())),
        static_cast<float>(rand() % static_cast<int>(this->window->getSize().y - this->point.getRadius()))
   );

    this->point.setFillColor(sf::Color::Green);

    //Spawn the point
    this->points.push_back(this->point);
}

void Voronoi::poll_events()
{
    while (this->window->pollEvent(this->ev))
    {
       switch (this->ev.type)
       {
       case sf::Event::Closed:
            this->window->close();
        break;
        case sf::Event::KeyPressed:
            if (this->ev.key.code == sf::Keyboard::Q)
            {
                this->window->close();
            } 
        break;
       default:
        break;
       }
    }
    
}

void Voronoi::update_mouse_positions()
{
   /*
        @return void

        Updates the mouse positions:
        - Mouse position relative to window (Vector2i)
   */ 
    
    this->mouse_position_window = sf::Mouse::getPosition(*this->window);
}

void Voronoi::update_points()
{
    /*
        @return void

        Updates the point spawn timer and spawns points
        when the tota; amount of points is smaller than 
        the maximum.
        Removes the points at the edge of the screen.
    */
    // updating the timer for point spwaning
    if (this->points.size() < this->max_points)
    {
        if (this->point_spawn_timer >= this->point_spawn_timer_max)
        {
            this->spawn_points();
            this->point_spawn_timer = 0.f;
        }
        else
        {
            this->point_spawn_timer += 1.f;
        }
    }
    

    //Move the points
    // for (auto &e : this->points)
    // {
    //     e.move(0.f, 1.f);
    // }
    
}

void Voronoi::render_points()
{
    //Rendering all the points
    for (auto &e : this->points)
    {
        this->window->draw(e);
    }
}

#include "voronoi.hpp"



// Constructor
Voronoi::Voronoi(const std::size_t points_size)
{
    this->init_variables(points_size);
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

void Voronoi::init_variables(const std::size_t points_size)
{
    this->window = nullptr;

    // logic
    this->point_counter = 0;
    this->point_spawn_timer_max = 1000.f;
    this->point_spawn_timer = this->point_spawn_timer_max;
    this->max_points = static_cast<int>(points_size);

}

void Voronoi::init_window()
{
    
    this->video_mode.height = 640;
    this->video_mode.width = 800;

    this->window = new sf::RenderWindow(this->video_mode, "Voronoi Diagram", sf::Style::Titlebar | sf::Style::Close);
    
    this->icon.loadFromFile("/home/celil/Pictures/voronoi_2.png");
    this->window->setIcon(128, 128, this->icon.getPixelsPtr());
    
    this->window->setFramerateLimit(60);
}

void Voronoi::init_points()
{
    this->point.setPosition(0.f, 0.f);
    this->point.setRadius(2.f);
    this->point.setFillColor(sf::Color::Cyan);
    this->point.setOutlineColor(sf::Color::Green);
    this->point.setOutlineThickness(1.f);


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

    //Spawn the point
    for (size_t i = 0; i < this->max_points; i++)
    {
        this->point.setPosition(
            static_cast<float>(rand() % static_cast<int>(this->window->getSize().x - this->point.getRadius())),
            static_cast<float>(rand() % static_cast<int>(this->window->getSize().y - this->point.getRadius()))
        );

        // std::cout <<  "getPosition_x: " << this->point.getPosition().x << " windowPosition_x: " << static_cast<int>(this->window->getSize().x) << std::endl;
        // std::cout << "getPosition_y: " << this->point.getPosition().y << " windowPosition_y: " << static_cast<int>(this->window->getSize().y) << std::endl;
        // std::cout << "---------------------"<< std::endl;

        this->point.setFillColor(sf::Color::Green);

        this->points.push_back(this->point);

        this->voronoi_point.x = this->point.getPosition().x;
        this->voronoi_point.y = this->point.getPosition().y;

        this->voronoi_point_vec.push_back(this->voronoi_point);
    }
    
    // this->points.push_back(this->point);
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

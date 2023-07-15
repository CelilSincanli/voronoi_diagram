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
    this->window->draw(this->points);
    
    this->window->display();
}

void Voronoi::init_variables()
{
    this->window = nullptr;
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
    this->points.setPosition(10.f, 10.f);
    this->points.setRadius(3.f);
    this->points.setFillColor(sf::Color::Cyan);
    this->points.setOutlineColor(sf::Color::Green);
    this->points.setOutlineThickness(2.f);
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
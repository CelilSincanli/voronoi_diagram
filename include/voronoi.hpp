#ifndef VORONOI_H
#define VORONOI_H

#include <iostream>
#include <vector>
#include <ctime>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <SFML/Network.hpp>

/*

    Class that acts as the voronoi diagram 	rendering
*/
class Voronoi
{
private:
    
    sf::RenderWindow* window;
    sf::VideoMode video_mode;
    sf::Event ev;

    //Mouse positions
    sf::Vector2i mouse_position_window;

    // logic
    int point_counter;
    float point_spawn_timer;
    float point_spawn_timer_max;
    int max_points;

    // Voronoi Diagram points
    std::vector<sf::CircleShape> points;
    sf::CircleShape point;

    //Private functions
    void init_variables();
    void init_window();
    void init_points();
    
    
public:
    //Constructors / Destructors
    Voronoi(/* args */);
    ~Voronoi();

    //Accessors
    const bool is_window_open() const;
    
    //Fucntions
    void spawn_points();

    void poll_events();
    void update_mouse_positions();
    void update_points();
    void update();
    
    void render_points();
    void render();

    

};

#endif // VORONOI_H
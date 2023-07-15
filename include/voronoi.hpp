#ifndef VORONOI_H
#define VORONOI_H

#include <iostream>

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

    // Voronoi Diagram points
    sf::CircleShape points;
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
    void poll_events();
    void update();
    void render();

};

#endif // VORONOI_H
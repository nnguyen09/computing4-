#pragma once 
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <string>

class CelestialBody:public sf::Drawable{
private:
    double xpos, ypos, xvel, yvel, mass;
    std::string imageFile;
    sf::Texture texture;
    sf::Sprite sprite; 
    sf::Image image;
    
public:
    //constructor destructor
    CelestialBody();
    CelestialBody(double newXpos, double newYpos, double newXvel, double newYvel, double newMass, std::string file);
    ~CelestialBody();
    //funtion 
    friend std::istream& operator >> (std::istream& in, CelestialBody& body);
    //virtual draw function
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    void distance (double radius, int windowx, int windowy);
    void setImg(std::string image_i);
    
};

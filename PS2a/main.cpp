#include <iostream>
#include <vector>
#include "Body.h"
using namespace std;

int main(int argc, char* argggv[]){
    sf::Image background;
    sf::Event ev;

    if(!background.loadFromFile("./nbody/starfield.jpg"))   return -1;
    sf::Vector2u size = background.getSize();
    sf::RenderWindow window(sf::VideoMode(size.x,size.y), "The Solar System!");
    window.setFramerateLimit(1);

    sf::Texture texture;
    texture.loadFromImage(background);

    sf::Sprite sprite;
    sprite.setTexture(texture);

    int numOfPlanets = 0;
    double radius = 0.0;

    std::cin>>numOfPlanets;
    std::cin>>radius;

    vector <CelestialBody*> planet;
    for(int i = 0; i<numOfPlanets; i++ ){
        planet.push_back(new CelestialBody);
        cin>>*planet[i];
    }
    
    while (window.isOpen()){
        while(window.pollEvent(ev)){
            if(ev.type==sf::Event::Closed)  window.close();
            if (ev.type ==sf::Event::KeyPressed && ev.key.code == sf::Keyboard::Escape)   window.close();
        }
        window.clear();
        window.draw(sprite);

        for(int i = 0; i<numOfPlanets; i++){
            (*planet[i]).distance(radius, size.x/2, size.y/2);
            window.draw(*planet[i]);
        }
        window.display();
    }
    return 0;
}
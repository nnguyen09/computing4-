#include "Body.h"

//constructor destructor
CelestialBody::CelestialBody(){}
CelestialBody::CelestialBody(double newXpos, double newYpos, double newXvel, double newYvel, double newMass, std::string file){}
CelestialBody::~CelestialBody(){}

//funtion 
std::istream& operator >> (std::istream& in, CelestialBody& body){
    in>>body.xpos>>body.ypos>>body.xvel>>body.yvel>>body.mass>>body.imageFile;
    body.texture.loadFromFile(body.imageFile);
    body.sprite.setTexture(body.texture);
    return in;
}

void CelestialBody::draw(sf::RenderTarget& target, sf::RenderStates states) const{
    target.draw(sprite, states);
}

void CelestialBody::distance (double radius, int windowx, int windowy){
    sf::Vector2u size = image.getSize();

    int x,y, xpixel, ypixel, xPosition, yPosition;
    x=windowx-size.x/2;
    y=windowy - size.y/2;
    xpixel = xpos / radius * windowx;
    ypixel = ypos/ radius *windowy;
    xPosition = x+xpixel;
    yPosition = y+ypixel;
    sprite.setPosition(xPosition, yPosition);
}
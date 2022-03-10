#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "FibLFSR.h"

// transforms image using FibLFSR
sf::Image transform(sf::Image& image, FibLFSR* fiblfsr){
    // p is a pixel
	sf::Color p;
    sf::Vector2u size = image.getSize();

    // create photographic negative image
	for (unsigned x = 0; x<size.x; x++) {
		for (unsigned y = 0; y< size.y; y++) {
			p = image.getPixel(x, y);
			p.r ^= fiblfsr->generate(8);
			p.g ^= fiblfsr->generate(8);
			p.b ^= fiblfsr->generate(8);
			image.setPixel(x, y, p);
		}
	}
    return image;

}

// display an encrypted copy of the picture, using the LFSR
// to do the encryption
int main(int argc, char* argv[]){
    sf::Image image;
    sf::Image output;
    sf::Color p;

    std::string input_image = argv[1];
    std::string output_image = argv[2];
    std::string seed = argv[3];
  

    FibLFSR fiblfsr (seed);


	if (!image.loadFromFile(input_image))
		return -1;
    
    sf::Vector2u size = image.getSize();

    
    //original image
	sf::RenderWindow window1(sf::VideoMode(size.x, size.y), "OG");
    //transfrom image 
    sf::RenderWindow window2(sf::VideoMode(size.x, size.y), "FibLFSR");

	sf::Texture texture1;
	texture1.loadFromImage(image);

        transform(image, &fiblfsr);

        sf::Texture texture2;
	texture2.loadFromImage(image);

	sf::Sprite sprite1;
	sprite1.setTexture(texture1);
    sf::Sprite sprite2;
	sprite2.setTexture(texture2);

	while (window1.isOpen()&&window2.isOpen())
	{
		sf::Event event;
		while (window1.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window1.close();
		}
        while (window2.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window2.close();
		}

		window1.clear();
		window1.draw(sprite1);
		window1.display();
        window2.clear();
		window2.draw(sprite2);
		window2.display();
	}

	// fredm: saving a PNG segfaults for me, though it does properly
	//   write the file
	if (!output.saveToFile(output_image))
		return -1;

	return 0;
}
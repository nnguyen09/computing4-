
#include <SFML/Graphics.hpp>

int main(){

    //sprite movement speed
    float spriteSpeed = 0.3;

	//Create the main window 
	sf::RenderWindow window(sf::VideoMode(800,600),"SFML window");

    //set frame limit so that the window doesn't run too fast 
        //clear screen
            // window.setFramerateLimit(.999999999);

	//Load a sprite to display
	sf::Texture texture;
	if(!texture.loadFromFile("sprite.png"))
		return EXIT_FAILURE;
	sf::Sprite sprite(texture);

	while (window.isOpen()){

		//process event 
		sf::Event event;
		while(window.pollEvent(event)){
			//close window: exit 
			if (event.type == sf::Event::Closed)
				window.close();
            if (event.type ==sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
                window.close();
		}

		window.clear();

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
            sprite.move(0,-spriteSpeed);
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
            sprite.move(0,spriteSpeed);
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
            sprite.move(-spriteSpeed,0);
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            sprite.move(spriteSpeed,0);


		//draw the sprite 
		window.draw(sprite);

		//display window
		window.display();
	}
	return EXIT_SUCCESS;

}
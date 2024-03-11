#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "FibLFSR.hpp"

void transform(sf::Image&, FibLFSR*);

int main(int argc, const char* argv[])
{
	// Check to see if it is has three command line arguments and only three, less or more doesn't make sense.
	if (argc > 1 && argc < 5)
	{
		sf::Image image;

		// Load argument from argv[1] which holds the input file image
		if (!image.loadFromFile(argv[1]))
			return -1;

		// Load arugment from argv[3] which holds the seed
		FibLFSR seed(argv[3]);

		sf::Vector2u size = image.getSize();

		// One window showing before encryption and other show after encryption.
		sf::RenderWindow window1(sf::VideoMode(size.x, size.y), "Before");
		sf::RenderWindow window2(sf::VideoMode(size.x, size.y), "After");

		sf::Texture texture1;

		texture1.loadFromImage(image);

		sf::Sprite sprite1;

		sprite1.setTexture(texture1);

		// Call transform here so the first window doesn't get the encryption, only the second window will get it.
		transform(image, &seed);

		sf::Texture texture2;

		texture2.loadFromImage(image);

		sf::Sprite sprite2;

		sprite2.setTexture(texture2);

		while (window1.isOpen() && window2.isOpen()) {
   			sf::Event event;
    	
			while (window1.pollEvent(event)) {
    			if (event.type == sf::Event::Closed)
       				window1.close();
			}
	
			while (window2.pollEvent(event)) {
    			if (event.type == sf::Event::Closed)
        			window2.close();
			}
		
			window1.clear(sf::Color::White);
			window1.draw(sprite1);
			window1.display();
			window2.clear(sf::Color::White);
			window2.draw(sprite2);
			window2.display();
		}

	// Load argument from argv[2] which holds the output file image
	if (!image.saveToFile(argv[2]))
		return -1;
	}
	else
	{
		sf::Image image;

		if (!image.loadFromFile("./cat.png"))
		return -1;

    	FibLFSR seed("1011011000110110");

		sf::Vector2u size = image.getSize();

		sf::RenderWindow window1(sf::VideoMode(size.x, size.y), "Before");
		sf::RenderWindow window2(sf::VideoMode(size.x, size.y), "After");

		sf::Texture texture1;
		texture1.loadFromImage(image);

		sf::Sprite sprite1;
		sprite1.setTexture(texture1);

		transform(image, &seed);

		sf::Texture texture2;
		texture2.loadFromImage(image);

		sf::Sprite sprite2;
		sprite2.setTexture(texture2);

		while (window1.isOpen() && window2.isOpen()) {
   			sf::Event event;
    	
			while (window1.pollEvent(event)) {
    			if (event.type == sf::Event::Closed)
       				window1.close();
			}
	
			while (window2.pollEvent(event)) {
    			if (event.type == sf::Event::Closed)
        			window2.close();
			}
		  
			window1.clear(sf::Color::White);
			window1.draw(sprite1);
			window1.display();
			window2.clear(sf::Color::White);
			window2.draw(sprite2);
			window2.display();
		}

		if (!image.saveToFile("cat-out.bmp"))
			return -1;
	return 0;
	}
}

void transform(sf::Image& image, FibLFSR* seed)
{
    sf::Color p;

	sf::Vector2u size = image.getSize();

	// Check to see if the seed is alphanumeric and execute instructions based on if it is true or not.
	if (seed->getIsAlphanumeric() == true)
	{
		// Loop through x and y based on the size of image, don't have to worry about the image dimension changing.
		for (int x = 0; x < (int)size.x; x++)
		{
			for (int y = 0; y < (int)size.y; y++)
			{
				p = image.getPixel(x, y);

				// Set encryption for R, G, B using generate but this time it is based on the seed size minus one.
				// This will scambled the image to it maximum.
				int encryption1 = seed->generate(seed->getString().size() - 1);
            	int encryption2 = seed->generate(seed->getString().size() - 1);
            	int encryption3 = seed->generate(seed->getString().size() - 1);	

				// xor each color components which the encryption from above. 
            	p.r ^= encryption1;
            	p.g ^= encryption2;
            	p.b ^= encryption3;

				// This changes the color based on the xor results of each color components.
            	image.setPixel(x, y, p);
			}
		}
	}
	else
	{
    	for (int x = 0; x < (int)size.x; x++) 
		{
			for (int y = 0; y < (int)size.y; y++) 
			{
            	p = image.getPixel(x, y);
	
				// Everything is the same from above but this generate is using 16 as input which is the maximum allowed for 16 bit.
				// This will scambled the image to it maximum.
            	int encryption1 = seed->generate(16);
            	int encryption2 = seed->generate(16);
            	int encryption3 = seed->generate(16);	

            	p.r ^= encryption1;
            	p.g ^= encryption2;
            	p.b ^= encryption3;

            	image.setPixel(x, y, p);
			}
		}
	}
}
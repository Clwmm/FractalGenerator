#include "FractalGenerator.h"

FractalGenerator::FractalGenerator(int verticles, int nrpoints, float x, float y, int windowSize)
{
	srand(time(0));

	if (verticles > MAXVERTICLES)
	{
		std::cout << "Given wrong numbers";
		return;
	}
	radius = windowSize * 0.45;
	window = new sf::RenderWindow(sf::VideoMode(windowSize, windowSize), "Fractal Generator");
	window->setFramerateLimit(0);
	center = sf::Vector2f(window->getSize().x / 2 - (pointsize / 2), window->getSize().y / 2 - (pointsize / 2));
	window->clear();

	// Given regular figure:
	sf::CircleShape points[MAXVERTICLES];
	for (int i = 0; i < verticles; i++)
	{
		points[i].setRadius(pointsize);
		points[i].setPosition(sf::Vector2f(center.x + (cos(i * 360 / verticles * DEGTORAD) * radius), center.y + (sin(i * 360 / verticles * DEGTORAD) * radius)));
		window->draw(points[i]);
	}
	
	// First iteration of fractal
	randomNext = fromtoran(1, verticles - 1);
	sf::CircleShape p(pointsize);
	dif = sf::Vector2f( ( points[randomNext].getPosition().x - points[0].getPosition().x) * x / y, (points[randomNext].getPosition().y - points[0].getPosition().y) * x / y);
	lastvec = sf::Vector2f(points[0].getPosition().x + dif.x, points[0].getPosition().y + dif.y);
	p.setPosition(lastvec);
	window->draw(p);
	
	sf::Event ev;
	while (window->isOpen())
	{
		while (window->pollEvent(ev))
		{
			if (ev.type == sf::Event::Closed)
				window->close();
			if (ev.type == sf::Event::KeyPressed)
				if (ev.key.code == sf::Keyboard::Escape)
					window->close();
		}


		// Creating fractal
		if (iter < nrpoints - 1)
		{
			randomNext = fromtoran(0, verticles - 1);
			sf::CircleShape p(pointsize);
			dif = sf::Vector2f( ( points[randomNext].getPosition().x - lastvec.x ) * x / y, ( points[randomNext].getPosition().y - lastvec.y ) * x / y);
			lastvec = sf::Vector2f(lastvec.x + dif.x, lastvec.y + dif.y);
			p.setPosition(lastvec);
			window->draw(p);
			iter++;
		}
		else
			if (status == State::still)
				status = State::last;

		// Display
		if (iter % 100 == 0 && status == State::still)
			window->display();
		if (status == State::last)
		{
			// SAVING IMAGE
			/*sf::Texture texture;
			texture.create(window->getSize().x, window->getSize().y);
			texture.update(*window);
			std::string filename = "rend/Fractal_" + std::to_string(verticles) + "_" + std::to_string(x) + "_" + std::to_string(y) + ".png";
			texture.copyToImage().saveToFile(filename);
			window->display();*/
			status = State::done;
		}

		// CLOSING AFTER
		/*if (status == State::done)
			window->close();*/

	}
}

FractalGenerator::~FractalGenerator()
{
	delete window;
}

int FractalGenerator::fromtoran(int a, int b)
{
	// Generating random number from a to b
	return (rand() % (b - a + 1)) + a;
}

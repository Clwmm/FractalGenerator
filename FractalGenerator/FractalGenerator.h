#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#define MAXVERTICLES 1000

enum class State { still, last, done };

class FractalGenerator
{
private:
	sf::RenderWindow* window;
public:
	FractalGenerator(int verticles, int nrpoints, float x, float y, int windowSize);
	~FractalGenerator();
private:
	float DEGTORAD = 0.017453;
	float pointsize = 1;
	float radius;
	sf::Vector2f center;

	sf::Vector2f lastvec;
	sf::Vector2f dif;
	int randomNext;
	
	int iter = 0;

	State status = State::still;

private:
	int fromtoran(int a, int b);
};


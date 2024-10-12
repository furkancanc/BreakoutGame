#pragma once


#include <SFML/Graphics.hpp>

// Abstract base class to represent any graphical entity on the screen
class entity
{
protected:
	sf::Sprite sprite;
public:
	// Pure virtual functions
	// Concrete graphical entities must implement these functions
	// The update member function will compute the new position, appearence, etc of the object
	// The draw memeber function will cause the updated object to be display in the game window
	virtual void update() = 0;
	virtual void draw(sf::RenderWindow& window) = 0;

	// Virtual destructor
	virtual ~entity() {}
};
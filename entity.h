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

	// Helper function to get the bounding box of a sprite
	sf::FloatRect get_bounding_box() const noexcept;

	// Helper function to get the centre of a sprite
	sf::Vector2f get_centre() const noexcept;

	// Helper functions to get the position of the sprite
	float x() const noexcept;
	float y() const noexcept;

	// Virtual destructor
	virtual ~entity() {}
};


// Abstract base class to represent graphical entities wihch can move around the screen
class moving_entity : public entity
{
protected:
	// SFML vector to store the object's velocity
	// This is the distance the ball moves between screen updates
	sf::Vector2f velocity;
public:
	// Helper functions

	// Pure virtual functions inherited from parent class
	// virtual void update() = 0;
	// virtual void draw(sf::RenderWindow& window) = 0;
	// etc

};
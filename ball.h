#pragma once

#include "constants.h"
#include "entity.h"

// Class to represent the bouncing ball
// Inherits from moving_entity
class ball : public moving_entity
{
	// Private data members
	static sf::Texture texture;

public:
	// Interface of the class

	// Constructor
	// Arguments are the initial coordinates of the centre
	// SFML uses the computer graphics convention
	// (0, 0) is the top left cornet of the screen
	// x increases to the right
	// y increases downwards
	ball(float x, float y);

	// Implement the pure virtual functions
	void update() override;
	void draw(sf::RenderWindow& window) override;
	void move_up() noexcept override;
	void move_left() noexcept override;
	void move_right() noexcept override;
};


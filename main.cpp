// Code for a "breakout" game
// Based on a talk by Vittorio Romeo
// Uses the SFML graphics library
#include <SFML/Graphics.hpp>

#include <string>
#include "constants.h"
#include "background.h"
#include "ball.h"
#include "paddle.h"

using namespace std::literals;

// The main function for the program
int main()
{
	// Create the background object
	background the_background(0.0f, 0.0f);

	// Create a ball object in the middle of the screen
	ball the_ball(constants::window_width / 2.0f, constants::window_height / 2.0f);

	// Create a paddle object at the bottom fo the screen in the middle
	paddle the_paddle(constants::window_width / 2.0f, constants::window_height - constants::paddle_height);

	// Create the game's window using an object of class RenderWindow
	// The constructor takes an SFML 2D vectorw ith the window dimensions
	// and an std::string with the window title
	// The SFML code is in the sf namespace
	sf::RenderWindow game_window{ {constants::window_width, constants::window_height}, "Simple Breakout Game Version 1"s };

	// Limit the framerate
	// This allows other processes to run and reduces power consumption
	game_window.setFramerateLimit(60);									// Max rate is 60 frames per second

	// Game loop
	// Clear the screen
	// Check for new events
	// Calculate updated graphics
	// Display the updated graphics

	while (game_window.isOpen())
	{
		// Clear the screen
		game_window.clear();

		// Check for any events since the last loop iteration
		sf::Event event;

		// If the user pressed "Escape", or clicked on "close", we close the window
		// This will terminate the program

		while (game_window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				game_window.close();
				break;
			}
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
		{
			game_window.close();
			break;
		}

		// Calculate the updated graphics
		the_background.update();
		the_ball.update();
		the_paddle.update();

		// Display the updated graphics
		the_background.draw(game_window);
		the_ball.draw(game_window);
		the_paddle.draw(game_window);
		game_window.display();
	}
}
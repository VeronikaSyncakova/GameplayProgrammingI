#include <Defines.h>

#include <iostream>
#include <SFML/Graphics.hpp>
#include <Player.h>
#include <Events.h>
#include <Debug.h>
#include <ConcreteCommands.h>
#include <InputManager.h>


using namespace std;

int main()
{
	// Create the main window
	sf::RenderWindow window(sf::VideoMode(800, 600), "Player Finite State Machine");

	// Load a sprite to display
	sf::Texture player_texture;
	if (!player_texture.loadFromFile(PLAYER_SPRITES))
	{
		DEBUG_MSG("Failed to load file");
		if (!player_texture.loadFromFile(ERROR_SPRITES))
		{
			return EXIT_FAILURE;
		}
	}


	// Setup Players Default Animated Sprite
	AnimatedSprite player_animated_sprite(player_texture);
	AnimatedSprite new_animated_sprite(player_texture);

	Player player(player_animated_sprite);
	Player npc(player_animated_sprite);

	Command *kick = new KickCommand();
	Command *block = new BlockCommand();
	Command *punch = new PunchCommand();

	InputManager::getInstance()->keyCommands(Keyboard::K, kick);
	InputManager::getInstance()->keyCommands(Keyboard::B, block);
	InputManager::getInstance()->keyCommands(Keyboard::P, punch);

	int index = -1;
	std::vector<Command*> commands;

	gpp::Events input;
	gpp::Events ai;

	// Start the game loop
	while (window.isOpen())
	{
		// Process events
		sf::Event event;
		while (window.pollEvent(event))
		{
			
			if(sf::Event::Closed==event.type)
			{
				// Close window : exit
				window.close();
			}
				// Deal with KeyPressed
			else if(sf::Event::KeyPressed==event.type)
			{
				Command *command = InputManager::getInstance()->handleInput();

				if (command)
				{
					command->execute(input);
					commands.push_back(command->copy());
					index++;
					commands.erase(commands.begin() + index + 1, commands.end());
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::U) && index > 0)
				{
					commands[index]->undo(input);
					index--;
				}

				if (sf::Keyboard::isKeyPressed(sf::Keyboard::R) && (commands.begin() + index + 1) != commands.end())
				{
					commands[index]->execute(input);
					index++;
				}
			}
		/*
				//Kick event
				if(sf::Keyboard::isKeyPressed(sf::Keyboard::K))
				{
					DEBUG_MSG("gpp::Events::Event::KICK_STAR_EVENT");
					input.setCurrent(gpp::Events::Event::KICK_START_EVENT);
					
				} //Punch event
				else if(sf::Keyboard::isKeyPressed(sf::Keyboard::P))
				{
					DEBUG_MSG("gpp::Events::Event::PUNCH_STAR_EVENT");
					input.setCurrent(gpp::Events::Event::PUNCH_START_EVENT);
					

				}//Block event
				else if(sf::Keyboard::isKeyPressed(sf::Keyboard::B))
				{
					DEBUG_MSG("gpp::Events::Event::BLOCK_STAR_EVENT");
					input.setCurrent(gpp::Events::Event::BLOCK_START_EVENT);
					
				}

				// Died Event
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
				{
					DEBUG_MSG("gpp::Events::Event::DIED_EVENT");
					input.setCurrent(gpp::Events::Event::DIED_EVENT);
				}
				// Revieved Event
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
				{
					DEBUG_MSG("gpp::Events::Event::REVIVED_EVENT");
					input.setCurrent(gpp::Events::Event::REVIVED_EVENT);
				}
		*/
				// Deal with KeyReleased
			else if(sf::Event::KeyReleased==event.type)
			{
				Command *command = InputManager::getInstance()->handleInput();

				if (command)
				{
					command->execute(input);
					commands.push_back(command->copy());
					index++;
					commands.erase(commands.begin() + index + 1, commands.end());
				}
			}
			else
			{
				DEBUG_MSG("gpp::Events::Event::NONE");
				input.setCurrent(gpp::Events::Event::NONE);
			}
			// Handle input to Player
			player.handleInput(input);
		}

		// Update AI
		ai.setCurrent(gpp::Events::Event::NONE);
		npc.handleInput(ai);

		// Update the Player
		player.update();
		
		// Update the NPC
		npc.update();

		// Clear screen
		window.clear();

		// Draw the Players Current Animated Sprite
		window.draw(player.getAnimatedSpriteFrame());

		// Draw the NPC's Current Animated Sprite
		npc.getAnimatedSprite().setScale(-1.0f, 1.0f);
		npc.getAnimatedSprite().setPosition(600.0f,0.0f);
		window.draw(npc.getAnimatedSpriteFrame());

		// Update the window
		window.display();
	}

	return EXIT_SUCCESS;
};
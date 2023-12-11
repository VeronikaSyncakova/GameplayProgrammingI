#define CUTE_C2_IMPLEMENTATION

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
	sf::RenderWindow window(sf::VideoMode(800, 600), "Pproject Orc vs Troll");

	sf::Font font;
	font.loadFromFile("assets/redBurger.otf");
	sf::Text playerHealth;
	playerHealth.setPosition(100.0f, 500.0f);
	playerHealth.setFillColor(sf::Color::Green);
	playerHealth.setFont(font);
	sf::Text npcHealth;
	npcHealth.setPosition(700.0f, 500.0f);
	npcHealth.setColor(sf::Color::Green);
	npcHealth.setFont(font);


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

	Player player(player_animated_sprite, sf::Vector2f(0.0f,30.0f));
	Player npc(player_animated_sprite, sf::Vector2f(700.0f,30.0f));

	Command *kick = new KickCommand();
	Command *block = new BlockCommand();
	Command *punch = new PunchCommand();
	Command *revived=new RevievedCommand();

	InputManager::getInstance()->keyCommands(Keyboard::K, kick);
	InputManager::getInstance()->keyCommands(Keyboard::B, block);
	InputManager::getInstance()->keyCommands(Keyboard::P, punch);
	InputManager::getInstance()->keyCommands(Keyboard::R, revived);


	int index = -1;
	std::vector<Command*> commands;

	gpp::Events input;
	gpp::Events ai;

	int calculated=0;

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

					ai.setRandom();
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

				if (sf::Keyboard::isKeyPressed(sf::Keyboard::R) && npc.getHealth()<= 0)
				{
					ai.setCurrent(gpp::Events::Event::REVIVED_EVENT);
				}

			}

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

					ai.setRandom();

				}
			}
			else
			{
				DEBUG_MSG("gpp::Events::Event::NONE");
				input.setCurrent(gpp::Events::Event::NONE);
				ai.setCurrent(gpp::Events::Event::NONE);
			}
			// Handle input to Player
			player.handleInput(input);
			// Handle input to NPC
			npc.handleInput(ai);
		}

		// Update the Player
		player.update();
		
		// Update the NPC
		npc.update();

		//check collision and move the collision circles
		if (player.getCircle().circleCollision(npc.getCircle().getCollisionCircle())&& player.getPlayerState()->getCurrentState()== gpp::Events::Event::NONE)//exit collision
		{
			calculated=0;
			player.setCirclePosition(sf::Vector2f(0.0f,30.0f));
			npc.setCirclePosition(sf::Vector2f(700.0f,30.0f));
		}
		else if (player.getCircle().circleCollision(npc.getCircle().getCollisionCircle())) //collision
		{
			DEBUG_MSG("Circles are in Collision");
			input.setCurrent(gpp::Events::Event::NONE);
			ai.setCurrent(gpp::Events::Event::NONE);
			if (calculated==0)
			{
				player.calculateHealth(npc);
			}
			calculated++;
		}
		else if(player.getPlayerState()->getCurrentState()!= gpp::Events::Event::NONE) //no collision, move circles
		{
			DEBUG_MSG("No Collision");
			player.updateCircle(1);
			npc.updateCircle(-1);
		}

		
		playerHealth.setString(std::to_string(player.getHealth()));
		npcHealth.setString(std::to_string(npc.getHealth()));
		

		// Clear screen
		window.clear();

		// Draw the Players Current Animated Sprite
		window.draw(player.getAnimatedSpriteFrame());
		window.draw(player.getCircle().getBody());

		// Draw the NPC's Current Animated Sprite
		npc.getAnimatedSprite().setScale(-1.0f, 1.0f);
		npc.getAnimatedSprite().setPosition(600.0f,0.0f);
		window.draw(npc.getAnimatedSpriteFrame());
		window.draw(npc.getCircle().getBody());

		//draw text
		window.draw(playerHealth);
		window.draw(npcHealth);


		// Update the window
		window.display();
	}

	return EXIT_SUCCESS;
};
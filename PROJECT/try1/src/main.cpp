#include <Defines.h>

#include <iostream>
#include <SFML/Graphics.hpp>
#include <Player.h>
#include <Events.h>
#include <Debug.h>
#include <GameObject.h>
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

	GameObject* player=new Player(player_animated_sprite, sf::Vector2f(0.0f,0.0f));
	GameObject* npc=new Player(player_animated_sprite, sf::Vector2f(400.0f,0.0f));

	////Commands
	Command *shield = new MoveUpCommand();
	Command *sword = new MoveDownCommand();
	//Command *moveLeft = new MoveLeftCommand();
	//Command *moveRight = new MoveRightCommand();
	//Command *jump = new JumpCommand();
	//Command *run= new RunCommand();
	//Command *crouch= new CrouchCommand();
	Command *bat= new AttackCommand();
	//Command *shield= new ShieldCommand();

	InputManager::getInstance()->keyCommands(Keyboard::E, shield); //******************************
	InputManager::getInstance()->keyCommands(Keyboard::S, sword);//*********************************
	InputManager::getInstance()->keyCommands(Keyboard::B, bat);//***********************************
	//InputManager::getInstance()->keyCommands(Keyboard::A, moveLeft);
	//InputManager::getInstance()->keyCommands(Keyboard::D, moveRight);
	//InputManager::getInstance()->keyCommands(Keyboard::J, jump);
	//InputManager::getInstance()->keyCommands(Keyboard::F, run);
	//InputManager::getInstance()->keyCommands(Keyboard::C, crouch);
	//InputManager::getInstance()->keyCommands(Keyboard::P, shield);

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
			switch (event.type)
			{
			case sf::Event::Closed:
				// Close window : exit
				window.close();
				break;
				// Deal with KeyPressed
			case sf::Event::KeyPressed:
				Command *command = InputManager::getInstance()->handleInput();

				if (command)
				{
					command->execute(player, input);
					commands.push_back(command->copy());
					index++;
					commands.erase(commands.begin() + index + 1, commands.end());
				}

				if (Keyboard::isKeyPressed(Keyboard::U) && index > 0)
				{
					commands[index]->undo(player);
					index--;
				}

				if (Keyboard::isKeyPressed(Keyboard::R) && (commands.begin() + index + 1) != commands.end())
				{
					commands[index]->execute(player, input);
					index++;
				}

				break;
			default:
				break;
			}
			/*
				//////////////////////////////////////////////////////////////////////////////////
				// added cases
				//////////////////////////////////////////////////////////////////////////////////

				//Kick event
				if(sf::Keyboard::isKeyPressed(sf::Keyboard::K))
				{
					DEBUG_MSG("gpp::Events::Event::KICK_STAR_EVENT");
					input.setCurrent(gpp::Events::Event::KICK_START_EVENT);
					//player.setAnimatedSprite(new_animated_sprite);
				} //Punch event
				else if(sf::Keyboard::isKeyPressed(sf::Keyboard::P))
				{
					DEBUG_MSG("gpp::Events::Event::PUNCH_STAR_EVENT");
					input.setCurrent(gpp::Events::Event::PUNCH_START_EVENT);
					//player.setAnimatedSprite(new_animated_sprite);

				}//Block event
				else if(sf::Keyboard::isKeyPressed(sf::Keyboard::B))
				{
					DEBUG_MSG("gpp::Events::Event::BLOCK_STAR_EVENT");
					input.setCurrent(gpp::Events::Event::BLOCK_START_EVENT);
					//player.setAnimatedSprite(new_animated_sprite);
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
				// Running attack
				else if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Z) &&
						  sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) ||
						 (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) &&
						  sf::Keyboard::isKeyPressed(sf::Keyboard::Z)))
				{
					DEBUG_MSG("gpp::Events::Event::ATTACK_START");
					input.setCurrent(gpp::Events::Event::ATTACK_START_EVENT);
				}
				// Attack
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
				{
					DEBUG_MSG("gpp::Events::Event::ATTACK_START_EVENT");
					input.setCurrent(gpp::Events::Event::ATTACK_START_EVENT);
				}
				// Throw attack
				else if ((sf::Keyboard::isKeyPressed(sf::Keyboard::X) &&
						  sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) ||
						 (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) &&
						  sf::Keyboard::isKeyPressed(sf::Keyboard::X)))
				{
					DEBUG_MSG("gpp::Events::Event::THROW_START_EVENT");
					input.setCurrent(gpp::Events::Event::THROW_START_EVENT);
				}
				// Throw Attack
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::X))
				{
					DEBUG_MSG("gpp::Events::Event::THROW_START_EVENT");
					input.setCurrent(gpp::Events::Event::THROW_START_EVENT);
				}
				// Run Right
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
				{
					DEBUG_MSG("gpp::Events::Event::RUN_RIGHT_START_EVENT");
					input.setCurrent(gpp::Events::Event::RUN_RIGHT_START_EVENT);
				}
				// Climb Up
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
				{
					DEBUG_MSG("gpp::Events::Event::MOVE_UP_START_EVENT");
					input.setCurrent(gpp::Events::Event::MOVE_UP_START_EVENT);
				}
				// Climb Down
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
				{
					DEBUG_MSG("gpp::Events::Event::MOVE_DOWN_START_EVENT");
					input.setCurrent(gpp::Events::Event::MOVE_DOWN_START_EVENT);
				}
				// Hit Bottom of Ladder Event
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::C))
				{
					DEBUG_MSG("gpp::Events::Event::HIT_LADDER_BOTTOM_EVENT");
					input.setCurrent(gpp::Events::Event::HIT_LADDER_BOTTOM_EVENT);
				}
				// Hit Top of Ladder Event
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::T))
				{
					DEBUG_MSG("gpp::Events::Event::HIT_LADDER_TOP_EVENT");
					input.setCurrent(gpp::Events::Event::HIT_LADDER_TOP_EVENT);
				}
				// Jump Run
				if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Space) &&
					 sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) ||
					(sf::Keyboard::isKeyPressed(sf::Keyboard::Right) &&
					 sf::Keyboard::isKeyPressed(sf::Keyboard::Space)))
				{
					DEBUG_MSG("gpp::Events::Event::JUMP_UP_EVENT");
					input.setCurrent(gpp::Events::Event::JUMP_UP_EVENT);
				}
				// Jump Event
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
				{
					DEBUG_MSG("gpp::Events::Event::JUMP_UP_EVENT");
					input.setCurrent(gpp::Events::Event::JUMP_UP_EVENT);
				}
				// Running Slide
				else if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Down) &&
						  sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) ||
						 (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) &&
						  sf::Keyboard::isKeyPressed(sf::Keyboard::Down)))
				{
					DEBUG_MSG("gpp::Events::Event::SLIDE_EVENT");
					input.setCurrent(gpp::Events::Event::SLIDE_EVENT);
				}
				// Hit Ground Event
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::H))
				{
					DEBUG_MSG("gpp::Events::Event::HIT_GROUND_EVENT");
					input.setCurrent(gpp::Events::Event::HIT_GROUND_EVENT);
				}

				// Jump Attack Event
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::H))
				{
					DEBUG_MSG("gpp::Events::Event::HIT_GROUND_EVENT");
					input.setCurrent(gpp::Events::Event::HIT_GROUND_EVENT);
				}

				// Jump Throw Attack Event
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::H))
				{
					DEBUG_MSG("gpp::Events::Event::HIT_GROUND_EVENT");
					input.setCurrent(gpp::Events::Event::HIT_GROUND_EVENT);
				}
				break;
			
				// Deal with KeyReleased
			case sf::Event::KeyReleased:
				///////////////////////////////////////////////////////////////////////////
				//added cases
				///////////////////////////////////////////////////////////////////////////

				//stop kick
				if(event.key.code==sf::Keyboard::K)
				{
					DEBUG_MSG("gpp::Events::Event::KICK_STOP_EVENT");
					input.setCurrent(gpp::Events::Event::KICK_STOP_EVENT);
					//player.setAnimatedSprite(player_animated_sprite);
				}
				else if(event.key.code==sf::Keyboard::P)
				{
					DEBUG_MSG("gpp::Events::Event::PUNCH_STOP_EVENT");
					input.setCurrent(gpp::Events::Event::PUNCH_STOP_EVENT);
				}
				else if(event.key.code==sf::Keyboard::B)
				{
					DEBUG_MSG("gpp::Events::Event::BLOCK_STOP_EVENT");
					input.setCurrent(gpp::Events::Event::BLOCK_STOP_EVENT);
				}


				// Run and Stop Attack
				if (event.key.code == sf::Keyboard::Z &&
					sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
				{
					DEBUG_MSG("gpp::Events::Event::RUN_RIGHT_START_EVENT");
					input.setCurrent(gpp::Events::Event::RUN_RIGHT_START_EVENT);
				}
				// Stop Attack
				else if (event.key.code == sf::Keyboard::Z)
				{
					DEBUG_MSG("gpp::Events::Event::ATTACK_STOP_EVENT");
					input.setCurrent(gpp::Events::Event::ATTACK_STOP_EVENT);
				}
				// Run and Stop Throw Attack
				else if (event.key.code == sf::Keyboard::X &&
						 sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
				{
					DEBUG_MSG("gpp::Events::Event::RUN_RIGHT_START_EVENT");
					input.setCurrent(gpp::Events::Event::RUN_RIGHT_START_EVENT);
				}
				// Stop Throw Attack
				else if (event.key.code == sf::Keyboard::X)
				{
					DEBUG_MSG("gpp::Events::Event::THROW_STOP_EVENT");
					input.setCurrent(gpp::Events::Event::THROW_STOP_EVENT);
				}
				// Stop Running Right
				else if (event.key.code == sf::Keyboard::Right)
				{
					DEBUG_MSG("gpp::Events::Event::RUN_RIGHT_STOP_EVENT");
					input.setCurrent(gpp::Events::Event::RUN_RIGHT_STOP_EVENT);
				}
				// Stop Slide
				else if (event.key.code == sf::Keyboard::Down &&
						 sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
				{
					DEBUG_MSG("gpp::Events::Event::RUN_RIGHT_START_EVENT");
					input.setCurrent(gpp::Events::Event::RUN_RIGHT_START_EVENT);
				}
				// Stop Moving Up
				else if (event.key.code == sf::Keyboard::Up)
				{
					DEBUG_MSG("gpp::Events::Event::MOVE_UP_STOP_EVENT");
					input.setCurrent(gpp::Events::Event::MOVE_UP_STOP_EVENT);
				}
				// Stop Moving Down
				else if (event.key.code == sf::Keyboard::Down)
				{
					DEBUG_MSG("gpp::Events::Event::MOVE_DOWN_STOP_EVENT");
					input.setCurrent(gpp::Events::Event::MOVE_DOWN_STOP_EVENT);
				}
				break;

			default:
				DEBUG_MSG("gpp::Events::Event::NONE");
				input.setCurrent(gpp::Events::Event::NONE);
				break;
			}
		*/
			// Handle input to Player
			dynamic_cast<Player*>(player)->handleInput(input);
		}

		// Update AI
		ai.setCurrent(gpp::Events::Event::RUN_RIGHT_START_EVENT);
		dynamic_cast<Player*>(npc)->handleInput(ai);

		// Update the Player
		dynamic_cast<Player*>(player)->update();
		
		// Update the NPC
		dynamic_cast<Player*>(npc)->update();

		// Clear screen
		window.clear();

		// Draw the Players Current Animated Sprite
		window.draw(player.getAnimatedSpriteFrame());

		// Draw the NPC's Current Animated Sprite
		//window.draw(npc.getAnimatedSpriteFrame());

		// Update the window
		window.display();
	}

	return EXIT_SUCCESS;
};
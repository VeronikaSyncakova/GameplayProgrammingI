#include <iostream>
#include <SFML/Graphics.hpp>
#include <./include/Command.h>
#include <./include/ConcreteCommands.h>
#include <./include/InputManager.h>

class Player : public GameObject
{
public:
	Player(Vector2f position, String image)
	{
		this->position = position;
		initialize(image);
	}
};

class Enemy : public GameObject
{
public:
	Enemy(Vector2f position, String image)
	{
		this->position = position;
		initialize(image);
	}
};

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Command Pattern");

	Command *moveUp = new MoveUpCommand();
	Command *moveDown = new MoveDownCommand();
	Command *moveLeft = new MoveLeftCommand();
	Command *moveRight = new MoveRightCommand();
	Command *jump = new JumpCommand();
	Command *run= new RunCommand();
	Command *crouch= new CrouchCommand();
	Command *attack= new AttackCommand();
	Command *shield= new ShieldCommand();


	InputManager::getInstance()->keyCommands(Keyboard::W, moveUp);
	InputManager::getInstance()->keyCommands(Keyboard::S, moveDown);
	InputManager::getInstance()->keyCommands(Keyboard::A, moveLeft);
	InputManager::getInstance()->keyCommands(Keyboard::D, moveRight);
	InputManager::getInstance()->keyCommands(Keyboard::J, jump);
	InputManager::getInstance()->keyCommands(Keyboard::F, run);
	InputManager::getInstance()->keyCommands(Keyboard::C, crouch);
	InputManager::getInstance()->keyCommands(Keyboard::B, attack);
	InputManager::getInstance()->keyCommands(Keyboard::P, shield);




	GameObject *player = new Player(Vector2f(100, 100), "./images/player/Player");
	GameObject *enemy = new Enemy(Vector2f(300, 200), "./images/npc/npc");

	int index = -1;
	std::vector<Command*> commands;

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

			else if (event.type == sf::Event::EventType::KeyPressed)
			{
				Command *command = InputManager::getInstance()->handleInput();

				if (command)
				{
					command->execute(player);
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
					commands[index]->execute(player);
					index++;
				}
			}
		}

		player->update();
		enemy->update();

		window.clear(sf::Color::Black);
		player->draw(window);
		enemy->draw(window);
		window.display();
	}

	return 0;
}
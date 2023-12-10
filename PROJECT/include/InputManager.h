#ifndef INPUT_MANAGER_H
#define INPUT_MANAGER_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include <Command.h> 

// Singleton Input Manager

class InputManager
{
public:
	InputManager(InputManager &other) = delete; // Ensure not clonable
	void operator=(const InputManager &) = delete; // Ensure not assignable
	static InputManager* getInstance();
	Command* handleInput();	 
	void keyCommands(sf::Keyboard::Key, Command*);
protected:
	InputManager();
private:
	static InputManager* m_instance;
	std::vector<std::pair<sf::Keyboard::Key, Command*>> keyboard_mapping;
};

#endif // !INPUT_MANAGER_H
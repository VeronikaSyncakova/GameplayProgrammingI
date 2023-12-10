#include <InputManager.h>

InputManager* InputManager::m_instance= nullptr;


InputManager::InputManager()
{
}

InputManager* InputManager::getInstance() {
	if (m_instance==nullptr) {
		m_instance = new InputManager();
	}
	return m_instance;
}

Command* InputManager::handleInput()
{
	int size = keyboard_mapping.size();
	for (int i = 0; i < size; i++) {
		if (sf::Keyboard::isKeyPressed(keyboard_mapping[i].first)) {
			return keyboard_mapping[i].second;
		}
	}
	return NULL;
}

void InputManager::keyCommands(sf::Keyboard::Key key, Command * command)
{
	keyboard_mapping.push_back(std::pair<sf::Keyboard::Key, Command*>(key, command));
}
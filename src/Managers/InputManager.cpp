#include "../../include/Managers/InputManager.h"

// Default constructor for InputManager
InputManager::InputManager()
{
    // Initialize key states and previous key states for all keyboard keys
    for (int i = 0; i < sf::Keyboard::KeyCount; ++i) {
        keyState[static_cast<sf::Keyboard::Key>(i)] = false;
        keyPrevState[static_cast<sf::Keyboard::Key>(i)] = false;
    }
}

// Process user input and update key states
void InputManager::ProcessInput(sf::RenderWindow& window)
{
    // Update key states and previous key states for all keyboard keys
    for (int i = 0; i < sf::Keyboard::KeyCount; ++i) {
        keyPrevState[static_cast<sf::Keyboard::Key>(i)] = keyState[static_cast<sf::Keyboard::Key>(i)];
        keyState[static_cast<sf::Keyboard::Key>(i)] = sf::Keyboard::isKeyPressed(static_cast<sf::Keyboard::Key>(i));
    }

    // Update mouse position
    mousePosition = sf::Mouse::getPosition(window);
}

// Check if a specific key is currently pressed
bool InputManager::KeyPressed(sf::Keyboard::Key key)
{
    return keyState[key];
}

// Check if a specific key has just been pressed
bool InputManager::KeyDown(sf::Keyboard::Key key)
{
    return keyState[key] && !keyPrevState[key];
}

// Check if a specific key has just been released
bool InputManager::KeyUp(sf::Keyboard::Key key)
{
    return !keyState[key] && keyPrevState[key];
}

// Get the current mouse position
sf::Vector2i InputManager::getMousePosition(sf::RenderWindow& window)
{
    return mousePosition;
}
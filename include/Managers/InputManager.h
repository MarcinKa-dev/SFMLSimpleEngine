#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <unordered_map>

/**
 * @brief The InputManager class handles user input and manages key states.
 * 
 * This class provides functionality to process user input, update key states,
 * and check the status of individual keys. It also retrieves the current mouse position.
 */
class InputManager
{
public:
    // Default constructor for InputManager
    InputManager();

    
    /**
     * @brief Process user input and update key states.
     * 
     * This function processes user input from the provided SFML window and updates
     * the internal state of each keyboard key accordingly.
     * 
     * @param window The SFML window to process input from.
     */
    void ProcessInput(sf::RenderWindow& window);

    
    /**
     * @brief Check if a specific key is currently pressed.
     * 
     * @param key The SFML Keyboard::Key to check.
     * @return true if the key is currently pressed, false otherwise.
     */
    bool KeyPressed(sf::Keyboard::Key key);
    
    /**
     * @brief Check if a specific key has just been pressed.
     * 
     * @param key The SFML Keyboard::Key to check.
     * @return true if the key has just been pressed, false otherwise.
     */
    bool KeyDown(sf::Keyboard::Key key);
    
    /**
     * @brief Check if a specific key has just been released.
     * 
     * @param key The SFML Keyboard::Key to check.
     * @return true if the key has just been released, false otherwise.
     */
    bool KeyUp(sf::Keyboard::Key key);
    
    /**
     * @brief Get the current mouse position.
     * 
     * @param window The SFML window to retrieve the mouse position relative to.
     * @return sf::Vector2i The current mouse position.
     */
    sf::Vector2i getMousePosition(sf::RenderWindow& window);
    
private:
    // Map to store the current state of each keyboard key
    std::unordered_map<sf::Keyboard::Key, bool> keyState;
    
    // Map to store the previous state of each keyboard key
    std::unordered_map<sf::Keyboard::Key, bool> keyPrevState;
    
    // Vector to store the current mouse position
    sf::Vector2i mousePosition;
};
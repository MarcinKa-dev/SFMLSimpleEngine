#pragma once
#include<SFML/Graphics.hpp>
#include"../Managers/InputManager.h"

/**
 * @brief The IGameState class defines the interface for game states.
 * 
 * This class provides a base interface for game states with virtual functions
 * for initializing, updating, rendering, handling input, and cleaning up.
 */
class IGameState
{
public:
    // Virtual destructor for IGameState
    virtual ~IGameState() = default;

    /**
     * @brief Virtual function to initialize the game state.
     * 
     * This pure virtual function must be implemented by derived classes to handle
     * the initialization of the specific game state.
     */
    virtual void initialize() = 0;
    
    /**
     * @brief Virtual function to update the logic of the game state.
     * 
     * This pure virtual function must be implemented by derived classes to handle
     * the logic update for the specific game state.
     */
    virtual void update() = 0;
    
    /**
     * @brief Virtual function to render the game state to an SFML window.
     * 
     * This pure virtual function must be implemented by derived classes to handle
     * the rendering of the specific game state to an SFML window.
     * 
     * @param window The SFML window to render the game state to.
     */
    virtual void render(sf::RenderWindow& window) = 0;
    
    /**
     * @brief Virtual function to handle input for the game state.
     * 
     * This pure virtual function must be implemented by derived classes to handle
     * input for the specific game state using an InputManager.
     * 
     * @param inputManager The InputManager for processing input.
     */
    virtual void handleInput(InputManager& inputManager) = 0;
    
    /**
     * @brief Virtual function to clean up resources associated with the game state.
     * 
     * This pure virtual function must be implemented by derived classes to handle
     * the cleanup of resources associated with the specific game state.
     */
    virtual void cleanup() = 0;
};
#pragma once
#include "AbstractGameState.h"
#include "../../Entities/GameObject.h"
#include "../Game.h"
#include <memory>

/**
 * @brief The PlayingState class represents the testing game state for playing the game.
 * 
 * This class inherits from AbstractGameState and provides specific implementations
 * for initializing, updating, rendering, handling input, and cleaning up the playing state.
 */
class PlayingState : public AbstractGameState
{
public:
    /**
     * @brief Constructor for the PlayingState class.
     * 
     * @param game A reference to the Game object managing the game state.
     */
    PlayingState(Game& game);
    
    /**
     * @brief Implementation of the initialize function for the PlayingState.
     * 
     * This function is called to initialize the playing state.
     */
    void initialize() override;
    
    /**
     * @brief Implementation of the update function for the PlayingState.
     * 
     * This function is called to update the logic of the playing state.
     */
    void update() override;
    
    /**
     * @brief Implementation of the render function for the PlayingState.
     * 
     * This function is called to render the playing state to an SFML window.
     * 
     * @param window The SFML window to render the playing state to.
     */
    void render(sf::RenderWindow& window) override;
    
    /**
     * @brief Implementation of the handleInput function for the PlayingState.
     * 
     * This function is called to handle input for the playing state using an InputManager.
     * 
     * @param inputManager The InputManager for processing input.
     */
    void handleInput(InputManager& inputManager) override;
    
    /**
     * @brief Implementation of the cleanup function for the PlayingState.
     * 
     * This function is called to clean up resources associated with the playing state.
     */
    void cleanup() override;

private:
    // Vector to store weak pointers to game objects in the playing state.
    std::vector<std::weak_ptr<GameObject>> gameObjects;
    // Example game object (rectangle) for demonstration.
    sf::RectangleShape playerRect;
    // Example player movement velocity.
    sf::Vector2f playerVelocity;
};
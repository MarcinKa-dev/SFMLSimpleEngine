#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <memory>
#include "../Managers/ResourceManager.h"
#include "../Managers/InputManager.h"
#include "../Managers/EntityManager.h"
#include "../Managers/AudioManager.h"
#include "IGameState.h"

/**
 * @brief The Game class represents the main game engine.
 * 
 * This class is responsible for initializing the game window, managing various game
 * aspects such as resources, input, entities, and audio, and running the game loop.
 */
class Game
{
public:
    
    /**
     * @brief Constructor to initialize the Game object with the specified parameters.
     * 
     * @param width The width of the game window.
     * @param height The height of the game window.
     * @param title The title of the game window.
     * @param frameLimit The frame limit for the game window.
     */
    Game(int width, int height, std::string title, int frameLimit) : window(sf::RenderWindow(sf::VideoMode(width, height),title)), 
    resourceManager(), inputManager(), entityManager(), audioManager(resourceManager){ window.setFramerateLimit(frameLimit);}
    
    // Destructor for the Game class
    ~Game();
    
    /**
     * @brief Method to start the game loop.
     * 
     * This function initiates the main game loop, processing input, updating game logic,
     * and rendering the game window until it is closed.
     */
    void Run();

    /**
     * @brief Function to change the current game state.
     * 
     * @param newState The new game state to set.
     */
    void changeState(std::shared_ptr<IGameState> newState);

    // Accessors for various managers
    ResourceManager& getResourceManager() { return resourceManager; }
    InputManager& getInputManager() { return inputManager; }
    EntityManager& getEntityManager() { return entityManager; }
    AudioManager& getAudioManager() { return audioManager; }
private:
    // Functions to handle different aspects of the game loop
    void processInput();
    void update();
    void render();

    std::shared_ptr<IGameState> currentState;


    //SFML Window for the game
    sf::RenderWindow window;
    // ResourceManager to handle game resources
    ResourceManager resourceManager;
    // InputManager to handle user input
    InputManager inputManager;
    // EntityManager to manage game entities
    EntityManager entityManager;
    // AudioManager to handle game audio
    AudioManager audioManager;
};
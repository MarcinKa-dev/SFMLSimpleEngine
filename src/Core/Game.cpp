#include "../../include/Core/Game.h"

Game::~Game() 
{
    // Close the window if it is still open when the game is destroyed
    if(window.isOpen())
        window.close();
}

// Main game loop
void Game::Run()
{
    
    // Game loop runs as long as the window is open
    while(window.isOpen())
    {
        processInput();

        update();

        render();
    }

    currentState->cleanup();
}

void Game::processInput() 
{
    // Process user input using the InputManager
    inputManager.ProcessInput(window);

    if(currentState)
    {
    currentState->handleInput(inputManager);
    }

    // Handle SFML events
    sf::Event event;
    while(window.pollEvent(event))
    {
        // Check if the window should be closed
        if(event.type ==sf::Event::Closed)
        {
            window.close();
        }
    }
}

void Game::update() {
    // Update game logic
    if(currentState)
    {
        currentState->update();
    }
}

void Game::render()
{
    // Clear the window (for the next frame)
    window.clear();
    if(currentState)
    {
        currentState->render(window);
    }
    // Display the content of the window
    window.display();
}

/**
 * @brief Changes the current game state to a new state.
 * 
 * This function is responsible for transitioning the game from the current state
 * to a new state. It cleans up resources associated with the current state (if any),
 * sets the current state to the new state, and initializes the new state.
 * 
 * @param newState A shared pointer to the new game state to be set.
 */
void Game::changeState(std::shared_ptr<IGameState> newState)
{
    // Clean up resources associated with the current state (if any).
    if(currentState)
    {
        currentState->cleanup();
    }

    // Set the current state to the new state.
    currentState = newState;

    // Initialize the new state.
    currentState->initialize();
}
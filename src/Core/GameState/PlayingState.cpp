#include"../../../include/Core/GameState/PlayingState.h"

/**
 * @brief Constructor for the PlayingState class.
 * 
 * This constructor initializes a PlayingState instance by creating a game object,
 * adding a graphics component to it, and configuring the player's rectangle.
 * 
 * @param game A reference to the Game instance to which this state belongs.
 */
PlayingState::PlayingState(Game& game)
{
    // Create a game object and add a graphics component to it.
    auto gameObject1 = game.getEntityManager().createEntity<GameObject>();
    gameObject1->addComponent(std::make_unique<GraphicsComponent>(game.getResourceManager(), "bird.png"));
    gameObjects.push_back(gameObject1);

    // Configure the player's rectangle.
    playerRect.setSize(sf::Vector2f(50.0f, 50.0f));
    playerRect.setFillColor(sf::Color::Green);
    playerVelocity = sf::Vector2f(200.0f, 0.0f);  // Movement speed in pixels per second
}

/**
 * @brief Initializes the PlayingState.
 * 
 * This function is called when the state is set as the current state.
 */
void PlayingState::initialize()
{
    // Implementation not provided in the current context.
}

/**
 * @brief Updates the PlayingState.
 * 
 * This function is called during each frame update to handle state-specific logic,
 * such as moving the player's rectangle based on the player's velocity.
 */
void PlayingState::update()
{
    // Calculate displacement based on player velocity and update player's position.
    float deltaTime = 1.0f / 60.0f;
    sf::Vector2f displacement = playerVelocity * deltaTime;
    playerRect.move(displacement);
}

/**
 * @brief Renders the PlayingState.
 * 
 * This function is responsible for rendering the player's rectangle and all game objects
 * associated with the state to the specified SFML window.
 * 
 * @param window The SFML window to render to.
 */
void PlayingState::render(sf::RenderWindow& window)
{
    // Draw the player's rectangle.
    window.draw(playerRect);
    
    // Render all game objects associated with the state.
    for (auto& gameobject : gameObjects)
    {
        if(auto gameObject = gameobject.lock())
        gameObject->render(window);
    }
}

/**
 * @brief Handles input for the PlayingState.
 * 
 * This function is responsible for handling input during the PlayingState,
 * such as toggling the direction of player movement on the press of the space key.
 * 
 * @param inputManager A reference to the InputManager for handling user input.
 */
void PlayingState::handleInput(InputManager& inputManager)
{
    // Toggle the direction of player movement on the press of the space key.
    if(inputManager.KeyDown(sf::Keyboard::Space))
    {
        playerVelocity.x *= -1.0f;
    }
}

/**
 * @brief Cleans up resources associated with the PlayingState.
 * 
 * This function is called when transitioning away from the PlayingState to
 * clean up any resources or perform any necessary cleanup tasks.
 */
void PlayingState::cleanup()
{
    // Implementation not provided in the current context.
}
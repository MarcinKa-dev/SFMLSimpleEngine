#pragma once

#include "Entity.h"
#include "Components/GraphicsComponent.h"

/**
 * @brief The GameObject class represents a game object with graphics components.
 * 
 * This class inherits from the Entity class and provides specific implementations
 * for the update and render functions.
 */
class GameObject : public Entity
{
public:
    // Default constructor for GameObject
    GameObject();
    
    // Virtual destructor for GameObject
    virtual ~GameObject() = default;

    /**
     * @brief Implementation of the update function for the GameObject.
     * 
     * This function is called to update the logic of the GameObject.
     * Override this function to define the specific logic for the GameObject.
     */
    void update() override;
    
    /**
     * @brief Implementation of the render function for the GameObject.
     * 
     * This function is called to render the GameObject to an SFML window.
     * Override this function to define the specific rendering for the GameObject.
     * 
     * @param window The SFML window to render the GameObject to.
     */
    void render(sf::RenderWindow& window) override;
};
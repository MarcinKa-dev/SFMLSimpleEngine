#pragma once

#include <SFML/Graphics.hpp>
#include "../Managers/ResourceManager.h"

class Entity;

/**
 * @brief The Component class represents a base class for game components.
 * 
 * This class defines the interface for game components with virtual functions
 * for updating and rendering the component within the context of a game entity.
 */
class Component
{
public:
    // Virtual destructor for Component
    virtual ~Component() = default;

    /**
     * @brief Virtual function to update the component within the context of a game entity.
     * 
     * This pure virtual function must be implemented by derived classes to handle
     * the logic update for the specific component within the context of the provided entity.
     * 
     * @param entity The game entity to which the component is attached.
     */
    virtual void update(Entity& entity) = 0;
    
    /**
     * @brief Virtual function to render the component within the context of a game entity.
     * 
     * This pure virtual function must be implemented by derived classes to handle
     * the rendering of the specific component within the context of the provided entity.
     * 
     * @param window The SFML window to render to.
     * @param entity The game entity to which the component is attached.
     */
    virtual void render(sf::RenderWindow& window, Entity& entity) = 0; 
};
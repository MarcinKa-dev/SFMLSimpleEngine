#pragma once
#include <SFML/Graphics.hpp>

/**
 * @brief The IEntity class defines the interface for game entities.
 * 
 * This class provides a base interface for game entities with virtual functions
 * for updating the entity's logic and rendering the entity to an SFML window.
 */
class IEntity
{
public:
    // Virtual destructor for the IEntity class
    virtual ~IEntity() = default;

    // Virtual function to update the entity's logic
    virtual void update() = 0;
    
    // Virtual function to render the entity to the specified SFML window
    virtual void render(sf::RenderWindow& window) = 0;
};
#pragma once

#include "../Component.h"
#include "string"

class GraphicsComponent : public Component
{
    public:
    /**
     * @brief Constructor for the GraphicsComponent class.
     * 
     * @param resourceManager A reference to the ResourceManager for handling resource loading.
     * @param texturePath The path to the texture file for the graphics component.
     */
    GraphicsComponent(ResourceManager& resourceManager, const std::string& texturePath);
    
    // Virtual destructor for GraphicsComponent
    virtual ~GraphicsComponent() = default;

    /**
     * @brief Implementation of the update function for the GraphicsComponent.
     * 
     * This function is called to update the logic of the GraphicsComponent within the context of a game entity.
     * 
     * @param entity The game entity to which the GraphicsComponent is attached.
     */
    void update(Entity& entity) override;
    
    /**
     * @brief Implementation of the render function for the GraphicsComponent.
     * 
     * This function is called to render the GraphicsComponent within the context of a game entity.
     * 
     * @param window The SFML window to render to.
     * @param entity The game entity to which the GraphicsComponent is attached.
     */
    void render(sf::RenderWindow& window, Entity& entity) override;
    
private:
    // SFML sprite for rendering the graphics component.
    sf::Sprite sprite;
    
    // Reference to the ResourceManager for handling resource loading.
    ResourceManager& resourceManager;
    
    // Path to the texture file for the graphics component.
    std::string texturePath;
};
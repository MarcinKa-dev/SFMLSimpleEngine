#include "../../../include/Entities/Components/GraphicsComponent.h"

/**
 * GraphicsComponent constructor
 * 
 * @param resourceManager A reference to the ResourceManager for handling resource loading.
 * @param texturePath The path to the texture file.
 */
GraphicsComponent::GraphicsComponent(ResourceManager& resourceManager, const std::string& texturePath) : 
    resourceManager(resourceManager), texturePath(texturePath)
{
    // Load the texture using the ResourceManager and set it on the sprite.
    sprite.setTexture(*resourceManager.loadTexture(texturePath));
}

//Update function for the GraphicsComponent.
void GraphicsComponent::update(Entity& entity)
{

}

//Render function for the GraphicsComponent.
void GraphicsComponent::render(sf::RenderWindow& window, Entity& entity)
{
    window.draw(sprite);
}
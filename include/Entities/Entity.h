#pragma once

#include "IEntity.h"
#include "Component.h"
#include <typeindex>
#include <memory>
#include "../Managers/EntityManager.h"

/**
 * @brief The Entity class represents a game entity with components.
 * 
 * This class inherits from IEntity and provides functionality for updating and rendering
 * the entity as well as managing its components.
 */
class Entity : public IEntity
{
public:
    // Default constructor for Entity
    Entity();

    // Virtual destructor for Entity
    virtual ~Entity() = default;
    
    /**
     * @brief Implementation of the update function for the Entity.
     * 
     * This function is called to update the logic of the Entity.
     * It iterates through all attached components and updates each one.
     */
    void update() override;
    
    /**
     * @brief Implementation of the render function for the Entity.
     * 
     * This function is called to render the Entity to an SFML window.
     * It iterates through all attached components and renders each one.
     * 
     * @param window The SFML window to render the Entity to.
     */
    void render(sf::RenderWindow& window) override;

    /**
     * @brief Adds a component to the Entity.
     * 
     * This function adds a unique pointer to a component to the Entity.
     * 
     * @param component A unique pointer to the Component to be added.
     */
    void addComponent(std::unique_ptr<Component> component);
    
    /**
     * @brief Removes a component from the Entity based on its type.
     * 
     * This function removes a component from the Entity based on its type.
     * 
     * @param type The type index of the Component to be removed.
     */
    void removeComponent(const std::type_index& type);

private:
    // Vector to store unique pointers to components associated with the Entity.
    std::vector<std::unique_ptr<Component>> components;
};
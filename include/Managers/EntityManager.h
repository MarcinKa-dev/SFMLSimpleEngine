#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>
#include "../Entities/Entity.h"
#include <iostream>

/**
 * @brief The EntityManager class manages entities in the game.
 * 
 * This class provides functionality to add, remove, update, and render entities.
 */
class EntityManager
{
public:
    // Default constructor for EntityManager
    EntityManager();

    /**
     * @brief Creates a new entity of the specified type and adds it to the manager.
     * 
     * This function creates a new entity of the specified type, adds it to the
     * EntityManager's list of entities, and returns a shared pointer to the new entity.
     * 
     * @tparam EntityType The type of entity to create.
     * @tparam Args Parameter pack for the entity constructor arguments.
     * @param args Arguments forwarded to the entity constructor.
     * @return std::shared_ptr<EntityType> A shared pointer to the newly created entity.
     */
    template <typename EntityType, typename... Args>
    std::shared_ptr<EntityType> createEntity(Args&&... args);
    
    //Removes the specified entity from the EntityManager.
    void removeEntity(Entity& entity);

    // Update all entities in the manager
    void update();

    // Render all entities in the manager to the specified SFML window
    void render(sf::RenderWindow& window);
private:
    // Vector to store shared pointers to entities
    std::vector<std::shared_ptr<Entity>> entities;
};

template <typename EntityType, typename... Args>
std::shared_ptr<EntityType> EntityManager::createEntity(Args&&... args)
{
    // Ensure that the provided EntityType is derived from the Entity class.
    static_assert(std::is_base_of<Entity, EntityType>::value, "EntityType must derive from Entity");

    // Create a new entity of the specified type.
    auto newEntity = std::make_shared<EntityType>(std::forward<Args>(args)...);
    
    // Add the new entity to the vector of entities.
    entities.push_back(newEntity);

    // Return a shared pointer to the newly created entity.
    return newEntity;
}
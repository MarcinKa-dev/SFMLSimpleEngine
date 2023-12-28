#include "../../include/Managers/EntityManager.h"

// Default constructor for EntityManager
EntityManager::EntityManager()
{
    // Implementation for any additional setup or initialization
}

void EntityManager::removeEntity(Entity& entity)
{
    // Find the entity in the entities vector using a lambda function.
    auto it = std::find_if(entities.begin(),entities.end(),[&](const auto& e) {return e.get() == &entity;});
    
    // Check if the entity was found.
    if(it != entities.end())
    {
        // If found, erase the entity from the vector.
        entities.erase(it);
    }
    else
    {
        // If not found, print a warning message.
        std::cerr << "Warning: Trying to remove an entity that does not exist in the EntityManager." << std::endl;
    }
}

// Update all entities in the manager
void EntityManager::update()
{
    // Iterate through all entities and update them
    for(auto& entity : entities)
    {
        entity->update();
    }
}

// Render all entities in the manager to the specified window
void EntityManager::render(sf::RenderWindow& window)
{
    // Iterate through all entities and render them
    for(auto& entity : entities)
    {
        entity->render(window);
    }
}
#include "../../include/Entities/Entity.h"

//Default constructor for the Entity class.
Entity::Entity()
{

}

//Update function for the Entity.
void Entity::update()
{
    for(auto& component : components)
    {
        component->update(*this);
    }
}

//Render function for the Entity.
void Entity::render(sf::RenderWindow& window)
{
    for(auto& component : components)
    {
        component->render(window, *this);
    }
}

//Adds a component to the Entity.
void Entity::addComponent(std::unique_ptr<Component> component)
{
    components.push_back(std::move(component));
}

/**
 * @brief Removes a component from the Entity based on its type.
 * 
 * This function removes the component from the list of components associated
 * with the entity based on its type. It uses type_index for comparison.
 * 
 * @param type The type_index of the component to be removed.
 */
void Entity::removeComponent(const std::type_index& type)
{
    // Use erase-remove_if idiom to remove the component based on its type.
    components.erase(std::remove_if(components.begin(), components.end(),
                    [type](const auto& component)
                    {
                        // Compare the type of the component with the specified type.
                        return std::type_index(typeid(*component.get())) == type;
                    }),
                    components.end());
}

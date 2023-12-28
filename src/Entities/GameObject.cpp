#include "../../include/Entities/GameObject.h"

//Default constructor for the GameObject class.
GameObject::GameObject()
{

}

//Update function for GameObject.
void GameObject::update()
{
    Entity::update();
}

//Render function for GameObject.
void GameObject::render(sf::RenderWindow& window)
{
    Entity::render(window);
}
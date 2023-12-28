#include "../../include/Managers/ResourceManager.h"

// Default constructor for ResourceManager
ResourceManager::ResourceManager()
{

}

// Default destructor for ResourceManager
ResourceManager::~ResourceManager()
{

}

// Load a texture from a file path
// If the texture is already loaded, return the existing shared pointer
// If the texture fails to load, return nullptr
std::shared_ptr<sf::Texture> ResourceManager::loadTexture(const std::string& filePath)
{
    // Check if the texture is already loaded
    auto it = textures.find(filePath);
    if(it != textures.end())
    {
        return it->second; // Return the existing texture
    }

    // If the texture is not loaded, load it from the file
    auto texture = std::make_shared<sf::Texture>();
    if(!texture->loadFromFile(filePath))
    {
        return nullptr; // Return nullptr if the texture fails to load
    }

    // Store the loaded texture in the map for future use
    textures[filePath] = texture;

    return texture;
}


// Load a sound from a file path
// If the sound is already loaded, return the existing shared pointer
// If the sound fails to load, return nullptr
std::shared_ptr<sf::SoundBuffer> ResourceManager::loadSound(const std::string& filePath)
{
    // Check if the soundBuffer is already loaded
    auto it = sounds.find(filePath);
    if(it != sounds.end())
    {
        return it->second; // Return the existing soundBuffer
    }

    // If the soundBuffer is not loaded, load it from the file
    auto sound = std::make_shared<sf::SoundBuffer>();
    if(!sound->loadFromFile(filePath))
    {
        return nullptr; // Return nullptr if the soundBuffer fails to load
    }

    // Store the loaded soundBuffer in the map for future use
    sounds[filePath] = sound;

    return sound;
}

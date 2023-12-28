#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <unordered_map>
#include <memory>

/**
 * @brief The ResourceManager class manages the loading and storage of game resources.
 * 
 * This class provides functionality to load textures and sound buffers from file paths,
 * storing them in unordered maps for efficient resource management.
 */
class ResourceManager {
public:

    // Default constructor for ResourceManager
    ResourceManager();

    // Default destructor for ResourceManager
    ~ResourceManager();

    /**
     * @brief Load a texture from a file path.
     * 
     * This function loads a texture from the specified file path.
     * If the texture is already loaded, it returns the existing shared pointer.
     * 
     * @param filePath The path to the texture file.
     * @return std::shared_ptr<sf::Texture> A shared pointer to the loaded texture.
     */
    std::shared_ptr<sf::Texture> loadTexture(const std::string& filePath);

    /**
     * @brief Load a sound buffer from a file path.
     * 
     * This function loads a sound buffer from the specified file path.
     * If the sound buffer is already loaded, it returns the existing shared pointer.
     * 
     * @param filePath The path to the sound file.
     * @return std::shared_ptr<sf::SoundBuffer> A shared pointer to the loaded sound buffer.
     */
    std::shared_ptr<sf::SoundBuffer> loadSound(const std::string& filePath);
private:
    // A map to store loaded textures. The key is the file path, and the value is a shared pointer to an SFML texture.
    std::unordered_map<std::string, std::shared_ptr<sf::Texture>> textures;
    
    // A map to store loaded sound buffers. The key is the file path, and the value is a shared pointer to an SFML sound buffer.
    std::unordered_map<std::string, std::shared_ptr<sf::SoundBuffer>> sounds;
};
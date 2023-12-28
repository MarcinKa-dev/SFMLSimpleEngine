#include "../../include/Managers/AudioManager.h"

// Default constructor for AudioManager
AudioManager::AudioManager(ResourceManager& resourceManager) : resourceManager(resourceManager)
{
    // Implementation for any additional setup or initialization
}

// Load audio from file and return a shared pointer to the corresponding IAudio interface
std::shared_ptr<IAudio> AudioManager::loadAudio(const std::string& filePath)
{
    // Check if the audio has already been loaded
    auto it = audioMap.find(filePath);
    if (it != audioMap.end()) {
        // Return existing audio if found
        return it->second;
    }

    // Load sound buffer from file
    auto soundBuffer = resourceManager.loadSound(filePath);
    if (soundBuffer) {
        // Create SFMLAudio object and add it to the map
        auto audio = std::make_shared<SFMLAudio>(*soundBuffer);
        audioMap[filePath] = audio;
        return audio;
    } else {
        // Return nullptr if loading failed
        return nullptr;
    }
}

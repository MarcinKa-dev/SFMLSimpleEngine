#pragma once
#include <unordered_map>
#include <memory>
#include "../Audio/IAudio.h"
#include "../Audio/SFMLAudio.h"
#include "ResourceManager.h"

class AudioManager
{
public:
    AudioManager(ResourceManager& resourceManager);

    // Load audio from file and return a shared pointer to the corresponding IAudio interface
    std::shared_ptr<IAudio> loadAudio(const std::string& filePath);

private:
    ResourceManager& resourceManager;
    // Map to store loaded audio, using file path as the key
    std::unordered_map<std::string, std::shared_ptr<IAudio>> audioMap;
};
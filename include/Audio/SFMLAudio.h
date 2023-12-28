#pragma once
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <memory>
#include "IAudio.h"

/**
 * @brief SFMLAudio class for handling audio using SFML.
 * 
 * This class implements the IAudio interface and provides functionality
 * for playing, stopping, and adjusting the volume of audio using SFML.
 */
class SFMLAudio : public IAudio
{
public:
    /**
     * @brief Constructor for SFMLAudio, initializing the sound and sound buffer.
     * 
     * @param buffer The sound buffer containing audio data.
     */
    SFMLAudio(const sf::SoundBuffer& buffer);
    
    /**
     * @brief Play the audio.
     * 
     * Implements the virtual function from the base interface.
     */
    void play() override;
    
    /**
     * @brief Stop playing the audio.
     * 
     * Implements the virtual function from the base interface.
     */
    void stop() override;
    
    /**
     * @brief Set the volume level for the audio.
     * 
     * Implements the virtual function from the base interface.
     * @param volume The volume level (0 to 100).
     */
    void setVolume(float volume) override;

private:
    // SFML sound object to manage audio playback
    sf::Sound sound;
};
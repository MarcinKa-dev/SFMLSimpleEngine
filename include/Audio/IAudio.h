#pragma once
#include <SFML/Audio.hpp>

/**
 * @brief Interface for handling audio functionality.
 */
class IAudio
{
public:
    // Virtual destructor for the IAudio interface
    virtual ~IAudio() = default;

    /**
     * @brief Virtual function to play the audio.
     * 
     * This pure virtual function must be implemented by derived classes
     * to handle playing of audio.
     */
    virtual void play() = 0;
    
    /**
     * @brief Virtual function to stop playing the audio.
     * 
     * This pure virtual function must be implemented by derived classes
     * to handle stopping of audio playback.
     */
    virtual void stop() = 0;
    
    /**
     * @brief Virtual function to set the volume level for the audio.
     * 
     * This pure virtual function must be implemented by derived classes
     * to handle adjusting the volume level of the audio.
     * 
     * @param volume The volume level (0 to 100).
     */
    virtual void setVolume(float volume) = 0;
};
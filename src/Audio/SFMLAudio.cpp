#include "../../include/Audio/SFMLAudio.h"

// Constructor for SFMLAudio, initializing the sound and sound buffer
SFMLAudio::SFMLAudio(const sf::SoundBuffer& buffer) 
{
    sound.setBuffer(buffer);
}

// Play the audio
void SFMLAudio::play()
{
    sound.play();
}

// Stop playing the audio
void SFMLAudio::stop()
{
    sound.stop();
}

// Set the volume level for the audio
void SFMLAudio::setVolume(float volume)
{
    sound.setVolume(volume);
}
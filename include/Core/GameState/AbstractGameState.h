#pragma once
#include "../IGameState.h"

/**
 * @brief The AbstractGameState class is a base class for game states with default implementations.
 * 
 * This class inherits from IGameState and provides default implementations for the initialize
 * and cleanup functions. It can be used as a convenient base class for specific game states.
 */
class AbstractGameState : public IGameState
{
public:
    /**
     * @brief Implementation of the initialize function for the AbstractGameState.
     * 
     * This function is empty and serves as a default implementation.
     */
    void initialize() override {}
    
    /**
     * @brief Implementation of the cleanup function for the AbstractGameState.
     * 
     * This function is empty and serves as a default implementation.
     */
    void cleanup() override {}
};
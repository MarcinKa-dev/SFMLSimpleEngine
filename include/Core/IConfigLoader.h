#pragma once

#include <string>

/**
 * @brief The IConfigLoader interface defines the contract for configuration file loaders.
 * 
 * This interface provides virtual functions for loading a configuration file and retrieving
 * configuration values of various types (int, float, string, bool) based on a key.
 */
class IConfigLoader
{
public:
    // Virtual destructor for IConfigLoader
    virtual ~IConfigLoader() = default;

    /**
     * @brief Virtual function to load the configuration file.
     * 
     * This pure virtual function must be implemented by derived classes to handle
     * the loading of the configuration file.
     * 
     * @return bool True if the configuration file is successfully loaded, false otherwise.
     */
    virtual bool LoadConfigFile() = 0;
    
    /**
     * @brief Virtual function to retrieve an integer configuration value based on a key.
     * 
     * This pure virtual function must be implemented by derived classes to provide
     * the integer value associated with the specified key in the configuration file.
     * 
     * @param key The key for the configuration value.
     * @return int The integer value associated with the key.
     */
    virtual int getInt(const std::string& key) const = 0;
    
    /**
     * @brief Virtual function to retrieve a floating-point configuration value based on a key.
     * 
     * This pure virtual function must be implemented by derived classes to provide
     * the floating-point value associated with the specified key in the configuration file.
     * 
     * @param key The key for the configuration value.
     * @return float The floating-point value associated with the key.
     */
    virtual float getFloat(const std::string& key) const = 0;
    
    /**
     * @brief Virtual function to retrieve a string configuration value based on a key.
     * 
     * This pure virtual function must be implemented by derived classes to provide
     * the string value associated with the specified key in the configuration file.
     * 
     * @param key The key for the configuration value.
     * @return std::string The string value associated with the key.
     */
    virtual std::string getString(const std::string& key) const = 0;
    
    /**
     * @brief Virtual function to retrieve a boolean configuration value based on a key.
     * 
     * This pure virtual function must be implemented by derived classes to provide
     * the boolean value associated with the specified key in the configuration file.
     * 
     * @param key The key for the configuration value.
     * @return bool The boolean value associated with the key.
     */
    virtual bool getBool(const std::string& key) const = 0;
};
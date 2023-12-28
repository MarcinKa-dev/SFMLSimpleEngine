#pragma once

#include "../IConfigLoader.h"
#include <nlohmann/json.hpp>
#include <fstream>
#include <iostream>

/**
 * @brief JSONConfigLoader class for loading configuration from a JSON file.
 * 
 * This class implements the IConfigLoader interface and provides functionality
 * to load configuration data from a JSON file.
 */
class JSONConfigLoader : public IConfigLoader
{
public:
    /**
     * @brief Constructor for JSONConfigLoader.
     * 
     * @param filePath The file path to the JSON configuration file.
     */
    JSONConfigLoader(const std::string& filePath);
    
    // Destructor for JSONConfigLoader
    ~JSONConfigLoader() = default;
    
    /**
     * @brief Load the configuration file.
     * 
     * Implements the virtual function from the base interface.
     * @return bool True if the configuration file is successfully loaded, false otherwise.
     */
    bool LoadConfigFile() override;
    
    /**
     * @brief Get an integer configuration value based on a key.
     * 
     * Implements the virtual function from the base interface.
     * @param key The key for the configuration value.
     * @return int The integer value associated with the key.
     */
    int getInt(const std::string& key) const override;
    
    // Get a float configuration value based on a key.
    float getFloat(const std::string& key) const override;

    // Get a string configuration value based on a key.
    std::string getString(const std::string& key) const override;

    // Get a boolean configuration value based on a key.
    bool getBool(const std::string& key) const override;
private:
    // JSON object to store configuration data
    nlohmann::json configData;
    
    // File path to the JSON configuration file
    std::string filePath;

    /**
     * @brief Initialize the default configuration.
     * 
     * This function sets default values and creates a new configuration file
     * if the specified file path is not valid.
     */
    void initializeDefaultConfig();
};
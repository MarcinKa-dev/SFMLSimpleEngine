#include "../../../include/Core/ConfigLoaders/JSONConfigLoader.h"

/**
 * @brief Constructor for the JSONConfigLoader class.
 * 
 * This constructor initializes a JSONConfigLoader instance with the specified file path.
 * It checks if the configuration file exists, and if not, initializes the default configuration.
 * 
 * @param filePath The path to the configuration file.
 */
JSONConfigLoader::JSONConfigLoader(const std::string& filePath) : filePath(filePath)
{
    // Check if the configuration file exists.
    std::ifstream configFile(filePath);

    // If the configuration file does not exist, initialize the default configuration.
    if(!configFile.good())
    {
        initializeDefaultConfig();
    }

    // Close the configuration file.
    configFile.close();
    
    // Load the configuration file.
    LoadConfigFile();
}

/**
 * @brief Loads the configuration file.
 * 
 * This function attempts to load the configuration file specified in the file path.
 * If successful, it reads the contents into the configData JSON object.
 * 
 * @return true if the configuration file is successfully loaded, false otherwise.
 */
bool JSONConfigLoader::LoadConfigFile()
{
    try
    {
        // Open the configuration file.
        std::ifstream configFile(filePath);

        // Read the contents of the file into the configData JSON object.
        configFile >> configData;
        
        // Close the configuration file.
        configFile.close();

        // Print an error message if an exception occurs during file loading.
        return true;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';

        return false;
    }
    
}

/**
 * @brief Retrieves an integer value from the configuration data.
 * 
 * This function retrieves an integer value associated with the specified key from the configData.
 * If the key is not found, a default value of 0 is returned.
 * 
 * @param key The key associated with the integer value in the configuration data.
 * @return The retrieved integer value.
 */
int JSONConfigLoader::getInt(const std::string& key) const
{
    return configData.value(key, 0);
}

/**
 * @brief Retrieves an float value from the configuration data.
 * 
 * This function retrieves an float value associated with the specified key from the configData.
 * If the key is not found, a default value of 0 is returned.
 * 
 * @param key The key associated with the float value in the configuration data.
 * @return The retrieved float value.
 */
float JSONConfigLoader::getFloat(const std::string& key) const
{
    return configData.value(key, 0.0f);
}

/**
 * @brief Retrieves an string value from the configuration data.
 * 
 * This function retrieves an string value associated with the specified key from the configData.
 * If the key is not found, a default an empty string is returned.
 * 
 * @param key The key associated with the string value in the configuration data.
 * @return The retrieved string value.
 */
std::string JSONConfigLoader::getString(const std::string& key) const
{
    return configData.value(key, "");
}

/**
 * @brief Retrieves an boolean value from the configuration data.
 * 
 * This function retrieves an boolean value associated with the specified key from the configData.
 * If the key is not found, false is returned.
 * 
 * @param key The key associated with the boolean value in the configuration data.
 * @return The retrieved boolean value.
 */
bool JSONConfigLoader::getBool(const std::string& key) const
{
    return configData.value(key, false);
}

/**
 * @brief Initializes the default configuration.
 * 
 * This function sets default values for various configuration parameters and writes
 * them to the configuration file. It is called when the configuration file is not found.
 */
void JSONConfigLoader::initializeDefaultConfig()
{
    // Set default values for various configuration parameters.
    configData["WindowWidth"] = 800;
    configData["WindowHeight"] = 600;
    configData["SoundVolume"] = 50.0f;
    configData["FullScreen"] = false;
    configData["FPSLimit"] = 60;
    configData["ScreenTitle"] = "Game Window";

    // Open the configuration file for writing.
    std::ofstream configFile(filePath);

    // Write the default configuration data to the file.
    configFile << std::setw(6) << configData << std::endl;
    
    // Close the configuration file.
    configFile.close();
}
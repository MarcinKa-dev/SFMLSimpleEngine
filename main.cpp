#include "include/Core/Game.h"
#include "include/Core/GameState/PlayingState.h"
#include "include/Core/ConfigLoaders/JSONConfigLoader.h"

int main()
{

    JSONConfigLoader configLoader("config.json");

    Game game(configLoader.getInt("WindowWidth"),configLoader.getInt("WindowHeight"),configLoader.getString("ScreenTitle"), configLoader.getInt("FPSLimit"));
    
    game.changeState(std::make_shared<PlayingState>(game));
    
    game.Run();
    return 0;
}
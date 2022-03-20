#include <iostream>

#include "/Users/gissellepetty/Desktop/cppStuff/SquidwardVenture/SquidwardVenture/HeaderFiles/Game.hpp"


int main()
{
    // Init Game Engine
    
    Game game;
    
    // Game Loop
    while (game.running())
    {
        // Event Polling
        
        // Update
        game.update();
        
        // Render
        game.render();
        // Draw your game
        
        
    }
    
    // End of Application
    return 0;
}

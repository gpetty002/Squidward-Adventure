#ifndef Game_hpp
#define Game_hpp

#include <iostream>
#include "SpriteMovements.hpp"
#include "MainMenu.hpp"
#include "GameMap.hpp"
#include "KrustyKrab.hpp"
#include "Intro_to_Krusty_Krab.hpp"
#include "Player.hpp"
#include "Styles.hpp"
#include "WinningScreen.hpp"

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

/*
    Class that acts as the Game Engine
    Wrapper Class.
 */

class Game
{
private:
    // Variables
    // Window
    sf::RenderWindow* window;
    sf::Event ev;
    sf::VideoMode videoMode;
    
    // Private Functions
    void initVariables();
    void initWindow();
public:

    // Game Screens
    MainMenu menu;
    GameMap gameMap;
    Intro_to_Krusty_Krab introKrustyKrab;
    KrustyKrab krustyKrab;
    WinningScreen winScreen;
    
    // Player Info
    Player player;
    
    // Styles
    Styles styles;
    
    // Constructors and Destructors
    Game();
    virtual ~Game();
    
    // Accessors
    const bool running() const;

    // Functions
    void pollEvents();
    void update();
    void render();

};

#endif /* Game_hpp */

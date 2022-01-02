#ifndef MainMenu_hpp
#define MainMenu_hpp

#include <iostream>
#include "SpriteMovements.hpp"

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

#include "Styles.hpp"

#define MAX_NUMBER_OF_ITEMS 3
#define FLOWERS_IN_MAIN 10

class MainMenu
{
public:
    // Constructor
    MainMenu();
    // Destructor
    virtual ~MainMenu();
    
    // Members
    float initial_xPos = 0.f;
    float initial_yPos = 450;
    
    bool onMainMenu = true;
    bool stillWalking = true;
    sf::Clock clock;
    sf::Clock secondClock;
    sf::Texture squidwardTexture;
    sf::Texture flowerTexture;
    sf::CircleShape flowers[FLOWERS_IN_MAIN];
//    sf::Sprite flowerSprite;
    sf::Text title;
    sf::RectangleShape titleBackground;
    sf::Text createdBy;
    sf::IntRect rectSourceSprite;
    SpriteMovements animations;
    sf::Sprite squidwardSprite;
    
    // Styles
    Styles styles;
    
    // Main Menu Music
    sf::Music music;
    
    // Functions
    void loadTextures(float width, float height, sf::RenderWindow &window);
    void displayMainMenu(sf::RenderWindow &window);
    void moveLeft();
    void moveRight();
    int getPressedBtn() { return selectedItemIndex; }
    
    void stopMusic() { music.stop(); }
    
private:
    int selectedItemIndex;
    sf::Font impact;
    sf::Font someTimeLaterFont;
    sf::Text menu[MAX_NUMBER_OF_ITEMS];
    sf::RectangleShape rectBtns[MAX_NUMBER_OF_ITEMS];
    
};

#endif /* MainMenu_hpp */

#ifndef GameMap_hpp
#define GameMap_hpp

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

#include "SpriteMovements.hpp"
#include "Player.hpp"
#include "Styles.hpp"

#include <iostream>

#define MAX_NUM_OF_LEVELS 5

using std::string;


class GameMap
{
public:
    
    // Constructors and Destructors
    GameMap();
    virtual ~GameMap();
    
    // Members
    bool onGameMap = false;
    bool stillMoving = false;
    bool up = false;
    bool down = false;
    bool left = false;
    bool right = false;
    sf::IntRect rectSourceSprite;
    sf::Clock clock;
    
    // Style Class
    Styles styles;
    
    // Game Map Music
    sf::Music music;
    sf::Music buttonEffect;
    
    // Functions
    void loadTextures(float width, float height, sf::RenderWindow &window);
    void displayGameMap(sf::RenderWindow &window, Player &player);
    void moveUp();
    void moveDown();
    void moveLeft();
    void moveRight();
    int getPressedBtn() { return selectedItemIndex; }
    void stopMusic() { music.stop(); }
    
private:
    int selectedItemIndex = 0;
    sf::Font impactFont;
    sf::Texture background;
    sf::Sprite bg;
    sf::Texture squidwardTexture;
    sf::Font someTimeLater;
    sf::Sprite squidwardSprite;
    sf::Text playerLivesLeft;
    sf::Text playerLevelsLeft;
    sf::CircleShape levels[MAX_NUM_OF_LEVELS];
};

#endif /* GameMap_hpp */

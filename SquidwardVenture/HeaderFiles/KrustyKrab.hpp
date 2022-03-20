#ifndef KrustyKrab_hpp
#define KrustyKrab_hpp

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

#include "Styles.hpp"
#include <vector>

#define MAX_NUM_OF_INGREDIENTS 5
#define INGREDIENT_BUTTONS 9

using std::vector;

class KrustyKrab
{
public:
    // Constructor
    KrustyKrab();
    // Destructror
    virtual ~KrustyKrab();
    
    // Members
    bool onKrustyKrab = false;
    bool onTutorialWindow = true;
    sf::RectangleShape okayButton;
    sf::Sprite ingredientButtons[INGREDIENT_BUTTONS];
    sf::Sprite tutorialWindow;
    sf::Texture textBox;
    sf::Text okayString;
    sf::Text directions[4];
    sf::Text clockText;

    std::vector<sf::Sprite> krabbyPatties;
    
    // Styles
    Styles styles;
    
    sf::Clock clock;
    sf::Music music;
    int customers = 7;
    int num_seconds = 55;
    int drawPattyClicks = 0;
    int secondsAfterRawPatty[4];
    
    // Functions
    void loadTextures(sf::RenderWindow &window);
    void displayKrustyKrab(sf::RenderWindow &window, sf::Mouse m);
    void movePatty(sf::Sprite s);

    void endOfGame();
    void stopMusic() { music.stop(); }
    
    int getPressedBtn() { return selectedItemIndex; }
    
    
private:
    int selectedItemIndex;
    sf::Font someTimeLaterFont;
    sf::Font impact;
    
    sf::Texture bgTexture;
    sf::Texture squidwardTexture;
    
    sf::Texture perfectPattyTexture;
    sf::Texture rawPattyTexture;
    sf::Texture burntPattyTexture;
    sf::Texture cheeseTexture;
    sf::Texture lettuceTexture;
    sf::Texture picklesTexture;
    sf::Texture ketchupTexture;
    sf::Texture mustardTexture;
    sf::Texture mayoTexture;
    sf::Texture topBunTexture;
    sf::Texture botBunTexture;
    
    // stack textures
    sf::Texture botBunStackTexture;
    sf::Texture cheeseStackTexture;
    sf::Texture picklesStackTexture;
    sf::Texture lettuceStackTexture;
    sf::Texture pattiesStackTexture;
    sf::Texture topBunStackTexture;
    
    // sprites
    sf::Sprite bg;
    sf::Sprite squidwardSprite;
    sf::Sprite ingredients[MAX_NUM_OF_INGREDIENTS];
    sf::Sprite rawPatties[4];
    sf::Sprite perfectPatties[4];
    sf::Sprite burntPatties[4];
};

#endif /* KrustyKrab_hpp */

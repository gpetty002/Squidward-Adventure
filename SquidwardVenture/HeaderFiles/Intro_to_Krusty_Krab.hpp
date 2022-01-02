#ifndef Intro_to_Krusty_Krab_hpp
#define Intro_to_Krusty_Krab_hpp

#include <iostream>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

#define NUM_OF_DIALOGUE_TEXTBOXES 8

#include "Styles.hpp"

class Intro_to_Krusty_Krab
{
public:
    
    // Members
    bool onIntroScreen = false;
    sf::Clock clock;
    sf::Music music;
    int selectedItemIndex;
    
    // Styles
    Styles styles;
    
    // Functions
    void loadTextures(sf::RenderWindow &window);
    void displayIntroScreen(sf::RenderWindow &window);
    void stopMusic() { music.stop(); }
    int getPressedBtn() { return selectedItemIndex; }
    
private:
    sf::Font someTimeLater;
    sf::Font impactFont;
    
    sf::Sprite squidward;
    sf::Sprite textBox;
    sf::Sprite krabs;
    sf::Sprite bg;
    
    sf::Texture textBoxTexture;
    sf::Texture krabsTexture;
    sf::Texture squidwardTexture;
    sf::Texture bgTexture;
    
    sf::Text dialogueBox[NUM_OF_DIALOGUE_TEXTBOXES];
    
};

#endif /* Intro_to_Krusty_Krab_hpp */

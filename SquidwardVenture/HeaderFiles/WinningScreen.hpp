#ifndef WinningScreen_hpp
#define WinningScreen_hpp

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

#include "Styles.hpp"
#include <vector>


class WinningScreen 
{
    public:
        // Constructor
        WinningScreen();
        // Destructor
        virtual ~WinningScreen();

        // Members
        bool onWinningScreen = false;
        sf::Text congrats[4];
        sf::Music music;

        // Styles
        Styles styles;


        // Functions
        void loadTextures(sf::RenderWindow &window);
        void displayWinScreen(sf::RenderWindow &window, sf::Mouse m);


    private:
        // Textures
        sf::Texture bgTexture;
        sf::Texture window_Texture;
        sf::Font impact;

        // Sprites
        sf::Sprite bg;
        sf::Sprite mini_Window;
};

#endif
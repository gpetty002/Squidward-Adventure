#include "/Users/gissellepetty/Desktop/cppStuff/SquidwardVenture/SquidwardVenture/HeaderFiles/WinningScreen.hpp"

WinningScreen::WinningScreen(){}
WinningScreen::~WinningScreen(){}

void WinningScreen::loadTextures(sf::RenderWindow &window)
{
    bgTexture.loadFromFile(styles.win_image);
    window_Texture.loadFromFile(styles.krustyKrabTextBox_ImgPath);
    if (!impact.loadFromFile(styles.impact_Font))
    {
        // handle error
        std::cout << "could not load some-time-later font" << std::endl;
    }

    // Audio
    if (!music.openFromFile(styles.cocktail_audio))
    {
        std::cout << "cannot play cocktail_Lounge.wav file" << std::endl;
    }

    bg.setTexture(bgTexture);
    mini_Window.setTexture(window_Texture);
    mini_Window.setPosition(sf::Vector2f(200, 20));

    congrats[0].setString("YOU WON! You get the rest of the");
    congrats[0].setCharacterSize(40);
    congrats[0].setFont(impact);
    congrats[0].setFillColor(styles.sb_Blue);
    congrats[0].setPosition(sf::Vector2f(530, 470));

    congrats[1].setString("day off! Don't forget to comeback");
    congrats[1].setCharacterSize(40);
    congrats[1].setFont(impact);
    congrats[1].setFillColor(styles.sb_Blue);
    congrats[1].setPosition(sf::Vector2f(530, 520));

    congrats[2].setString("to work again tomorrow! Thanks for");
    congrats[2].setCharacterSize(40);
    congrats[2].setFont(impact);
    congrats[2].setFillColor(styles.sb_Blue);
    congrats[2].setPosition(sf::Vector2f(530, 570));

    congrats[3].setString("playing!");
    congrats[3].setCharacterSize(40);
    congrats[3].setFont(impact);
    congrats[3].setFillColor(styles.sb_Blue);
    congrats[3].setPosition(sf::Vector2f(530, 620));

    music.play();
}

void WinningScreen::displayWinScreen(sf::RenderWindow &window, sf::Mouse m)
{
    window.draw(bg);
    window.draw(mini_Window);

    for (int i = 0; i < 4; i++)
    {
        window.draw(congrats[i]);
    }
}
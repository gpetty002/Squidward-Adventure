#include "GameMap.hpp"

// helper function for squidward sprite

void squidwardMovements(sf::IntRect *r)
{
    switch (r->left) {
        case 0:
            r->left = 100;
            break;
        case 100:
            r->left = 190;
            break;
        case 190:
            r->left = 280;
            r->width = 80;
            break;
        case 280:
            r->left = 350;
            r->width = 75;
            break;
        case 350:
            r->left = 420;
            r->width = 90;
            break;
        case 420:
            r->left = 510;
            break;
        case 510:
            r->left = 590;
            r->width = 80;
            break;
        case 590:
            r->left = 670;
            r->width = 70;
            break;
        case 670:
            r->left = 740;
            r->width = 70;
            break;
        case 740:
            r->left = 0;
            r->width = 100;
            break;
    }
}


// Constructor and Destructor
GameMap::GameMap(){}
GameMap::~GameMap(){}

void GameMap::loadTextures(float width, float height, sf::RenderWindow &window)
{
    // Background of GameMap set up
    if (!someTimeLater.loadFromFile(styles.some_time_later_Font))
    {
        // handle error
        std::cout << "could not load some-time-later font" << std::endl;
    }
    
    if (!impactFont.loadFromFile(styles.impact_Font))
    {
        // handle error
        std::cout << "could not load impact.ttf font" << std::endl;
    }
    
    background.loadFromFile(styles.gameMapImgPath);
    
    bg.setTexture(background);
    
    if (!music.openFromFile(styles.gameMap_audio))
    {
        std::cout << "cannot play game_map_music.wav file" << std::endl;
    }
    
    // squidward sprite
    squidwardTexture.loadFromFile(styles.squidGameMapPath);
    
    rectSourceSprite.height = 114;
    rectSourceSprite.width = 100;
    rectSourceSprite.top = 20;
    squidwardSprite.setTextureRect(rectSourceSprite);
    squidwardSprite.setTexture(squidwardTexture);
    squidwardSprite.setPosition(300, 735);
    squidwardSprite.setScale(1.5, 1.5);
    
    // gameMap blue level circles
    
    for (int i = 0; i < MAX_NUM_OF_LEVELS; i++)
    {
        levels[i].setRadius(30);
        levels[i].setFillColor(styles.sb_Blue);
    }
    
    levels[0].setFillColor(sf::Color::White);
    levels[0].setPosition(sf::Vector2f(340, 810));
    levels[1].setPosition(sf::Vector2f(340, 720));
    levels[2].setPosition(sf::Vector2f(640, 725));
    levels[3].setPosition(sf::Vector2f(640, 810));
    levels[4].setPosition(sf::Vector2f(1050, 810));
    
    playerLivesLeft.setFont(someTimeLater);
    playerLivesLeft.setFillColor(styles.creamColor);
    playerLivesLeft.setString("LIVES LEFT: ");
    playerLivesLeft.setCharacterSize(55);
    playerLivesLeft.setPosition(sf::Vector2f(235, 980));
    
    playerLevelsLeft.setFont(someTimeLater);
    playerLevelsLeft.setFillColor(styles.creamColor);
    playerLevelsLeft.setString("LEVELS LEFT: ");
    playerLevelsLeft.setCharacterSize(55);
    playerLevelsLeft.setPosition(sf::Vector2f(680, 980));
        
    
    // play music
    music.play();
    
}

void GameMap::displayGameMap(sf::RenderWindow &window, Player &player)
{
    sf::Text travel_to_any_place;
    travel_to_any_place.setString("Travel to any place on the map using");
    travel_to_any_place.setCharacterSize(30);
    travel_to_any_place.setFillColor(styles.sb_Blue);
    travel_to_any_place.setFont(impactFont);
    travel_to_any_place.setPosition(sf::Vector2f(760, 380));
    
    sf::Text place_Text;
    place_Text.setCharacterSize(30);
    place_Text.setString("the left, right, up, and down arrows");
    place_Text.setFillColor(styles.sb_Blue);
    place_Text.setFont(impactFont);
    place_Text.setPosition(sf::Vector2f(770, 430));
    
    window.draw(bg);
    window.draw(squidwardSprite);
    window.draw(travel_to_any_place);
    window.draw(place_Text);
    
    for (int i = 0; i < MAX_NUM_OF_LEVELS; i++)
    {
        window.draw(levels[i]);
    }
    
    if (clock.getElapsedTime().asMilliseconds() > 45.0f)
    {
        if (up)
        {
            if (selectedItemIndex == 1 || selectedItemIndex == 2)
            {
                if (squidwardSprite.getPosition().y != 615)
                {
                    squidwardMovements(&rectSourceSprite);
                    squidwardSprite.setPosition(squidwardSprite.getPosition().x, squidwardSprite.getPosition().y - 10.0f);
                    squidwardSprite.setTextureRect(rectSourceSprite);
                } else {
                    up = false;
                }
            }
        } else if (down)
        {
            if (selectedItemIndex == 0 || selectedItemIndex == 3)
            {
                if (squidwardSprite.getPosition().y != 715)
                {
                    squidwardMovements(&rectSourceSprite);
                    squidwardSprite.setPosition(squidwardSprite.getPosition().x, squidwardSprite.getPosition().y + 10.0f);
                    squidwardSprite.setTextureRect(rectSourceSprite);
                } else {
                    down = false;
                }
            }
        } else if (left)
        {
            if (selectedItemIndex == 1)
            {
                if (squidwardSprite.getPosition().x != 330)
                {
                    squidwardMovements(&rectSourceSprite);
                    squidwardSprite.setPosition(squidwardSprite.getPosition().x - 10.0f, squidwardSprite.getPosition().y);
                    squidwardSprite.setTextureRect(rectSourceSprite);
                } else {
                    left = false;
                }
            }
        } else if (right)
        {
            if (selectedItemIndex == 2)
            {
                if (squidwardSprite.getPosition().x != 630)
                {
                    squidwardMovements(&rectSourceSprite);
                    squidwardSprite.setPosition(squidwardSprite.getPosition().x + 10.0f, squidwardSprite.getPosition().y);
                    squidwardSprite.setTextureRect(rectSourceSprite);
                } else {
                    right = false;
                }
            }
        }
        clock.restart();
    }
    
    sf::Text numLives;
    sf::Text numLevels;
    
    numLives.setString(std::to_string(player.livesLeft));
    numLives.setFont(someTimeLater);
    numLives.setCharacterSize(55);
    numLives.setFillColor(styles.creamColor);
    numLives.setPosition(sf::Vector2f(490, 980));
    
    numLevels.setString(std::to_string(player.levelsLeft));
    numLevels.setFont(someTimeLater);
    numLevels.setCharacterSize(55);
    numLevels.setFillColor(styles.creamColor);
    numLevels.setPosition(sf::Vector2f(970, 980));
    
    window.draw(squidwardSprite);
    window.draw(playerLivesLeft);
    window.draw(playerLevelsLeft);
    
    
    window.draw(numLives);
    window.draw(numLevels);
    
}





// Sprite Controls

void GameMap::moveUp()
{
    if (selectedItemIndex == 0 || selectedItemIndex == 4 || selectedItemIndex == 6 || selectedItemIndex == 11)
    {
        // Increment
        if (selectedItemIndex + 1 < MAX_NUM_OF_LEVELS)
        {
            stillMoving = true;
            up = true;
            levels[selectedItemIndex].setFillColor(styles.sb_Blue);
            selectedItemIndex++;
            levels[selectedItemIndex].setFillColor(sf::Color::White);
        }
    } else if (selectedItemIndex == 3 || selectedItemIndex == 10)
    {
        // Decrement
        stillMoving = true;
        up = true;
        levels[selectedItemIndex].setFillColor(styles.sb_Blue);
        selectedItemIndex--;
        levels[selectedItemIndex].setFillColor(sf::Color::White);
    }
    levels[selectedItemIndex].setFillColor(sf::Color::White);
}

void GameMap::moveDown()
{
    levels[selectedItemIndex].setFillColor(styles.sb_Blue);
    
    // only places that are going down but also incrementing the selectedItemIndex value
    if (selectedItemIndex == 2 || selectedItemIndex == 9)
    {
        if (selectedItemIndex + 1 < MAX_NUM_OF_LEVELS)
        {
            levels[selectedItemIndex].setFillColor(styles.sb_Blue);
            selectedItemIndex++;
                    levels[selectedItemIndex].setFillColor(sf::Color::White);
            down = true;
        }
        
    } else if (selectedItemIndex == 1 || selectedItemIndex == 5 || selectedItemIndex == 8 || selectedItemIndex == 12)
    {
        // places that are going down but also decrementing the selectedItemIndex value
        if (selectedItemIndex - 1 >= 0)
        {
            down = true;
            levels[selectedItemIndex].setFillColor(styles.sb_Blue);
            selectedItemIndex--;
            levels[selectedItemIndex].setFillColor(sf::Color::White);
        }
    }
    levels[selectedItemIndex].setFillColor(sf::Color::White);
    
}

void GameMap::moveLeft()
{
    if (selectedItemIndex == 5)
    {
        levels[selectedItemIndex].setFillColor(styles.sb_Blue);
        selectedItemIndex++;
        levels[selectedItemIndex].setFillColor(sf::Color::White);
        left = true;
    } else if (selectedItemIndex == 2 || selectedItemIndex == 4 || selectedItemIndex == 9 || selectedItemIndex == 11)
    {
        if (selectedItemIndex - 1 >= 0)
        {
            left = true;
            levels[selectedItemIndex].setFillColor(styles.sb_Blue);
            selectedItemIndex--;
            levels[selectedItemIndex].setFillColor(sf::Color::White);
        }
    }
    levels[selectedItemIndex].setFillColor(sf::Color::White);
}

void GameMap::moveRight()
{
    if (selectedItemIndex == 6)
    {
        right = true;
        levels[selectedItemIndex].setFillColor(styles.sb_Blue);
        selectedItemIndex--;
        levels[selectedItemIndex].setFillColor(sf::Color::White);
    } else if (selectedItemIndex == 1 || selectedItemIndex == 3 || selectedItemIndex == 8 || selectedItemIndex == 10 || selectedItemIndex == 12)
    {
        if (selectedItemIndex + 1 < MAX_NUM_OF_LEVELS)
        {
            right = true;
            levels[selectedItemIndex].setFillColor(styles.sb_Blue);
            selectedItemIndex++;
            levels[selectedItemIndex].setFillColor(sf::Color::White);
        }
    }
    levels[selectedItemIndex].setFillColor(sf::Color::White);
}



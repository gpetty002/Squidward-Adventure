#include "/Users/gissellepetty/Desktop/cppStuff/SquidwardVenture/SquidwardVenture/HeaderFiles/Game.hpp"

bool buttonClicked(sf::RectangleShape r, sf::Mouse m, sf::RenderWindow &w)
{

    int m_Xpos = m.getPosition(w).x;
    int m_Ypos = m.getPosition(w).y;
    
    
    // check if mouse click is in bounds
    if (m_Xpos >= r.getPosition().x && m_Xpos <= (r.getPosition().x + r.getSize().x))
    {
        if (m_Ypos >= r.getPosition().y && m_Ypos <= (r.getPosition().y + r.getSize().y))
        {
            return true;
        }
    }
    return false;
}

bool spriteClicked(sf::Sprite s, sf::Mouse m, sf::RenderWindow &w)
{
    // set up mouse float position
    float m_Xpos = m.getPosition(w).x;
    float m_Ypos = m.getPosition(w).y;
    
    // create new mouse vector based on position
    sf::Vector2f m_vector(m_Xpos, m_Ypos);
    
    sf::FloatRect bounds = s.getGlobalBounds();
    
    // check if the mouse click within the sprite's bounds
    if (bounds.contains(m_vector))
    {
        // mouse clicked on sprite's location
        return true;
    }
    return false;
}

/*
bool spriteClicked(sf::Sprite s, sf::Mouse m, sf::RenderWindow &w)
{
    // set up mouse float position
    float m_Xpos = m.getPosition(w).x;
    float m_Ypos = m.getPosition(w).y;
    
    // create new mouse vector based on position
    sf::Vector2f m_vector(m_Xpos, m_Ypos);
    
    sf::FloatRect bounds = s.getGlobalBounds();
    
    // check if the mouse click is within the sprite's bounds
    if (bounds.contains(m_vector))
    {
        // mouse on sprite
        return true;
    }
    return false;
}
*/
 
// Private Functions
void Game::initVariables()
{
    this->window = nullptr;
    
}

void Game::initWindow()
{
    this->videoMode.height = 1080;
    this->videoMode.width = 1280;
    this->window = new sf::RenderWindow (this->videoMode, "Squidward's Adventure", sf::Style::Titlebar | sf::Style::Close);
    menu.loadTextures(window->getSize().x, window->getSize().y, *window);
}

// Constructors and Destructors
Game::Game()
{
    this->initVariables();
    this->initWindow();
}


Game::~Game()
{
    delete this->window;
}

// Accessors

const bool Game::running() const
{
    return this->window->isOpen();
}

// Functions

void Game::pollEvents()
{
    while(window->pollEvent(this->ev))
    {
        switch(this->ev.type)
        {
            case sf::Event::Closed:
                this->window->close();
                break;
                
            case sf::Event::KeyPressed:
                if (this->ev.key.code == sf::Keyboard::Escape)
                    this->window->close();
                break;
                
            case sf::Event::KeyReleased:
                
                if (menu.onMainMenu)
                {
                    switch (ev.key.code)
                    {
                        case sf::Keyboard::Right:
                            menu.moveRight();
                            break;
                        case sf::Keyboard::Left:
                            menu.moveLeft();
                            break;
                        case sf::Keyboard::Return:
                            switch (menu.getPressedBtn())
                            {
                                case 0:
                                    menu.onMainMenu = false;
                                    menu.stopMusic();
                                    break;
                                
                                case 1:
                                    menu.onMainMenu = false;
                                    gameMap.onGameMap = true;
                                    gameMap.loadTextures(window->getSize().x, window->getSize().y, *window);
                                    menu.stopMusic();
                                    menu.buttonEffect.play();
                                    break;
                                
                                case 2:
                                    window->close();
                                    break;
                            }
                            break;
                    }
                }
                if (gameMap.onGameMap)
                {
                    switch(ev.key.code)
                    {
                        case sf::Keyboard::Right:
                            gameMap.moveRight();
                            break;
                        case sf::Keyboard::Left:
                            gameMap.moveLeft();
                            break;
                        case sf::Keyboard::Up:
                            gameMap.moveUp();
                            break;
                        case sf::Keyboard::Down:
                            gameMap.moveDown();
                            break;
                        case sf::Keyboard::Return:
                            switch (gameMap.getPressedBtn())
                            {
                                case 1:
                                    gameMap.onGameMap = false;
                                    introKrustyKrab.onIntroScreen = true;
                                    introKrustyKrab.loadTextures(*window);
                                    gameMap.buttonEffect.play();
                                    gameMap.stopMusic();
                                    break;
                            }
                            break;
                    }
                }
            
            case sf::Event::MouseButtonPressed:
                if (introKrustyKrab.onIntroScreen)
                {
                    // we're going to move forward in the character dialogue by simpling clicking the screen
                    introKrustyKrab.selectedItemIndex++;
                    if (introKrustyKrab.selectedItemIndex == 8)
                    {
                        introKrustyKrab.onIntroScreen = false;
                        krustyKrab.onKrustyKrab = true;
                        krustyKrab.loadTextures(*window);
                        introKrustyKrab.stopMusic();
                        break;
                    }
                } else if (krustyKrab.onKrustyKrab)
                {
                    sf::Mouse m;
                    if (buttonClicked(krustyKrab.okayButton, m, *window))
                    {
                        krustyKrab.onTutorialWindow = false;
                    } else if (spriteClicked(krustyKrab.ingredientButtons[0], m, *window))
                    {
                        krustyKrab.foodFallingEffect.play();
                        krustyKrab.drawPattyClicks++;

                        if (krustyKrab.drawPattyClicks > 4)
                        {
                            krustyKrab.drawPattyClicks = 4;
                        }
                        
                        switch (krustyKrab.drawPattyClicks)
                        {
                        case 1:
                            krustyKrab.secondsAfterRawPatty[0] = krustyKrab.num_seconds;
                            krustyKrab.onGrill[0] = true;
                            break;
                        case 2:
                            krustyKrab.secondsAfterRawPatty[1] = krustyKrab.num_seconds;
                            krustyKrab.onGrill[1] = true;
                            break;
                        case 3:
                            krustyKrab.secondsAfterRawPatty[2] = krustyKrab.num_seconds;
                            krustyKrab.onGrill[2] = true;
                            break;
                        case 4:
                            krustyKrab.secondsAfterRawPatty[3] = krustyKrab.num_seconds;
                            krustyKrab.onGrill[3] = true;
                            break;
                        default:
                            break;
                        }
                    } else if ((spriteClicked(krustyKrab.krabbyPatties[3], m, *window)) && (krustyKrab.passedTime[3] >= 8))
                    {
                        krustyKrab.onGrill[3] = false;
                        krustyKrab.movingPatty[3] = true;
                    } else if ((spriteClicked(krustyKrab.krabbyPatties[2], m, *window)) && (krustyKrab.passedTime[2] >= 8))
                    {
                        krustyKrab.onGrill[2] = false;
                        krustyKrab.movingPatty[2] = true;
                        krustyKrab.foodFallingEffect.play();
                    } else if ((spriteClicked(krustyKrab.krabbyPatties[1], m, *window)) && (krustyKrab.passedTime[1] >= 8))
                    {
                        krustyKrab.onGrill[1] = false;
                        krustyKrab.movingPatty[1] = true;
                        krustyKrab.foodFallingEffect.play();
                    } else if ((spriteClicked(krustyKrab.krabbyPatties[0], m, *window)) && (krustyKrab.passedTime[0] >= 8))
                    {
                        krustyKrab.onGrill[0] = false;
                        krustyKrab.movingPatty[0] = true;
                        krustyKrab.foodFallingEffect.play();
                    } else if (spriteClicked(krustyKrab.ingredientButtons[4], m, *window))
                    {
                        // Check clicks for Cheese

                        krustyKrab.drawCheeseClicks++;
                        krustyKrab.foodFallingEffect.play();

                        if (krustyKrab.drawCheeseClicks > 4)
                            krustyKrab.drawCheeseClicks = 4;

                    } else if (spriteClicked(krustyKrab.ingredientButtons[5], m, *window))
                    {
                        // Check clicks for Lettuce

                        krustyKrab.drawLettuceClicks++;

                        krustyKrab.foodFallingEffect.play();

                        if (krustyKrab.drawLettuceClicks > 4)
                            krustyKrab.drawLettuceClicks = 4;
                    } else if (spriteClicked(krustyKrab.ingredientButtons[8], m, *window))
                    {
                        krustyKrab.drawTopBunsClicks++;

                        if (krustyKrab.drawTopBunsClicks >= 4)
                        {
                            krustyKrab.drawTopBunsClicks = 4;
                            krustyKrab.finishedGame = true;
                        }
                    } else if (buttonClicked(krustyKrab.submitButton, m, *window))
                    {
                        krustyKrab.onKrustyKrab = false;
                        krustyKrab.bubbles.play();
                        krustyKrab.music.stop();
                        krustyKrab.grillingEffect.stop();
                        winScreen.onWinningScreen = true;
                        winScreen.loadTextures(*window);

                    }

                }
                break;
        }
    }
}

void Game::update()
{
    // Event Polling
    this->pollEvents();
}

void Game::render()
{
    /*
        - clear old frame
        - render objects
        - display frame in window
     
        Renders the Game Objects
     */
    
    // Draw Game Objects
    this->window->clear(sf::Color::Black);
    
    if (menu.onMainMenu)
    {
        this->window->clear(sf::Color::White);
        menu.displayMainMenu(*window);
        
    } else if (gameMap.onGameMap)
    {
        this->window->clear(sf::Color::Black);
        gameMap.displayGameMap(*window, player);
    } else if (introKrustyKrab.onIntroScreen)
    {
        this->window->clear(sf::Color::Black);
        introKrustyKrab.displayIntroScreen(*window);
    } else if (krustyKrab.onKrustyKrab)
    {
        this->window->clear();
        sf::Mouse m;
        krustyKrab.displayKrustyKrab(*window, m);
    } else if (winScreen.onWinningScreen)
    {
        this->window->clear();
        sf::Mouse m;
        winScreen.displayWinScreen(*window,m);
    }
    
    this->window->display();
}

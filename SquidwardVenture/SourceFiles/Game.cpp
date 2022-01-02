#include "Game.hpp"

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
                        krustyKrab.drawPattyClicks++;
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
    }
    
    this->window->display();
}

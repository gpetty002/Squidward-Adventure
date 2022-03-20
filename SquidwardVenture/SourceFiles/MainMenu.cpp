#include "/Users/gissellepetty/Desktop/cppStuff/SquidwardVenture/SquidwardVenture/HeaderFiles/MainMenu.hpp"


MainMenu::MainMenu(){}
MainMenu::~MainMenu(){}



void MainMenu::loadTextures(float width, float height, sf::RenderWindow &window)
{
    if (!impact.loadFromFile(styles.impact_Font))
    {
        // handle error
        std::cout << "could not load impact font" << std::endl;
    }

    
    if (!someTimeLaterFont.loadFromFile(styles.some_time_later_Font))
    {
        // handle error
        std::cout << "could not load some-time-later font" << std::endl;
    }
    
    if (!flowerTexture.loadFromFile(styles.flowerImgPath))
    {
        // handle error
        std::cout << "could not load skyFlowers texture" << std::endl;
    }
    
    int newHeight = height - 300;
    float rect_X_Size = 250.f + 80.f;
    float rect_Y_Size = 100.f;
    
    menu[0].setFont(someTimeLaterFont);
    menu[0].setFillColor(styles.sb_Yellow);
    menu[0].setString("OPTIONS");
    menu[0].setCharacterSize(60);
    menu[0].setStyle(sf::Text::Bold);
    menu[0].setPosition(sf::Vector2f(150, newHeight));
    
    menu[1].setFont(someTimeLaterFont);
    menu[1].setFillColor(sf::Color::White);
    menu[1].setString("START");
    menu[1].setCharacterSize(60);
    menu[1].setStyle(sf::Text::Bold);
    menu[1].setPosition(sf::Vector2f(580, newHeight));

    menu[2].setFont(someTimeLaterFont);
    menu[2].setFillColor(sf::Color::White);
    menu[2].setString("EXIT");
    menu[2].setCharacterSize(60);
    menu[2].setStyle(sf::Text::Bold);
    menu[2].setPosition(sf::Vector2f(1010, newHeight));
    
    
    // Rectangles for Options, Start, and Exit buttons
    
    rectBtns[0].setSize(sf::Vector2f(rect_X_Size-15, rect_Y_Size));
    rectBtns[0].setFillColor(styles.sb_Blue);
    rectBtns[0].setPosition(sf::Vector2f(100, newHeight - 15));
    
    rectBtns[1].setSize(sf::Vector2f(rect_X_Size-15, rect_Y_Size));
    rectBtns[1].setFillColor(styles.sb_Blue);
    rectBtns[1].setPosition(sf::Vector2f(500, newHeight - 15));
    
    rectBtns[2].setSize(sf::Vector2f(rect_X_Size-15, rect_Y_Size));
    rectBtns[2].setFillColor(styles.sb_Blue);
    rectBtns[2].setPosition(sf::Vector2f(900, newHeight - 15));
    
    // Title and my name on project
    title.setString("Squidward's Adventure");
    title.setFont(someTimeLaterFont);
    title.setCharacterSize(100);
    title.setPosition(150, 150);
    
    titleBackground.setSize(sf::Vector2f(1050, 150));
    titleBackground.setPosition(118, 142);
    titleBackground.setFillColor(styles.sb_Blue);
    
    createdBy.setString("developed by Gisselle Petty");
    createdBy.setFont(impact);
    createdBy.setPosition(490, 1000);
    createdBy.setFillColor(styles.sb_Blue);
    
    
    // flower images
    for (int j = 0; j < FLOWERS_IN_MAIN; j++)
    {
        flowers[j].setTexture(&flowerTexture);
        
    }
    flowers[0].setPosition(900, 400);
    flowers[0].setRadius(100);
    flowers[0].setOrigin(100.f, 100.f);
    
    flowers[1].setPosition(5, 680);
    flowers[1].setRadius(50);
    flowers[1].setOrigin(50.f, 50.f);
    
    flowers[2].setPosition(1100, 900);
    flowers[2].setRadius(40);
    flowers[2].setOrigin(40.f, 40.f);
    
    flowers[3].setPosition(400, 350);
    flowers[3].setRadius(40);
    flowers[3].setOrigin(40.f, 40.f);
    
    flowers[4].setPosition(450, 20);
    flowers[4].setRadius(45);
    flowers[4].setOrigin(45.f, 45.f);
    
    flowers[5].setPosition(1020, 40);
    flowers[5].setRadius(40);
    flowers[5].setOrigin(40.f, 40.f);
    
    flowers[6].setPosition(350, 845);
    flowers[6].setRadius(88);
    flowers[6].setOrigin(88.f, 88.f);
    
    flowers[7].setPosition(25, 980);
    flowers[7].setRadius(45);
    flowers[7].setOrigin(45.f, 45.f);
    
    flowers[8].setPosition(800, 700);
    flowers[8].setRadius(35);
    flowers[8].setOrigin(35.f, 35.f);
    
    flowers[9].setPosition(2, 180);
    flowers[9].setRadius(50);
    flowers[9].setOrigin(50.f, 50.f);
    
    selectedItemIndex = 0;
    
    if (!music.openFromFile(styles.mainMenu_audio))
    {
        std::cout << "cannot play music file" << std::endl;
    }
    
    // Play music
    music.play();
    
    rectSourceSprite.left = 10;
    rectSourceSprite.top = 210;
    
    rectSourceSprite.width = 30;
    rectSourceSprite.height = 60;
    
    animations.updateProperties(rectSourceSprite);
    
    sf::Image squidwardImage;
    squidwardImage.loadFromFile(styles.mainMenu_SquidPath);
    squidwardImage.createMaskFromColor(sf::Color(129,211,222));
    
    // Set the Sprite Texture and the Rect Size
    squidwardTexture.loadFromImage(squidwardImage);
    squidwardSprite.setTexture(squidwardTexture);
    squidwardSprite.setTextureRect(rectSourceSprite);
    
    
    // Scale and Size of Squidward on MainMenu
    squidwardSprite.setPosition(sf::Vector2f(initial_xPos, initial_yPos));
    squidwardSprite.scale(sf::Vector2f(3.5f, 3.5f));
    
//    flowerSprite.setTexture(flowerTexture);
//    flowerSprite.scale(sf::Vector2f(0.3f, 0.3f));
//    flowerSprite.setPosition(sf::Vector2f(200, 300));
    
}


void MainMenu::displayMainMenu(sf::RenderWindow &window)
{
    // Walking onto Main Menu
        
    window.draw(titleBackground);
    window.draw(title);
    window.draw(createdBy);
    
    window.draw(flowers[0]);
    window.draw(flowers[1]);
    window.draw(flowers[2]);
    window.draw(flowers[3]);
    window.draw(flowers[4]);
    window.draw(flowers[5]);
    window.draw(flowers[6]);
    window.draw(flowers[7]);
    window.draw(flowers[8]);
    window.draw(flowers[9]);
    
    if (secondClock.getElapsedTime().asSeconds() > .80f)
    {
        for (int j = 0; j < FLOWERS_IN_MAIN; j++)
        {
            if (j % 2 == 0)
            {
                flowers[j].rotate(300);
            } else {
                flowers[j].rotate(-300);
            }
        }
        secondClock.restart();
    }
  
    
    if (stillWalking)
    {
        if (clock.getElapsedTime().asMilliseconds() > 45.0f)
        {
            if (squidwardSprite.getPosition().x != 550)
            {
                float x_Pos = squidwardSprite.getPosition().x;
                squidwardSprite.setPosition(x_Pos + 5.0f, initial_yPos);
                
                animations.walk(&rectSourceSprite);
                
                squidwardSprite.setTextureRect(rectSourceSprite);
                clock.restart();
            }
        }
    }
    
    // Playing Clarinet
    if (stillWalking == true && squidwardSprite.getPosition().x >= 550)
    {
        rectSourceSprite.left = 14;
        rectSourceSprite.top = 446;
        rectSourceSprite.width = 36;
        rectSourceSprite.height = 55;
        
        stillWalking = false;
    }
    
    if (!stillWalking)
    {
        if (clock.getElapsedTime().asMilliseconds() > 200.0f)
        {
            
            animations.playClarinet(&rectSourceSprite);
            
            squidwardSprite.setTextureRect(rectSourceSprite);
            clock.restart();
        }
    }
    
    window.draw(squidwardSprite);
//    window.draw(flowerSprite);

    for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
    {
        window.draw(rectBtns[i]);
        window.draw(menu[i]);
    }
}

void MainMenu::moveLeft()
{
    if (selectedItemIndex - 1 >= 0)
    {
        menu[selectedItemIndex].setFillColor(sf::Color::White);
        selectedItemIndex--;
        menu[selectedItemIndex].setFillColor(styles.sb_Yellow);
    }
}

void MainMenu::moveRight()
{
    if (selectedItemIndex + 1 < MAX_NUMBER_OF_ITEMS)
    {
        menu[selectedItemIndex].setFillColor(sf::Color::White);
        selectedItemIndex++;
        menu[selectedItemIndex].setFillColor(styles.sb_Yellow);
    }
}

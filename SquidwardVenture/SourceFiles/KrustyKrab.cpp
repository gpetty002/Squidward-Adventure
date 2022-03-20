#include "/Users/gissellepetty/Desktop/cppStuff/SquidwardVenture/SquidwardVenture/HeaderFiles/KrustyKrab.hpp"


KrustyKrab::KrustyKrab(){}
KrustyKrab::~KrustyKrab(){}


void KrustyKrab::loadTextures(sf::RenderWindow &window)
{
    
    squidwardTexture.loadFromFile(styles.squidward_KrustyKrabImgPath);
    bgTexture.loadFromFile(styles.krabbyPattyImgPath);
    
    // Ingredients Textures
    perfectPattyTexture.loadFromFile(styles.perfectPatty);
    rawPattyTexture.loadFromFile(styles.rawPatty);
    burntPattyTexture.loadFromFile(styles.burntPatty);
    cheeseTexture.loadFromFile(styles.cheese);
    lettuceTexture.loadFromFile(styles.lettuce);
    picklesTexture.loadFromFile(styles.pickles);
    topBunTexture.loadFromFile(styles.topBun);
    botBunTexture.loadFromFile(styles.bottomBun);
    mayoTexture.loadFromFile(styles.mayo);
    ketchupTexture.loadFromFile(styles.ketchup);
    mustardTexture.loadFromFile(styles.mustard);
    
    // Stack Ingredients Textures
    botBunStackTexture.loadFromFile(styles.stackofBottomBuns);
    cheeseStackTexture.loadFromFile(styles.stackofCheese);
    picklesStackTexture.loadFromFile(styles.stackofPickles);
    lettuceStackTexture.loadFromFile(styles.stackofLettuce);
    pattiesStackTexture.loadFromFile(styles.stackofPatties);
    topBunStackTexture.loadFromFile(styles.stackofBuns);
    
    
    someTimeLaterFont.loadFromFile(styles.some_time_later_Font);
    impact.loadFromFile(styles.impact_Font);
    
    
    // Set Stack Textures with Sprites
    
    // patty stack
    ingredientButtons[0].setTexture(pattiesStackTexture);
    ingredientButtons[0].setPosition(sf::Vector2f(1120, 720));
    
    // ketchup button
    ingredientButtons[1].setTexture(ketchupTexture);
    ingredientButtons[1].setPosition(sf::Vector2f(45, 550));
    
    // mustard button
    ingredientButtons[2].setTexture(mustardTexture);
    ingredientButtons[2].setPosition(sf::Vector2f(0, 640));
    
    // mayo button
    ingredientButtons[3].setTexture(mayoTexture);
    ingredientButtons[3].setPosition(sf::Vector2f(-8, 730));
    
    // cheese stack
    ingredientButtons[4].setTexture(cheeseStackTexture);
    ingredientButtons[4].setPosition(sf::Vector2f(90, 700));
    
    // lettuce stack
    ingredientButtons[5].setTexture(lettuceStackTexture);
    ingredientButtons[5].setPosition(sf::Vector2f(75, 800));
    
    // pickles stack
    ingredientButtons[6].setTexture(picklesStackTexture);
    ingredientButtons[6].setPosition(sf::Vector2f(60, 875));
    
    // bottom Bun stack
    ingredientButtons[7].setTexture(botBunStackTexture);
    ingredientButtons[7].setPosition(sf::Vector2f(160, 780));
    
    // top Bun stack
    ingredientButtons[8].setTexture(topBunStackTexture);
    ingredientButtons[8].setPosition(sf::Vector2f(15, 910));
    


    textBox.loadFromFile(styles.krustyKrabTextBox_ImgPath);
    tutorialWindow.setTexture(textBox);
    
    // Set Single Ingredient Textures to Sprites
    
    // Raw Patty Array
    rawPatties[0].setTexture(rawPattyTexture);
    rawPatties[0].setPosition(sf::Vector2f(500, 860));
    
    rawPatties[1].setTexture(rawPattyTexture);
    rawPatties[1].setPosition(sf::Vector2f(700, 800));
    
    rawPatties[2].setTexture(rawPattyTexture);
    rawPatties[2].setPosition(sf::Vector2f(900, 900));
    
    rawPatties[3].setTexture(rawPattyTexture);
    rawPatties[3].setPosition(sf::Vector2f(650, 950));
    
    // Perfect Patty Array
    perfectPatties[0].setTexture(perfectPattyTexture);
    perfectPatties[0].setPosition(sf::Vector2f(500, 860));
    
    perfectPatties[1].setTexture(perfectPattyTexture);
    perfectPatties[1].setPosition(sf::Vector2f(700, 800));
    
    perfectPatties[2].setTexture(perfectPattyTexture);
    perfectPatties[2].setPosition(sf::Vector2f(900, 900));
    
    perfectPatties[3].setTexture(perfectPattyTexture);
    perfectPatties[3].setPosition(sf::Vector2f(650, 950));
    
    // Burnt Patty Array
    burntPatties[0].setTexture(burntPattyTexture);
    burntPatties[0].setPosition(sf::Vector2f(500, 860));
    
    burntPatties[1].setTexture(burntPattyTexture);
    burntPatties[1].setPosition(sf::Vector2f(700, 800));
    
    burntPatties[2].setTexture(burntPattyTexture);
    burntPatties[2].setPosition(sf::Vector2f(900, 900));
    
    burntPatties[3].setTexture(burntPattyTexture);
    burntPatties[3].setPosition(sf::Vector2f(650, 950));
    
    // 1 Cheese
    ingredients[0].setTexture(cheeseTexture);
    
    // 2 Lettuce
    ingredients[1].setTexture(lettuceTexture);
    
    // 3 Top Bun
    ingredients[2].setTexture(topBunTexture);
    
    
    okayButton.setPosition(sf::Vector2f(800, 580));
    okayButton.setFillColor(styles.lightBrown);
    okayButton.setSize(sf::Vector2f(120, 50));
    
    
    // Directions for Tutorial Game Window
    
    directions[0].setString("Drag the patties to the grill. Flip them");
    directions[0].setFont(impact);
    directions[0].setCharacterSize(40);
    directions[0].setFillColor(styles.lightBrown);
    directions[0].setPosition(sf::Vector2f(320, 450));
    
    directions[1].setString("over then bring them over to the buns.");
    directions[1].setFont(impact);
    directions[1].setCharacterSize(40);
    directions[1].setFillColor(styles.lightBrown);
    directions[1].setPosition(sf::Vector2f(320, 490));
    
    directions[2].setString("Don't forget to add the other ingredients.");
    directions[2].setFont(impact);
    directions[2].setCharacterSize(40);
    directions[2].setFillColor(styles.lightBrown);
    directions[2].setPosition(sf::Vector2f(320, 530));
    
    directions[3].setString("Pres okay to start");
    directions[3].setFont(impact);
    directions[3].setCharacterSize(40);
    directions[3].setFillColor(styles.lightBrown);
    directions[3].setPosition(sf::Vector2f(320, 570));
    
    okayString.setString("OKAY");
    okayString.setFont(someTimeLaterFont);
    okayString.setFillColor(styles.creamColor);
    okayString.setPosition(sf::Vector2f(815, 580));
    okayString.setCharacterSize(40);
    
    bg.setTexture(bgTexture);
    squidwardSprite.setTexture(squidwardTexture);
    squidwardSprite.setPosition(sf::Vector2f(50, -115));
    
    clock.restart();
    
    clockText.setString(std::to_string(num_seconds));
    clockText.setCharacterSize(100);
    clockText.setFillColor(styles.creamColor);
    clockText.setFont(someTimeLaterFont);
    clockText.setPosition(sf::Vector2f(800, 100));
    
    
}

void KrustyKrab::displayKrustyKrab(sf::RenderWindow &window, sf::Mouse m)
{
    window.draw(bg);
    window.draw(squidwardSprite);
    
    for (int i = 0; i < INGREDIENT_BUTTONS; i++)
    {
        window.draw(ingredientButtons[i]);
    }
    
    if (num_seconds > 0)
    {
        clockText.setString(std::to_string(num_seconds));
        window.draw(clockText);
    } else {
        endOfGame();
    }
    
    if (onTutorialWindow)
    {
        window.draw(tutorialWindow);
        for (int i = 0; i < 4; i++)
        {
            window.draw(directions[i]);
        }
        window.draw(okayButton);
        window.draw(okayString);
        num_seconds = 55;
    }
    
    if (clock.getElapsedTime().asSeconds() > 1.0f)
    {
        num_seconds--;
        clock.restart();
    }

    if (drawPattyClicks > 0)
    {
        if (drawPattyClicks > 4)
            drawPattyClicks = 4;
        
        // draw raw patty
        for (int i = 0; i < drawPattyClicks; i++)
        {
            window.draw(rawPatties[i]);
            krabbyPatties.push_back(rawPatties[i]);
        }
    }

    for (int j = 0; j < drawPattyClicks; j++)
    {
        int currentTime = num_seconds;
        int passedTime = secondsAfterRawPatty[j] - currentTime;

        // draw Burnt Patty
        if (passedTime > 18)
        {
            window.draw(burntPatties[j]);
            krabbyPatties[j] = burntPatties[j];
        } else if (passedTime > 10)
        {
            // draw Perfect Patty
            window.draw(perfectPatties[j]);
            krabbyPatties[j] = perfectPatties[j];
        }
    }
    
}

void movePatty(sf:: Sprite s)
{
    s.setPosition(sf::Vector2f(300, 720));
}

void KrustyKrab::endOfGame()
{
    std::cout << "game over" << std::endl;
}


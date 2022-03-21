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
    
    
    // Fonts 
    someTimeLaterFont.loadFromFile(styles.some_time_later_Font);
    impact.loadFromFile(styles.impact_Font);

    // Audio
    if (!music.openFromFile(styles.cookingKrustyKrab_audio))
    {
        std::cout << "cannot play cookingKrustyKrab.wav file" << std::endl;
    }

    if (!grillingEffect.openFromFile(styles.grilling_audio))
    {
        std::cout << "cannot play grillingSound.wav file" << std::endl;
    }
    
    
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
    ingredientButtons[6].setPosition(sf::Vector2f(40, 890));
    
    // bottom Bun stack
    ingredientButtons[7].setTexture(botBunStackTexture);
    ingredientButtons[7].setPosition(sf::Vector2f(160, 780));
    
    // top Bun stack
    ingredientButtons[8].setTexture(topBunStackTexture);
    ingredientButtons[8].setPosition(sf::Vector2f(15, 930));
    


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

    submitButton.setPosition(sf::Vector2f(900, 600));
    submitButton.setFillColor(styles.sb_Blue);
    submitButton.setSize(sf::Vector2f(220, 100));

    submitText.setString("ORDER'S UP");
    submitText.setFont(someTimeLaterFont);
    submitText.setCharacterSize(44);
    submitText.setFillColor(styles.creamColor);
    submitText.setPosition(sf::Vector2f(915, 615));
    
    
    // Directions for Tutorial Game Window
    
    directions[0].setString("Tap the patties to hit the grill. Tap again to");
    directions[0].setFont(impact);
    directions[0].setCharacterSize(35);
    directions[0].setFillColor(styles.lightBrown);
    directions[0].setPosition(sf::Vector2f(320, 450));
    
    directions[1].setString("bring them over to the buns. Don't forget");
    directions[1].setFont(impact);
    directions[1].setCharacterSize(35);
    directions[1].setFillColor(styles.lightBrown);
    directions[1].setPosition(sf::Vector2f(320, 490));
    
    directions[2].setString("to add other ingredients. Press OKAY to");
    directions[2].setFont(impact);
    directions[2].setCharacterSize(35);
    directions[2].setFillColor(styles.lightBrown);
    directions[2].setPosition(sf::Vector2f(320, 530));
    
    directions[3].setString("start and ORDERS UP to finish.");
    directions[3].setFont(impact);
    directions[3].setCharacterSize(35);
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

    music.play();
    grillingEffect.play();
    
    
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

    for (int j = 0; j < drawPattyClicks; j++)
    {
        int currentTime = num_seconds;
        passedTime[j] = secondsAfterRawPatty[j] - currentTime;

        // draw Burnt Patty
        if (passedTime[j] > 14 && onGrill[j] == true)
        {
            krabbyPatties[j] = burntPatties[j];
        } else if (passedTime[j] > 8)
        {
            // draw Perfect Patty
            krabbyPatties[j] = perfectPatties[j];
        } else {
            // draw raw Patty
            krabbyPatties[j] = rawPatties[j];
        }

        if (movingPatty[j])
        {
            movePatty(j, krabbyPatties);
        }
        
        window.draw(krabbyPatties[j]);
    }

    for (int k = 0; k < drawCheeseClicks; k++)
    {
        cheese[k] = ingredients[0];
        switch (k)
        {
        case 0:
            cheese[k].setPosition(sf::Vector2f(250,740));
            break;
        case 1:
            cheese[k].setPosition(sf::Vector2f(220,810));
            break;
        case 2:
            cheese[k].setPosition(sf::Vector2f(200,870));
            break;
        case 3:
            cheese[k].setPosition(sf::Vector2f(160,950));
            break;
        default:
            break;
        }
        window.draw(cheese[k]);
    }

    for (int l = 0; l < drawLettuceClicks; l++)
    {
        lettuce[l] = ingredients[1];
        switch (l)
        {
        case 0:
            lettuce[l].setPosition(sf::Vector2f(250, 730));
            break;
        case 1:
            lettuce[l].setPosition(sf::Vector2f(220, 800));
            break;
        case 2:
            lettuce[l].setPosition(sf::Vector2f(200, 860));
            break;
        case 3:
            lettuce[l].setPosition(sf::Vector2f(160, 940));
            break;
        default:
            break;
        }
        window.draw(lettuce[l]);
    }

    for (int m = 0; m < drawTopBunsClicks; m++)
    {
        topBuns[m] = ingredients[2];

        switch (m)
        {
        case 0:
            topBuns[m].setPosition(sf::Vector2f(260, 680));
            break;
        case 1:
            topBuns[m].setPosition(sf::Vector2f(240, 770));
            break;
        case 2:
            topBuns[m].setPosition(sf::Vector2f(220, 840));
            break;
        case 3:
            topBuns[m].setPosition(sf::Vector2f(170, 910));
            break;
        default:
            break;
        }
        window.draw(topBuns[m]);
    }
    
    if (finishedGame)
    {
        window.draw(submitButton);
        window.draw(submitText);
    }

}

void KrustyKrab::movePatty(int x, sf:: Sprite s[])
{
    switch (x)
    {
    case 0:
        s[x].setPosition(sf::Vector2f(260, 750));
        break;
    case 1:
        s[x].setPosition(sf::Vector2f(220, 820));
        break;
    case 2:
        s[x].setPosition(sf::Vector2f(200, 880));
        break;
    case 3:
        s[x].setPosition(sf::Vector2f(160, 950));
        break;
    default:
        break;
    }
}

void KrustyKrab::endOfGame()
{
    std::cout << "game over" << std::endl;
}


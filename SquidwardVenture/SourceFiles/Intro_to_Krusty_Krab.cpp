#include "/Users/gissellepetty/Desktop/cppStuff/SquidwardVenture/SquidwardVenture/HeaderFiles/Intro_to_Krusty_Krab.hpp"

void Intro_to_Krusty_Krab::loadTextures(sf::RenderWindow &window)
{
    if (!krabsTexture.loadFromFile(styles.krustyKrab_KrabsImgPath))
    {
        // handle error
        std::cout << "could not load introKrabs.png texture" << std::endl;
    }
    
    if (!squidwardTexture.loadFromFile(styles.unfazedSquidward_ImgPath))
    {
        // handle error
        std::cout << "could not load unfazedSquidward.png texture" << std::endl;
    }
    
    if (!bgTexture.loadFromFile(styles.krabsOfficeImgPath))
    {
        // handle error
        std::cout << "could not load krabsOffice.png texture" << std::endl;
    }
    
    if (!textBoxTexture.loadFromFile(styles.krustyKrabTextBox_ImgPath))
    {
        // handle error
        std::cout << "could not load KrustyKrabTextBox.png texture" << std::endl;
    }
    
    if (!someTimeLater.loadFromFile(styles.some_time_later_Font))
    {
        // handle error
        std::cout << "could not load some-time-later.ttf font" << std::endl;
    }
    
    if (!impactFont.loadFromFile(styles.impact_Font))
    {
        // handle error
        std::cout << "could not load impact.ttf font" << std::endl;
    }
    
    if (!music.openFromFile(styles.krustyKrab_audio))
    {
        // handle error
        std::cout << "could not load krusty_krab_music.wav file" << std::endl;
    }
    
    selectedItemIndex = -1;
    
    squidward.setTexture(squidwardTexture);
    krabs.setTexture(krabsTexture);
    bg.setTexture(bgTexture);
    textBox.setTexture(textBoxTexture);
    
    krabs.setScale(sf::Vector2f(0.5f, 0.5f));
    krabs.setPosition(sf::Vector2f(730, 500));
    
    squidward.setPosition(sf::Vector2f(50, 200));
    
    dialogueBox[0].setString("SQUIDWARD!!! SQUIDWARD!!!");
    dialogueBox[0].setFont(impactFont);
    dialogueBox[0].setFillColor(styles.sb_Blue);
    dialogueBox[0].setCharacterSize(45);
    dialogueBox[0].setPosition(sf::Vector2f(370, 520));
    dialogueBox[0].setStyle(sf::Text::Bold);
    
    dialogueBox[1].setString("What, Mr. Krabs?");
    dialogueBox[1].setFont(impactFont);
    dialogueBox[1].setFillColor(styles.sb_Blue);
    dialogueBox[1].setCharacterSize(45);
    dialogueBox[1].setPosition(sf::Vector2f(480, 520));
    
    dialogueBox[2].setString("I need you to man the grill today.");
    dialogueBox[2].setFont(impactFont);
    dialogueBox[2].setFillColor(styles.sb_Blue);
    dialogueBox[2].setCharacterSize(40);
    dialogueBox[2].setPosition(sf::Vector2f(380, 500));
    
    dialogueBox[3].setString("What??? Why can't Spongebob do it?");
    dialogueBox[3].setFont(impactFont);
    dialogueBox[3].setFillColor(styles.sb_Blue);
    dialogueBox[3].setCharacterSize(40);
    dialogueBox[3].setPosition(sf::Vector2f(340, 500));
    
    dialogueBox[4].setString("He called in sick today. If it wasn't for him");
    dialogueBox[4].setFont(impactFont);
    dialogueBox[4].setFillColor(styles.sb_Blue);
    dialogueBox[4].setCharacterSize(40);
    dialogueBox[4].setPosition(sf::Vector2f(310, 460));
    
    dialogueBox[5].setString("But Krabs I don't even know how to make");
    dialogueBox[5].setFont(impactFont);
    dialogueBox[5].setFillColor(styles.sb_Blue);
    dialogueBox[5].setCharacterSize(40);
    dialogueBox[5].setPosition(sf::Vector2f(320, 500));
    
    dialogueBox[6].setString("Its simple. Drag over the patties to the");
    dialogueBox[6].setFont(impactFont);
    dialogueBox[6].setFillColor(styles.sb_Blue);
    dialogueBox[6].setCharacterSize(40);
    dialogueBox[6].setPosition(sf::Vector2f(310, 460));
    
    dialogueBox[7].setString("Make sure to follow the recipe. Keep an");
    dialogueBox[7].setFont(impactFont);
    dialogueBox[7].setFillColor(styles.sb_Blue);
    dialogueBox[7].setCharacterSize(40);
    dialogueBox[7].setPosition(sf::Vector2f(310, 460));
    
    music.play();
    
    
}

void Intro_to_Krusty_Krab::displayIntroScreen(sf::RenderWindow &window)
{
    sf::Text holder_Text;
    holder_Text.setFont(impactFont);
    holder_Text.setFillColor(styles.sb_Blue);
    holder_Text.setCharacterSize(40);
    
    sf::Text second_Holder;
    second_Holder.setFont(impactFont);
    second_Holder.setFillColor(styles.sb_Blue);
    second_Holder.setCharacterSize(40);
    
    sf::Text third_Holder;
    third_Holder.setFont(impactFont);
    third_Holder.setFillColor(styles.sb_Blue);
    third_Holder.setCharacterSize(40);
    
    sf::Text press_Continue;
    press_Continue.setString("CLICK TO CONTINUE");
    press_Continue.setFont(impactFont);
    press_Continue.setFillColor(sf::Color(255, 252, 235, 200));
    press_Continue.setPosition(sf::Vector2f(470, 1000));
    press_Continue.setCharacterSize(45);
    
    window.draw(bg);
    
    if (selectedItemIndex+1 <= NUM_OF_DIALOGUE_TEXTBOXES)
    {
        window.draw(textBox);
    }
    
    
    for (int i = 0; i < NUM_OF_DIALOGUE_TEXTBOXES; i++)
    {
        if (selectedItemIndex == i)
        {
            window.draw(dialogueBox[selectedItemIndex]);
            if (selectedItemIndex == 0)
            {
                window.draw(krabs);
            } else if (selectedItemIndex == 1)
            {
                window.draw(squidward);
            } else if (selectedItemIndex == 2)
            {
                holder_Text.setString("We got a lot of hungry paying customers.");
                holder_Text.setPosition(sf::Vector2f(320, 550));
                
                window.draw(krabs);
                window.draw(holder_Text);
            } else if (selectedItemIndex == 3)
            {
                holder_Text.setString("He likes the smell of grease anyways.");
                holder_Text.setPosition(sf::Vector2f(340, 550));
                
                window.draw(squidward);
                window.draw(holder_Text);
            } else if (selectedItemIndex == 4)
            {
                holder_Text.setString("scaring me customers, I'd still have him");
                second_Holder.setString("work the grill. Anyway, grab a spatula");
                third_Holder.setString("and head on over there.");
                
                holder_Text.setPosition(sf::Vector2f(320, 500));
                second_Holder.setPosition(sf::Vector2f(320, 540));
                third_Holder.setPosition(sf::Vector2f(320, 580));
                
                window.draw(krabs);
                window.draw(holder_Text);
                window.draw(second_Holder);
                window.draw(third_Holder);
            } else if (selectedItemIndex == 5)
            {
                holder_Text.setString("Krabby Patties");
                holder_Text.setPosition(sf::Vector2f(320, 550));
                
                window.draw(squidward);
                window.draw(holder_Text);
            } else if (selectedItemIndex == 6)
            {
                holder_Text.setString("grill. You still have to flip them so keep");
                holder_Text.setPosition(sf::Vector2f(320, 500));
                
                second_Holder.setString("your eye on them. Also, make sure they");
                second_Holder.setPosition(sf::Vector2f(320, 540));
                
                third_Holder.setString("don't burn.");
                third_Holder.setPosition(sf::Vector2f(320, 580));
                
                window.draw(krabs);
                window.draw(holder_Text);
                window.draw(second_Holder);
                window.draw(third_Holder);
            } else if (selectedItemIndex == 7)
            {
                holder_Text.setString("eye on the clock. I don't want any angry");
                second_Holder.setString("customers. That's money out of our");
                third_Holder.setString("pocket.");
                
                holder_Text.setPosition(sf::Vector2f(320, 500));
                second_Holder.setPosition(sf::Vector2f(320, 540));
                third_Holder.setPosition(sf::Vector2f(320, 580));
                
                window.draw(krabs);
                window.draw(holder_Text);
                window.draw(second_Holder);
                window.draw(third_Holder);
            }
        }
    }
    
//    if (clock.getElapsedTime().asMilliseconds() > 50)
//    {
//        std::cout << clock.getElapsedTime().asMilliseconds() << std::endl;
//        press_Continue.setFillColor(sf::Color(255, 252, 235, 255));
//        clock.restart();
//    }
    
    window.draw(press_Continue);
}

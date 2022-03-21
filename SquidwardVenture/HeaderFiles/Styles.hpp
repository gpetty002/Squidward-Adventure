#ifndef Styles_hpp
#define Styles_hpp

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

using std::string;

class Styles
{
    
public:
    
    // Images
    
    string flowerImgPath = "/Users/gissellepetty/Desktop/cppStuff/SquidwardVenture/SquidwardVenture/ResourceFiles/Images/304201517179211.png";
    
    string gameMapImgPath = "/Users/gissellepetty/Desktop/cppStuff/SquidwardVenture/SquidwardVenture/ResourceFiles/Images/GameMap.png";
    
    string krustyKrab_KrabsImgPath = "/Users/gissellepetty/Desktop/cppStuff/SquidwardVenture/SquidwardVenture/ResourceFiles/Images/1200MrKrabs.png";
    
    string krustyKrab_SquidImgPath = "/Users/gissellepetty/Desktop/cppStuff/SquidwardVenture/SquidwardVenture/ResourceFiles/Images/introSquidward.png";
    
    string krabbyPattyImgPath = "/Users/gissellepetty/Desktop/cppStuff/SquidwardVenture/SquidwardVenture/ResourceFiles/Images/KrabbyPattyBG.png";
    
    string krabsOfficeImgPath = "/Users/gissellepetty/Desktop/cppStuff/SquidwardVenture/SquidwardVenture/ResourceFiles/Images/krabsOffice.png";
    
    string squidGameMapPath = "/Users/gissellepetty/Desktop/cppStuff/SquidwardVenture/SquidwardVenture/ResourceFiles/Images/squidGameMap.png";
    
    string mainMenu_SquidPath = "/Users/gissellepetty/Desktop/cppStuff/SquidwardVenture/SquidwardVenture/ResourceFiles/Images/squidwardSprites.png";
    
    string unfazedSquidward_ImgPath = "/Users/gissellepetty/Desktop/cppStuff/SquidwardVenture/SquidwardVenture/ResourceFiles/Images/unfazedSquidward.png";
    
    string krustyKrabTextBox_ImgPath = "/Users/gissellepetty/Desktop/cppStuff/SquidwardVenture/SquidwardVenture/ResourceFiles/Images/KrustyKrabTextBox.png";
    
    string squidward_KrustyKrabImgPath = "/Users/gissellepetty/Desktop/cppStuff/SquidwardVenture/SquidwardVenture/ResourceFiles/Images/SquidwardSpriteKrustyKrab.png";
    
    // Fonts
    
    string arial_Font = "/Users/gissellepetty/Desktop/cppStuff/SquidwardVenture/SquidwardVenture/ResourceFiles/Fonts/Arial.ttf";
    
    string impact_Font = "/Users/gissellepetty/Desktop/cppStuff/SquidwardVenture/SquidwardVenture/ResourceFiles/Fonts/Impact.ttf";
    
    string some_time_later_Font = "/Users/gissellepetty/Desktop/cppStuff/SquidwardVenture/SquidwardVenture/ResourceFiles/Fonts/some-time-later.ttf";
    
    
    // Ingredients to Krusty Krab Mini Game
    
    string bottomBun = "/Users/gissellepetty/Desktop/cppStuff/SquidwardVenture/SquidwardVenture/ResourceFiles/Images/Ingredients/bottomBun.png";
    
    string topBun = "/Users/gissellepetty/Desktop/cppStuff/SquidwardVenture/SquidwardVenture/ResourceFiles/Images/Ingredients/bun.png";
    
    string burntPatty = "/Users/gissellepetty/Desktop/cppStuff/SquidwardVenture/SquidwardVenture/ResourceFiles/Images/Ingredients/burntPatty.png";
    
    string rawPatty = "/Users/gissellepetty/Desktop/cppStuff/SquidwardVenture/SquidwardVenture/ResourceFiles/Images/Ingredients/patty.png";
    
    string perfectPatty = "/Users/gissellepetty/Desktop/cppStuff/SquidwardVenture/SquidwardVenture/ResourceFiles/Images/Ingredients/perfectPatty.png";
    
    string cheese = "/Users/gissellepetty/Desktop/cppStuff/SquidwardVenture/SquidwardVenture/ResourceFiles/Images/Ingredients/cheese.png";
    
    string lettuce = "/Users/gissellepetty/Desktop/cppStuff/SquidwardVenture/SquidwardVenture/ResourceFiles/Images/Ingredients/lettuce.png";
    
    string pickles = "/Users/gissellepetty/Desktop/cppStuff/SquidwardVenture/SquidwardVenture/ResourceFiles/Images/Ingredients/pickles.png";
    
    string ketchup = "/Users/gissellepetty/Desktop/cppStuff/SquidwardVenture/SquidwardVenture/ResourceFiles/Images/Ingredients/ketchup.png";
    
    string mustard = "/Users/gissellepetty/Desktop/cppStuff/SquidwardVenture/SquidwardVenture/ResourceFiles/Images/Ingredients/mustard.png";
    
    string mayo = "/Users/gissellepetty/Desktop/cppStuff/SquidwardVenture/SquidwardVenture/ResourceFiles/Images/Ingredients/mayo.png";
    
    string stackofBuns = "/Users/gissellepetty/Desktop/cppStuff/SquidwardVenture/SquidwardVenture/ResourceFiles/Images/IngredientStacks/stackofBuns.png";
    
    string stackofPatties = "/Users/gissellepetty/Desktop/cppStuff/SquidwardVenture/SquidwardVenture/ResourceFiles/Images/IngredientStacks/stackofPatties.png";
    
    string stackofPickles = "/Users/gissellepetty/Desktop/cppStuff/SquidwardVenture/SquidwardVenture/ResourceFiles/Images/IngredientStacks/stackofPickles.png";
    
    string stackofBottomBuns = "/Users/gissellepetty/Desktop/cppStuff/SquidwardVenture/SquidwardVenture/ResourceFiles/Images/IngredientStacks/stackofBotBun.png";
    
    string stackofLettuce = "/Users/gissellepetty/Desktop/cppStuff/SquidwardVenture/SquidwardVenture/ResourceFiles/Images/IngredientStacks/stackofLettuce.png";
    
    string stackofCheese = "/Users/gissellepetty/Desktop/cppStuff/SquidwardVenture/SquidwardVenture/ResourceFiles/Images/IngredientStacks/stackofCheese.png";

    string win_image = "/Users/gissellepetty/Desktop/cppStuff/SquidwardVenture/SquidwardVenture/ResourceFiles/Images/winningImage.png";
    
    // Audio
    
    string mainMenu_audio = "/Users/gissellepetty/Desktop/cppStuff/SquidwardVenture/SquidwardVenture/ResourceFiles/Audio/game_intro.wav";
    
    string gameMap_audio = "/Users/gissellepetty/Desktop/cppStuff/SquidwardVenture/SquidwardVenture/ResourceFiles/Audio/game_map_music.wav";
    
    string krustyKrab_audio = "/Users/gissellepetty/Desktop/cppStuff/SquidwardVenture/SquidwardVenture/ResourceFiles/Audio/krusty_krab_music.wav";
    
    string grilling_audio = "/Users/gissellepetty/Desktop/cppStuff/SquidwardVenture/SquidwardVenture/ResourceFiles/Audio/grillingSound.wav";

    string cookingKrustyKrab_audio = "/Users/gissellepetty/Desktop/cppStuff/SquidwardVenture/SquidwardVenture/ResourceFiles/Audio/cookingKrustyKrab.wav";

    string cocktail_audio = "/Users/gissellepetty/Desktop/cppStuff/SquidwardVenture/SquidwardVenture/ResourceFiles/Audio/cocktail_Lounge.wav";
    // Colors
    
    sf::Color creamColor = sf::Color(255, 252, 235);
    sf::Color sb_Blue = sf::Color(4, 87, 160);
    sf::Color sb_Yellow = sf::Color(255, 245, 108);
    sf::Color lightBrown = sf::Color(205,174,95);

    
};


#endif /* Styles_hpp */

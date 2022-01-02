#ifndef Player_hpp
#define Player_hpp

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

class Player
{
public:
    // Constructor
    Player();
    // Destructor
    virtual ~Player();
    
    // Members
    int livesLeft = 3;
    int levelsLeft = 5;
    
    // Functions
    void checkGameOver();
    void displayGameOver();
private:
    
};

#endif /* Player_hpp */

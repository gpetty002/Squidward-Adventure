#ifndef SpriteMovements_hpp
#define SpriteMovements_hpp

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

#include <iostream>

class SpriteMovements
{
public:
    int x_Pos;
    int y_Pos;
    int width_Val;
    int height_Val;
    
    // Constructors & Destructors
    SpriteMovements();
    SpriteMovements (sf::IntRect r);
    virtual ~SpriteMovements();
    
    // Functions
    void updateProperties(sf::IntRect r);
    void walk(sf::IntRect *r);
    void playClarinet(sf::IntRect *r);
    void idle(sf::IntRect *r);
    void run(sf::IntRect *r);
    void jump(sf::IntRect *r);
    void laugh(sf::IntRect *r);
    void hurt(sf::IntRect *r);
    
};

#endif /* SpriteMovements_hpp */

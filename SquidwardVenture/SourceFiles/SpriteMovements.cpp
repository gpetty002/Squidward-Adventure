#include "/Users/gissellepetty/Desktop/cppStuff/SquidwardVenture/SquidwardVenture/HeaderFiles/SpriteMovements.hpp"


#include <iostream>

SpriteMovements::SpriteMovements()
{
    
}

SpriteMovements::SpriteMovements(sf::IntRect r) : x_Pos(r.left), y_Pos(r.top), width_Val(r.width), height_Val(r.height)
{
    
}

void SpriteMovements::updateProperties(sf::IntRect r)
{
    x_Pos = r.left;
    y_Pos = r.top;
    width_Val = r.width;
    height_Val = r.height;
}

void SpriteMovements::walk(sf::IntRect *r)
{
    r->width = 34;
    if (r->left == 10)
    {
        r->left = 43;
        
    } else if (r->left == 43)
    {
        r->left = 74;
    } else if (r->left == 74)
    {
        r->left = 103;
    } else if (r->left == 103)
    {
        r->left = 130;
    } else if (r->left == 130)
    {
        r->left = 160;
        r->top = 207;
        r->height = 63;
    } else if (r->left == 160)
    {
        r->left = 190;
        r->width = 36;
    } else if (r->left == 190)
    {
        r->left = 230;
    } else if (r->left == 230)
    {
        r->left = 274;
    } else if (r->left == 274)
    {
        r->left = 308;
    } else if (r->left == 308)
    {
        r->left = 339;
    } else if (r->left == 339)
    {
        r->left = 368;
        r->width = 35;
    } else if (r->left == 368)
    {
        r->left = 397;
    } else if (r->left == 397)
    {
        r->left = 428;
    } else if (r->left == 428)
    {
        r->left = 460;
        r->width = 43;
    } else if (r->left == 460)
    {
        r->left = 467;
    } else if (r->left == 467)
    {
        r->left = 10;
    }
        
}

void SpriteMovements::playClarinet(sf::IntRect *r)
{
    if (r->left == 14)
    {
        r->left = 46;
    } else if (r->left == 46)
    {
        r->left = 88;
        r->top = 446;
    } else if (r->left == 88)
    {
        r->left = 130;
        r->width = 50;
    } else if (r->left == 130)
    {
        r->left = 190;
        r->width = 45;
    } else {
        r->left = 130;
        r->width = 50;
    }
}

void SpriteMovements::idle(sf::IntRect *r)
{
    
}

void SpriteMovements::run(sf::IntRect *r)
{
    
}

void SpriteMovements::jump(sf::IntRect *r)
{
    
}

void SpriteMovements::laugh(sf::IntRect *r)
{
    
}

void SpriteMovements::hurt(sf::IntRect *r)
{
    
}

SpriteMovements::~SpriteMovements()
{
    
}

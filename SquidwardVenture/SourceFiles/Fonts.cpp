#include <iostream>
#include <string>

using std::string;

class FontPaths
{
public:
    FontPaths();
    string getSomeTimeLater()
    {
        return "/Users/gissellepetty/Desktop/cppStuff/SquidwardVenture/ResourceFiles/Fonts/some-time-later.ttf";
    }
    
    string getImpact()
    {
        return "/Users/gissellepetty/Desktop/cppStuff/SquidwardVenture/ResourceFiles/Fonts/Impact.ttf";
    }
    
    string getArial()
    {
        return "/Users/gissellepetty/Desktop/cppStuff/SquidwardVenture/ResourceFiles/Fonts/Arial.ttf";
    }
};

FontPaths::FontPaths(){}



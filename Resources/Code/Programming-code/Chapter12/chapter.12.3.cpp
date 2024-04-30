
//
// This is example code from Chapter 12.3 "A first example" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

// The NOGDI below is needed to prevent Windows from including wingdi.h which has a duplicate
// declaration of 'Polygon' and throws ambiguous error.
#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
#define NOGDI
#endif

#include "Simple_window.h"    // get access to our window library
#include "Graph.h"            // get access to our graphics library facilities
#include <iostream>
#include <fstream>
#include <vector>
#include "vec3.h"

using namespace std;
class Pixel
{
private:
    int positionx;
    int positiony;
    vec3 color;

public:
    // def constructor
    Pixel() : positionx(0), positiony(0), color(0, 0, 0) {}

    // Constructor
    Pixel(int x, int y, const vec3 &col) : positionx(x), positiony(y), color(col) {}

    // Getters
    int getPositionX() const { return positionx; }
    int getPositionY() const { return positiony; }
    const vec3 &getColor() const { return color; }

    // Setters
    void setPositionX(int x) { positionx = x; }
    void setPositionY(int y) { positiony = y; }
    void setColor(const vec3 &col) { color = col; }
};

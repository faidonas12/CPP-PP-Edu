
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

// Image Data Class
class ImageData
{
private:
    vector<vector<Pixel>> image;
    int width;
    int height;
    string imagename;

public:
    // Constructor
    ImageData(const string &filename)
    {
        ifstream file(filename);
        if (!file)
        {
            cerr << "Error: Unable to open file " << filename << endl;
            return;
        }

        string magicNumber;
        getline(file, magicNumber);

        file >> width >> height;

        // Resize image vector
        image.resize(height, vector<Pixel>(width));

        // Read pixel data
        for (int y = 0; y < height; ++y)
        {
            for (int x = 0; x < width; ++x)
            {
                double r, g, b;
                file >> r >> g >> b;
                vec3 color = vec3(r, g, b);
                image[y][x] = Pixel(x, y, color);
            }
        }

        file.close();
    }

    // Getters
    const vector<vector<Pixel>> &getImage() const { return image; }
    int getWidth() const { return width; }
    int getHeight() const { return height; }
    string getImageName() const { return imagename; }

    // Setters
    void setImage(const vector<vector<Pixel>> &img) { image = img; }
    void setWidth(int w) { width = w; }
    void setHeight(int h) { height = h; }

    Pixel getPixel(int x, int y) const
    {
        
        if (x >= 0 && x < width && y >= 0 && y < height)
        {
            // Return the pixel at the specified position
            return image[y][x];
     }
    }
}


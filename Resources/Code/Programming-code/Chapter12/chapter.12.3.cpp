
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
} void displaywindow(int width, int height, const string &filename)
{
    int newwidth = width * 20 + 70;
    int newheight = height * 20;
   using namespace Graph_lib;  
     Point tl(100,100);           

    Simple_window win(tl,newwidth,newheight,filename);    // make a simple window
    imag
    for (int y = 0; y < newHeight; ++y)
    {
        for (int x = 0; x < newWidth; ++x)
        {
            Pixel curr_pixel = imageData.getPixel(x, y);
            int red = static_cast<int>(color.x());
            int green = static_cast<int>(color.y());
            int blue = static_cast<int>(color.z());

             int rect_width = 20;
            int rect_height = 20;
            int rect_x = x * rect_width;
            int rect_y = y * rect_height;
            Fl_Rectangle *rect = new Fl_Rectangle(rect_x, rect_y, rect_width, rect_height);
            rect->color(FL_RGB_COLOR(red, green, blue));

            // Add the rectangle to the window
            win.attach(*rect)
            
        }
    }
   
   win.show();
   Fl::run();
}

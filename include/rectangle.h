#pragma once

#include "libraries.h"

class Rectangle {
private:
    int length;
    int width;
    int area;
    bool placed;
public:
    Rectangle(int length, int width);
    int getLength();
    int getWidth();
    int getArea();
    void setPlaced(bool b);
    bool getPlaced();
    void reverseLW();
    bool operator < (const Rectangle &r1) const;
    bool operator == (const Rectangle &r1) const;
};

#pragma once

#include "libraries.h"
#include "coordinate.h"
#include "rectangle.h"

class Grid {
private:
    std::vector<std::vector<Coordinate>> coordinates;
    int side;
public:
    Grid(int side);
    int getSide();
    std::vector<std::vector<Coordinate>> getCoordinates();
    void setCoordinate(int x, int y, char c);
    void unsetCoordinate(int x, int y);
    std::set<Coordinate> topLefts(Rectangle r);
    bool getFull();
    void display();
};
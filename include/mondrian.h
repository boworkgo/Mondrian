#pragma once

#include "libraries.h"
#include "rectangle.h"
#include "grid.h"

class Mondrian {
private:
    int side;
    std::vector<Rectangle> rectangles;
    std::set<std::set<Rectangle>> subsets;
    int bestDifference;
public:
    char getRandomPiece();
    Mondrian(int side);
    void sumToArea();
    bool deadGrid(Grid g, std::set<Rectangle> temp);
    void validateTemp(std::set<Rectangle> temp);
    Grid recursiveGrid(Grid master, std::set<Rectangle> temp);
    void displayRectsProperties(std::set<Rectangle> r);
};

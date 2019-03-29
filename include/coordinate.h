#pragma once

#include "libraries.h"

class Coordinate {
private:
    int x;
    int y;
    char piece;
    bool occupied;
public:
    Coordinate(int x, int y);
    int getX();
    int getY();
    void setPiece(char p);
    char getPiece();
    void setOccupied(bool b);
    bool getOccupied();
    bool operator < (const Coordinate &c1) const;
    bool operator == (const Coordinate &c1) const;
};

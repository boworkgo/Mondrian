#include "coordinate.h"

Coordinate::Coordinate(int x, int y) {
    this->x = x;
    this->y = y;
    piece = '*';
    occupied = false;
}

int Coordinate::getX() {
    return x;
}

int Coordinate::getY() {
    return y;
}

void Coordinate::setPiece(char p) {
    piece = p;
}

char Coordinate::getPiece() {
    return piece;
}

void Coordinate::setOccupied(bool b) {
    occupied = b;
}

bool Coordinate::getOccupied() {
    return occupied;
}

bool Coordinate::operator < (const Coordinate &c1) const {
    if (c1.x != x) {
        return x < c1.x;
    } else {
        return y < c1.y;
    }
}

bool Coordinate::operator == (const Coordinate &c1) const {
    return x == c1.x && y == c1.y;
}

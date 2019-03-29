#include "rectangle.h"

Rectangle::Rectangle(int length, int width) {
    this->length = length;
    this->width = width;
    area = length * width;
    placed = false;
}

int Rectangle::getLength() {
    return length;
}

int Rectangle::getWidth() {
    return width;
}

int Rectangle::getArea() {
    return area;
}

void Rectangle::setPlaced(bool b) {
    placed = b;
}

bool Rectangle::getPlaced() {
    return placed;
}

void Rectangle::reverseLW() {
    int temp = length;
    length = width;
    width = temp;
}

bool Rectangle::operator < (const Rectangle &r1) const {
    if (r1.length != length) {
        return length < r1.length;
    } else {
        return width < r1.width;
    }
}

bool Rectangle::operator == (const Rectangle &r1) const {
    return (r1.length == length && r1.width == width) ||
        (r1.length == width && r1.width == length);
}

bool operator == (std::set<std::set<Rectangle>> r, std::set<std::set<Rectangle>> s) {
    if (r.size() != s.size()) {
        return false;
    } else {
        auto rIt = r.begin(), sIt = s.begin();
        while (rIt != r.end()) {
            if (*rIt != *sIt) {
                return false;
            }
            rIt++;
            sIt++;
        }
        return true;
    }
}

#include "grid.h"

Grid::Grid(int side) {
    this->side = side;
    for (int x = 0; x < side; x++) {
        std::vector<Coordinate> row;
        for (int y = 0; y < side; y++) {
            row.push_back(Coordinate(x, y));
        }
        coordinates.push_back(row);
    }
}

int Grid::getSide() {
    return side;
}

std::vector<std::vector<Coordinate>> Grid::getCoordinates() {
    return coordinates;
}

void Grid::setCoordinate(int x, int y, char c) {
    coordinates[x][y].setOccupied(true);
    coordinates[x][y].setPiece(c);
}

void Grid::unsetCoordinate(int x, int y) {
    coordinates[x][y].setOccupied(false);
    coordinates[x][y].setPiece('*');
}

std::set<Coordinate> Grid::topLefts(Rectangle r) {
    std::set<Coordinate> output;
    if (r.getPlaced()) {
        return output;
    }
    for (auto row : coordinates) {
        for (auto c : row) {
            if (!c.getOccupied()) {
                if (c.getX() + r.getLength() <= side && c.getY() + r.getWidth() <= side) { // stupid &&
                    for (int i = c.getX(); i < c.getX() + r.getLength(); i++) {
                        for (int j = c.getY(); j < c.getY() + r.getWidth(); j++) {
                            if (coordinates[i][j].getOccupied()) {
                                goto speckBreak;
                            }
                        }
                    }
                    output.insert(c);
                    speckBreak:;
                }
            }
        }
    }
    return output;
}

bool Grid::getFull() {
    for (auto r : coordinates) {
        for (auto c : r) {
            if (!c.getOccupied()) {
                return false;
            }
        }
    }
    return true;
}

void Grid::display() {
    std::cout << std::endl << "Board" << std::endl; 
    for (auto c : coordinates) {
        for (auto r : c) {
            std::cout << r.getPiece() << " " << std::flush;
        }
        std::cout << std::endl;
    }
    std::cout << std::endl; 
}

#include "mondrian.h"

int sumArea(std::set<Rectangle> rs) {
    int sum = 0;
    for (auto r : rs) {
        sum += r.getArea();
    }
    return sum;
}

int getDifference(std::set<Rectangle> rs) {
    if (rs.size() < 2) {
        return MAX;
    }
    int max = MIN, min = MAX;
    for (auto r : rs) {
        if (r.getArea() < min) {
            min = r.getArea();
        }
        if (r.getArea() > max) {
            max = r.getArea();
        }
    }
    return max - min;
}

char Mondrian::getRandomPiece() {
    return (char) (rand() % 78 + 49);
}

Mondrian::Mondrian(int side) {
    std::cout << "\nMondrian difference for " << side << " x " << side << " square.\n" << std::flush;
    this->side = side;
    Grid bestGrid(side);
    for (int length = side; length >= 1; length--) {
        for (int width = length; width >= 1; width--) {
            if (length != side || width != side) {
                rectangles.push_back(Rectangle(length, width));
                subsets.insert({Rectangle(length, width)});
            }
        }
    }
    bestDifference = MAX;
}

void Mondrian::sumToArea() {
    clock_t start;
    double duration;
    start = clock();
    for (std::size_t i = 0; i < rectangles.size(); i++) {
        std::set<std::set<Rectangle>> subsets1 = subsets;
        for (auto s : subsets1) {
            std::set<Rectangle> temp = s;
            temp.insert(rectangles[i]);
            duration = (clock() - start) / (double) CLOCKS_PER_SEC;
            if (duration >= 60) {
                goto timesUp;
            } else if (sumArea(temp) > pow(side, 2)) {
                continue;
            } else if (sumArea(temp) == int(pow(side, 2)) && temp.size() >= 3
                && getDifference(temp) < bestDifference) { 
                validateTemp(temp);
            }
            subsets.insert(temp);
        }
    }
    timesUp:;
}

bool Mondrian::deadGrid(Grid g, std::set<Rectangle> temp) {
    for (auto t : temp) {
        if (g.topLefts(t).size() != 0) {
            return false;
        }
    }
    return true;
}

void Mondrian::validateTemp(std::set<Rectangle> temp) {
    Grid master(side);
    Rectangle r = *temp.begin();
    char piece = getRandomPiece();
    for (int x = 0; x < r.getLength(); x++) {
        for (int y = 0; y < r.getWidth(); y++) {
            master.setCoordinate(x, y, piece);
        }
    }
    r.setPlaced(true);
    Grid testGrid = recursiveGrid(master, temp);
    if (testGrid.getFull()) {
        if (getDifference(temp) < bestDifference) {
            bestDifference = getDifference(temp);
            std::cout << "\nBest Mondrian come up with so far...\n" << std::flush;
            testGrid.display();
            displayRectsProperties(temp);
        }
    }
}

Grid Mondrian::recursiveGrid(Grid master, std::set<Rectangle> temp) {
    if (master.getFull() || deadGrid(master, temp)) {
        return master;
    }
    for (auto it = temp.begin(); it != temp.end(); it++) {
        if (it == temp.begin()) {
            continue;
        } else {
            Rectangle puzzle = *it;
            if (puzzle.getPlaced()) {
                continue;
            } else {
                for (int i = 0; i < 2; i++) {
                    if (i == 1) {
                        puzzle.reverseLW();
                    }
                    char piece = getRandomPiece();
                    for (auto c : master.topLefts(puzzle)) {
                        for (int x = c.getX(); x < c.getX() + puzzle.getLength(); x++) {
                            for (int y = c.getY(); y < c.getY() + puzzle.getWidth(); y++) {
                                master.setCoordinate(x, y, piece);
                            }
                        }
                        puzzle.setPlaced(true);
                        if (recursiveGrid(master, temp).getFull()) {
                            return recursiveGrid(master, temp);
                        }
                        puzzle.setPlaced(false);
                        for (int x = c.getX(); x < c.getX() + puzzle.getLength(); x++) {
                            for (int y = c.getY(); y < c.getY() + puzzle.getWidth(); y++) {
                                master.unsetCoordinate(x, y);
                            }
                        }
                        break;
                    }
                }
            }
        }
    }
    return master;
}

void Mondrian::displayRectsProperties(std::set<Rectangle> rs) {
    std::cout << "Difference: " << getDifference(rs) << std::endl;
    for (auto r : rs) {
        std::cout << r.getLength() << " x " << r.getWidth() << std::endl;
    }
}
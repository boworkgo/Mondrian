#include "mondrian.h"

int main() {
    for (int side = 3; side <= 10; side++) {
        Mondrian m(side);
        m.sumToArea();
    }
    return 0;
}

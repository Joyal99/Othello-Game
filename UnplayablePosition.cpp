#include "UnplayablePosition.h"

UnplayablePosition::UnplayablePosition(int row, int col) : Position(row, col) {
}

bool UnplayablePosition::canPlay() const {
    return false;
}
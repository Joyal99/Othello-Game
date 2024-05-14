#include "Position.h"

Position::Position(int row, int col) : row(row), col(col), disc(' ') {
}

char Position::getDisc() const {
    return disc;
}

void Position::updateDisc(char newDisc) {
    disc = newDisc;
}

bool Position::canPlay() const {
    return false; // By default, a position is unplayable
}

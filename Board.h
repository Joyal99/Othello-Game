#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include "Position.h"

class Board {
public:
    Board() : BOARD_SIZE(8) { // Initialize BOARD_SIZE to 8x8
        initializeBoard();
    }

    void initializeBoard();
    void displayBoard() const;
    Position* getPosition(int row, int col) const;
    bool isValidMove(int row, int col, char disc) const;
    void flipDiscs(int row, int col, char disc);
    std::vector<Position*> getPlayablePositions(char disc) const;

private:
    std::vector<std::vector<Position*>> positions;
};

#endif // BOARD_H
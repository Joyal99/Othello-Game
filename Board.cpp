#include "Board.h"
#include <iostream>
#include <vector>

Board::Board() {
    initializeBoard();
}

void Board::initializeBoard() {
    positions.assign(BOARD_SIZE, std::vector<Position*>(BOARD_SIZE, nullptr));

    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (i == UNPLAYABLE_ROW && j >= UNPLAYABLE_COL) {
                positions[i][j] = new UnplayablePosition(i, j);
            }
            else {
                positions[i][j] = new PlayablePosition(i, j);
            }
        }
    }
}

void Board::displayBoard() const {
    // Implement code to display the current state of the board
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            Position* position = positions[i][j];
            if (position->canPlay()) {
                // Display playable positions differently, e.g., 'X' or 'O'
                std::cout << " " << position->getDisc() << " ";
            }
            else {
                // Display unplayable positions as spaces
                std::cout << "   ";
            }
            if (j < BOARD_SIZE - 1) {
                std::cout << "|";
            }
        }
        std::cout << std::endl;
        if (i < BOARD_SIZE - 1) {
            for (int j = 0; j < BOARD_SIZE; j++) {
                std::cout << "___";
                if (j < BOARD_SIZE - 1) {
                    std::cout << "|";
                }
            }
            std::cout << std::endl;
        }
    }
}

Position* Board::getPosition(int row, int col) const {
    return positions[row][col];
}

Position* Board::getPosition(int row, int col) const {
    return positions[row][col];
}

bool Board::isValidMove(int row, int col, char disc) const {
    // Check if the selected position is empty (playable)
    Position* position = positions[row][col];
    if (!position->canPlay() || position->getDisc() != ' ') {
        return false;
    }

    bool valid = false;

    // Define the directions to check for adjacent discs
    int directions[][2] = {
        {-1, -1}, {-1, 0}, {-1, 1},
        {0, -1},           {0, 1},
        {1, -1}, {1, 0}, {1, 1}
    };

    // Iterate over all directions to check for valid moves
    for (int dir = 0; dir < 8; dir++) {
        int dr = directions[dir][0];
        int dc = directions[dir][1];
        int r = row + dr;
        int c = col + dc;

        // Check if there's an opponent's disc in the current direction
        if (r >= 0 && r < BOARD_SIZE && c >= 0 && c < BOARD_SIZE && positions[r][c]->getDisc() != disc) {
            // Keep moving in the same direction until we find an empty position or the same disc
            while (r >= 0 && r < BOARD_SIZE && c >= 0 && c < BOARD_SIZE) {
                if (positions[r][c]->getDisc() == ' ') {
                    break;  // Found an empty position; the move is invalid in this direction
                }
                if (positions[r][c]->getDisc() == disc) {
                    valid = true;  // Found the same disc; the move is valid in this direction
                    break;
                }
                r += dr;
                c += dc;
            }
        }
    }

    return valid;
}

void Board::flipDiscs(int row, int col, char disc) {
    // Define the directions to check for adjacent discs
    int directions[][2] = {
        {-1, -1}, {-1, 0}, {-1, 1},
        {0, -1},           {0, 1},
        {1, -1}, {1, 0}, {1, 1}
    };

    // Iterate over all directions to flip discs
    for (int dir = 0; dir < 8; dir++) {
        int dr = directions[dir][0];
        int dc = directions[dir][1];
        int r = row + dr;
        int c = col + dc;

        // Check if there's an opponent's disc in the current direction
        if (r >= 0 && r < BOARD_SIZE && c >= 0 && c < BOARD_SIZE && positions[r][c]->getDisc() != disc) {
            // Keep moving in the same direction until we find the same disc
            while (r >= 0 && r < BOARD_SIZE && c >= 0 && c < BOARD_SIZE) {
                if (positions[r][c]->getDisc() == ' ') {
                    break;  // Found an empty position; stop flipping discs
                }
                if (positions[r][c]->getDisc() == disc) {
                    // Found the same disc; backtrack and flip the discs
                    r -= dr;
                    c -= dc;
                    while (r != row || c != col) {
                        positions[r][c]->updateDisc(disc);
                        r -= dr;
                        c -= dc;
                    }
                    break;
                }
                r += dr;
                c += dc;
            }
        }
    }
}

std::vector<Position*> Board::getPlayablePositions(char disc) const {
    std::vector<Position*> playablePositions;

    // Define the directions to check for adjacent discs
    int directions[][2] = {
        {-1, -1}, {-1, 0}, {-1, 1},
        {0, -1},           {0, 1},
        {1, -1}, {1, 0}, {1, 1}
    };

    // Iterate over all positions on the board
    for (int row = 0; row < BOARD_SIZE; row++) {
        for (int col = 0; col < BOARD_SIZE; col++) {
            Position* position = positions[row][col];

            if (!position->canPlay() || position->getDisc() != ' ') {
                continue; // Skip unplayable positions or positions already occupied
            }

            bool valid = false;

            // Iterate over all directions to check for valid moves
            for (int dir = 0; dir < 8; dir++) {
                int dr = directions[dir][0];
                int dc = directions[dir][1];
                int r = row + dr;
                int c = col + dc;

                // Check if there's an opponent's disc in the current direction
                if (r >= 0 && r < BOARD_SIZE && c >= 0 && c < BOARD_SIZE && positions[r][c]->getDisc() != disc) {
                    // Keep moving in the same direction until we find the same disc
                    while (r >= 0 && r < BOARD_SIZE && c >= 0 && c < BOARD_SIZE) {
                        if (positions[r][c]->getDisc() == ' ') {
                            break;  // Found an empty position; the move is invalid in this direction
                        }
                        if (positions[r][c]->getDisc() == disc) {
                            valid = true;  // Found the same disc; the move is valid in this direction
                            break;
                        }
                        r += dr;
                        c += dc;
                    }
                }
            }

            if (valid) {
                // The position is a valid move; add it to the list of playable positions
                playablePositions.push_back(position);
            }
        }
    }

    return playablePositions;
}
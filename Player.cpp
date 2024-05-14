#include "Player.h"
#include "board.h" 

Player::Player(const std::string& name, char disc) : name(name), disc(disc) {
}

std::string Player::getName() const {
    return name;
}

char Player::getDisc() const {
    return disc;
}

bool Player::canMove(const Board& board) const {
    // Get the list of playable positions for the player's disc
    std::vector<Position*> playablePositions = board.getPlayablePositions(disc);

    // Check if there are any playable positions
    return !playablePositions.empty();
}


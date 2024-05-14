#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>

class Player {
public:
    Player(const std::string& name, char disc);

    std::string getName() const;
    char getDisc() const;
    bool canMove(const Board& board) const;

private:
    std::string name;
    char disc;
};

#endif // PLAYER_H
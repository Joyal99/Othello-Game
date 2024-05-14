#include "Board.h"
#include "Player.h"
#include <string>
#include <vector>

#ifndef GAME_H
#define GAME_H

class Game
{
public:
    Game();
    void startNewGame();
    void loadGame(const std::string& filename);
    void playGame();

private:
    Board board;
    std::vector<Player> players;
    int currentPlayerIndex;

    bool gameOver();
    bool displayBoard();
    std::string checkforWinner();
};


#endif //GAME_H


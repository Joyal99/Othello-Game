#include "Game.h"
#include "Player.h"
#include <iostream>
#include <fstream>

Game::Game() {
    board = Board();
    players.push_back(Player("Player 1", 'X'));
    players.push_back(Player("Player 2", 'O'));
    currentPlayerIndex = 0;
}

void Game::startNewGame() {
    // Initialize the game board
    board.initializeBoard();

    // Prompt for player names (you can customize the input method)
    std::string player1Name, player2Name;
    std::cout << "Enter Player 1 name: ";
    std::cin >> player1Name;
    std::cout << "Enter Player 2 name: ";
    std::cin >> player2Name;

    // Create player objects
    players[0] = Player(player1Name, 'X');
    players[1] = Player(player2Name, 'O');

    // Decide who starts (you can randomize this)
    currentPlayerIndex = 0;

    // Display the initial board
    displayBoard();
}

void Game::loadGame(const std::string& filename) {
    std::ifstream file(filename);
    if (file.is_open()) {
        // Read the first three lines of the file for player names and the current player
        std::string player1Name, player2Name;
        char currentPlayerDisc;

        std::getline(file, player1Name); // Read Player 1 name
        std::getline(file, player2Name); // Read Player 2 name
        file >> currentPlayerDisc; // Read the current player's disc

        // Create player objects based on the read information
        players[0] = Player(player1Name, 'X');
        players[1] = Player(player2Name, 'O');

        // Determine the current player index
        if (currentPlayerDisc == 'X') {
            currentPlayerIndex = 0;
        }
        else if (currentPlayerDisc == 'O') {
            currentPlayerIndex = 1;
        }
        else {
            std::cout << "Error: Invalid player disc in the save file." << std::endl;
            return;
        }

        // Read the last line of the file for the board state
        std::vector<std::vector<char>> boardState(BOARD_SIZE, std::vector<char>(BOARD_SIZE));
        for (int i = 0; i < BOARD_SIZE; i++) {
            for (int j = 0; j < BOARD_SIZE; j++) {
                file >> boardState[i][j];
            }
        }

        // Set up the game board with the loaded state
        board.loadBoard(boardState);

        // Close the file
        file.close();

        // Notify the user that the game has been loaded
        std::cout << "Game loaded successfully from '" << filename << "'." << std::endl;
    }
    else {
        std::cout << "Error: Unable to open the specified file." << std::endl;
    }
}

void Game::play() {
    while (!gameOver()) {
        displayBoard();
        Player& currentPlayer = players[currentPlayerIndex];

        if (currentPlayer.canMove(board)) {
            std::cout << "It's " << currentPlayer.getName() << "'s turn (" << currentPlayer.getDisc() << ")." << std::endl;

            int row, col;

            // Get the player's move (row, col)
            std::cout << "Enter your move (row col): ";
            std::cin >> row >> col;

            // Check if the move is within the board and a valid play
            if (row >= 0 && row < BOARD_SIZE && col >= 0 && col < BOARD_SIZE) {
                Position* position = board.getPosition(row, col);

                if (position->canPlay()) {
                    // Check if the move is valid and flips discs
                    if (board.isValidMove(row, col, currentPlayer.getDisc())) {
                        // Update the position with the player's disc
                        position->updateDisc(currentPlayer.getDisc());

                        // Flip the discs according to the Othello rules
                        board.flipDiscs(row, col, currentPlayer.getDisc());
                    }
                    else {
                        std::cout << "Invalid move. It does not flip any discs." << std::endl;
                    }
                }
                else {
                    std::cout << "Invalid move. The position is not playable." << std::endl;
                }
            }
            else {
                std::cout << "Invalid move. Row and column values should be within the board." << std::endl;
            }
        }
        else {
            std::cout << currentPlayer.getName() << " can't make a move." << std::endl;
        }

        // Switch to the next player
        currentPlayerIndex = (currentPlayerIndex + 1) % players.size();
    }

    // Handle the end of the game
    displayBoard();
    std::string winner = determineWinner();
    if (winner.empty()) {
        std::cout << "It's a tie!" << std::endl;
    }
    else {
        std::cout << "Game over. Winner: " << winner << std::endl;
    }
}

bool Game::gameOver() {
    // Implement logic to check if the game is over
    return false; // Placeholder
}

void Game::displayBoard() {
    // Implement code to display the current state of the board
    board.displayBoard();
}

std::string Game::determineWinner() {
    // Implement logic to determine the winner and return the player's name
    return "Player X"; // Placeholder
}
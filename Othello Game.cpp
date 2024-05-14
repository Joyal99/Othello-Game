#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

//Contents for board size
const int BOARD_SIZE = 8;
const char EMPTY = ' ';
const char BLACK = 'X';
const char WHITE = 'O';

int main() {

    std::cout << "*****************************\n";
    std::cout << "Welcome to the Othello Game! \n";
    std::cout << "*****************************\n";

    //Game game;
    int choice;
 
    std::cout << "1. Start a New Game\n";
    std::cout << "2. Quit Game\n";
    std::cout << "3. Load a Game\n";
    std::cout << "Enter your choice: ";
    std::cin >> choice;

    switch (choice) {
    case 1:
        //game.startNewGame();
       // game.play();
        break;

    case 2:
        std::cout << "\nThanks for playing! This game is quitting.....!\n";
        break;
        //End Program

    case 3:
        //game.loadNewGame();

    default:
        std::cout << "\nYou have inputted an invalid option! Please try again!\n";
        break;


    }

	return 0;
}


    /*Game game;
    int choice;

    cout << "1. Start a New Game\n2. Quit\n3. Load a Game\n";
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
    case 1:
        game.startNewGame();
        game.play();
        break;
    case 2:
        // Quit the game
        break;
    case 3:
        string filename;
        cout << "Enter the filename to load the game: ";
        cin >> filename;
        game.loadGame(filename);
        game.play();
        break;
    default:
        cout << "Invalid choice.\n";
        break;
    }




int main() {

    std::cout << "********************************************\n";
    std::cout << "Welcome to Game :)\n";
    std::cout << "********************************************\n";

    Game::LoadData("db/General.txt");

    std::cout << "availblale operations :\n\n";

    int option = 0;

    while (option < 1 || option > 3) {

        std::cout << "1)Start a new Game\n";;
        std::cout << "2)Load a Game\n";
        std::cout << "3)Exit\n";

        std::cout << "enter operation number: ";
        std::cin >> option;

        if (option == 3)
            break;

        switch (option)
        {
        case 1:
            StartGame();
            break;
        case 2:
            LoadGame();
            break;
        default:
            std::cout << "incorrect number\n";
            break;
        }

    }


    while (true)
    {
        Game::render();
        Game::TakeTurn();
    }



    return 0;
}

void StartGame() {

    int initialMapsNum = Game::getInitialMapsSize();




    std::string name1, name2;
    std::cout << "\nplease enter player1 name: ";
    std::cin >> name1;
    std::cout << "\nplease enter player2 name: ";
    std::cin >> name2;

    int option = 0;
    while (true)
    {
        std::cout << "\nplease choose the initial map layout (1 - " << initialMapsNum << " ):";
        std::cin >> option;
        if (option <= initialMapsNum && option > 0)
            break;
        std::cout << "\nplease don't be an asshole and write a correct number MF\n";
    }




    Game::StartGame(option, name1, name2);

}

void LoadGame() {

    std::cout << "please make me :(";

}*/
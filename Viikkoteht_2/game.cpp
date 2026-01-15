#include "game.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;


Game::Game(int maxNum)
{
    maxNumber = maxNum;
    numOfGuesses = 0;

    srand(time(0));
    randomNumber = rand() % (maxNumber + 1);

    cout << "GAME CONSTRUCTOR: object initialized with " << maxNumber << " as a maximum value" << endl;
}

Game::~Game()
{
    printGameResult();
    cout << "GAME DESTRUCTOR: object cleared from stack memory" << endl;
}

void Game::play()
{
    while (playerGuess != randomNumber){

        numOfGuesses ++;
        cout << "Guess a number between 1 and " << maxNumber << endl;
        cin >> playerGuess;

        if (playerGuess < randomNumber){
            cout << "Too small" << endl;
        }
        else if (playerGuess > randomNumber){
            cout << "Too big" << endl;
        }
        else {
            cout << "Your guess is right = " << playerGuess << endl;
        }
    }
}

void Game::printGameResult()
{
    cout << "You guessed the right number = " << playerGuess;
    cout << " with " << numOfGuesses << " guesses." << endl;
}

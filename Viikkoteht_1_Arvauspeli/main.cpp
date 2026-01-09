#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int masterNum;
int playerNum;
int guessCount;

int game(int maxNum);

int main()
{
    game(40);

    return 0;
}

int game(int maxNum) {

    int guessCount = 0;

    srand(time(0));
    int masterNum = rand() % maxNum + 1;

    while (playerNum != masterNum){

        guessCount ++;
        cout << "Guess a number between 1 and " << maxNum << endl;
        cin >> playerNum;

        if (playerNum < masterNum){
            cout << "Too small" << endl;
        }
        else if (playerNum > masterNum){
            cout << "Too big" << endl;
        }
        else {
            cout << "Thats correct!" << endl;
            cout << "You guessed " << guessCount << " times." << endl;
        }
    }
}

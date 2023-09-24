#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
    // Seed the random number generator with the current time
    srand(static_cast<unsigned int>(time(nullptr)));

    // Generate a random number between 1 and 100
    int secretNumber = rand() % 100 + 1;

    int tries = 0;
    int guess;

    cout << "Welcome to the Number Guessing Game!" << endl;
    cout << "I have selected a number between 1 and 100. Try to guess it." << endl;

    while (true)
    {
        cout << "Enter your guess: ";
        cin >> guess;
        tries++;

        if (guess == secretNumber)
        {
            cout << "Congratulations! You guessed the number in " << tries << " tries." << endl;
            break;
        }
        else if (guess < secretNumber)
        {
            cout << "Too low. Try again." << endl;
        }
        else
        {
            cout << "Too high. Try again." << endl;
        }
    }
    return 0;
}

#include <iostream>
#include <random>
#include <limits>

using namespace std;

int rollDice(int diceSides, int diceCount) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> distribution(1, diceSides);

    int totalRoll = 0;
    cout << "Results: ";

    for (int i = 0; i < diceCount; i++) {
        int diceRoll = distribution(gen);
        cout << diceRoll << " ";
        totalRoll += diceRoll;
    }

    cout << endl << "Total: " << totalRoll << endl;
    return totalRoll;
}

bool getUserChoice() {
    char choice;
    cout << "Roll again? (y/n): ";
    cin >> choice;

    while (choice != 'y' && choice != 'Y' && choice != 'n' && choice != 'N') {
        cout << "Invalid input. Enter Y/N (Yes/No): ";
        cin >> choice;
    }

    return (choice == 'y' || choice == 'Y');
}

int main() {
    bool flag = true;

    cout << "Welcome to the DnD Dice Roller!" << endl;

    while (flag) {
        int diceSides;
        int diceCount;

        while (flag) {
            cout << "Sides of dice: ";
            cin >> diceSides;

            if (cin.fail() || diceSides <= 0) {
                cout << "Invalid input. Enter a positive number." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            } else {
                break;
            }
        }

        while (flag) {
            cout << "Number of dice: ";
            cin >> diceCount;

            if (cin.fail() || diceCount <= 0) {
                cout << "Invalid input. Enter a positive number." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            } else {
                break;
            }
        }

        cout << "Rolling " << diceCount << " dice with " << diceSides << " sides..." << endl;
        int totalRoll = rollDice(diceSides, diceCount);

        if (!getUserChoice()) {
            break;
        }
    }

    return 0;
}

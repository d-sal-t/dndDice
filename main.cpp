#include <iostream>
#include <random>
#include <limits>

using namespace std;

int main() {
    random_device rd;
    mt19937 gen(rd());

    cout << "Welcome to the DnD Dice Roller!" << endl;

    while (true) {
        int diceSides;
        int diceCount;
        int totalRoll = 0;

        while (true) {
            cout << "Sides of dice: ";
            cin >> diceSides;

            if (cin.fail()) {
                cout << "Invalid input. Please enter a positive number." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            } else if (diceSides <= 0) {
                cout << "Invalid input. Please enter a positive number." << endl;
            } else {
                break;
            }
        }

        while (true) {
            cout << "Number of dice: ";
            cin >> diceCount;

            if (cin.fail()) {
                cout << "Invalid input. Please enter a positive number." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            } else if (diceCount <= 0) {
                cout << "Invalid input. Please enter a positive number." << endl;
            } else {
                break;
            }
        }

        cout << "Rolling " << diceCount << " dice with " << diceSides << " sides..." << endl;
        cout << "Results: ";

        uniform_int_distribution<int> distribution(1, diceSides);

        for (int i = 0; i < diceCount; i++) {
            int diceRoll = distribution(gen);
            cout << diceRoll << " ";
            totalRoll += diceRoll;
        }

        cout << endl << "Total: " << totalRoll << endl;

        char choice;
        cout << "Roll again? (y/n): ";
        cin >> choice;
         
        while (choice != 'y' && choice != 'Y' && choice != 'n' && choice != 'N') {
            cout << "Invalid input. Enter Y/N (Yes/No).";
            cin >> choice;
        } 
       

        if (choice != 'y' && choice != 'Y') {
            break;
        }
    }

    return 0;
}

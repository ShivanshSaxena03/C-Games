#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

char getComputerChoice() {
    int random = rand() % 3;
    if (random == 0) return 's';  // Snake
    if (random == 1) return 'w';  // Water
    return 'g';                   // Gun
}

string getChoiceName(char choice) {
    if (choice == 's') return "Snake";
    if (choice == 'w') return "Water";
    return "Gun";
}

int determineWinner(char player, char computer) {
    if (player == computer) return 0; // Draw

    // Snake vs Water -> Snake wins
    // Water vs Gun -> Water wins
    // Gun vs Snake -> Gun wins
    if ((player == 's' && computer == 'w') ||
        (player == 'w' && computer == 'g') ||
        (player == 'g' && computer == 's')) {
        return 1; // Player wins
    }
    return -1; // Computer wins
}

int main() {
    srand(time(0));
    char playerChoice, computerChoice;
    string name;

    cout << "Welcome to Snake-Water-Gun Game!\n";
    cout << "Enter your name: ";
    getline(cin, name);

    cout << "\nChoose:\n's' for Snake\n'w' for Water\n'g' for Gun\n";
    cout << "Enter your choice: ";
    cin >> playerChoice;

    computerChoice = getComputerChoice();

    cout << "\n" << name << " chose: " << getChoiceName(playerChoice) << endl;
    cout << "Computer chose: " << getChoiceName(computerChoice) << endl;

    int result = determineWinner(playerChoice, computerChoice);
    if (result == 0)
        cout << "\nIt's a draw!\n";
    else if (result == 1)
        cout << "\nYou win! \n";
    else
        cout << "\nComputer wins! \n";

    return 0;
}

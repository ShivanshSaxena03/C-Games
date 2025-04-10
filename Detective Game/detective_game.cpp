#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Suspect class
class Suspect {
public:
    string name;
    string alibi;
    bool guilty;
    string response;

    Suspect(string n, string a, string r, bool g) {
        name = n;
        alibi = a;
        response = r;
        guilty = g;
    }

    void interrogate() {
        cout << "\nInterrogating " << name << "...\n";
        cout << "Alibi: " << alibi << "\n";
        cout << "Response: " << response << "\n";
    }
};

// Clue class
class Clue {
public:
    string location;
    string detail;

    Clue(string l, string d) {
        location = l;
        detail = d;
    }

    void showClue() {
        cout << "\nClue found at " << location << ": " << detail << "\n";
    }
};

// Main Game class
class DetectiveGame {
private:
    vector<Suspect> suspects;
    vector<Clue> clues;
    int chances;

public:
    DetectiveGame() {
        chances = 3; // Player ke paas 3 chances hain

        // Suspects initialize
        suspects.push_back(Suspect("Mr. Brown (Butler)", "I was cleaning the dining hall.", "I heard a scream but did not see anything.", false));
        suspects.push_back(Suspect("Miss Scarlet (Actress)", "I was rehearsing my lines.", "Why would I kill anyone? I am too pretty for jail!", false));
        suspects.push_back(Suspect("Dr. Grey (Family Friend)", "I was reading in the library.", "This family has secrets... but I am not one of them.", true));
        suspects.push_back(Suspect("Lady Violet (Widow)", "I was sleeping in my room.", "My husband is gone... now this? I am devastated.", false));

        // Clues initialize
        clues.push_back(Clue("Library", "A bloody glove was found near the bookshelf."));
        clues.push_back(Clue("Kitchen", "A broken vase with fingerprints was discovered."));
        clues.push_back(Clue("Garden", "Footprints leading away from the house."));
    }

    void showIntro() {
        cout << "-------------------------------------\n";
        cout << " DETECTIVE MYSTERY GAME \n";
        cout << "-------------------------------------\n";
        cout << "You are Detective Shivansh. A murder has occurred in the mansion.\n";
        cout << "Interrogate suspects, investigate clues, and catch the killer!\n";
    }

    void interrogateSuspects() {
        cout << "\nList of Suspects:\n";
        for (int i = 0; i < suspects.size(); i++) {
            cout << i + 1 << ". " << suspects[i].name << endl;
        }

        int choice;
        cout << "\nEnter suspect number to interrogate: ";
        cin >> choice;

        if (choice >= 1 && choice <= suspects.size()) {
            suspects[choice - 1].interrogate();
        } else {
            cout << "Invalid choice.\n";
        }
    }

    void investigateClues() {
        cout << "\nInvestigating mansion...\n";
        for (int i = 0; i < clues.size(); i++) {
            clues[i].showClue();
        }
    }

    void makeGuess() {
        cout << "\nWho do you think is the murderer?\n";
        for (int i = 0; i < suspects.size(); i++) {
            cout << i + 1 << ". " << suspects[i].name << endl;
        }

        int guess;
        cout << "\nEnter number of your guess: ";
        cin >> guess;

        if (guess >= 1 && guess <= suspects.size()) {
            if (suspects[guess - 1].guilty) {
                cout << "\nCorrect! You caught the killer: " << suspects[guess - 1].name << "!\n";
            } else {
                chances--;
                cout << "\nWrong guess! Chances left: " << chances << "\n";
                if (chances > 0) {
                    makeGuess(); // Recursive retry
                } else {
                    cout << "\nGame Over! The real killer was: Dr. Grey.\n";
                }
            }
        } else {
            cout << "Invalid choice.\n";
        }
    }

    void startGame() {
        showIntro();

        int option;
        do {
            cout << "\nMenu:\n1. Interrogate Suspect\n2. Investigate Clues\n3. Make Accusation\n4. Exit\nEnter choice: ";
            cin >> option;

            switch (option) {
                case 1:
                    interrogateSuspects();
                    break;
                case 2:
                    investigateClues();
                    break;
                case 3:
                    makeGuess();
                    break;
                case 4:
                    cout << "Exiting game. Goodbye, Detective!\n";
                    break;
                default:
                    cout << "Invalid option!\n";
            }
        } while (option != 4 && chances > 0);
    }
};

int main() {
    DetectiveGame game;
    game.startGame();
    return 0;
}

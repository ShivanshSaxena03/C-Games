#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int playerHP = 100;
int enemyHP = 100;

// Show current health
void showStatus() {
    cout << "\n🚀 Your HP: " << playerHP << " | 👾 Alien HP: " << enemyHP << "\n";
}

// Player move
void playerTurn() {
    int choice;
    cout << "\nYour Move:\n1. Attack 🔫\n2. Shield 🛡️\n3. Heal 💊\nEnter choice: ";
    cin >> choice;

    switch (choice) {
        case 1: {
            int damage = rand() % 21 + 10; // 10-30 damage
            enemyHP -= damage;
            cout << "You attacked and dealt " << damage << " damage!\n";
            break;
        }
        case 2: {
            cout << "You raised your shield! You will take reduced damage next turn.\n";
            break;
        }
        case 3: {
            int heal = rand() % 16 + 10; // 10-25 heal
            playerHP += heal;
            if (playerHP > 100) playerHP = 100;
            cout << "You healed yourself for " << heal << " HP.\n";
            break;
        }
        default:
            cout << "Invalid choice. You missed your turn!\n";
    }
}

// Enemy move
void enemyTurn(bool playerShielded) {
    int move = rand() % 3 + 1;

    if (move == 1) {
        int damage = rand() % 16 + 10; // 10-25
        if (playerShielded) {
            damage /= 2;
            cout << "Alien attacked but your shield reduced the damage!\n";
        } else {
            cout << "Alien attacked fiercely!\n";
        }
        playerHP -= damage;
        cout << "You received " << damage << " damage.\n";
    } else if (move == 2) {
        int heal = rand() % 11 + 5; // 5-15 heal
        enemyHP += heal;
        if (enemyHP > 100) enemyHP = 100;
        cout << "Alien used alien-serum and healed " << heal << " HP.\n";
    } else {
        cout << "Alien is charging power... skipped its turn!\n";
    }
}

int main() {
    srand(time(0));
    cout << "🚀 Welcome to SPACE BATTLE! 👾\n";
    cout << "You are Earth's last hope against the alien invader!\n";

    while (playerHP > 0 && enemyHP > 0) {
        showStatus();

        bool shield = false;
        int choice;
        cout << "\n=== Your Turn ===\n";
        cout << "1. Attack 🔫\n2. Shield 🛡️\n3. Heal 💊\nEnter your move: ";
        cin >> choice;

        if (choice == 1) {
            int damage = rand() % 21 + 10;
            enemyHP -= damage;
            cout << "You fired your blaster! Damage dealt: " << damage << "\n";
        } else if (choice == 2) {
            cout << "You activated shield! Incoming damage will be halved.\n";
            shield = true;
        } else if (choice == 3) {
            int heal = rand() % 16 + 10;
            playerHP += heal;
            if (playerHP > 100) playerHP = 100;
            cout << "You used med-kit. Healed " << heal << " HP.\n";
        } else {
            cout << "Wrong input! You lost your turn.\n";
        }

        if (enemyHP <= 0) break;

        cout << "\n--- Alien's Turn ---\n";
        enemyTurn(shield);
    }

    cout << "\n============================\n";
    if (playerHP <= 0)
        cout << "💀 You lost! The alien invader destroyed Earth!\n";
    else
        cout << "🎉 Victory! You saved Earth from the alien!\n";
    cout << "============================\n";

    return 0;
}

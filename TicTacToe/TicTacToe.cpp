#include <iostream>
using namespace std;

char board[3][3]; // 3x3 game board

// Function to initialize the board with numbers 1 to 9
void initializeBoard() {
    char start = '1';
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = start++;
        }
    }
}

// Function to display the current board
void displayBoard() {
    cout << "\n";
    for (int i = 0; i < 3; i++) {
        cout << " ";
        for (int j = 0; j < 3; j++) {
            cout << board[i][j];
            if (j < 2) cout << " | ";
        }
        if (i < 2) cout << "\n-----------\n";
    }
    cout << "\n\n";
}

// Function to check if a player has won
bool checkWin(char mark) {
    // Check rows, columns, and diagonals
    for (int i = 0; i < 3; i++)
        if ((board[i][0] == mark && board[i][1] == mark && board[i][2] == mark) ||
            (board[0][i] == mark && board[1][i] == mark && board[2][i] == mark))
            return true;

    if ((board[0][0] == mark && board[1][1] == mark && board[2][2] == mark) ||
        (board[0][2] == mark && board[1][1] == mark && board[2][0] == mark))
        return true;

    return false;
}

// Function to check if board is full
bool isDraw() {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i][j] != 'X' && board[i][j] != 'O')
                return false;
    return true;
}

// Function to make a move
bool makeMove(int position, char mark) {
    int row = (position - 1) / 3;
    int col = (position - 1) % 3;

    if (position < 1 || position > 9 || board[row][col] == 'X' || board[row][col] == 'O') {
        cout << "Invalid move! Try again.\n";
        return false;
    }

    board[row][col] = mark;
    return true;
}

int main() {
    int move;
    char currentPlayer = 'X';

    initializeBoard();

    cout << "Welcome to Tic Tac Toe!\n";
    displayBoard();

    while (true) {
        cout << "Player " << currentPlayer << ", enter your move (1-9): ";
        cin >> move;

        if (makeMove(move, currentPlayer)) {
            displayBoard();

            if (checkWin(currentPlayer)) {
                cout << "Player " << currentPlayer << " wins!\n";
                break;
            }

            if (isDraw()) {
                cout << "It's a draw!\n";
                break;
            }

            // Switch players
            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        }
    }

    return 0;
}


#include <bits/stdc++.h>
using namespace std;
class TicTacToe {
private:
    char board[3][3];       // The game board
    char userMarker;        // Marker for the user X
    char computerMarker;    // Marker for the computer O

    public:
    TicTacToe() {
        initializeBoard();      // Initialize the game board
        userMarker = 'X';
        computerMarker = 'O';
    }
    // Initialize the game board with empty spaces
    void initializeBoard() {
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                board[i][j] = ' ';
            }
        }
    }

    // Print the current state of the game board
    void printBoard() {
        cout << "   1   2   3" << endl;
        cout << "  -------------" << endl;
        for (int i = 0; i < 3; ++i) {
            cout << i + 1 << " |";
            for (int j = 0; j < 3; ++j) {
                cout << " " << board[i][j] << " ";
                if (j < 2) cout << "|";
            }
            cout << " |" << endl;
            cout << "  -------------" << endl;
        }
    }
};


int main()
{

    TicTacToe game;
    game.initializeBoard();
    game.printBoard();

    return 0;

}

/* This Project is created by 23CS014-Priyanshu Chaniyara, 23CS004-Zeel Barvaliya, 23CS002- Krish Babariya*/
// Console-based Tic Tac Toe game in C++ featuring player vs. computer gameplay. Enjoy classic fun in a simple, user-friendly interface
#include <bits/stdc++.h>
#include <cstdlib>
#include <ctime>

using namespace std;

class TicTacToe
{
private:
    char board[3][3];       // The game board
    char userMarker;        // Marker for the user X
    char computerMarker;    // Marker for the computer 0
    bool userTurn;          // Indicates whether it's the user's turn
    bool gameOver;          // Indicates whether the game is over

public:
    TicTacToe()
    {
        initializeBoard();      // Initialize the game board
        userMarker = 'X';
        computerMarker = 'O';
        userTurn = true;        // User starts the game
        gameOver = false;       // Game is not over initially
    }

    // Initialize the game board with empty spaces
    void initializeBoard()
    {
        for (int i = 0; i < 3; ++i)
        {
            for (int j = 0; j < 3; ++j)
            {
                board[i][j] = ' ';
            }
        }
    }

    // Print the current state of the game board
    void printBoard()
    {
        cout << "   1   2   3" << endl;
        cout << "  -------------" << endl;
        for (int i = 0; i < 3; ++i)
        {
            cout << i + 1 << " |";
            for (int j = 0; j < 3; ++j)
            {
                cout << " " << board[i][j] << " ";
                if (j < 2) cout << "|";
            }
            cout << " |" << endl;
            cout << "  -------------" << endl;
        }
    }

    // Switch turns between user and computer
    void switchTurn()
    {
        userTurn = !userTurn;
    }

    // Check if a move at a given row and column is valid
    bool isValidMove(int row, int col)
    {
        return row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ';
    }

    // Check if the specified marker has won the game
    bool checkWin(char marker)
    {
        // Check rows
        for (int i = 0; i < 3; ++i)
        {
            if (board[i][0] == marker && board[i][1] == marker && board[i][2] == marker)
            {
                return true;
            }
        }
        // Check columns
        for (int j = 0; j < 3; ++j)
        {
            if (board[0][j] == marker && board[1][j] == marker && board[2][j] == marker)
            {
                return true;
            }
        }
        // Check diagonals
        if ((board[0][0] == marker && board[1][1] == marker && board[2][2] == marker) ||
                (board[0][2] == marker && board[1][1] == marker && board[2][0] == marker))
        {
            return true;
        }
        return false;
    }

    // Check if the board is full - No further places in board
    bool boardFull()
    {
        for (int i = 0; i < 3; ++i)
        {
            for (int j = 0; j < 3; ++j)
            {
                if (board[i][j] == ' ')
                {
                    return false;
                }
            }
        }
        return true;
    }

    // Handle the user's move
    void userMove()
    {
        int row, col;
        cout << "Enter your move (row and column): ";
        cin >> row >> col;
        row--; // Adjust for 0-based indexing
        col--;

        if (isValidMove(row, col))
        {
            board[row][col] = userMarker;
            if (checkWin(userMarker))
            {
                cout << "Congratulations! You win!" << endl;
                gameOver = true;
            }
            else if (boardFull())
            {
                cout << "It's a draw!" << endl;
                gameOver = true;
            }
        }
        else
        {
            cout << "Invalid move. Try again." << endl;
            userMove(); // Recursive call until a valid move is made
        }
    }

    // Handle the computer's move
    void computerMove()
    {
        cout << "Computer's move:" << endl;
        int row, col;
        do
        {
            row = rand() % 3;
            col = rand() % 3;
        }
        while (!isValidMove(row, col));
        board[row][col] = computerMarker;

        if (checkWin(computerMarker))
        {
            cout << "Computer wins!" << endl;
            gameOver = true;
        }
        else if (boardFull())
        {
            cout << "It's a draw!" << endl;
            gameOver = true;
        }
    }

    // Start and control the game
    void play()
    {
        srand(time(0)); // Seed random number generator
        while (!gameOver)
        {
            printBoard();
            if (userTurn)
            {
                userMove();
            }
            else
            {
                computerMove();
            }
            switchTurn();
        }
        printBoard();
    }
};

int main()
{
    TicTacToe game;
    game.play();
    return 0;
}

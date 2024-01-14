#include <iostream>
#include <vector>
using namespace std;

class TicTacToe
{
private:
    vector<vector<char>> board;
    char currentPlayer;

public:
    TicTacToe() : board(3, vector<char>(3, ' ')), currentPlayer('X') {}

    void displayBoard() const
    {
        cout << "~~~~~~~~~~~~~~~~\n";
        cout << "Current Board:\n";
        cout << "  1 2 3\n";
        for (int i = 0; i < 3; ++i)
        {
            cout << i + 1 << " ";
            for (int j = 0; j < 3; ++j)
            {
                cout << board[i][j] << ' ';
            }
            cout << '\n';
        }
        cout << "~~~~~~~~~~~~~~~~\n";
    }

    void getPlayerMove()
    {
        int row, col;
        do
        {
            cout << "Player " << currentPlayer << ", enter your move (row and column): ";
            cin >> row >> col;
        } while (!isValidMove(row, col));

        board[row - 1][col - 1] = currentPlayer;
    }

    bool checkForWin() const
    {
        for (int i = 0; i < 3; ++i)
        {
            if (board[i][0] == currentPlayer && board[i][1] == currentPlayer && board[i][2] == currentPlayer)
            {
                return true;
            }
            if (board[0][i] == currentPlayer && board[1][i] == currentPlayer && board[2][i] == currentPlayer)
            {
                return true; // Column win
            }
        }
        if (board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer)
        {
            return true;
        }
        if (board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer)
        {
            return true;
        }

        return false;
    }

    bool checkForDraw() const
    {
        for (const auto &row : board)
        {
            for (char cell : row)
            {
                if (cell == ' ')
                {
                    return false;
                }
            }
        }
        return true;
    }

    void switchPlayers()
    {
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    void playGame()
    {
        do
        {
            displayBoard();
            getPlayerMove();
            if (checkForWin())
            {
                displayBoard();
                cout << "Player " << currentPlayer << " wins!\n";
                break;
            }
            if (checkForDraw())
            {
                displayBoard();
                cout << "The game is a draw!\n";
                break;
            }
            switchPlayers();
        } while (true);

        cout << "Do you want to play again? (Y/N): ";
        char playAgain;
        cin >> playAgain;
        if (playAgain == 'Y' || playAgain == 'y')
        {
            resetGame();
            playGame();
        }
        else
        {
            cout << "~~~~~~~~~~~~~~~~\n";
            cout << "Thanks for playing!\n";
        }
    }

private:
    bool isValidMove(int row, int col) const
    {
        return (row >= 1 && row <= 3 && col >= 1 && col <= 3 && board[row - 1][col - 1] == ' ');
    }

    void resetGame()
    {
        board = vector<vector<char>>(3, vector<char>(3, ' '));
        currentPlayer = 'X';
    }
};

int main()
{
    TicTacToe game;
    game.playGame();

    return 0;
}

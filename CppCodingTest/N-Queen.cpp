#include <iostream>
#include <vector>

using namespace std;

void printBoard(const vector<vector<int>> &board, int n)
{
    cout << "=======" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (board[i][j] == 1)
            {
                cout << "Q ";
            }
            else
            {
                cout << ". ";
            }
        }
        cout << endl;
    }
    cout << "=======" << endl;
}

bool isSafe(const vector<vector<int>> &board, int row, int col, int n)
{
    for (int i = 0; i < row; i++)
    {
        if (board[i][col] == 1)
        {
            return false;
        }   
    }

    for (int i = 1; i <= row; i++)
    {
        if ((col - i >= 0 && board[row - i][col - i]) || (col + i < n && board[row - i][col + i]))
        {
            return false;
        }
    }

    return true;
}

void solveNQueens(vector<vector<int>> &board, int row, int n)
{
    if (row == n)
    {
        printBoard(board, n);
        return;
    }

    for (int i = 0; i < n; i++)
    {
        if (isSafe(board, row, i, n))
        {
            board[row][i] = 1;
            solveNQueens(board, row + 1, n);
            board[row][i] = 0;
        }
    }
}

int main(void)
{
    int n = 4;
    vector<vector<int>> board(n, vector<int>(n, 0));
    solveNQueens(board, 0, n);

    return 0;
}
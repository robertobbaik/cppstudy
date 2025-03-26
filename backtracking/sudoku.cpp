#include <vector>
#include <iostream>

using namespace std;

vector<vector<int>> board = {
    {0, 3, 5, 4, 6, 9, 2, 7, 8},
    {7, 8, 2, 1, 0, 5, 6, 0, 9},
    {0, 6, 0, 2, 7, 8, 1, 3, 5},
    {3, 2, 1, 0, 4, 6, 8, 9, 7},
    {8, 0, 4, 9, 1, 3, 5, 0, 6},
    {5, 9, 6, 8, 2, 0, 4, 1, 3},
    {9, 1, 7, 6, 5, 2, 0, 8, 0},
    {6, 0, 3, 7, 0, 1, 9, 5, 2},
    {2, 5, 8, 3, 9, 4, 7, 6, 0}};

vector<pair<int, int>> blank;

bool isValid(pair<int, int> point, int num)
{
    for (int i = 0; i < board.size(); ++i)
    {
        if (board[point.first][i] == num)
            return false;
        if (board[i][point.second] == num)
            return false;
    }

    return true;
}

void backtracking(int index)
{
    if (index == blank.size())
    {
        for (int i = 0; i < board.size(); ++i)
        {
            for (int j = 0; j < board[i].size(); ++j)
            {
                cout << board[i][j] << " ";
            }
            cout << endl;
        }

        return;
    }

    for (int i = 0; i < board.size(); ++i)
    {
        pair<int, int> point = blank[index];
        if (isValid(point, i + 1))
        {
            board[point.first][point.second] = i + 1;
            backtracking(index + 1);
            board[point.first][point.second] = 0;
        }
    }
}

int main(void)
{
    for (int i = 0; i < board.size(); ++i)
    {
        for (int j = 0; j < board.size(); ++j)
        {
            if (board[i][j] == 0)
            {
                blank.push_back({i, j});
            }
        }
    }

    backtracking(0);

    cout << 1 / 3 << endl;

    return 0;
}
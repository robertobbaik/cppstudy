#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> maps)
{
    vector<int> answer;

    vector<vector<bool>> visited(maps.size(), vector<bool>(maps[0].size(), false));

    for(auto v : visited)
    {
        for(bool b : v)
        {
            cout << b;
        }

        cout << endl;
    }

    cout << endl;

    for (string s : maps)
    {
        for (char c : s)
        {
            cout << c;
        }
        cout << endl;
    }

    for(int i = 0; i < maps.size(); ++i)
    {
        for(int j = 0; j < maps[i].size(); ++j)
        {

        }
    }

    return answer;
}

bool isAdjacent(const vector<string>& maps, int row, int col)
{
    if(row > 0 && maps[row - 1][col] != 'X')
    {
        return true;    
    }

    if(row < maps.size() && maps[row + 1][col] != 'X')
    {
        return true;
    }

    if(col > 0 && maps[row][col + 1] != 'X')
    {
        return true;
    }

    if(col < maps[0].size() && maps[row][col - 1] != 'X')
    {
        return true;
    }

    return false;
}

int main(void)
{
    vector<string> maps = {"X591X", "X1X5X", "X231X", "1XXX1"};
    vector<int> answer = solution(maps);

    for (int n : answer)
    {
        cout << n << endl;
    }

    

    return 0;
}
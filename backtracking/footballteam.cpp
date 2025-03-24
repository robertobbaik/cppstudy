#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// vector<vector<int>> abillties = {
//     {0, 1, 2, 3, 4, 5},
//     {1, 0, 2, 3, 4, 5},
//     {1, 2, 0, 3, 4, 5},
//     {1, 2, 3, 0, 4, 5},
//     {1, 2, 3, 4, 0, 5},
//     {1, 2, 3, 4, 5, 0}
// };

vector<vector<int>> abillties;
int n;
vector<int> answer;
vector<vector<int>> teamlist;

void backtracking(int n, int start, int depth)
{
    if (depth >= n / 2)
    {
        teamlist.push_back(answer);
        return;
    }

    for (int i = start; i < n; ++i)
    {
        answer.push_back(i);
        backtracking(n, i + 1, depth + 1);
        answer.pop_back();
    }
}

int team_abillity_score(const vector<int> &arr)
{
    int result = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < arr.size(); j++)
        {
            if (i < j)
            {
                result += abillties[arr[i]][arr[j]] + abillties[arr[j]][arr[i]];
            }
        }
    }
    return result;
}

int main(void)
{
    cin >> n;
    abillties.resize(n, vector<int>(n));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> abillties[i][j];
        }
    }

    int answer = INT_MAX;
    backtracking(n, 0, 0);

    vector<int> temp;

    for (auto const &v : teamlist)
    {
        int n = team_abillity_score(v);

        temp.push_back(n);
    }

    for (int i = 0; i < temp.size() / 2; i++)
    {
        answer = min(answer, abs(temp[i] - temp[temp.size() - 1 - i]));
    }

    cout << answer << endl;

    return 0;
}
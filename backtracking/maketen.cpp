#include <iostream>
#include <vector>

using namespace std;

vector<int> selected_num;
vector<vector<int>> answer;

void backtracking(int n, int sum, int idx)
{
    if (sum == 10)
    {
        answer.push_back(selected_num);
        return;
    }

    for (int i = idx; i <= n; i++)
    {
        if (sum + i <= 10)
        {
            selected_num.push_back(i);
            backtracking(n, sum + i, i + 1);
            selected_num.pop_back();
        }
    }
}

int main(void)
{
    backtracking(5, 0, 1);

    for(auto const& v : answer)
    {
        for(int n : v)
        {
            cout << n << " ";
        }

        cout << endl;
    }

    return 0;
}
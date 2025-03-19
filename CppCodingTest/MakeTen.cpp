#include <vector>
#include <iostream>

using namespace std;

vector<vector<int>> results;
vector<int> selected_num;

void backtracking(int n, int start, int sum)
{
    if(sum == 10)
    {
        results.push_back(selected_num);
        return;
    }

    for(int i = start; i <= n; i++)
    {
        selected_num.push_back(i);
        backtracking(n, i + 1, sum + i);
        selected_num.pop_back();
    }
}

int main(void)
{
    int n = 5;

    backtracking(5, 1, 0);

    for(auto vv : results)
    {
        for(auto n : vv)
        {
            cout << n << " ";
        }

        cout << endl;
    }

    return 0;
}

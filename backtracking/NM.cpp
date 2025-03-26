#include <iostream>
#include <vector>

using namespace std;

vector<int> sequence;
vector<bool> used(9, false);

void backtracking(int depth, int n, int m, int index)
{
    if (depth >= m)
    {
        for (int n : sequence)
        {
            cout << n << " ";
        }
        cout << endl;
        return;
    }

    for (int i = 1; i <= n; ++i)
    {
        if (!used[i])
        {
            used[i] = true;
            sequence.push_back(i);
            backtracking(depth + 1, n, m, i);
            sequence.pop_back();
            used[i] = false;
        }
    }
}

int main(void)
{
    int n = 4;
    int m = 4;

    backtracking(0, n, m, 0);

    return 0;
}
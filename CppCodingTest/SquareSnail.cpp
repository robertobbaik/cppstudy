#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(int n)
{
    vector<int> answer;
    vector<vector<int>> triangle(n, vector<int>(n, 0));

    int num = 1;
    int x = -1;
    int y = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            if (i % 3 == 0)
            {
                x++;
            }
            else if (i % 3 == 1)
            {
                y++;
            }
            else
            {
                x--;
                y--;
            }
            
            triangle[x][y] = num++;
        }
    }

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j <= i; ++j)
        {
            answer.push_back(triangle[i][j]);
        }
    }

    return answer;
}

int main(void)
{
    vector<int> answer = solution(5);

    for (int n : answer)
    {
        cout << n << " ";
    }

    return 0;
}

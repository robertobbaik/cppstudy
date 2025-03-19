#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(int k, vector<vector<int>> dungeons)
{
    int answer = -1;

    vector<vector<int>> v;

    vector<int> temp;
    int max_count = 0;

    for (size_t i = 0; i < dungeons.size(); i++)
    {
        temp.push_back(i);
    }

    do
    {
        vector<int> a;

        for (int num : temp)
        {
            a.push_back(num);
        }

        v.push_back(a);
        a.clear();

    } while (next_permutation(temp.begin(), temp.end()));

    for (int i = 0; i < v.size(); i++)
    { 
        int count = 0;
        int energy = k;
        for (int j = 0; j < v[i].size(); ++j)
        {
            if(dungeons[v[i][j]][0] <= energy && energy - dungeons[v[i][j]][1] >= 0)
            {
                energy -= dungeons[v[i][j]][1];
                ++count;
            } 
        }

        if(max_count < count)
        {
            max_count = count;
        }
    }

    answer = max_count;

    return answer;
}

int main(void)
{
    vector<vector<int>> dungeons = {{80, 20}, {50, 40}, {30, 10}};
    int a = solution(80, dungeons);

    cout << a << endl;
    return 0;
}
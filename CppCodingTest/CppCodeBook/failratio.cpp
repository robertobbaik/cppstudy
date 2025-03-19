#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool Compare(pair<int, float> a, pair<int, float> b)
{
    if (a.second == b.second)
    {
        return a.first < b.first;
    }

    return a.second > b.second;
}

vector<int> solution(int N, vector<int> stages)
{
    vector<int> answer;
    vector<pair<int, float>> pv;
    for (int i = 1; i <= N; ++i)
    {
        int total = 0;
        int success = 0;
        int fail = 0;
        pair<int, float> temp = {i, 0};
        float ratio = 0;
        for (int j = 0; j < stages.size(); ++j)
        {
            if (stages[j] > i)
            {
                success++;
            }
            else if (stages[j] == i)
            {
                fail++;
            }
            else
            {
                continue;
            }
        }

        if (fail == 0)
        {
            temp.second = 0;
        }
        else
        {
            ratio = (float)(fail) / (float)(fail + success);
            temp.second = ratio;
        }

        pv.push_back(temp);
    }

    sort(pv.begin(), pv.end(), Compare);

    for (auto pair : pv)
    {
        answer.push_back(pair.first);
    }

    return answer;
}

int main()
{
    vector<int> stages = {2, 1, 2, 6, 2, 4, 3, 3};
    int N = 5;

    vector<int> answer = solution(N, stages);

    for (int num : answer)
    {
        cout << num << " ";
    }

    return 0;
}
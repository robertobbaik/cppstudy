#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(vector<int> priorities, int location)
{
    int answer = 0;

    queue<pair<int, int>> q;
    priority_queue<int> pq;

    for (int i = 0; i < priorities.size(); ++i)
    {
        q.push({i, priorities[i]});
        pq.push(priorities[i]);
    }

    while (q.size())
    {
        pair<int, int> p = q.front();
        q.pop();

        if (p.second < pq.top())
        {
            q.push(p);
        }
        else
        {
            pq.pop();
            answer++;

            if (p.first == location)
            {
                return answer;
            }
        }
    }

    return answer;
}

int main(void)
{
    vector<int> priorities = {2, 1, 3, 2};

    int answer = solution(priorities, 2);

    cout << answer << endl; // 1

    return 0;
}
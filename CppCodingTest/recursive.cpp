#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int solution(vector<int> numbers, int target)
{
    int answer = 0;

    queue<pair<int, int>> q;

    q.push({0, 0});

    while (!q.empty())
    {
        int sum = q.front().first;
        int index = q.front().second;

        q.pop();

        if (index == numbers.size())
        {
            if (sum == target)
            {
                answer++;
            }
        }
        else
        {
            q.push({sum + numbers[index], index + 1});
            q.push({sum - numbers[index], index + 1});
        }
    }

    return answer;
}

int main()
{
    vector<int> numbers = {4,1,2,1};
    int target = 4;

    int answer = solution(numbers, target);
    cout << answer << endl;
    return 0;
}
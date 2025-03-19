#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// void dfs(const vector<int> &numbers, int target, int index, int sum, int &count, const string &str)
// {
//     // cout << str << endl;
//     cout << str << ": " << sum << endl;
//     if (index == numbers.size())
//     { // 모든 숫자를 사용한 경우
//         if (sum == target)
//             count++; // 타겟 넘버를 만든 경우
//         return;
//     }

//     // 현재 숫자를 더하거나 빼는 두 가지 경우 탐색
//     dfs(numbers, target, index + 1, sum + numbers[index], count, "add");
//     dfs(numbers, target, index + 1, sum - numbers[index], count, "subtractive");
// }

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

        if(index == numbers.size())
        {
            if(sum == target)
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
    vector<int> numbers = {1, 1, 1, 1, 1};
    int target = 3;
    int answer = solution(numbers, target);

    cout << answer << endl;

    return 0;
}
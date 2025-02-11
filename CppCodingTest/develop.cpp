#include <string>
#include <vector>
#include <iostream>
#include <numeric>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds)
{
    vector<int> answer;
    queue<int> days; // 각 작업이 완료되기까지 걸리는 일수를 저장하는 큐

    // 각 기능이 완료되는 데 필요한 일 수 계산
    for (size_t i = 0; i < progresses.size(); i++)
    {
        int remain = 100 - progresses[i];
        int day = (remain + speeds[i] - 1) / speeds[i]; // 올림 처리

        cout << day << endl;
        days.push(day);
    }

    // 배포 작업 진행
    while (!days.empty())
    {
        int deploy_day = days.front(); // 가장 먼저 개발이 끝나는 기능의 배포 기준일
        days.pop();
        int count = 1;

        // 같은 날 배포 가능한 기능 찾기
        while (!days.empty() && days.front() <= deploy_day)
        {
            count++;
            days.pop();
        }

        answer.push_back(count);
    }

    return answer;
}

int main(void)
{
    vector<int> a = {93, 30, 55};
    vector<int> b = {1, 30, 5};

    vector<int> c = solution(a, b);

    // for (int num : c)
    // {
    //     cout << num << endl;
    // }

    return 0;
}
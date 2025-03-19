#include <string>
#include <vector>
#include <iostream>
#include <numeric>
#include <queue>

using namespace std;

int solution(vector<int> queue1, vector<int> queue2)
{
    int answer = -1;
    long long q1total = accumulate(queue1.begin(), queue1.end(), 0LL);
    long long q2total = accumulate(queue2.begin(), queue2.end(), 0LL);
    long long total = q1total + q2total;
    long long target = total / 2;
    
    if (total % 2 != 0) return -1;
    queue<int> q1;
    queue<int> q2;

    for(auto n : queue1)
    {
        q1.push(n);
    }
    for(auto n : queue2)
    {
        q2.push(n);
    }

    int count = 0;

    while(count <= queue1.size() + queue2.size() && q1total != q2total)
    {
        if(q1total > q2total)
        {
            int num = q1.front();
            q1.pop();
            q2.push(num);
            q1total -= num;
            q2total += num;
        }   
        else
        {
            int num = q2.front();
            q2.pop();
            q1.push(num);
            q2total -= num;
            q1total += num;
        }   
        count++;
    }
    answer = q1total == q2total ? count : -1;

    return answer;
}

int main(void)
{
    vector<int> queue1 = {1, 2, 1, 2};
    vector<int> queue2 = {1, 10, 1, 2};

    int result = solution(queue1, queue2);

    cout << "result : " << result;

    return 0;
}
#include <string>
#include <vector>
#include <iostream>
#include <stack>

using namespace std;

// 정렬하면 안됨
// 데이터 수 O(N^2) 사용 불가
// 뒤에서부터 돌아야될 듯?

vector<int> solution(vector<int> numbers) {
    vector<int> answer(numbers.size(), -1);
    stack<int> s;

    for(int i = answer.size() - 1; i >= 0; --i)
    {
        while (!s.empty() && s.top() <= numbers[i])
        {
            s.pop();
        }

        if(!s.empty())
        {
            answer[i] = s.top();
        }

        s.push(numbers[i]);
    }


    return answer;
}

int main(void)
{
    vector<int> numbers = {2,3,3,5};

    vector<int> answer = solution(numbers);

    for(int num : answer)
    {
        cout << num << endl;
    }

    return 0;
}
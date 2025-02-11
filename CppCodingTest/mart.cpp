#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
#include <numeric>

using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount)
{
    int answer = 0;

    for (int i = 0; i < discount.size() - 9; ++i)
    {
        unordered_map<string, int> discount_map;
        for (int j = 0; j < 10; ++j)
        {
            discount_map[discount[i + j]]++;
        }

        bool isComplete = true;
        for (int j = 0; j < want.size(); ++j)
        {
            if (discount_map[want[j]] < number[j])
            {
                isComplete = false;
                break;
            }
        }

        if (isComplete)
        {
            answer++;
        }
        discount_map.clear();
    }

    return answer;
}

int main(void)
{
    vector<string> want = {"banana", "apple", "rice", "pork", "pot"};
    vector<int> number = {3, 2, 2, 2, 1};
    vector<string> discount = {"chicken", "apple", "apple", "banana", "rice", "apple", "pork", "banana", "pork", "rice", "pot", "banana", "apple", "banana"};

    int answer = solution(want, number, discount);

    cout << answer << endl;

    return 0;
}
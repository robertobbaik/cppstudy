#include <iostream>
#include <vector>

using namespace std;

vector<long long> solution(vector<long long> numbers)
{
    vector<long long> answer;

    for (long long x : numbers)
    {
        if (x % 2 == 0)
        {
            answer.push_back(x + 1);
        }
        else
        {
            long long bit = 1;
            while (x & bit)
            {
                bit <<= 1;
            }
            
            answer.push_back(x + bit - (bit >> 1));
        }
    }

    return answer;
}

int main(void)
{
    vector<long long> numbers = {11, 7};

    vector<long long> result = solution(numbers);

    cout << (11 & 4) << endl;

    return 0;
}
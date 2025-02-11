#include <string>
#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

vector<int> solution(int n, long long left, long long right)
{
    vector<int> answer;
    for (size_t i = left; i <= right; ++i)
    {
        int temp1 = i / n;
        int temp2 = i % n;

        cout << max(temp1, temp2) + 1 << endl;
    }

    return answer;
}

int main()
{
    vector<int> result = solution(3, 2, 5);

    for(int num : result)
    {
        cout << num << endl;
    }

    long long a = pow(10, 7);

    cout << a << endl;

    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr)
{
    sort(arr.begin(), arr.end());

    return arr;
}

int main(void)
{
    vector<int> question = {1, -5, 2, 4, 3};

    vector<int> answer = solution(question);

    for(int num : answer)
    {
        cout << num << endl;
    }

    return 0;
}
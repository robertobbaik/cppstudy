#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> citations)
{
    int answer = 0;

    sort(citations.rbegin(), citations.rend());

    for(int i = 0; i < citations.size(); ++i)
    {
        if(citations[i] >= i + 1)
        {
            answer = i + 1;
        }
        else
        {
            break;
        }
    }

    return answer;
}

int main()
{
    vector<int> citations = {3,0,6,1,5};
    int result = solution(citations);

    cout << result << endl;

    return 0;
}
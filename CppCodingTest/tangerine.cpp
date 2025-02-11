#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;

int solution(int k, vector<int> tangerine)
{
    int answer = 0;

    unordered_map<int, int> tangerine_map;

    for (int num : tangerine)
    {
        tangerine_map[num]++;
    }

    vector<int> counts;

    for(auto& num : tangerine_map)
    {
        counts.push_back(num.second);
    }

    sort(counts.rbegin(), counts.rend());

    int tangerine_count = 0;
    int size_count = 0;
    
    for(int count : counts)
    {
        tangerine_count++;
        size_count += count;

        if(size_count >= k)
        {
            answer = tangerine_count;
            break;
        }   
    }

    return answer;
}

int main()
{
    int k = 6;
    vector<int> tangerine = {1, 3, 2, 5, 4, 5, 2, 3};

    int c = solution(k, tangerine);
}
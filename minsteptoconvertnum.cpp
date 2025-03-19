#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

int solution(int x, int y, int n) {
    int answer = -1;
    if (x == y) return 0;
    queue<pair<int, int>> q; 
    unordered_set<int> visited; 
   
    q.push({0,x});
    visited.insert(x);
    
    
    while(!q.empty())
    {
        int count = q.front().first;
        int value = q.front().second;
        
        q.pop();

        vector<int> next_value = {value * 2, value * 3, value + n};    

        for(int num : next_value)
        {
            if(num == y) return count + 1;
        
            if(num < y && visited.find(num) == visited.end())
            {
                q.push({count + 1, num});
                visited.insert(num);
            }
        }
    }

    return -1;
}

int main(void)
{
    int result = solution(10, 40, 5);

    cout << result << endl;

    return 0;
}
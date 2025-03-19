#include <string>
#include <vector>
#include <iostream>
#include <deque>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights)
{
    int answer = 0;

    int enter_index = 0;
    deque<pair<int, int>> dq;

    dq.push_back({truck_weights[0], 1});
    enter_index++;

    while(!dq.empty())
    {
        int total_weight = 0;
        for (auto& p : dq)
        {
            total_weight += p.first;
            
            p.second++;

            if(p.second > bridge_length)
            {
                dq.erase(dq.begin());
                total_weight -= p.first;
            }
        }

        if(total_weight + truck_weights[enter_index] <= weight && enter_index < truck_weights.size())
        {
            dq.push_back({truck_weights[enter_index], 1});
            enter_index++;
        }

        answer++;
    }
    
    return answer + 1;
}

int main(void)
{
    int bridge_length = 100;

    int weight = 100;

    vector<int> truck_weights = {10,10,10,10,10,10,10,10,10,10};

    int answer = solution(bridge_length, weight, truck_weights);

    cout << answer << endl;
    return 0;
}
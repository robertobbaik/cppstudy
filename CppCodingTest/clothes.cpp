#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

int solution(vector<vector<string>> clothes)
{
    int answer = 1;
    unordered_map<string, int> clothes_map;
    for(vector<string> v : clothes)
    {
        clothes_map[v[1]]++;
    }

    for(auto m : clothes_map)
    {
       answer += m.second + 1;
    }

    return answer - 1;
}

int main(void)
{
    vector<vector<string>> clothes = {{"yellow_hat", "headgear"}, {"blue_sunglasses", "eyewear"}, {"green_turban", "headgear"}};

    int answer = solution(clothes);

    cout << answer << endl;

    return 0;
}
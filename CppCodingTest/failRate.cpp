#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <map>
#include <set>
using namespace std;

// E 2 
// 01234

void setMove(string& route)
{
    char dir = route[0];

    int dis = stoi(route.substr(2, route.size() - 2));

    cout << dir << " : " << dis << endl; 
}

int main()
{
    vector<string> park = {"SOO","OOO","OOO"};
    vector<string> routes = {"E 200","S 2","W 1"};

    for(int i = 0; i < park.size(); ++i)
    {
        for(int j = 0; j < park[i].size(); ++j)
        {
            if(park[i][j] == 'S')
            {
                cout << "start pos : " << i << " " << j << endl;
                break;
            }
        }
    }

    return 0;
}
#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2)
{
    vector<vector<int>> answer;

    for (int i = 0; i < arr1.size(); ++i)
    {
        vector<int> temp;
        for (int j = 0; j < arr1[0].size(); ++j)
        {
            int add_num = 0;
            for (int k = 0; k < arr2.size(); ++k)
            {
                add_num += arr1[i][k] * arr2[k][j];
            }
            temp.push_back(add_num);
        }
        answer.push_back(temp);
        temp.clear();
    }

    return answer;
}

int main()
{
    vector<vector<int>> arr1 = {{2, 3, 2}, {4, 2, 4}, {3, 1, 4}};
    vector<vector<int>> arr2 = {{5, 4, 3}, {2, 4, 1}, {3, 1, 1}};

    vector<vector<int>> answer = solution(arr1, arr2);

    for (auto arr : answer)
    {
        for (auto num : arr)
        {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}
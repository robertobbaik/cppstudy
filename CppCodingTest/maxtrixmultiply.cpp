#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2)
{
    vector<vector<int>> answer;

    for (int i = 0; i < arr1.size(); ++i)
    {
        vector<int> temp;
        for (int j = 0; j < arr2[0].size(); ++j)
        {
            int num = 0;
            for (int k = 0; k < arr2.size(); ++k)
            {
                num += arr1[i][k] * arr2[k][j];
            }
            temp.push_back(num);
        }
        answer.push_back(temp);
    }

    return answer;
}

int main()
{
    vector<vector<int>> arr1 = {{1, 4},
                                {3, 2},
                                {4, 1}};

    vector<vector<int>> arr2 = {{3, 3},
                                {3, 3}};

    vector<vector<int>> a = solution(arr1, arr2);

    for (int i = 0; i < a.size(); ++i)
    {
        for (int j = 0; j < a[0].size(); ++j)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
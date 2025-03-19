#include <vector>
using namespace std;

// 0과 1의 개수를 저장할 전역 변수
int zeroCount = 0, oneCount = 0;

// 주어진 영역이 모두 같은 값인지 확인하는 함수
bool isUniform(const vector<vector<int>> &arr, int x, int y, int size)
{
    int first = arr[x][y];
    for (int i = x; i < x + size; ++i)
    {
        for (int j = y; j < y + size; ++j)
        {
            if (arr[i][j] != first)
            {
                return false;
            }
        }
    }
    return true;
}

// 재귀적으로 영역을 나누어 처리하는 함수
void compress(const vector<vector<int>> &arr, int x, int y, int size)
{
    if (isUniform(arr, x, y, size))
    {
        if (arr[x][y] == 0)
        {
            zeroCount++;
        }
        else
        {
            oneCount++;
        }
        return;
    }

    int newSize = size / 2;
    compress(arr, x, y, newSize);
    compress(arr, x, y + newSize, newSize);
    compress(arr, x + newSize, y, newSize);
    compress(arr, x + newSize, y + newSize, newSize);
}

vector<int> solution(vector<vector<int>> arr)
{
    zeroCount = 0;
    oneCount = 0;
    int size = arr.size();
    compress(arr, 0, 0, size);
    return {zeroCount, oneCount};
}

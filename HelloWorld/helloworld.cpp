#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(vector<string> keymap, vector<string> targets)
{
    unordered_map<char, int> minKeyPress; // 각 문자의 최소 입력 횟수 저장
    cout << minKeyPress.size() << endl;
    // keymap의 각 키에 대해 최소 입력 횟수 계산
    for (const string &key : keymap)
    {
        for (int i = 0; i < key.size(); i++)
        {
            char c = key[i];
            if (minKeyPress.find(c) == minKeyPress.end())
            {
                minKeyPress[c] = i + 1; // 1-based index
            }
            else
            {
                minKeyPress[c] = min(minKeyPress[c], i + 1);
            }
        }
    }

    vector<int> result;

    // 각 target 문자열에 대해 최소 입력 횟수 계산
    for (const string &target : targets)
    {
        int totalKeyPress = 0;
        bool canType = true;

        for (char c : target)
        {
            if (minKeyPress.find(c) == minKeyPress.end())
            {
                // 문자를 작성할 수 없는 경우
                canType = false;
                break;
            }
            totalKeyPress += minKeyPress[c];
        }

        if (canType)
        {
            result.push_back(totalKeyPress);
        }
        else
        {
            result.push_back(-1); // 작성할 수 없는 경우
        }
    }

    return result;
}

int main()
{
    string answer = "";
    string s = "zzzz";
    string skip = "wbqd";
    int index = 5;

    for (char c : s)
    {
        int tempIndex = index;
        int cint = c;
        int resultChar = c;


        for (char skipc : skip)
        {
            int scint = skipc;

            if (scint > cint && scint < cint + index)
            {
                ++tempIndex;
                resultChar = cint + tempIndex;
            }
            else
            {
                resultChar = cint + tempIndex;
            }
        }
        if (resultChar > 'z')
        {
            resultChar = (resultChar % 'z') + 'a' - 1;
        }

        answer += resultChar;
    }

    cout << answer << endl;

    return 0;
}

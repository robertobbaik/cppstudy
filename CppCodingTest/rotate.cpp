#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
#include <unordered_map>

using namespace std;

int solution(string s)
{
    int answer = 0;

    unordered_map<char, int> parentheses;

    parentheses['['] = 0;
    parentheses[']'] = 0;
    parentheses['{'] = 1;
    parentheses['}'] = 1;
    parentheses['('] = 2;
    parentheses[')'] = 2;

    for (int i = 0; i < s.size(); ++i)
    {
        bool is_complete = true;
        stack<char> cst;
        for (char c : s)
        {
            if (c == '[' || c == '{' || c == '(')
            {
                cst.push(c);
            }
            else
            {
                if (cst.empty())
                {
                    is_complete = false;
                    break;
                }

                int open_idx = parentheses[cst.top()];
                int close_idx = parentheses[c];

                if (open_idx == close_idx)
                {
                    cst.pop();
                }
                else
                {
                    is_complete = false;
                    break;
                }
            }
        }

        if (cst.empty())
        {
            if (is_complete)
            {
                answer++;
            }
        }
        else
        {
            while (!cst.empty())
            {
                cst.pop();
            }
        }

        rotate(s.begin(), s.begin() + 1, s.end());
    }

    return answer;
}

int main()
{
    string s = "}]()[{";

    int res = solution(s);

    cout << res << endl;

    return 0;
}
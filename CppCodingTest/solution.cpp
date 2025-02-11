#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <map>

using namespace std;

int main()
{
    map<char, int> termsMap;
    string today = "2022.05.19";

    vector<string> terms = {"A 6", "B 12", "C 3"};
    vector<string> privacies = {"2021.05.02 A", "2021.07.01 B", "2022.02.19 C", "2022.02.20 C"};
    vector<int> answer;

    for (string str : terms)
    {
        termsMap[str[0]] = stoi(str.substr(2, str.size() - 2));
    }

    for (int i = 0; i < privacies.size(); ++i)
    {
        string str = privacies[i];
        string temp = "";
        int termsMonth = termsMap[str[11]];

        cout << termsMonth << endl;
        int divide = termsMonth / 12;
        int remainder = termsMonth % 12;

        int year = stoi(str.substr(0, 4));
        int month = stoi(str.substr(5, 2));
        int day = stoi(str.substr(8, 2));

        month += remainder;

        day -= 1;

        if(day - 1 == 0)
        {
            day = 28;
            --month;
        }

        if (month > 12)
        {
            month -= 12;
            ++divide;
        }

        year += divide;

        string y = to_string(year);
        string m = month < 10 ? "0" + to_string(month) : to_string(month);
        string d = day < 10 ? "0" + to_string(day) : to_string(day);

        temp = y + m + d;

        long long current = stol(temp);

        long long expire = stol(today.substr(0, 4) + today.substr(5, 2) + today.substr(8, 2));

        if(current < expire)
        {
            cout << i + 1 << endl;
            answer.push_back(i+1);
        }
    }

    return 0;
}
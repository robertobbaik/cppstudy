#include <iostream>
#include <vector>

using namespace std;

vector<string> splitString(const string &str, char delimiter)
{
    vector<string> tokens;
    size_t start = 0, end;

    while ((end = str.find(delimiter, start)) != string::npos)
    {
        string s = str.substr(start, end - start);
        tokens.push_back(s);
        start = end + 1;
    }

    tokens.push_back(str.substr(start));
    return tokens;
}

int main()
{
    string text = "apple,,banana,grape,orange";
    char delimiter = ',';

    vector<string> result = splitString(text, delimiter);

    for (const auto &word : result)
    {
        if (word.empty())
            continue;
        cout << word << endl;
    }

    return 0;
}
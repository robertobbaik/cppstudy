#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

int solution(string word) {
    int answer = 0;

    unordered_map<char, int> umap = {{'A', 0}, {'E', 1}, {'I', 2}, {'O', 3}, {'U', 4}};
    vector<int> v = {781, 156, 31, 6, 1};

    for (int i = 0; i < word.size(); i++)
    {
        answer += umap[word[i]] * v[i] + 1;
    }
    
    return answer;
}

int main(void)
{
    string word = "EIO";
    int answer = solution(word);

    cout << answer << endl;

    return 0;
}
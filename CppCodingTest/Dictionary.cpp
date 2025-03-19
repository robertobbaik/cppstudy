#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

int solution(string word) {
    int answer = 0;

    unordered_map<char, int> umap = {{'A', 0}, {'E', 1}, {'I', 2}, {'O', 3}, {'U', 4}}; // 각 모음 순서 매핑
    vector<int> v = {781, 156, 31, 6, 1}; // 가중치 설정 5^4 ~ 5 ^ 0

    for (int i = 0; i < word.size(); i++)
    {
        answer += umap[word[i]] * v[i] + 1;
    }
    
    return answer;
}

int main(void)
{
    int result = solution("UUUUU");

    cout << result;

    return 0;
}
#include <string>
#include <vector>
#include <cmath>
#include <set>
#include <iostream>
#include <algorithm>

using namespace std;

bool isPrime(int num)
{
    if (num < 2)
        return false;
    if (num == 2)
        return true;
    if (num % 2 == 0)
        return false;

    for (int i = 3; i <= sqrt(num); i += 2)
    {
        if (num % i == 0)
        {
            return false;
        }
    }
    return true;
}

int solution(string numbers)
{
    set<int> numSet;

    vector<char> digits(numbers.begin(), numbers.end());

    for (int len = 1; len <= numbers.length(); len++)
    {
        vector<char> temp = digits;
        sort(temp.begin(), temp.end());

        do
        {
            string numStr = "";
            for (int i = 0; i < len; i++)
            {
                numStr += temp[i];
            }

            int num = stoi(numStr);
            numSet.insert(num);
        } while (next_permutation(temp.begin(), temp.end()));
    }

    int primeCount = 0;
    for (int num : numSet)
    {
        if (isPrime(num))
        {
            primeCount++;
        }
    }

    return primeCount;
}

int main(void)
{
    int a = solution("171");

    return 0;
}
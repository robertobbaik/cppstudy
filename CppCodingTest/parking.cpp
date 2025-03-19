#include <string>
#include <vector>
#include <map>
#include <cmath>

using namespace std;

vector<string> split_string(string str, char c)
{
    int start = 0;
    int end = 0;
    vector<string> v;

    while ((end = str.find(c, start)) != string::npos)
    {
        v.push_back(str.substr(start, end - start));
        start = end + 1;
    }

    v.push_back(str.substr(start));

    return v;
}

int getPrice(int parkingtime, vector<int> fees)
{
    if (parkingtime <= fees[0])
    {
        return fees[1];
    }
    else
    {
        int price = fees[1] + (int)ceil((double)(parkingtime - fees[0]) / fees[2]) * fees[3];

        return price;
    }
}

int get_parkingtime(string intime, string outtime)
{
    vector<string> v_intime = split_string(intime, ':');
    vector<string> v_outtime = split_string(outtime, ':');

    int hour = stoi(v_outtime[0]) - stoi(v_intime[0]);
    int minute = stoi(v_outtime[1]) - stoi(v_intime[1]);

    int totaltime = (hour * 60) + minute;

    return totaltime;
}

vector<int> solution(vector<int> fees, vector<string> records)
{
    vector<int> answer;
    map<string, string> temp;
    map<string, int> parkingtime;

    for (string record : records)
    {
        vector<string> split = split_string(record, ' ');
        
        if(split[2] == "IN")
        {
            temp[split[1]] = split[0];
        }
        else
        {
            int time = get_parkingtime(temp[split[1]], split[0]);
            parkingtime[split[1]] += time;

            temp.erase(split[1]);
        }
    }

    if(temp.size() != 0)
    {
        for(auto pair : temp)
        {
            int time = get_parkingtime(pair.second, "23:59");
            parkingtime[pair.first] += time;
        }
    }

    for(auto pair : parkingtime)
    {
        int price = getPrice(pair.second, fees);

        answer.push_back(price);
    }
    

    return answer;
}

int main(void)
{
    vector<string> record = {"05:34 5961 IN", "06:00 0000 IN", "06:34 0000 OUT", "07:59 5961 OUT", "07:59 0148 IN", "18:59 0000 IN", "19:09 0148 OUT", "22:59 5961 IN", "23:00 5961 OUT"};
    vector<int> fees = {180, 5000, 10, 600};

    vector<int> result = solution(fees, record);

    return 0;
}
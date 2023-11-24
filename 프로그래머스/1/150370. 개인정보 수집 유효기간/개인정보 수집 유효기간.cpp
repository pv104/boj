#include <string>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <sstream>
#include <iostream>
using namespace std;
#define DAY 1
#define MONTH 28
#define YEAR MONTH*12
map <string, int> term;
vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    istringstream iss(today);
    string buffer;
    vector<string> res;
    // "2022 / 05 / 19"
    while (getline(iss, buffer, '.')) {
        res.push_back(buffer);
    }
    // (,]
    int year = stoi(res[0]) * YEAR;
    int month = stoi(res[1]) * MONTH;
    int day = stoi(res[2]);
    int todayValue = year + month + day;

    buffer = "";
    for (auto i : terms) {
        stringstream ss(i);
        res.clear();
        string name = "";
        int val = 0;
        while (ss >> buffer)
        {
            if (buffer[0] >= 'A' && buffer[0] <= 'Z')
            {
                name = buffer;
            }
            else
                val = stoi(buffer);
        }
        term.insert({ name,val });
    }
    buffer = "";
    int cnt = 1;
    for (auto i : privacies) {
        i[i.length() - 2] = '.';
        iss.clear();
        iss.str(i);
        res.clear();
        while (getline(iss, buffer, '.')) {
            res.push_back(buffer);
            //cout << buffer << "\n";
        }
        year = (stoi(res[0]) * YEAR);
        month = (stoi(res[1]) * MONTH);
        day = (stoi(res[2]));
        int termValue = (term.find(res[3])->second * MONTH);
        int val = year + month + day + termValue - 1;
        //cout << term.find(res[3])->first << ' ' << term.find(res[3])->second << "\n";
        //cout << todayValue << ' ' << val << "\n";
        if (todayValue > val) {
            answer.push_back(cnt);
        }
        cnt++;
    }
    return answer;
}
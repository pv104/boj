#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <algorithm>
#include <iostream>
using namespace std;
map <int, int> m, resM;
bool isExit[10003];
#define MAX 10003
#define MAXTIME 60*23+59
vector<int> solution(vector<int> fees, vector<string> records) {
    int defTime = fees[0];
    int defAmount = fees[1];
    int addTime = fees[2];
    int addAmount = fees[3];
    vector<int> answer;
    for (auto i : records) {
        istringstream iss(i);
        string buffer;
        vector <string> res;
        while (getline(iss, buffer, ' ')) {
            res.push_back(buffer);
        }
        // xx:yy, carnumbers, time
        istringstream isss(res[0]);
        vector <string> times;
        while (getline(isss, buffer, ':')) {
            times.push_back(buffer);
        }
        //times : xx, yy
        string carNumbers = res[1];
        string inOrOut = res[2];

        int carNum = stoi(carNumbers);
        if (inOrOut == "IN") {
            int time = stoi((times[0])) * 60;
            time += stoi(times[1]);
            m.insert({ carNum,time });
        }//  출차
        else {
            int totalTime = stoi((times[0])) * 60;
            totalTime += stoi(times[1]);
            int time = totalTime - m.find(stoi(carNumbers))->second;
            //기본
            int totalAmount = defAmount;
            if (resM.find(carNum) != resM.end())
                resM.find(carNum)->second += time;
            else
                resM.insert({ carNum,time });
                m.erase(carNum);
        }
    }
    for (auto i : m) {
        if (resM.find(i.first) != resM.end())
            resM.find(i.first)->second += (MAXTIME - i.second);
        else
            resM.insert({ i.first,MAXTIME - i.second });
    }
    for (auto i : resM) {
        if (i.second <= defTime) {
            answer.push_back(defAmount);
            continue;
        }
        int totalAmount = defAmount;
        totalAmount += ((i.second - defTime) / addTime * addAmount);
        if ((i.second - defTime) % addTime != 0)
            totalAmount += addAmount;
        answer.push_back(totalAmount);
    }
    return answer;
}
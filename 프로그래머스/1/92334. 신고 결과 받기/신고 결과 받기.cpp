#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <sstream>
using namespace std;
#define MAX 1003
int isReported[MAX][MAX];
int sendResult[MAX];
vector<int> solution(vector<string> id_list, vector<string> report, int k) {
	map <string, int> idList;
	int size = id_list.size();
	for (int i = 0; i < id_list.size(); i++) {
		idList.insert({ id_list[i],i });
	}
	for (int i = 0; i < report.size(); i++) {
		istringstream iss(report[i]);
		string buffer;
		vector<string> id;
		while (getline(iss, buffer, ' ')) {
			id.push_back(buffer);
		}
		string dest = id[0];
		string target = id[1];
		int row = idList.find(dest)->second;
		int col = idList.find(target)->second;
		if (isReported[row][col] == 0)
		{
			isReported[row][col] = 1;
		}
	}
	vector<int> answer;
	for (int i = 0; i < size; i++) {
		int t = 0;
		for (int j = 0; j < size; j++) {
			t += isReported[j][i];
		}
		if (k <= t)
		{
			for (int j = 0; j < size; j++) {
				if (isReported[j][i] > 0)
					sendResult[j]++;
			}
		}
	}
	for (int i = 0; i < size; i++) {
		answer.push_back(sendResult[i]);
	}
	return answer;

}
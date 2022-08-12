#include <iostream>
#include <string>
using namespace std;
string x[4] = { "\"재귀함수가 뭔가요?\"",
"\"잘 들어보게. 옛날옛날 한 산 꼭대기에 이세상 모든 지식을 통달한 선인이 있었어.",
"마을 사람들은 모두 그 선인에게 수많은 질문을 했고, 모두 지혜롭게 대답해 주었지.",
"그의 답은 대부분 옳았다고 하네. 그런데 어느 날, 그 선인에게 한 선비가 찾아와서 물었어.\"" };
string def = "어느 한 컴퓨터공학과 학생이 유명한 교수님을 찾아가 물었다.";
string ret = "\"재귀함수는 자기 자신을 호출하는 함수라네\"";
string fin = "라고 답변하였지.";
int n;
void rec(int t)
{
	string s = "";
	for (int i = 0; i < t * 4; i++)
		s += "_";
	if (t == n)
	{
		cout << s + x[0] << "\n";
		cout << s + ret << "\n";
		cout << s + fin << "\n";
		return;
	}
	for (int i = 0; i < 4; i++)
		cout << s + x[i] << "\n";
	rec(t + 1);
	cout << s + fin << "\n";
}
int main()
{
	cin.tie(0); ios::sync_with_stdio(0);
	cin >> n;
	cout << def << "\n";
	rec(0);
}
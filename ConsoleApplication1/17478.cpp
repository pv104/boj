#include <iostream>
#include <string>
using namespace std;
string x[4] = { "\"����Լ��� ������?\"",
"\"�� ����. �������� �� �� ����⿡ �̼��� ��� ������ ����� ������ �־���.",
"���� ������� ��� �� ���ο��� ������ ������ �߰�, ��� �����Ӱ� ����� �־���.",
"���� ���� ��κ� �ǾҴٰ� �ϳ�. �׷��� ��� ��, �� ���ο��� �� ���� ã�ƿͼ� ������.\"" };
string def = "��� �� ��ǻ�Ͱ��а� �л��� ������ �������� ã�ư� ������.";
string ret = "\"����Լ��� �ڱ� �ڽ��� ȣ���ϴ� �Լ����\"";
string fin = "��� �亯�Ͽ���.";
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
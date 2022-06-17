#include <iostream>
using namespace std;
#define MAX 1000005
int dat[2 * MAX + 1];
int tail = MAX, head = MAX;
int back();
int empty()
{
	if (head == tail) return 1;
	else return 0;
}
void push_front(int x)
{
	dat[--head] = x;
}
void push_back(int x)
{
	dat[tail++] = x;
}
int pop_front()
{
	if (empty()) return -1;
	int t = dat[head++];
	return t;
}
int pop_back()
{
	if (empty()) return -1;
	int t = dat[--tail];
	return t;
}
int front()
{
	if (!empty())
		if (dat[head] == 0)
			return back();
		else 
		return dat[head];
	else return -1;
}
int back()
{
	if (!empty())
		if (dat[tail-1] == 0)
			return front();
	else return dat[tail - 1];
		else return -1;
}
int size()
{
	return tail - head;
}
int main(){
int t, c;
string s;
cin >> t;
for (int i = 0; i < t; i++)
{
	cin >> s;
	if (s == "push_front")
	{
		cin >> c;
		 push_front(c);
	}

	else if (s == "push_back")
	{
		cin >> c;
		 push_back(c);
	}
	else if (s == "pop_front")
		cout <<  pop_front() << "\n";
	else if (s == "pop_back")
		cout <<  pop_back() << "\n";
	else if (s == "size")
		cout <<  size() << "\n";
	else if (s == "empty")
		cout <<  empty() << "\n";
	else if (s == "front")
		cout <<  front() << "\n";
	else if (s == "back")
		cout <<  back() << "\n";

}
}
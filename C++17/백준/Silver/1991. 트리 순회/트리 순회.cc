#include <iostream>
#include <map>
using namespace std;
int N;
typedef struct node {
	char lchild, rchild;
}Node;
map <char, node> tree;
void input() {
	cin >> N;
	char d, lc, rc;
	for (int i = 0; i < N; i++) {
		cin >> d >> lc >> rc;
		tree.insert({ d,{lc,rc} });
	}

}
void preOrder(char cur) {
	if (cur == '.' || cur == '\0') return;
	cout << cur;
	preOrder(tree.at(cur).lchild);
	preOrder(tree.at(cur).rchild);
	
}
void inOrder(char cur) {
	if (cur == '.' || cur == '\0') return;
	inOrder(tree.at(cur).lchild);
	cout << cur;
	inOrder(tree.at(cur).rchild);
}
void postOrder(char cur) {
	if (cur == '.' || cur == '\0') return;
	postOrder(tree.at(cur).lchild);
	postOrder(tree.at(cur).rchild);
	cout << cur;
}
int main() {
	cin.tie(0); ios::sync_with_stdio(0);
	input();

	preOrder('A');
	cout << "\n";

	inOrder('A');
	cout << "\n";
	postOrder('A');
}
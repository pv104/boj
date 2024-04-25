#include <iostream>
#include <map>
#include <vector>
#include <memory.h>
using namespace std;
#define INF -1

typedef struct node {
	int data;
	node* left, * right;
}node;
node* root;
node newNode[10002];
int cnt = 0;
void insertTree(node* cur, int x) {
	if (x < cur->data)
	{
		auto& left = cur->left;
		if (left == nullptr) {
			newNode[cnt] = { x,nullptr,nullptr };
			left = &newNode[cnt++];
			
			return;
		}
		else {
			insertTree(left, x);
		}
	}
	else {
		auto& right = cur->right;
		if (right == nullptr) {
			newNode[cnt] = { x,nullptr,nullptr };
			right = &newNode[cnt++];
			return;
		}
		else {
			insertTree(right, x);
		}
	}
	return;
}
void input() {
	int x;
	cin >> x;
	newNode[cnt] = { x,nullptr,nullptr };
	root = &newNode[cnt++];
	
	while (cin >> x)
		insertTree(root, x);
}
void postOrder(node* cur) {
	if (cur->left != nullptr)
		postOrder(cur->left);
	if (cur->right != nullptr)
		postOrder(cur->right);
	cout << cur->data << "\n";
	return;
}
void solve() {
	postOrder(root);
	return;
}
int main() {
	cin.tie(0); cin.sync_with_stdio(0);
	input(); solve();
}
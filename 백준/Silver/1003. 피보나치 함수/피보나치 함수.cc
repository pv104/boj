#include <iostream>
using namespace std;
int main() {

	int in, t, n_1 = 1, n_2 = 0, te = 0;
	cin >> t;
	for (int a = 0; a < t; a++) {
		cin >> in;
		for (int i = 1; i < in; i++) {
			te = n_1 + n_2;
			n_2 = n_1;
			n_1 = te;
		}	
		if (in == 0)
			cout << 1 << ' ' << 0 << endl;
		else if (in == 1)
			cout << 0 << ' ' << 1 << endl;
		else
			cout << n_2 << ' ' << n_1 << endl;
		n_1 = 1;
		n_2 = 0;
		te = 0;
	}
}

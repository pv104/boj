#include <vector>
#include <iostream>
using namespace std;
vector<vector<int>> originals;
constexpr int MAX = 102;
int temps[MAX][MAX];
int r, n, m, x;
void input() {
	cin >> n >> m >> r;
	
		for (int i = 0; i < n; i++) {
			originals.push_back(vector<int>(m));

			for (int j = 0; j < m; j++) {
				cin >> originals[i][j];
			}
		}


}
vector<vector<int>> rotate(int op,vector<vector<int>> board) {
	int index = 0;
	int r, c;
	r = board.size();
	c = board[0].size();
	if (op == 1) {
		for (int i = 0; i < r / 2; i++) {
			for (int j = 0; j < c; j++) {
				swap(board[i][j], board[r-i-1][j]);
			}
		}
	}

	else if (op == 2) {
		for (int i = 0; i < c / 2; i++) {
			for (int j = 0; j < r; j++) {
				swap(board[j][i], board[j][c - i - 1]);
			}
		}
	}
	else if (op == 3) {

		vector<vector<int>> temp(c);
		for (int i = 0; i < c; i++)
			temp[i].resize(r);


			for (int i = 0; i <r; i++) {

				for (int j = 0; j < c; j++) {
					temp[j][r - i - 1] = board[i][j];
				}
			}

			board.resize(c);
			for (int i = 0; i < c; i++)
				board[i].resize(r);

			for (int i = 0; i < c; i++) {
				for (int j = 0; j < r; j++) {
					board[i][j] = temp[i][j];
				}
			}
			
			
	}
	else if (op == 4) {

			vector<vector<int>> temp(c);
			for (int i = 0; i < c; i++)
				temp[i].resize(r);

			for (int i = 0; i <r; i++) {
				for (int j = 0; j < c; j++) {
					temp[c - j - 1][i] = board[i][j];
				}
			}

			board.resize(c);
			for (int i = 0; i < c; i++)
				board[i].resize(r);
			for (int i = 0; i < c; i++) {
				for (int j = 0; j < r; j++) {
					board[i][j] = temp[i][j];
				}
			}
		
	}
	else if (op == 5) {
		int cn, cm;
		vector<vector<int>> temp(r);
			for (int i = 0; i <r; i++)
				temp[i].resize(c);
			cn = r / 2;
			cm = c / 2;
			// 1
			for (int i = 0; i < cn; i++) {
				for (int j = 0; j < cm; j++) {
					int nx = i + cn;
					int ny = j;
					temp[i][j] = board[nx][ny];
				}
			}

			// 2
			for (int i = 0; i < cn; i++) {
				for (int j = cm; j < c; j++) {
					int nx = i;
					int ny = j - cm;
					temp[i][j] = board[nx][ny];
				}
			}
			// 3
			for (int i = cn; i <r; i++) {
				for (int j = cm; j < c; j++) {
					int nx = i - cn;
					int ny = j;
					temp[i][j] = board[nx][ny];
				}
			}
			// 4

			for (int i = cn; i <r; i++) {
				for (int j = 0; j < cm; j++) {
					int nx = i;
					int ny = j + cm;
					temp[i][j] = board[nx][ny];
				}
			}

			for (int i = 0; i <r; i++) {
				for (int j = 0; j < c; j++) {
					board[i][j] = temp[i][j];
				}
			}

			
		
	}
	else if (op == 6) {
		for (int i = 0; i < 3; i++)
			board = rotate(5, board);
	}
	return board;
}
int main() {
	cin.tie(0); ios::sync_with_stdio(0);
	input();
	vector<vector<int>> board = originals;
	for (int cnt = 0; cnt < r; cnt++) {
		int op;
		cin >> op;

		board = rotate(op, board);



	}

	for (auto i : board) {
		for (auto j : i)
			cout << j << ' ';
		cout << "\n";
	}

}
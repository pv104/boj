#include <iostream>
#include <algorithm>
using namespace std;
#define SIZE 5
int N, M, res;
int papers[SIZE][SIZE], bits[SIZE][SIZE];
void input() {
    cin >> N >> M;
    char c;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> c;
            papers[i][j] = c - '0';
        }
    }
}
void solve() {
    // 1. 비트 연산으로 bits에 0/1 구하기 
    // (0 = 가로, 1 = 세로)
   
    for (int c = 0, k = (1 << N * M); c < k; c++) {
        // 여기에 비트 구하기
        int x = 0;
        for (int i = 0; i < N; i++) {
            for (int j=0; j< M; j++) {
                bits[i][j] = (c & (1 << x++)); // c 값을 NM번 비트연산하고 각각 (i,j)에 저장
            }
        }
        /*
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                cout << bits[i][j] << ' ';
            }
            cout << "\n";
        }*/
        int row = 0, col = 0;
        // 2. 가로 계산하기
        for (int i = 0; i < N; i++) {
            int cur = 0;
            for (int j = 0; j < M; j++) {
                if (bits[i][j] == 0) {
                    cur *= 10;
                    cur += papers[i][j];
                }
                else {
                    row += cur;
                    cur = 0;
                }
            }
            row += cur;
        }
        for (int j = 0; j < M; j++) {
            int cur = 0;
            for (int i = 0; i < N; i++) {
                if (bits[i][j] != 0) {
                    cur *= 10;
                    cur += papers[i][j];
                }
                else {
                    col += cur;
                    cur = 0;
                }
            }
            col += cur;
        }
        res = max(res, row + col);
    }
}
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    input();
    solve();
    cout << res;
}
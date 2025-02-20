#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define SIZE 2003
int N;
char s[SIZE];
vector<int> ctoi;
void input() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> s[i];
        ctoi.push_back(s[i] - 65);
    }
}
// 투포인터,그리디
void solve() {
    int f = 0, b = N-1;
    int cnt = 1;
    bool flag = false;
    while (cnt <= N) {

        for (int i = f, j = b; i <= b && j >= f; i++, j--) {
            if (s[i] == s[j]) continue;
            if (s[i] < s[j]) {
                flag = true;
            }
            break;
        }
        if (flag) {
            cout << s[f++];
        }
        else {
            cout << s[b--];
        }
        
        if (cnt % 80 == 0) {
            cout << "\n";
        }
        cnt++;
        flag = false;
    }
}
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    input();
    solve();
}
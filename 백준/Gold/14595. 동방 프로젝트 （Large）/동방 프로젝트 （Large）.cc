#include <iostream>
#include <map>
#include <algorithm>
using namespace std;
map <int, int> m, range;
int N, M;
void input() {
    cin >> N >> M;
    int k, v;
    for (int i = 0; i < M; i++) {
        cin >> k >> v;
        if (m.find(k) != m.end() && m[k] < v)
            m.insert_or_assign( k, v );
        else
            m.insert({ k, v });
    }
}
int solve() {
    if (M == 0) return N;
    int l = m.begin()->first, r = m.begin()->second;
    for (auto& cur : m) {
        int k = cur.first, v = cur.second;
        if (k > r) {
            range.insert({ l, r });
            l = k;
            r = v;
        }
        else { 
            r = max(r, v);
        }
        
    }
    range.insert({ l, r });
    int res = N;
    for (auto cur : range) {
        res -= (cur.second - cur.first);
    }
    return res;
}
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    input();
    cout << solve();
}
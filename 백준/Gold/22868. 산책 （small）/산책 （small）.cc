#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <memory.h>
#define N_SIZE 10003
#define fileio FILE* stream; freopen_s(&stream, "input.txt", "r", stdin)
#define START 0
#define END 1
using namespace std;
int N, M, S, E, minDist;
vector <int> v[N_SIZE];
bool visited[N_SIZE];
map <int, int> m[N_SIZE];
queue <pair<int,int>> q;
void input() {
    minDist = 1987654321;
    memset(visited, false, sizeof(visited));
    cin >> N >> M;
    int r, c;
    for (int i = 0; i < M; i++) {
        cin >> r >> c;
        v[r].push_back(c);
        v[c].push_back(r);
    }
    cin >> S >> E;
    for (int i = 0; i < N; i++) {
        sort(v[i].begin(), v[i].end());
    }
}
 //직전 정점 저장해두기. <cur,pre>
int bfs(int st,int ed) {
    q.push({ st,0 });
    int dist = 0;
    while (true) {
        int size = q.size();
        while (size != 0) {
            --size;
            auto cur = q.front(); q.pop();
            int val = cur.first;
            int pre = cur.second;
            // 루트 찾기
            if (val == ed) {
                memset(visited, false, sizeof(visited));
                int cur = val;
                // 방문 처리
                for (int i = dist - 1; i > 0; i--) {
                    auto nxt = m[i].find(cur);
                    cur = nxt->second;
                    visited[cur] = true;
                    //cout << " cur : " << cur << "\n";
                }
                while (!q.empty()) q.pop();
                return dist;
            }
            for (auto nxt : v[val]) {
                if (visited[nxt]) continue;
                visited[nxt] = true;
                q.push({ nxt,val });
                m[dist].insert({ nxt,val });
                //cout << " dist : " << dist << " nxt : " << nxt << " pre : " << val << "\n";
            }
        }
        dist++;
    }
}
int solve() {
    visited[S] = true;
    int res = bfs(S, E);

    for (auto i : m) {
        i.clear();
    }

    visited[E] = true;

    return res + bfs(E, S);

}
int main() {
    //fileio;
    cin.tie(0);
    cin.sync_with_stdio(0);

    input();
    cout << solve();
}
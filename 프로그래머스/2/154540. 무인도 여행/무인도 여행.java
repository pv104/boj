import java.util.*;
class Solution {
    static final int SIZE = 101;
    static final int[] dr = {-1,0,1,0}, dc = {0,1,0,-1};
    static int[][] A = new int[SIZE][SIZE];
    static boolean[][] vis = new boolean[SIZE][SIZE];
    static int N,M;
    static class Pair {
        int r,c;
        Pair() {}
        Pair(int r,int c) {
            this.r = r;
            this.c = c;
        }
    }
    static int bfs(int R,int C,int t, String[] maps) {
        ArrayDeque<Pair> q = new ArrayDeque<>();
        q.add(new Pair(R,C));
            while(!q.isEmpty()) {
                Pair cur = q.poll();
                int r = cur.r;
                int c = cur.c;
                for (int dir=0; dir<4; dir++) {
                    int nr = r+dr[dir];
                    int nc = c+dc[dir];
                    if(nr < 0 || nc < 0 || nr >= N || nc >= maps[nr].length() || vis[nr][nc]) continue;
                    if(A[nr][nc] < 1) continue;
                    t += A[nr][nc];
                    vis[nr][nc] = true;
                    q.add(new Pair(nr,nc));
                }
            }
        return t;
    }
    public int[] solution(String[] maps) {
        int[] answer = {};
        List<Integer> ans = new ArrayList<>();
        N = maps.length;
        for (int r=0; r<N; r++) {
            M = maps[r].length();
            for (int c=0; c<M; c++) {
                char ch = maps[r].charAt(c);
                if(ch == 'X') {
                    A[r][c] = -1;
                } else {
                    A[r][c] = ch-'0';
                }
            }
        }
        for (int r=0; r<N; r++) {
            M = maps[r].length();
            for (int c=0; c<M; c++) {
                if(A[r][c] > 0 && !vis[r][c]) {
                    int t = 0;
                    vis[r][c] = true;
                    t += bfs(r,c,A[r][c],maps);
                    ans.add(t);
                }
            }
        }
        if(ans.size() == 0) {
            answer = new int[1];
            answer[0] = -1; return answer;
        } else 
        return ans.stream().sorted().mapToInt(Integer::intValue).toArray();
    }
}
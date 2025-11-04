import java.io.*;
import java.util.*;

class Solution {
    static final int S = 1, E = 2, L = 3, O = 0, X = -1;
    static final int[] dr = {-1,0,1,0},dc = {0,1,0,-1};
    static final int SIZE = 102;
    static int N,M;
    static String[] A;
    int bfs(int[] s,int[] tg) {
        boolean[][] visited = new boolean[SIZE][SIZE];
        ArrayDeque<int[]> q = new ArrayDeque<>();
        visited[s[0]][s[1]] = true;
        q.add(new int[]{s[0],s[1],0});
        while(!q.isEmpty()) {
            int[] cur = q.poll();
            int r = cur[0];
            int c = cur[1];
            int t = cur[2];
            if(r == tg[0] && c == tg[1]) {
                return t;
            }
            for (int dir=0; dir<4; dir++) {
                int nr = r+dr[dir];
                int nc = c+dc[dir];
                if(nr < 0 || nc < 0 || nr >= N || nc >= A[nr].length() || visited[nr][nc]) continue;
                if(A[nr].charAt(nc) == 'X') continue;
                visited[nr][nc] = true;
                q.add(new int[]{nr,nc,t+1});
            }
        }
        return -1;
    }
    public int solution(String[] maps) {
        int answer = 0;
        int t1=0,t2=0;
        N = maps.length;
        A = new String[N+1];
        int[] s = new int[2];
        int[] l = new int[2];
        int[] e = new int[2];
        for (int i=0; i<N; i++)
            A[i] = maps[i];
        for (int i=0; i<N; i++) {
            for (int j=0; j<A[i].length(); j++) {
                if(A[i].charAt(j) == 'S') {
                    s[0] = i;
                    s[1] = j;
                }
                else if(A[i].charAt(j) == 'L') {
                    l[0] = i;
                    l[1] = j;
                }
            }
        }
        t1 = bfs(s,l);
         for (int i=0; i<N; i++) {
            for (int j=0; j<A[i].length(); j++) {
                if(A[i].charAt(j) == 'L') {
                    l[0] = i;
                    l[1] = j;
                }
                else if(A[i].charAt(j) == 'E') {
                    e[0] = i;
                    e[1] = j;
                }
            }
        }
        t2 = bfs(l,e);
        if((t1 == -1) || (t2 == -1)) answer = -1;
        else answer = t1 + t2;
        return answer;
    }
}
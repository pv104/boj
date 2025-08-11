import java.io.*;
import java.util.*;

class Solution {
    static final int SIZE=102, D=-1,R=1,G=2,INF=987654321;
    static final int[] dr = {-1,0,1,0}, dc = {0,1,0,-1};
    static int N,M;
    static int[][] A = new int[SIZE][SIZE];
    static int[][][] vis = new int[SIZE][SIZE][4]; 
    static class Data {
        int r,c,d,cnt;
        Data() {}
        Data(int o1, int o2, int o3, int o4) {
            r = o1;
            c = o2;
            d = o3;
            cnt = o4;
        }
    }
    static boolean inRange(int r,int c) {
        return r >= 0 && r < N && c >= 0 && c < M;
    }
    public int solution(String[] board) {
        int answer = 0;
        N=board.length;
        M=board[0].length();
        ArrayDeque<Data> q = new ArrayDeque<>();
        Data st = new Data(0,0,-1,0);
        for (int i=0; i<board.length; i++) {
            for (int j=0; j<board[i].length(); j++) {
                if(board[i].charAt(j) == 'D') {
                    A[i][j] = D;
                }
                else if(board[i].charAt(j) == 'R') {
                    A[i][j] = R;
                    st.r = i;
                    st.c = j;
                }
                else if(board[i].charAt(j) == 'G') {
                    A[i][j] = G;
                }
            }
        }
                for (int dir=0; dir<4; dir++) {
                    int nr = st.r+dr[dir];
                    int nc = st.c+dc[dir];
                    if((inRange(nr,nc)) && (A[nr][nc] == 0 || A[nr][nc] == G)) {
                    q.add(new Data(nr,nc,dir,1));
                    vis[nr][nc][dir] = 1;}
                        
                }
        for (int i=0; i<SIZE; i++) {
            for (int j=0; j<SIZE; j++) {
                for (int k=0; k<4; k++) {
                    vis[i][j][k] = INF;
                }
            }
        }
        answer = INF;
                while(!q.isEmpty()) {
                    Data cur = q.poll();
                    int r = cur.r;
                    int c = cur.c;
                    int d = cur.d;
                    int cnt = cur.cnt;
                    int nr = r+dr[d];
                    int nc = c+dc[d];
                    if((inRange(nr,nc) && A[nr][nc] == D) || (!inRange(nr,nc))) {
                        // 정상 종료
                        
                        if(A[r][c] == G) {
                         answer = Math.min(answer,cnt);   
                        }
                        // 방향 변경
                        for (int dir=0; dir<4; dir++) {
                            nr = r+dr[dir];
                            nc = c+dc[dir];
                            if((inRange(nr,nc)) && vis[nr][nc][dir] >= cnt && (A[nr][nc] == 0 || A[nr][nc] == G)) {
                                vis[nr][nc][dir] = cnt;
                                q.add(new Data(nr,nc,dir,cnt+1));
                            }
                            
                        }
                    } else if((inRange(nr,nc)) && vis[nr][nc][d] >= cnt && (A[nr][nc] == 0 || A[nr][nc] == G)) {
                        vis[nr][nc][d] = cnt;
                        q.add(new Data(nr,nc,d,cnt));
                    }
                }
                return answer == INF ? -1 : answer;
            }
        }

import java.util.*;
class Solution {
    public static int SIZE = 505, N,M;
    public static HashMap<Integer, Integer> gas = new HashMap<>();
    public static int dy[] = {-1,0,1,0};
    public static int dx[] = {0,1,0,-1};
    public static void bfs(int r,int c,int[][] board) {
        int idx = gas.size() + 2;
        ArrayDeque<int[]> q = new ArrayDeque<>();
        q.add(new int[]{r,c});
        int cnt = 1;
        board[r][c] = idx;
        while (!q.isEmpty()) {
            int[] cur = q.poll();
            // System.out.println("r " + r + " c " + c + " i " + cur[0] + " j " + cur[1] + "idx " + idx);
            for (int dir=0; dir<4; dir++) {
                int ny = cur[0]+dy[dir];
                int nx = cur[1]+dx[dir];
                if(ny < 0 || ny >= board.length || nx < 0 || nx >= board[ny].length || board[ny][nx] != 1) continue;
                cnt++;
                board[ny][nx] = idx;
                q.add(new int[]{ny,nx});
            }
        }
        gas.put(idx,cnt);
    }
    public static void seperateGas(int[][] a) {
        for (int i=0; i<a.length; i++) {
            for (int j=0; j<a[i].length; j++) {
             if(a[i][j] == 1) {
                 bfs(i,j,a);
             }   
            }
        }
    }
    public static int simulation(int[][] board) {
        int res=0;
        
        // 3,5 0,0 1,0 2,0 3,0 b l = 3 b[i] l = 5 -> (0,0 1,0 2,0까지)
        // 5,3 0,0 1,0 2,0 3,0 4,0 b l = 5, b[i] l = 3 4,0까지
        // (3,5) / j,i 
            for (int i=0; i<board[0].length; i++) {
                HashSet<Integer> visited = new HashSet<>();
                    int t=0;
                for (int j=0; j<board.length; j++) {
                    if(board[j][i] != 0) {
                        visited.add(board[j][i]);
                    }
                }
                for(int j : visited)
                    t += gas.get(j);
            res = Math.max(res,t);
        }
        return res;
    }
    public int solution(int[][] land) {
        seperateGas(land);
        
        int answer = simulation(land);
        return answer;
    }
}
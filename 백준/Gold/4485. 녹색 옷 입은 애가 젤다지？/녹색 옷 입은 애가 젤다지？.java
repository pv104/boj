import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Main {

	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	static StringBuilder sb = new StringBuilder();
	static int n,res;
	static final int INF = 987654321;
	static int dx[] = { -1,0,1,0};
	static int dy[] = { 0,1,0,-1};
	static int dist[][],board[][];
	static boolean visited[][];
	static PriorityQueue<Pair> pq;
	static void input(int t) throws Exception {
		n = t;
		board = new int[n][n];
		dist = new int[n][n];
		visited = new boolean[n][n]; 
		pq = new PriorityQueue<>();
		for (int i = 0; i < board.length; i++) {
			st = new StringTokenizer(br.readLine());
			for (int j = 0; j < board.length; j++) {
				board[i][j] = Integer.parseInt(st.nextToken());
				dist[i][j] = INF;
			}
		}
	}
	static class Pair implements Comparable<Pair>{
		int x;
		int y;
		int val;
		Pair() {}
		Pair(int x,int y,int val) {
			this.x = x;
			this.y = y;
			this.val = val;
		}
		@Override
		public int compareTo(Pair o) {
			return this.val - o.val;
		}
	}
	static int solve() throws Exception {
		pq.add(new Pair(0,0,board[0][0]));
		dist[0][0] = board[0][0];
		while(!pq.isEmpty()) {
			Pair cur = pq.poll();
			int r = cur.x;
			int c = cur.y;
			if(r == n-1 && c == n-1) {
				return dist[r][c];
			}
			for (int dir=0; dir<4; dir++) {
				int nr = r+dx[dir];
				int nc = c+dy[dir];
				if(nr < 0 || nc < 0 || nr >= n || nc >= n) continue;
				if(dist[nr][nc] > dist[r][c]+board[nr][nc]) {
					dist[nr][nc] = dist[r][c]+board[nr][nc];
					pq.add(new Pair(nr,nc,dist[nr][nc]));
				}
			}
		}
		return 0;
	}
	public static void main(String[] args) throws Exception {
		int t = 1;
		int counts=1;
		while(true) {
			t = Integer.parseInt(br.readLine());
			if(t == 0) break;
		input(t);
		sb.append("Problem ").append(counts++).append(": ").append(solve()).append("\n");
		}
		System.out.println(sb.toString());
	}
}
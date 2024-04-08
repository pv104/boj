import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Solution {

	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	static StringBuilder sb = new StringBuilder();
	static int visited[][];
	static int board[][];
	static int N;
	static final int INF = 987654321;
	static final int dx[] = {-1,0,1,0};
	static final int dy[] = {0,1,0,-1};
	static void input() throws Exception {
		N = Integer.parseInt(br.readLine());
		visited = new int[N][N];
		board = new int[N][N];
		for (int i = 0; i < N; i++) {
			String str = br.readLine();
			Arrays.fill(visited[i], INF);
			for (int j = 0; j < N; j++) {
				board[i][j] = str.charAt(j) - '0';
			}
		}
	}
	static class Pair implements Comparable <Pair> {
		int x;
		int y;
		int sec;
		public Pair() {
		}
		Pair(int x,int y,int sec) {
			this.x = x;
			this.y = y;
			this.sec = sec;
		}
		@Override
		public int compareTo(Pair o) {
			return this.sec - o.sec;
		}
	}
	static int solve() throws Exception {
		int res=0;
		PriorityQueue<Pair> q = new PriorityQueue<>();
		q.add(new Pair(0,0,0));
		visited[0][0] = INF;
		while(!q.isEmpty()) {
			Pair cur = q.poll();
			int x = cur.x;
			int y = cur.y;
			int sec = cur.sec;
			if(x == N-1 && y == N-1) break;
			for (int dir = 0; dir < 4; dir++) {
				int nx = x+dx[dir];
				int ny = y+dy[dir];
				if(nx < 0 || ny < 0 || nx >= N || ny >= N || visited[nx][ny] != INF) continue;
				int nsec = sec + board[nx][ny];
				visited[nx][ny] = nsec;
				q.add(new Pair(nx,ny,nsec));
			}
		}
		return res = visited[N-1][N-1];
	}
	public static void main(String[] args) throws Exception {
		int T;
		T = Integer.parseInt(br.readLine());
		for (int i = 1; i <= T; i++) {
			input();
			sb.append("#").append(i).append(" ").append(solve()).append("\n");
		}
		System.out.print(sb);
	}
}
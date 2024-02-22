import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.StringTokenizer;

public class Solution {

	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	static StringBuilder sb = new StringBuilder();
	static int dx[] = { -1, 0, 1, 0 };
	static int dy[] = { 0, 1, 0, -1 };
	static boolean visited[];

	static class Pair {
		int x;
		int cnt;

		public Pair() {
		}

		public Pair(int x, int cnt) {
			this.x = x;
			this.cnt = cnt;
		}
	}

	static int start, n;
	public static final int MAX = 102;
	static int[][] board;
	static ArrayDeque<Pair> q;
	static int[][] result;

	static void input() throws Exception {
		st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		start = Integer.parseInt(st.nextToken());
		st = new StringTokenizer(br.readLine());

		board = new int[MAX][MAX];
		result = new int[MAX][MAX];
		
		visited = new boolean[MAX];
		q = new ArrayDeque<>();
		int from, to;
		while (st.hasMoreTokens()) {
			from = Integer.parseInt(st.nextToken());
			to = Integer.parseInt(st.nextToken());
			board[from][to] = 1;
		}
	}

	static int solve() {
		q.add(new Pair(start, 0));
		int res = 0;
		while (!q.isEmpty()) {
			Pair cur = q.poll();
			int x = cur.x;
			int cnt = cur.cnt;
			for (int i = 0; i < MAX; i++) {
				
				int y = i;
				int ncnt = cnt + 1;
				if (visited[y] || board[x][y] == 0)
					continue;
				visited[y] = true;
				q.add(new Pair(y, ncnt));
				result[x][y] = ncnt;
				
			}
		}
		
		int max=0;
		for (int i = 0; i < MAX; i++) {
			for (int j = 0; j < MAX; j++) {
				max = Math.max(max, result[i][j]);
			}
		}
		for (int i = 0; i < MAX; i++) {
			for (int j = 0; j < MAX; j++) {
				if(max == result[i][j]) {
					res = Math.max(res, j);
				}
			}
		}
		return res;
	}

	public static void main(String[] args) throws Exception {

		for (int tc = 0; tc < 10; tc++) {
			input();
			sb.append("#").append(tc + 1).append(" ").append(solve()).append("\n");
		}
		System.out.print(sb);
	}
}
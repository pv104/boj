import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.StringTokenizer;

public class Main {

	static int n,m,v;
	static int board[][];
	static boolean visited[];
	static StringBuilder sb = new StringBuilder();
	static StringTokenizer st;
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static ArrayDeque<Integer> q;
	static void input() throws Exception {
		st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		v = Integer.parseInt(st.nextToken());
		board = new int[n+1][n+1];
		q = new ArrayDeque<>();
		visited = new boolean[n+1];
		for (int i=1; i<=m; i++) {
			st = new StringTokenizer(br.readLine()," ");
			int x = Integer.parseInt(st.nextToken());
			int y = Integer.parseInt(st.nextToken());
			board[x][y] = board[y][x] = 1;
		}
	}
	static void dfs(int cur) {

		sb.append(cur).append(" ");
		for (int nxt=1; nxt<=n; nxt++) {
			if(visited[nxt] || board[cur][nxt] != 1) continue;
			visited[nxt] = true;
			dfs(nxt);
		}
		return;
	}
	static void init() {
		for (int i=1; i<=n; i++)
			visited[i] = false;
		visited[v] = true;
	}
	static void bfs() {
		sb.append(v).append(" ");
		q.add(v);
		while(!q.isEmpty()) {
			int cur = q.poll();
			for (int nxt=1; nxt<=n; nxt++) {
				if(visited[nxt]|| board[cur][nxt] != 1) continue;
				visited[nxt] = true;
				sb.append(nxt).append(" ");
				q.add(nxt);
			}
		}
		return;
	}
	public static void main(String[] args) throws Exception {
		input();
		init();
		dfs(v);
		sb.append("\n");
		init();
		bfs();
		sb.append("\n");
		System.out.println(sb);
	}
}
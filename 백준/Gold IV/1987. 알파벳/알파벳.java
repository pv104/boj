import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static char board[][];
	static int r,c;
	static boolean visited[];
	static int result;
	static int dx[]= {-1,0,1,0};
	static int dy[]= {0,1,0,-1};
	static StringTokenizer st;
	static class Sc {
		public Sc(int x, int y, int alpha, int cnt) {
			this.x = x;
			this.y = y;
			this.alpha = alpha;
			this.cnt = cnt;
		}
		int x;
		int y;
		int alpha;
		int cnt;
	}
	static void input() throws IOException {
		st = new StringTokenizer(br.readLine());
		r = Integer.parseInt(st.nextToken());
		c = Integer.parseInt(st.nextToken());
		board = new char[r][c];
		visited = new boolean[27];
		for (int i=0; i<r; i++) {
			String s = br.readLine();
			for (int j = 0; j < s.length(); j++) {
				board[i][j] = s.charAt(j);
			}
		}
		visited[board[0][0] - 'A'] = true;
	}
	static int dfs(Sc cur) {
		int x = cur.x;
		int y = cur.y;
		int alpha = cur.alpha;
		int cnt = cur.cnt;
		for (int dir=0; dir<4; dir++) {
			int nx = x+dx[dir];
			int ny = y+dy[dir];
			if (nx < 0 || ny < 0 || nx >= r || ny >= c || visited[board[nx][ny] - 'A']) continue;
			visited[board[nx][ny]-'A'] = true;
			result = Math.max(result, dfs(new Sc(nx,ny,board[nx][ny]-'A',cnt+1)));
			visited[board[nx][ny]-'A'] = false;
		}
		return Math.max(result, cnt);
	}
	static int solve() {
		
		result = Math.max(result, dfs(new Sc(0,0,board[0][0] - 'A',1)));
		
		return result;
	}
	public static void main(String[] args) throws Exception {
		input();
		System.out.print(solve());
	}
}
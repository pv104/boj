import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Queue;
import java.util.StringTokenizer;

public class Solution {

	static final char SPACE = '.';
	static final char BRICK = '*';
	static final char IRON = '#';
	static final char WATER = '-';
	static final char UP = '^';
	static final char DOWN = 'v';
	static final char LEFT = '<';
	static final char RIGHT = '>';
	static char board[][];
	static int n;
	static int h, w;
	static String S;
	

	static class Tank {
		int r;
		int c;
		int dir;

		public Tank(int r, int c, int dir) {
			this.r = r;
			this.c = c;
			this.dir = dir;
		}
	}

	static Tank tank;
	static int dx[] = { -1, 0, 1, 0 };
	static int dy[] = { 0, 1, 0, -1 };
	static final char dirT[] = { UP, RIGHT, DOWN, LEFT };
	static final char dirD[] = { 'U', 'R', 'D', 'L' };
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringBuilder sb = new StringBuilder();
	static StringTokenizer st;

	static void input() throws Exception {
		st = new StringTokenizer(br.readLine());
		h = Integer.parseInt(st.nextToken());
		w = Integer.parseInt(st.nextToken());
		board = new char[h][w];
		for (int i = 0; i < h; i++) {
			String s = br.readLine();
			for (int j = 0; j < w; j++) {
				board[i][j] = s.charAt(j);
				for (int k = 0; k < 4; k++) {
					if (board[i][j] == dirT[k])
						tank = new Tank(i, j, k);
				}

			}
		}
		n = Integer.parseInt(br.readLine());
		S = br.readLine();
	}

	static boolean OOB(int r, int c) {
		return r < 0 || c < 0 || r >= h || c >= w;
	}

	static void shoot() {
		int dir = tank.dir;
		Queue<Tank> q = new ArrayDeque<>();
		q.add(tank);
				while (!q.isEmpty()) {
					Tank tanks = q.poll();
					int nr = tanks.r + dx[dir];
					int nc = tanks.c + dy[dir];
					if (OOB(nr, nc)) continue;
					char cur = board[nr][nc];
					if (cur == BRICK || cur == IRON) {
						if (cur == BRICK) {
							board[nr][nc] = SPACE;
						}
						return;
					}
					q.add(new Tank(nr,nc,dir));
				
				}
			
	}

	static void move(char uDir) {
		for (int dir = 0; dir < 4; dir++) {
			if (dirD[dir] == uDir) {
				tank.dir = dir;
			}
		}
			int r = tank.r;
			int c = tank.c;
			int dirs = tank.dir;
			board[r][c] = dirT[dirs];
				int nr = r + dx[dirs];
				int nc = c + dy[dirs];
				if (OOB(nr, nc)) {
					return;
				}
				char cur = board[nr][nc];
				if (cur == SPACE) {
					board[nr][nc] = dirT[dirs];
					board[r][c] = SPACE;
					tank.r = nr;
					tank.c = nc;
					return;
				} 
			}

	static String solve() {
		StringBuilder sb2 = new StringBuilder();
		for (int cnt = 0; cnt < n; cnt++) {
			switch (S.charAt(cnt)) {
			case 'S':
				shoot();
				break;
			default:
				move(S.charAt(cnt));
				break;
			}
		}
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				sb2.append(board[i][j]);
			}
			sb2.append("\n");
		}
		return sb2.toString();
	}

	public static void main(String[] args) throws Exception {

		int t = Integer.parseInt(br.readLine());
		for (int tc = 1; tc <= t; tc++) {
			input();
			sb.append("#").append(tc).append(" ").append(solve());
		}
		System.out.println(sb);
	}
}
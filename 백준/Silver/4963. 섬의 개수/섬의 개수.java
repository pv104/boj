import java.io.*;
import java.util.*;

public class Main {

	static final int SIZE = 52;
	static final int[] dr = new int[] { -1,-1,0,1,1,1,0,-1 }, dc = { 0,1,1,1,0,-1,-1,-1 };
	static int[][] A = new int[SIZE][SIZE];
	static boolean[][] visited = new boolean[SIZE][SIZE];
	static int W, H;

	static void init() {
		for (int i = 0; i < SIZE; i++) {
			for (int j = 0; j < SIZE; j++) {
				A[i][j] = 0;
				visited[i][j] = false;
			}
		}
	}

	static void bfs(int h, int w) {
		ArrayDeque<int[]> q = new ArrayDeque<>();
		q.add(new int[] { h, w });
		visited[h][w] = true;
		while (!q.isEmpty()) {
			int[] cur = q.poll();
			int r = cur[0];
			int c = cur[1];
			for (int dir = 0; dir < 8; dir++) {
				int nr = r + dr[dir];
				int nc = c + dc[dir];
				if (nr < 0 || nc < 0 || nr >= H || nc >= W || visited[nr][nc] || A[nr][nc] == 0)
					continue;
				q.add(new int[] { nr, nc });
				visited[nr][nc] = true;
			}
		}
		return;
	}

	public static int solve() {
		int answer = 0;
		for (int i=0; i<H; i++) {
			for (int j=0; j<W; j++) {
				if(A[i][j] == 1 && !visited[i][j]) {
					answer++;
					bfs(i,j);
				}
			}
		}
		return answer;
	}

	public static void main(String[] args) throws Exception {
		BufferedReader br;
		br = new BufferedReader(new InputStreamReader(System.in));
		while (true) {
			init();
			StringTokenizer st = new StringTokenizer(br.readLine());
			W = Integer.parseInt(st.nextToken());
			H = Integer.parseInt(st.nextToken());
			if (W == 0 && H == 0)
				break;
			for (int i = 0; i < H; i++) {
				st = new StringTokenizer(br.readLine());
				for (int j = 0; j < W; j++) {
					A[i][j] = Integer.parseInt(st.nextToken());
				}
			}
			System.out.println(solve());
		}
	}
}

import java.io.*;
import java.util.*;

public class Main {

	public static final int N_SIZE = 1002, M_SIZE = 1002;
	public static final int[] dr = { -1, 0, 1, 0 }, dc = { 0, 1, 0, -1 };
	public static int N, M, T;

	public static ArrayDeque<int[]> q;
	public static int[][] A = new int[N_SIZE][M_SIZE];
	public static boolean[][] visited = new boolean[N_SIZE][M_SIZE];

	public static void bfs(int i, int j) {
		q = new ArrayDeque<>();
		q.add(new int[] { i, j });
		while (!q.isEmpty()) {
			int[] cur = q.poll();
			for (int dir = 0; dir < 4; dir++) {
				int nr = cur[0] + dr[dir];
				int nc = cur[1] + dc[dir];
				if (nr < 0 || nc < 0 || nr >= N || nc >= M || visited[nr][nc] || A[nr][nc] != 255)
					continue;
				visited[nr][nc] = true;
				q.add(new int[] { nr, nc });
			}
		}
	}

	public static int solve() {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				A[i][j] = (A[i][j] >= T) ? 255 : 0;
			}
		}
		int answer = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (!visited[i][j] && A[i][j] == 255) {
					answer++;
					bfs(i, j);
					visited[i][j] = true;
				}
			}
		}
		return answer;
	}

	public static void main(String[] args) throws Exception {
		BufferedReader br;
		br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		for (int i = 0; i < N; i++) {
			st = new StringTokenizer(br.readLine());
			for (int j = 0; j < M; j++) {
				int s = 0;
				for (int k = 0; k < 3; k++) {
					s += Integer.parseInt(st.nextToken());
				}
				s /= 3;
				A[i][j] = s;
			}
		}
		st = new StringTokenizer(br.readLine());
		T = Integer.parseInt(st.nextToken());
		System.out.print(solve());
	}
}

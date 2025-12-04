import java.io.*;
import java.util.*;

public class Main {

	public static class Pair {
		int r, c;

		Pair() {
		}

		Pair(int r1, int c1) {
			r = r1;
			c = c1;
		}
	}

	public static final int[] dr = { -1, 0, 1, 0 }, dc = { 0, 1, 0, -1 };
	public static int N, Q;
	public static int[] L;
	public static int[][] A;

	public static int[] run() {
		int sum = 0, cnt = 0;
		for (int q = 0; q < Q; q++) {
			int l = 0;
			{
				int t = 1;
				for (int i = 0; i < L[q]; i++)
					t *= 2;
				l = t;
			}
			rotate(l);
			calculate();
		}
		sum = findSum();
		cnt = bfs();
		return new int[] { sum, cnt };

	}

	static int findSum() {
		int sum = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (A[i][j] > 0)
					sum += A[i][j];
			}
		}
		return sum;
	}

	static void rotate(int l) {
		for (int r = 0; r < N; r += l) {
			for (int c = 0; c < N; c += l) {
				int[][] ca = new int[l][l];
				for (int i = 0; i < l; i++) {
					for (int j = 0; j < l; j++) {
						ca[j][l - 1 - i] = A[i + r][j + c];
					}
				}
				for (int i = 0; i < l; i++) {
					for (int j = 0; j < l; j++) {
						A[i + r][j + c] = ca[i][j];
					}
				}
			}
		}
	}

	static boolean inRange(int r, int c) {
		return (0 <= r && r < N && 0 <= c && c < N);
	}

	static void calculate() {
		int[][] ca = new int[N][N];
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				int cnt = 0;
				for (int dir = 0; dir < 4; dir++) {
					int nr = i + dr[dir];
					int nc = j + dc[dir];
					if (inRange(nr, nc) && A[nr][nc] > 0) {
						cnt++;
					}
				}
				if (cnt < 3)
					ca[i][j]--;
			}
		}
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				A[i][j] += ca[i][j];
			}
		}
	}

	static int bfs() {
		int cnts = 0;
		ArrayDeque<Pair> q = new ArrayDeque<>();
		boolean[][] visited = new boolean[N][N];
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (A[i][j] > 0 && !visited[i][j]) {
					q.add(new Pair(i, j));
					visited[i][j] = true;
					int cnt = 1;
					while (!q.isEmpty()) {
						Pair cur = q.poll();
						for (int dir = 0; dir < 4; dir++) {
							int nr = cur.r + dr[dir];
							int nc = cur.c + dc[dir];
							if (inRange(nr, nc) && !visited[nr][nc] && A[nr][nc] > 0) {
								visited[nr][nc]=true;
								cnt++;
								q.add(new Pair(nr, nc));
							}
						}
					}
					cnts = Math.max(cnts, cnt);
				}
			}
		}
		return cnts;
	}

	public static void main(String[] args) throws Exception {
		BufferedReader br;
		br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		Q = Integer.parseInt(st.nextToken());
		int t = 1;
		for (int i = 0; i < N; i++) {
			t *= 2;
		}
		N = t;
		A = new int[N][N];
		for (int i = 0; i < N; i++) {
			st = new StringTokenizer(br.readLine());
			for (int j = 0; j < N; j++) {
				A[i][j] = Integer.parseInt(st.nextToken());
			}
		}
		L = new int[Q];
		st = new StringTokenizer(br.readLine());
		for (int i = 0; i < Q; i++) {
			L[i] = Integer.parseInt(st.nextToken());
		}
		int[] answer = run();
		System.out.println(answer[0]);
		System.out.println(answer[1]);
	}
}

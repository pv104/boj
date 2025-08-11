import java.io.*;
import java.util.*;

public class Main {

	static class Pair {
		int r;
		int c;

		Pair() {
		}

		Pair(int r, int c) {
			this.r = r;
			this.c = c;
		}
	}

	static final int SIZE = 102;
	static final int[] dr = { -1, 0, 1, 0 }, dc = { 0, 1, 0, -1 };

	static int N, K, R;
	// A[r][c].get(r',c') != null -> 길 있음
	static ArrayList<Pair>[][] A = new ArrayList[SIZE][SIZE];
	static int[][] C = new int[SIZE][SIZE];
	static boolean[][] vis = new boolean[SIZE][SIZE];

	// *** 1-based
	static int bfs(int r, int c) {
		int answer = K-1;
		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= N; j++)
				vis[i][j] = false;
		ArrayDeque<Pair> q = new ArrayDeque<>();
		q.add(new Pair(r, c));
		vis[r][c] = true;
		while (!q.isEmpty()) {
			Pair p = q.poll();
			r = p.r;
			c = p.c;
			for (int dir = 0; dir < 4; dir++) {
				int nr = r + dr[dir];
				int nc = c + dc[dir];
				boolean flag = true;
				if (nr < 1 || nr > N || nc < 1 || nc > N || vis[nr][nc])
					continue;
				if (A[r][c] != null) {
					for (Pair np : A[r][c]) {
						if (np.r == nr && np.c == nc) {
							flag = false;
							break;
						}
					}
				}
				if (flag) {
					vis[nr][nc] = true;
					q.add(new Pair(nr, nc));
					if (C[nr][nc] > 0)
						{
						answer--;
						}

				}
			}
		}
		return answer;
	}

	static int run() {
		int answer = 0;
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (C[i][j] != 0) {
					answer += bfs(i, j);
				}
			}
		}
		
		return answer >> 1;
	}

	public static void main(String[] args) throws Exception {
		BufferedReader br;
		br = new BufferedReader(new InputStreamReader(System.in));
//		br = new BufferedReader(new FileReader("input.txt"));
		StringTokenizer st = new StringTokenizer(br.readLine());

		N = Integer.parseInt(st.nextToken());
		K = Integer.parseInt(st.nextToken());
		R = Integer.parseInt(st.nextToken());

		for (int i = 0; i < R; i++) {
			st = new StringTokenizer(br.readLine());
			int r = Integer.parseInt(st.nextToken());
			int c = Integer.parseInt(st.nextToken());
			int rr = Integer.parseInt(st.nextToken());
			int cc = Integer.parseInt(st.nextToken());
			if (A[r][c] == null)
				A[r][c] = new ArrayList<>();
			if(A[rr][cc] == null)
				A[rr][cc] = new ArrayList<>();
			A[r][c].add(new Pair(rr, cc));
			A[rr][cc].add(new Pair(r,c));

		}
		for (int i = 0; i < K; i++) {
			st = new StringTokenizer(br.readLine());
			int r = Integer.parseInt(st.nextToken());
			int c = Integer.parseInt(st.nextToken());
			C[r][c] = i + 1;
		}

		System.out.println(run());
	}
}

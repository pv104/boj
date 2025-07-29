import java.io.*;
import java.util.*;

public class Main {

	static int N = 5;
	static int[] num = new int[N], numR = new int[N];
	static int[][][] A = new int[N][N][N], cA = new int[N][N][N], tA = new int[N][N][N];

	static boolean[] isSelected = new boolean[N], isSelectedR = new boolean[N];
	static boolean[][][] visited = new boolean[N + 1][N][N];
	static int[][] dt = { { 0, 0, 1 }, { 0, 0, -1 }, { 0, 1, 0 }, { 0, -1, 0 }, { 1, 0, 0 }, { -1, 0, 0 } };

	static int[][] dots = { { 0, 0, 0 }, { 4, 4, 4 }, { 0, 0, 4 }, { 4, 4, 0 }, { 0, 4, 0 }, { 4, 0, 4 }, { 0, 4, 4 },
			{ 4, 0, 0 } };

	static ArrayDeque<int[]> q;
	static int answer = Integer.MAX_VALUE;

	static void pmt(int k) {

		if (answer == 12)
			return;
		if (k == N) {
			copy();
			pmtR(0);
			return;
		}
		for (int i = 0; i < N; i++) {
			if (isSelected[i])
				continue;
			isSelected[i] = true;
			num[k] = i;
			pmt(k + 1);
			isSelected[i] = false;
		}
	}

	static void copy() {
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				for (int k = 0; k < N; k++)
					cA[num[i]][j][k] = A[i][j][k];
	}

	static void pmtR(int k) {
		if (answer == 12)
			return;
		if (k == N) {
			run();
			return;
		}

		for (int i = 0; i < 4; i++) {
			numR[k] = i;
			pmtR(k + 1);

		}
	}

	static void bfs() {
		q = new ArrayDeque<>();
		int[] dest = new int[3], src = new int[3];

		for (int cb = 0; cb < 8; cb += 2) {
			for (int k = 0; k < 3; k++) {
				dest[k] = dots[cb][k];
				src[k] = dots[cb + 1][k];
			}
			for (int i = 0; i < 5; i++)
				for (int j = 0; j < 5; j++)
					for (int k = 0; k < 5; k++)
						visited[i][j][k] = false;
			int s = dest[0];
			int r = dest[1];
			int c = dest[2];
			int p = 0;
			if (cA[s][r][c] == 0 || cA[src[0]][src[1]][src[2]] == 0)
				continue;
			q.add(new int[] { s, r, c, p });
			visited[s][r][c] = true;
			// 초기 설정
			while (!q.isEmpty()) {
				int[] cur = q.poll();
				s = cur[0];
				r = cur[1];
				c = cur[2];
				p = cur[3];
				if (answer < p) {
					q.clear();
					break;
				}
				if (s == src[0] && r == src[1] && c == src[2]) {
					answer = Math.min(answer, p);
					q.clear();
					break;
				}
				for (int dir = 0; dir < 6; dir++) {
					int ns = s + dt[dir][0];
					int nr = r + dt[dir][1];
					int nc = c + dt[dir][2];
					if (s == 0) {
						if (nr < 0 || nc < 0 || nr > 4 || nc > 4 || ns < 0 || ns > 4 || visited[ns][nr][nc])
							continue;
						if (cA[ns][nr][nc] == 0)
							continue;
						visited[ns][nr][nc] = true;
						q.add(new int[] { ns, nr, nc, p + 1 });
					} else {
						if (nr < 0 || nc < 0 || nr > 4 || nc > 4 || ns < 0 || ns > 4 || visited[ns][nr][nc])
							continue;
						if (cA[ns][nr][nc] == 0)
							continue;
						visited[ns][nr][nc] = true;
						q.add(new int[] { ns, nr, nc, p + 1 });
					}
				}
			}

		}
	}

	static void run() {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < numR[i]; j++) {
				rotate(num[i]); // 회전하기
			}
		}
		bfs();
		copy();
	}

	static void rotate(int i) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < N; k++) {
				tA[i][k][N - 1 - j] = cA[i][j][k];
			}
		}
		for (int j = 0; j < N; j++)
			for (int k = 0; k < N; k++)
				cA[i][j][k] = tA[i][j][k];
	}

	public static void main(String[] args) throws Exception {
		BufferedReader br;
		br = new BufferedReader(new InputStreamReader(System.in));

		StringTokenizer st;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				st = new StringTokenizer(br.readLine());
				for (int k = 0; k < N; k++)
					A[i][j][k] = Integer.parseInt(st.nextToken());
			}
		}
		pmt(0);
		if (answer == Integer.MAX_VALUE)
			answer = -1;
		System.out.print(answer);
	}
}

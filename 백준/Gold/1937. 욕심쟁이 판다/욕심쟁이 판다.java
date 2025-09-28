import java.io.*;
import java.util.*;

public class Main {

	static final int[] dr = { -1, 0, 1, 0 }, dc = { 0, 1, 0, -1 };
	static final int N_SIZE = 502;
	static int[][] A = new int[N_SIZE][N_SIZE];
	static int answer = -1, N;
	static int[][][] dp = new int[N_SIZE][N_SIZE][4];

	static int rec(int r, int c, int d) {

		if (dp[r][c][d] != -1)
			return dp[r][c][d];
		dp[r][c][d] = 1;
		for (int dir = 0; dir < 4; dir++) {
			int nr = r + dr[dir];
			int nc = c + dc[dir];
			if (nr < 0 || nc < 0 || nr >= N || nc >= N)
				continue;

			if (A[r][c] < A[nr][nc]) {
				dp[r][c][d] = Math.max(rec(nr, nc, dir) + 1, dp[r][c][d]);
			}
		}
		return dp[r][c][d];
	}

	public static void main(String[] args) throws Exception {
		BufferedReader br;
		br = new BufferedReader(new InputStreamReader(System.in));
//		br = new BufferedReader(new FileReader("input.txt"));
		StringTokenizer st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		for (int i = 0; i < N; i++) {
			st = new StringTokenizer(br.readLine());
			for (int j = 0; j < N; j++)
				A[i][j] = Integer.parseInt(st.nextToken());
		}
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				for (int k = 0; k < 4; k++)
					dp[i][j][k] = -1;
			}
		}
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				for (int dir = 0; dir < 4; dir++)
					answer = Math.max(answer, rec(i, j, dir));
		System.out.println(answer);
	}
}

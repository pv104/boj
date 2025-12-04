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

	public static final int[][][] percents = {
			{ { 0, 0, 2, 0, 0 }, { 0, 10, 7, 1, 0 }, { 5, 55, 0, 0, 0 }, { 0, 10, 7, 1, 0 }, { 0, 0, 2, 0, 0 } },
			{ { 0, 0, 0, 0, 0 }, { 0, 1, 0, 1, 0 }, { 2, 7, 0, 7, 2 }, { 0, 10, 55, 10, 0 }, { 0, 0, 5, 0, 0 } },
			{ { 0, 0, 2, 0, 0 }, { 0, 1, 7, 10, 0 }, { 0, 0, 0, 55, 5 }, { 0, 1, 7, 10, 0 }, { 0, 0, 2, 0, 0 } },
			{ { 0, 0, 5, 0, 0 }, { 0, 10, 55, 10, 0 }, { 2, 7, 0, 7, 2 }, { 0, 1, 0, 1, 0 }, { 0, 0, 0, 0, 0 } } }; // [dir][i][j]

	public static final int[] dr = { 0, 1, 0, -1 }, dc = { -1, 0, 1, 0 };
	public static final int N_SIZE = 502;

	public static int N, sum;
	public static int[][] A = new int[N_SIZE][N_SIZE];

	public static boolean inRange(int r, int c) {
		return r >= 0 && r < N && c >= 0 && c < N;
	}

	public static void calculate(int nr, int nc, int dir) {
//		System.out.println(" calculate, r c dir " + r + " " + c + " " + dir);
		int cost = A[nr][nc];
		int ar = nr+dr[dir], ac = nc+dc[dir];
		A[nr][nc] = 0; //y의 위치
		int rm = cost;
		// y의 값을 비율대로 A[tr][tc]에 이동하고, a에 나머지를 이동
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				int tr = nr - 2 + i;
				int tc = nc - 2 + j;
				// 모래를 percents에 적힌 비율대로 이동시킬 수 있는 경우
				if (inRange(tr, tc) && percents[dir][i][j] > 0 && percents[dir][i][j] < 55) {
//					System.out.println("A[r+i][c+j] 이전 " + A[r+i][c+j] + " mod " + (percents[dir][i][j]));
					A[tr][tc] += (cost * percents[dir][i][j] / 100);
					rm -= (cost * percents[dir][i][j] / 100);
//					System.out.println("A[r+i][c+j] 이후 " + A[r+i][c+j]);
				}
				
				// 모래가 밖으로 나가서 버려지는 경우
				else if(!inRange(tr,tc))
					rm -= (cost * percents[dir][i][j] / 100);
			}
		}
		if(inRange(ar,ac))
			A[ar][ac] += rm;
//		print();
		return;
	}

	public static void print() {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				System.out.print(A[i][j] + " ");
			}
			System.out.println();
		}
	}

	public static void solve() {
		int r = N / 2, c = N / 2, dir = 0;
		for (int k = 1; k <= N; k++) {
			for (int cur = 1; cur <= 2; cur++) {
				for (int cnt = 1; cnt <= k; cnt++) {
					if (r == 0 && c == 0)
						return;
					calculate(r + dr[dir], c + dc[dir], dir);
					r = r + dr[dir];
					c = c + dc[dir];
				}
				dir++;
				dir %= 4;
			}
		}
	}

	public static void rec(int r, int c, int dir, int k, int cur, int cnt) {
		if (r == 0 && c == 0)
			return;
//		if (cur > k || cnt > 2 || k > N)
//			return;
//		System.out.println(" rec " + r + " " + c + " " + dir + " " + k + " " + cur + " " + cnt + " sum : " + findSum());
//		print();
		calculate(r+dr[dir], c+dc[dir], dir);
//		System.out.println("계산 후");
//		print();
		if (cur == k) {
			if (cnt == 2) {
				rec(r + dr[dir], c + dc[dir], (dir + 1) % 4, k + 1, 1, 1);
			} else {
				rec(r + dr[dir], c + dc[dir], (dir + 1) % 4, k, 1, 2);
			}

		} else {
			rec(r + dr[dir], c + dc[dir], dir, k, cur + 1, cnt);
		}

	}

	public static int findSum() {
		int t = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				t += A[i][j];
			}
		}
		return t;
	}

	public static int run() {
		rec(N / 2, N / 2, 0, 1, 1, 1);
//		solve();
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				sum -= A[i][j];
			}
		}
		return sum;
	}

	public static void main(String[] args) throws Exception {
		BufferedReader br;
		br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		for (int i = 0; i < N; i++) {
			st = new StringTokenizer(br.readLine());
			for (int j = 0; j < N; j++) {
				A[i][j] = Integer.parseInt(st.nextToken());
				sum += A[i][j];
			}
		}
		System.out.print(run());
	}
}

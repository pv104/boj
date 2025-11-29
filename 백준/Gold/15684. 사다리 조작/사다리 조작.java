import java.io.*;
import java.util.*;

public class Main {

	static final int N_SIZE = 11, M_SIZE = 301, H_SIZE = 31;
	static int N, M, H, answer = 4;
	static boolean[][][] A = new boolean[H_SIZE][N_SIZE][N_SIZE];

	static boolean isCollision(int h, int i, int j) {
		if (h < H && i > 1) {
			if (A[h][i - 1][i])
				return true;
		}
		if (h < H && j < N) {
			if (A[h][j][j + 1])
				return true;
		}

		return false;
	}

	static int play(int h, int i, int si) {
		if (h > H)
			return i;
//		System.out.println("play, h, i" + " " + h + " " + i + " si " + si);
		if (i > 1 && A[h][i - 1][i])
			return play(h + 1, i - 1, si);
		else if (i < N && A[h][i][i + 1])
			return play(h + 1, i + 1, si);
		else
			return play(h + 1, i, si);

	}

	static boolean simulation() {
		boolean flag = true;
		for (int i = 1; i <= N; i++) {
			if (play(1, i, i) == i) {

//				System.out.println(" simulation, play result : " + i + " nh, ni " + nh + " " + ni);
				continue;
			}
			return false;
		}
//		print();
		return flag;
	}

	static void print() {
		for (int h = 1; h <= H; h++) {
			for (int i = 1; i <= N; i++) {
				if (A[h][i][i + 1])
					System.out.println("h, i, i+1 " + h + " " + i + " " + (i + 1));
			}
		}
	}

	static void rec(int h, int k, int cnt) {
		if (k == 3)
			return;
		if (answer == 1)
			return;
//		System.out.println(" cnt : " + cnt);
		// 0, 1, 2, 0, 1, 3 ... ->
		for (int nh = h; nh <= H; nh++) {
			for (int ni = 1; ni < N; ni++) {
				if (isCollision(nh, ni, ni + 1) || A[nh][ni][ni - 1] || A[nh][ni][ni + 1]) {
					continue;
				}
				A[nh][ni][ni + 1] = true;
//				System.out.println("rec, nh, ni " + nh + " " + ni + " " + (ni + 1));
				if (simulation()) {
//					print();
					answer = Math.min(k + 1, answer);
				}
				rec(nh, k + 1, cnt + 1);
				A[nh][ni][ni + 1] = false;

			}
		}
	}

	static void run() {
		if (simulation()) {
			answer = 0;
			return;
		}
		rec(1, 0, 0);
	}

	public static void main(String[] args) throws Exception {
		BufferedReader br;
		br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		H = Integer.parseInt(st.nextToken());
		for (int i = 0; i < M; i++) {
			st = new StringTokenizer(br.readLine());
			int h = Integer.parseInt(st.nextToken());
			int a = Integer.parseInt(st.nextToken());
			A[h][a][a + 1] = A[h][a + 1][a] = true;
		}
//		print();
		run();

		answer = answer == 4 ? -1 : answer;
		System.out.println(answer);
	}
}

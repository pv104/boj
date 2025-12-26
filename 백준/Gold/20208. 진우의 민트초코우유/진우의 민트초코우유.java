import java.io.*;
import java.util.*;

public class Main {

	static class Pair {
		int r, c;

		Pair() {
		}

		Pair(int r1, int c1) {
			r = r1;
			c = c1;
		}
	}

	public static final int N_SIZE = 12, INF = 987654321;
	public static final int[] dr = { -1, 0, 1, 0 }, dc = { 0, 1, 0, -1 };

	static int N, M, H, C, answer;
	static int[][] A = new int[N_SIZE][N_SIZE];
	static boolean[] isSelected = new boolean[N_SIZE];
	static int[] number = new int[N_SIZE];
	static Pair[] target = new Pair[N_SIZE];

	static int dist(int sr, int sc, int tr, int tc) {
		return Math.abs(sr - tr) + Math.abs(sc - tc);
	}

	static void rec(int idx, int cnt, int h) {
		if (idx == C) {
			if (h - dist(target[number[idx]].r, target[number[idx]].c, target[0].r, target[0].c) >= 0)
				answer = Math.max(answer, cnt);
			return;
		}
		if (h - dist(target[number[idx]].r, target[number[idx]].c, target[0].r, target[0].c) >= 0)
			answer = Math.max(answer, cnt);
		for (int nxt = 1; nxt <= C; nxt++) {
			if (isSelected[nxt])
				continue;
			if (h - dist(target[number[idx]].r, target[number[idx]].c, target[nxt].r, target[nxt].c) >= 0) {
				isSelected[nxt] = true;
				number[idx + 1] = nxt;
				rec(idx + 1, cnt + 1,
						h - dist(target[number[idx]].r, target[number[idx]].c, target[nxt].r, target[nxt].c) + H);
				isSelected[nxt] = false;
			}
		}
	}

	public static int solve() {
		rec(0, 0, M);
		return answer;
	}

	public static void main(String[] args) throws Exception {
		BufferedReader br;
		br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		H = Integer.parseInt(st.nextToken());
		int c = 1;
		for (int i = 0; i < N; i++) {
			st = new StringTokenizer(br.readLine());
			for (int j = 0; j < N; j++) {
				int v = Integer.parseInt(st.nextToken());
				A[i][j] = v;
				if (v == 1) {
					target[0] = new Pair(i, j);
				} else if (v == 2) {
					target[c++] = new Pair(i, j);
				}
			}
		}
		C = c - 1;
		System.out.print(solve());
	}
}

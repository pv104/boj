import java.io.*;
import java.util.*;

public class Main {

	public static class Value {
		int num;
		int cnt;

		Value() {
		}

		Value(int n, int c) {
			num = n;
			cnt = c;
		}

	}

	public static final Comparator<Value> cmp = Comparator.comparingInt((Value v) -> v.cnt).thenComparing(v -> v.num);
	public static final int N_SIZE = 101;
	public static int R, C, K,maxRow,maxCol;
	public static int[][] A = new int[N_SIZE][N_SIZE];

	public static int[] findMax() {
		for (int i = 1; i < N_SIZE; i++) {
			for (int j = 1; j < N_SIZE; j++) {
				if (A[i][j] == 0) {
					maxCol = Math.max(maxCol, j-1);
					break;
				}
			}
		}
		for (int i = 1; i < N_SIZE; i++) {
			for (int j = 1; j < N_SIZE; j++) {
				if (A[j][i] == 0) {
					maxRow = Math.max(maxRow, j-1);
					break;
				}
			}
		}
		return new int[] { maxRow, maxCol };
	}

	public static void check() {
//		System.out.println("check, maxRow : " + maxRow + " maxCol : " + maxCol);
		int[] cnts = new int[N_SIZE];
		if (maxRow >= maxCol) {
			for (int i = 1; i < N_SIZE; i++) {
				PriorityQueue<Value> pq = new PriorityQueue<>(cmp);
				for (int j = 1; j < N_SIZE; j++) {
					if (A[i][j] == 0)
						continue;
					cnts[A[i][j]]++;
				}
				for (int j = 1; j < N_SIZE; j++) {
					if (cnts[j] > 0) {
						pq.add(new Value(j, cnts[j]));
						cnts[j] = 0;
					}
				}
				maxCol = Math.max(maxCol, pq.size());
				int idx = 1;
				while (idx < 100) {
					if (!pq.isEmpty()) {
						Value cur = pq.poll();
						A[i][idx++] = cur.num;
						A[i][idx++] = cur.cnt;
					} else {
						A[i][idx++] = 0;
						A[i][idx++] = 0;
					}
				}

			}
		} else {
			for (int i = 1; i < N_SIZE; i++) {
				PriorityQueue<Value> pq = new PriorityQueue<>(cmp);
				for (int j = 1; j < N_SIZE; j++) {
					if (A[j][i] == 0)
						continue;
					cnts[A[j][i]]++;
				}
				for (int j = 1; j < N_SIZE; j++) {
					if (cnts[j] > 0) {
						pq.add(new Value(j, cnts[j]));
						cnts[j] = 0;
					}
				}
				maxRow = Math.max(maxRow, pq.size());
				int idx = 1;
				while (idx < 100) {
					if (!pq.isEmpty()) {
						Value cur = pq.poll();
						A[idx++][i] = cur.num;
						A[idx++][i] = cur.cnt;
					} else {
						A[idx++][i] = 0;
						A[idx++][i] = 0;
					}
				}
			}
		}

	}

	public static int run() {
		int answer = -1;
		for (int time = 0; time <= 100; time++) {
//			System.out.println("time:" + time);
//			print();
			findMax();
			if (A[R][C] == K)
				return time;
			// 1. 값 확인하기
			check();

		}
		return answer;
	}

	public static void print() {
		for (int i = 1; i < N_SIZE; i++) {
			int cnt = 0;
			for (int j = 1; j < N_SIZE; j++) {
				if (A[i][j] != 0) {
					System.out.print("[" + i + "]" + "[" + j + "]:" + A[i][j] + " ");
					cnt++;
				}
			}
			if (cnt > 0)
				System.out.println();
		}
	}

	public static void main(String[] args) throws Exception {
		BufferedReader br;
		br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		// 1-idx
		R = Integer.parseInt(st.nextToken());
		C = Integer.parseInt(st.nextToken());
		K = Integer.parseInt(st.nextToken());
		for (int i = 1; i <= 3; i++) {
			st = new StringTokenizer(br.readLine());
			for (int j = 1; j <= 3; j++) {
				A[i][j] = Integer.parseInt(st.nextToken());
			}
		}
		System.out.println(run());
	}
}

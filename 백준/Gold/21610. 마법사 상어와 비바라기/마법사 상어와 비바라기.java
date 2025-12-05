import java.io.*;
import java.util.*;

public class Main {

	public static class Grid {
		int water, latestCloud;
		boolean hasCloud;

		Grid() {
		}

		Grid(int w, int l, boolean h) {
			water = w;
			latestCloud = l;
			hasCloud = h;
		}
	}

	public static final int N_SIZE = 52;
	public static final int[] dr = { 0, -1, -1, -1, 0, 1, 1, 1 }, dc = { -1, -1, 0, 1, 1, 1, 0, -1 };

	public static int N, M, D, S;
	public static Grid[][] A = new Grid[N_SIZE][N_SIZE];

	public static boolean inRange(int r, int c) {
		return 0 <= r && r < N && 0 <= c && c < N;
	}

	public static void print() {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				System.out.print(A[i][j].water + " ");
			}
			System.out.println();
		}
	}

	public static void move(int d, int s, int time) {
		// 원형
		Grid[][] ca = new Grid[N_SIZE][N_SIZE];
		for (int i=0; i<N; i++) {
			for (int j=0; j<N; j++) {
				ca[i][j] = new Grid(0,0,false);
			}
		}
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (A[i][j].hasCloud) {
					int nr = (i + ((dr[d] * (s % N))) + N) % N;
					int nc = (j + ((dc[d] * (s % N))) + N) % N;
					ca[nr][nc].hasCloud = true;
					ca[nr][nc].latestCloud = time;
					A[i][j].hasCloud = false;
					A[i][j].latestCloud = 0;

				}
			}
		}
		for (int i=0; i<N; i++) {
			for (int j=0; j<N; j++) {
				if(ca[i][j].hasCloud) {
					A[i][j].hasCloud = ca[i][j].hasCloud;
					A[i][j].latestCloud = ca[i][j].latestCloud;
				}
			}
		}
		return;
	}

	public static void drop() {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (A[i][j].hasCloud)
					A[i][j].water++;
			}
		}
	}

	public static void remove() {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (A[i][j].hasCloud)
					A[i][j].hasCloud = false;
			}
		}
	}

	public static void copy(int time) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (A[i][j].latestCloud == time) {
					for (int dir = 1; dir < 8; dir += 2) {
						int nr = i + dr[dir];
						int nc = j + dc[dir];
						if (inRange(nr, nc) && A[nr][nc].water > 0)
							A[i][j].water++;
					}
				}
			}
		}
	}

	public static void create(int time) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (A[i][j].water > 1 && A[i][j].latestCloud != time) {
					A[i][j].water -= 2;
					A[i][j].hasCloud = true;
					A[i][j].latestCloud = time + 1;
				}
			}
		}
	}

	public static int findSum() {
		int sum = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				sum += A[i][j].water;
			}
		}
		return sum;
	}

	public static void run(int d, int s, int time) {
		move(d, s, time);
		drop();
		remove();
		copy(time);
		create(time);
	}

	public static void main(String[] args) throws Exception {
		BufferedReader br;
		br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		for (int i = 0; i < N; i++) {
			st = new StringTokenizer(br.readLine());
			for (int j = 0; j < N; j++) {
				A[i][j] = new Grid(Integer.parseInt(st.nextToken()), 0, false);
			}
		}
		A[N - 2][0].hasCloud = A[N - 2][1].hasCloud = A[N - 1][0].hasCloud = A[N - 1][1].hasCloud = true;
		A[N - 2][0].latestCloud = A[N - 2][1].latestCloud = A[N - 1][0].latestCloud = A[N - 1][0].latestCloud = 1;
		for (int time = 1; time <= M; time++) {
			st = new StringTokenizer(br.readLine());
			D = Integer.parseInt(st.nextToken()) - 1;
			S = Integer.parseInt(st.nextToken());
			run(D, S, time);
		}
		System.out.print(findSum());
	}
}

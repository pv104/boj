import java.io.*;
import java.util.*;

public class Main {

	static final int N_SIZE = 1002, M_SIZE = 12;
	static int[] res = new int[N_SIZE];
	static int[][] A = new int[N_SIZE][M_SIZE];
	static int N;
	static boolean flag = false;
	static boolean[][] visited = new boolean[N_SIZE][M_SIZE];
	static int rec(int idx, int pre) {
//		System.out.println("rec, i p " + idx + " " + pre);
		if (idx < 0) {
			return pre;
		}
		for (int j = 1; j <= 9; j++) {
			if(!visited[idx][j] && A[idx][j] != 0 && j != pre) {
				visited[idx][j] = true;
				res[idx] = rec(idx - 1, j);
				if(res[idx] > 0) return pre;
			}
		}
		
		return -1;
	}

	public static void main(String[] args) throws Exception {
		BufferedReader br;
		br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		for (int i = 0; i < N; i++) {
			st = new StringTokenizer(br.readLine());
			int M = Integer.parseInt(st.nextToken());
			for (int j=0; j<M; j++) {
				int k = Integer.parseInt(st.nextToken());
				A[i][k] = k;
			}
		}
		rec(N-1,0);
		for (int i=0; i<N; i++) {
			if(res[i] == -1) flag = true;
		}
		if(!flag) {
			for (int i=0; i<N; i++) {
				System.out.println(res[i]);
			}
		} else {
			System.out.print("-1");
		}
	}
}

import java.io.*;
import java.util.*;

public class Main {

	static final int N_SIZE = 100002, M_SIZE = 2;
	static int[][] A = new int[N_SIZE][M_SIZE];
	static boolean[][] visited = new boolean[N_SIZE][M_SIZE];
	static int N, K;
	static ArrayDeque<int[]> q = new ArrayDeque<>();

	static int solve() {
		int answer = 0;
		q.add(new int[] { 1, 0, 1 });
		visited[1][0] = true;
		while (!q.isEmpty()) {
			int[] cur = q.poll();
			int r = cur[0];
			int c = cur[1];
			int t = cur[2];
			int nr = r + 1;
//			System.out.println("r,c,t " + r + " " + c + " " + t);
			if (nr > N || r + K > N || r - 1 > N) {
				answer = 1;
				break;
			}
			check(nr, c, t);
			nr = r - 1;
			check(nr, c, t);

			nr = r + K;
			int nc = (c == 0) ? 1 : 0;

			check(nr, nc, t);
		}
		return answer;
	}

	static boolean check(int nr, int c,int t) {
		if (nr >= 1) {
			
			if (nr <= N && !visited[nr][c] && A[nr][c] == 1 && nr > t) {
//				System.out.println("nr, c, T " + nr + " " + c + " " + t);
				visited[nr][c] = true;
				q.add(new int[] { nr, c, t+1 });
				return true;
			}
		}
		return false;
	}

	public static void main(String[] args) throws Exception {
		BufferedReader br;
		 br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		K = Integer.parseInt(st.nextToken());
		String str = br.readLine();
		for (int i = 1; i <= N; i++)
			A[i][0] = str.charAt(i - 1) - '0';
		str = br.readLine();
		for (int i = 1; i <= N; i++)
			A[i][1] = str.charAt(i - 1) - '0';
		System.out.println(solve());
	}
}

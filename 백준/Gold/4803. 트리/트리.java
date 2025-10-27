import java.io.*;
import java.util.*;

public class Main {

	static final int N_SIZE = 502;
	static int[][] A = new int[N_SIZE][N_SIZE];
	static int N,M;
	static int V,E,answer;
	static boolean[] visited = new boolean[N_SIZE];
	static HashSet<Integer> s = new HashSet<>();
	public static void dfs(int i) {
		for (int j=0; j<N; j++) {
			if(A[i][j] == 1) {
				A[i][j] = 0;
				A[j][i] = 0;
				s.add(j);
				E++;
				dfs(j);

			}

			
		}
	}
	public static void solve() {
		for (int i=0; i<N; i++) {
			for (int j=0; j<N; j++) {
				if(A[i][j] == 1) {
					s.add(i);
					dfs(i);
					if(E == s.size() - 1) answer++;
					E = 0;
					s.clear();
				}
			}
		}
	}
	public static void init() {
		for (int i=0; i<N; i++)
			for (int j=0; j<N; j++)
				A[i][j] = 0;
		E = 0;
		s = new HashSet<>();
		answer = 0;
		for (int i=0; i<N; i++)
			visited[i] = false;
	}
	public static void main(String[] args) throws Exception {
		BufferedReader br;
		br = new BufferedReader(new InputStreamReader(System.in));
		for(int tc=1; ; tc++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			N = Integer.parseInt(st.nextToken());
			M = Integer.parseInt(st.nextToken());
			V = E = 0;
			init();
			if(N == 0 && M == 0) break;
			for (int i=0; i<M; i++) {
				st = new StringTokenizer(br.readLine());
				int r = Integer.parseInt(st.nextToken()) - 1;
				int c = Integer.parseInt(st.nextToken()) - 1;
				A[r][c] = 1;
				A[c][r] = 1;
				visited[r] = visited[c] = true;
			}
			solve();
			String str;
			for (int i=0; i<N; i++) {
				if(!visited[i]) answer++;
				visited[i] = false;
			}
			if(answer == 0)
				str = "No trees.";
			else if(answer == 1)
				str = 
			"There is one tree.";
			else {
			str = "A forest of " + answer + " trees.";
			}
			System.out.println("Case "+ tc + ": " + str);
			answer = 0;
		}
	}
}

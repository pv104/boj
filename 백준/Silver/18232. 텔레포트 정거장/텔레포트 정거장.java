import java.io.*;
import java.util.*;

public class Main {

	public static final int N_SIZE = 300_002, MAX = 987_654_321;
	static int N, M, S, E;
	static int[] A = new int[N_SIZE];
	static boolean[] visited = new boolean[N_SIZE];
	static ArrayList<Integer>[] TP = new ArrayList[N_SIZE];

	static int solve() {
		int answer = MAX;
		ArrayDeque<int[]> q = new ArrayDeque<>();
		q.add(new int[] { S, 0 });
		visited[S] = true;
		while (!q.isEmpty()) {
			
			int[] cur = q.poll();
			int x = cur[0];
			int t = cur[1];
			if (x == E)
				return answer = t;

			if (x + 1 <= N) {
				if (!visited[x + 1]) {
					q.add(new int[] { x + 1, t + 1 });
					visited[x + 1] = true;
				}
			}
			if (x - 1 > 0) {
				if (!visited[x - 1]) {
					q.add(new int[] { x - 1, t + 1 });
					visited[x - 1] = true;
				}
				
			}
			
			for (int nxt : TP[x]) {
				if (!visited[nxt]) {
					q.add(new int[] { nxt, t + 1 });
					visited[nxt] = true;
				}
			}
		}
		return answer;
	}

	public static void main(String[] args) throws Exception {
		BufferedReader br;
		br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		st = new StringTokenizer(br.readLine());
		S = Integer.parseInt(st.nextToken());
		E = Integer.parseInt(st.nextToken());
		for (int i=0; i<N_SIZE; i++)
			TP[i] = new ArrayList<>();
		for (int i=0; i<M; i++) {
			st = new StringTokenizer(br.readLine());
			int x = Integer.parseInt(st.nextToken());
			int y = Integer.parseInt(st.nextToken());
			TP[x].add(y);
			TP[y].add(x);
		}
		System.out.print(solve());
	}
}

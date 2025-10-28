import java.io.*;
import java.util.*;

public class Main {
	static class Edge implements Comparable<Edge> {
		int s, e, c;

		Edge() {
		}

		Edge(int s, int e, int c) {
			this.s = s;
			this.e = e;
			this.c = c;
		}

		@Override
		public int compareTo(Edge o) {
			return c - o.c;
		}
	}

	static final int N_SIZE = 52;
	static int N, cnt = 1;
	static int[][] A = new int[N_SIZE][N_SIZE];
	static int[] P;
	static 
	PriorityQueue<Edge> pq = new PriorityQueue<>();
	static int find(int x) {
		if (P[x] != x)
			return P[x] = find(P[x]);
		return x;
	}

	static void merge(int a, int b) {

		a = find(a);
		b = find(b);
		if (a < b)
			P[b] = a;
		else
			P[a] = b;
	}

	public static int solve() {
		
		int answer = 0;
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if(i != j && A[i][j] != 0)
				pq.add(new Edge(i, j, A[i][j]));
			}
		}
		while (!pq.isEmpty()) {

			Edge cur = pq.poll();
			int s = find(cur.s);
			int e = find(cur.e);
			int c = cur.c;
			
			if (s != e) {
				cnt++;
				answer += c;
				merge(cur.s,cur.e);
			}
		}

		return answer;
	}

	public static void main(String[] args) throws Exception {
		BufferedReader br;
		br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		int total = 0;
		P = new int[N+1];
		for (int i = 1; i <= N; i++) {
			P[i] = i;
			String str = br.readLine();
			for (int j = 1; j <= N; j++) {
				char c = str.charAt(j - 1);
				if (c >= 'a' && c <= 'z') {
					A[i][j] = c - 96;

				} else if (c >= 'A' && c <= 'Z') {
					A[i][j] = c - 38;
				} else
					A[i][j] = 0;
				total += A[i][j];
			}
		}
		int answer = solve();
		
		if(cnt == N)
			System.out.print(total - answer);
		else System.out.print(-1);
	}
}

import java.io.*;
import java.util.*;

public class Main {

	static class Pair implements Comparable<Pair> {
		int idx;
		int cost;

		Pair() {
		}

		Pair(int idx, int cost) {
			this.idx = idx;
			this.cost = cost;
		}

		@Override
		public int compareTo(Pair o) {
			if (cost == o.cost)
				return idx - o.idx;
			return cost - o.cost;
		}

	}

	static final int N_SIZE = 2002, M_SIZE = 50002, T_SIZE = 102, INF = 555_555_555;
	static int N, M, T, S, G, H, TO;
	static ArrayList<Pair>[] A = new ArrayList[M_SIZE];
	static int[] To = new int[T_SIZE];
	static int[][] dist = new int[3][N_SIZE];
	static PriorityQueue<Pair> pq;

	public static void init() {
		A = new ArrayList[M_SIZE];
		for (int i = 0; i < M_SIZE; i++) {
			A[i] = new ArrayList<>();
		}
		To = new int[T_SIZE];
		pq = new PriorityQueue<>();
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < N_SIZE; j++)
				dist[i][j] = INF;
	}

	static void dijkstra(int start, int num) {
		boolean[] visited = new boolean[N_SIZE];
		dist[num][start] = 0;
		pq.add(new Pair(start, 0));
		while (!pq.isEmpty()) {
			Pair cur = pq.poll();
			if (visited[cur.idx])
				continue;
			visited[cur.idx] = true;
			for (Pair p : A[cur.idx]) {
				if (dist[num][p.idx] > dist[num][cur.idx] + p.cost) {
					dist[num][p.idx] = dist[num][cur.idx] + p.cost;
					pq.add(new Pair(p.idx, dist[num][cur.idx] + p.cost));
				}
			}
		}
	}

	public static void main(String[] args) throws Exception {
		BufferedReader br;
		br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		T = Integer.parseInt(st.nextToken());
		for (int tc = 0; tc < T; tc++) {
			init();
			st = new StringTokenizer(br.readLine());
			N = Integer.parseInt(st.nextToken());
			M = Integer.parseInt(st.nextToken());
			TO = Integer.parseInt(st.nextToken());
			st = new StringTokenizer(br.readLine());
			S = Integer.parseInt(st.nextToken());
			G = Integer.parseInt(st.nextToken());
			H = Integer.parseInt(st.nextToken());
			for (int i = 0; i < M; i++) {
				st = new StringTokenizer(br.readLine());
				int a = Integer.parseInt(st.nextToken());
				int b = Integer.parseInt(st.nextToken());
				int d = Integer.parseInt(st.nextToken());
				A[a].add(new Pair(b, d));
				A[b].add(new Pair(a, d));
			}
			for (int i = 0; i < TO; i++) {
				To[i] = Integer.parseInt(br.readLine());
			}
			Arrays.sort(To);
			dijkstra(S, 0);
			dijkstra(G, 1);
			dijkstra(H, 2);
//			for (int i=0; i<3; i++) {
//				
//				for (int j=0; j<N; j++) {
//					System.out.print(dist[i][j] + " ");
//				}
//				System.out.println();
//			}
			for (int i : To) {
				// S->i == S->G+G->H+H->i
				// S->i == S->H+H->G+G->i
				if(dist[0][i] == INF) continue;
				if(i == 0) continue;
//				System.out.println(dist[0][i] + " " + dist[0][G] + " " + dist[1][H] + " " + dist[2][i]);
//				System.out.println(dist[0][i] + " " + dist[0][H] + " " + dist[1][G] + " " +dist[2][i]);
				if ((dist[0][i] == (dist[0][G] + dist[1][H] + dist[2][i]))
						|| (dist[0][i] == (dist[0][H] + dist[2][G] + dist[1][i]))) {
						System.out.print(i+ " ");
				}
			}
		}
	}
}

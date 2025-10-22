import java.io.*;
import java.util.*;

public class Main {

	static class Pair implements Comparable<Pair> {
		int idx, cost;

		Pair() {
		}

		Pair(int idx, int cost) {
			this.idx = idx;
			this.cost = cost;
		}

		@Override
		public int compareTo(Pair o) {
			
			if(cost == o.cost)return idx - o.idx;
			else return cost - o.cost;
		}
	}
	static final int INF = 987654321;
	static int N,M;
	static int[][] dists;
	static ArrayList<ArrayList<Pair>> A;
	static int[] friends = new int[3];
	static void dijk(int idx) {
		
		int start = friends[idx];
		boolean[] visited = new boolean[N];
		dists[idx][start] = 0;
		PriorityQueue<Pair> pq = new PriorityQueue<>();
		pq.add(new Pair(start,0));
		while(!pq.isEmpty()) {
			Pair cur = pq.poll();
			if(visited[cur.idx]) continue;
			visited[cur.idx]= true; 
//			System.out.println(" start : " + start + " cur : " + cur.idx + " " + cur.cost);
			for(Pair p : A.get(cur.idx)) {
				if(dists[idx][p.idx] > dists[idx][cur.idx] + p.cost) {
					
					dists[idx][p.idx] = dists[idx][cur.idx]+p.cost;
					pq.add(new Pair(p.idx, dists[idx][p.idx]));
				}
			}
		}
	}
	static int solve() {
		int ans = INF,cost=-1;
		for (int i=0; i<3; i++) {
			dijk(i);
//			System.out.println(" 친구 " + i + " (번호 " + friends[i] + ") 의 최단 거리 리스트") ;
//			for (int j=0; j<N; j++) {
//				System.out.print(j + " " + dists[i][j] + " ");
//			}
//			System.out.println();
		}
		for (int i=0; i<N; i++) {
			int t = INF;
			for (int j=0; j<3; j++) {
				if(j == friends[j]) continue;
				t = Math.min(t, dists[j][i]); // 친구 0(A) / 1(B) / 2(C)
			}
			if(t == cost) {
				ans = Math.min(ans, i);
			}
			else if(t != INF && t > cost) {
				cost = t;
				ans = i;
			}
		}
		return ans + 1;
	}
	
	public static void main(String[] args) throws Exception {
		BufferedReader br;
		br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		A = new ArrayList<>(N);
		for (int i=0; i<N; i++) {
			A.add(new ArrayList<>());
		}
		st = new StringTokenizer(br.readLine());
		for (int i=0; i<3; i++) {
			friends[i] = Integer.parseInt(st.nextToken()) - 1;
		}
		dists = new int[3][N];
		for (int i=0; i<3; i++) {
			for (int j=0; j<N; j++) {
				dists[i][j] = INF;
			}
		}
		M = Integer.parseInt(br.readLine());
		for (int i=0; i<M; i++) {
			// s,e,c
			st = new StringTokenizer(br.readLine());
			int start = Integer.parseInt(st.nextToken()) - 1;
			int end = Integer.parseInt(st.nextToken()) - 1;
			int cost = Integer.parseInt(st.nextToken());
			A.get(start).add(new Pair(end,cost));
			A.get(end).add(new Pair(start,cost));
		}
		System.out.print(solve());
	}
}

import java.io.*;
import java.util.*;

public class Main {

	static class Cable implements Comparable<Cable>{
		int r,c,w;
		Cable(int rr,int cc,int ww) {
			r = rr;
			c = cc;
			w = ww;
		}
	@Override
	public int compareTo(Cable cable) {
			if(this.w != cable.w) return this.w - cable.w;
			if(this.r != cable.r) return this.r - cable.r;
			return this.c - cable.c;
		}
	}
	static final int SIZE = 1002;
	static int N,M,K;
	static int[] parent = new int[SIZE];
	static boolean[] P = new boolean[SIZE];
	static PriorityQueue<Cable> A = new PriorityQueue<>();
	
	static int find(int x) {
		if(x == parent[x]) return x;
		return parent[x] = find(parent[x]);
	}
	static boolean merge(int a,int b) {
		int x = find(a);
		int y = find(b);
		if(parent[x] == parent[y]) return false;
		parent[y] = x;
	    P[x] = P[x] || P[y];
		return true;
	}
	static int solve() {
		int ans=0,cnt=K;
		while(!A.isEmpty()) {
			if(cnt == N) break;
			Cable cur = A.poll();
			int x = find(cur.r);
			int y = find(cur.c);
			if(P[x] && P[y]) continue;
			if(!merge(cur.r,cur.c)) continue;
			cnt++;
			ans += cur.w;
			}
		return ans;
	}
	public static void main(String[] args) throws Exception {
		BufferedReader br;
		br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		K = Integer.parseInt(st.nextToken());
		st = new StringTokenizer(br.readLine());
		for (int i=0; i<K; i++) {
			P[Integer.parseInt(st.nextToken())-1] = true;
		}
		for (int i=0; i<N; i++) {
			parent[i] = i;
		}
		for (int i=0; i<M; i++) {
		st = new StringTokenizer(br.readLine());
		int u = Integer.parseInt(st.nextToken()) -1;
		int v = Integer.parseInt(st.nextToken()) -1;
		int w = Integer.parseInt(st.nextToken());
		A.add(new Cable(u,v,w));
		}
		System.out.print(solve());
	}
}

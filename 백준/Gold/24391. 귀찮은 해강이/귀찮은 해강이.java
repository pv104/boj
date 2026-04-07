import java.io.*;
import java.util.*;

public class Main {

	static int N,M;
	static ArrayList<Integer>[] A;
	static int[] P;
	static int find(int x) {
		if(P[x] == x) return x;
		return P[x] = find(P[x]);
	}
	static void merge(int a, int b) {
		int x = find(a);
		int y = find(b);
		if(x == y) return;
		P[y] = x;
	}
	
	public static void main(String[] args) throws Exception {
		BufferedReader br;
		br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		A = new ArrayList[N+1];
		P = new int[N+1];
		for (int i=1; i<=N; i++) {
			A[i] = new ArrayList<>();
			P[i] = i;
		}
		for (int i=0; i<M; i++) {
			st = new StringTokenizer(br.readLine());
			int x = Integer.parseInt(st.nextToken());
			int y = Integer.parseInt(st.nextToken());
			merge(x,y);
		}

		st = new StringTokenizer(br.readLine());
		int v1=Integer.parseInt(st.nextToken()),v2=0;
		int ans=0;
		for (int i=0; i<N-1; i++) {
			v2 = Integer.parseInt(st.nextToken());
			if(find(v1) != find(v2)) ans++;
			v1 = v2;
		}
		System.out.print(ans);
	}
}

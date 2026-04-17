import java.io.*;
import java.util.*;

public class Main {

	static final int SIZE = 4040;
	static int N,T,idx;
	static int[] I,P;
	static StringBuilder sb;
	static void f(int l,int r) {
		if(idx == N) return;
		if(l > r) return;
		int root = P[idx++];
		f(l,I[root]-1);
		f(I[root]+1,r);
		if(sb.length() > 0)
			sb.append(' ');
			sb.append(root);
	}
	static void solve() {
		int l=0,r=N-1;
		f(l,r);
		System.out.println(sb.toString());
	}
	static void init() {
		idx = 0;
		sb = new StringBuilder();
		P = new int[SIZE];
		I = new int[SIZE];
	}
	public static void main(String[] args) throws Exception {
		BufferedReader br;
		br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		T = Integer.parseInt(st.nextToken());
		for (int i=0; i<T; i++) {
			init();
			st = new StringTokenizer(br.readLine());
			N = Integer.parseInt(st.nextToken());
			st = new StringTokenizer(br.readLine());
			for (int j=0; j<N; j++) {
				P[j] = Integer.parseInt(st.nextToken());
			}
			st = new StringTokenizer(br.readLine());
			for (int j=0; j<N; j++) {
				I[Integer.parseInt(st.nextToken())] = j;
			}
			solve();
			
		}
	}
}

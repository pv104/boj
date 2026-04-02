import java.io.*;
import java.util.*;

public class Main {

	public static int N;
	public static final int INF = -1001;
	static int[] a;
	public static int solve() {
		int ans=0;
		int l=0,r=N-1;
		int lv=INF,rv=INF;
		while(l <= r) {
			if(a[l] <= 0) {
				if(lv == INF) {
					lv = a[l];
				}
				else {
					ans += Math.max(lv+a[l], lv*a[l]);
					lv = INF;
				}l++;
			}
			if(a[r] > 0) {
				if(rv == INF) {
					rv = a[r];
				} else {
					ans += Math.max(rv+a[r], rv*a[r]);
					rv = INF;
					
				}
				r--;
			}
		}
		if(lv != INF) {
			ans += lv;
		}
		if(rv != INF) {
			ans += rv;
		}
		return ans;
	}
	public static void main(String[] args) throws Exception {
		BufferedReader br;
		br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		a = new int[N];
		for (int i=0; i<N; i++) {
			a[i] = Integer.parseInt(br.readLine());
		}
		Arrays.sort(a);
		System.out.print(solve());
	}
}

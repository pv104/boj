import java.io.*;
import java.util.*;

public class Main {


	public static int N,M;
	static int[] a;
	public static int solve() {
		int ans=Integer.MAX_VALUE;
		int l=0,r=0;
		while(l != N && r != N) {
			int x = a[l];
			int y = a[r];
			if(y - x < M) r++;
			else {
				ans = Math.min(ans,y-x);
				l++;
			}
		}
		return ans;
	}
	public static void main(String[] args) throws Exception {
		BufferedReader br;
		br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		a = new int[N];
		for (int i=0; i<N; i++) {
			a[i] = Integer.parseInt(br.readLine());
		}
		Arrays.sort(a);
		System.out.print(solve());
	}
}

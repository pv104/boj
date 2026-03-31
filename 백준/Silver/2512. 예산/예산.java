import java.io.*;
import java.util.*;

public class Main {

	public static int N,M;
	public static int[] a;
	public static boolean chk(int d) {
		int sum=0;
		for (int i=0; i<N; i++) {
			if(a[i] < d) sum+= a[i];
			else sum+= d;
		}
		return sum <= M;
	}
	public static int solve() {
		int lo=1, hi=a[N-1];
		while(lo <= hi) {
			int mid=(lo+hi)/2;
			if(chk(mid)) lo=mid+1;
			else hi=mid-1;
		}
		return hi;
	}
	public static void main(String[] args) throws Exception {
		BufferedReader br;
		br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		a = new int[N];
		st = new StringTokenizer(br.readLine());
		for (int i=0; i<N; i++) {
			a[i] = Integer.parseInt(st.nextToken());
		}
		st = new StringTokenizer(br.readLine());
		M = Integer.parseInt(st.nextToken());
		Arrays.sort(a);
		System.out.print(solve());
	}
}

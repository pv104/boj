import java.io.*;
import java.util.*;

public class Main {

	public static int N,C;
	public static int[] a;
	public static boolean chk(int d) {
		int cnt=1,cur=a[0];
		for (int i=1; i<N; i++) {
			if(a[i] - cur >= d) {
				cnt++;
				cur = a[i];
			}
		}
		return cnt >= C;
	}
	public static int solve() {
		int lo=1, hi = a[N-1] - a[0];
		while(lo <= hi) {
			int mid = (lo + hi) / 2;
			if(chk(mid)) {
				lo = mid + 1;
			}
			else hi = mid - 1;
		}
		return hi;
	}
	public static void main(String[] args) throws Exception {
		BufferedReader br;
		br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		C = Integer.parseInt(st.nextToken());
		a = new int[N];
		for (int i=0; i<N; i++) {
			st = new StringTokenizer(br.readLine());
			a[i] = Integer.parseInt(st.nextToken());
		}
		Arrays.sort(a);
		System.out.print(solve());
	}
}

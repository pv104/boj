import java.io.*;
import java.util.*;

public class Main {

	public static long N,K;
	public static long[] A;
	public static boolean chk(long d) {
		long cnt=0;
		for (int i=1; i<=N; i++) {
			if(i * N < d) {
				cnt += N;
			} else {
				cnt += d / i;
			}
		}
//		System.out.println(" cnt, d " + cnt +  " " + d);
		return cnt>=K;
	}
	public static long solve() {
		
		long lo=1, hi=N*N;
		while(lo <= hi) {
			long mid = (lo+hi)/2;
			if(chk(mid)) {
//				System.out.println(" lo, hi, mid " + lo + " " + hi + " " + mid);
				hi = mid-1;
			}
			else
			lo = mid+1;
		}
		return lo;
	}
	public static void main(String[] args) throws Exception {
		BufferedReader br;
		br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		st = new StringTokenizer(br.readLine());
		K = Integer.parseInt(st.nextToken());
		System.out.print(solve());
	}
}

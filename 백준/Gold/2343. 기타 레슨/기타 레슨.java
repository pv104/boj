import java.io.*;
import java.util.*;

public class Main {

	public static int N,M;
	public static int[] arr;
	public static boolean chk(int d) { 
		int cur=0,cnt=1;
		for (int i=0; i<N; i++) {
			if(cur + arr[i] <= d) {
				cur += arr[i];
			}
			else {
				cur = arr[i];
				cnt++;
			}
		} 
//		System.out.println(" d , cnt " + d + " " + cnt + " cur " + cur);
		return cnt <= M;
	}
	public static int solve() {
		int ans=Integer.MAX_VALUE;
		int maxV=0,sum=0;
		for (int i=0; i<N; i++) {
			maxV = Math.max(maxV, arr[i]);
			sum += arr[i];
		}
		int lo=maxV, hi=sum;
		while(lo <= hi) {
			int mid = (lo+hi)/2;
//			System.out.println("l, h, m" + lo + " " + hi + " " + mid);
			if(chk(mid)) {
				hi = mid - 1;
			}
			else lo = mid + 1;
		}
		return lo;
	}
	public static void main(String[] args) throws Exception {
		BufferedReader br;
		br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		st = new StringTokenizer(br.readLine());
		arr = new int[N];
		for (int i=0; i<N; i++) {
			arr[i] = Integer.parseInt(st.nextToken());
		}
		System.out.print(solve());
	}
}

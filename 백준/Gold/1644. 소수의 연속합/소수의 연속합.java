import java.io.*;
import java.util.*;

public class Main {


	public static int N;
	static int[] a;
	public static void getPrimeNum(int k) {
		boolean[] isNotPrime = new boolean[k+1];
		isNotPrime[0] = isNotPrime[1] = true;
	    for (int i = 2; i*i <= k; i++) { 
	        if(isNotPrime[i]) {
	           continue;
	        }
	        for (int j = i * i; j <= k; j += i) { 
	            isNotPrime[j] = true;
	        }
	    }
		int idx=0;
		for (int i=2; i<=k; i++) {
			if(!isNotPrime[i]) a[idx++] = i;
		}
	}
	public static int solve() {
		int ans=0;
		int sum=0;
		int l=0,r=0;
		getPrimeNum(N);
		while(l <= r) {
			if(a[r] == 0) break;
			if(sum+a[r] <= N) {
				sum += a[r++];
			}
			else {
				sum -= a[l++];
			}
			if(sum == N) ans++;
		}
		return ans;
	}
	public static void main(String[] args) throws Exception {
		BufferedReader br;
		br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		a = new int[N+1];
		System.out.print(solve());
	}
}

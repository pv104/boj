import java.io.*;
import java.util.*;

public class Main {
	static int N;
	static int[] A;
	static int find(int idx) {
		int l=0,r=N-1;
		while(l < r) {
			if(A[l] + A[r] > A[idx]) {
				r--;
			} else if(A[l] + A[r] < A[idx]) {
				l++;
			}
			else {
				if(l != idx && r != idx)
				return 1;
				if(l == idx) l++;
				else if(r == idx) r--;
				
			}
		}
		
		return 0;
	}
	static int solve() {
		int ans=0;
		for (int i=0; i<N; i++) {
			ans+=find(i);
		}
		return ans;
	}
	public static void main(String[] args) throws Exception {
		BufferedReader br;
		br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		A = new int[N];
		st = new StringTokenizer(br.readLine());
		for (int i=0; i<N; i++) {
			A[i] = Integer.parseInt(st.nextToken());
		}
		Arrays.sort(A);
		System.out.print(solve());
	}
}

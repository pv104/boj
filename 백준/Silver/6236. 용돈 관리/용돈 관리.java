import java.io.*;
import java.util.*;

public class Main {

	static int N,M,answer;
	static int SIZE = 100_002;
	static int[] A = new int[SIZE];
	public static boolean cal(int mid) {
		int cnt=1,k=mid;
		int r = k;
		for (int i=0; i<N; i++) {
			if(A[i] > k) return false;
			if(r < A[i]) {
				cnt++;
				r = k;
			}
			r -= A[i];
		}
		return cnt <= M;
	}
	public static int bs(int l,int h) {
		if(l == h) return l;
		int mid = (l+h)/2;
		
		if(cal(mid)) {
			return bs(l,mid);
		} else {
			return bs(mid+1,h);
		}
	}
	public static void main(String[] args) throws Exception {
		BufferedReader br;
		br = new BufferedReader(new InputStreamReader(System.in));
//		br = new BufferedReader(new FileReader("input.txt"));
		StringTokenizer st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		int sumA = 0;
		int maxA = 0;
		for (int i=0; i<N; i++) {
			A[i] = Integer.parseInt(br.readLine());
			sumA += A[i];
			maxA = Math.max(maxA, A[i]);
		}
		answer = bs(maxA,sumA);
		System.out.print(answer);
	}
}

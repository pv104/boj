import java.io.*;
import java.util.*;

public class Main {

	public static final int N_SIZE = 1002;
	static int N;
	static int[] A = new int[N_SIZE],dp = new int[N_SIZE];
	static int solve() {
		for (int i=0; i<N; i++) {
			for (int j=0; j<=i; j++) {
				if(A[j] < A[i]) {
					dp[i] = Math.max(dp[j]+1, dp[i]);
				}
				else {
					dp[i] = Math.max(dp[i], 1);
				}
			}
		}
		int answer  = -1;
		for (int i=0; i<N; i++) {
			answer = Math.max(answer, dp[i]);
		}
		return answer;
	}
	public static void main(String[] args) throws Exception {
		BufferedReader br;
		br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		st = new StringTokenizer(br.readLine());
		for (int i=0; i<N; i++) {
			A[i] = Integer.parseInt(st.nextToken());
		}
		System.out.print(solve());
	}
}

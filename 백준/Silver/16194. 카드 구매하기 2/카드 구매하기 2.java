import java.io.*;
import java.util.*;

public class Main {

	static final int SIZE = 1002;
	static int N;
	static int[] P = new int[SIZE], dp = new int[SIZE];
	
	public static void main(String[] args) throws Exception {
		BufferedReader br;
		br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		st = new StringTokenizer(br.readLine());
		for (int i=1; i<=N; i++) {
			P[i] = Integer.parseInt(st.nextToken());
		}
		Arrays.fill(dp, Integer.MAX_VALUE);
		dp[0] = 0;
		for (int i=1; i<=N; i++) {
			for (int j=1; j<=i; j++) {
				dp[i] = Math.min(dp[i], P[j]+dp[i-j]);
			}
		}
		System.out.println(dp[N]);
	}
}

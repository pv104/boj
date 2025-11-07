import java.io.*;
import java.util.*;

public class Main {

	static final int SIZE=5002,MOD = 1_000_000_000;
	static int N,K;
	static long[][] dp = new long[SIZE][SIZE];
	public static void main(String[] args) throws Exception {
		BufferedReader br;
		br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		K = Integer.parseInt(st.nextToken());
		for (int i=0; i<=K; i++) {
			dp[0][i] = 1;
		}
		for (int i=1; i<=N; i++) {
			dp[i][1] = 1l;
			for (int j=2; j<=K; j++) {
				dp[i][j] = (dp[i-1][j]+dp[i][j-1]) % MOD;
			}
		}
		System.out.print(dp[N][K]);
	}
}

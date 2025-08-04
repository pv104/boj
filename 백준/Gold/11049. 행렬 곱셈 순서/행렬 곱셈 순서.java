import java.io.*;
import java.util.*;

public class Main {

	static final int SIZE = 502, INF = 987654321;
	static long N, R, C;
	static long[] A = new long[SIZE];
	static long[][] dp = new long[SIZE][SIZE];

	static long rec(int l, int r) {
		if (l == r)
			return 0;
		if (dp[l][r] != -1)
			return dp[l][r];
		dp[l][r] = INF;
		for (int k=l; k<r; k++) {
			long left = rec(l,k);
			long right = rec(k+1,r);
			long sum = A[l]*A[k + 1]*A[r + 1];
			dp[l][r] = Math.min(dp[l][r], left+right+sum);
		}
		return dp[l][r];

	}

	public static void main(String[] args) throws Exception {
		BufferedReader br;
		br = new BufferedReader(new InputStreamReader(System.in));
//		br = new BufferedReader(new FileReader("input.txt"));
		StringTokenizer st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		for (int i = 0; i < N; i++) {
			st = new StringTokenizer(br.readLine());
			A[i] = Integer.parseInt(st.nextToken());
			A[i + 1] = Integer.parseInt(st.nextToken());

		}
		for (int i = 0; i <= N; i++)
			for (int j = 0; j <= N; j++)
				dp[i][j] = -1;

		long answer = rec(0, (int)N-1);
		System.out.print(answer);
	}
}

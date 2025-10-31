import java.io.*;
import java.util.*;

public class Main {

	public static final int[] maxN = new int[] { -1, -1, 1, 7 };
	public static final int[] values = new int[] { 1, 7, 4, 2, 0, 8 };
	public static final int N_SIZE = 102;
	static final long INF = 987_654_321_987_654L;
	public static int N, T;
	static StringBuilder sb = new StringBuilder();

	static long[] dp = new long[N_SIZE];

	static void findMax() {
		int n = N;
		if (n % 2 != 0) {
			sb.append(maxN[3]);
			n -= 3;
		}
		while (n > 0) {
			sb.append(maxN[2]);
			n -= 2;
		}
		sb.append("\n");
	}

	static void init() {
        for (int i=0; i<N_SIZE; i++)
			dp[i] = INF;
		dp[2] = 1;
		dp[3] = 7;
		dp[4] = 4;
		dp[5] = 2;
		dp[6] = 6;
		dp[7] = 8;
		dp[8] = 10;
	}

	public static void main(String[] args) throws Exception {
		BufferedReader br;
		br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		T = Integer.parseInt(st.nextToken());
		init();
		for (int tc = 0; tc < T; tc++) {
			N = Integer.parseInt(br.readLine());
			for (int k = 9; k <= N; k++)
				for (int i = 2; i <= 7; i++)
					dp[k] = Math.min(Long.parseLong(String.valueOf(dp[k - i]) + String.valueOf(values[i - 2])), dp[k]);

			sb.append(dp[N]).append(" ");
			findMax();
		}
		System.out.print(sb.toString());
	}
}

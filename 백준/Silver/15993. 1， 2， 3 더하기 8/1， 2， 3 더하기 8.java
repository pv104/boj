import java.io.*;
import java.util.*;

public class Main {

	public static class C {
		long v, e, o;
	}

	static int SIZE = 100002;
	static long MAX = 1_000_000_009;
	public static C[] dp = new C[SIZE];

	public static void solve(int N) {
		if(dp[N] != null) 
			return;
			for (int i = 0; i <= N; i++) {
				dp[i] = new C();
				for (int j = 1; j <= 3; j++) {
					if (j > i)
						break;
					if (i - j == 0) {
						dp[i].v += dp[0].v + 1;
						dp[i].o += dp[0].o + 1;
					} else {
						dp[i].v += dp[i - j].v;
						dp[i].o += dp[i - j].e;
						dp[i].e += dp[i - j].o;

					}

					dp[i].v %= MAX;
					dp[i].o %= MAX;
					dp[i].e %= MAX;
				}
			}
	}
	public static void main(String[] args) throws Exception {
		BufferedReader br;
		br = new BufferedReader(new InputStreamReader(System.in));
//		br = new BufferedReader(new FileReader("input.txt"));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int T, N;
		T = Integer.parseInt(st.nextToken());

		for (int tc = 0; tc < T; tc++) {
			N = Integer.parseInt(br.readLine());
			solve(N);
			System.out.println(dp[N].o + " " + dp[N].e);
		}
	}
}

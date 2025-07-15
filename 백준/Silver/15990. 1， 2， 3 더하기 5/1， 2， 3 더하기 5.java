import java.io.*;
import java.util.*;

public class Main {

	static final int SIZE = 100_002,MIN = -1,MOD = 1_000_000_009;
	static int[][] dp = new int[SIZE][4];
	static int N,T;
	public static void main(String[] args) throws Exception {
		BufferedReader br;
		br = new BufferedReader(new InputStreamReader(System.in));
//		br = new BufferedReader(new FileReader("input.txt"));
		StringTokenizer st = new StringTokenizer(br.readLine());
		T = Integer.parseInt(st.nextToken());
		for (int i=0; i<SIZE; i++)
			Arrays.fill(dp[i], 0);

		dp[0][0] = 0;
		dp[1][1] = dp[2][2] = dp[3][3] = 1;
		for (int TC=0; TC<T; TC++) {
			
			N = Integer.parseInt(br.readLine());
			
			for (int i=1; i<=N; i++) {
				for (int j=1; j<=3; j++) {
					if(dp[i][j] != 0)
						break;
					if(j == 1) {
						if(i-1 < 1) continue;
						dp[i][j] += dp[i-1][2];
						dp[i][j] += dp[i-1][3];
					} else if(j == 2) {
						if(i-2 < 1) continue;
						dp[i][j] += dp[i-2][1];
						dp[i][j] += dp[i-2][3];
					} else if(j == 3) {
						if(i-3 < 1) continue;
						dp[i][j] += dp[i-3][1];
						dp[i][j] += dp[i-3][2];
					}
					dp[i][j] %= MOD;
				}
			}
			int res=0;
			for (int i=1; i<=3; i++) {
				if(dp[N][i] != MIN) {
					res += dp[N][i];
					res %= MOD;
				}
			}
			System.out.println(res);
		}
		
		
	}
}

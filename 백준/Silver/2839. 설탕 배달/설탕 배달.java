import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringBuilder sb = new StringBuilder();
	static StringTokenizer st;
	static final int INF = 987654321;
	static final int RES = -1;
	static int dp[],n;
	public static void main(String[] args) throws NumberFormatException, IOException {
		n = Integer.parseInt(br.readLine());
		dp = new int[n+10];
		Arrays.fill(dp, INF);
		dp[3] = dp[5] = 1;
		dp[6] = 2;
		for(int i=8; i<=n; i++) {
			dp[i] = Math.min(dp[i-3]+1, dp[i-5]+1);
		}
		if(dp[n] == INF) dp[n] = RES;
		
		System.out.print(dp[n]);
	}
}
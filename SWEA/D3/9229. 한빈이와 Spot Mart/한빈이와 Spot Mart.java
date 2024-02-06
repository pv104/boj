import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Solution {
	final int MAX = 1003;
	static int dp[][];
	static int snack[];
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	static StringBuilder sb = new StringBuilder();
	static int solve() throws IOException {
		st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken());
		int m = Integer.parseInt(st.nextToken());
		snack = new int[n+1];
		dp = new int[n+1][n+1];
		st = new StringTokenizer(br.readLine());
		for (int i = 1; i <= n; i++)
			snack[i] = Integer.parseInt(st.nextToken());
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (i == j) continue;
				dp[i][j] = snack[i] + snack[j];
				if (dp[i][j] > m) dp[i][j] = -1;
				
			}
		}
		int res = -1;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
				res = Math.max(res, dp[i][j]);
			}
		if(res == 0) res = -1;
		return res;
	}
	public static void main(String[] args) throws NumberFormatException, IOException {
		int t;
		t = Integer.parseInt(br.readLine());
		for (int tc = 1; tc <= t; tc++) {
			sb.append("#").append(tc).append(" ").append(solve()).append("\n");
	}
		System.out.println(sb);
		}
	}
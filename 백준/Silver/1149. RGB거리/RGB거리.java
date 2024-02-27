import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {

	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	static StringBuilder sb = new StringBuilder();
	static int dp[][];
	static int n;
	static final int R = 0;
	static final int G = 1;
	static final int B = 2;
	static int house[][];
	static void input() throws Exception {
		n = Integer.parseInt(br.readLine());
		dp = new int[n+1][3];
		house = new int[n+1][3];
		dp[1][R] = house[1][R];
		dp[1][G] = house[1][G];
		dp[1][B] = house[1][B];
		for (int i = 1; i < dp.length; i++) {
			st = new StringTokenizer(br.readLine());
			house[i][R] = Integer.parseInt(st.nextToken());
			house[i][G] = Integer.parseInt(st.nextToken());
			house[i][B] = Integer.parseInt(st.nextToken());
		}
		
	}
	
	static int solve() {
		
		for (int i = 1; i < dp.length; i++) {
			dp[i][R] = Math.min(dp[i-1][G]+house[i][R], dp[i-1][B]+house[i][R]);
			dp[i][G] = Math.min(dp[i-1][R]+house[i][G], dp[i-1][B]+house[i][G]);
			dp[i][B] = Math.min(dp[i-1][R]+house[i][B], dp[i-1][G]+house[i][B]);
		}
		return Math.min(dp[n][R], Math.min(dp[n][G],dp[n][B]));
	}

	public static void main(String[] args) throws Exception {
			input();
			solve();
			System.out.print(solve());
	}
}
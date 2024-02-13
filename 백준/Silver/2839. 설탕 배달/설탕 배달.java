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
	static int f(int c) {
		if(c < 3 || c == 4 || c == 7) return INF;
		if(c == 3 || c == 5) return 1;
		if(dp[c] != INF) return dp[c];
		return dp[c] = Math.min(f(c-3)+1,f(c-5)+1);
	}
	public static void main(String[] args) throws NumberFormatException, IOException {
		n = Integer.parseInt(br.readLine());
		dp = new int[n+1];
		Arrays.fill(dp, INF);
		dp[n] = f(n);
		if(dp[n] == INF) dp[n] = -1;
		
		System.out.print(dp[n]);
	}
}
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	static StringBuilder sb = new StringBuilder();
	static int n,k;
	static final int INF = 987654321;
	static int dp[],coin[];
	static void input() throws Exception {
		st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		k = Integer.parseInt(st.nextToken());
		dp = new int[k+1];
		coin = new int[n];
		for (int i = 0; i < n; i++) {
			coin[i] = Integer.parseInt(br.readLine());
		}
		for (int i = 1; i <= k; i++) {
			dp[i] = INF;
		}
		Arrays.sort(coin);
		
	}
	static int solve() throws Exception {
		int res=0;
		
		for (int i = 1; i <= k; i++) { // 원
			for (int j = 0, index = 0; j < n; j++) { // 코인
				if(coin[j] <= i) { // 인덱스에 넣을 수 있는 경우
					index = i - coin[j];
					dp[i] = Math.min(dp[i], dp[index]+1);
				}
			}
		}
		if(dp[k] == INF) res = -1;
		else res = dp[k];
		return res;
		
	}
	public static void main(String[] args) throws Exception {
		input();
		System.out.println(solve());
	}
}
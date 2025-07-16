import java.io.*;
import java.util.*;

public class Main {
	static int[] dp = new int[100_002];
	public static void main(String[] args) throws Exception {
		BufferedReader br;
		br = new BufferedReader(new InputStreamReader(System.in));
//		br = new BufferedReader(new FileReader("input.txt"));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int N = Integer.parseInt(st.nextToken());
		Arrays.fill(dp, 987654321);
		dp[1] = 1;
		
		for (int i=2; i<=N; i++) {
			int sN = (int)Math.sqrt(i);
			if(sN * sN == i) {
				dp[i] = 1; continue;
			}
			for (int k=1; k<=sN; k++) {
				dp[i] = Math.min(dp[i], dp[i-k*k]+1);
			}
		}
		System.out.println(dp[N]);
	}
}

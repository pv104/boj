import java.io.*;
import java.util.*;

public class Main {

	static final int N_SIZE = 102, M_SIZE = 22, F = 0, S = 1;
	static String M, A, D;
	static int[][][] dp = new int[N_SIZE][M_SIZE][2]; // idx,m,flag

	static int rec(int idx, int m, int flag) {
		if (dp[idx][m][flag] != -1)
			return dp[idx][m][flag];
		if (m == M.length()) {
			return 1;
		}
		dp[idx][m][flag] = 0;
		if (flag == 0) { // 'A'
			if (idx >= A.length())
				return 0;
			for (int nxt = idx; nxt < A.length(); nxt++) {
				if (A.charAt(nxt) == M.charAt(m)) {
					dp[idx][m][flag] += rec(nxt + 1, m + 1, 1);
				}
			}
		} else {
			if (idx >= D.length())
				return 0;
			for (int nxt = idx; nxt < D.length(); nxt++) {
				if (D.charAt(nxt) == M.charAt(m)) {
					dp[idx][m][flag] += rec(nxt + 1, m + 1, 0);
				}
			}
		}
		return dp[idx][m][flag];
	}

	public static void main(String[] args) throws Exception {
		BufferedReader br;
		br = new BufferedReader(new InputStreamReader(System.in));
//		StringTokenizer st = new StringTokenizer(br.readLine());
		for (int i = 0; i < N_SIZE; i++)
			for (int k = 0; k < M_SIZE; k++)
				for (int l = 0; l < 2; l++)
					dp[i][k][l] = -1;
		M = br.readLine();
		D = br.readLine();
		A = br.readLine();
		int answer = rec(0, 0, 1);
		answer += rec(0, 0, 0);
		System.out.print(answer);
	}
}

import java.io.*;
import java.util.*;

public class Main {

	static int SIZE = 32;
	static int N;
	static long [][][] dp = new long [SIZE << 1][SIZE][SIZE];
	public static long rec(int day,int p,int hp) {
		if(day == 0) {
			return 1;
		}
		if(dp[day][p][hp] != -1) return dp[day][p][hp];
		dp[day][p][hp] = 0;

		if(p < N) {
			dp[day][p][hp] += rec(day-1,p+1,hp);
		}
		if(p > hp && hp < N) {
			dp[day][p][hp] += rec(day-1,p,hp+1);
		}
		return dp[day][p][hp];
	}
	public static void main(String[] args) throws Exception {
		BufferedReader br;
		br = new BufferedReader(new InputStreamReader(System.in));
//		br = new BufferedReader(new FileReader("input.txt"));
		StringTokenizer st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		for (int i=0; i<SIZE << 1; i++)
			for (int j=0; j<SIZE; j++)
				for (int k=0; k<SIZE; k++)
					dp[i][j][k] = -1;
		StringBuilder sb = new StringBuilder();
		while(N != 0) {
			sb.append(rec(N << 1,0,0)).append("\n");
			N = Integer.parseInt(br.readLine());
		}
		System.out.print(sb.toString());
	}
}

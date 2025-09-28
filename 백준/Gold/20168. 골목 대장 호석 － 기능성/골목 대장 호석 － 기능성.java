import java.io.*;
import java.util.*;

public class Main {

	
	static final int N_SIZE = 12;
	static int N, M, S, E, R, answer = Integer.MAX_VALUE;
	static boolean[] isSelected = new boolean[N_SIZE];
	static int[][] A = new int[N_SIZE][N_SIZE];
	
	static void pmt(int cur, int remain, int ans) {
//		System.out.println("[pmt] " + cur + " " + remain + " " + ans);
		if(cur == E) {
			answer = Math.min(ans, answer); return;
		}
		
		for (int i=1; i<=N; i++) {
			if(!isSelected[i] && A[cur][i] != 0 && (remain - A[cur][i] >= 0)) {
				isSelected[i] = true;
				pmt(i,remain - A[cur][i],Math.max(ans,A[cur][i]));
				isSelected[i] = false;
			}
		}
	}
	public static void main(String[] args) throws Exception {
		BufferedReader br;
		br = new BufferedReader(new InputStreamReader(System.in));
//		br = new BufferedReader(new FileReader("input.txt"));
		StringTokenizer st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		S = Integer.parseInt(st.nextToken());
		E = Integer.parseInt(st.nextToken());
		R = Integer.parseInt(st.nextToken());
		for (int i=0; i<M; i++) {
			st = new StringTokenizer(br.readLine());
			int n = Integer.parseInt(st.nextToken());
			int m = Integer.parseInt(st.nextToken());
			int r = Integer.parseInt(st.nextToken());
			A[n][m] = r;
			A[m][n] = r;
		}
		isSelected[S] = true;
		pmt(S,R,0);
		answer = answer == Integer.MAX_VALUE ? -1 : answer;
		System.out.println(answer);
	}
}

import java.io.BufferedReader;
import java.io.IOException;
import java.util.StringTokenizer;
public class Main {

	static int n,m;
	static int x1,y1,x2,y2;
	static int [][] board,sum;
	static BufferedReader br = new BufferedReader(new java.io.InputStreamReader(System.in));
	static StringBuilder sb = new StringBuilder();
	static StringTokenizer st;
	public static void solve() throws NumberFormatException, IOException {

		st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken(" "));
		int m = Integer.parseInt(st.nextToken(" "));
		sum = new int[n+1][n+1];
		for (int i = 1; i <= n; i++) {
			st = new StringTokenizer(br.readLine());
			for (int j = 1; j <=n; j++) {
				int x = Integer.parseInt(st.nextToken());
				if (j == 1) 
					sum[i][j] = x;
				else sum[i][j] = sum[i][j - 1] + x;
			}
		}	
		for (int cnt = 0; cnt < m; cnt++) {
			st = new StringTokenizer(br.readLine()," ");
			x1 = Integer.parseInt(st.nextToken());
			y1 = Integer.parseInt(st.nextToken());
			x2 = Integer.parseInt(st.nextToken());
			y2 = Integer.parseInt(st.nextToken());
			int res=0;
			for (int i=x1; i<=x2; i++) {
				res += sum[i][y2] - sum[i][y1-1];
			}
			sb.append(res).append("\n");
		}
		return;
	}
	public static void main(String[] args) throws IOException {
		solve();
		System.out.println(sb);
	}
}
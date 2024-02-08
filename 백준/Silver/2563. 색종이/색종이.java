import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringBuilder sb = new StringBuilder();
	static StringTokenizer st;
	static final int N = 10;
	public static int solve() throws NumberFormatException, IOException {
		int res=0;
		int n,r,c;
		n = Integer.parseInt(br.readLine());
		int board[][] = new int[102][102];
		for (int tc=0; tc<n; tc++) {
			st = new StringTokenizer(br.readLine());
			r = Integer.parseInt(st.nextToken());
			c = Integer.parseInt(st.nextToken());
			for (int i=r; i<r+N; i++) {
				for (int j=c; j<c+N; j++)
					board[i][j]=1;
			}
		}
		for (int i=1; i<102; i++) {
			for (int j=1; j<102; j++)
				res+=board[i][j];
		}
		return res;
	}
	public static void main(String[] args) throws NumberFormatException, IOException {
		System.out.println(solve());
	}
}
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringBuilder sb = new StringBuilder();
	static StringTokenizer st;
	static int QuadTree[][];
	static int lastN;

	static void solve(int i, int j, int n) {
		boolean flag = true;
		int start = QuadTree[i][j];
		for (int k = 0; k < n; k++) {
			for (int l = 0; l < n; l++) {
				if (start != QuadTree[k + i][j + l]) {
					flag = false;
					break;
				}
			}
			if (flag == false)
				break;
		}

		if (flag == false) {
			sb.append("(");
			solve(i, j, n / 2);
			solve(i, j + n / 2, n / 2);
			solve(i + n / 2, j, n / 2);
			solve(i + n / 2, j + n / 2, n / 2);
			sb.append(")");
		} else {
			sb.append(start);
		}
		return;
	}

	public static void main(String[] args) throws Exception{
		int n = Integer.parseInt(br.readLine());
		QuadTree = new int[n][n];
		
		for (int i = 0; i < n; i++) {
			
			st = new StringTokenizer(br.readLine());
			String s = st.nextToken();
		for (int j = 0; j < n; j++) {
			QuadTree[i][j] = s.charAt(j) - '0';
				}
			}

		lastN = (n * 2);
		solve(0, 0, n);
		System.out.println(sb);
	}
}
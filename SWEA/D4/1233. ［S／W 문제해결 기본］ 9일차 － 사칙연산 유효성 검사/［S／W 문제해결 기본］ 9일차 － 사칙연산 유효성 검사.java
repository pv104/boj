import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Solution {

	public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	public static StringTokenizer st;
	public static StringBuilder sb = new StringBuilder();
	public static int n;
	public static int res;
	public static int solve() throws NumberFormatException, IOException {
		n = Integer.parseInt(br.readLine());
		int res = 1;
		for (int i = 0; i < n; i++) {
			st = new StringTokenizer(br.readLine());
			st.nextToken();
			char c = st.nextToken().charAt(0);
			if(st.countTokens() == 0) { // 리프면
				if(!Character.isDigit(c)) res = 0;
			} else {
				if(Character.isDigit(c)) res = 0;
			}
		}
		return res;
	}
	public static void main(String[] args) throws NumberFormatException, IOException {
		for (int tc=1; tc<=10; tc++) {
			sb.append("#").append(tc).append(" ").append(solve()).append("\n");
		}
		System.out.println(sb);
	}
}
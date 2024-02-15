import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	static int n, l;
	static int board[][];
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

	static void input() throws Exception{
		StringTokenizer st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		l = Integer.parseInt(st.nextToken());
		board = new int[n][n];
		for (int i = 0; i < n; i++) {
			String s = br.readLine();
			int len = s.length();
			for (int j = 0, index = 0; index < len && j < n; j++, index+=2) {
				board[i][j] = s.charAt(index);
			}
		}
	}

	static int isAble(int[] arr) {
		int size = arr.length - 1;

		boolean w[] = new boolean [size+1];
		for (int i = 0; i < size; i++) {
			int diff = arr[i] - arr[i + 1];
			if (Math.abs(diff) > 1) { // 불가능
				return 0;
			}
			if (diff == 1) { // i>i+1
				int cnt = 1;
				for (int j = i + 1; j < size; j++) {
					if (arr[j] == arr[j + 1]) ++cnt;
					else break;
				}
				if (cnt >= l) {
					int target = i + 1 + l;
					for (int j = i + 1; j < size && j < target; j++) {
						if (w[j] == false)
							w[j] = true;
						else return 0;
					}
					i += cnt-1;
				}
				else return 0;
			}
			else if (diff == -1) { // i<i+1
				int cnt = 1;
				for (int j = i; j > 0; j--) {
					if (arr[j] == arr[j - 1]) ++cnt;
					else break;
				}
				if (cnt >= l) {
					int target = i - l;
					for (int j = i; j > 0 && j > target; j--) {
						if (w[j] == false)
							w[j] = true;
						else return 0;
					}
				}
				else return 0;
			}
		}
		return 1;
		
	}

	static int solve() throws Exception{
		int res = 0;
		for (int i = 0; i < n; i++) {
			int[] t = new int[n];
			for (int j = 0; j < n; j++) 
				t[j] = board[i][j];
			
			res += isAble(t);
		}
		for (int i = 0; i < n; i++) {

			int[] t = new int[n];
			for (int j = 0; j < n; j++) {
				t[j] = board[j][i];
			}

			res += isAble(t);
		}

		return res;
	}

	public static void main(String[] args) throws Exception {
		input();
		System.out.println(solve());
	}
		

}
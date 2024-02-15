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
			/** 입력이 (한자리숫자' '한자리숫자' ' 형태이므로)*/
			for (int j = 0, index = 0; index < len && j < n; j++, index+=2) {
				board[i][j] = s.charAt(index);
			}
		}
	}

	static int isAble(int[] arr) {
		int size = arr.length - 1;

		boolean w[] = new boolean [size+1];
		for (int i = 0; i < size; i++) {
			/** 차이를 계산(1이거나 0이거나 -1이거나, 이외는 안 됨*/
			int diff = arr[i] - arr[i + 1];
			if (Math.abs(diff) > 1) { // 절댓값이 1 초과 = 불가능
				return 0;
			}
			if (diff == 1) { // i>i+1 5>4처럼 앞쪽이 더 큰 경우
				int cnt = 1; // ~5까지 무시하고, 뒤쪽에 경사로 놓을 수 있는지 체크. 1칸은 기본적으로 가능
				for (int j = i + 1; j < size; j++) {
					if (arr[j] == arr[j + 1]) ++cnt; // 같아야 놓을 수 있음
					else break;
				}
				if (cnt >= l) { // l개 이상이면 놓으면 됨(꼭 l개가 아니어도 되니까)
					int target = i + 1 + l; // 놓을 경사로의 인덱스
					for (int j = i + 1; j < size && j < target; j++) {
						if (w[j] == false) // 아직 경사로가 놓여있지 않은 경우
							w[j] = true;
						else return 0;
					}
					i += cnt-1; // 다음 i로 이동하기
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
		// 배열을 row 1줄, column 1줄씩 각각 옮겨서 체크(독립적)
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
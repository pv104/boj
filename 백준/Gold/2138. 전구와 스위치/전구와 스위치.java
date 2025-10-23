import java.io.*;
import java.util.*;

public class Main {

	static final int SIZE = 100002, INF = 987654321;
	static int[] A = new int[SIZE], ans = new int[SIZE], T = new int[SIZE];
	static int N;

	static void toggle(int idx) {
		if (idx > 0)
			A[idx - 1] = A[idx - 1] == 0 ? 1 : 0;
		A[idx] = A[idx] == 0 ? 1 : 0;
		if (idx < N - 1)
			A[idx + 1] = A[idx + 1] == 0 ? 1 : 0;

	}

	static int solve() {
		int answer = 0, cnt = 0;
		// 1. 0번 스위치를 누르지 않은 경우

		for (int i = 1; i < N; i++) {
			// i-1번 전구에 영향을 끼칠 수 있는 스위치는 i번 스위치밖에 없음
			// 따라서, i-1번 전구의 상태와 정답의 상태가 다른 경우 토글
			if (A[i - 1] != ans[i - 1]) {
				answer++;
				toggle(i);
			}
		}
		if (A[N - 1] == ans[N - 1])
			return answer;
		else
			return INF;
		// 2. 0번 스위치를 누른 경우
	}

	public static void main(String[] args) throws Exception {
		BufferedReader br;
		br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		String str = br.readLine();
		for (int i = 0; i < N; i++) {
			A[i] = str.charAt(i) - '0';
			T[i] = A[i];
		}
		str = br.readLine();
		for (int i = 0; i < N; i++) {
			ans[i] = str.charAt(i) - '0';
		}
		int answer = solve(); // 토글 X
		A[0] = A[0] == 0 ? 1 : 0;
		for (int i = 0; i < N; i++) {
			A[i] = T[i];
		}
		toggle(0);
		answer = Math.min(answer, solve() + 1);
		if(answer < INF) System.out.print(answer);
		else System.out.print(-1);
	}
}

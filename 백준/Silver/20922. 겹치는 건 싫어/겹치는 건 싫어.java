import java.io.*;
import java.util.*;

public class Main {

	static final int N_SIZE = 200002;
	static int N, K, ans;
	static int[] A = new int[N_SIZE], cnt = new int[N_SIZE];

	public static int solve() {
		int j = 0;
		for (int i = 0; i < N; i++) {

			while (j < N && cnt[A[j]] != K) {
				cnt[A[j]]++;
				j++;
				ans = Math.max(ans, j - i);
			}
			cnt[A[i]]--;
		}
		return ans;
	}

	public static void main(String[] args) throws Exception {
		BufferedReader br;
		br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		K = Integer.parseInt(st.nextToken());
		st = new StringTokenizer(br.readLine());
		for (int i = 0; i < N; i++)
			A[i] = Integer.parseInt(st.nextToken());
		System.out.print(solve());
	}
}

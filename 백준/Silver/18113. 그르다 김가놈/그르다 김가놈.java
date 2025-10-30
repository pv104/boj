import java.io.*;
import java.util.*;

public class Main {

	static final int N_SIZE = 1_000_002, L_SIZE = 1_000_000_000;
	static int N, K, M, answer = -1;
	static int[] A = new int[N_SIZE];

	static int slice(int p) {
//		System.out.println(p);
		int total = 0;
		int len = 0;
		for (int i = 0; i < N; i++) {
			len = A[i];
			if(len <= K) continue;
			if(len >= 2 * K) {
				len -= 2*K;
			}
			else
				len -= K;
			total += len / p;
		}
		return total;
	}

	static void bs(int l, int r) {
		if (l + 1 < r) {
			int m = (l + r) / 2;
			int total = slice(m);
//			System.out.println(l + " " + r + " " + m + " " + total);
			if (total < M)
				bs(l, m);
			else {
				answer = Math.max(answer, m);
				bs(m, r);
			}
		} else {
			if (slice((l + r) / 2) >= M)
				answer = Math.max(answer, (l + r) / 2);
		}

	}

	static int solve() {
		bs(1, L_SIZE);
		return answer;
	}

	public static void main(String[] args) throws Exception {
		BufferedReader br;
		br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int[] t = new int[3];
		for (int i = 0; i < 3; i++) {
			t[i] = Integer.parseInt(st.nextToken());
		}
		N = t[0];
		K = t[1];
		M = t[2];
		for (int i = 0; i < N; i++) {
			A[i] = Integer.parseInt(br.readLine());
		}
		System.out.print(solve());
	}
}

import java.io.*;
import java.util.*;

public class Main {
	static final int SIZE = 52;
	static int[] A;
	static int N;
	static int solve() {
		if(N < 3) return N;
		int ans = 0;
		int x=0, y=1, z=2;
		for (; ;) {
			if(y == N || z >= N) return ans + 2;
			if((A[x] + A[y]) > A[z]) {
				ans++;
			}
			else {
				x++;
				y++;
			}
			z++;
		}
	}
	public static void main(String[] args) throws Exception {
		BufferedReader br;
		br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		A = new int[N];
		st = new StringTokenizer(br.readLine());
		for (int i=0; i<N; i++) {
			A[i] = Integer.parseInt(st.nextToken());
		}
		Arrays.sort(A);
		System.out.print(solve());
	}
}

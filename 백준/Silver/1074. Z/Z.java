import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	static int Z(int n, int r, int c) {
		if (n == 0)
			return 0;
		int half = 1 << (n - 1);

		if (r < half && c < half)
			return Z(n - 1, r, c);
		else if (r < half && c >= half)
			return half * half + Z(n - 1, r, c - half);
		else if (r >= half && c < half)
			return 2 * half * half + Z(n - 1, r - half, c);
		else
			return 3 * half * half + Z(n - 1, r - half, c - half);

	}

	public static void main(String[] args) throws Exception {
		int n, r, c;
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		r = Integer.parseInt(st.nextToken());
		c = Integer.parseInt(st.nextToken());
		System.out.println(Z(n, r, c));
	}
}
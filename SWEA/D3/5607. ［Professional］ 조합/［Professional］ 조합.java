import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Stack;
import java.util.StringTokenizer;

public class Solution {
	public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringBuilder sb = new StringBuilder();
	static StringTokenizer st;
	static final long MOD = 1234567891;
	public static long Pow(long a,long p) {
		long mul = 1;
		while(p != 0) {
			if(p % 2 == 1) { // 곱해야 하는 수
				mul *= a;
				mul %= MOD;
			}
			a *= a;
			a %= MOD;
			p /= 2;
		}
		return mul;
	}
	public static long solve() throws NumberFormatException, IOException {
	
		// npr, r! 구하고 a^p-2 구하면서 필요한 수만 곱하기
		st = new StringTokenizer(br.readLine());
		long n = Long.parseLong(st.nextToken());
		long r = Long.parseLong(st.nextToken());
		// npr = n-r+1부터 n까지 곱셈하기
		long per = 1;
		for (long i=n-r+1; i<=n; i++) {
			per *= i;
			per %= MOD;
		}
		long fact = 1;
		for (long i=2; i<=r; i++) {
			fact *= i;
			fact %= MOD;
		}
		fact = Pow(fact,MOD - 2);
		return per * fact % MOD;
	}
	public static void main(String[] args) throws NumberFormatException, IOException {
		StringBuilder sb = new StringBuilder();
		int T = Integer.parseInt(br.readLine());
		for (int i=1; i<=T; i++) {
			sb.append("#").append(i).append(" ").append(solve()).append("\n");
		}
		System.out.print(sb);
	}
}
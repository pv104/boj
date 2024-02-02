import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	static int n,res = Integer.MAX_VALUE;
	static int[] s,b;
	
	static int solve() throws IOException {
		st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		s = new int[n+1];
		b = new int[n+1];
		for (int i=0; i<n; i++) {
			st = new StringTokenizer(br.readLine());
			s[i] = Integer.parseInt(st.nextToken());
			b[i] = Integer.parseInt(st.nextToken());
		}
		for (int i=1; i<(1 << n); i++) {
			int ts=1, tb=0;
			for (int j=0; j<n; j++) {
			if((i & (1 << j)) != 0) {
				ts *= s[j];
				tb += b[j];
			}
		}
			
			res = Math.min(res, Math.abs(ts-tb));
		}
		
		return res;
	}
	public static void main(String[] args) throws IOException {
		System.out.println(solve());
	}
}
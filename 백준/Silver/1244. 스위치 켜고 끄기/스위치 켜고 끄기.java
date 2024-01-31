import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

	public static int[] s;
	public static int n,m;
	public static StringBuilder sb = new StringBuilder();
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		n = Integer.parseInt(br.readLine());
		s = new int[n+1];
		StringTokenizer st = new StringTokenizer(br.readLine()," ");
		int idx=1;
		while(st.hasMoreTokens()) {
			s[idx++] = Integer.parseInt(st.nextToken());
		}
		m = Integer.parseInt(br.readLine());
		int x=0;
		int y=0;
		for (int cnt = 0; cnt < m; cnt++) {
			st = new StringTokenizer(br.readLine()," ");
			x = Integer.parseInt(st.nextToken());
			y = Integer.parseInt(st.nextToken());
			if(x == 1) {
				for (int i=y; i<=n; i+=y) {
					if(s[i] == 0) s[i] = 1;
					else s[i] = 0;
				}
			} else {
				if(s[y] == 0) s[y] = 1;
				else s[y] = 0;
				int nx = y;
				int ny = y;
				while(nx > 1 && ny < n) {
					nx--;
					ny++;
					if (s[nx] != s[ny]) break;
					if (s[nx] == 0) {
						s[nx] = s[ny] = 1;
					}
					else {
						s[nx] = s[ny] = 0;
					}
				}
			}
		}
		for (int i = 1; i <= n; i++) {
			sb.append(s[i]).append(" ");
		if (i % 20 == 0) {
			if (i == n) break;
			else sb.append("\n");
		}
		}
			System.out.println(sb);
	
	}
}
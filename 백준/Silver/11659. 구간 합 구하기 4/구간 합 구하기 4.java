import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

	public static int n,m,i,j;
	public static int sum[];
	public static int data[];
	public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	public static StringTokenizer st;
	public static StringBuilder sb = new StringBuilder();
	public static void solve() throws Exception {
		st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		sum = new int[n+1];
		data = new int[n+1];
		st = new StringTokenizer(br.readLine());
		for (int i = 1; i <= data.length && st.hasMoreTokens(); i++) {
			data[i] = Integer.parseInt(st.nextToken());
			sum[i] = sum[i-1]+data[i];
		}
		for (int cnt=0; cnt<m; cnt++) {
			st = new StringTokenizer(br.readLine());
			i = Integer.parseInt(st.nextToken());
			j = Integer.parseInt(st.nextToken());
			sb.append(sum[j]-sum[i-1]).append("\n");
			
		}
		return;
	}
	public static void main(String[] args) throws java.lang.Exception {
		solve();
		System.out.println(sb);
	}   
}
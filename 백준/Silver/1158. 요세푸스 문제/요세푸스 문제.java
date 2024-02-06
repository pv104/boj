import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	static StringBuilder sb = new StringBuilder();
	
	public static String solve() throws IOException {
		int n,k;
		st = new StringTokenizer(br.readLine());
		
		n = Integer.parseInt(st.nextToken());
		k = Integer.parseInt(st.nextToken());
		Queue<Integer> q = new ArrayDeque<>();
		sb.append("<");
		for (int i=1; i<=n; i++)
			q.add(i);
		int resSize=0;
		while(!q.isEmpty()) {
			int cnt=0;
			int cur=0;
			for (cnt=1; cnt<k; cnt++) {
				cur = q.poll();
				q.add(cur);
			}
			cur = q.poll();
			sb.append(cur);
			if(resSize++ != n-1)
				sb.append(", ");
		}
		sb.append(">");
		return sb.toString();
	}
	public static void main(String[] args) throws IOException {
		System.out.println(solve());
	}
}
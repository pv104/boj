import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Main {

	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	static StringBuilder sb = new StringBuilder();
	static PriorityQueue<int[]> pq = new PriorityQueue<>((int[] o1,int[] o2) -> {
	if(Math.abs(o1[0]) < Math.abs(o2[0])) {
		return o1[0]-o2[0];
	} else if(Math.abs(o1[0]) == Math.abs(o2[0])){
		return o1[1] - o2[1];
	}
	return o1[0] - o2[0];
	});
	static int n, x;
	public static void solve() throws IOException {
		st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		for (int tc=0; tc<n; tc++) {
		st = new StringTokenizer(br.readLine());
		x = Integer.parseInt(st.nextToken());
		if (x == 0) {
			if (pq.isEmpty())
				sb.append(0).append("\n");
			else {
				int[] datas = pq.poll();
				sb.append(datas[1]).append(("\n"));
			}
		} else {
			int[] datas = {Math.abs(x),x};
			pq.add(datas);
		}
		}
	}

	public static void main(String[] args) throws IOException {
		solve();
		System.out.println(sb);
	}
}
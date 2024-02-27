import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {

	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	static StringBuilder sb = new StringBuilder();
	static int dx[] = { -1, 0, 1, 0 };
	static int dy[] = { 0, 1, 0, -1 };
	static int n, m, t, x;
	static ArrayList<Integer> arr[];
	static int inDegrees[];
	static void input() throws Exception {
		st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		arr = new ArrayList[n+1];
		
		inDegrees = new int[n+1];
		for (int i = 0; i < arr.length; i++) {
			arr[i] = new ArrayList<>();
		}
		for (int cnt = 0; cnt < m; cnt++) {
			st = new StringTokenizer(br.readLine());
			t = Integer.parseInt(st.nextToken());
			ArrayList<Integer> temp = new ArrayList<>();
			for (int i = 0; i < t; i++) {
				temp.add(Integer.parseInt(st.nextToken()));
			}
			for (int i = 1; i < temp.size(); i++) {
				int cur = temp.get(i-1);
				int nxt = temp.get(i);
				arr[cur].add(nxt);
			}
		}
		
	}
	
	static int solve() {
		Queue <Integer> q = new ArrayDeque<>();
		// findInDegrees
		for (ArrayList<Integer> arrayList : arr) {
			for (Integer cur : arrayList) {
				++inDegrees[cur];
			}
		}
		for (int i = 1; i < inDegrees.length; i++) {
			if(inDegrees[i] == 0) q.add(i);
		}
		int cnt=0;
		while(!q.isEmpty()) {
			int cur = q.poll();
			sb.append(cur).append("\n");
			++cnt;
			for (Integer nxt : arr[cur]) {
				if(--inDegrees[nxt] == 0) q.add(nxt);
			}
		}
		return cnt;
	}

	public static void main(String[] args) throws Exception {
			input();
			int res = solve();
			if(res == n)
			System.out.print(sb);
			else System.out.print(0);
	}
}
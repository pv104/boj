import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.Stack;
import java.util.StringTokenizer;

public class Main {

	static class Pair {
		int x;
		int y;
		Pair(int a, int b) {
			x = a;
			y = b;
		}
	}
	public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	public static StringTokenizer st;
	public static StringBuilder sb = new StringBuilder();
	public static void solve() throws NumberFormatException, IOException {
		Stack <Pair> s = new Stack<>();
		List <Pair> TOP = new ArrayList<>();
		int res[];
		int N;
		N = Integer.parseInt(br.readLine());
		res = new int[N+1];
		st = new StringTokenizer(br.readLine());
		for (int i=0; i<N; i++) {
			TOP.add(new Pair(Integer.parseInt(st.nextToken()),i));
		}
		for (int i = N-1; i >= 0; i--)
		{
			while (!s.empty() && s.peek().x<= TOP.get(i).x)
			{
				res[s.pop().y] = i+1;
				
			}
			s.push(TOP.get(i));
		}
		while (!s.empty()) {
			res[s.pop().y] = 0;
		}	
		for (int i = 0; i < N; i++) {
			sb.append(res[i]).append(' ');
		}
		return;
	}
	public static void main(String[] args) throws NumberFormatException, IOException {
		solve();
		System.out.print(sb);
	}
}
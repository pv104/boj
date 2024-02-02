import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Queue;

public class Main {

	public static Queue<Integer> q = new ArrayDeque<>();
	public static int n,x;
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	public static int solve() throws IOException {
		n = Integer.parseInt(br.readLine());
		for (int i=1; i<=n; i++)
			q.add(i);
		while(true) {
			if(q.size() == 1) return q.peek();
			q.poll();
			if(q.size() == 1)
				return q.peek();
			x = q.poll();
			q.add(x);
		}
	}
	public static void main(String[] args) throws IOException {
		System.out.println(solve());
	}
}
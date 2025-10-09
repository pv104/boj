import java.io.*;
import java.util.*;

public class Main {

	static final int SIZE = 1000002;
	static PriorityQueue[] A = new PriorityQueue[SIZE];
	public static void main(String[] args) throws Exception {
		BufferedReader br;
		
		br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int N = Integer.parseInt(st.nextToken()),ans=0;
		st = new StringTokenizer(br.readLine());
		for (int i=0; i<SIZE; i++)
			A[i] = new PriorityQueue<>();
		for (int i=1; i<=N; i++) {
			int v = Integer.parseInt(st.nextToken());
			if(!A[v+1].isEmpty()) {
				A[v+1].poll();
			}
			else ans++;
			A[v].add(i);
		}
		System.out.println(ans);
	}
}

import java.io.*;
import java.util.*;

public class Main {

	static class Pair {
		Long cur;
		Long origin;
		Pair() {};
		Pair(Long c,Long o) {
			cur = c;
			origin = o;
		}
	}

	static Comparator<Pair> cmp = Comparator.comparingLong((Pair p) -> p.cur);
	static PriorityQueue<Pair> pq = new PriorityQueue<>(cmp); // cur,origin

	public static void main(String[] args) throws Exception {
		BufferedReader br;
		br = new BufferedReader(new InputStreamReader(System.in));
//		br = new BufferedReader(new FileReader("input.txt"));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int N, M;
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		st = new StringTokenizer(br.readLine());
		for (int i = 0; i < N; i++) {
			Long k = Long.parseLong(st.nextToken());
			pq.add(new Pair(k,k));
		}
		int cnt = 0;
		Long time = 0l;
		while(true) {
			Pair cur = pq.poll();
			time = cur.cur;
			cnt++;
			pq.add(new Pair(cur.cur + cur.origin, cur.origin));
			if(cnt == M) break;
		}
		System.out.print(time);
	}
}

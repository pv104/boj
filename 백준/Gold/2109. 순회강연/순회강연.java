import java.io.*;
import java.util.*;

public class Main {

	static class Pair implements Comparable<Pair> {
		int p, d;

		Pair() {
		}

		Pair(int p, int d) {
			this.p = p;
			this.d = d;

		}

		@Override
		public int compareTo(Pair o) {
			if(o.p == p) return d-o.d;
			return o.p-p;
		}
	}

	static final int N_SIZE = 10002; // 1일 이상, 3일 이하에서 3개 고르기
	// 우선순위 = d 오름차순, p 내림차수ㅏㄴ

	static PriorityQueue<Pair> A = new PriorityQueue<>();
	static int N,maxDay=0;
	static int cnt;
	static int[] res = new int[N_SIZE];
	static int solve() {
		int answer = 0;
		// res[d] == 0 -> 넣기
		// != 0 -> d-1부터 0까지 가능한곳에 넣기
		while(!A.isEmpty()) {
			Pair cur = A.poll();
			int p = cur.p;
			int d = cur.d;
			if(res[d] == 0) {
				res[d] = cur.p;
			} else {
				for (int i=d-1; i>0; i--) {
					if(res[i] == 0) {
						res[i] = cur.p; break;
					}
				}
			}
			
		}
		for (int i=0; i<N_SIZE; i++)
			answer += res[i];
		return answer;
	}

	public static void main(String[] args) throws Exception {
		BufferedReader br;
		br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		for (int i = 0; i < N; i++) {
			st = new StringTokenizer(br.readLine());
			int p = Integer.parseInt(st.nextToken());
			int d = Integer.parseInt(st.nextToken());
			maxDay = Math.max(d, maxDay);
			A.add(new Pair(p, d));
		}
		System.out.print(solve());
	}

}
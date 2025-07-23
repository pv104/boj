import java.io.*;
import java.util.*;

public class Main {

	public static class Problem {
		int p, l, g;
	}

	public static final Comparator<Problem> p11 = Comparator.comparingInt((Problem p) -> -p.l)
			.thenComparingInt(p -> -p.p), p12 = Comparator.comparingInt((Problem p) -> p.l).thenComparingInt(p -> p.p),
			p31 = Comparator.comparingInt((Problem p) -> p.p), p32 = Comparator.comparingInt((Problem p) -> -p.p);
	public static final int SIZE = 101, MAX_N = 100002;
	public static int P, L, G, N, M, X;
	public static PriorityQueue<Problem> aU, aD;
	public static PriorityQueue<Problem>[] gU, gD, lU, lD;
	public static Problem[] updated;

	public static void init() {
		aU = new PriorityQueue<>(p11);
		aD = new PriorityQueue<>(p12);
		gU = new PriorityQueue[SIZE];
		gD = new PriorityQueue[SIZE];
		lU = new PriorityQueue[SIZE];
		lD = new PriorityQueue[SIZE];
		for (int i = 0; i < SIZE; i++) {
			gU[i] = new PriorityQueue<>(p11);
			gD[i] = new PriorityQueue<>(p12);
			lU[i] = new PriorityQueue<>(p31);
			lD[i] = new PriorityQueue<>(p32);

		}
		updated = new Problem[MAX_N];
		for (int i = 0; i < MAX_N; i++)
			updated[i] = new Problem();
	}

	static int recommend(int g, int x) {
		int res = 0;
		if (x == 1) {
			while (true) {
				Problem p = gU[g].peek();
				if (updated[p.p].l == -1 || updated[p.p].l != p.l || updated[p.p].g == -1 || updated[p.p].g != g) {
					gU[g].poll();
					continue;
				}
				res = gU[g].peek().p;
				break;
			}
		} else {
			while (true) {
				Problem p = gD[g].peek();
				if (updated[p.p].l == -1 || updated[p.p].l != p.l || updated[p.p].g == -1 || updated[p.p].g != g) {
					gD[g].poll();
					continue;
				}
				res = gD[g].peek().p;
				break;
			}
		}
//		System.out.println("[recommend], " + " g : " + g + " x : " + x + " res : " + res);
		return res;
	}

	static int recommend2(int x) {
		int res = 0;
		if (x == 1) {
			while (true) {
				Problem p = aU.peek();
				if (updated[p.p].l == -1 || updated[p.p].l != p.l || updated[p.p].g == -1 || updated[p.p].g != p.g) {
					aU.poll();
					continue;
				}
				res = aU.peek().p;
				break;
			}
		} else {
			while (true) {
				Problem p = aD.peek();
				if (updated[p.p].l == -1 || updated[p.p].l != p.l || updated[p.p].g == -1 || updated[p.p].g != p.g) {
					aD.poll();
					continue;
				}
				res = aD.peek().p;
				break;
			}
		}
//		System.out.println("[recommend2], " + " x : " + x + " res : " + res);
		return res;
	}

	static int recommend3(int x, int l) {
		int res = 0;
		if (x == 1) {
			for (int i = l; i < SIZE; i++) {
				while (true) {
					if (lU[i].isEmpty())
						break;
					Problem p = lU[i].peek();
					if (updated[p.p].l == -1 || updated[p.p].l != i || updated[p.p].g == -1 || updated[p.p].g != p.g) {
						lU[i].poll();
						continue;
					}
					res = lU[i].peek().p;
					break;
				}
				if (res != 0)
					break;
//				System.out.println("[recommend3] i : " + i + " lu");
			}

		} else {
			for (int i = l - 1; i > 0; i--) {
				while (true) {
					if (lD[i].isEmpty())
						break;
					Problem p = lD[i].peek();
					if (updated[p.p].l == -1 || updated[p.p].l != i || updated[p.p].g == -1 || updated[p.p].g != p.g) {
						lD[i].poll();
						continue;
					}
					res = lD[i].peek().p;
					break;
				}
				if (res != 0)
					break;
			}

		}
//		System.out.println("[recommend3], " + " x : " + x + " l : " + l + " res : " + res);
		return res == 0 ? -1 : res;
	}

	static void add(Problem p) {
		aU.add(p);
		aD.add(p);

		gU[p.g].add(p);
		gD[p.g].add(p);

		lU[p.l].add(p);
		lD[p.l].add(p);

		updated[p.p].g = p.g;
		updated[p.p].l = p.l;

	}

	static void solved(int p) {
		updated[p].l = -1;
		updated[p].g = -1;
	}

	public static void main(String[] args) throws Exception {
		BufferedReader br;
		br = new BufferedReader(new InputStreamReader(System.in));
//		br = new BufferedReader(new FileReader("input.txt"));
		StringTokenizer st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		init();
		StringBuilder sb = new StringBuilder();
		for (int i = 0; i < N; i++) {
			st = new StringTokenizer(br.readLine());
			Problem p = new Problem();
			p.p = Integer.parseInt(st.nextToken());
			p.l = Integer.parseInt(st.nextToken());
			p.g = Integer.parseInt(st.nextToken());
			// add
			add(p);
		}
		M = Integer.parseInt(br.readLine());
		for (int tc = 0; tc < M; tc++) {
			st = new StringTokenizer(br.readLine());
			Problem p = new Problem();
			String q = st.nextToken();
			int res = 0;
			if (q.contains("recommend")) {
				if (q.contains("2")) {
					X = Integer.parseInt(st.nextToken());
					res = recommend2(X);
				} else if (q.contains("3")) {
					X = Integer.parseInt(st.nextToken());
					L = Integer.parseInt(st.nextToken());
					res = recommend3(X, L);
				} else {
					G = Integer.parseInt(st.nextToken());
					X = Integer.parseInt(st.nextToken());
					res = recommend(G, X);
				}
			} else if (q.contains("solved")) {
				P = Integer.parseInt(st.nextToken());
				solved(P);
			} else {
				P = Integer.parseInt(st.nextToken());
				L = Integer.parseInt(st.nextToken());
				G = Integer.parseInt(st.nextToken());
				p.p = P;
				p.l = L;
				p.g = G;
				add(p);
			}
			if (res != 0)
				sb.append(res).append("\n");
		}
		System.out.print(sb.toString());
	}
}

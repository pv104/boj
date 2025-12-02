import java.io.*;
import java.util.*;

public class Main {

	public static class Belt {
		int val;
		boolean hasRobot;
		int robotNumber;

		Belt() {
		}

		Belt(int v, boolean h, int r) {
			val = v;
			hasRobot = h;
			robotNumber = r;
		}
	}

	public static class Robot {
		int robotNumber;
		int idx;

		Robot() {
		}

		Robot(int r, int i) {
			robotNumber = r;
			idx = i;
		}
	}

	public static final int N_SIZE = 102, T_SIZE = 1000;

	public static final Comparator<Robot> cmp = Comparator.comparing((Robot r) -> r.robotNumber);
	public static int N, M, K, robotNumber = 1;
	public static PriorityQueue<Robot> pq;
	public static Belt[] A = new Belt[N_SIZE * 2];

	public static int run() {
		for (int time = 1; ; time++) {
//			System.out.println("time -> " + time);
			// 1. rotate
//			System.out.println("회전 이전 ");
//			print();
			rotate(1, A[M].val, A[M].robotNumber, A[M].hasRobot);
			drop();
//			System.out.println("회전 이후 ");
//			print();
			// 2. find
			find();
			// 3. move
			move();
			// 4. add
			add();
			// 5. isFinished
			if (isFinished())
				return time;
		}
	}

	static void rotate(int idx, int val, int num, boolean hasRobot) {
		if (idx > M)
			return;
		rotate(idx + 1, A[idx].val, A[idx].robotNumber, A[idx].hasRobot);
		A[idx].val = val;
		A[idx].robotNumber = num;
		A[idx].hasRobot = hasRobot;
		return;
	}

	static void drop() {
		if(A[N].hasRobot) {
			A[N].hasRobot = false;
			A[N].robotNumber = -1;
		}
	}
	static void find() {
		pq = new PriorityQueue<>(cmp);
		for (int i = 1; i <= M; i++) {
			if (A[i].hasRobot) {
				pq.add(new Robot(A[i].robotNumber, i));
			}
		}
	}

	static void move() {
		while (!pq.isEmpty()) {
			Robot cur = pq.poll();
			int nxt = (cur.idx%M)+1;
			if (!A[nxt].hasRobot && A[nxt].val > 0) {
				if (nxt != N) {
					A[nxt].robotNumber = cur.robotNumber;
					A[nxt].hasRobot = true;
				}
				A[nxt].val--;
				A[cur.idx].hasRobot = false;
				A[cur.idx].robotNumber = -1;
			}
		}
	}

	static void add() {
		if (A[1].val > 0) {
			A[1].val--;
			A[1].robotNumber = robotNumber++;
			A[1].hasRobot = true;
		}
	}

	static boolean isFinished() {
		int cnt = 0;
		for (int i = 1; i <= M; i++) {
			if (A[i].val == 0)
				cnt++;
		}
		if (cnt >= K)
			return true;
		return false;
	}

	static void print() {
		for (int i = 1; i <= M; i++) {
			System.out.println(" i : " + i + " val : " + A[i].val + " num : " + A[i].robotNumber);
		}
	}

	public static void main(String[] args) throws Exception {
		BufferedReader br;
		br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		K = Integer.parseInt(st.nextToken());
		M = N * 2;
		st = new StringTokenizer(br.readLine());
		for (int i = 1; i <= M; i++) {
			A[i] = new Belt(Integer.parseInt(st.nextToken()), false, -1);
		}
		System.out.println(run());
	}
}

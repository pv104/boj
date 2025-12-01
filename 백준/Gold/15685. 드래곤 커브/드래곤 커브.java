import java.io.*;
import java.util.*;

public class Main {

	public static class Pair {
		int r, c;

		Pair() {
		}

		Pair(int r1, int c1) {
			r = r1;
			c = c1;
		}
	}

	public static class Curve {
		Pair st, ed;
		int dir;

		Curve() {
		}

		Curve(Pair s1, Pair e1, int d1) {
			st = s1;
			ed = e1;
			dir = d1;
		}
	}

	public static class Input {
		int r, c, d, g;

		Input() {
		}

		Input(int r1, int c1, int d1, int g1) {
			c = r1;
			r = c1;
			d = d1;
			g = g1;
		}
	}

	public static final int[] dr = { 0, -1, 0, 1 }, dc = { 1, 0, -1, 0 };
	public static final int N_SIZE = 22, M_SIZE = 101;

	public static int N, answer;
	public static ArrayList<Curve>[] curves = new ArrayList[N_SIZE];
	public static Input[] inputs = new Input[N_SIZE];
	public static boolean[][] isCurve = new boolean[M_SIZE][M_SIZE];

	public static boolean inRange(int r, int c) {
		return 0 <= r && r <= 100 && 0 <= c && c <= 100;
	}

	public static int run() {
		for (int i = 0; i < N; i++) {
			// 0세대
			Input cur = inputs[i];
			curves[i].add(
					new Curve(new Pair(cur.r, cur.c), new Pair(cur.r + dr[cur.d], cur.c + dc[cur.d]), (cur.d + 1) % 4));
			for (int g = 1; g <= cur.g; g++) {
				int size = curves[i].size();
				for (int j = size - 1; j >= 0; j--) {
					Curve curve = curves[i].get(j);
					Curve updated = curves[i].get(curves[i].size() - 1);
					// j의 방향, size-1.ed의 인덱스
					curves[i].add(new Curve(new Pair(updated.ed.r, updated.ed.c),
							new Pair(updated.ed.r + dr[curve.dir], updated.ed.c + dc[curve.dir]), (curve.dir + 1) % 4));
//					curves[i].add(new Curve(new Pair(curve.ed.r, curve.ed.c),
//							new Pair(curve.ed.r + dr[curve.dir], curve.ed.c + dc[curve.dir]), (curve.dir + 1) % 4));
				}
			}
		}
		for (int i = 0; i < N; i++) {
//			System.out.println(" i " + i);
			for (Curve cur : curves[i]) {
//				System.out.println(cur.st.r + " " + cur.st.c + " " + cur.ed.r + " " + cur.ed.c + " " + cur.dir);
				isCurve[cur.st.r][cur.st.c] = true;
				isCurve[cur.ed.r][cur.ed.c] = true;
			}
		}
		for (int i = 0; i < M_SIZE; i++) {
			for (int j = 0; j < M_SIZE; j++) {
				if (inRange(i, j) && inRange(i, j + 1) && (inRange(i + 1, j) && inRange(i + 1, j + 1))) {
					if (isCurve[i][j] && isCurve[i][j + 1] && isCurve[i + 1][j] && isCurve[i + 1][j + 1])
						answer++;
				}
			}
		}
		return answer;
	}

	public static void main(String[] args) throws Exception {
		BufferedReader br;
		br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		for (int i = 0; i < N; i++)
			curves[i] = new ArrayList<>();
		for (int i = 0; i < N; i++) {
			st = new StringTokenizer(br.readLine());
			int x, y, d, g;
			x = Integer.parseInt(st.nextToken());
			y = Integer.parseInt(st.nextToken());
			d = Integer.parseInt(st.nextToken());
			g = Integer.parseInt(st.nextToken());
			inputs[i] = new Input(x, y, d, g);
		}
		System.out.println(run());
	}
}

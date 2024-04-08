import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	static StringBuilder sb = new StringBuilder();
	static final int MAX = 10, INF = 987654321;
	static class Paper {
		int x;
		int y;
		int size;
		public Paper() {
		}
		Paper(int x,int y,int size) {
			this.x = x;
			this.y = y;
			this.size = size;
		}
	}
	static int boards[][],papers[];
	static int N = 10, res = INF;

static int input() throws IOException {
	int cnt = 0;
	boards = new int[N][N];
	papers = new int[6];
	for (int i = 0; i < N; i++) {
		st = new StringTokenizer(br.readLine()," ");
		for (int j = 0; j < N; j++) {
			boards[i][j] = Integer.parseInt(st.nextToken());
			if (boards[i][j] == 1) ++cnt;
		}
	}
	return cnt;
}
static boolean check(Paper paper) {
	int x = paper.x;
	int y = paper.y;
	int size = paper.size;

	int tx = x + size;
	int ty = y + size;
	if (tx > N || ty > N) return false;
	for (int r = x; r < tx; r++) {

		for (int c = y; c < ty; c++) {

			if (boards[r][c] != 1) return false;
		}
	}
	return true;
}
static int paste(Paper paper, boolean flag) {
	int x = paper.x;
	int y = paper.y;
	int size = paper.size;

	int tx = x + size;
	int ty = y + size;
	if (flag == true) {

		int cnt = 0;
		if (!check(paper)) return INF;
		for (int r = x; r < tx; r++) {

			for (int c = y; c < ty; c++) {

				boards[r][c] = 2;
				++cnt;
			}
		}

		return cnt;
	}
	else {
		for (int r = x; r < tx; r++) {

			for (int c = y; c < ty; c++) {

				boards[r][c] = 1;
			}
		}
		return 1; 
		
	}
}
static int findCounts(int cnt, int paperCounts, int colorCounts) {
	if (cnt > 25) return INF;
	if (res <= cnt) return INF;
	if (paperCounts == 0) {
		return cnt;
	}
	if (colorCounts == 0) return INF;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (boards[i][j] != 1) continue;

			int size = 6;
			while (--size > 0) {
				if (papers[size] == 0) continue;
				int flag = paste(new Paper(i,j,size), true);
				if (flag == INF) continue;
				--papers[size];
				res = Math.min(res, findCounts(cnt + 1, paperCounts - flag, colorCounts - 1));
				++papers[size];
				paste(new Paper(i,j,size), false);

			}
			return res;
		}
	}
	return res;
}

static int solve(int paperCounts) {
	for (int i = 1; i <= 5; i++) {
		papers[i] = 5;
	}
	findCounts( 0, paperCounts, 25);
	return (res == INF) ? -1 : res;
}
public static void main(String[] args) throws IOException {
	int paperCounts = input();
	if (paperCounts == 0) {
		System.out.print(0);
	}
	else System.out.println(solve(paperCounts));
}
}
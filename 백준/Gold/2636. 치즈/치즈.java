import java.io.*;
import java.util.*;

public class Main {

	static final int[] dr = {-1,0,1,0}, dc = {0,1,0,-1};
	public static int R,C;
	static int[][] A;
	static boolean[][] visited,checked;
	static ArrayDeque<int[]> q = new ArrayDeque<>();
	static int[] ans;
	static int last;
	static void init() {
		visited = new boolean[R][C];
		checked = new boolean[R][C];
		for (int r=0; r<R; r++) {
			for (int c=0; c<C; c++) {
				if(r == 0 || c == 0 || r == R-1 || c == C-1) {q.add(new int[] {r,c});
				visited[r][c] = true;
			}}
		}
	}
	static boolean inRange(int r,int c) {
		return r >= 0 && r < R && c >= 0 && c < C;
	}
	static void check() {
		int size = q.size();
		while(size > 0) {
			size--;
			ArrayDeque<int[]> inq = new ArrayDeque<>();
			inq.add(q.poll());
			while(!inq.isEmpty()) {
				int[] cur = inq.poll();
				int r=cur[0];
				int c=cur[1];
				for (int dir=0; dir<4; dir++) {
					int nr = r+dr[dir];
					int nc = c+dc[dir];
					if(inRange(nr,nc) && !visited[nr][nc] && !checked[nr][nc]) {
						if(A[nr][nc] == 1) {
							checked[nr][nc] = true;
							q.add(new int[] {nr,nc});
						}
						else {
						inq.add(new int[] {nr,nc});}
						visited[nr][nc] = true;
					}
				}
			}
		}
	}
	static int cal() {
		int cnt=0;
		for (int r=0; r<R; r++) {
			for (int c=0;c<C; c++) {
				if(A[r][c] == 1) cnt++;
			}
		}
		return cnt;
	}
	static void remove() {
		for (int r=0; r<R; r++) {
			for (int c=0; c<C; c++) {
				if(A[r][c] == 1 && checked[r][c]) A[r][c] = 0;
			}
		}
	}
	static void print() {
		for (int r=0; r<R; r++) {
			for (int c=0; c<C; c++) {
				System.out.print(A[r][c] + " ");
			}
			System.out.println();
		}
	}
	static void solve() {
		//ans[0] = time, ans[1] = cheese
		init();
		for (int timer=0; ; timer++) {
			// 1. 녹는 치즈 찾기
			check();
			// 2. 계산하기
			ans[timer] = cal();
			// 3. 확인하기
			if(ans[timer] == 0) {
				last = timer;
				return;}
			// 4. 녹이기
//			print();
//			System.out.println(" timer : " + timer + " remove() 위 ");
			remove();
//			System.out.println(" timer : " + timer + " remove() 아래 ");
//			print();
			}
		}
	
	public static void main(String[] args) throws Exception {
		BufferedReader br;
		br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		R = Integer.parseInt(st.nextToken());
		C = Integer.parseInt(st.nextToken());
		A = new int[R][C];
		ans = new int[R*C];
		for (int r=0; r<R; r++) {
			st = new StringTokenizer(br.readLine());
			for (int c=0; c<C; c++) {
				A[r][c] = Integer.parseInt(st.nextToken());
				}
		}
		solve();
		System.out.println(last);
		System.out.println(ans[last - 1]);
	}
}

import java.io.*;
import java.util.*;

public class Main {

	static final int W = 0, R = 1, B = 2, INF = 1000, SIZE = 14;
	static final int[] dirs = { -1, 1, 3, 0, 2 }; // 1 -> 1, 2 -> 3, 3 -> 0, 4 -> 2
	static final int[] dr = { -1, 0, 1, 0 }, dc = { 0, 1, 0, -1 };

	static class Board {
		int color;
		ArrayDeque<Player> player = new ArrayDeque<>();
	}

	static class Player {
		int num;
		int dir;

		Player() {
		}

		Player(int num, int dir) {
			this.num = num;
			this.dir = dir;
		}
	}

	static int N, K, answer;
	static Board[][] A = new Board[SIZE][SIZE];
	static int[][] playerLocation = new int[SIZE][2]; // [k][0] = r, [k][1] = c;

	static int run() {
		for (int timer = 1; timer <= INF; timer++) {
			// 턴 시작
//			System.out.println(" timer : " + timer);
			for (int cur = 0; cur < K; cur++) {
				// 1. 종료 조건인지 확인하기
				if (isFinished(cur)) {
					return answer = timer;
				}

				// 2. 말 이동 가능한지 확인하기
				if (isMoveable(cur)) {
					// cur 말의 위치 찾기
					int r = playerLocation[cur][0];
					int c = playerLocation[cur][1];
					int dir = A[r][c].player.peekFirst().dir;
					// 3. 이동
					// 
					int t = play(cur,r,c);

				if(checkBoardColor(r+dr[dir],c+dc[dir]) == B && t == -1) {
						play(cur,r,c);
				}
				}

			}
			for (int cur = 0; cur < K; cur++) {
				if (isFinished(cur)) {
					return answer = timer;
				}
			}
//			for (int cur=0; cur<K; cur++) {
//				
//				
//				System.out.print("in Array : ");
//				System.out.println(" k : " + cur + " r , c : " + playerLocation[cur][0] + " " + playerLocation[cur][1]);
//			}
//			System.out.println("in board : ");
//			for (int i=0; i<N; i++) {
//			for (int j=0; j<N; j++) {
//				if(!A[i][j].player.isEmpty()) {
//					for(Player p : A[i][j].player) {
//						System.out.println("k,r,c,dir :" + p.num + " " + i + " " + j + " " + p.dir);
//					}
//				}
//			}
//		}
		}
		return -1;
	}

	public static int play(int cur, int r, int c) {
		// 1. 다음 갈 위치의 색 확인
		int dir = A[r][c].player.peekFirst().dir;
		int s = checkBoardColor(r+dr[dir], c+dc[dir]);
		switch (s) {
		case B: {
			// 이동 전에 방향 바꾸고 확인하기
			Player dest = A[r][c].player.pollFirst();

//			System.out.println(" play, in B, cur, dir, r,c,nr,nc, next -> " + cur + " " + dir + " " + r + " " + c + " " + nr + " " + nc + " " + s);
			dest.dir = (dest.dir + 2) % 4;
//			System.out.println(" play, in B, cur, dir, r,c,nr,nc, next -> " + cur + " " + dir + " " + r + " " + c + " " + nr + " " + nc + " " + s);
			
			
			s = checkBoardColor(r + dr[dest.dir], c + dc[dest.dir]);
			int nr = r+dr[dest.dir];
			int nc = c+dc[dest.dir];
			A[r][c].player.addFirst(dest);
			// 방향 바꿔서 봤는데도 B 혹은 범위 바깥이라면 B 리턴하기
//			System.out.println(" play, in B, cur, dir, r,c,nr,nc, next -> " + cur + " " + dest.dir + " " + r + " " + c + " " + nr + " " + nc + " " + s);
			if (s == B)
				return B;
			else 
			return -1;
		}
		case W: {
			// (r,c)의 순서를 유지하고, (nr,nc)에 있든 없든 back으로
			// front -> back
//			System.out.println(" play, in W, r,c,nr,nc, next -> " + cur + " " + r + " " + c + " " + nr + " " + nc + " " + s);
			// 위치 변경
			int nr = r+dr[dir];
			int nc = c+dc[dir];
			while (!A[r][c].player.isEmpty()) {
				Player dest = A[r][c].player.pollFirst();
				nr = r+dr[dir];
				nc = c+dc[dir];
				playerLocation[dest.num][0] = nr;
				playerLocation[dest.num][1] = nc;
				// front -> back
				A[nr][nc].player.addLast(dest);
			}
//			System.out.println(" play, in W, cur, dir, r,c, nr, nc, next -> " + cur + " " + dir + " " + r + " " + c + " " + nr + " " + nc + " " + s);
			return W;
		}
		case R: {
			// (r,c)의 순서 반대로, (nr,nc)에 있든 없든 back으로
			// back -> back
//			System.out.println(" play, in R, r,c,nr,nc, next -> " + cur + " " + r + " " + c + " " + nr + " " + nc + " " + s);
			// 위치 변경
			int nr = r+dr[dir];
			int nc = c+dc[dir];
			while (!A[r][c].player.isEmpty()) {
				Player dest = A[r][c].player.pollLast();
				nr = r+dr[dir];
				nc = c+dc[dir];
				playerLocation[dest.num][0] = nr;
				playerLocation[dest.num][1] = nc;
				// front -> back
				A[nr][nc].player.addLast(dest);
			}
//			System.out.println(" play, in R, cur, dir, r,c, nr, nc, next -> " + cur + " " + dir + " " + r + " " + c + " " + nr + " " + nc + " " + s);
			return R;
			}

		}
		return -1;
	}

	public static int checkBoardColor(int nr, int nc) {

		if (nr < 0 || nc < 0 || nr >= N || nc >= N)
			return B;
		return A[nr][nc].color;
	}

	// 모든 말이 한 판에 있는지 검사
	public static boolean isFinished(int cur) {
		// cur 말의 위치 찾기
		int r = playerLocation[cur][0];
		int c = playerLocation[cur][1];
		return A[r][c].player.size() > 3;
	}

	// 현재 말의 위치가 가장 아래인지 확인
	public static boolean isMoveable(int cur) {
		// cur 말의 위치 찾기
		int r = playerLocation[cur][0];
		int c = playerLocation[cur][1];

		return A[r][c].player.peekFirst().num == cur;
	}

	public static void main(String[] args) throws Exception {
		BufferedReader br;
		br = new BufferedReader(new InputStreamReader(System.in));
//		br = new BufferedReader(new FileReader("input.txt"));
		StringTokenizer st = new StringTokenizer(br.readLine());

		N = Integer.parseInt(st.nextToken());
		K = Integer.parseInt(st.nextToken());

		for (int i = 0; i < N; i++) {
			st = new StringTokenizer(br.readLine());
			for (int j = 0; j < N; j++) {
				A[i][j] = new Board();
				A[i][j].color = Integer.parseInt(st.nextToken());
			}
		}

		for (int i = 0; i < K; i++) {
			st = new StringTokenizer(br.readLine());
			int r = Integer.parseInt(st.nextToken()) - 1;
			int c = Integer.parseInt(st.nextToken()) - 1;
			int dir = dirs[Integer.parseInt(st.nextToken())];
			playerLocation[i][0] = r;
			playerLocation[i][1] = c;
			A[r][c].player.add(new Player(i, dir));
		}
		System.out.print(run());

	}
}

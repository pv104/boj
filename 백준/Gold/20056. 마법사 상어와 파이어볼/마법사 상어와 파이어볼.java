import java.io.*;
import java.util.*;

public class Main {

	public static int SIZE = 52, K_SIZE = 1000;

	public static class Fireball {
		int m, s, d;

		Fireball() {
		}

		Fireball(int m, int s, int d) {
			this.m = m;
			this.s = s;
			this.d = d;
		}
	}

	public static class Board {
		int sm, ss, size;
		ArrayList<Integer> sd = new ArrayList<>();
		
	}

	public static ArrayDeque<Fireball>[][] fireballs = new ArrayDeque[SIZE][SIZE];
	public static Board[][] A = new Board[SIZE][SIZE];

	public static int N, M, K;

	public static int[] go(int r, int c, int s, int d) {
		s %= N;

		// 방향 확인하기
		switch (d) {

		case 0: {
			// r-1,c
			r -= s;
			if (r < 0)
				r += N;
			break;
		}
		case 2: {
			// r,c+1
			c += s;
			c %= N;
			break;
		}
		case 4: {
			// r+1,c
			r += s;
			r %= N;
			break;
		}
		case 6: {
			// r,c-1
			c -= s;
			if (c < 0)
				c += N;
			break;
		}
		}
		return new int[] {r,c};
	}

	// 1. move
	public static void move() {
		for (int r = 0; r < N; r++) {
			for (int c = 0; c < N; c++) {
				while(!fireballs[r][c].isEmpty()) {
					Fireball f = fireballs[r][c].poll();
					int m = f.m, s = f.s, d = f.d;

					int[] res;
					
					if (d % 2 == 1) {
						res = go(r,c,s,d-1);
						res = go(res[0],res[1],s,(d+1)%8);
					} else {
					res = go(r,c,s,d);
					}
					
					int nr = res[0];
					int nc = res[1];
					A[nr][nc].size++;
					A[nr][nc].sm+=m;
					A[nr][nc].ss+=s;
					A[nr][nc].sd.add(d);
				}
				}
			}
		}
	// 2. merge
	public static void merge() {
		// N*N 다 돌면서 size > 1이면 merge
		for (int r=0; r<N; r++) {
			for (int c=0; c<N; c++) {
				if(A[r][c].size > 1) {
					int sm = A[r][c].sm;
					int ss = A[r][c].ss;
					
					sm /= 5;
					if(sm < 1)  {
						A[r][c].sm = A[r][c].ss = A[r][c].size = 0;
						A[r][c].sd.clear();
						continue;
					}
					ss /= A[r][c].size;
					int o=0,e=0;
					boolean flag = true;
					for (int d : A[r][c].sd) {
						if(d % 2 == 0) e++;
						else o++;
						if(o > 0 && e > 0) {
							flag = false; break;
						}
						
					}
					// 방향 대각선(1357) = false
					int x = flag ? 0 : 1;
					
					for (int dir= 0; dir<8; dir+=2) {
						fireballs[r][c].add(new Fireball(sm,ss,x+dir));
					}
				} else if (A[r][c].size == 1){
					int sm = A[r][c].sm;
					int ss = A[r][c].ss;
					int sd = A[r][c].sd.get(0);
					fireballs[r][c].add(new Fireball(sm,ss,sd));
				}
				A[r][c].sm = A[r][c].ss = A[r][c].size = 0;
				A[r][c].sd.clear();
			}
		}
	}
	public static int sum() {
		// 1개만 있을수도 있으니, A랑 fireballs 다 합치기
		int answer = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
//				if(A[i][j].size > 0)
//					System.out.println(" A / r,c,sizr,m,s : " + i + " " + j + " " + A[i][j].size + " " + A[i][j].sm + " " + A[i][j].ss);
				answer += A[i][j].sm;
				
				for (Fireball f : fireballs[i][j]) {
					answer += f.m;
//					System.out.println(" fireball / r,c,sizr,m,s,d : " + i + " " + j + " " + fireballs[i][j].size() + " " + f.m + " " + f.s + " " + f.d);
				}

			}
		}
		return answer;
	}

	public static int run() {
		for (int k = 1; k <= K; k++) {
			// 1. 이동하기
			move();
			// 2. 합치기 / 나누기
			merge();
//			System.out.println(" k : " + k + " sum : " + sum());
		}
		return sum();

	}

	public static void main(String[] args) throws Exception {
		BufferedReader br;
		br = new BufferedReader(new InputStreamReader(System.in));
//		br = new BufferedReader(new FileReader("input.txt"));
		StringTokenizer st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		K = Integer.parseInt(st.nextToken());
		for (int i = 0; i < SIZE; i++) {

			for (int j = 0; j < SIZE; j++) {
				fireballs[i][j] = new ArrayDeque<>();
				A[i][j] = new Board();
			}
		}
		for (int i = 0; i < M; i++) {
			st = new StringTokenizer(br.readLine());
			int r = Integer.parseInt(st.nextToken()) - 1;
			int c = Integer.parseInt(st.nextToken()) - 1;
			int m = Integer.parseInt(st.nextToken());
			int s = Integer.parseInt(st.nextToken());
			int d = Integer.parseInt(st.nextToken());
			fireballs[r][c].add(new Fireball(m, s, d));
		}
		System.out.print(run());
	}
}

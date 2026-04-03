import java.io.*;
import java.util.*;

public class Main {

	static int N,M,L,R;
	static int[][] A,tA;
	static boolean[][][] Lines;
	static boolean[][] visited;
	static final int[] dr = {-1,0,1,0}, dc = {0,1,0,-1};
	static final int MAX_K = 103;
	static int[] unions,cnts;
	
	public static boolean inRange(int r,int c) {
		return 0 <= r && r < N && 0 <= c && c < N;
	}
	public static void init() {

		visited = new boolean[N][N];
		Lines = new boolean[N][N][4];
		unions = new int[N*N+MAX_K+1];
		cnts = new int[N*N+MAX_K+1];
	}
	public static void open() {
		for (int r=0; r<N; r++) {
			for (int c=0; c<N; c++) {
				for (int dir=0;dir<4;dir++) {
					int nr = r+dr[dir];
					int nc = c+dc[dir];
					int nd = (dir+2)%4;
					if(!inRange(nr,nc)) continue;
					if(Lines[r][c][dir] || Lines[nr][nc][nd]) continue;
					int diff = Math.abs(A[nr][nc] - A[r][c]);
					if(diff >= L && R >= diff) {
						Lines[r][c][dir] = Lines[nr][nc][nd] = true;
					}
				}
			}
		}
	}
	static void bfs(int r,int c, int last) {
		ArrayDeque<int[]> q = new ArrayDeque<>();
		q.add(new int[] {r,c});
		visited[r][c] = true;
		unions[last] = A[r][c];
		A[r][c] = last;
		cnts[last]++;
		while(!q.isEmpty()) {
			int[] cur = q.poll();
			for (int dir=0; dir<4; dir++) {
				int nr=cur[0]+dr[dir];
				int nc=cur[1]+dc[dir];
				int nd=(dir+2)%4;
				if(inRange(nr,nc) && Lines[cur[0]][cur[1]][dir] && Lines[nr][nc][nd] && !visited[nr][nc]) {
					unions[last] += A[nr][nc];
					A[nr][nc] = last;
					cnts[last]++;
					q.add(new int[] {nr,nc});
					visited[nr][nc]=true;
				}
			}
		}
		
	}
	static void move() {
		int last=MAX_K;
		tA = new int[N][N];
		for (int r=0; r<N; r++) {
			for (int c=0; c<N; c++) {
				tA[r][c] = A[r][c];
			}
		}
		for (int r=0; r<N; r++) {
			for (int c=0; c<N; c++) {
				for (int dir=0; dir<4; dir++) {
					if(!visited[r][c] && Lines[r][c][dir]) {
						bfs(r,c,last++);
					}
				}
			}
		}
	}
	public static boolean chk() {
		for (int r=0; r<N; r++) {
			for (int c=0; c<N; c++) {
				if(A[r][c] != tA[r][c]) return true;
			}
		}
		return false;
	}
	public static void toggle() {
		for (int r=0; r<N; r++) {
			for (int c=0; c<N; c++) {
				if(A[r][c] < MAX_K) continue;
				A[r][c] = unions[A[r][c]] / cnts[A[r][c]];
			}
		}
	}
	public static void print() {
		System.out.println(" A ");
		for (int r=0; r<N; r++) {
			for (int c=0; c<N; c++) {
				System.out.print(A[r][c] + " ");
			}
			System.out.println();
		}
		System.out.println("Lines ");
		for (int r=0; r<N; r++) {
			for (int c=0; c<N; c++) {
				for (int dir=0;dir<4;dir++) {
					System.out.print(Lines[r][c][dir] + " " );
				}
			}
			System.out.println();
		}
	}
	public static int solve() {
		int answer=0;
		for (int day=0; day<=2000; day++) {
			init();
			// 1.국경선 열기
			open();
			// 2.인구 이동 시작
			move();
			toggle();
//			System.out.println("day : " + day +  " TOGGLE 아래");
//			print();
			// 3.인구 이동 확인
			if(!chk()) return day;
			// 4.국경선 닫기
			
		}
		return -1;
	}
	public static void main(String[] args) throws Exception {
		BufferedReader br;
		br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		L = Integer.parseInt(st.nextToken());
		R = Integer.parseInt(st.nextToken());
		A = new int[N][N];
		for (int i=0; i<N; i++) {
			st = new StringTokenizer(br.readLine());
			for (int j=0; j<N; j++) {
				A[i][j] = Integer.parseInt(st.nextToken());
			}
		}
		System.out.print(solve());
	}
}

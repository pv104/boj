import java.io.*;
import java.util.*;

public class Main {

	static final int[] dy = {-1,0,1,0}, dx = {0,1,0,-1};
	static int R,C,T;
	static int SIZE = 52;
	static int[][] A = new int[SIZE][SIZE];
	static int UR,DR;
	static ArrayDeque<int[]> q;
	public static void spread() {
		while(!q.isEmpty() ) {
			int[] cur = q.poll();
			int r = cur[0];
			int c = cur[1];
			int val = cur[2];
			int cnt=0;
			for (int dir=0; dir<4; dir++) {
				int nr = r+dy[dir];
				int nc = c+dx[dir];
				if(nr < 0 || nc < 0 || nr >= R || nc >= C || A[nr][nc] == -1) continue;
				A[nr][nc] += (val/5);
				cnt++;
				
			}
			A[r][c] += val-(val/5*cnt);
		}
	}
	public static void upCir(int r,int c, int val) {
//		System.out.println(" upCir, r : " + r + " c : " + c);
		if(r == UR && c == 0) return;
		else if(r == UR && c < C-1) upCir(r,c+1,A[r][c]);
		else if(r > 0 && c == C-1) upCir(r-1,c,A[r][c]);
		else if(r == 0 && c > 0) upCir(r,c-1,A[r][c]);
		else if(r < UR && c == 0) upCir(r+1,c,A[r][c]);
		A[r][c] = val;
	}
	public static void downCir(int r,int c,int val) {
//		System.out.println(" downCir, r : " + r + " c : " + c + " val : " + val);
		if(r == DR && c == 0) return;
		else if(r == DR && c < C-1) downCir(r,c+1,A[r][c]);
		else if(r < R-1 && c == C-1) downCir(r+1,c,A[r][c]);
		else if(r == R-1 && c > 0) downCir(r,c-1,A[r][c]);
		else if(r > DR && c == 0) downCir(r-1,c,A[r][c]);
		A[r][c] = val;
		
	}
	public static void search() {
		q = new ArrayDeque<>();
		for (int i=0; i<R; i++) {
			for (int j=0; j<C; j++) {
				if(A[i][j] > 0)
					{
					q.add(new int[] {i,j,A[i][j]});
					A[i][j] = 0;
					}
			}
		}
	}
	public static void run() {
		search();
		spread();
		upCir(UR,2,A[UR][1]);
		A[UR][1] = 0;
		downCir(DR,2,A[DR][1]);
		A[DR][1] = 0;
	}
	public static void print() {
		for (int r=0; r<R; r++) {
			for (int c=0; c<C; c++) {
				System.out.print(A[r][c] + " ");
			}
			System.out.println();
		}
	}
	public static void main(String[] args) throws Exception {
		BufferedReader br;
		br = new BufferedReader(new InputStreamReader(System.in));
//		br = new BufferedReader(new FileReader("input.txt"));
		StringTokenizer st = new StringTokenizer(br.readLine());
		R = Integer.parseInt(st.nextToken());
		C = Integer.parseInt(st.nextToken());
		T = Integer.parseInt(st.nextToken());
		
		for (int i=0; i<R; i++) {
			st = new StringTokenizer(br.readLine());
			for (int j=0; j<C; j++) {
				A[i][j] = Integer.parseInt(st.nextToken());
				if(A[i][j] == -1) {
					if(UR == 0)
						UR = i;
					else
						DR = i;
				}
			}
		}
		for (int tc=0; tc<T; tc++)
			run();
		
		int res=0;
		for (int r=0; r<R; r++)
			for (int c=0; c<C; c++)
				if(A[r][c] > 0) res += A[r][c];
//		print();
		System.out.print(res);
	}
}

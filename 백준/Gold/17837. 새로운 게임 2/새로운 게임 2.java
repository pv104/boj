import java.io.*;
import java.util.*;

public class Main {

	static class Pair {
		int r,c;
		Pair() {}
		Pair(int r1, int c1) {
			r=r1; c=c1;
		}
	}
	static class Piece {
		int r,c,d;
		Piece() {}
		Piece(int r1,int c1,int d1) {
			r=r1; c=c1; d=d1;
		}
	}
	static final int[] dr = {-1,0,1,0}, dc = {0,1,0,-1};
	static final int W=0, R=1, B=2;
	static int N,K;
	static ArrayDeque<Integer>[][] A;
	static int[][] Colors;
	static Piece[] P;	
	static boolean inRange(int r,int c) {
		return r >= 0 && r < N && c >= 0 && c < N;
	}
	static boolean chkMove(int idx) {
		Piece cur = P[idx];
		int nr = cur.r+dr[cur.d];
		int nc = cur.c+dc[cur.d];
		if(!inRange(nr,nc)) return false;
		
		return Colors[nr][nc] == W || Colors[nr][nc] == R;
	}
	static int changeDir(int idx) {
		Piece cur = P[idx];
		int nr = cur.r+dr[cur.d];
		int nc = cur.c+dc[cur.d];
		if( !inRange(nr,nc) || Colors[nr][nc] == B) return (cur.d+2)%4;
		else return cur.d;
	}
	static void move(int idx) {
		ArrayDeque<Integer> in = new ArrayDeque<>(), out = new ArrayDeque<>();
		Piece cur = P[idx];
		// 현재 위치
		while(!A[cur.r][cur.c].isEmpty() && A[cur.r][cur.c].getFirst() != idx) {
			in.addLast(A[cur.r][cur.c].pollFirst());
		}
		while(!A[cur.r][cur.c].isEmpty()) {
			out.addLast(A[cur.r][cur.c].pollFirst());
		}
		while(!in.isEmpty()) {
			A[cur.r][cur.c].addLast(in.pollFirst());
		}
		int nr = cur.r+dr[cur.d];
		int nc = cur.c+dc[cur.d];
		if(Colors[nr][nc] == W) {
			// 1. 올리기
			 while(!out.isEmpty()) {
				 int curIdx = out.pollFirst();
				 A[nr][nc].addLast(curIdx);
				 // 2. P 바꾸기
				 P[curIdx].r = nr;
				 P[curIdx].c = nc;
			 }
			
		} else if(Colors[nr][nc] == R) {
			while(!out.isEmpty()) {
				int curIdx = out.pollLast();
				A[nr][nc].addLast(curIdx);
				P[curIdx].r = nr;
				P[curIdx].c = nc;
			}
		}
	}
	static boolean isEnd() {
		for (int i=0; i<N; i++) {
			for (int j=0; j<N; j++) {
				if(A[i][j].size() >= 4) return true;
			}
		}
		return false;
	}
	static void print() {
		System.out.println(" A. size ");
		for (int i=0; i<N; i++) {
			for (int j=0; j<N; j++) {
				System.out.print(A[i][j].size() + " ");
			}
			System.out.println();
		}
		System.out.println("P -> ");
		for (int i=0; i<N; i++) {
			System.out.print(" i, r, c, d " + i + " " + P[i].r + " " + P[i].c + " " + P[i].d);
		}
		
	}
	static int solve() {
		for (int turn=1; turn<=1000; turn++) {
			for (int idx=0; idx<K; idx++) {
				// 1.changeDir 하기
				P[idx].d = changeDir(idx);
				// 2. chkMove
				if(chkMove(idx)) {
					move(idx);
				} 
				// else 가만히 있기
				// 3. 확인
				if(isEnd()) {
					return turn;
				}
//				System.out.println(" turn, idx : " + turn + " " + idx);
//				print();
			}
		}
		return -1;
	}
	public static void main(String[] args) throws Exception {
		BufferedReader br;
		br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		K = Integer.parseInt(st.nextToken());
		Colors = new int[N][N];
		A = new ArrayDeque[N][N];
		P = new Piece[K];
		for (int i=0; i<N; i++) {
			st = new StringTokenizer(br.readLine());
			for (int j=0; j<N; j++) {
				Colors[i][j] = Integer.parseInt(st.nextToken());
				A[i][j] = new ArrayDeque<>();
			}
		}
		for (int i=0; i<K; i++) {
			st = new StringTokenizer(br.readLine());
			int r = Integer.parseInt(st.nextToken())-1;
			int c = Integer.parseInt(st.nextToken())-1;
			int d = Integer.parseInt(st.nextToken());
			if(d == 2) 
				d = 3;
			else if(d == 3)
				d = 0;
			else if(d == 4)
				d = 2;
			P[i] = new Piece(r,c,d);
			A[r][c].add(i);
		}
		System.out.print(solve());
	}
}

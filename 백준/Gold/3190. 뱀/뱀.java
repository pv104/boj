import java.io.BufferedReader;
import java.io.IOException;
import java.util.ArrayDeque;
import java.util.Deque;
import java.util.Iterator;
import java.util.Queue;
import java.util.StringTokenizer;




public class Main {
	static class Pair <K,V>{
		public K x;
		public V y;
		Pair(K x, V y) {
			this.x = x;
			this.y = y;
		}
		
	}
	
	public static int n,k,l,curR;
	public static final int dx[] = {0,1,0,-1};
	public static final int dy[] = {1,0,-1,0};
	public static char board[][];
	public static Queue<Pair<Integer,Character>> R = new ArrayDeque<>(); 
	public static Deque<Pair<Integer,Integer>> S = new ArrayDeque<>();
	static BufferedReader br = new BufferedReader(new java.io.InputStreamReader(System.in));
	static StringBuilder sb = new StringBuilder();
	static StringTokenizer st;
	
	public static int solve() throws IOException {
		st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		
		board = new char[n+1][n+1];
		
		st = new StringTokenizer(br.readLine());
		k = Integer.parseInt(st.nextToken());
		
		for (int i=0; i<k; i++) {
			st = new StringTokenizer(br.readLine());
			board[Integer.parseInt(st.nextToken())][Integer.parseInt(st.nextToken())] = 'A';
		}
		
		st = new StringTokenizer(br.readLine());
		l = Integer.parseInt(st.nextToken());
		
		for (int i=0; i<l; i++) {
			st = new StringTokenizer(br.readLine());
			R.add(new Pair<Integer,Character>(Integer.parseInt(st.nextToken()),st.nextToken().charAt(0)));
		}
		S.add(new Pair<Integer,Integer>(1,1));
		int nx = 1;
		int ny = 1;
		
		for (int timer = 1; ; timer++) {
			nx += dx[curR];
			ny += dy[curR];
			S.addLast(new Pair<Integer, Integer>(nx,ny)); // 뱀 길이 늘리기
			//System.out.println(" nx " + nx + " ny " + ny);
			if (nx < 1 || ny < 1 || nx > n || ny > n) { // 벽
				return timer;
			}
			int i=0;
			for (Pair<Integer, Integer> pair : S) {
				if(i >= S.size()-1) break;
				if(pair.x.intValue() == nx && pair.y.intValue() == ny) return timer;
				i++;
			}
			if (board[nx][ny] != 'A') {
				S.pollFirst();
			}
			else {
				board[nx][ny] = ' ';
			}
			if (!R.isEmpty() && (R.peek().x.intValue() == timer)) { // 방향 변환
				if (R.peek().y.charValue() == 'D') {
					curR++;
					curR%=4;
				}
				else {
					curR+=3;
					curR%=4;
				}
				R.poll();
			}
		}
	}
	public static void main(String[] args) throws IOException {
		System.out.println(solve());
	}
}
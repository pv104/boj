import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {

	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	static StringBuffer sb = new StringBuffer();
	static int board[][];
	static int answer[][];
	static int dx[] = {0,1,0,-1};
	static int dy[] = {1,0,-1,0};

	public static void rotate(int x,int y, int r,int c) {
		Queue <Integer> q = new ArrayDeque<>();
		int nx = x;
		int ny = y;
		for (int dir=0; dir<4; dir++) {
			while(true) {

				nx = nx+dx[dir];
				ny = ny+dy[dir];
				if( nx < x || nx >= x+r || ny < y || ny >= y+c) {
					nx-=dx[dir];
					ny-=dy[dir];
					break;
				}
				q.add(board[nx][ny]);
			}
		}
		nx = x;
		ny = y-1;
		
		for (int dir=0; dir<4; dir++) {
			while(!q.isEmpty()) {
				nx = nx+dx[dir];
				ny = ny+dy[dir];

				if( nx < x || nx >= x+r || ny < y || ny >= y+c) {
					nx-=dx[dir];
					ny-=dy[dir];
					break;
				}
				board[nx][ny] = q.poll();
			}
		}
	}
	public static void main(String[] args) throws IOException {
		// start
		// 큐에 push
		// 시작점 빼고 큐 pop
		// 꼬리에 start 넣기
		st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken());
		int m = Integer.parseInt(st.nextToken());
		int r = Integer.parseInt(st.nextToken());
		board = new int[n][m];
		answer = new int[n][m];
		for (int i=0; i<n; i++) {
			st = new StringTokenizer(br.readLine());
			for (int j=0; j<m; j++) {
				board[i][j] = Integer.parseInt(st.nextToken());
			}
		}
		int layer = Math.min(n, m)/2;
		for (int tc = 0; tc < r; tc++) {
			for (int i=0; i<layer; i++) {
				rotate(i,i,n-i*2,m-i*2);
			}
		}
		for (int i=0; i<n; i++) {
			for (int j=0; j<m; j++) {
				sb.append(board[i][j]).append(" ");
			}
			sb.append("\n");
		}
		System.out.println(sb);
	}
}
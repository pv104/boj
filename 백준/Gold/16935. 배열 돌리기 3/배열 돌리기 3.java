import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	static StringBuilder sb = new StringBuilder();
	static int temp[][],originals[][];
	public static String solve() throws IOException {

		int r, n, m, x;
		st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		r = Integer.parseInt(st.nextToken());
		originals = new int[n][m];
		for (int i=0; i<n; i++) {
			st = new StringTokenizer(br.readLine());
			for (int j=0; j<m; j++) {
				originals[i][j] = Integer.parseInt(st.nextToken());
			}
		}
		int[][] board = originals;
		st = new StringTokenizer(br.readLine());
		while(st.hasMoreTokens()) {
			int op = Integer.parseInt(st.nextToken());
			board = rotate(op, board);
		}
		for (int[] is : board) {
			for (int is2 : is) {
				sb.append(is2).append(" ");
			}
			sb.append("\n");
		}
		return sb.toString();
	}
	static int[][] rotate(int op,int[][] board) {
		int r, c;
		r = board.length;
		c = board[0].length;
		if (op == 1) {
			for (int i = 0; i < r / 2; i++) {
				for (int j = 0; j < c; j++) {
					int t = board[i][j];
					board[i][j] = board[r-i-1][j];
					board[r-i-1][j] = t;
				}
			}
		}

		else if (op == 2) {
			for (int i = 0; i < c / 2; i++) {
				for (int j = 0; j < r; j++) {
					int t = board[j][i];
					board[j][i] = board[j][c-i-1];
					board[j][c-i-1] = t;
				}
			}
		}
		else if (op == 3) {
			temp = new int[c][r];

				for (int i = 0; i <r; i++) {

					for (int j = 0; j < c; j++) {
						temp[j][r - i - 1] = board[i][j];
					}
				}
			board = new int[c][r];
				for (int i = 0; i < c; i++) {
					for (int j = 0; j < r; j++) {
						board[i][j] = temp[i][j];
					}
				}
				
				
		}
		else if (op == 4) {

			temp = new int[c][r];
				for (int i = 0; i <r; i++) {
					for (int j = 0; j < c; j++) {
						temp[c - j - 1][i] = board[i][j];
					}
				}

				board = new int[c][r];
				for (int i = 0; i < c; i++) {
					for (int j = 0; j < r; j++) {
						board[i][j] = temp[i][j];
					}
				}
			
		}
		else if (op == 5) {
			int cn, cm;
			temp = new int [r][c];
				cn = r / 2;
				cm = c / 2;
				// 1
				for (int i = 0; i < cn; i++) {
					for (int j = 0; j < cm; j++) {
						int nx = i + cn;
						int ny = j;
						temp[i][j] = board[nx][ny];
					}
				}

				// 2
				for (int i = 0; i < cn; i++) {
					for (int j = cm; j < c; j++) {
						int nx = i;
						int ny = j - cm;
						temp[i][j] = board[nx][ny];
					}
				}
				// 3
				for (int i = cn; i <r; i++) {
					for (int j = cm; j < c; j++) {
						int nx = i - cn;
						int ny = j;
						temp[i][j] = board[nx][ny];
					}
				}
				// 4

				for (int i = cn; i <r; i++) {
					for (int j = 0; j < cm; j++) {
						int nx = i;
						int ny = j + cm;
						temp[i][j] = board[nx][ny];
					}
				}

				for (int i = 0; i <r; i++) {
					for (int j = 0; j < c; j++) {
						board[i][j] = temp[i][j];
					}
				}

				
			
		}
		else if (op == 6) {

			int cn, cm;
			temp = new int [r][c];
			cn = r / 2;
			cm = c / 2;
			// 1
			for (int i = 0; i < cn; i++) {
				for (int j = 0; j < cm; j++) {
					int nx = i;
					int ny = j + cm;
					temp[i][j] = board[nx][ny];
				}
			}

			// 2
			for (int i = 0; i < cn; i++) {
				for (int j = cm; j < c; j++) {
					int nx = i + cn;
					int ny = j;
					temp[i][j] = board[nx][ny];
				}
			}

			// 3
			for (int i = cn; i < r; i++) {
				for (int j = cm; j < c; j++) {
					int nx = i;
					int ny = j - cm;
					temp[i][j] = board[nx][ny];
				}
			}
			// 4

			for (int i = cn; i < r; i++) {
				for (int j = 0; j < cm; j++) {
					int nx = i - cn;
					int ny = j;
					temp[i][j] = board[nx][ny];
				}
			}

			for (int i = 0; i < r; i++) {
				for (int j = 0; j < c; j++) {
					board[i][j] = temp[i][j];
				}
			}


		}
		return board;	
	}
	public static void main(String[] args) throws IOException {
		System.out.println(solve());
	}
}
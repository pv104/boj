import java.io.*;
import java.util.*;
public class Main {

	static int[][] A = new int[52][52],copyArr;
	static int N,M,K,R,C,S,res = Integer.MAX_VALUE;
	static ArrayList<int[]> rotateInfo = new ArrayList<>();
	static boolean[] isSelected = new boolean[7];
	static int[] num = new int[7];
	public static void rotate(int v) {
		int r = rotateInfo.get(v)[0];
		int c = rotateInfo.get(v)[1];
		int s = rotateInfo.get(v)[2];
		R = r;
		C = c;
		S = s;
		// i,j -> j,N-1-i;
//		System.out.println(" r : " + r + " c : " + c + " s : " + s);
		int val = 0;
		for (int k=s; k>0; k--) 
			rec(r-k,c-k,k,copyArr[r-k+1][c-k]);
		}
	public static void rec(int r,int c,int s,int val) {

		if(r-1 == R-s && c == C-s){
			copyArr[r][c] = val;
			return;
		}
		else if(r == R-s && c+1 <= C+s) {
			rec(r,c+1,s,copyArr[r][c]);
		}else if(r+1 <= R+s && c == C+s) {
			rec(r+1,c,s,copyArr[r][c]);
		}else if(r == R+s && c-1 >= C-s) {
			rec(r,c-1,s,copyArr[r][c]);
		}else if(r-1 >= R-s && c == C-s) {
			rec(r-1,c,s,copyArr[r][c]);
		} else return;
		
		copyArr[r][c] = val;
	}
	public static void solve() {
		// 1. 배열 복사하기
		copyArr = new int[52][52];
		for (int i=0; i<N; i++)
			for (int j=0; j<M; j++)
				copyArr[i][j] = A[i][j];
//		System.out.println("회전 전");
//		for (int i=0; i<N; i++) {
//			for (int j=0; j<M; j++) {
//				System.out.print(copyArr[i][j] + " ");
//			}
//			System.out.println();
//		}
		// 2. 배열 회전하기(순서 num)
		for (int i=0; i<K; i++) {
		rotate(num[i]);
		}
		// 3. 계산
		for (int i=0; i<N; i++) {
			int t = 0;
			for (int j=0; j<M; j++) {
				t += copyArr[i][j];
			}
			res = Math.min(res, t);
		}
	}
	public static void pmt(int k) {
		if(k == K) {
			solve();
			return;
		}
		for (int i=0; i<K; i++) {
			if(isSelected[i]) continue;
			isSelected[i] = true;
			num[k] = i;
			pmt(k+1);
			isSelected[i] = false;
		}
		
	}
	public static void main(String[] args) throws Exception {
		BufferedReader br;
		br = new BufferedReader(new InputStreamReader(System.in));
//		br = new BufferedReader(new FileReader("input.txt"));
		StringTokenizer st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		K = Integer.parseInt(st.nextToken());
		for (int i=0; i<N; i++) {
			st = new StringTokenizer(br.readLine());
			for (int j=0; j<M; j++) {
				A[i][j] = Integer.parseInt(st.nextToken());
			}
		}
		for (int i=0; i<K; i++) {
			st = new StringTokenizer(br.readLine());
			int r = Integer.parseInt(st.nextToken()) - 1;
			int c = Integer.parseInt(st.nextToken()) - 1;
			int s = Integer.parseInt(st.nextToken());
			rotateInfo.add(new int[] {r,c,s});
		}
		pmt(0);
		System.out.println(res);
    }
}
